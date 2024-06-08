#pragma once

namespace utopia::portal::client_connection {

struct ClientConnectionEvents {
  struct UnableToSendPacket {};

  struct ReceivedValidConnectPacket {};

  struct ReceivedValidStartTlsPacket {};
  struct SentStartTlsReplyPacket {};
};

} // namespace utopia::portal::client_connection
