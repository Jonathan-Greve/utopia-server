#pragma once

#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <mbedtls/md.h>
#include <mbedtls/sha256.h>

#include <array>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

inline std::optional<std::array<std::uint8_t, 20>>
tls_compute_handshake_finished_hmac(
    const std::array<std::uint8_t, 8> &sequence_number,
    const std::vector<std::uint8_t> &header_data,
    const std::vector<std::uint8_t> &decrypted_msg, TlsContext &context,
    mbedtls_md_context_t mac_ctx, std::uint32_t msg_size) {
  mbedtls_md_hmac_reset(&mac_ctx);
  mbedtls_md_hmac_update(&mac_ctx, sequence_number.data(),
                         sequence_number.size());

  // Make sure that the header uses the size of the message without HMAC.
  std::array<std::uint8_t, 5> modified_header;
  std::copy(header_data.begin(), header_data.begin() + 5,
            modified_header.begin());
  modified_header[4] = msg_size;

  if (mbedtls_md_hmac_update(&mac_ctx, modified_header.data(),
                             modified_header.size())) {
    spdlog::error("Failed to update HMAC context with modified header.");
    return std::nullopt;
  }

  if (mbedtls_md_hmac_update(&mac_ctx, decrypted_msg.data(),
                             decrypted_msg.size())) {
    spdlog::error("Failed to update HMAC context with modified header.");
    return std::nullopt;
  }

  std::array<std::uint8_t, 20> calculated_hmac;
  if (mbedtls_md_hmac_finish(&mac_ctx, calculated_hmac.data())) {
    spdlog::error("Failed to finish HMAC calculation.");
    return std::nullopt;
  }

  return calculated_hmac;
}

} // namespace utopia::portal::client_connection
