#pragma once

#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_key_exchange_packet.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto handle_tls_client_key_exchange =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       TlsClientKeyExchangePacket event, TlsContext &context) {
      const auto data = event.serialize();
      mbedtls_sha256_update_ret(&context.checksum, &data.at(5), event.size);

      context.client_public = event.public_key;

      spdlog::trace("Handling Tls Client Key Exchange packet.");
    };

} // namespace utopia::portal::client_connection
