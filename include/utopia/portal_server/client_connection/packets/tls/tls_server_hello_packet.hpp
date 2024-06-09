#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

class TlsServerHelloPacket {
public:
  TlsServerHelloPacket() = default;
  TlsServerHelloPacket(std::vector<uint8_t> &data);

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
  std::uint16_t size = 53;                         // bytes 3-4
  std::uint8_t msg_type = 2;                       // byte 5
  std::array<std::uint8_t, 3> msg_length{0, 0, 0}; // bytes 6-8
  std::uint16_t server_version = 0x0303;           // bytes 9-10
  std::array<std::uint8_t, 32> random;             // bytes 11-42
  std::uint8_t session_id = 0;                     // byte 43
  std::uint16_t cipher_suite = 0xFF04;             // byte 44-45

  std::uint8_t compression_method = 0;    // byte 46
  std::uint16_t extensions_length = 4;    // byte 47-48
  std::uint16_t extension0_type = 0xADAE; // byte 49-50
  std::uint16_t extension0_length = 0;    // byte 51-52

private:
  bool is_valid_ = false;
};

} // namespace utopia::portal::client_connection
