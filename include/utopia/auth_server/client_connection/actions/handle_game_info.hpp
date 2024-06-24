#pragma once

#include "utopia/auth_server/client_connection/auth_client_connection.hpp"
#include "utopia/auth_server/client_connection/auth_client_connection_context.hpp"
#include "utopia/auth_server/client_connection/events/auth_client_connection_event.hpp"
#include "utopia/common/network/packets/generated/auth_client_packets.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace client_connection = utopia::auth::client_connection;

namespace utopia::auth::client_connection {

inline const auto handle_game_info =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<AuthClientConnectionEvent> *event_queue,
       AuthClientConnectionContext &client_conn_context,
       AuthClientConnection &client_connection,
       common::AuthClientGameInfo event) {
      spdlog::trace("Received game info from client with version: {}",
                    event.game_version);
    };

} // namespace utopia::auth::client_connection
