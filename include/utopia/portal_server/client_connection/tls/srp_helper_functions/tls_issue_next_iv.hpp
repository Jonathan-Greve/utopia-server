#pragma once

#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <mbedtls/aes.h>

#include <array>
#include <cassert>
#include <cstdint>
#include <optional>

namespace utopia::portal::client_connection {

inline std::optional<std::array<std::uint8_t, 16>>
tls_issue_next_iv(TlsContext &tls_context) {
  assert(tls_context.iv_enc.size() == 16);

  std::array<std::uint8_t, 16> iv;
  std::copy(tls_context.iv_enc.begin(), tls_context.iv_enc.end(), iv.begin());

  // We increment the `uint128_t` by 1.
  for (size_t i = 0; i < tls_context.iv_enc.size(); ++i) {
    if (++iv[i] != 0)
      break;
  }

  if (mbedtls_internal_aes_encrypt(&tls_context.cipher_enc,
                                   tls_context.iv_enc.data(), iv.data())) {
    return std::nullopt;
  }

  tls_context.iv_enc = iv;

  return iv;
}
} // namespace utopia::portal::client_connection
