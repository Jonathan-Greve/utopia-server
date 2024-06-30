#pragma once

namespace utopia::auth::client_connection {

struct AuthClientConnectionEvents {
  struct UnableToSendPacket {};
  struct SentSessionInfo {};
  struct SentErrorMessage {};
};

} // namespace utopia::auth::client_connection
