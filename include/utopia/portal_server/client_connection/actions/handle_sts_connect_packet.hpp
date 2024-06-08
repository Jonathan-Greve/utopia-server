#pragma once

#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_connect_packet.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto handle_sts_connect_packet =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       StsConnectPacket event) {
      spdlog::trace("Handling STS Connect packet.");
      event_queue->enqueue(ClientConnectionEvent{
          ClientConnectionEvents::ReceivedValidConnectPacket{}});
    };

} // namespace utopia::portal::client_connection
