#pragma once

#include "utopia/common/network/diffie_hellman_key.hpp"
#include "utopia/common/sml/logging/state_transition_log_entry.hpp"

#include <boost/circular_buffer.hpp>

#include <cstdint>

namespace utopia::auth::app {

struct AuthAppContext {
  std::uint32_t port = 0;
  std::uint32_t game_version = 0;
  const common::DiffieHellmanKey &diffie_hellman_key;
  const std::array<std::uint8_t, 64> private_key;

  boost::circular_buffer<common::StateTransitionLogEntry> state_log{100};
};

} // namespace utopia::auth::app
