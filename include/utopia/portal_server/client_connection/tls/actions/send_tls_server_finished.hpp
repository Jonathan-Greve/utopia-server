#pragma once

#include "utopia/common/network/endian/endian.hpp"
#include "utopia/portal_server/client_connection/events/portal_client_connection_event.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_server_finished_packet.hpp"
#include "utopia/portal_server/client_connection/portal_client_connection.hpp"
#include "utopia/portal_server/client_connection/tls/events/tls_events.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/tls_encode_with_hmac_and_padding.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <mbedtls/aes.h>
#include <mbedtls/md.h>
#include <mbedtls/sha256.h>
#include <spdlog/spdlog.h>

#include <string_view>

namespace utopia::portal::client_connection {

inline const auto send_tls_server_finished =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<PortalClientConnectionEvent> *event_queue,
       PortalClientConnection &client_connection, TlsContext &context) {
      // Send packet using default values
      TlsServerFinishedPacket tls_server_finished_packet;

      // Build the server_finished data from the checksum
      constexpr std::string_view server_finished_label = "server finished";
      const std::vector<std::uint8_t> server_finished_label_vec(
          server_finished_label.begin(), server_finished_label.end());

      mbedtls_sha256_context checksum_ctx;
      mbedtls_sha256_init(&checksum_ctx);
      mbedtls_sha256_clone(&checksum_ctx, &context.checksum);

      std::vector<std::uint8_t> checksum(32);
      int ret = mbedtls_sha256_finish_ret(&checksum_ctx, checksum.data());
      mbedtls_sha256_free(&checksum_ctx);

      if (ret) {
        spdlog::error("Failed to finish checksum");
        event_queue->enqueue(
            PortalClientConnectionEvent{TlsEvents::UnableToSendPacket{}});
        return;
      }

      auto server_finished_opt =
          tls_prf_sha256(context.master_secret, server_finished_label_vec,
                         checksum, context.server_finished.size());

      if (!server_finished_opt) {
        spdlog::error("Failed to compute server finished data");
        event_queue->enqueue(
            PortalClientConnectionEvent{TlsEvents::UnableToSendPacket{}});
        return;
      }

      assert(server_finished_opt.value().size() ==
             context.server_finished.size());

      auto &server_finished_data = server_finished_opt.value();

      std::move(server_finished_data.begin(), server_finished_data.end(),
                context.server_finished.begin());

      // Write the part of the msg to be encrypted (bytes 0 to 15. First 16
      // bytes). Header + verify data
      std::vector<std::uint8_t> msg_to_encrypt(16);
      msg_to_encrypt[0] = 0x14;
      msg_to_encrypt[1] = 0x00;
      msg_to_encrypt[2] = 0x00;
      msg_to_encrypt[3] = 0x0c;
      std::copy(context.server_finished.begin(), context.server_finished.end(),
                msg_to_encrypt.begin() + 4);

      auto encrypted_msg = tls_encode_with_hmac_and_padding(
          msg_to_encrypt, tls_server_finished_packet.serialize(), context);

      if (!encrypted_msg) {
        spdlog::error("Failed to encrypt message.");
        event_queue->enqueue(
            PortalClientConnectionEvent{TlsEvents::UnableToSendPacket{}});
        return;
      }

      assert(encrypted_msg.value().size() == 48);
      std::copy(encrypted_msg.value().begin(), encrypted_msg.value().end(),
                tls_server_finished_packet.encrypted_msg.begin());
      tls_server_finished_packet.iv_enc = context.iv_enc;

      // Send the packet
      if (!client_connection.send(tls_server_finished_packet.serialize())) {
        spdlog::error("Failed to send STS Connect Reply packet.");
        event_queue->enqueue(
            PortalClientConnectionEvent{TlsEvents::UnableToSendPacket{}});
        return;
      }

      event_queue->enqueue(
          PortalClientConnectionEvent{TlsEvents::SentServerFinishedPacket{}});

      spdlog::debug("Sent TLS Server Finished.");
    };

} // namespace utopia::portal::client_connection
