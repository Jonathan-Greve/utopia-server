#include "utopia/utopia_pch.hpp"

#include "utopia/common/network/connection_base.hpp"

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

// Used in arc4_hash
#define ROL32(x, n) ((x << n) | ((x & 0xFFFFFFFF) >> (32 - n)))

namespace utopia::common {
/**
 * @struct msg_client_seed
 * @brief Represents the client seed message structure.
 *
 * Contains the source, length, and seed bytes for the client.
 */
#pragma pack(push, 1)
struct msg_client_seed {
  std::uint8_t source =
      0; /**< Source of the message, typically set to 0 for client. */
  std::uint8_t length = 66; /**< Length of the seed message, set to 66 bytes. */
  std::array<std::uint8_t, 64> seed =
      {}; /**< Seed value used in the key exchange. */
};

/**
 * @struct msg_server_seed
 * @brief Represents the server seed message structure.
 *
 * Contains the source, length, and seed bytes for the server.
 */
struct msg_server_seed {
  std::uint8_t source =
      1; /**< Source of the message, typically set to 1 for server. */
  std::uint8_t length = 22; /**< Length of the seed message, set to 22 bytes. */
  std::array<std::uint8_t, 20> seed =
      {}; /**< Seed value used in the key exchange. */
};
#pragma pack(pop)

/**
 * @brief Constructs a new ConnectionBase object.
 * @param io_context Reference to the ASIO I/O context to be used for handling
 * I/O operations.
 */
ConnectionBase::ConnectionBase(asio::io_context &io_context)
    : socket_(io_context), resolver_(io_context) {
  // Initialize entropy_ and CTR DRBG contexts
  mbedtls_entropy_init(&entropy_);
  mbedtls_ctr_drbg_init(&ctr_drbg_);
  std::string secret = "Stradivarius";
  mbedtls_ctr_drbg_seed(&ctr_drbg_, mbedtls_entropy_func, &entropy_,
                        reinterpret_cast<std::uint8_t *>(secret.data()),
                        secret.size());
}

/**
 * @brief Receives data from the connected server.
 * @param data Vector where the received data is to be written.
 * @return true on successful reception, false otherwise.
 */
std::uint32_t ConnectionBase::try_read_some(std::vector<std::uint8_t> &data) {
  if (!socket_.is_open()) {
    spdlog::error("Cannot try_read_some, socket is closed");
    return 0;
  }

  if (const std::size_t avail = socket_.available(); avail <= 0) {
    return 0;
  }

  asio::error_code ec;
  const std::size_t length = socket_.read_some(asio::buffer(data), ec);

  if (ec) {
    spdlog::error("Failed to receive data.");
    return 0;
  }

  data.resize(length); // Resize to actual data length received
  return static_cast<std::uint32_t>(length);
}

std::uint32_t
ConnectionBase::try_read_some_and_decrypt(std::vector<std::uint8_t> &data) {
  if (!socket_.is_open()) {
    return 0;
  }

  if (const std::size_t avail = socket_.available(); avail <= 0) {
    return 0;
  }

  asio::error_code ec;
  std::vector<std::uint8_t> recv_buffer(10000);
  const std::size_t length = socket_.read_some(asio::buffer(recv_buffer), ec);

  if (ec) {
    spdlog::error("Failed to receive data.");
    return 0;
  }

  recv_buffer.resize(length);
  std::vector<std::uint8_t> decrypted_data(length);
  decrypt(recv_buffer, decrypted_data);

  // Append the decrypted data to the end of the input argument data
  data.insert(data.end(), decrypted_data.begin(), decrypted_data.end());

  return static_cast<std::uint32_t>(length);
}

std::optional<std::uint32_t>
ConnectionBase::read_some(std::vector<std::uint8_t> &data,
                          std::uint32_t num_bytes_to_read) {
  if (!socket_.is_open()) {
    spdlog::error("Cannot read_some, socket is closed");
    return std::nullopt;
  }

  asio::error_code ec;
  std::vector<std::uint8_t> recv_buffer(num_bytes_to_read);
  const std::size_t length = socket_.read_some(asio::buffer(recv_buffer), ec);

  if (ec) {
    if (ec == asio::error::eof || ec == asio::error::connection_reset) {
      spdlog::info("Client disconnected");
    } else {
      spdlog::error("Failed to receive data: {} (error code: {})", ec.message(),
                    ec.value());
    }
    socket_.close();
    return std::nullopt;
  }

  recv_buffer.resize(length); // Resize to actual data length received
  data.insert(data.end(), recv_buffer.begin(), recv_buffer.end());
  return static_cast<std::uint32_t>(length);
}

std::optional<std::uint32_t>
ConnectionBase::read_some_and_decrypt(std::vector<std::uint8_t> &data) {
  if (!socket_.is_open()) {
    spdlog::error("Cannot read_some, socket is closed");
    return std::nullopt;
  }

  asio::error_code ec;
  std::vector<std::uint8_t> recv_buffer(10000);
  const std::size_t length = socket_.read_some(asio::buffer(recv_buffer), ec);

  if (ec) {
    if (ec == asio::error::eof || ec == asio::error::connection_reset) {
      spdlog::info("Client disconnected");
    } else {
      spdlog::error("Failed to receive data: {} (error code: {})", ec.message(),
                    ec.value());
    }
    socket_.close();
    return std::nullopt;
  }

  recv_buffer.resize(length);
  std::vector<std::uint8_t> decrypted_data(length);
  decrypt(recv_buffer, decrypted_data);

  // Append the decrypted data to the end of the input argument data
  data.insert(data.end(), decrypted_data.begin(), decrypted_data.end());

  return static_cast<std::uint32_t>(length);
}

/**
 * @brief Encrypts the data and send it to the connected server.
 * @param data vector containing the to-be-encrypted data to send.
 * @return true on successful send, false otherwise.
 */
bool ConnectionBase::encrypt_and_send(const std::vector<std::uint8_t> &data) {
  spdlog::trace("Packet 0x{:04X}. Num bytes sent: {}", (data[0] | data[1] << 8),
                data.size());
  std::vector<std::uint8_t> encrypted_data(data.size());
  if (encrypt(data, encrypted_data) != PSA_SUCCESS) {
    // Handle the encryption failure as needed
    return false;
  }
  return send(encrypted_data);
}

/**
 * @brief Checks if the connection is open.
 * @return true if the connection is open, false otherwise.
 */
bool ConnectionBase::is_connected() { return socket_.is_open(); }

/**
 * @brief Disconnects from the connected server.
 */
bool ConnectionBase::disconnect() {
  if (socket_.is_open()) {
    asio::error_code ec;

    socket_.shutdown(asio::ip::tcp::socket::shutdown_both, ec);
    if (ec) {
      spdlog::debug("Failed to shutdown socket: {}, {}", ec.message(),
                    ec.value());
      return false;
    }

    socket_.close(ec);
    if (ec) {
      spdlog::debug("Failed to close socket: {}, {}", ec.message(), ec.value());
      return false;
    }
  }

  return true;
}

/**
 * @brief Accepts a connection on the given port.
 * @param port Port number to accept connections on.
 * @return true on successful connection, false otherwise.
 *
 * Example usage:
 * @code
 * accept_connection(6112);
 * @endcode
 */
bool ConnectionBase::accept_connection(unsigned short port) {
  asio::ip::tcp::acceptor acceptor(socket_.get_executor());
  asio::error_code ec;
  acceptor.open(asio::ip::tcp::v4(), ec);
  if (ec) {
    spdlog::error("Failed to open acceptor: {}", ec.message());
    return false;
  }

  acceptor.bind(asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port), ec);
  if (ec) {
    spdlog::error("Failed to bind acceptor: {}", ec.message());
    return false;
  }

  acceptor.listen(asio::socket_base::max_listen_connections, ec);
  if (ec) {
    spdlog::error("Failed to listen on acceptor: {}", ec.message());
    return false;
  }

  acceptor.accept(socket_, ec);
  if (ec) {
    spdlog::error("Failed to accept connection: {}", ec.message());
    return false;
  }

  return true;
}

/**
 * @brief Connects to a given host and port.
 * @param host Hostname or IP address of the server to connect to.
 * @param port Port number to connect to.
 * @return true on successful connection, false otherwise.
 *
 * Example usage:
 * @code
 * connect("Auth1.ArenaNetworks.com", "6112");
 * @endcode
 */
bool ConnectionBase::connect(const std::string &host, const std::string &port) {
  asio::error_code ec;
  const asio::ip::basic_resolver_results<asio::ip::tcp> endpoints =
      resolver_.resolve(host, port, ec);

  if (ec) {
    spdlog::error("Failed to resolve host: {}", host);
    return false;
  }

  asio::connect(socket_, endpoints, ec);
  if (ec || !socket_.is_open()) {
    spdlog::error("Failed to connect to {}:{}", host, port);
    return false;
  }

  return true;
}

std::optional<std::string> ConnectionBase::get_local_endpoint_address() const {
  if (socket_.is_open()) {
    if (std::string local_endpoint =
            socket_.local_endpoint().address().to_string();
        local_endpoint.size() > 0) {
      return local_endpoint;
    }
  }

  return std::nullopt;
}

std::optional<std::string> ConnectionBase::get_remote_endpoint_address() const {
  if (socket_.is_open()) {
    if (std::string remote_endpoint =
            socket_.remote_endpoint().address().to_string();
        remote_endpoint.size() > 0) {
      return remote_endpoint;
    }
  }

  return std::nullopt;
}

/**
 * @brief Sends data to the connected server.
 * @param data Vector containing the data to send.
 * @return true on successful send, false otherwise.
 */
bool ConnectionBase::send(const std::vector<std::uint8_t> &data) {
  if (!socket_.is_open()) {
    spdlog::error("Cannot send, socket is closed");
    return false;
  }

  asio::error_code ec;
  const auto num_bytes_written = write(socket_, asio::buffer(data), ec);
  if (ec) {
    spdlog::error("Failed to send data: {}", ec.message());
    return false;
  }

  return true;
}

/**
 * @brief Performs a Diffie-Hellman key exchange, computes the shared secret,
 * and sets up the ARC4 context used for encryption and decryption.
 *
 * This function initiates a Diffie-Hellman key exchange with the server using
 * given parameters, computes the client's public and private keys, and
 * calculates the shared secret. It also prepares the ARC4 key for further
 * cipher operations.
 *
 * @return true on successful key exchange and ARC4 setup, false otherwise
 * (e.g., if the computation fails).
 */
bool ConnectionBase::do_key_exchange(
    const DiffieHellmanKey &dhm_key,
    const std::array<std::uint8_t, 64> &private_key) {
  mbedtls_mpi mpi_private_key, mpi_public_key, mpi_shared_secret,
      mpi_public_key_precomputed;

  mbedtls_mpi_init(&mpi_private_key);
  mbedtls_mpi_init(&mpi_public_key);
  mbedtls_mpi_init(&mpi_shared_secret);
  mbedtls_mpi_init(&mpi_public_key_precomputed);

  mbedtls_mpi prime_modulus = dhm_key.get_prime_modulus();
  mbedtls_mpi primitive_root = dhm_key.get_primitive_root();

  // Set the private key from the given 64-byte array
  mbedtls_mpi_read_binary(&mpi_private_key, private_key.data(), 64);

  // Compute server's public key: g^y mod p
  mbedtls_mpi_exp_mod(&mpi_public_key, &primitive_root, &mpi_private_key,
                      &prime_modulus, nullptr);

  // Receive client's public key
  msg_client_seed client_seed;
  try {
    const auto num_read_bytes =
        socket_.read_some(asio::buffer(&client_seed, sizeof(client_seed)));
    spdlog::debug("Key exchange, received {} bytes from client.",
                  num_read_bytes);
  } catch (const std::exception &e) {
    spdlog::error("Error reading client seed: {}", e.what());
    return false;
  }

  // Convert received client public key to MPI
  mbedtls_mpi client_public;
  mbedtls_mpi_init(&client_public);
  mbedtls_mpi_read_binary(&client_public, client_seed.seed.data() + 2, 64);

  // Compute shared secret: (g^x)^y mod p
  mbedtls_mpi_exp_mod(&mpi_shared_secret, &client_public, &mpi_private_key,
                      &prime_modulus, nullptr);

  if (mpi_shared_secret.n == 0 || mpi_public_key.n == 0) {
    spdlog::error("Diffie-Hellman computation failed (empty).");
    return false;
  }

  // Generate 20 random bytes for server seed
  msg_server_seed server_seed{1, 22};
  mbedtls_ctr_drbg_random(&ctr_drbg_, server_seed.seed.data(), 20);

  const auto num_bytes_written =
      write(socket_, asio::buffer(&server_seed, sizeof(server_seed)));
  if (num_bytes_written < sizeof(server_seed)) {
    spdlog::error("Failed to send server seed. Number of bytes written: {}",
                  num_bytes_written);
    return false;
  }

  // XOR the first 20 bytes of the shared secret with the server seed
  auto *const shared_bytes =
      reinterpret_cast<std::uint8_t *>(mpi_shared_secret.p);
  std::span<std::uint8_t, 20> shared_bytes_span(shared_bytes, 20);
  for (std::uint8_t i = 0; i < 20; i++) {
    server_seed.seed[i] ^= shared_bytes_span[i];
  }

  // Set up ARC4 contexts
  std::uint8_t arc4_key[20];
  arc4_hash(server_seed.seed.data(), arc4_key);
  mbedtls_arc4_setup(&arc4_encrypt_context_, arc4_key, 20);
  mbedtls_arc4_setup(&arc4_decrypt_context_, arc4_key, 20);

  // Clean up
  mbedtls_mpi_free(&mpi_private_key);
  mbedtls_mpi_free(&mpi_public_key);
  mbedtls_mpi_free(&mpi_shared_secret);
  mbedtls_mpi_free(&client_public);

  return true;
}

/**
 * @brief Performs an ARC4 cipher operation on the input data.
 *
 * This function encrypts or decrypts the given input data using the ARC4
 * algorithm with the previously configured ARC4 context. The result is stored
 * in the provided output buffer.
 *
 * @param arc4_context The context used by encryption or decryption.
 * Encryption and decryption cannot use the same context or it won't work with
 * the server.
 * @param input A vector of bytes containing the data to be
 * encrypted/decrypted.
 * @param output A vector of bytes to store the resulting encrypted/decrypted
 * data. It must be at least the same size as the input vector.
 *
 * @return PSA_SUCCESS if the cipher operation is successful,
 * PSA_ERROR_BUFFER_TOO_SMALL if the output buffer is too small and
 * PSA_ERROR_GENERIC_ERROR otherwise.
 */
psa_status_t
ConnectionBase::perform_arc4_cipher(mbedtls_arc4_context &arc4_context,
                                    const std::vector<std::uint8_t> &input,
                                    std::vector<std::uint8_t> &output) {
  if (output.size() < input.size()) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }

  if (mbedtls_arc4_crypt(&arc4_context, input.size(), input.data(),
                         output.data()) != 0) {
    return PSA_ERROR_GENERIC_ERROR;
  }

  return PSA_SUCCESS;
}

/**
 * @brief Encrypt a message using the ARC4 symmetric cipher.
 *
 * This function encrypts a given plaintext using ARC4 with the internally
 * managed key.
 *
 * @param[in] input         Vector containing the message to encrypt.
 * @param[out] output       Vector where the ciphertext is to be written.
 * @return psa_status_t     PSA_SUCCESS on successful encryption, error code
 * otherwise.
 */
psa_status_t ConnectionBase::encrypt(const std::vector<std::uint8_t> &input,
                                     std::vector<std::uint8_t> &output) {
  return perform_arc4_cipher(arc4_encrypt_context_, input, output);
}

/**
 * @brief Decrypt a message using the ARC4 symmetric cipher.
 *
 * This function decrypts a given ciphertext using ARC4 with the internally
 * managed key.
 *
 * @param[in] input         Vector containing the message to decrypt.
 * @param[out] output       Vector where the plaintext is to be written.
 * @return psa_status_t     PSA_SUCCESS on successful decryption, error code
 * otherwise.
 */
psa_status_t ConnectionBase::decrypt(const std::vector<std::uint8_t> &input,
                                     std::vector<std::uint8_t> &output) {
  return perform_arc4_cipher(arc4_decrypt_context_, input, output);
}

/**
 * @brief Computes a hash using a custom ARC4-based algorithm. Used anytime
 * connecting to a new auth or game server.
 *
 * This function performs a specialized hash computation on the input key
 * using an algorithm that includes a series of bitwise operations and
 * rotations. The resultant digest is stored in the output parameter.
 *
 * @param key Pointer to an array of 20 bytes (std::uint8_t) containing the
 * input key to be hashed.
 * @param digest Pointer to an array of 20 bytes (std::uint8_t) where the
 * computed hash will be stored.
 */
void ConnectionBase::arc4_hash(const std::uint8_t *key, std::uint8_t *digest) {
  using u20 = union u20 {
    std::array<std::uint8_t, 20> u8;
    std::array<std::uint32_t, 5> u32;
  };

  std::uint32_t a = 0x67452301;
  std::uint32_t b = 0xEFCDAB89;
  std::uint32_t c = 0x98BADCFE;
  std::uint32_t d = 0x10325476;
  std::uint32_t e = 0xC3D2E1F0;

  const auto output = reinterpret_cast<u20 *>(digest);
  const auto input = reinterpret_cast<const u20 *>(key);

  std::uint32_t f = (d ^ (b & (c ^ d)));
  e += input->u32.at(0) + ROL32(a, 5) + f + 0x5A827999;
  b = ROL32(b, 30);

  f = (c ^ (a & (b ^ c)));
  d += input->u32.at(1) + ROL32(e, 5) + f + 0x5A827999;
  a = ROL32(a, 30);

  f = (b ^ (e & (a ^ b)));
  c += input->u32.at(2) + ROL32(d, 5) + f + 0x5A827999;
  e = ROL32(e, 30);

  f = (b ^ c ^ d);
  e += input->u32.at(3) + ROL32(a, 5) + f + 0x6ED9EBA1;
  b = ROL32(b, 30);

  f = (a ^ b ^ c);
  d += input->u32.at(4) + ROL32(e, 5) + f + 0x6ED9EBA1;
  a = ROL32(a, 30);

  output->u32.at(0) = input->u32.at(0) + a;
  output->u32.at(1) = input->u32.at(1) + b;
  output->u32.at(2) = input->u32.at(2) + c;
  output->u32.at(3) = input->u32.at(3) + d;
  output->u32.at(4) = input->u32.at(4) + e;
}

ConnectionBase::~ConnectionBase() {
  mbedtls_arc4_free(&arc4_encrypt_context_);
  mbedtls_arc4_free(&arc4_decrypt_context_);
  mbedtls_ctr_drbg_free(&ctr_drbg_);
  mbedtls_entropy_free(&entropy_);
  resolver_.cancel();
  socket_.close();
}

} // namespace utopia::common
