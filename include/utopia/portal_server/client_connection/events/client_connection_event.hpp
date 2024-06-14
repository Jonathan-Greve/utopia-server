#pragma once

#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_connect_packet.hpp"
#include "utopia/portal_server/client_connection/tls/events/tls_events.hpp"

#include <variant>

namespace utopia::portal::client_connection {

using ClientConnectionEvent =
    std::variant<ClientConnectionEvents::UnableToSendPacket,
                 ClientConnectionEvents::ReceivedValidConnectPacket,
                 ClientConnectionEvents::ReceivedValidStartTlsPacket,
                 ClientConnectionEvents::SentStartTlsReplyPacket,

                 TlsEvents::UnableToSendPacket, TlsEvents::SentServerHelloReply,
                 TlsEvents::SentServerKeyExchangePacket,
                 TlsEvents::SentServerHelloDonePacket,
                 TlsEvents::FailedToDecryptMessage,
                 TlsEvents::ClientFinishedVerifyDataMismatch,
                 TlsEvents::ClientFinishedPacketHandled>;
} // namespace utopia::portal::client_connection
