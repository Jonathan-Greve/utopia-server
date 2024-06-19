#pragma once

#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_connect_packet.hpp"
#include "utopia/portal_server/client_connection/tls/events/tls_events.hpp"

#include <variant>

namespace utopia::portal::client_connection {

using ClientConnectionEvent = std::variant<
    ClientConnectionEvents::UnableToSendPacket,
    ClientConnectionEvents::ReceivedValidConnectPacket,
    ClientConnectionEvents::ReceivedValidStartTlsPacket,
    ClientConnectionEvents::SentStartTlsReplyPacket,
    ClientConnectionEvents::SentLoginFinishReplyPacket,
    ClientConnectionEvents::SentListMyGameAccountsReplyPacket,

    TlsEvents::UnableToSendPacket, TlsEvents::SentServerHelloReply,
    TlsEvents::SentServerKeyExchangePacket,
    TlsEvents::SentServerHelloDonePacket, TlsEvents::FailedToDecryptMessage,
    TlsEvents::ClientFinishedVerifyDataMismatch,
    TlsEvents::ClientFinishedPacketHandled,
    TlsEvents::SentCipherChangeSpecPacket, TlsEvents::SentServerFinishedPacket,
    TlsEvents::HmacValidationFailed, TlsEvents::FailedToIssueNextIV,
    TlsEvents::HmacComputationFailed, TlsEvents::HandshakeComplete>;
} // namespace utopia::portal::client_connection
