#pragma once

#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_hello_packet.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto handle_tls_client_hello_packet =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       TlsClientHelloPacket event, TlsContext &context) {
      const auto data = event.serialize();
      mbedtls_sha256_update_ret(&context.checksum, &data.at(5), event.size);

      context.client_random = event.random;

      spdlog::trace("Handling Tls Client Hello packet.");
    };

} // namespace utopia::portal::client_connection
