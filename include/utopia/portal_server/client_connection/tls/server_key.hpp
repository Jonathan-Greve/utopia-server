#pragma once

#include "mbedtls/bignum.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/dhm.h"
#include "mbedtls/entropy.h"

#include <spdlog/spdlog.h>

#include <array>
#include <stdexcept>
#include <string>

namespace utopia::portal::client_connection {

class ServerKey {
public:
  std::array<uint8_t, 128> prime{};         // 128 bytes p
  std::array<uint8_t, 1> generator{2};      // 1 byte g
  std::array<uint8_t, 8> salt{};            // 8 bytes salt
  std::array<uint8_t, 128> server_public{}; // 128 bytes public key

  ServerKey() {
    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    const char *personalization = "server_key_gen";

    mbedtls_entropy_init(&entropy);
    mbedtls_ctr_drbg_init(&ctr_drbg);

    // Seed and set up the random number generator
    if (mbedtls_ctr_drbg_seed(
            &ctr_drbg, mbedtls_entropy_func, &entropy,
            reinterpret_cast<const unsigned char *>(personalization),
            strlen(personalization)) != 0) {
      spdlog::error("Failed to initialize random number generator");
      throw std::runtime_error("Random number generator initialization failed");
    }

    // Generate random data for prime, salt, and server_public
    if (mbedtls_ctr_drbg_random(&ctr_drbg, prime.data(), prime.size()) != 0 ||
        mbedtls_ctr_drbg_random(&ctr_drbg, salt.data(), salt.size()) != 0 ||
        mbedtls_ctr_drbg_random(&ctr_drbg, server_public.data(),
                                server_public.size()) != 0) {
      spdlog::error("Failed to generate random data");
      throw std::runtime_error("Random data generation failed");
    }

    mbedtls_ctr_drbg_free(&ctr_drbg);
    mbedtls_entropy_free(&entropy);
  }
};

} // namespace utopia::portal::client_connection
