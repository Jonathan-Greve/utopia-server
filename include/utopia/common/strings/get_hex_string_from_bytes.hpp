#pragma once

#include <cstdint>
#include <iomanip>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace utopia::common {

inline std::string
get_hex_string_from_bytes(const std::vector<std::uint8_t> bytes) {
  std::ostringstream hex_stream;
  for (const auto &byte : bytes) {
    hex_stream << std::hex << std::setw(2) << std::setfill('0')
               << (static_cast<int>(byte) & 0xff) << " ";
  }
  std::string hex_str = hex_stream.str();

  return hex_str;
}
} // namespace utopia::common
