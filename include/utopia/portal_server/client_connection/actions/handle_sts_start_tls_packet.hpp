#pragma once

#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/sts_start_tls_packet.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto handle_sts_start_tls_packet =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       StsConnectPacket event) {
      spdlog::debug("Received STS StartTls packet.");
      event_queue->enqueue(ClientConnectionEvent{
          ClientConnectionEvents::ReceivedValidStartTlsPacket{}});
    };

} // namespace utopia::portal::client_connection
