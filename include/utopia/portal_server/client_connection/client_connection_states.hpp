#pragma once

namespace utopia::portal::client_connection {

struct ClientConnectionStates {
  struct Disconnected {};
  struct WaitingForClientConnectMsg {};
  struct ReceivedClientConnectMsg {};
  struct Stopping {};
};

} // namespace utopia::portal::client_connection
