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
      // Send packet using default values
      TlsChangeCipherSpecPacket tls_change_cipher_spec_packet;

      if (!client_connection.send(tls_change_cipher_spec_packet.serialize())) {
        spdlog::error("Failed to TLS change cipher packet.");
        event_queue->enqueue(
            ClientConnectionEvent{TlsEvents::UnableToSendPacket{}});
        return;
      }

      const auto data = tls_change_cipher_spec_packet.serialize();
      mbedtls_sha256_update_ret(&context.checksum, &data.at(5),
                                tls_change_cipher_spec_packet.size);

      event_queue->enqueue(
          ClientConnectionEvent{TlsEvents::SentCipherChangeSpecPacket{}});

      spdlog::debug("Sent TLS Change Cipher Spec Packet.");
    };

} // namespace utopia::portal::client_connection
