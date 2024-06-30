#pragma once
#include "utopia/auth_server/client_connection/actions/handle_computer_info.hpp"
#include "utopia/auth_server/client_connection/actions/handle_game_info.hpp"
#include "utopia/auth_server/client_connection/actions/handle_portal_account_login.hpp"
#include "utopia/auth_server/client_connection/actions/send_heartbeat_reply.hpp"
#include "utopia/auth_server/client_connection/actions/send_session_info.hpp"
#include "utopia/auth_server/client_connection/auth_client_connection_states.hpp"
#include "utopia/auth_server/client_connection/events/auth_client_connection_events.hpp"
#include "utopia/common/network/packets/generated/auth_client_packets.hpp"

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
      * state<AuthClientConnectionStates::Connected> + event<AuthClientComputerUserInfo> / handle_computer_info = state<AuthClientConnectionStates::ReceivedComputerUserInfo>

      , state<AuthClientConnectionStates::ReceivedComputerUserInfo> + event<AuthClientGameInfo> / handle_game_info = state<AuthClientConnectionStates::ReceivedGameInfo>

      , state<AuthClientConnectionStates::ReceivedGameInfo> + on_entry<_> / send_session_info 
      , state<AuthClientConnectionStates::ReceivedGameInfo> + event<AuthClientConnectionEvents::SentSessionInfo> = state<AuthClientConnectionStates::SessionInfoSent>
      , state<AuthClientConnectionStates::ReceivedGameInfo> + event<AuthClientConnectionEvents::UnableToSendPacket> = X

      , state<AuthClientConnectionStates::SessionInfoSent> + event<AuthClientPortalAccountLogin> / handle_portal_account_login = state<AuthClientConnectionStates::PortalAccountLoginReceived>

      , state<_> + event<AuthClientHeartbeat> / send_heartbeat_reply
    );
    // clang-format on
  }
};

} // namespace utopia::auth::client_connection
