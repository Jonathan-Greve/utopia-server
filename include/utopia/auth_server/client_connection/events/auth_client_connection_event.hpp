#pragma once

#include "utopia/auth_server/client_connection/events/auth_client_connection_events.hpp"

#include <variant>

namespace utopia::auth::client_connection {

using AuthClientConnectionEvent = std::variant<std::monostate>;
} // namespace utopia::auth::client_connection
