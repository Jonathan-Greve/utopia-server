#include "utopia/utopia_pch.hpp"

#include "utopia/common/network/gwuuid.hpp"

#include "utopia/common/network/endian/endian.hpp"

#include <array>
#include <cstdint>
#include <span>

namespace utopia::core {

GWUUID::GWUUID() noexcept
    : time_low(0), time_mid(0), time_hi_and_version(0),
      clock_seq_hi_and_reserved(0), clock_seq_low(0), node{} {}

void GWUUID::uuid_enc_le(void *buf, const GWUUID &u) {
  auto b = std::span<uint8_t, 16>(static_cast<uint8_t *>(buf), 16);
  le32_enc(b.subspan(0, 4).data(), u.time_low);
  le16_enc(b.subspan(4, 2).data(), u.time_mid);
  le16_enc(b.subspan(6, 2).data(), u.time_hi_and_version);
  b[8] = u.clock_seq_hi_and_reserved;
  b[9] = u.clock_seq_low;
  std::copy(u.node.begin(), u.node.end(), b.subspan(10, 6).begin());
}

} // namespace utopia::core
