#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {
class StsConnect {
public:
  StsConnect() = default;
  StsConnect(const std::vector<std::uint8_t> &data);

  std::uint32_t protocol_version_major;
  std::uint32_t protocol_version_minor;
  std::uint32_t xml_content_size;
  std::uint32_t conn_type;
  std::uint32_t product_type;
  std::string product_name;
  std::uint32_t app_index;
  std::uint64_t epoch;
  std::uint32_t program;
  std::uint32_t build;
  std::uint32_t process_id;

private:
  std::string xml_content_;
  bool is_valid_ = false;
};
} // namespace utopia::portal::client_connection
