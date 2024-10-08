#pragma once

#include "utopia/portal_server/client_connection/events/portal_client_connection_event.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_server_hello_packet.hpp"
#include "utopia/portal_server/client_connection/portal_client_connection.hpp"
#include "utopia/portal_server/client_connection/tls/events/tls_events.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

#include <random>

namespace utopia::portal::client_connection {

inline const auto send_tls_server_hello =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<PortalClientConnectionEvent> *event_queue,
       PortalClientConnection &client_connection, TlsContext &context) {
      // Send packet using default values
      TlsServerHelloPacket tls_server_hello_packet;

      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> dis(0, 255);
      std::generate(tls_server_hello_packet.random.begin(),
                    tls_server_hello_packet.random.end(),
                    [&]() { return dis(gen); });

      if (!client_connection.send(tls_server_hello_packet.serialize())) {
        spdlog::error("Failed to send STS Connect Reply packet.");
        event_queue->enqueue(
            PortalClientConnectionEvent{TlsEvents::UnableToSendPacket{}});
        return;
      }

      const auto data = tls_server_hello_packet.serialize();
      std::vector<std::uint8_t> data_vec(data.begin() + 5, data.end());
      mbedtls_sha256_update_ret(&context.checksum, data_vec.data(),
                                data_vec.size());

      context.server_random = tls_server_hello_packet.random;

      spdlog::debug("Sent STS Connect Reply packet.");
      event_queue->enqueue(
          PortalClientConnectionEvent{TlsEvents::SentServerHelloReply{}});
      spdlog::debug("Sending TLS Server Hello.");
    };

} // namespace utopia::portal::client_connection
