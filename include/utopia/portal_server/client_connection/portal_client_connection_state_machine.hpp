#pragma once
#include "utopia/portal_server/client_connection/actions/disconnect.hpp"
#include "utopia/portal_server/client_connection/actions/handle_sts_connect_packet.hpp"
#include "utopia/portal_server/client_connection/actions/handle_sts_ping_packet.hpp"
#include "utopia/portal_server/client_connection/actions/handle_sts_start_tls_packet.hpp"
#include "utopia/portal_server/client_connection/actions/send_sts_list_my_game_accounts_reply_packet.hpp"
#include "utopia/portal_server/client_connection/actions/send_sts_login_finish_reply_packet.hpp"
#include "utopia/portal_server/client_connection/actions/send_sts_request_game_token_reply_packet.hpp"
#include "utopia/portal_server/client_connection/actions/send_sts_start_tls_reply_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_connect_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_list_my_game_accounts_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_login_finish_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_ping_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_request_game_token_packet.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_start_tls_packet.hpp"
#include "utopia/portal_server/client_connection/portal_client_connection_states.hpp"
#include "utopia/portal_server/client_connection/tls/tls_state_machine.hpp"

#include <boost/sml.hpp>
#include <spdlog/spdlog.h>

namespace sml = boost::sml;

namespace utopia::portal::client_connection {

struct PortalClientConnectionStateMachine {
  auto operator()() const noexcept {
    using namespace sml;
    using namespace utopia::common;
    // clang-format off
    return make_transition_table(
      * state<PortalClientConnectionStates::Connected> = state<PortalClientConnectionStates::WaitingForClientConnectMsg>

      , state<PortalClientConnectionStates::WaitingForClientConnectMsg> + event<StsConnectPacket> / handle_sts_connect_packet 
      , state<PortalClientConnectionStates::WaitingForClientConnectMsg> + event<PortalClientConnectionEvents::ReceivedValidConnectPacket> = state<PortalClientConnectionStates::ReceivedConnectPacket> 

      , state<PortalClientConnectionStates::ReceivedConnectPacket> + event<StsStartTlsPacket> / handle_sts_start_tls_packet
      , state<PortalClientConnectionStates::ReceivedConnectPacket> + event<PortalClientConnectionEvents::ReceivedValidStartTlsPacket> = state<PortalClientConnectionStates::ReceivedStartTlsPacket>

      , state<PortalClientConnectionStates::ReceivedStartTlsPacket> + on_entry<_> / send_sts_start_tls_reply_packet
      , state<PortalClientConnectionStates::ReceivedStartTlsPacket> + event<PortalClientConnectionEvents::SentStartTlsReplyPacket> = state<TlsStateMachine>

      , state<TlsStateMachine> + event<TlsEvents::HandshakeComplete> = state<PortalClientConnectionStates::TlsHandshakeComplete>

      , state<PortalClientConnectionStates::TlsHandshakeComplete> + event<StsLoginFinishPacket> = state<PortalClientConnectionStates::ReceivedLoginFinishPacket>

      , state<PortalClientConnectionStates::ReceivedLoginFinishPacket> + on_entry<_> / send_login_finish_reply_packet 
      , state<PortalClientConnectionStates::ReceivedLoginFinishPacket> + event<PortalClientConnectionEvents::SentLoginFinishReplyPacket> = state<PortalClientConnectionStates::LoggedIn>

      , state<PortalClientConnectionStates::LoggedIn> + event<StsListMyGameAccountsPacket> / send_list_my_game_accounts_reply_packet
      , state<PortalClientConnectionStates::LoggedIn> + event<StsRequestGameTokenPacket> / send_request_game_token_reply_packet
      
      , state<PortalClientConnectionStates::Stopping> / disconnect = X

      , state<_> + event<StsPingPacket> / handle_sts_ping_packet 
      , state<_> + event<PortalClientConnectionEvents::UnableToSendPacket> = X
    );
    // clang-format on
  }
};

} // namespace utopia::portal::client_connection
