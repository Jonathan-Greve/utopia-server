#pragma once

#include "mbedtls/bignum.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/dhm.h"
#include "mbedtls/entropy.h"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/compute_legacy_verifier_hash.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/concat.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/pad.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/sha1.hpp"

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
  std::array<uint8_t, 128> verifier{};
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

    prime = hardcoded_prime;
    salt = hardcoded_salt;
    generator[0] = 2;

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

    auto verifier_hash =
        compute_legacy_verifier_hash(username, hardcoded_password_vec);

    if (!verifier_hash) {
      spdlog::error("Failed to compute verifier hash");
      return;
    }

    auto x = sha1(concat(salt, verifier_hash.value()));

    if (!x) {
      spdlog::error("Failed to compute x");
      return;
    }

    mbedtls_mpi mpi_N, mpi_g, mpi_x, mpi_v;
    mbedtls_mpi_init(&mpi_N);
    mbedtls_mpi_init(&mpi_g);
    mbedtls_mpi_init(&mpi_x);
    mbedtls_mpi_init(&mpi_v);

    mbedtls_mpi mpi_b, mpi_k, mpi_B, mpi_temp1, mpi_temp2, mpi_temp3;
    mbedtls_mpi_init(&mpi_b);
    mbedtls_mpi_init(&mpi_k);
    mbedtls_mpi_init(&mpi_B);
    mbedtls_mpi_init(&mpi_temp1);
    mbedtls_mpi_init(&mpi_temp2);
    mbedtls_mpi_init(&mpi_temp3);

    auto cleanup = [&]() {
      mbedtls_mpi_free(&mpi_N);
      mbedtls_mpi_free(&mpi_g);
      mbedtls_mpi_free(&mpi_x);
      mbedtls_mpi_free(&mpi_v);
      mbedtls_mpi_free(&mpi_b);
      mbedtls_mpi_free(&mpi_k);
      mbedtls_mpi_free(&mpi_B);
      mbedtls_mpi_free(&mpi_temp1);
      mbedtls_mpi_free(&mpi_temp2);
      mbedtls_mpi_free(&mpi_temp3);
    };

    if (mbedtls_mpi_read_binary(&mpi_N, hardcoded_prime.data(),
                                hardcoded_prime.size()) ||
        mbedtls_mpi_read_binary(&mpi_g, generator.data(), generator.size()) ||
        mbedtls_mpi_read_binary(&mpi_x, x.value().data(), x.value().size())) {
      spdlog::error("Failed to read mpi values");
      cleanup();
      return;
    }

    if (mbedtls_mpi_exp_mod(&mpi_v, &mpi_g, &mpi_x, &mpi_N, nullptr) ||
        mbedtls_mpi_write_binary(&mpi_v, verifier.data(), verifier.size())) {
      spdlog::error("Failed to compute verifier");
      cleanup();
      return;
    }

    // Initialize random number generator
    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    mbedtls_entropy_init(&entropy);
    mbedtls_ctr_drbg_init(&ctr_drbg);
    const char *pers = "mbedtls";
    if (mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy,
                              (const unsigned char *)pers, strlen(pers)) != 0) {
      spdlog::error("Failed to seed RNG");
      cleanup();
      return;
    }

    // Compute public key
    const auto k = sha1(concat(prime, pad(generator, prime.size())));

    if (mbedtls_ctr_drbg_random(&ctr_drbg, private_key.data(),
                                private_key.size()) ||
        mbedtls_mpi_read_binary(&mpi_b, private_key.data(),
                                private_key.size())) {
      spdlog::error("Failed to generate private key");
      cleanup();
      return;
    }

    if (mbedtls_mpi_read_binary(&mpi_k, k.value().data(), k.value().size())) {
      spdlog::error("Failed to read k value");
      cleanup();
      return;
    }

    // Compute B = (k*v + (g^b % N)) % N. Note that RFC 5054 writes:  B =
    // k*v + g^b % N, which is not correct.
    if (mbedtls_mpi_exp_mod(&mpi_temp1, &mpi_g, &mpi_b, &mpi_N, nullptr) ||
        mbedtls_mpi_mul_mpi(&mpi_temp2, &mpi_k, &mpi_v) ||
        mbedtls_mpi_add_mpi(&mpi_temp3, &mpi_temp2, &mpi_temp1) ||
        mbedtls_mpi_mod_mpi(&mpi_B, &mpi_temp3, &mpi_N)) {
      spdlog::error("Failed to compute B");
      cleanup();
      return;
    }

    // Store public
    if (mbedtls_mpi_write_binary(&mpi_B, server_public.data(),
                                 server_public.size())) {
      spdlog::error("Failed to write public key");
      cleanup();
      return;
    }

    cleanup();
  }

private:
  std::array<uint8_t, 32> private_key;
};

} // namespace utopia::portal::client_connection
