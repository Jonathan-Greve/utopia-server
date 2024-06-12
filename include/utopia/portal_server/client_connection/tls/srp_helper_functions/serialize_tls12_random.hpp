#pragma once

#include "utopia/common/network/endian/endian.hpp"

#include <array>
#include <cstdint>

namespace utopia::portal::client_connection {
std::array<std::uint8_t, 64>
serialize_tls12_random(const std::array<std::uint8_t, 32> &client_random,
                       const std::array<std::uint8_t, 32> &server_random) {
  std::array<std::uint8_t, 64> result;
  std::uint32_t client_time;
  std::uint32_t server_time;
  std::memcpy(&client_time, client_random.data(), 4);
  std::memcpy(&server_time, server_random.data(), 4);

  common::be32_enc(result.data(), client_time);
  std::copy(client_random.begin() + 4, client_random.end(), result.begin() + 4);
  common::be32_enc(result.data() + 32, server_time);
  std::copy(server_random.begin() + 4, server_random.end(),
            result.begin() + 36);

  return result;
}
} // namespace utopia::portal::client_connection
