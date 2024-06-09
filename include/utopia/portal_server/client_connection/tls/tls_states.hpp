#pragma once

namespace utopia::portal::client_connection {

struct TlsStates {
  struct WaitingOnClientHello {};
  struct ReceivedClientHello {};
  struct SentServerHelloReply {};
  struct SentServerKeyExchange {};
};

} // namespace utopia::portal::client_connection
