#pragma once

namespace utopia::portal::client_connection {

struct ClientConnectionEvents {
  struct ClientDataReceived {
    std::vector<std::uint8_t> data;
  };

  struct UnableToParseMessage {};
};

} // namespace utopia::portal::client_connection
