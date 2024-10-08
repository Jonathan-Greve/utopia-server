#pragma once

#include "utopia/auth_server/client_connection/auth_client_connection.hpp"
#include "utopia/auth_server/client_connection/auth_client_connection_context.hpp"
#include "utopia/auth_server/client_connection/events/auth_client_connection_event.hpp"
#include "utopia/common/network/packets/generated/auth_client_packets.hpp"
#include "utopia/common/network/packets/generated/auth_server_packets.hpp"

#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace client_connection = utopia::auth::client_connection;

namespace utopia::auth::client_connection {

inline auto send_session_info =
    [](AuthClientConnection &client_connection,
       common::AuthClientHeartbeat event,
       moodycamel::ConcurrentQueue<AuthClientConnectionEvent> &event_queue) {
      common::AuthServerSessionInfo session_info;
      session_info.salt = 0x164d9765;
      session_info.field_1 = 0xffffffff;
      session_info.field_2 = 0x00000000;

      if (!client_connection.encrypt_and_send(session_info.get_packed_data())) {
        spdlog::error("Failed to send session info to the client");
        event_queue.enqueue(AuthClientConnectionEvent{
            AuthClientConnectionEvents::UnableToSendPacket{}});
      }

      if (!event_queue.enqueue(AuthClientConnectionEvent{
              AuthClientConnectionEvents::SentSessionInfo{}})) {
        spdlog::error("Failed to queue SentSessionInfo event");
      }

      spdlog::trace("Sent session info to the client");
    };

} // namespace utopia::auth::client_connection
