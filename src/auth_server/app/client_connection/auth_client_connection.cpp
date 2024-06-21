#include "utopia/utopia_pch.hpp"

#include "utopia/auth_server/client_connection/auth_client_connection.hpp"

namespace utopia::auth::client_connection {
AuthClientConnection::AuthClientConnection(asio::io_context &io_context,
                                           unsigned short port)
    : io_context_(io_context), common::ConnectionBase(io_context) {}

void AuthClientConnection::run() {}

} // namespace utopia::auth::client_connection
