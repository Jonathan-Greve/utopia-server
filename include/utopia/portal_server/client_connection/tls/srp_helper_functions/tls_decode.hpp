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

  return decrypted_msg;
}

} // namespace utopia::portal::client_connection
