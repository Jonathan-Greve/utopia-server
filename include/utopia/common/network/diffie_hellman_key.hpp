#pragma once
#include "utopia/common/file_io/read_file.hpp"

#include <mbedtls/bignum.h>

#include <cassert>
#include <optional>
#include <string>
#include <vector>

namespace utopia::common {
/**
 * @class DiffieHellmanKey
 * @brief Manages Diffie-Hellman keys.
 *
 * This class provides functionality to create, serialize and deserialize
 * Diffie-Hellman keys. It also provides accessors to retrieve specific
 * components of the Diffie-Hellman key.
 */
class DiffieHellmanKey final {
public:
  /**
   * @brief Creates a Diffie-Hellman key object from binary key data.
   * @param key_data Binary key data representing the Diffie-Hellman keys.
   * Assumes big-endian format.
   * @return A Diffie-Hellman key object or an error code.
   */
  static std::optional<DiffieHellmanKey>
  create(const std::vector<std::uint8_t> &key_data) {
    auto dhm_key = DiffieHellmanKey();

    if (!dhm_key.deserialize_key_data(key_data)) {
      return std::nullopt;
    }

    return dhm_key;
  }

  /**
   * @brief Creates a Diffie-Hellman key object from a file.
   * @param filepath Path to the file containing the Diffie-Hellman key data.
   * @return A Diffie-Hellman key object or an error code.
   */
  static std::optional<DiffieHellmanKey>
  create_from_file(const std::string &filepath) {
    const auto dhm_key_data = read_file(filepath);

    if (!dhm_key_data.has_value()) {
      return std::nullopt;
    }

    return create(dhm_key_data.value());
  }

  /**
   * @brief Retrieves the prime modulus of the Diffie-Hellman key.
   * @return Prime modulus component of the Diffie-Hellman key.
   */
  [[nodiscard]] mbedtls_mpi get_prime_modulus() const {
    assert(valid_key_);
    return prime_modulus_;
  }

  /**
   * @brief Retrieves the server's public component of the Diffie-Hellman key.
   * @return Server's public component of the Diffie-Hellman key.
   */
  [[nodiscard]] mbedtls_mpi get_server_public() const {
    assert(valid_key_);
    return server_public_;
  }

  /**
   * @brief Retrieves the primitive root of the Diffie-Hellman key.
   * @return Primitive root component of the Diffie-Hellman key.
   */
  [[nodiscard]] mbedtls_mpi get_primitive_root() const {
    assert(valid_key_);
    return primitive_root_;
  }

  /// Copy constructor for the DiffieHellmanKey.
  DiffieHellmanKey(const DiffieHellmanKey &other)
      : valid_key_(other.valid_key_), prime_modulus_(other.prime_modulus_),
        server_public_(other.server_public_),
        primitive_root_(other.primitive_root_) {
    // Copy MPI values
    int res = mbedtls_mpi_copy(&prime_modulus_, &other.prime_modulus_);
    if (res != 0) {
      spdlog::error("Failed to copy prime modulus");
    }

    res = mbedtls_mpi_copy(&server_public_, &other.server_public_);
    if (res != 0) {
      spdlog::error("Failed to copy server public key");
    }

    res = mbedtls_mpi_copy(&primitive_root_, &other.primitive_root_);
    if (res != 0) {
      spdlog::error("Failed to copy primitive root");
    }
  }

  DiffieHellmanKey &operator=(const DiffieHellmanKey &other) {
    if (this == &other) {
      return *this; // handle self assignment
    }

    valid_key_ = other.valid_key_;

    // Copying MPI values
    int res = mbedtls_mpi_copy(&prime_modulus_, &other.prime_modulus_);
    if (res != 0) {
      spdlog::error("Failed to copy prime modulus");
    }

    res = mbedtls_mpi_copy(&server_public_, &other.server_public_);
    if (res != 0) {
      spdlog::error("Failed to copy server public key");
    }

    res = mbedtls_mpi_copy(&primitive_root_, &other.primitive_root_);
    if (res != 0) {
      spdlog::error("Failed to copy primitive root");
    }

    return *this;
  }

private:
  /// Default constructor.
  explicit DiffieHellmanKey()
      : valid_key_{false}, prime_modulus_{0, 0, nullptr},
        server_public_{0, 0, nullptr}, primitive_root_{0, 0, nullptr} {
    spdlog::trace("DiffieHellmanKey constructor called.");
  }
  bool valid_key_; ///< Indicates if the key is valid or not.

  mbedtls_mpi
      prime_modulus_; ///< Prime modulus for Diffie-Hellman key exchange.
  mbedtls_mpi
      server_public_; ///< Server public key for Diffie-Hellman key exchange.
  mbedtls_mpi
      primitive_root_; ///< Primitive root for Diffie-Hellman key exchange.

  /**
   * @brief Converts the binary key data into Diffie-Hellman key components.
   * @param key_data Binary key data for deserialization. Assumes big-endian
   * format.
   * @return true if conversion is successful, false otherwise.
   */
  bool deserialize_key_data(const std::vector<std::uint8_t> &key_data) {
    constexpr std::size_t key_key_data_size = 132;
    if (key_data.size() != key_key_data_size) {
      // 4 + 64 + 64
      spdlog::error("Invalid key_data size for diffie-hellman key.");
      return false;
    }

    assert(key_data.size() == key_key_data_size);
    mbedtls_mpi_read_binary(&primitive_root_, key_data.data(), 4);
    mbedtls_mpi_read_binary(&prime_modulus_, &key_data.at(4), 64);
    mbedtls_mpi_read_binary(&server_public_, &key_data.at(68), 64);

    valid_key_ = true;

    return valid_key_;
  }
};
} // namespace utopia::common
