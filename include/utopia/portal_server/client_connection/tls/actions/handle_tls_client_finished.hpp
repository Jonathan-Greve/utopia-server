#pragma once

#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_finished_packet.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <asio.hpp>
#include <concurrentqueue.h>
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

      // Check that verify_data is equal to context.client_finished
      if (!std::equal(verify_data.begin(), verify_data.end(),
                      context.client_finished.begin())) {
        spdlog::error("Client Finished packet verify data does not match.");
        event_queue->enqueue(ClientConnectionEvent{
            TlsEvents::ClientFinishedVerifyDataMismatch{}});
        return;
      }

      event_queue->enqueue(
          ClientConnectionEvent{TlsEvents::ClientFinishedPacketHandled{}});
      spdlog::trace("Handling Tls Client Finished packet.");
    };

} // namespace utopia::portal::client_connection
