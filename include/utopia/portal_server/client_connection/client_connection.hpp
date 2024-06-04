#pragma once

#include "utopia/common/network/connection_base.hpp"

#include <asio.hpp>

#include <string>

namespace utopia::portal::client_connection {

class ClientConnection : public common::ConnectionBase {
public:
  ClientConnection(asio::io_context &io_context, unsigned short port);

  void run();

private:
  asio::io_context &io_context_;
};

} // namespace utopia::portal::client_connection
