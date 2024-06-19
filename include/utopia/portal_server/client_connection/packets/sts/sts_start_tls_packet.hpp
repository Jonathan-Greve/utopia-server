#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {
class StsStartTlsPacket {
public:
  StsStartTlsPacket() = default;
  StsStartTlsPacket(const std::vector<std::uint8_t> &data) noexcept;

  // Returns whether the packet is valid. I.e. if it was successfully parsed
  // Doesn't make sense to use this when sending the packet because it will
  // always be valid when sending due to the data members having default values.
  bool is_valid() const noexcept { return is_valid_; }

  // Get the size of the packet in bytes. I.e. the number of bytes of this
  // packet serialized. Not the size of this class in memory.
  std::uint32_t get_packet_size() const noexcept;

  std::vector<std::uint8_t> serialize() noexcept;

  std::uint32_t protocol_version_major;
  std::uint32_t protocol_version_minor;
  std::uint32_t sequence_number;
  std::uint32_t timeout_ms;
  std::uint32_t xml_content_size;

private:
  std::string xml_content_;
  bool is_valid_ = false;

  // This packet uses two almost similar variants for its header.
  bool alternative_scan_str_used = false;
};
} // namespace utopia::portal::client_connection
