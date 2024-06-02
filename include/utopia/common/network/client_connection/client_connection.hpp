#pragma once

#include "utopia/common/network/connection_base.hpp"

#include <asio.hpp>

#include <string>

namespace utopia::common {

class ClientConnection : public ConnectionBase {
public:
  ClientConnection(asio::io_context &io_context, unsigned short port);
};

} // namespace utopia::common
