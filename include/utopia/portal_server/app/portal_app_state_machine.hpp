#pragma once

#include "utopia/portal_server/app/actions/check_for_new_connections.hpp"
#include "utopia/portal_server/app/events/portal_app_events.hpp"
#include "utopia/portal_server/app/portal_app_states.hpp"

#include <boost/sml.hpp>

namespace sml = boost::sml;

namespace utopia::portal::app {

struct PortalAppStateMachine {
  auto operator()() const noexcept {
    using namespace sml;
    using namespace utopia::common;
    // clang-format off
    return make_transition_table(
      * state<PortalAppStates::Initializing> = state<PortalAppStates::Running>
      
      , state<PortalAppStates::Running> + event<PortalAppEvents::Tick> / check_for_new_connections = state<PortalAppStates::Running>
      
      , state<PortalAppStates::Stopping> = X
    );
    // clang-format on
  }
};

} // namespace utopia::portal::app
