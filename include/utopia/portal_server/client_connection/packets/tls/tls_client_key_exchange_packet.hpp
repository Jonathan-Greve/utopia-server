#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

class TlsClientKeyExchangePacket {
public:
  TlsClientKeyExchangePacket() = default;
  TlsClientKeyExchangePacket(std::vector<uint8_t> &data);

  // Returns whether the packet is valid. I.e. if it was successfully parsed
  // Doesn't make sense to use this when sending the packet because it will
  // always be valid when sending due to the data members having default values.
  bool is_valid() const noexcept { return is_valid_; }

  // Get the size of the packet in bytes. I.e. the number of bytes of this
  // packet serialized. Not the size of this class in memory.
  std::uint32_t get_packet_size() const noexcept;

  std::vector<uint8_t> serialize();

  std::uint8_t type = 0x16;                        // byte 0
  std::uint16_t tls_version = 0x0303;              // bytes 1-2
  std::uint16_t size = 139;                        // bytes 3-4
  std::uint8_t msg_type = 16;                      // byte 5
  std::array<std::uint8_t, 3> msg_length{0, 0, 0}; // bytes 6-8

  std::uint16_t public_key_length = 128; // bytes 9-10
  std::array<uint8_t, 128> public_key{}; // bytes 11-138

private:
  bool is_valid_ = false;
};

} // namespace utopia::portal::client_connection
