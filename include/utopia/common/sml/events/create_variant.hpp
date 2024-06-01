#pragma once

#include <boost/mp11.hpp>

#include <array>
#include <cassert>
#include <cstdint>
#include <utility>
#include <variant>
#include <vector>

namespace utopia::common {

template <typename V, typename... Args>
auto create_variant(size_t index, Args &&...args) -> V {
  using namespace boost::mp11;
  return mp_with_index<mp_size<V>>(index, [&](auto I) {
    return V{std::in_place_index<I>, std::forward<Args>(args)...};
  });
}

} // namespace utopia::common
