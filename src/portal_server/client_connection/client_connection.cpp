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
}

} // namespace utopia::portal::client_connection
