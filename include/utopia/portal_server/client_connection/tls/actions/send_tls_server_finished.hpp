#pragma once

#include "utopia/common/network/endian/endian.hpp"
#include "utopia/portal_server/client_connection/client_connection.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_server_finished_packet.hpp"
#include "utopia/portal_server/client_connection/tls/events/tls_events.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/tls_compute_handshake_finished_hmac.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/tls_issue_next_iv.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <mbedtls/aes.h>
#include <mbedtls/md.h>
#include <mbedtls/sha256.h>
#include <spdlog/spdlog.h>

#include <random>

namespace utopia::portal::client_connection {

inline const auto send_tls_server_finished =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       ClientConnection &client_connection, TlsContext &context) {
      // Send packet using default values
      TlsServerFinishedPacket tls_server_finished_packet;

      auto iv_enc_opt = tls_issue_next_iv(context);

      if (!iv_enc_opt) {
        spdlog::error("Failed to issue next IV.");
        event_queue->enqueue(
            ClientConnectionEvent{TlsEvents::FailedToIssueNextIV{}});
        return;
      }
      tls_server_finished_packet.iv_enc = iv_enc_opt.value();

      // Build the server_finished data from the checksum
      constexpr std::string server_finished_label = "server finished";
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
            ClientConnectionEvent{TlsEvents::UnableToSendPacket{}});
        return;
      }

      auto server_finished_opt =
          tls_prf_sha256(context.master_secret, server_finished_label_vec,
                         checksum, context.server_finished.size());

      if (!server_finished_opt) {
        spdlog::error("Failed to compute server finished data");
        event_queue->enqueue(
            ClientConnectionEvent{TlsEvents::UnableToSendPacket{}});
        return;
      }

      assert(server_finished_opt.value().size() ==
             context.server_finished.size());

      auto &server_finished_data = server_finished_opt.value();

      std::move(server_finished_data.begin(), server_finished_data.end(),
                context.server_finished.begin());

      // Write the part of the msg to be encrypted (bytes 0 to 15. First 16
      // bytes). Header + verify data
      std::vector<std::uint8_t> msg_to_encrypt(48);
      msg_to_encrypt[0] = 0x14;
      msg_to_encrypt[1] = 0x00;
      msg_to_encrypt[2] = 0x00;
      msg_to_encrypt[3] = 0x0c;
      std::copy(context.server_finished.begin(), context.server_finished.end(),
                msg_to_encrypt.begin() + 4);

      // Compute the HMAC (bytes 16 to 35. Next 20 bytes)
      const auto calculated_hmac = tls_compute_handshake_finished_hmac(
          context.next_write_id, tls_server_finished_packet.serialize(),
          msg_to_encrypt, context, context.mac_enc, 0x10);

      if (!calculated_hmac) {
        spdlog::error("Failed to compute HMAC.");
        event_queue->enqueue(
            ClientConnectionEvent{TlsEvents::HmacComputationFailed{}});
      }

      // Copy the calculated HMAC into the msg to be encrypted.
      std::copy(calculated_hmac.value().begin(), calculated_hmac.value().end(),
                msg_to_encrypt.begin() + 16);

      // Pad to 48 bytes using PKCS7 padding. But the padded value is `num bytes
      // - 1` rather than just `num bytes`.
      constexpr std::uint8_t num_bytes_to_pad = 48 - 36;
      constexpr std::uint8_t padding_byte = num_bytes_to_pad - 1;
      for (std::uint8_t i = 0; i < num_bytes_to_pad; i++) {
        msg_to_encrypt[i + 36] = padding_byte;
      }

      // encrypt the msg
      mbedtls_aes_crypt_cbc(&context.cipher_enc, MBEDTLS_AES_ENCRYPT, 0x30,
                            iv_enc_opt.value().data(), msg_to_encrypt.data(),
                            tls_server_finished_packet.encrypted_msg.data());

      // Send the packet
      if (!client_connection.send(tls_server_finished_packet.serialize())) {
        spdlog::error("Failed to send STS Connect Reply packet.");
        event_queue->enqueue(
            ClientConnectionEvent{TlsEvents::UnableToSendPacket{}});
        return;
      }

      // Increment context.next_write_id by 1 (in big endian) to prepare for the
      // next client message
      common::be64_enc(context.next_write_id.data(),
                       common::be64_dec(context.next_write_id.data()) + 1);

      event_queue->enqueue(
          ClientConnectionEvent{TlsEvents::SentServerFinishedPacket{}});

      spdlog::debug("Sent TLS Server Finished.");
    };

} // namespace utopia::portal::client_connection
