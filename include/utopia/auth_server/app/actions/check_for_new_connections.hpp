#pragma once

#include "utopia/auth_server/app/auth_app_context.hpp"
#include "utopia/auth_server/app/events/auth_app_event.hpp"
#include "utopia/auth_server/app/events/auth_app_events.hpp"
#include "utopia/auth_server/client_connection/auth_client_connection.hpp"
#include "utopia/common/network/connection_manager.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace client_connection = utopia::auth::client_connection;

namespace utopia::auth::app {
inline const auto check_for_new_connections =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<AuthAppEvent> *event_queue,
       AuthAppContext &app_context,
       common::ConnectionManager &connection_manager) {
      auto connection =
          std::make_unique<client_connection::AuthClientConnection>(
              io, app_context.port);

      if (connection->is_connected()) {
        spdlog::info("Accepted a new connection.");
        const auto id =
            connection_manager.add_connection(std::move(connection));

        io.post([&, id]() {
          static_cast<client_connection::AuthClientConnection *>(
              connection_manager.get_connection(id))
              ->run(app_context.game_version, app_context.diffie_hellman_key);
        });
      }
    };
} // namespace utopia::auth::app
