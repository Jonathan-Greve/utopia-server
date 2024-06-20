#pragma once

#include "utopia/portal_server/client_connection/events/portal_client_connection_event.hpp"
#include "utopia/portal_server/client_connection/tls/events/tls_events.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto enqueue_handshake_complete_event =
    [](moodycamel::ConcurrentQueue<PortalClientConnectionEvent> *event_queue,
       TlsContext &context) {
      context.handshake_complete = true;
      event_queue->enqueue(
          PortalClientConnectionEvent{TlsEvents::HandshakeComplete{}});
      spdlog::debug("TLS handshake complete");
    };

} // namespace utopia::portal::client_connection
