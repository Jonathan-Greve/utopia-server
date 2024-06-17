#pragma once

#include "utopia/common/network/endian/endian.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/tls_compute_handshake_finished_hmac.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/tls_issue_next_iv.hpp"
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
tls_encode_with_hmac_and_padding(std::vector<uint8_t> &msg,
                                 std::vector<std::uint8_t> tls_header,
                                 TlsContext &context) {
  assert(tls_header.size() >= 5);

  auto iv_enc_opt = tls_issue_next_iv(context);

  if (!iv_enc_opt) {
    spdlog::error("Failed to issue next IV.");
    return std::nullopt;
  }
  assert(iv_enc_opt.value() == context.iv_enc);

  const auto calculated_hmac = tls_compute_handshake_finished_hmac(
      context.next_write_id, tls_header, msg, context, context.mac_enc,
      static_cast<std::uint32_t>(msg.size()));

  if (!calculated_hmac) {
    spdlog::error("Failed to compute HMAC.");
    return std::nullopt;
  }

  std::vector<std::uint8_t> msg_to_encrypt;
  msg_to_encrypt.insert(msg_to_encrypt.end(), msg.begin(), msg.end());
  msg_to_encrypt.insert(msg_to_encrypt.end(), calculated_hmac.value().begin(),
                        calculated_hmac.value().end());

  // Write the padding with the modified PKCS7.
  // We use AES, so the block size is 16, we pad to this value.
  constexpr size_t aes_block_size = 16;

  // We compute the next alignment size. If the buffer is already
  // aligned, the aligned size will be the same as the size. This
  // is incorrect, because it could be ambiguous whether there is
  // a padding or not.
  const size_t size = msg_to_encrypt.size();
  size_t aligned = (size + (aes_block_size - 1)) & ~(aes_block_size - 1);

  // When the buffer was already aligned, we simply pad it with
  // an extra complete block.
  if (size == aligned)
    aligned = size + aes_block_size;

  assert(size < aligned);
  assert((aligned - size) <= aes_block_size);

  // PKCS7 padding value should be the number of bytes padded, but
  // portal use a custom one similar, but the padded value is the
  // number of bytes - 1.
  const auto pad_val = static_cast<uint8_t>(aligned - size - 1);

  for (uint8_t i = 0; i < (pad_val + 1); ++i)
    msg_to_encrypt.push_back(pad_val);

  std::vector<std::uint8_t> encrypted_msg(msg_to_encrypt.size());
  if (mbedtls_aes_crypt_cbc(&context.cipher_enc, MBEDTLS_AES_ENCRYPT,
                            msg_to_encrypt.size(), iv_enc_opt.value().data(),
                            msg_to_encrypt.data(), encrypted_msg.data())) {
    spdlog::error("Failed to encrypt message.");
    return std::nullopt;
  }

  common::be64_enc(context.next_write_id.data(),
                   common::be64_dec(context.next_write_id.data()) + 1);

  return encrypted_msg;
}

} // namespace utopia::portal::client_connection
