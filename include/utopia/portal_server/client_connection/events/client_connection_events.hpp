#pragma once

namespace utopia::portal::client_connection {

struct ClientConnectionEvents {
  struct UnableToSendPacket {};

  struct ReceivedValidConnectPacket {};
  struct SentConnectReplyPacket {};
};

} // namespace utopia::portal::client_connection
