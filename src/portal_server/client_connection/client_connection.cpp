#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/client_connection/client_connection.hpp"

#include "utopia/common/network/connection_base.hpp"
#include "utopia/portal_server/client_connection/client_connection_context.hpp"
#include "utopia/portal_server/client_connection/client_connection_logger.hpp"
#include "utopia/portal_server/client_connection/client_connection_state_machine.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_connect_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_login_finish_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_ping_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_start_tls_packet.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_change_cipher_spec_packet.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_finished_packet.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_hello_packet.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_key_exchange_packet.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/tls_decode.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <boost/sml.hpp>
#include <spdlog/spdlog.h>

#include <iomanip>
#include <optional>
#include <sstream>

void log_received_data(const std::vector<std::uint8_t> &recv_buf,
                       size_t num_bytes_read) {
  if (!recv_buf.empty()) {
    // Convert recv_buf to a hex string
    std::ostringstream hex_stream;
    for (const auto &byte : recv_buf) {
      hex_stream << std::hex << std::setw(2) << std::setfill('0')
                 << (static_cast<int>(byte) & 0xff) << " ";
    }
    std::string hex_str = hex_stream.str();

    // Log recv_buf as ASCII
    spdlog::debug(
        "Received data ({} bytes recv, {} bytes in buffer) (ASCII):\n{}",
        num_bytes_read, recv_buf.size(),
        std::string(recv_buf.begin(), recv_buf.end()));

    // Log recv_buf as hex
    spdlog::debug(
        "Received data ({} bytes recv, {} bytes in buffer) (Hex):\n{}",
        num_bytes_read, recv_buf.size(), hex_str);
  }
}

namespace utopia::portal::client_connection {

ClientConnection::ClientConnection(asio::io_context &io_context,
                                   unsigned short port)
    : ConnectionBase(io_context), io_context_(io_context) {
  if (accept_connection(port)) {
    spdlog::info("Accepted incoming connection on port {}", port);
  }
}

void ClientConnection::run() {
  using namespace boost::sml;
  auto event_queue =
      std::make_unique<moodycamel::ConcurrentQueue<ClientConnectionEvent>>();

  ClientConnectionContext client_connection_sm_context{};
  TlsContext tls_context{};

  ClientConnectionLogger client_connection_logger{client_connection_sm_context};

  sm<ClientConnectionStateMachine, logger<ClientConnectionLogger>>
      client_connection_sm{*this,
                           io_context_,
                           client_connection_sm_context,
                           tls_context,
                           client_connection_logger,
                           event_queue.get()};

  std::vector<std::uint8_t> recv_buf;

  spdlog::info("Running client connection.");
  while (is_connected()) {
    ClientConnectionEvent event;
    while (event_queue->try_dequeue(event)) {
      std::visit([&](auto &&x) { client_connection_sm.process_event(x); },
                 event);
    }

    auto num_bytes_read = read_some(recv_buf);
    if (!num_bytes_read) {
      continue;
    }

    while (!recv_buf.empty()) {
      if (recv_buf.size() >= 21 && recv_buf[0] == 0x17 && recv_buf[1] == 3 &&
          recv_buf[2] == 3) {
        auto decrypted_bytes = tls_decode(recv_buf, tls_context);
        if (!decrypted_bytes) {
          spdlog::error("Failed to decrypt TLS packet.");
          disconnect();
          break;
        }
        log_received_data(decrypted_bytes.value(),
                          decrypted_bytes.value().size());

        // We need these 5 bytes to compute the HMAC.
        std::vector<std::uint8_t> tls_header(recv_buf.begin(),
                                             recv_buf.begin() + 5);

        // We remove the processed bytes from the data buffer and insert the
        // decrypted bytes instead in front. Performance isn't an issue here.
        recv_buf.erase(recv_buf.begin(),
                       recv_buf.begin() + 21 + decrypted_bytes.value().size());
        recv_buf.insert(recv_buf.begin(), decrypted_bytes.value().begin(),
                        decrypted_bytes.value().end());

        std::uint32_t recv_buf_size =
            static_cast<std::uint32_t>(recv_buf.size());
        if (dispatch_sts_packets(recv_buf, client_connection_sm)) {
          const auto processed_bytes = recv_buf_size - recv_buf.size();
          const auto decrypted_bytes_remaining =
              decrypted_bytes.value().size() - processed_bytes;

          // The next 20 bytes are the received HMAC bytes
          if (decrypted_bytes_remaining < 20) {
            spdlog::error("Not enough bytes for HMAC.");
            disconnect();
            break;
          }

          // Store the received HMAC
          std::vector<std::uint8_t> hmac_bytes(
              decrypted_bytes.value().begin() + processed_bytes,
              decrypted_bytes.value().begin() + processed_bytes + 20);

          // Compute the HMAC
          mbedtls_md_hmac_reset(&tls_context.mac_dec);
          if (mbedtls_md_hmac_update(&tls_context.mac_dec,
                                     tls_context.next_read_id.data(),
                                     tls_context.next_read_id.size())) {
            spdlog::error("Failed to update HMAC context with next_read_id.");
            disconnect();
            break;
          }
          
          tls_header[4] = processed_bytes;
          if (mbedtls_md_hmac_update(&tls_context.mac_dec, tls_header.data(),
                                     tls_header.size())) {
            spdlog::error(
                "Failed to update HMAC context with modified header.");
            disconnect();
            break;
          }

          std::span decrypted_msg_packet(decrypted_bytes.value().data(),
                                         processed_bytes);
          if (mbedtls_md_hmac_update(&tls_context.mac_dec,
                                     decrypted_msg_packet.data(),
                                     decrypted_msg_packet.size())) {
            spdlog::error(
                "Failed to update HMAC context with modified header.");
            disconnect();
            break;
          }

          std::array<std::uint8_t, 20> calculated_hmac;
          if (mbedtls_md_hmac_finish(&tls_context.mac_dec,
                                     calculated_hmac.data())) {
            spdlog::error("Failed to finish HMAC calculation.");
            disconnect();
            break;
          }

          // Validate the HMAC
          if (!std::equal(hmac_bytes.begin(), hmac_bytes.end(),
                          calculated_hmac.begin())) {
            spdlog::error("HMAC validation failed.");
            disconnect();
            break;
          }

          // Remove the remaining decrypted bytes from the buffer
          recv_buf.erase(recv_buf.begin(),
                         recv_buf.begin() + decrypted_bytes_remaining);
        }
      } else {
        dispatch_sts_packets(recv_buf, client_connection_sm);
      }
      while (event_queue->try_dequeue(event)) {
        std::visit([&](auto &&x) { client_connection_sm.process_event(x); },
                   event);
      }
    }

    log_received_data(recv_buf, num_bytes_read.value());
  }
}

bool ClientConnection::dispatch_sts_packets(
    std::vector<std::uint8_t> &data,
    boost::sml::sm<ClientConnectionStateMachine,
                   boost::sml::logger<ClientConnectionLogger>> &sm) {
  if (dispatch_sts_packet<StsConnectPacket>(data, sm))
    return true;
  if (dispatch_sts_packet<StsPingPacket>(data, sm))
    return true;
  if (dispatch_sts_packet<StsStartTlsPacket>(data, sm))
    return true;
  if (dispatch_sts_packet<TlsClientHelloPacket>(data, sm))
    return true;
  if (dispatch_sts_packet<TlsClientKeyExchangePacket>(data, sm))
    return true;
  if (dispatch_sts_packet<TlsChangeCipherSpecPacket>(data, sm))
    return true;
  if (dispatch_sts_packet<TlsClientFinishedPacket>(data, sm))
    return true;
  if (dispatch_sts_packet<StsLoginFinishPacket>(data, sm))
    return true;

  return false;
}

} // namespace utopia::portal::client_connection
