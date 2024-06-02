#include "utopia/utopia_pch.hpp"

#include "utopia/common/network/client_connection/client_connection.hpp"

#include "utopia/common/network/connection_base.hpp"

#include <asio.hpp>
#include <spdlog/spdlog.h>

namespace utopia::common {

ClientConnection::ClientConnection(asio::io_context &io_context,
                                   unsigned short port)
    : ConnectionBase(io_context) {
  if (accept_connection(port)) {
    spdlog::info("Accepted incoming connection on port {}", port);
  }
}

} // namespace utopia::common
