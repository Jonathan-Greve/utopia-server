#pragma once

#include <mbedtls/sha1.h>
#include <spdlog/spdlog.h>

#include <array>
#include <cstdint>
#include <optional>
#include <vector>

namespace utopia::portal::client_connection {

inline std::optional<std::array<std::uint8_t, 20>>
sha1_concat_2_values(std::vector<std::uint8_t> part1,
                     std::vector<std::uint8_t> part2) {
  mbedtls_sha1_context ctx;
  mbedtls_sha1_init(&ctx);

  auto cleanup = [&ctx]() { mbedtls_sha1_free(&ctx); };

  int ret;
  if ((ret = mbedtls_sha1_starts_ret(&ctx)) != 0) {
    cleanup();
    return std::nullopt;
  }

  if ((ret = mbedtls_sha1_update_ret(&ctx, part1.data(), part1.size())) != 0) {
    cleanup();
    return std::nullopt;
  }

  if ((ret = mbedtls_sha1_update_ret(&ctx, part2.data(), part2.size())) != 0) {
    cleanup();
    return std::nullopt;
  }

  std::array<std::uint8_t, 20> concat_sha_1_result;
  if ((ret = mbedtls_sha1_finish_ret(&ctx, concat_sha_1_result.data())) != 0) {
    cleanup();
    return std::nullopt;
  }

  cleanup();

  return concat_sha_1_result;
}

} // namespace utopia::portal::client_connection
