#pragma once

#include <mbedtls/md.h>

#include <array>
#include <cstdint>
#include <optional>
#include <vector>

namespace utopia::portal::client_connection {

inline std::optional<std::vector<std::uint8_t>>
tls_prf_sha256(const std::vector<uint8_t> &secret,
               const std::vector<uint8_t> &label,
               const std::vector<uint8_t> &seed, std::size_t output_size) {

  std::vector<std::uint8_t> output(output_size, 0);

  constexpr auto sha256_digest_size = 32;
  constexpr auto max_concat_size = 111;
  std::array<std::uint8_t, sha256_digest_size> digest;
  std::array<std::uint8_t, max_concat_size> concat;

  size_t concat_len = sha256_digest_size + label.size() + seed.size();
  if (concat.size() < concat_len) {
    spdlog::error("Concat buffer isn't large enough, need {} bytes",
                  concat_len);
    return std::nullopt;
  }

  std::fill(concat.begin(), concat.begin() + sha256_digest_size, 0);
  std::copy(label.begin(), label.end(), concat.begin() + sha256_digest_size);
  std::copy(seed.begin(), seed.end(),
            concat.begin() + sha256_digest_size + label.size());

  const mbedtls_md_info_t *md_info;
  if ((md_info = mbedtls_md_info_from_type(MBEDTLS_MD_SHA256)) == nullptr) {
    return std::nullopt;
  }

  size_t md_len = mbedtls_md_get_size(md_info);
  if (md_len != digest.size()) {
    return std::nullopt;
  }

  mbedtls_md_context_t ctx;
  mbedtls_md_init(&ctx);

  auto cleanup = [&ctx]() { mbedtls_md_free(&ctx); };

  if (mbedtls_md_setup(&ctx, md_info, 1)) {
    cleanup();
    return std::nullopt;
  }

  if (mbedtls_md_hmac_starts(&ctx, secret.data(), secret.size())) {
    cleanup();
    return std::nullopt;
  }

  if (mbedtls_md_hmac_update(&ctx, concat.data() + sha256_digest_size,
                             concat_len - sha256_digest_size)) {
    cleanup();
    return std::nullopt;
  }
  if (mbedtls_md_hmac_finish(&ctx, concat.data())) {
    cleanup();
    return std::nullopt;
  }

  for (size_t i = 0; i < output_size; i += md_len) {
    if (mbedtls_md_hmac_reset(&ctx)) {
      cleanup();
      return std::nullopt;
    }
    if (mbedtls_md_hmac_update(&ctx, concat.data(), concat_len)) {

      cleanup();
      return std::nullopt;
    }
    if (mbedtls_md_hmac_finish(&ctx, digest.data())) {

      cleanup();
      return std::nullopt;
    }

    if (mbedtls_md_hmac_reset(&ctx)) {
      cleanup();
      return std::nullopt;
    }
    if (mbedtls_md_hmac_update(&ctx, concat.data(), md_len)) {
      cleanup();
      return std::nullopt;
    }
    if (mbedtls_md_hmac_finish(&ctx, concat.data())) {
      cleanup();
      return std::nullopt;
    }

    size_t k = (output_size < i + md_len) ? output_size % md_len : md_len;

    for (size_t j = 0; j < k; ++j)
      output[i + j] = digest[j];
  }

  cleanup();

  return output;
}

} // namespace utopia::portal::client_connection
