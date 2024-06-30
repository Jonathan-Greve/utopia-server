#pragma once

#include "utopia/auth_server/client_connection/events/auth_client_connection_events.hpp"
#include "utopia/common/network/packets/generated/auth_client_packets.hpp"

#include <variant>

namespace utopia::auth::client_connection {

using AuthClientConnectionEvent =
    std::variant<AuthClientConnectionEvents::UnableToSendPacket,
                 AuthClientConnectionEvents::SentSessionInfo,
                 AuthClientConnectionEvents::SentErrorMessage>;

using AuthClientPacket = std::variant<
    common::AuthClientHeartbeat, common::AuthClientComputerUserInfo,
    common::AuthClientGameInfo, common::AuthClientPacket003,
    common::AuthClientPacket004, common::AuthClientPacket005,
    common::AuthClientPacket006, common::AuthClientPacket007,
    common::AuthClientPacket008, common::AuthClientPacket009,
    common::AuthClientChangePlayCharacter, common::AuthClientPacket011,
    common::AuthClientPacket012, common::AuthClientPacket013,
    common::AuthClientSetPlayerStatus, common::AuthClientHardwareInfo,
    common::AuthClientPacket016, common::AuthClientPacket017,
    common::AuthClientPacket018, common::AuthClientPacket019,
    common::AuthClientPacket020, common::AuthClientPacket021,
    common::AuthClientPacket022, common::AuthClientPacket023,
    common::AuthClientPacket024, common::AuthClientPacket025,
    common::AuthClientPacket026, common::AuthClientPacket027,
    common::AuthClientPacket028, common::AuthClientPacket029,
    common::AuthClientPacket030, common::AuthClientPacket031,
    common::AuthClientPacket032, common::AuthClientPacket033,
    common::AuthClientPacket034, common::AuthClientPacket035,
    common::AuthClientPacket036, common::AuthClientPacket037,
    common::AuthClientPacket038, common::AuthClientPacket039,
    common::AuthClientPacket040, common::AuthClientRequestInstance,
    common::AuthClientPacket042, common::AuthClientPacket043,
    common::AuthClientPacket044, common::AuthClientPacket045,
    common::AuthClientPacket046, common::AuthClientPacket047,
    common::AuthClientPacket048, common::AuthClientPacket049,
    common::AuthClientPacket050, common::AuthClientPacket051,
    common::AuthClientPacket052, common::AuthClientAskServerResponse,
    common::AuthClientPacket054, common::AuthClientPacket055,
    common::AuthClientPortalAccountLogin>;

} // namespace utopia::auth::client_connection
