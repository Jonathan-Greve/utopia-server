#pragma once

namespace utopia::portal::client_connection {

struct TlsStates {
  struct WaitingOnClientHello {};
  struct ReceivedClientHello {};
  struct SentServerHelloReply {};
};

} // namespace utopia::portal::client_connection
