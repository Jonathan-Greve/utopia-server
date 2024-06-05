#pragma once

namespace utopia::portal::client_connection {

struct ClientConnectionEvents {
  struct ClientDataReceived {
    std::vector<std::uint8_t> data;
  };

  struct UnableToParsePacket {};
  struct ReceivedValidConnectPacket {};
};

} // namespace utopia::portal::client_connection
