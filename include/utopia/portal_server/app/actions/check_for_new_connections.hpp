#pragma once

#include "utopia/common/network/connection_manager.hpp"
#include "utopia/portal_server/app/events/portal_app_event.hpp"
#include "utopia/portal_server/app/events/portal_app_events.hpp"
#include "utopia/portal_server/app/portal_app_context.hpp"
#include "utopia/portal_server/client_connection/portal_client_connection.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace client_connection = utopia::portal::client_connection;

namespace utopia::portal::app {
inline const auto check_for_new_connections =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<PortalAppEvent> *event_queue,
       PortalAppContext &app_context,
       common::ConnectionManager &connection_manager) {
      auto connection =
          std::make_unique<client_connection::PortalClientConnection>(
              io, app_context.port);

      if (connection->is_connected()) {
        spdlog::info("Accepted a new connection.");
        const auto id =
            connection_manager.add_connection(std::move(connection));

        io.post([&connection_manager, id]() {
          static_cast<client_connection::PortalClientConnection *>(
              connection_manager.get_connection(id))
              ->run();
        });
      }
    };
} // namespace utopia::portal::app
