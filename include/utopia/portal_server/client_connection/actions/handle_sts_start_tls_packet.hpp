#pragma once

#include "utopia/portal_server/client_connection/events/portal_client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/portal_client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_start_tls_packet.hpp"
#include "utopia/portal_server/client_connection/portal_client_connection_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto handle_sts_start_tls_packet =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<PortalClientConnectionEvent> *event_queue,
       StsStartTlsPacket event, PortalClientConnectionContext &context) {
      spdlog::debug("Received STS StartTls packet.");
      context.sequence_number = event.sequence_number;
      event_queue->enqueue(PortalClientConnectionEvent{
          PortalClientConnectionEvents::ReceivedValidStartTlsPacket{}});
    };

} // namespace utopia::portal::client_connection
