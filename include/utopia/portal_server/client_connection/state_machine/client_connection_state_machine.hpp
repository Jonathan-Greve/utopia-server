#pragma once

#include <boost/sml.hpp>

namespace sml = boost::sml;

namespace utopia::portal::app {

struct AppStateMachine {
  auto operator()() const noexcept {
    using namespace sml;
    using namespace utopia::common;
    // clang-format off
    return make_transition_table(
      * state<AppStates::Initializing> = state<AppStates::Running>
      
      , state<AppStates::Running> + event<AppEvents::Tick> / check_for_new_connections = state<AppStates::Running>
      
      , state<AppStates::Stopping> = X
    );
    // clang-format on
  }
};

} // namespace utopia::portal::app
