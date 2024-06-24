#pragma once

#include "utopia/common/network/endian/endian.hpp"
#include "utopia/portal_server/client_connection/events/portal_client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/portal_client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/sts/sts_login_finish_reply_packet.hpp"
#include "utopia/portal_server/client_connection/portal_client_connection.hpp"
#include "utopia/portal_server/client_connection/portal_client_connection_context.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/tls_encode_with_hmac_and_padding.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto send_login_finish_reply_packet =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<PortalClientConnectionEvent> *event_queue,
       PortalClientConnection &client_connection,
       PortalClientConnectionContext &context, TlsContext &tls_context) {
      StsLoginFinishReplyPacket sts_login_finish_reply_packet;
      sts_login_finish_reply_packet.protocol_version_major = 1;
      sts_login_finish_reply_packet.protocol_version_minor = 0;
      sts_login_finish_reply_packet.conn_type = 200;
      sts_login_finish_reply_packet.sequence_number = context.sequence_number++;
      sts_login_finish_reply_packet.xml_content_user_id =
          common::GWUUID::from_string("D8024183-DB2B-ED11-81BB-02DE0BB68F60")
              .value();
      sts_login_finish_reply_packet.xml_content_user_center = 4;
      sts_login_finish_reply_packet.xml_content_user_name =
          ":046B93D4-EFF7-C3EE-5FFB-69FA47D48DD9.4106";
      sts_login_finish_reply_packet.xml_content_resume_token =
          common::GWUUID::from_string("34FF9D30-0482-4060-A150-58075C706DF7")
              .value();

      std::vector<std::uint8_t> tls_packet = {0x17, 0x03, 0x03, 0x00, 0x00};
      common::be16_enc(tls_packet.data() + 3,
                       sts_login_finish_reply_packet.get_packet_size());

      auto sts_packet_data = sts_login_finish_reply_packet.serialize();
      auto encrypted_msg = tls_encode_with_hmac_and_padding(
          sts_packet_data, tls_packet, tls_context);

      if (!encrypted_msg) {
        spdlog::error("Failed to encrypt message.");
        event_queue->enqueue(PortalClientConnectionEvent{
            PortalClientConnectionEvents::UnableToSendPacket{}});
        return;
      }

      tls_packet.insert(tls_packet.end(), tls_context.iv_enc.begin(),
                        tls_context.iv_enc.end());
      tls_packet.insert(tls_packet.end(), encrypted_msg.value().begin(),
                        encrypted_msg.value().end());
      common::be16_enc(tls_packet.data() + 3,
                       static_cast<std::uint32_t>(tls_packet.size()) - 5);

      if (!client_connection.send(tls_packet)) {
        spdlog::error("Failed to send STS LoginFinish Reply packet.");
        event_queue->enqueue(PortalClientConnectionEvent{
            PortalClientConnectionEvents::UnableToSendPacket{}});
        return;
      }

      spdlog::debug("Sent STS LoginFinish Reply packet.");
      event_queue->enqueue(PortalClientConnectionEvent{
          PortalClientConnectionEvents::SentLoginFinishReplyPacket{}});
    };

} // namespace utopia::portal::client_connection
