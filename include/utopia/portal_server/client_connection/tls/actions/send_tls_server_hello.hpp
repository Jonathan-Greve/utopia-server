#pragma once

#include "utopia/portal_server/client_connection/client_connection.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/tls/events/tls_events.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto send_tls_server_hello =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       ClientConnection &client_connection, TlsContext &context) {
      //   StsConnectReplyPacket sts_connect_reply_packet;
      //   sts_connect_reply_packet.protocol_version_major = 1;
      //   sts_connect_reply_packet.protocol_version_minor = 0;
      //   sts_connect_reply_packet.conn_type = 400;
      //   sts_connect_reply_packet.sequence_number = context.sequence_number;
      //   sts_connect_reply_packet.xml_content_server = 1001;
      //   sts_connect_reply_packet.xml_content_module = 2;
      //   sts_connect_reply_packet.xml_content_line = 1146;

      //   if (!client_connection.send(sts_connect_reply_packet.serialize())) {
      //     spdlog::error("Failed to send STS Connect Reply packet.");
      //     event_queue->enqueue(ClientConnectionEvent{
      //         ClientConnectionEvents::UnableToSendPacket{}});
      //     return;
      //   }

      //   spdlog::debug("Sent STS Connect Reply packet.");
      //   event_queue->enqueue(ClientConnectionEvent{
      //       ClientConnectionEvents::SentConnectReplyPacket{}});
      spdlog::debug("Sending TLS Server Hello.");
    };

} // namespace utopia::portal::client_connection
