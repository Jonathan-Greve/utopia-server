#pragma once

#include "utopia/portal_server/client_connection/events/portal_client_connection_event.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_ping_packet.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto handle_sts_ping_packet =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<PortalClientConnectionEvent> *event_queue,
       StsPingPacket event) { spdlog::debug("Received STS Ping packet."); };

} // namespace utopia::portal::client_connection
