#pragma once

#include "utopia/portal_server/client_connection/events/portal_client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/portal_client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_hello_packet.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto handle_tls_client_hello_packet =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<PortalClientConnectionEvent> *event_queue,
       TlsClientHelloPacket event, TlsContext &context) {
      const auto data = event.serialize();

      std::vector<std::uint8_t> data_vec(data.begin() + 5, data.end());
      assert(data_vec.size() == event.size);
      mbedtls_sha256_update_ret(&context.checksum, data_vec.data(),
                                data_vec.size());

      context.client_random = event.random;
      context.server_key.generate(event.extension_srp_data);

      spdlog::trace("Handling Tls Client Hello packet.");
    };

} // namespace utopia::portal::client_connection
