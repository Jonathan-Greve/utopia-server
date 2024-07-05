#pragma once

#include "utopia/common/network/packets/generated/auth_client_packets.hpp"

#include <spdlog/spdlog.h>

namespace utopia::auth::client_connection {

inline const auto handle_game_info = [](common::AuthClientGameInfo event) {
  spdlog::trace("Received game info from client with version: {}",
                event.game_version);
};

} // namespace utopia::auth::client_connection
