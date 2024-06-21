#pragma once

#include "utopia/auth_server/app/actions/check_for_new_connections.hpp"
#include "utopia/auth_server/app/auth_app_states.hpp"
#include "utopia/auth_server/app/events/auth_app_events.hpp"

#include <boost/sml.hpp>

namespace sml = boost::sml;

namespace utopia::auth::app {

struct AuthAppStateMachine {
  auto operator()() const noexcept {
    using namespace sml;
    using namespace utopia::common;
    // clang-format off
    return make_transition_table(
      * state<AuthAppStates::Initializing> = state<AuthAppStates::Running>
      
      , state<AuthAppStates::Running> + event<AuthAppEvents::Tick> / check_for_new_connections = state<AuthAppStates::Running>
      
      , state<AuthAppStates::Stopping> = X
    );
    // clang-format on
  }
};

} // namespace utopia::auth::app
