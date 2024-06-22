#include "utopia/utopia_pch.hpp"

#include "utopia/auth_server/client_connection/auth_client_connection.hpp"

#include "utopia/auth_server/client_connection/auth_client_connection_context.hpp"
#include "utopia/auth_server/client_connection/auth_client_connection_logger.hpp"
#include "utopia/auth_server/client_connection/auth_client_connection_state_machine.hpp"
#include "utopia/auth_server/client_connection/events/auth_client_connection_event.hpp"
#include "utopia/common/network/connection_base.hpp"
#include "utopia/common/network/connection_manager.hpp"
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
                                           unsigned short port)
    : io_context_(io_context), common::ConnectionBase(io_context) {
  if (accept_connection(port)) {
    spdlog::info("Accepted incoming connection on port {}", port);
  }
}

void AuthClientConnection::run() {
  using namespace boost::sml;
  auto event_queue = std::make_unique<
      moodycamel::ConcurrentQueue<AuthClientConnectionEvent>>();

  AuthClientConnectionContext client_connection_sm_context{};

  AuthClientConnectionLogger client_connection_logger{
      client_connection_sm_context};

  sm<AuthClientConnectionStateMachine, logger<AuthClientConnectionLogger>>
      client_connection_sm{*this, io_context_, client_connection_sm_context,
                           client_connection_logger, event_queue.get()};

  std::vector<std::uint8_t> recv_buf;

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
