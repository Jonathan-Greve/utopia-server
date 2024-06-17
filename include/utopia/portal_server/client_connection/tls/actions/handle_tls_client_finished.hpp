#pragma once

#include "utopia/common/network/endian/endian.hpp"
#include "utopia/common/strings/get_hex_string_from_bytes.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_finished_packet.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/tls_compute_handshake_finished_hmac.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <mbedtls/aes.h>
#include <mbedtls/md.h>
#include <mbedtls/sha256.h>
#include <spdlog/spdlog.h>

#include <array>
#include <cstdint>
#include <optional>
#include <string>

namespace utopia::portal::client_connection {

inline const auto handle_tls_client_finished =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       TlsClientFinishedPacket event, TlsContext &context) {
      const auto data = event.serialize();

      std::vector<std::uint8_t> decrypted_msg(0x30);
      if (mbedtls_aes_crypt_cbc(&context.cipher_dec, MBEDTLS_AES_DECRYPT, 0x30,
                                event.iv_enc.data(), event.encrypted_msg.data(),
                                decrypted_msg.data())) {
        spdlog::error("Failed to decrypt message.");
        event_queue->enqueue(
            ClientConnectionEvent{TlsEvents::FailedToDecryptMessage{}});
        return;
      }

      // Update checksum with handshake message
      mbedtls_sha256_update_ret(&context.checksum, decrypted_msg.data(), 0x10);

      const auto calculated_hmac = tls_compute_handshake_finished_hmac(
          context.next_read_id, data, decrypted_msg, context, context.mac_dec,
          0x10);

      if (!calculated_hmac) {
        spdlog::error("Failed to compute HMAC.");
        event_queue->enqueue(
            ClientConnectionEvent{TlsEvents::HmacComputationFailed{}});
        return;
      }

      // Validate the HMAC
      std::span<std::uint8_t> hmac{decrypted_msg.data() + 16, 20};
      if (!std::equal(hmac.begin(), hmac.end(),
                      calculated_hmac.value().begin())) {
        spdlog::error("HMAC validation failed.");
        event_queue->enqueue(
            ClientConnectionEvent{TlsEvents::HmacValidationFailed{}});
        return;
      }

      // Check that verify_data is equal to context.client_finished
      std::span<std::uint8_t> verify_data{decrypted_msg.data() + 4, 12};
      if (!std::equal(verify_data.begin(), verify_data.end(),
                      context.client_finished.begin())) {
        spdlog::error("Client Finished packet verify data does not match.");
        event_queue->enqueue(ClientConnectionEvent{
            TlsEvents::ClientFinishedVerifyDataMismatch{}});
      }

      // Increment context.next_read_id by 1 (in big endian) to prepare for the
      // next client message
      common::be64_enc(context.next_read_id.data(),
                       common::be64_dec(context.next_read_id.data()) + 1);

      event_queue->enqueue(
          ClientConnectionEvent{TlsEvents::ClientFinishedPacketHandled{}});
      spdlog::trace("Handled Tls Client Finished packet.");
    };
} // namespace utopia::portal::client_connection
