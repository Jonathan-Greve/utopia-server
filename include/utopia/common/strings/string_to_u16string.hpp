#pragma once

#include <utf8.h>

#include <string>

namespace utopia::common {

inline std::u16string string_to_u16string(const std::string &utf8str) {
  return utf8::utf8to16(utf8str);
}

} // namespace utopia::common

