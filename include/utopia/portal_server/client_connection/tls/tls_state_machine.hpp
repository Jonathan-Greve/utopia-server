#pragma once
#include "utopia/portal_server/client_connection/packets/tls/tls_client_hello_packet.hpp"
#include "utopia/portal_server/client_connection/tls/client_connection_states.hpp"

#include <boost/sml.hpp>
#include <spdlog/spdlog.h>

namespace sml = boost::sml;

namespace utopia::portal::client_connection {

struct TlsStateMachine {
  auto operator()() const noexcept {
    using namespace sml;
    using namespace utopia::common;
    // clang-format off
    return make_transition_table(
      * state<ClientConnectionStates::Connected> = state<ClientConnectionStates::WaitingForClientConnectMsg>
    );
    // clang-format on
  }
};

} // namespace utopia::portal::client_connection
