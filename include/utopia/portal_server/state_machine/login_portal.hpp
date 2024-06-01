#pragma once

#include <boost/sml.hpp>

namespace sml = boost::sml;

namespace utopia::portal {

struct LoginPortalStates {
  struct Initializing {};
  struct Running {};
  struct Stopping {};
};

struct LoginPortalStateMachine {
  auto operator()() const noexcept {
    using namespace sml;

    // clang-format off
    return make_transition_table(
        * state<Initializing> = state<Running>
        , state<LoginPortalStates::Running> +  state<LoginPortalStates::Stopping>
    );
    // clang-format on
  }
};

} // namespace utopia::portal
