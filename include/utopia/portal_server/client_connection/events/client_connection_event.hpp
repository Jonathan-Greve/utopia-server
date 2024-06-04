#pragma once

#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/sts_connect_packet.hpp"

#include <variant>

namespace utopia::portal::client_connection {

using ClientConnectionEvent =
    std::variant<ClientConnectionEvents::ClientDataReceived,
                 ClientConnectionEvents::UnableToParseMessage,

                 StsConnectPacket>;
} // namespace utopia::portal::client_connection
