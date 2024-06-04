#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/client_connection/client_connection.hpp"

#include "utopia/common/network/connection_base.hpp"

#include <asio.hpp>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

ClientConnection::ClientConnection(asio::io_context &io_context,
                                   unsigned short port)
    : ConnectionBase(io_context) {
  if (accept_connection(port)) {
    spdlog::info("Accepted incoming connection on port {}", port);
  }

  io_context.post([this] { run(); });
}

void ClientConnection::run() {
  spdlog::info("Running client connection.");
  while (is_connected()) {
    static std::vector<std::uint8_t> recv_buffer(1024);
    std::fill(recv_buffer.begin(), recv_buffer.end(), 0);

    std::uint32_t num_bytes_recv = try_read_some(recv_buffer);
    if (num_bytes_recv > 0) {
      spdlog::info("Received {} bytes.", num_bytes_recv);

      std::string recv_data(recv_buffer.begin(),
                            recv_buffer.begin() + num_bytes_recv);
      spdlog::info("Received data (ASCII): {}", recv_data);
    }
  }
}

} // namespace utopia::portal::client_connection
