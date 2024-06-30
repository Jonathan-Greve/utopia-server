#pragma once

namespace utopia::auth::client_connection {

struct AuthClientConnectionStates {
  struct Connected {};
  struct ReceivedComputerUserInfo {};
  struct ReceivedGameInfo {};
  struct SessionInfoSent {};
  struct PortalAccountLoginReceived {};
};

} // namespace utopia::auth::client_connection
