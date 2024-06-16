#pragma once

#include <mbedtls/sha1.h>

#include <algorithm>
#include <array>
#include <cstdint>
#include <optional>
#include <vector>

namespace utopia::portal::client_connection {
inline std::optional<std::array<std::uint8_t, 20>>
sha1(const std::vector<std::uint8_t> &data) {
  mbedtls_sha1_context ctx;
  mbedtls_sha1_init(&ctx);

  auto cleanup = [&ctx]() { mbedtls_sha1_free(&ctx); };

  std::array<std::uint8_t, 20> sha1_result;

  if (mbedtls_sha1_starts_ret(&ctx) ||
      mbedtls_sha1_update_ret(&ctx, data.data(), data.size()) ||
      mbedtls_sha1_finish_ret(&ctx, sha1_result.data())) {
    cleanup();
    return std::nullopt;
  }

  cleanup();

  return sha1_result;
}
} // namespace utopia::portal::client_connection
