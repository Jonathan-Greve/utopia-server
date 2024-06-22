#include "utopia/utopia_pch.hpp"

#include "utopia/auth_server/client_connection/auth_client_connection.hpp"

#include "utopia/auth_server/client_connection/auth_client_connection_context.hpp"
#include "utopia/auth_server/client_connection/auth_client_connection_logger.hpp"
#include "utopia/auth_server/client_connection/auth_client_connection_state_machine.hpp"
#include "utopia/auth_server/client_connection/events/auth_client_connection_event.hpp"
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
    : io_context_(io_context), common::ConnectionBase(io_context) {
  if (accept_connection(port)) {
    spdlog::info("Accepted incoming connection on port {}", port);
  }
}

void AuthClientConnection::run(
    const std::uint32_t game_version,
    const common::DiffieHellmanKey &diffie_hellman_key) {
  // Verify that we are using the same client version
  std::vector<std::uint8_t> recv_buf;
  auto num_bytes_read = read_some(recv_buf);
  if (!num_bytes_read) {
    spdlog::error("Failed to read ClientConnectVersionPacket.");
    return;
  }

  log_received_data(recv_buf, num_bytes_read.value());

  ClientConnectVersionPacket packet{recv_buf};
  if (!packet.is_valid()) {
    spdlog::error("Received invalid ClientConnectVersionPacket.");
    return;
  }

  recv_buf.erase(recv_buf.begin(), recv_buf.begin() + packet.get_packet_size());

  if (packet.version != game_version) {
    spdlog::error("Received invalid client version: 0x{:08x}.", packet.version);
    return;
  }

  if (!do_key_exchange(diffie_hellman_key)) {
    spdlog::error("Failed to do key exchange.");
    return;
  }

  spdlog::debug("Key exchange successful.");

  using namespace boost::sml;
  auto event_queue = std::make_unique<
      moodycamel::ConcurrentQueue<AuthClientConnectionEvent>>();

  AuthClientConnectionContext client_connection_sm_context{};

  AuthClientConnectionLogger client_connection_logger{
      client_connection_sm_context};

  sm<AuthClientConnectionStateMachine, logger<AuthClientConnectionLogger>>
      client_connection_sm{*this, io_context_, client_connection_sm_context,
                           client_connection_logger, event_queue.get()};

  auto is_sm_running = [&client_connection_sm] {
    return !client_connection_sm.is(sml::X);
  };

  spdlog::info("Running client connection.");
  while (is_connected()) {
    auto num_bytes_read = read_some(recv_buf);
    if (!num_bytes_read) {
      continue;
    }

    // while (!recv_buf.empty()) {
    //   recv_buf.clear();
    // }
    log_received_data(recv_buf, num_bytes_read.value());
  }

  // In case we are still connected, we need to disconnect.
  // I we are already disconnected, this does nothing.
  disconnect();

  spdlog::debug("AuthClientConnection::Run() finished.");
}

} // namespace utopia::auth::client_connection
