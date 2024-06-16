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
    const std::vector<std::uint8_t> &packet_data,
    const std::vector<std::uint8_t> &decrypted_msg, TlsContext &context,
    mbedtls_md_context_t mac_ctx) {
  mbedtls_md_hmac_reset(&mac_ctx);
  mbedtls_md_hmac_update(&mac_ctx, sequence_number.data(),
                         sequence_number.size());

  // The HMAC message was encrypted with the TlsClientFinishedPacket's size
  // set to 0x10. I.e. the size of the packet without the encrypted message.
  // So we set it to 0x10 before computing our HMAC.
  std::array<std::uint8_t, 5> modified_header;
  std::copy(packet_data.begin(), packet_data.begin() + 5,
            modified_header.begin());
  modified_header[4] = 0x10;

  if (mbedtls_md_hmac_update(&mac_ctx, modified_header.data(),
                             modified_header.size())) {
    spdlog::error("Failed to update HMAC context with modified header.");
    return std::nullopt;
  }

  // Decrypted msg header (4bytes) + verify_data (12bytes)
  if (mbedtls_md_hmac_update(&mac_ctx, decrypted_msg.data(), 16)) {
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
