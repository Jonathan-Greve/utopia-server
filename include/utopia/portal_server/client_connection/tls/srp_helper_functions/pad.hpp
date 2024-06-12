#pragma once

#include <cassert>
#include <cstdint>
#include <iterator>
#include <vector>

namespace utopia::portal::client_connection {

template <typename Range>
std::vector<std::uint8_t> pad(const Range &data, std::uint32_t output_size) {
  static_assert(std::ranges::contiguous_range<Range> &&
                    std::ranges::sized_range<Range>,
                "Range must be contiguous and sized");

  std::vector<std::uint8_t> padded_data(output_size, 0);

  auto data_size = std::ranges::size(data);
  assert(data_size <= output_size);

  std::copy(data.begin(), data.end(), padded_data.end() - data_size);

  assert(padded_data.size() == output_size);
  return padded_data;
}

} // namespace utopia::portal::client_connection
