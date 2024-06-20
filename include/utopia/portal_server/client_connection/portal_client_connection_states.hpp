#pragma once

namespace utopia::portal::client_connection {

struct PortalClientConnectionStates {
  struct Connected {};
  struct WaitingForClientConnectMsg {};
  struct ReceivedConnectPacket {};
  struct ReceivedStartTlsPacket {};
  struct SentStartTlsReplyPacket {};
  struct TlsHandshakeComplete {};
  struct ReceivedLoginFinishPacket {};
  struct LoggedIn {};
};

} // namespace utopia::portal::client_connection
