#pragma once

namespace utopia::portal::client_connection {

struct TlsStates {
  struct WaitingOnClientHello {};
  struct ReceivedClientHello {};
  struct SentServerHelloReply {};
  struct SentServerKeyExchange {};
  struct SentServerHelloDone {};
  struct ReceivedClientKeyExchange {};
  struct ReceivedChangeCipherSpec {};
  struct ReceivedClientFinished {};
  struct ClientFinished {};
  struct SentCipherChangeSpec {};
  struct SentServerFinished {};
};

} // namespace utopia::portal::client_connection
