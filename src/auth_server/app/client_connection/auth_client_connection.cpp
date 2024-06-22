#include "utopia/utopia_pch.hpp"

#include "utopia/auth_server/client_connection/auth_client_connection.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>
#include <utopia/common/network/connection_base.hpp>
#include <utopia/common/network/connection_manager.hpp>

#include <chrono>
#include <thread>

namespace utopia::auth::client_connection {
AuthClientConnection::AuthClientConnection(asio::io_context &io_context,
                                           unsigned short port)
    : io_context_(io_context), common::ConnectionBase(io_context) {
  if (accept_connection(port)) {
    spdlog::info("Accepted incoming connection on port {}", port);
  }
}

void AuthClientConnection::run() {
  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

} // namespace utopia::auth::client_connection
