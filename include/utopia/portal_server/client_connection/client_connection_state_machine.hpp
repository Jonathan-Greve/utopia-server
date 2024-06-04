#pragma once
#include "utopia/portal_server/client_connection/client_connection_states.hpp"

#include <boost/sml.hpp>

namespace sml = boost::sml;

namespace utopia::portal::client_connection {

struct ClientConnectionStateMachine {
  auto operator()() const noexcept {
    using namespace sml;
    using namespace utopia::common;
    // clang-format off
    return make_transition_table(
      * state<ClientConnectionStates::Connected> = state<ClientConnectionStates::WaitingForClientConnectMsg>
      
      , state<ClientConnectionStates::Stopping> = X
    );
    // clang-format on
  }
};

} // namespace utopia::portal::client_connection
