#pragma once

#include "utopia/portal_server/client_connection/client_connection.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_change_cipher_spec_packet.hpp"
#include "utopia/portal_server/client_connection/tls/events/tls_events.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

#include <random>

namespace utopia::portal::client_connection {

inline const auto send_tls_change_cipher_spec =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       ClientConnection &client_connection, TlsContext &context) {
      spdlog::debug("Sending TLS Change Cipher Spec.");
    };

} // namespace utopia::portal::client_connection
