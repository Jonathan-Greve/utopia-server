#pragma once

#include "utopia/common/sml/logging/state_transition_log_entry.hpp"
#include "utopia/portal_server/client_connection/tls/server_key.hpp"

#include <boost/circular_buffer.hpp>
#include <mbedtls/aes.h>
#include <mbedtls/md.h>
#include <mbedtls/sha256.h>

#include <array>
#include <cstdint>

namespace utopia::portal::client_connection {

struct TlsContext {
  TlsContext() {
    mbedtls_sha256_init(&checksum);
    mbedtls_sha256_starts(&checksum, 0);

    mbedtls_ctr_drbg_context prng;
    mbedtls_ctr_drbg_init(&prng);

    mbedtls_entropy_context entropy;
    mbedtls_entropy_init(&entropy);

    if (mbedtls_ctr_drbg_seed(&prng, mbedtls_entropy_func, &entropy, nullptr,
                              0)) {
      spdlog::error("Failed to seed PRNG");
      return;
    }

    if (mbedtls_ctr_drbg_random(&prng, iv_enc.data(), iv_enc.size())) {
      spdlog::error("Failed to generate IV");
      return;
    }
  }

  boost::circular_buffer<common::StateTransitionLogEntry> state_log{100};

  mbedtls_sha256_context checksum;

  std::array<std::uint8_t, 32> server_random{};
  ServerKey server_key{};

  std::array<std::uint8_t, 32> client_random{};
  std::array<std::uint8_t, 128> client_public{};
  std::array<std::uint8_t, 128> premaster_secret{};
  std::vector<std::uint8_t> master_secret{};

  std::array<std::uint8_t, 8> next_read_id{};
  std::array<std::uint8_t, 8> next_write_id{};
  std::array<std::uint8_t, 16> iv_enc{};
  mbedtls_aes_context cipher_enc{};
  mbedtls_aes_context cipher_dec{};
  mbedtls_md_context_t mac_enc{};
  mbedtls_md_context_t mac_dec{};

  std::array<std::uint8_t, 12> client_finished{};
};

} // namespace utopia::portal::client_connection
