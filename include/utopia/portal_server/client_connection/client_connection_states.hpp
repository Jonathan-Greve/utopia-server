#pragma once

namespace utopia::portal::client_connection {

struct ClientConnectionStates {
  struct Connected {};
  struct WaitingForClientConnectMsg {};
  struct ReceivedConnectPacket {};
  struct SentConnectReplyPacket {};
  struct ReceivedStartTlsPacket {};
  struct SentStartTlsReplyPacket {};
  struct Stopping {};
};

} // namespace utopia::portal::client_connection
