#pragma once

namespace utopia::portal::client_connection {

struct TlsEvents {
  struct UnableToSendPacket {};

  struct SentServerHelloReply {};

  struct SentServerKeyExchangePacket {};

  struct SentServerHelloDonePacket {};

  struct FailedToDecryptMessage {};
  struct ClientFinishedVerifyDataMismatch {};
  struct HmacValidationFailed {};
  struct HmacComputationFailed {};
  struct ClientFinishedPacketHandled {};

  struct SentCipherChangeSpecPacket {};

  struct FailedToIssueNextIV {};
  struct SentServerFinishedPacket {};

  struct HandshakeComplete {};
};

} // namespace utopia::portal::client_connection
