#include "utopia/utopia_pch.hpp"

#include "utopia/auth_server/client_connection/auth_client_connection.hpp"

#include "utopia/auth_server/client_connection/auth_client_connection_context.hpp"
#include "utopia/auth_server/client_connection/auth_client_connection_logger.hpp"
#include "utopia/auth_server/client_connection/auth_client_connection_state_machine.hpp"
#include "utopia/auth_server/client_connection/events/auth_client_connection_event.hpp"
#include "utopia/auth_server/client_connection/events/dispatch_auth_client_packet.hpp"
#include "utopia/auth_server/client_connection/packets/client_connect_version_packet.hpp"
#include "utopia/common/network/connection_base.hpp"
#include "utopia/common/network/connection_manager.hpp"
#include "utopia/common/network/diffie_hellman_key.hpp"
#include "utopia/common/strings/get_hex_string_from_bytes.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

#include <chrono>
#include <thread>

namespace sml = boost::sml;

void log_received_data(const std::vector<std::uint8_t> &recv_buf,
                       size_t num_bytes_read) {
  if (!recv_buf.empty()) {
    std::string hex_str = utopia::common::get_hex_string_from_bytes(recv_buf);

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

namespace utopia::auth::client_connection {
AuthClientConnection::AuthClientConnection(asio::io_context &io_context,
                                           std::uint32_t port)
    : io_context_(io_context), common::ConnectionBase(io_context),
      event_queue_(), client_connection_sm_context_(),
      client_connection_logger_(client_connection_sm_context_),
      client_connection_sm_(
          std::make_unique<sml::sm<AuthClientConnectionStateMachine,
                                   sml::logger<AuthClientConnectionLogger>>>(
              *this, io_context_, client_connection_sm_context_,
              client_connection_logger_, event_queue_)) {
  if (accept_connection(port)) {
    spdlog::info("Accepted incoming connection on port {}", port);
  }
}

void AuthClientConnection::run(
    const std::uint32_t game_version,
    const common::DiffieHellmanKey &diffie_hellman_key,
    const std::array<std::uint8_t, 64> private_key) {
  // Verify that we are using the same client version
  auto num_bytes_read = read_some(auth_client_recv_buf_, 16);
  if (!num_bytes_read) {
    spdlog::error("Failed to read ClientConnectVersionPacket.");
    return;
  }

  log_received_data(auth_client_recv_buf_, num_bytes_read.value());

  ClientConnectVersionPacket packet{auth_client_recv_buf_};
  if (!packet.is_valid()) {
    spdlog::error("Received invalid ClientConnectVersionPacket.");
    return;
  }

  auth_client_recv_buf_.erase(auth_client_recv_buf_.begin(),
                              auth_client_recv_buf_.begin() +
                                  packet.get_packet_size());

  if (packet.version != game_version) {
    spdlog::error("Received invalid client version: 0x{:08x}.", packet.version);
    return;
  }

  if (!do_key_exchange(diffie_hellman_key, private_key)) {
    spdlog::error("Failed to do key exchange.");
    return;
  }

  spdlog::debug("Key exchange successful.");

  auto is_sm_running = [this] { return !client_connection_sm_->is(sml::X); };

  spdlog::info("Running client connection.");
  while (is_connected()) {
    auto num_bytes_read = read_some_and_decrypt(auth_client_recv_buf_);
    if (!num_bytes_read) {
      continue;
    }

    while (auth_client_recv_buf_.size() >= 2 &&
           dispatch_auth_client_packet(this, auth_client_recv_buf_)) {
      process_event_queue();
    }

    log_received_data(auth_client_recv_buf_, num_bytes_read.value());
  }

  // In case we are still connected, we need to disconnect.
  // I we are already disconnected, this does nothing.
  disconnect();

  spdlog::debug("AuthClientConnection::Run() finished.");
}

void AuthClientConnection::process_event(
    const AuthClientPacket &packet) noexcept {
  spdlog::trace("Processing AuthClientPacket event.");
  std::visit(
      [&](auto &&x) {
        if (x.packet_valid) {
          spdlog::debug("Packet {}({}) has size = {}:\n{}\n",
                        x.get_packet_name(), x.header_id, x.get_packet_size(),
                        x.get_packet_as_printable());
          client_connection_sm_->process_event(x);
        }
      },
      packet);
}

void AuthClientConnection::process_event_queue() {
  AuthClientConnectionEvent event;
  while (event_queue_.try_dequeue(event)) {
    std::visit([&](auto &&x) { client_connection_sm_->process_event(x); },
               event);
  }
}

} // namespace utopia::auth::client_connection
