#pragma once
#include "utopia/portal_server/client_connection/actions/handle_sts_connect_packet.hpp"
#include "utopia/portal_server/client_connection/actions/send_sts_connect_reply_packet.hpp"
#include "utopia/portal_server/client_connection/client_connection_states.hpp"

#include <boost/sml.hpp>
#include <spdlog/spdlog.h>

namespace sml = boost::sml;

namespace utopia::portal::client_connection {

struct ClientConnectionStateMachine {
  auto operator()() const noexcept {
    using namespace sml;
    using namespace utopia::common;
    // clang-format off
    return make_transition_table(
      * state<ClientConnectionStates::Connected> = state<ClientConnectionStates::WaitingForClientConnectMsg>

      , state<ClientConnectionStates::WaitingForClientConnectMsg> + event<ClientConnectionEvents::ClientDataReceived> / handle_sts_connect_packet 
      , state<ClientConnectionStates::WaitingForClientConnectMsg> + event<ClientConnectionEvents::ReceivedValidConnectPacket> = state<ClientConnectionStates::ReceivedConnectPacket> 
      , state<ClientConnectionStates::WaitingForClientConnectMsg> + event<ClientConnectionEvents::UnableToParsePacket> = state<ClientConnectionStates::Stopping> 

      , state<ClientConnectionStates::ReceivedConnectPacket> + on_entry<_> / send_sts_connect_reply_packet 
      
      , state<ClientConnectionStates::Stopping> = X
    );
    // clang-format on
  }
};

} // namespace utopia::portal::client_connection
