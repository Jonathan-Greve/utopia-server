#pragma once
#include "utopia/auth_server/client_connection/auth_client_connection_states.hpp"

#include <boost/sml.hpp>
#include <spdlog/spdlog.h>

namespace sml = boost::sml;

namespace utopia::auth::client_connection {

struct AuthClientConnectionStateMachine {
  auto operator()() const noexcept {
    using namespace sml;
    using namespace utopia::common;
    // clang-format off
    return make_transition_table(
      * state<AuthClientConnectionStates::Connected> = X
    );
    // clang-format on
  }
};

} // namespace utopia::auth::client_connection
