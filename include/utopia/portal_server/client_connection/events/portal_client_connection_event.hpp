#pragma once

#include "utopia/portal_server/client_connection/events/portal_client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_connect_packet.hpp"
#include "utopia/portal_server/client_connection/tls/events/tls_events.hpp"

#include <variant>

namespace utopia::portal::client_connection {

using PortalClientConnectionEvent = std::variant<
    PortalClientConnectionEvents::UnableToSendPacket,
    PortalClientConnectionEvents::ReceivedValidConnectPacket,
    PortalClientConnectionEvents::ReceivedValidStartTlsPacket,
    PortalClientConnectionEvents::SentStartTlsReplyPacket,
    PortalClientConnectionEvents::SentLoginFinishReplyPacket,
    PortalClientConnectionEvents::SentListMyGameAccountsReplyPacket,
    PortalClientConnectionEvents::SentRequestGameTokenReplyPacket,

    TlsEvents::UnableToSendPacket, TlsEvents::SentServerHelloReply,
    TlsEvents::SentServerKeyExchangePacket,
    TlsEvents::SentServerHelloDonePacket, TlsEvents::FailedToDecryptMessage,
    TlsEvents::ClientFinishedVerifyDataMismatch,
    TlsEvents::ClientFinishedPacketHandled,
    TlsEvents::SentCipherChangeSpecPacket, TlsEvents::SentServerFinishedPacket,
    TlsEvents::HmacValidationFailed, TlsEvents::FailedToIssueNextIV,
    TlsEvents::HmacComputationFailed, TlsEvents::HandshakeComplete>;
} // namespace utopia::portal::client_connection
