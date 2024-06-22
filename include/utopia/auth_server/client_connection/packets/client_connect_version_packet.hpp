#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace utopia::auth::client_connection {

class ClientConnectVersionPacket {
public:
  ClientConnectVersionPacket() = default;
  ClientConnectVersionPacket(const std::vector<std::uint8_t> &data);

  std::uint8_t source = 0; // Default 0
  std::uint8_t length = 4; // Default 4
  std::uint16_t size = 12; // Default 12
  std::uint32_t version;
  std::uint32_t unk0 = 1; // Default 1
  std::uint32_t unk1 = 4; // Default 4

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const;

  bool is_valid() const { return is_valid_; }

private:
  bool is_valid_ = false;
};

} // namespace utopia::auth::client_connection
