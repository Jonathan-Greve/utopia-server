#pragma once

#include <chrono>
#include <string>

namespace utopia::common {

struct StateTransitionLogEntry {
  std::string src_state;
  std::string dst_state;

  std::chrono::time_point<std::chrono::system_clock> timestamp;
};

} // namespace utopia::common

