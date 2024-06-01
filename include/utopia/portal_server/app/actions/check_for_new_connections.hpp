#pragma once

#include "utopia/portal_server/app/app_context.hpp"
#include "utopia/portal_server/app/events/app_event.hpp"
#include "utopia/portal_server/app/events/app_events.hpp"

#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::app {
inline const auto check_for_new_connections =
    [](asio::io_context &io, moodycamel::ConcurrentQueue<AppEvent> *event_queue,
       AppContext &ctx) {
      // Define the acceptor and endpoint
      static asio::ip::tcp::acceptor acceptor(
          io, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 6112));

      // Set the acceptor to non-blocking mode
      acceptor.non_blocking(true);

      // Create a socket for the incoming connection
      auto socket = std::make_shared<asio::ip::tcp::socket>(io);

      // Try to accept a new connection
      asio::error_code ec;
      acceptor.accept(*socket, ec);

      // Check if a connection was successfully accepted
      if (!ec) {
        // Successfully accepted a new connection, push an event to the queue
        spdlog::info("Accepted a new connection.");
        // Add any additional context updates or logging here
      } else if (ec != asio::error::would_block) {
        // Handle other errors (would_block is expected if there are no
        // connections) For example, log the error
      }
    };
} // namespace utopia::portal::app
