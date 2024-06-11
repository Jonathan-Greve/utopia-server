#pragma once

#include "mbedtls/bignum.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/dhm.h"
#include "mbedtls/entropy.h"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/compute_legacy_verifier_hash.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/sha1_concat_2_values.hpp"

#include <spdlog/spdlog.h>

#include <array>
#include <stdexcept>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

class ServerKey {
public:
  std::array<uint8_t, 128> prime{};
  std::array<uint8_t, 1> generator{};
  std::array<uint8_t, 8> salt{};
  std::array<uint8_t, 20> verifier{};
  std::array<uint8_t, 128> server_public{};

  ServerKey() = default;

  // This is a temporary solution until a proper implementation is made
  // usually the salt and verifier are stored in a database with unique values
  // for each user. The prime and generator are hardcoded in the server and the
  // client (i.e. they are the same for all users).
  inline void generate(std::vector<uint8_t> username) {
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

    // The salt can be anything but the server uses this as of GW version 37400.
    // It probably sends a different salt for each user (Not verified).
    constexpr std::array<uint8_t, 8> hardcoded_salt = {0x62, 0x53, 0xf6, 0xf2,
                                                       0x34, 0x00, 0x09, 0x20};

    // See: `https://www.nic.ad.jp/ja/tech/ipa/RFC5054EN.html` (Which is a link
    // to the RFC 5054): "Using the Secure Remote Password (SRP) Protocol for
    // TLS Authentication" for more information on the computations.

    // Compute verifier:
    // x = SHA1(s | SHA1(I | ":" | P))
    // v = g^x % N
    // where `s` is the salt, `I` is the username, `P` is the password,
    // `g` is the generator, `N` is the prime number

    // the verifier_hash is the `SHA1(I | ":" | P)` part but GW does some extra
    // stuff on the password as can be seen in the
    // `compute_legacy_verifier_hash` function.

    std::string hardcoded_password = "admin";
    std::vector<uint8_t> hardcoded_password_vec(hardcoded_password.begin(),
                                                hardcoded_password.end());

    auto verifier_hash_opt =
        compute_legacy_verifier_hash(username, hardcoded_password_vec);

    if (!verifier_hash_opt) {
      spdlog::error("Failed to compute verifier hash");
      return;
    }

    // Add salt to the verifier_hash
    std::vector<std::uint8_t> salt_vec(hardcoded_salt.begin(),
                                       hardcoded_salt.end());
    std::vector<std::uint8_t> verifier_hash_vec(
        verifier_hash_opt.value().begin(), verifier_hash_opt.value().end());
    auto x = sha1_concat_2_values(salt_vec, verifier_hash_vec);

    if (!x) {
      spdlog::error("Failed to compute x");
      return;
    }

    mbedtls_mpi mpi_N, mpi_g, mpi_x, mpi_v;
    mbedtls_mpi_init(&mpi_N);
    mbedtls_mpi_init(&mpi_g);
    mbedtls_mpi_init(&mpi_x);
    mbedtls_mpi_init(&mpi_v);
    int ret = 0;
    if ((ret = mbedtls_mpi_read_binary(&mpi_N, hardcoded_prime.data(),
                                       hardcoded_prime.size())) != 0) {
      spdlog::error("Failed to read binary prime");
      return;
    }

    if ((ret = mbedtls_mpi_read_binary(&mpi_g, generator.data(),
                                       generator.size())) != 0) {
      spdlog::error("Failed to read binary generator");
      return;
    }

    if ((ret = mbedtls_mpi_read_binary(&mpi_x, x.value().data(),
                                       x.value().size())) != 0) {
      spdlog::error("Failed to read binary x");
      return;
    }
    if ((ret = mbedtls_mpi_exp_mod(&mpi_v, &mpi_g, &mpi_x, &mpi_N, nullptr)) !=
        0) {
      spdlog::error("Failed to compute verifier");
      return;
    }

    if ((ret = mbedtls_mpi_write_binary(&mpi_v, verifier.data(),
                                        verifier.size())) != 0) {
      spdlog::error("Failed to write binary verifier");
      return;
    }

    prime = hardcoded_prime;
    salt = hardcoded_salt;
    generator[0] = 2;

    // mbedtls_entropy_context entropy;
    // mbedtls_ctr_drbg_context ctr_drbg;
    // mbedtls_mpi p, g, x, y;

    // mbedtls_entropy_init(&entropy);
    // mbedtls_ctr_drbg_init(&ctr_drbg);
    // mbedtls_mpi_init(&p);
    // mbedtls_mpi_init(&g);
    // mbedtls_mpi_init(&x);
    // mbedtls_mpi_init(&y);

    // const char *personalization = "server_key_gen";

    // // Seed and set up the random number generator
    // if (mbedtls_ctr_drbg_seed(
    //         &ctr_drbg, mbedtls_entropy_func, &entropy,
    //         reinterpret_cast<const unsigned char *>(personalization),
    //         strlen(personalization)) != 0) {
    //   spdlog::error("Failed to initialize random number generator");
    //   return;
    // }

    // // Load prime and generator into mbedtls_mpi structures
    // mbedtls_mpi_read_binary(&p, prime.data(), prime.size());
    // mbedtls_mpi_read_binary(&g, generator.data(), generator.size());

    // // Generate private key x
    // if (mbedtls_mpi_fill_random(&x, 32, mbedtls_ctr_drbg_random, &ctr_drbg)
    // !=
    //     0) {
    //   spdlog::error("Failed to generate private key");
    //   return;
    // }

    // // Store the private key x in the private member
    // size_t x_size = mbedtls_mpi_size(&x);
    // private_key.resize(x_size);
    // mbedtls_mpi_write_binary(&x, private_key.data(), x_size);

    // // Compute server public key y = g^x mod p
    // if (mbedtls_mpi_exp_mod(&y, &g, &x, &p, NULL) != 0) {
    //   spdlog::error("Failed to compute server public key");
    //   return;
    // }

    // // Export the server public key to binary
    // mbedtls_mpi_write_binary(&y, server_public.data(), server_public.size());

    // mbedtls_mpi_free(&p);
    // mbedtls_mpi_free(&g);
    // mbedtls_mpi_free(&x);
    // mbedtls_mpi_free(&y);
    // mbedtls_ctr_drbg_free(&ctr_drbg);
    // mbedtls_entropy_free(&entropy);
  }

private:
  std::vector<uint8_t> private_key; // Private key stored as a private member
};

} // namespace utopia::portal::client_connection
