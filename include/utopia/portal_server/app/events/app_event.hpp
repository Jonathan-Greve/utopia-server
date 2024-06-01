#pragma once

#include "utopia/portal_server/app/events/app_events.hpp"

#include <variant>

namespace utopia::portal::app {
using AppEvent =
    std::variant<AppEvents::Start, AppEvents::Stop, AppEvents::Tick>;
} // namespace utopia::portal::app
