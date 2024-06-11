#pragma once

#include "utopia/common/sml/logging/state_transition_log_entry.hpp"
#include "utopia/portal_server/client_connection/tls/server_key.hpp"

#include <boost/circular_buffer.hpp>
#include <mbedtls/sha256.h>

#include <array>
#include <cstdint>

namespace utopia::portal::client_connection {

struct TlsContext {
  TlsContext() {
    mbedtls_sha256_init(&checksum);
    mbedtls_sha256_starts(&checksum, 0);
  }

  boost::circular_buffer<common::StateTransitionLogEntry> state_log{100};

  mbedtls_sha256_context checksum;

  std::array<std::uint8_t, 32> server_random;
  ServerKey server_key;

  std::array<std::uint8_t, 32> client_random;
  std::array<std::uint8_t, 128> client_public;
};

} // namespace utopia::portal::client_connection
