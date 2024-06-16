#pragma once

#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/tls/events/tls_events.hpp"

#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto enqueue_handshake_complete_event =
    [](moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue) {
      event_queue->enqueue(
          ClientConnectionEvent{TlsEvents::HandshakeComplete{}});
      spdlog::debug("TLS handshake complete");
    };

} // namespace utopia::portal::client_connection
