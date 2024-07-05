#pragma once

#include "utopia/auth_server/client_connection/auth_client_connection.hpp"
#include "utopia/common/network/packets/generated/auth_client_packets.hpp"
#include "utopia/common/network/packets/generated/auth_server_packets.hpp"

#include <spdlog/spdlog.h>

#include <chrono>
#include <cstdint>

namespace client_connection = utopia::auth::client_connection;

namespace utopia::auth::client_connection {

inline const auto send_heartbeat_reply =
    [](AuthClientConnection &client_connection,
       common::AuthClientHeartbeat event) {
      common::AuthServerHeartbeat heartbeat;
      heartbeat.unknown = 301274;

      if (!client_connection.encrypt_and_send(heartbeat.get_packed_data())) {
        spdlog::error("Failed to send heartbeat reply to client");
      }

      spdlog::trace("Sent heartbeat reply to client");
    };

} // namespace utopia::auth::client_connection
