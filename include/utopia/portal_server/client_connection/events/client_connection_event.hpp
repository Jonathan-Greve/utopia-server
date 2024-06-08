#pragma once

#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_connect_packet.hpp"

#include <variant>

namespace utopia::portal::client_connection {

using ClientConnectionEvent =
    std::variant<ClientConnectionEvents::UnableToSendPacket,

                 ClientConnectionEvents::ReceivedValidConnectPacket,
                 ClientConnectionEvents::SentConnectReplyPacket,

                 ClientConnectionEvents::ReceivedValidStartTlsPacket,
                 ClientConnectionEvents::SentStartTlsReplyPacket>;
} // namespace utopia::portal::client_connection
