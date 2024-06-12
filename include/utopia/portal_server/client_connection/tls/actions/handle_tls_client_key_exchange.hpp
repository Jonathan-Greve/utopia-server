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

#include <cstdint>

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
      const auto randoms =
          serialize_tls12_random(context.client_random, context.server_random);

      std::string label = "master secret";
      std::vector<std::uint8_t> label_bytes(label.begin(), label.end());

      std::vector<std::uint8_t> premaster_secret_vec(
          context.premaster_secret.begin(), context.premaster_secret.end());

      auto master_secret =
          tls_prf_sha256(premaster_secret_vec, label_bytes, randoms, 48);

      spdlog::trace("Handling Tls Client Key Exchange packet.");
    };

} // namespace utopia::portal::client_connection
