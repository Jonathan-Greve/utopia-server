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
  std::array<uint8_t, 128> prime{};
  std::array<uint8_t, 1> generator{};
  std::array<uint8_t, 8> salt{};
  std::array<uint8_t, 128> server_public{};

  ServerKey() {
    // The server prime key must match the one stored in the GwLoginClient.dll
    constexpr std::array<uint8_t, 128> hardcoded_prime = {
        0xee, 0xaf, 0x0a, 0xb9, 0xad, 0xb3, 0x8d, 0xd6, 0x9c, 0x33, 0xf8, 0x0a,
        0xfa, 0x8f, 0xc5, 0xe8, 0x60, 0x72, 0x61, 0x87, 0x75, 0xff, 0x3c, 0x0b,
        0x9e, 0xa2, 0x31, 0x4c, 0x9c, 0x25, 0x65, 0x76, 0xd6, 0x74, 0xdf, 0x74,
        0x96, 0xea, 0x81, 0xd3, 0x38, 0x3b, 0x48, 0x13, 0xd6, 0x92, 0xc6, 0xe0,
        0xe0, 0xd5, 0xd8, 0xe2, 0x50, 0xb9, 0x8b, 0xe4, 0x8e, 0x49, 0x5c, 0x1d,
        0x60, 0x89, 0xda, 0xd1, 0x5d, 0xc7, 0xd7, 0xb4, 0x61, 0x54, 0xd6, 0xb6,
        0xce, 0x8e, 0xf4, 0xad, 0x69, 0xb1, 0x5d, 0x49, 0x82, 0x55, 0x9b, 0x29,
        0x7b, 0xcf, 0x18, 0x85, 0xc5, 0x29, 0xf5, 0x66, 0x66, 0x0e, 0x57, 0xec,
        0x68, 0xed, 0xbc, 0x3c, 0x05, 0x72, 0x6c, 0xc0, 0x2f, 0xd4, 0xcb, 0xf4,
        0x97, 0x6e, 0xaa, 0x9a, 0xfd, 0x51, 0x38, 0xfe, 0x83, 0x76, 0x43, 0x5b,
        0x9f, 0xc6, 0x1d, 0x2f, 0xc0, 0xeb, 0x06, 0xe3};

    // The salt can be anything but the server uses this as of GW version 37400
    constexpr std::array<uint8_t, 8> hardcoded_salt = {0x62, 0x53, 0xf6, 0xf2,
                                                       0x34, 0x00, 0x09, 0x20};

    prime = hardcoded_prime;
    salt = hardcoded_salt;

    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    mbedtls_mpi p, g, x, y;

    mbedtls_entropy_init(&entropy);
    mbedtls_ctr_drbg_init(&ctr_drbg);
    mbedtls_mpi_init(&p);
    mbedtls_mpi_init(&g);
    mbedtls_mpi_init(&x);
    mbedtls_mpi_init(&y);

    const char *personalization = "server_key_gen";

    // Seed and set up the random number generator
    if (mbedtls_ctr_drbg_seed(
            &ctr_drbg, mbedtls_entropy_func, &entropy,
            reinterpret_cast<const unsigned char *>(personalization),
            strlen(personalization)) != 0) {
      spdlog::error("Failed to initialize random number generator");
      throw std::runtime_error("Random number generator initialization failed");
    }

    // Load prime and generator into mbedtls_mpi structures
    mbedtls_mpi_read_binary(&p, prime.data(), prime.size());
    mbedtls_mpi_read_binary(&g, generator.data(), generator.size());

    // Generate private key x
    if (mbedtls_mpi_fill_random(&x, 32, mbedtls_ctr_drbg_random, &ctr_drbg) !=
        0) {
      spdlog::error("Failed to generate private key");
      throw std::runtime_error("Private key generation failed");
    }

    // Store the private key x in the private member
    size_t x_size = mbedtls_mpi_size(&x);
    private_key.resize(x_size);
    mbedtls_mpi_write_binary(&x, private_key.data(), x_size);

    // Compute server public key y = g^x mod p
    if (mbedtls_mpi_exp_mod(&y, &g, &x, &p, NULL) != 0) {
      spdlog::error("Failed to compute server public key");
      throw std::runtime_error("Public key computation failed");
    }

    // Export the server public key to binary
    mbedtls_mpi_write_binary(&y, server_public.data(), server_public.size());

    mbedtls_mpi_free(&p);
    mbedtls_mpi_free(&g);
    mbedtls_mpi_free(&x);
    mbedtls_mpi_free(&y);
    mbedtls_ctr_drbg_free(&ctr_drbg);
    mbedtls_entropy_free(&entropy);
  }

private:
  std::vector<uint8_t> private_key; // Private key stored as a private member
};

} // namespace utopia::portal::client_connection
