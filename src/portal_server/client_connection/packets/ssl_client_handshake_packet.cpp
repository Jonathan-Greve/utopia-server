#pragma once

#include "utopia/portal_server/client_connection/packets/ssl_client_handshake_packet.hpp"

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

SslClientHandshakePacket::SslClientHandshakePacket(std::vector<uint8_t> &data) {
  type = data[0];
  if (type != 0x16) {
    throw std::invalid_argument("Invalid SSL packet type");
  }

  ssl_version = (data[1] << 8) | data[2];
  if (ssl_version != 0x0303) {
    throw std::invalid_argument("Invalid SSL version");
  }

  size = (data[3] << 8) | data[4];
  if (size != data.size() - 5) {
    throw std::invalid_argument("Invalid SSL packet size");
  }

  msg_type = data[5];
  if (msg_type != 1) {
    throw std::invalid_argument("Invalid SSL message type");
  }

  std::copy(data.begin() + 6, data.begin() + 9, msg_length.begin());
  client_version = (data[9] << 8) | data[10];
  if (client_version != 0x0303) {
    throw std::invalid_argument("Invalid SSL client version");
  }

  std::copy(data.begin() + 11, data.begin() + 43, random.begin());
  session_id = data[43];
  if (session_id != 0) {
    throw std::invalid_argument("Invalid SSL session id");
  }

  for (int i = 0; i < 6; ++i) {
    cipther_suites[i] = (data[44 + i * 2] << 8) | data[45 + i * 2];
  }
  if (cipther_suites[0] != 0xC020 || cipther_suites[1] != 0xC01D ||
      cipther_suites[2] != 0xFF02 || cipther_suites[3] != 0xFF01 ||
      cipther_suites[4] != 0xFF04 || cipther_suites[5] != 0xFF03) {
    throw std::invalid_argument("Invalid SSL cipher suites");
  }

  compression_methods[0] = data[56];
  compression_methods[1] = data[57];
  if (compression_methods[0] != 1 || compression_methods[1] != 0) {
    throw std::invalid_argument("Invalid SSL compression methods");
  }

  extensions_length = (data[58] << 8) | data[59];
  extension0_type = (data[60] << 8) | data[61];
  extension0_length = (data[62] << 8) | data[63];
  if (extension0_type != 0xADAE) {
    throw std::invalid_argument("Invalid SSL extension type");
  }
  if (extension0_length != 0) {
    throw std::invalid_argument("Invalid SSL extension length");
  }

  extension_srp_type = (data[64] << 8) | data[65];
  if (extension_srp_type != 0x000c) {
    throw std::invalid_argument("Invalid SSL SRP extension type");
  }

  extension_srp_length = (data[66] << 8) | data[67];
  if (extension_srp_length + 68 != data.size()) {
    throw std::invalid_argument("Invalid SSL SRP extension length");
  }

  extension_srp_data_length = data[68];
  if (extension_srp_data_length != extension_srp_length - 1) {
    throw std::invalid_argument("Invalid SSL SRP extension data length");
  }

  if (data.size() < 69 + extension_srp_data_length) {
    throw std::invalid_argument(
        "Data size is too small for the specified SRP extension data length");
  }

  extension_srp_data.assign(data.begin() + 69,
                            data.begin() + 69 + extension_srp_data_length);

  is_valid_ = true;
}

std::uint32_t SslClientHandshakePacket::get_packet_size() {
  return 69 + extension_srp_data.size();
}

std::vector<uint8_t> SslClientHandshakePacket::serialize() {
  std::vector<uint8_t> packet;
  packet.push_back(type);
  packet.push_back(ssl_version >> 8);
  packet.push_back(ssl_version & 0xFF);
  packet.push_back(size >> 8);
  packet.push_back(size & 0xFF);
  packet.push_back(msg_type);
  packet.insert(packet.end(), msg_length.begin(), msg_length.end());
  packet.push_back(client_version >> 8);
  packet.push_back(client_version & 0xFF);
  packet.insert(packet.end(), random.begin(), random.end());
  packet.push_back(session_id);
  for (int i = 0; i < 6; ++i) {
    packet.push_back(cipther_suites[i] >> 8);
    packet.push_back(cipther_suites[i] & 0xFF);
  }
  packet.push_back(compression_methods[0]);
  packet.push_back(compression_methods[1]);
  packet.push_back(extensions_length >> 8);
  packet.push_back(extensions_length & 0xFF);
  packet.push_back(extension0_type >> 8);
  packet.push_back(extension0_type & 0xFF);
  packet.push_back(extension0_length >> 8);
  packet.push_back(extension0_length & 0xFF);
  packet.push_back(extension_srp_type >> 8);
  packet.push_back(extension_srp_type & 0xFF);

  extension_srp_length = extension_srp_data.size() + 1;
  extension_srp_data_length = extension_srp_data.size();

  packet.push_back(extension_srp_length >> 8);
  packet.push_back(extension_srp_length & 0xFF);
  packet.push_back(extension_srp_data_length);
  packet.insert(packet.end(), extension_srp_data.begin(),
                extension_srp_data.end());

  return packet;
}

} // namespace utopia::portal::client_connection
