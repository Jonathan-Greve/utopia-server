#pragma once

#include <asio.hpp>
#include <utopia/common/network/connection_base.hpp>

namespace utopia::auth::client_connection {

class AuthClientConnection : public common::ConnectionBase {
public:
  AuthClientConnection(asio::io_context &io_context, unsigned short port);

  void run();

private:
  asio::io_context &io_context_;
};

} // namespace utopia::auth::client_connection
