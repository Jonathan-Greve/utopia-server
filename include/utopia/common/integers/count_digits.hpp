#pragma once

#include <cstdint>

namespace utopia::common {

inline std::uint32_t count_digits(std::uint32_t n) noexcept {
  std::uint32_t count = 0;
  while (n != 0) {
    n /= 10;
    ++count;
  }
  return count;
}

} // namespace utopia::common
