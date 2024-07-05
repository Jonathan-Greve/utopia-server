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

inline const auto handle_portal_account_login =
    [](moodycamel::ConcurrentQueue<AuthClientConnectionEvent> &event_queue,
       AuthClientConnectionContext &client_conn_context,
       AuthClientConnection &client_connection,
       common::AuthClientPortalAccountLogin event) {
      client_conn_context.next_transaction_id = event.transaction_id;

      common::AuthServerErrorMessage error_message;
      error_message.error_code = 0;
      error_message.transaction_id = client_conn_context.next_transaction_id++;

      if (!client_connection.encrypt_and_send(
              error_message.get_packed_data())) {
        spdlog::error("Failed to send error message to the client");
        event_queue.enqueue(AuthClientConnectionEvent{
            AuthClientConnectionEvents::UnableToSendPacket{}});
      }

      event_queue.enqueue(AuthClientConnectionEvent{
          AuthClientConnectionEvents::SentErrorMessage{}});
      spdlog::trace("Sent error message to the client");
    };

} // namespace utopia::auth::client_connection
