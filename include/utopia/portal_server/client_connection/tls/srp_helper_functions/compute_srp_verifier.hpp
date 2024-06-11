#pragma once

#include <mbedtls/sha1.h>

#include <array>
#include <cstdint>
#include <optional>
#include <vector>

namespace utopia::portal::client_connection {

inline std::optional<std::array<std::uint8_t, 20>>
compute_srp_verifier(const std::vector<std::uint8_t> &username,
                     const std::vector<std::uint8_t> &password) {
  mbedtls_sha1_context ctx;
  mbedtls_sha1_init(&ctx);
  constexpr std::uint8_t separator = ':';

  auto cleanup = [&ctx]() { mbedtls_sha1_free(&ctx); };

  int ret = 0;
  if ((ret = mbedtls_sha1_starts_ret(&ctx)) != 0) {
    cleanup();
    return std::nullopt;
  }

  if ((ret = mbedtls_sha1_update_ret(&ctx, username.data(), username.size())) !=
      0) {
    cleanup();
    return std::nullopt;
  }

  if ((ret = mbedtls_sha1_update_ret(&ctx, &separator, sizeof(separator))) !=
      0) {
    cleanup();
    return std::nullopt;
  }

  if ((ret = mbedtls_sha1_update_ret(&ctx, password.data(), password.size())) !=
      0) {
    cleanup();
    return std::nullopt;
  }

  std::array<std::uint8_t, 20> verifier;
  if ((ret = mbedtls_sha1_finish_ret(&ctx, verifier.data())) != 0) {
    cleanup();
    return std::nullopt;
  }

  cleanup();

  return verifier;
}

} // namespace utopia::portal::client_connection
