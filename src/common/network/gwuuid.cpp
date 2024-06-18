#include "utopia/utopia_pch.hpp"

#include "utopia/common/network/gwuuid.hpp"

#include "utopia/common/network/endian/endian.hpp"

#include <scn/scan.h>

#include <array>
#include <cstdint>
#include <optional>
#include <random>
#include <span>
#include <string>

namespace utopia::common {

GWUUID::GWUUID() noexcept
    : time_low(0), time_mid(0), time_hi_and_version(0),
      clock_seq_hi_and_reserved(0), clock_seq_low(0), node{} {}

std::string GWUUID::to_string() const {
  return fmt::format(
      "{:08x}-{:04x}-{:04x}-{:02x}{:02x}-{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}",
      time_low, time_mid, time_hi_and_version, clock_seq_hi_and_reserved,
      clock_seq_low, node[0], node[1], node[2], node[3], node[4], node[5]);
}

void GWUUID::uuid_enc_le(void *buf, const GWUUID &u) {
  auto b = std::span<uint8_t, 16>(static_cast<uint8_t *>(buf), 16);
  le32_enc(b.subspan(0, 4).data(), u.time_low);
  le16_enc(b.subspan(4, 2).data(), u.time_mid);
  le16_enc(b.subspan(6, 2).data(), u.time_hi_and_version);
  b[8] = u.clock_seq_hi_and_reserved;
  b[9] = u.clock_seq_low;
  std::copy(u.node.begin(), u.node.end(), b.subspan(10, 6).begin());
}

std::optional<GWUUID> GWUUID::from_string(const std::string &str) {
  GWUUID u;
  auto scan_result =
      scn::scan<uint32_t, uint16_t, uint16_t, uint8_t, uint8_t, uint8_t,
                uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>(
          str, "{:8x}-{:4x}-{:4x}-{:2x}{:2x}-{:2x}{:2x}{:2x}{:2x}{:2x}{:2x}");

  if (!scan_result) {
    return std::nullopt;
  }

  auto &[time_low, time_mid, time_hi_and_version, clock_seq_hi_and_reserved,
         clock_seq_low, node0, node1, node2, node3, node4, node5] =
      scan_result->values();

  u.time_low = time_low;
  u.time_mid = time_mid;
  u.time_hi_and_version = time_hi_and_version;
  u.clock_seq_hi_and_reserved = clock_seq_hi_and_reserved;
  u.clock_seq_low = clock_seq_low;
  u.node = {node0, node1, node2, node3, node4, node5};

  return u;
}

GWUUID GWUUID::generate() {
  GWUUID u;
  u.time_low = std::rand();
  u.time_mid = std::rand();
  u.time_hi_and_version = std::rand();
  u.clock_seq_hi_and_reserved = std::rand();
  u.clock_seq_low = std::rand();
  for (auto &n : u.node) {
    n = std::rand();
  }
  return u;
}

} // namespace utopia::common
