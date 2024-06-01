#pragma once

#include "utopia/common/sml/logging/state_transition_log_entry.hpp"

#include <boost/circular_buffer.hpp>

namespace utopia::portal::app {

struct AppContext {
  boost::circular_buffer<common::StateTransitionLogEntry> state_log{100};
};

} // namespace utopia::portal::app
