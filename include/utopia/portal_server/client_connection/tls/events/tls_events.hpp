#pragma once

namespace utopia::portal::client_connection {

struct TlsEvents {
  struct UnableToSendPacket {};

  struct SentServerHelloReply {};

  struct SentServerKeyExchangePacket {};

  struct SentServerHelloDonePacket {};

  struct FailedToDecryptMessage {};
  struct ClientFinishedVerifyDataMismatch {};
  struct ClientFinishedPacketHandled {};

  struct SentCipherChangeSpecPacket {};
  struct SentServerFinishedPacket {};
};

} // namespace utopia::portal::client_connection
