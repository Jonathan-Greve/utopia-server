#pragma once

#include "utopia/auth_server/client_connection/auth_client_connection.hpp"
#include "utopia/auth_server/client_connection/auth_client_connection_context.hpp"
#include "utopia/auth_server/client_connection/events/auth_client_connection_event.hpp"
#include "utopia/common/network/packets/generated/auth_client_packets.hpp"
#include "utopia/common/network/packets/generated/auth_server_packets.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace client_connection = utopia::auth::client_connection;

namespace utopia::auth::client_connection {

inline const auto send_heartbeat_reply =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<AuthClientConnectionEvent> *event_queue,
       AuthClientConnectionContext &client_conn_context,
       AuthClientConnection &client_connection,
       common::AuthClientHeartbeat event) {
      common::AuthServerHeartbeat heartbeat;

      if (!client_connection.encrypt_and_send(heartbeat.get_packed_data())) {
        spdlog::error("Failed to send heartbeat reply to client");
      }

      spdlog::trace("Sent heartbeat reply to client");
    };

} // namespace utopia::auth::client_connection
