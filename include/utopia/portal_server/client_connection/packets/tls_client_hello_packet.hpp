#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

class TlsClientHelloPacket {
public:
  TlsClientHelloPacket() = default;
  TlsClientHelloPacket(std::vector<uint8_t> &data);

  std::uint32_t get_packet_size();

  std::vector<uint8_t> serialize();

  std::uint8_t type = 0x16;                        // byte 0
  std::uint16_t tls_version = 0x0303;              // bytes 1-2
  std::uint16_t size = 0;                          // bytes 3-4
  std::uint8_t msg_type = 1;                       // byte 5
  std::array<std::uint8_t, 3> msg_length{0, 0, 0}; // bytes 6-8
  std::uint16_t client_version = 0x0303;           // bytes 9-10
  std::array<std::uint8_t, 32> random;             // bytes 11-42
  std::uint8_t session_id = 0;                     // byte 43
  std::array<std::uint16_t, 6> cipther_suites{0xC020, 0xC01D,
                                              0xFF02, 0xFF01, // bytes 44-55
                                              0xFF04, 0xFF03};
  std::array<std::uint8_t, 2> compression_methods{1, 0}; // bytes 56-57
  std::uint16_t extensions_length = 0;                   // bytes 58-59
  std::uint16_t extension0_type = 0xADAE;                // bytes 60-61
  std::uint16_t extension0_length = 0;                   // bytes 62-63
  std::uint16_t extension_srp_type = 0x000c;             // bytes 64-65
  std::uint16_t extension_srp_length = 0;                // byte 66-67
  std::uint8_t extension_srp_data_length = 0;            // byte 68
  std::vector<std::uint8_t> extension_srp_data;          // bytes 69-end

private:
  bool is_valid_ = false;
};

} // namespace utopia::portal::client_connection
