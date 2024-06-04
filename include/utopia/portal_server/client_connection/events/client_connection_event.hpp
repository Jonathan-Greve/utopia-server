#pragma once

#include "utopia/portal_server/app/events/app_events.hpp"

#include <variant>

namespace utopia::portal::app {
using ClientConnectionEvent =
    std::variant<ClientConnectionEvent::UnableToParseMessage>;
} // namespace utopia::portal::app
