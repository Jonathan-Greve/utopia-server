#pragma once

namespace utopia::auth::client_connection {

struct AuthClientConnectionEvents {
  struct UnableToSendPacket {};
  struct SentSessionInfo {};
};

} // namespace utopia::auth::client_connection
