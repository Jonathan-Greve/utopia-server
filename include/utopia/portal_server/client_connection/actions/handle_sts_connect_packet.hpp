#pragma once

#include "utopia/portal_server/client_connection/client_connection.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/sts_connect_packet.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto handle_sts_connect_packet =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       ClientConnectionEvents::ClientDataReceived event) {
      if (event.data.size() > 0) {
        StsConnectPacket sts_connect_packet(event.data);
        if (sts_connect_packet.is_valid()) {
          spdlog::info("Packet size: {}", sts_connect_packet.get_packet_size());
        }

        spdlog::info("Received {} bytes.", event.data.size());

        std::string recv_data(event.data.begin(),
                              event.data.begin() + event.data.size());
        spdlog::info("Received data (ASCII): {}", recv_data);
      }
    };

} // namespace utopia::portal::client_connection
