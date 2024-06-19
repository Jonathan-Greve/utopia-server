#pragma once

namespace utopia::portal::client_connection {

struct ClientConnectionStates {
  struct Connected {};
  struct WaitingForClientConnectMsg {};
  struct ReceivedConnectPacket {};
  struct ReceivedStartTlsPacket {};
  struct SentStartTlsReplyPacket {};
  struct TlsHandshakeComplete {};
  struct ReceivedLoginFinishPacket {};
  struct LoggedIn {};
  struct ReceivedListMyGameAccountsPacket {};
  struct Stopping {};
};

} // namespace utopia::portal::client_connection
