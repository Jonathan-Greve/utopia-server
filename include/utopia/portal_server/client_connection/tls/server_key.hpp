#pragma once

#include "mbedtls/bignum.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/dhm.h"
#include "mbedtls/entropy.h"

#include <spdlog/spdlog.h>

#include <span>
#include <stdexcept>
#include <string>

namespace utopia::portal::client_connection {

class ServerKey {
public:
  std::array<uint8_t, 128> prime{};
  std::array<uint8_t, 1> generator{2};
  std::array<uint8_t, 8> salt{};
  std::array<uint8_t, 128> server_public{};

  ServerKey() {
    mbedtls_dhm_context dhm;
    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    std::array<uint8_t, 128> buf{};
    size_t len;

    mbedtls_dhm_init(&dhm);
    mbedtls_entropy_init(&entropy);
    mbedtls_ctr_drbg_init(&ctr_drbg);

    const std::string pers = "jona123@utopiaserver";
    if (auto ret = mbedtls_ctr_drbg_seed(
            &ctr_drbg, mbedtls_entropy_func, &entropy,
            reinterpret_cast<const unsigned char *>(pers.data()), pers.size());
        ret != 0) {
      spdlog::error("mbedtls_ctr_drbg_seed failed: {}", ret);
      throw std::runtime_error("Failed to seed CTR_DRBG");
    }

    if (auto ret = mbedtls_mpi_lset(&dhm.G, 2); ret != 0) {
      spdlog::error("mbedtls_mpi_lset failed: {}", ret);
      throw std::runtime_error("Failed to set generator");
    }

    if (auto ret = mbedtls_dhm_make_params(&dhm, 128, buf.data(), &len,
                                           mbedtls_ctr_drbg_random, &ctr_drbg);
        ret != 0) {
      spdlog::error("mbedtls_dhm_make_params failed: {}", ret);
      throw std::runtime_error("Failed to make DH params");
    }

    mbedtls_mpi_write_binary(&dhm.P, prime.data(), prime.size());

    if (auto ret = mbedtls_ctr_drbg_random(&ctr_drbg, salt.data(), salt.size());
        ret != 0) {
      spdlog::error("mbedtls_ctr_drbg_random failed: {}", ret);
      throw std::runtime_error("Failed to generate salt");
    }

    if (auto ret = mbedtls_dhm_make_public(&dhm, 128, server_public.data(),
                                           server_public.size(),
                                           mbedtls_ctr_drbg_random, &ctr_drbg);
        ret != 0) {
      spdlog::error("mbedtls_dhm_make_public failed: {}", ret);
      throw std::runtime_error("Failed to generate public key");
    }

    mbedtls_dhm_free(&dhm);
    mbedtls_entropy_free(&entropy);
    mbedtls_ctr_drbg_free(&ctr_drbg);
  }
};

} // namespace utopia::portal::client_connection
