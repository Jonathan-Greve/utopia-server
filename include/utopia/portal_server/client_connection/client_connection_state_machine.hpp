#pragma once
#include "utopia/portal_server/client_connection/actions/handle_sts_connect_packet.hpp"
#include "utopia/portal_server/client_connection/actions/handle_sts_ping_packet.hpp"
#include "utopia/portal_server/client_connection/actions/handle_sts_start_tls_packet.hpp"
#include "utopia/portal_server/client_connection/actions/send_sts_connect_reply_packet.hpp"
#include "utopia/portal_server/client_connection/actions/send_sts_start_tls_reply_packet.hpp"
#include "utopia/portal_server/client_connection/client_connection_states.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_connect_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_ping_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_start_tls_packet.hpp"

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

      , state<ClientConnectionStates::WaitingForClientConnectMsg> + event<StsConnectPacket> / handle_sts_connect_packet 
      , state<ClientConnectionStates::WaitingForClientConnectMsg> + event<ClientConnectionEvents::ReceivedValidConnectPacket> = state<ClientConnectionStates::ReceivedConnectPacket> 

      , state<ClientConnectionStates::ReceivedConnectPacket> + on_entry<_> / send_sts_connect_reply_packet 
      , state<ClientConnectionStates::ReceivedConnectPacket> + event<ClientConnectionEvents::SentConnectReplyPacket> = state<ClientConnectionStates::SentConnectReplyPacket>

      , state<ClientConnectionStates::SentConnectReplyPacket> + event<StsStartTlsPacket> / handle_sts_start_tls_packet
      , state<ClientConnectionStates::SentConnectReplyPacket> + event<ClientConnectionEvents::ReceivedValidStartTlsPacket> = state<ClientConnectionStates::ReceivedStartTlsPacket>

      , state<ClientConnectionStates::ReceivedStartTlsPacket> + on_entry<_> / send_sts_start_tls_reply_packet
      , state<ClientConnectionStates::ReceivedStartTlsPacket> + event<ClientConnectionEvents::SentStartTlsReplyPacket> = state<ClientConnectionStates::SentStartTlsReplyPacket>
      
      , state<ClientConnectionStates::Stopping> = X

      , state<_> + event<StsPingPacket> / handle_sts_ping_packet 
    );
    // clang-format on
  }
};

} // namespace utopia::portal::client_connection
