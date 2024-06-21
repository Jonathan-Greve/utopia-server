#pragma once

#include "utopia/auth_server/app/events/auth_app_events.hpp"

#include <variant>

namespace utopia::auth::app {
using AuthAppEvent = std::variant<AuthAppEvents::Start, AuthAppEvents::Stop,
                                  AuthAppEvents::Tick>;
} // namespace utopia::auth::app
