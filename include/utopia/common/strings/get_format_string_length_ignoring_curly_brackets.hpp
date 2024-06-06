#pragma once

#include <cstdint>
#include <string_view>

namespace utopia::common {

inline std::uint32_t get_format_string_length_ignoring_curly_brackets(
    std::string_view str) noexcept {
  std::uint32_t length = 0;
  bool inside_brackets = false;

  for (char ch : str) {
    if (ch == '{') {
      inside_brackets = true;
    } else if (ch == '}') {
      inside_brackets = false;
    } else if (!inside_brackets) {
      length++;
    }
  }

  return length;
}

} // namespace utopia::common
