#pragma once

#include <mbedtls/md.h>
#include <mbedtls/sha256.h>

#include <array>
#include <cstdint>
#include <optional>
#include <vector>

namespace utopia::portal::client_connection {

std::optional<std::vector<std::uint8_t>>
tls_prf_sha256(const std::vector<std::uint8_t> &secret,
               const std::vector<std::uint8_t> &label,
               const std::vector<std::uint8_t> &seed,
               std::uint32_t output_size) {
  std::vector<std::uint8_t> output(output_size, 0);

  constexpr sha256_digest_size = 32;
  constexpr max_concat_size = 111;
  std::array<std::uint8_t, sha256_digest_size> digest;
  std::array<std::uint8_t, max_concat_size> concat;

  size_t concat_len = sha256_digest_size + label_len + random_len;
  if (concat.size() < concat_len) {
    spdlog::error("Concat buffer isn't large enough, need {} bytes",
                  concat_len);
    return std::nullopt;
  }

  std::fill(concat.begin(), concat.begin() + sha256_digest_size, 0);
  std::copy(label.begin(), label.end(), concat.begin() + sha256_digest_size);
  std::copy(random.begin(), random.end(),
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

  if (mbedtls_md_hmac_starts(&ctx, secret, secret_len)) {
    cleanup();
    return std::nullopt;
  }

  if (mbedtls_md_hmac_update(&ctx, concat + sha256_digest_size,
                             concat_len - sha256_digest_size)) {
    cleanup();
    return std::nullopt;
  }
  if (mbedtls_md_hmac_finish(&ctx, concat)) {
    cleanup();
    return std::nullopt;
  }

  for (size_t i = 0; i < output_len; i += md_len) {
    if (mbedtls_md_hmac_reset(&ctx)) {
      cleanup();
      return std::nullopt;
    }
    if (mbedtls_md_hmac_update(&ctx, concat, concat_len)) {

      cleanup();
      return std::nullopt;
    }
    if (mbedtls_md_hmac_finish(&ctx, digest)) {

      cleanup();
      return std::nullopt;
    }

    if (mbedtls_md_hmac_reset(&ctx)) {
      cleanup();
      return std::nullopt;
    }
    if (mbedtls_md_hmac_update(&ctx, concat, md_len)) {
      cleanup();
      return std::nullopt;
    }
    if (mbedtls_md_hmac_finish(&ctx, concat)) {
      cleanup();
      return std::nullopt;
    }

    size_t k = (output_len < i + md_len) ? output_len % md_len : md_len;

    for (size_t j = 0; j < k; ++j)
      output[i + j] = digest[j];
  }

  cleanup();

  return output;
}

} // namespace utopia::portal::client_connection
