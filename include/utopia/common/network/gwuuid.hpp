#pragma once

#include <array>
#include <cstdint>
#include <optional>

namespace utopia::common {

struct GWUUID {
  GWUUID() noexcept;
  std::uint32_t time_low;
  std::uint16_t time_mid;
  std::uint16_t time_hi_and_version;
  std::uint8_t clock_seq_hi_and_reserved;
  std::uint8_t clock_seq_low;
  std::array<std::uint8_t, 6> node;

  std::string to_string() const;

  static void uuid_enc_le(void *buf, const GWUUID &u);
  static std::optional<GWUUID> from_string(const std::string &str);
  static GWUUID generate();
};

} // namespace utopia::common
