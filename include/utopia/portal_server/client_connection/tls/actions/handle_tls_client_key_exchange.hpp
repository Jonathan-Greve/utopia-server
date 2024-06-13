#pragma once

#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_key_exchange_packet.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/concat.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/pad.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/serialize_tls12_random.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/sha1.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/tls_prf_sha256.hpp"
#include "utopia/portal_server/client_connection/tls/tls_context.hpp"

#include <concurrentqueue.h>
#include <mbedtls/bignum.h>
#include <spdlog/spdlog.h>

#include <array>
#include <cstdint>
#include <optional>
#include <vector>

namespace utopia::portal::client_connection {

inline const auto handle_tls_client_key_exchange =
    [](moodycamel::ConcurrentQueue<ClientConnectionEvent> *event_queue,
       TlsClientKeyExchangePacket event, TlsContext &context) {
      const auto data = event.serialize();
      mbedtls_sha256_update_ret(&context.checksum, &data.at(5), event.size);

      context.client_public = event.public_key;

      assert(context.client_public.size() == context.server_key.prime.size());
      assert(context.client_public.size() == 128);

      const auto u = sha1(concat(pad(context.client_public, 128),
                                 pad(context.server_key.server_public, 128)));

      mbedtls_mpi N_mpi;
      mbedtls_mpi v_mpi;
      mbedtls_mpi b_mpi;
      mbedtls_mpi u_mpi;
      mbedtls_mpi A_mpi;
      mbedtls_mpi premaster_secret;

      mbedtls_mpi temp1;
      mbedtls_mpi temp2;

      mbedtls_mpi_init(&N_mpi);
      mbedtls_mpi_init(&v_mpi);
      mbedtls_mpi_init(&b_mpi);
      mbedtls_mpi_init(&u_mpi);
      mbedtls_mpi_init(&A_mpi);
      mbedtls_mpi_init(&premaster_secret);

      mbedtls_mpi_init(&temp1);
      mbedtls_mpi_init(&temp2);

      mbedtls_mpi_read_binary(&N_mpi, context.server_key.prime.data(),
                              context.server_key.prime.size());

      mbedtls_mpi_read_binary(&v_mpi, context.server_key.verifier.data(),
                              context.server_key.verifier.size());

      mbedtls_mpi_read_binary(&b_mpi, context.server_key.private_key.data(),
                              context.server_key.private_key.size());

      mbedtls_mpi_read_binary(&u_mpi, u.value().data(), u.value().size());

      mbedtls_mpi_read_binary(&A_mpi, context.client_public.data(),
                              context.client_public.size());

      // Compute S = (A * v^u) ^ b % N
      if (mbedtls_mpi_exp_mod(&temp1, &v_mpi, &u_mpi, &N_mpi, nullptr) ||
          mbedtls_mpi_mul_mpi(&temp2, &A_mpi, &temp1) ||
          mbedtls_mpi_exp_mod(&premaster_secret, &temp2, &b_mpi, &N_mpi,
                              nullptr)) {
        spdlog::error("Failed to compute premaster secret");
        return;
      }

      const auto premaster_secret_size = mbedtls_mpi_size(&premaster_secret);
      spdlog::debug("Premaster secret size: {}", premaster_secret_size);
      assert(premaster_secret_size == 128);

      if (mbedtls_mpi_write_binary(&premaster_secret,
                                   context.premaster_secret.data(),
                                   context.premaster_secret.size())) {
        spdlog::error("Failed to write premaster secret");
        return;
      }

      // Computer master key
      const auto randoms_cli_ser =
          serialize_tls12_random(context.client_random, context.server_random);

      constexpr std::string master_secret_label = "master secret";
      const std::vector<std::uint8_t> master_secret_label_vec(
          master_secret_label.begin(), master_secret_label.end());

      const std::vector<std::uint8_t> premaster_secret_vec(
          context.premaster_secret.begin(), context.premaster_secret.end());

      const auto master_secret = tls_prf_sha256(
          premaster_secret_vec, master_secret_label_vec, randoms_cli_ser, 48);

      if (!master_secret) {
        spdlog::error("Failed to compute master secret");
        return;
      }

      assert(master_secret.value().size() == 48);

      context.master_secret = master_secret.value();

      // Compute key block.
      const auto randoms_ser_client =
          serialize_tls12_random(context.server_random, context.client_random);

      constexpr std::string keyblock_label = "key expansion";
      const std::vector<std::uint8_t> keyblock_label_vec(keyblock_label.begin(),
                                                         keyblock_label.end());

      const auto keyblock_opt = tls_prf_sha256(
          context.master_secret, keyblock_label_vec, randoms_ser_client, 104);

      if (!keyblock_opt) {
        spdlog::error("Failed to compute key block");
        return;
      }
      auto &keyblock = keyblock_opt.value();

      assert(keyblock.size() == 104);

      // Setup keys HMAC and AES. Note that we're using symmetric encryption
      // algorithms. So the decode key on the client is the same as the encode
      // key on the server.
      std::span<const std::uint8_t> mac_dec_key(keyblock.data(), 20);
      std::span<const std::uint8_t> mac_enc_key(keyblock.data() + 20, 20);
      std::span<const std::uint8_t> cipher_dec_key(keyblock.data() + 40, 32);
      std::span<const std::uint8_t> cipher_enc_key(keyblock.data() + 72, 32);

      constexpr std::uint16_t CIPHER_KEY_BITS = 32 * 8;
      if (mbedtls_aes_setkey_enc(&context.cipher_enc, cipher_enc_key.data(),
                                 CIPHER_KEY_BITS)) {
        spdlog::error("Failed to set cipher_enc key");
        return;
      }
      if (mbedtls_aes_setkey_dec(&context.cipher_dec, cipher_dec_key.data(),
                                 CIPHER_KEY_BITS)) {
        spdlog::error("Failed to set cipher_dec key");
        return;
      }

      const mbedtls_md_info_t *md_info;
      if ((md_info = mbedtls_md_info_from_type(MBEDTLS_MD_SHA1)) == nullptr) {
        spdlog::error("Failed to get md_info");
        return;
      }

      constexpr int is_hmac = 1;
      constexpr size_t HMAC_KEY_LEN = 20;

      if (mbedtls_md_setup(&context.mac_enc, md_info, is_hmac)) {
        spdlog::error("Failed to setup mac_enc");
        return;
      }
      if (mbedtls_md_hmac_starts(&context.mac_enc, mac_enc_key.data(),
                                 HMAC_KEY_LEN)) {
        spdlog::error("Failed to start mac_enc");
        return;
      }

      if (mbedtls_md_setup(&context.mac_dec, md_info, is_hmac)) {
        spdlog::error("Failed to setup mac_dec");
        return;
      }
      if (mbedtls_md_hmac_starts(&context.mac_dec, mac_dec_key.data(),
                                 HMAC_KEY_LEN)) {
        spdlog::error("Failed to start mac_dec");
        return;
      }

      constexpr std::string client_finished_label = "client finished";
      const std::vector<std::uint8_t> client_finished_label_vec(
          client_finished_label.begin(), client_finished_label.end());

      mbedtls_sha256_context checksum_ctx;
      mbedtls_sha256_init(&checksum_ctx);
      mbedtls_sha256_clone(&checksum_ctx, &context.checksum);

      std::vector<std::uint8_t> checksum(32);
      int ret = mbedtls_sha256_finish_ret(&checksum_ctx, checksum.data());
      mbedtls_sha256_free(&checksum_ctx);

      if (ret) {
        spdlog::error("Failed to finish checksum");
        return;
      }

      auto client_finished_opt =
          tls_prf_sha256(context.master_secret, client_finished_label_vec,
                         checksum, context.client_finished.size());

      if (!client_finished_opt) {
        spdlog::error("Failed to compute client finished data");
        return;
      }

      assert(client_finished_opt.value().size() ==
             context.client_finished.size());

      auto &client_finished_data = client_finished_opt.value();

      std::move(client_finished_data.begin(), client_finished_data.end(),
                context.client_finished.begin());

      spdlog::trace("Handling Tls Client Key Exchange packet.");
    };

} // namespace utopia::portal::client_connection
