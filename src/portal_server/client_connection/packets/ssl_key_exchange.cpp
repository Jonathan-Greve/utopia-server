#pragma once

#include "utopia/portal_server/client_connection/packets/ssl_key_exchange.hpp"

#include <mbedtls/aes.h>
#include <mbedtls/bignum.h>
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/entropy.h>
#include <mbedtls/md.h>
#include <mbedtls/sha1.h>
#include <mbedtls/sha256.h>
#include <spdlog/spdlog.h>

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

SslKeyExchangePacket::SslKeyExchangePacket(std::vector<uint8_t> &data) {}

std::uint32_t SslKeyExchangePacket::get_packet_size() { return 0; }

std::vector<uint8_t> SslKeyExchangePacket::serialize() { return {}; }

const std::array<uint8_t, 128> &
SslKeyExchangePacket::get_client_public_key() const noexcept {
  if (!is_valid_) {
    spdlog::error("Trying to get client public key from invalid packet");
    return {};
  }

  return client_public_key_;
}

void SslKeyExchangePacket::generate_public_key() {
  // auto generator = std::make_unique<mbedtls_mpi>();
  // auto prime_modulus = std::make_unique<mbedtls_mpi>();
  // auto client_private = std::make_unique<mbedtls_mpi>();
  // auto client_public = std::make_unique<mbedtls_mpi>();

  // mbedtls_mpi_init(generator.get());
  // mbedtls_mpi_init(prime_modulus.get());
  // mbedtls_mpi_init(client_private.get());
  // mbedtls_mpi_init(client_public.get());

  // auto cleanup = [&]() {
  //   mbedtls_mpi_free(generator.get());
  //   mbedtls_mpi_free(prime_modulus.get());
  //   mbedtls_mpi_free(client_private.get());
  //   mbedtls_mpi_free(client_public.get());
  // };

  // if (mbedtls_mpi_read_binary(prime_modulus.get(), ssl_.server_key.prime,
  //                             sizeof(ssl_.server_key.prime)) != 0) {
  //   cleanup();
  //   return;
  // }

  // if (mbedtls_mpi_read_binary(generator.get(), ssl_.server_key.generator,
  //                             sizeof(ssl_.server_key.generator)) != 0) {
  //   cleanup();
  //   return;
  // }

  // if (mbedtls_mpi_read_binary(client_private.get(),
  //                             ssl_.client_key.private_data,
  //                             sizeof(ssl_.client_key.private_data)) != 0) {
  //   cleanup();
  //   return;
  // }

  // if (mbedtls_mpi_exp_mod(client_public.get(), generator.get(),
  //                         client_private.get(), prime_modulus.get(),
  //                         nullptr) != 0) {
  //   cleanup();
  //   return;
  // }

  // if (mbedtls_mpi_write_binary(client_public.get(),
  // ssl_.client_key.public_data,
  //                              sizeof(ssl_.client_key.public_data)) != 0) {
  //   cleanup();
  //   return;
  // }

  // cleanup();
}

} // namespace utopia::portal::client_connection
