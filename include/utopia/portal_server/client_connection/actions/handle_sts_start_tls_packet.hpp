#pragma once

#include "utopia/portal_server/client_connection/client_connection.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/sts_start_tls_packet.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto handle_sts_start_tls_packet =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       ClientConnectionEvents::ClientDataReceived event) {
      if (event.data.empty()) {
        spdlog::error("Received empty data.");
        return;
      }

      StsStartTlsPacket sts_start_tls_packet(event.data);
      if (!sts_start_tls_packet.is_valid()) {
        spdlog::error("STS Connect packet is invalid.");
        spdlog::debug("STS Connect packet recv {} bytes.", event.data.size());

        std::string recv_data(event.data.begin(),
                              event.data.begin() + event.data.size());
        spdlog::debug("STS Connect packet data (ASCII): {}", recv_data);

        event_queue->enqueue(ClientConnectionEvent{
            ClientConnectionEvents::UnableToParsePacket{}});
      }

      spdlog::debug("STS Connect packet is valid.");
      event_queue->enqueue(ClientConnectionEvent{
          ClientConnectionEvents::ReceivedValidConnectPacket{}});
    };

} // namespace utopia::portal::client_connection
