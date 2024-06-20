#pragma once

#include "utopia/portal_server/app/events/portal_app_events.hpp"

#include <variant>

namespace utopia::portal::app {
using PortalAppEvent =
    std::variant<PortalAppEvents::Start, PortalAppEvents::Stop,
                 PortalAppEvents::Tick>;
} // namespace utopia::portal::app
