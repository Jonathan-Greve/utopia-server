#pragma once

#include "utopia/portal_server/client_connection/events/portal_client_connection_event.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_server_hello_done_packet.hpp"
#include "utopia/portal_server/client_connection/portal_client_connection.hpp"
#include "utopia/portal_server/client_connection/tls/events/tls_events.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto send_tls_server_hello_done =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<PortalClientConnectionEvent> *event_queue,
       PortalClientConnection &client_connection, TlsContext &context) {
      // Send packet using default values
      TlsServerHelloDonePacket tls_server_hello_packet;

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

      spdlog::debug("Sent STS Connect Reply packet.");
      event_queue->enqueue(
          PortalClientConnectionEvent{TlsEvents::SentServerHelloDonePacket{}});
      spdlog::debug("Sending TLS Server HelloDone packet.");
    };

} // namespace utopia::portal::client_connection
