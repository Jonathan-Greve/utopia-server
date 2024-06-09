#pragma once

namespace utopia::portal::client_connection {

struct TlsEvents {
  struct UnableToSendPacket {};

  struct SentServerHelloReply {};

  struct SentServerKeyExchangePacket {};

  struct SentServerHelloDonePacket {};
};

} // namespace utopia::portal::client_connection
