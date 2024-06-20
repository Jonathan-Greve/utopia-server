#pragma once

#include "utopia/common/sml/logging/state_transition_log_entry.hpp"

#include <boost/circular_buffer.hpp>

#include <cstdint>

namespace utopia::portal::app {

struct PortalAppContext {
  std::uint32_t port = 0;

  boost::circular_buffer<common::StateTransitionLogEntry> state_log{100};
};

} // namespace utopia::portal::app
