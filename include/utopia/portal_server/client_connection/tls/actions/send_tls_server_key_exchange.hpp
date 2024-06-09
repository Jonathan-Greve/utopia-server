#pragma once

#include "utopia/portal_server/client_connection/client_connection.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_server_key_exchange_packet.hpp"
#include "utopia/portal_server/client_connection/tls/events/tls_events.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto send_tls_server_key_exchange =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       ClientConnection &client_connection, TlsContext &context) {
      // Send packet using default values
      TlsServerKeyExchangePacket tls_server_hello_packet;
      tls_server_hello_packet.prime = context.server_key.prime;
      tls_server_hello_packet.generator = context.server_key.generator;
      tls_server_hello_packet.salt = context.server_key.salt;
      tls_server_hello_packet.server_public = context.server_key.public_key;

      if (!client_connection.send(tls_server_hello_packet.serialize())) {
        spdlog::error("Failed to send STS Connect Reply packet.");
        event_queue->enqueue(
            ClientConnectionEvent{TlsEvents::UnableToSendPacket{}});
        return;
      }

      const auto data = tls_server_hello_packet.serialize();
      mbedtls_sha256_update_ret(&context.checksum, &data.at(5),
                                tls_server_hello_packet.size);

      spdlog::debug("Sent STS Connect Reply packet.");
      event_queue->enqueue(
          ClientConnectionEvent{TlsEvents::SentServerKeyExchangePacket{}});
      spdlog::debug("Sending TLS Server KeyExchange.");
    };

} // namespace utopia::portal::client_connection
