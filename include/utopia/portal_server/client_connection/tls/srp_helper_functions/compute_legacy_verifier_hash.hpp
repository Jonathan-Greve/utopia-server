#pragma once

#include "utopia/common/network/endian/endian.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/compute_srp_verifier_hash.hpp"

#include <spdlog/spdlog.h>

#include <array>
#include <cstdint>
#include <optional>
#include <vector>

namespace utopia::portal::client_connection {

inline std::optional<std::array<std::uint8_t, 20>>
compute_legacy_verifier_hash(const std::vector<std::uint8_t> &username,
                             const std::vector<std::uint8_t> &password) {
  using namespace common;
  std::array<std::uint16_t, 256> buffer;

  const size_t buffer_required_size = (username.size() + password.size()) * 2;
  if (buffer.size() < buffer_required_size) {
    spdlog::error(
        "Buffer is too short ({}) for the current username and password",
        buffer.size());
    return std::nullopt;
  }

  size_t i = 0;
  for (size_t j = 0; j < password.size(); j++, i++) {
    if ((password[j] & ~0x7F) != 0) {
      spdlog::error("We currently don't support non-ascii character");
      return std::nullopt;
    }
    buffer[i] = static_cast<std::uint16_t>(password[i]);
  }

  for (size_t j = 0; j < username.size(); j++, i++) {
    if ((username[j] & ~0x7F) != 0) {
      spdlog::error("We currently don't support non-ascii character\n");
      return std::nullopt;
    }

    buffer[i] = static_cast<std::uint16_t>(username[j]);
  }

  constexpr auto verifier_size = 20;
  std::vector<std::uint8_t> temp_digest(20);
  if (int ret; (ret = mbedtls_sha1_ret(
                    reinterpret_cast<const std::uint8_t *>(buffer.data()),
                    buffer_required_size, temp_digest.data())) != 0) {
    return std::nullopt;
  }

  // Yeah, the encoding of the words are reversed...
  le32_enc(&temp_digest[0], be32_dec(&temp_digest[0]));
  le32_enc(&temp_digest[4], be32_dec(&temp_digest[4]));
  le32_enc(&temp_digest[8], be32_dec(&temp_digest[8]));
  le32_enc(&temp_digest[12], be32_dec(&temp_digest[12]));
  le32_enc(&temp_digest[16], be32_dec(&temp_digest[16]));

  return compute_srp_verifier_hash(username, temp_digest);
}

} // namespace utopia::portal::client_connection
