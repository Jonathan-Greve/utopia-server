#pragma once
#include "utopia/portal_server/client_connection/actions/disconnect.hpp"
#include "utopia/portal_server/client_connection/actions/handle_sts_connect_packet.hpp"
#include "utopia/portal_server/client_connection/actions/handle_sts_ping_packet.hpp"
#include "utopia/portal_server/client_connection/actions/handle_sts_start_tls_packet.hpp"
#include "utopia/portal_server/client_connection/actions/send_sts_list_my_game_accounts_reply_packet.hpp"
#include "utopia/portal_server/client_connection/actions/send_sts_login_finish_reply_packet.hpp"
#include "utopia/portal_server/client_connection/actions/send_sts_start_tls_reply_packet.hpp"
#include "utopia/portal_server/client_connection/client_connection_states.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_connect_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_list_my_game_accounts_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_login_finish_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_ping_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_request_game_token_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_start_tls_packet.hpp"
#include "utopia/portal_server/client_connection/tls/tls_state_machine.hpp"

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

      , state<ClientConnectionStates::ReceivedConnectPacket> + event<StsStartTlsPacket> / handle_sts_start_tls_packet
      , state<ClientConnectionStates::ReceivedConnectPacket> + event<ClientConnectionEvents::ReceivedValidStartTlsPacket> = state<ClientConnectionStates::ReceivedStartTlsPacket>

      , state<ClientConnectionStates::ReceivedStartTlsPacket> + on_entry<_> / send_sts_start_tls_reply_packet
      , state<ClientConnectionStates::ReceivedStartTlsPacket> + event<ClientConnectionEvents::SentStartTlsReplyPacket> = state<TlsStateMachine>

      , state<TlsStateMachine> + event<TlsEvents::HandshakeComplete> = state<ClientConnectionStates::TlsHandshakeComplete>

      , state<ClientConnectionStates::TlsHandshakeComplete> + event<StsLoginFinishPacket> = state<ClientConnectionStates::ReceivedLoginFinishPacket>

      , state<ClientConnectionStates::ReceivedLoginFinishPacket> + on_entry<_> / send_login_finish_reply_packet 
      , state<ClientConnectionStates::ReceivedLoginFinishPacket> + event<ClientConnectionEvents::SentLoginFinishReplyPacket> = state<ClientConnectionStates::LoggedIn>

      , state<ClientConnectionStates::LoggedIn> + event<StsListMyGameAccountsPacket> / send_list_my_game_accounts_reply_packet
      , state<ClientConnectionStates::LoggedIn> + event<StsRequestGameTokenPacket> = state<ClientConnectionStates::Stopping>
      
      , state<ClientConnectionStates::Stopping> / disconnect = X

      , state<_> + event<StsPingPacket> / handle_sts_ping_packet 
      , state<_> + event<ClientConnectionEvents::UnableToSendPacket> = X
    );
    // clang-format on
  }
};

} // namespace utopia::portal::client_connection
