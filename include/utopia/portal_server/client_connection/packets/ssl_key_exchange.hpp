#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

class SslKeyExchangePacket {
public:
  SslKeyExchangePacket() = default;
  SslKeyExchangePacket(std::vector<uint8_t> &data);

  std::uint32_t get_packet_size();

  std::vector<uint8_t> serialize();

  const std::array<uint8_t, 128> &get_client_public_key() const noexcept;

private:
  bool is_valid_ = false;
  std::array<uint8_t, 128> client_public_key_;

  void generate_public_key();
};

} // namespace utopia::portal::client_connection
