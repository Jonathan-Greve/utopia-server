#pragma once

#include "utopia/common/network/endian/endian.hpp"

#include <array>
#include <cstdint>

namespace utopia::portal::client_connection {
inline std::vector<std::uint8_t>
serialize_tls12_random(const std::array<std::uint8_t, 32> &client_random,
                       const std::array<std::uint8_t, 32> &server_random) {
  std::vector<std::uint8_t> result(64);
  std::copy(client_random.begin(), client_random.end(), result.begin());
  std::copy(server_random.begin(), server_random.end(), result.begin() + 32);

  return result;
}
} // namespace utopia::portal::client_connection
