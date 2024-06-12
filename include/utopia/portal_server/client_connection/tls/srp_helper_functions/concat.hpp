#pragma once

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iterator>
#include <ranges>
#include <vector>

namespace utopia::portal::client_connection {

template <typename... Ranges>
std::vector<std::uint8_t> concat(const Ranges &...data) {
  static_assert((std::ranges::contiguous_range<Ranges> && ...),
                "Each range must be contiguous");
  static_assert((std::ranges::sized_range<Ranges> && ...),
                "Each range must be sized");

  std::vector<std::uint8_t> result;
  result.reserve((std::ranges::size(data) + ...));

  (result.insert(result.end(), std::ranges::begin(data),
                 std::ranges::end(data)),
   ...);

  return result;
}

} // namespace utopia::portal::client_connection
