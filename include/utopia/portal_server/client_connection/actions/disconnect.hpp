#pragma once

#include "utopia/portal_server/client_connection/portal_client_connection.hpp"

#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto disconnect = [](PortalClientConnection &client_connection) {
  spdlog::info("Disconnecting client connection.");
  client_connection.disconnect();
};

} // namespace utopia::portal::client_connection
