#pragma once

#include <utf8.h>

#include <string>

namespace utopia::common {

inline std::string u16string_to_string(const std::u16string &u16str) {
  try {
    return utf8::utf16to8(u16str);
  } catch (const utf8::invalid_utf16 &) {
    return "Invalid u16string";
  } catch (const std::exception &) {
    return "Unable to convert u16string in Utopia-client.";
  }
}

} // namespace utopia::common
