#pragma once

#include "mbedtls/bignum.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/dhm.h"
#include "mbedtls/entropy.h"

#include <spdlog/spdlog.h>

namespace utopia::portal::client_connection {
struct ServerKey {
  uint8_t prime[128];
  uint8_t generator[1];
  uint8_t salt[8];
  uint8_t server_public[128];

  ServerKey() {
    int ret;
    mbedtls_dhm_context dhm;
    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    unsigned char buf[128];
    size_t len;

    mbedtls_dhm_init(&dhm);
    mbedtls_entropy_init(&entropy);
    mbedtls_ctr_drbg_init(&ctr_drbg);

    const char *pers = "dhm_genkey";
    if ((ret = mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy,
                                     (const unsigned char *)pers,
                                     strlen(pers))) != 0) {
      spdlog::error("mbedtls_ctr_drbg_seed failed: {}", ret);
      return;
    }

    // Set the generator to 2
    if ((ret = mbedtls_mpi_lset(&dhm.G, 2)) != 0) {
      spdlog::error("mbedtls_mpi_lset failed: {}", ret);
      return;
    }

    // Generate DH parameters (prime p)
    if ((ret = mbedtls_dhm_make_params(
             &dhm, 128, buf, &len, mbedtls_ctr_drbg_random, &ctr_drbg)) != 0) {
      spdlog::error("mbedtls_dhm_make_params failed: {}", ret);
      return;
    }

    // Copy the prime
    mbedtls_mpi_write_binary(&dhm.P, prime, 128);

    // Copy the generator (2)
    generator[0] = 2;

    // Generate salt (random 8 bytes)
    if ((ret = mbedtls_ctr_drbg_random(&ctr_drbg, salt, 8)) != 0) {
      spdlog::error("mbedtls_ctr_drbg_random failed: {}", ret);
      return;
    }

    // Generate server's public key
    if ((ret = mbedtls_dhm_make_public(&dhm, 128, server_public, 128,
                                       mbedtls_ctr_drbg_random, &ctr_drbg)) !=
        0) {
      spdlog::error("mbedtls_dhm_make_public failed: {}", ret);
      return;
    }

    // Free resources
    mbedtls_dhm_free(&dhm);
    mbedtls_entropy_free(&entropy);
    mbedtls_ctr_drbg_free(&ctr_drbg);
  }
};
} // namespace utopia::portal::client_connection
