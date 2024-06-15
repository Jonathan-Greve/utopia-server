#pragma once

#include "utopia/common/network/endian/endian.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_finished_packet.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
#include <mbedtls/aes.h>
#include <mbedtls/md.h>
#include <mbedtls/sha256.h>
#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {

inline const auto handle_tls_client_finished =
    [](asio::io_context &io,
       moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       TlsClientFinishedPacket event, TlsContext &context) {
      const auto data = event.serialize();
      mbedtls_sha256_update_ret(&context.checksum, &data.at(5), event.size);

      std::vector<std::uint8_t> decrypted_msg(0x30);
      if (mbedtls_aes_crypt_cbc(&context.cipher_dec, MBEDTLS_AES_DECRYPT, 0x30,
                                event.iv_enc.data(), event.encrypted_msg.data(),
                                decrypted_msg.data())) {
        spdlog::error("Failed to decrypt message.");
        event_queue->enqueue(
            ClientConnectionEvent{TlsEvents::FailedToDecryptMessage{}});
        return;
      }

      std::span<std::uint8_t> msg_header{decrypted_msg.data(), 4};
      std::span<std::uint8_t> verify_data{decrypted_msg.data() + 4, 12};
      std::span<std::uint8_t> hmac{decrypted_msg.data() + 16, 20};

      // Validate the hmac
      mbedtls_md_hmac_reset(&context.mac_dec);
      mbedtls_md_hmac_update(&context.mac_dec, context.next_read_id.data(),
                             context.next_read_id.size());
      // Increment context.next_read_id by 1 (in big endian) to prepare for the
      // next client message
      common::be64_enc(context.next_read_id.data(),
                       common::be64_dec(context.next_read_id.data()) + 1);

      // The HMAC message was encrypted with the TlsClientFinishedPacket's size
      // set to 0x10. I.e. the size of the packet without the encrypted message.
      // So we set it to 0x10 before computing our HMAC.

      std::array<std::uint8_t, 5> modified_header;
      std::copy(data.begin(), data.begin() + 5, modified_header.begin());
      modified_header[4] = 0x10;

      mbedtls_md_hmac_update(&context.mac_dec, modified_header.data(),
                             modified_header.size());

      // Decrypted msg header (4bytes) + verify_data (12bytes)
      mbedtls_md_hmac_update(&context.mac_dec, decrypted_msg.data(), 16);

      std::array<std::uint8_t, 20> calculated_hmac;
      mbedtls_md_hmac_finish(&context.mac_dec, calculated_hmac.data());

      if (!std::equal(hmac.begin(), hmac.end(), calculated_hmac.begin())) {
        spdlog::error("HMAC validation failed.");
        event_queue->enqueue(
            ClientConnectionEvent{TlsEvents::HmacValidationFailed{}});
        return;
      }

      // Check that verify_data is equal to context.client_finished
      if (!std::equal(verify_data.begin(), verify_data.end(),
                      context.client_finished.begin())) {
        spdlog::error("Client Finished packet verify data does not match.");
        event_queue->enqueue(ClientConnectionEvent{
            TlsEvents::ClientFinishedVerifyDataMismatch{}});
      }

      event_queue->enqueue(
          ClientConnectionEvent{TlsEvents::ClientFinishedPacketHandled{}});
      spdlog::trace("Handling Tls Client Finished packet.");
    };
} // namespace utopia::portal::client_connection
