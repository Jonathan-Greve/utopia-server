#pragma once

#include "utopia/common/network/endian/endian.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <mbedtls/aes.h>
#include <mbedtls/md.h>
#include <mbedtls/sha256.h>

#include <algorithm>
#include <cstdint>
#include <optional>
#include <vector>

namespace utopia::portal::client_connection {

inline std::optional<std::vector<uint8_t>>
tls_decode(std::vector<uint8_t> &data, TlsContext &context) {
  if (data.size() < 21) {
    spdlog::error("Unable to decode message with invalid size (too short).");
  }

  std::uint8_t type = data[0];
  std::uint16_t tls_version = utopia::common::be16_dec(data.data() + 1);

  if (tls_version != 0x0303) {
    spdlog::error("Unable to decode message with invalid TLS version.");
    return std::nullopt;
  }

  std::uint16_t size = utopia::common::be16_dec(data.data() + 3);

  // Encrypted msg is always padded to 16 bytes
  if (size == 0 || size % 16 != 0) {
    spdlog::error("Unable to decode message with invalid size.");
    return std::nullopt;
  }

  std::vector<uint8_t> iv_enc(16);
  std::copy(data.begin() + 5, data.begin() + 21, iv_enc.begin());

  std::vector<uint8_t> encrypted_msg(size - iv_enc.size());
  std::copy(data.begin() + 21, data.begin() + 5 + size, encrypted_msg.begin());

  std::vector<std::uint8_t> decrypted_msg(size - iv_enc.size());
  if (mbedtls_aes_crypt_cbc(&context.cipher_dec, MBEDTLS_AES_DECRYPT,
                            encrypted_msg.size(), iv_enc.data(),
                            encrypted_msg.data(), decrypted_msg.data())) {
    spdlog::error("Failed to decrypt message.");
    return std::nullopt;
  }

  //   // Compute HMAC
  //   mbedtls_md_hmac_reset(&context.mac_dec);
  //   mbedtls_md_hmac_update(&context.mac_dec, context.next_read_id.data(),
  //                          context.next_read_id.size());

  //   // Compute HMAC
  //   if (mbedtls_md_hmac_update(&context.mac_dec, data.data(), 5)) {
  //     spdlog::error("Failed to update HMAC context with modified header.");
  //     return std::nullopt;
  //   }

  //   // Decrypted msg header (4bytes) + verify_data (12bytes)
  //   if (mbedtls_md_hmac_update(&context.mac_dec, decrypted_msg.data(), 16)) {
  //     spdlog::error("Failed to update HMAC context with modified header.");
  //     return std::nullopt;
  //   }

  //   std::array<std::uint8_t, 20> calculated_hmac;
  //   if (mbedtls_md_hmac_finish(&mac_ctx, calculated_hmac.data())) {
  //     spdlog::error("Failed to finish HMAC calculation.");
  //     return std::nullopt;
  //   }

  //   common::be64_enc(context.next_read_id.data(),
  //                    common::be64_dec(context.next_read_id.data()) + 1);

  //   if (!calculated_hmac) {
  //     spdlog::error("Failed to compute HMAC.");
  //     return std::nullopt;
  //   }

  //   // Validate the HMAC. The HMAC is 20 bytes but we don't know the exact
  //   start
  //   // position due to padding.
  //   const auto found_it = std::search(decrypted_msg.begin(),
  //   decrypted_msg.end(),
  //                                     calculated_hmac.value().begin(),
  //                                     calculated_hmac.value().end());

  //   if (found_it == decrypted_msg.end()) {
  //     spdlog::error("Decrypt and verify HMAC validation failed");
  //     return std::nullopt;
  //   }

  //   // Return the decrypted message without the HMAC and padding
  //   std::vector<uint8_t> decrypted_msg_without_hmac(decrypted_msg.begin(),
  //                                                   found_it);

  return decrypted_msg;
}

} // namespace utopia::portal::client_connection
