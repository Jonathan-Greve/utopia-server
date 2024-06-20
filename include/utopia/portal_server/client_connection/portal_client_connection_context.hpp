#pragma once

#include "utopia/common/sml/logging/state_transition_log_entry.hpp"

#include <boost/circular_buffer.hpp>

#include <cstdint>

namespace utopia::portal::client_connection {

struct PortalClientConnectionContext {
  boost::circular_buffer<common::StateTransitionLogEntry> state_log{100};

  std::uint32_t sequence_number = 1;
};

} // namespace utopia::portal::client_connection
