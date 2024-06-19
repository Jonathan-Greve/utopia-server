#pragma once

#include "utopia/portal_server/client_connection/client_connection.hpp"
#include "utopia/portal_server/client_connection/client_connection_context.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_start_tls_reply_packet.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto send_sts_start_tls_reply_packet =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       ClientConnection &client_connection, ClientConnectionContext &context) {
      StsStartTlsReplyPacket sts_start_tls_reply_packet;
      sts_start_tls_reply_packet.protocol_version_major = 1;
      sts_start_tls_reply_packet.protocol_version_minor = 0;
      sts_start_tls_reply_packet.conn_type = 400;
      sts_start_tls_reply_packet.sequence_number = context.sequence_number++;
      sts_start_tls_reply_packet.xml_content_server = 1001;
      sts_start_tls_reply_packet.xml_content_module = 2;
      sts_start_tls_reply_packet.xml_content_line = 1146;

      if (!client_connection.send(sts_start_tls_reply_packet.serialize())) {
        spdlog::error("Failed to send STS StartTls Reply packet.");
        event_queue->enqueue(ClientConnectionEvent{
            ClientConnectionEvents::UnableToSendPacket{}});
        return;
      }

      spdlog::debug("Sent STS StartTls Reply packet.");
      event_queue->enqueue(ClientConnectionEvent{
          ClientConnectionEvents::SentStartTlsReplyPacket{}});
    };

} // namespace utopia::portal::client_connection
