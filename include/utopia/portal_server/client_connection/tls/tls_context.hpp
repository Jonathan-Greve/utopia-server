#pragma once

#include "utopia/common/sml/logging/state_transition_log_entry.hpp"

#include <boost/circular_buffer.hpp>
#include <mbedtls/sha256.h>

#include <cstdint>

namespace utopia::portal::client_connection {

struct TlsContext {
  TlsContext() {
    mbedtls_sha256_init(&checksum);
    mbedtls_sha256_starts(&checksum, 0);
  }

  boost::circular_buffer<common::StateTransitionLogEntry> state_log{100};

  mbedtls_sha256_context checksum;
};

} // namespace utopia::portal::client_connection
