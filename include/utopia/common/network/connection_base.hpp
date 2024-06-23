#pragma once

#include "utopia/common/network/diffie_hellman_key.hpp"

#include <asio.hpp>
#include <mbedtls/arc4.h>
#include <mbedtls/bignum.h>
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/entropy.h>
#include <psa/crypto_types.h>
#include <psa/crypto_values.h>

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace utopia::common {

/**
 * @class ConnectionBase
 * @brief Represents a network connection and provides key exchange, encryption,
 * and decryption functionality.
 *
 * The ConnectionBase class is used to handle TCP connections using ASIO, and
 * it implements encryption and decryption through the PSA crypto library. It
 * also includes a Diffie-Hellman key exchange method for securing
 * communication.
 */
class ConnectionBase {
public:
  std::uint32_t try_read_some(std::vector<std::uint8_t> &data);
  std::uint32_t try_read_some_and_decrypt(std::vector<std::uint8_t> &data);
  std::optional<std::uint32_t>
  read_some(std::vector<std::uint8_t> &data,
            std::uint32_t num_bytes_to_read = 8192);
  std::optional<std::uint32_t>
  read_some_and_decrypt(std::vector<std::uint8_t> &data);
  bool encrypt_and_send(const std::vector<std::uint8_t> &data);
  bool send(const std::vector<std::uint8_t> &data);

  bool is_connected();
  bool disconnect();

  ConnectionBase(ConnectionBase &&) = delete;
  ConnectionBase &operator=(ConnectionBase &&) = delete;
  ConnectionBase(const ConnectionBase &) = delete;
  ConnectionBase &operator=(const ConnectionBase &) = delete;

  virtual ~ConnectionBase();

protected:
  explicit ConnectionBase(asio::io_context &io_context);
  bool connect(const std::string &host, const std::string &port);
  bool accept_connection(unsigned short port);
  std::optional<std::string> get_local_endpoint_address() const;
  std::optional<std::string> get_remote_endpoint_address() const;
  bool do_key_exchange(const DiffieHellmanKey &dhm_key);
  psa_status_t encrypt(const std::vector<std::uint8_t> &input,
                       std::vector<std::uint8_t> &output);
  psa_status_t decrypt(const std::vector<std::uint8_t> &input,
                       std::vector<std::uint8_t> &output);

private:
  asio::ip::tcp::socket socket_;
  asio::ip::tcp::resolver resolver_;
  mbedtls_arc4_context arc4_encrypt_context_;
  mbedtls_arc4_context arc4_decrypt_context_;
  mbedtls_ctr_drbg_context ctr_drbg_;
  mbedtls_entropy_context entropy_;

  static psa_status_t
  perform_arc4_cipher(mbedtls_arc4_context &arc4_context,
                      const std::vector<std::uint8_t> &input,
                      std::vector<std::uint8_t> &output);
  static void arc4_hash(const std::uint8_t *key, std::uint8_t *digest);
};

} // namespace utopia::common
