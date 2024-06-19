#pragma once

namespace utopia::portal::client_connection {

struct ClientConnectionEvents {
  struct UnableToSendPacket {};

  struct ReceivedValidConnectPacket {};

  struct ReceivedValidStartTlsPacket {};
  struct SentStartTlsReplyPacket {};

  struct SentLoginFinishReplyPacket {};

  struct SentListMyGameAccountsReplyPacket {};

  struct SentRequestGameTokenReplyPacket {};
};

} // namespace utopia::portal::client_connection
