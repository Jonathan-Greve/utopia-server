#pragma once

#include "utopia/portal_server/client_connection/packets/tls/tls_client_hello_packet.hpp"

#include "utopia/common/network/endian/endian.hpp"

#include <spdlog/spdlog.h>

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

TlsClientHelloPacket::TlsClientHelloPacket(std::vector<uint8_t> &data) {
  type = data[0];
  if (type != 0x16) {
    spdlog::trace("Invalid TLS packet type: {}", type);
    return;
  }

  tls_version = utopia::common::be16_dec(data.data() + 1);
  if (tls_version != 0x0303) {
    spdlog::trace("Invalid TLS version: {}", tls_version);
    return;
  }

  size = utopia::common::be16_dec(data.data() + 3);
  if (size != data.size() - 5) {
    spdlog::trace("Invalid TLS packet size: {}", size);
    return;
  }

  msg_type = data[5];
  if (msg_type != 1) {
    spdlog::trace("Invalid TLS message type: {}", msg_type);
    return;
  }

  std::copy(data.begin() + 6, data.begin() + 9, msg_length.begin());
  client_version = utopia::common::be16_dec(data.data() + 9);
  if (client_version != 0x0303) {
    spdlog::trace("Invalid TLS client version: {}", client_version);
    return;
  }

  std::copy(data.begin() + 11, data.begin() + 43, random.begin());
  session_id = data[43];
  if (session_id != 0) {
    spdlog::trace("Invalid TLS session id: {}", session_id);
    return;
  }

  num_cipher_bytes = utopia::common::be16_dec(data.data() + 44);
  if (num_cipher_bytes != 12) {
    spdlog::trace("Invalid TLS cipher suites length: {}", num_cipher_bytes);
    return;
  }

  for (int i = 0; i < 6; ++i) {
    cipher_suites[i] = utopia::common::be16_dec(data.data() + 46 + i * 2);
  }
  if (cipher_suites[0] != 0xC020 || cipher_suites[1] != 0xC01D ||
      cipher_suites[2] != 0xFF02 || cipher_suites[3] != 0xFF01 ||
      cipher_suites[4] != 0xFF04 || cipher_suites[5] != 0xFF03) {
    spdlog::trace("Invalid TLS cipher suites");
    return;
  }

  compression_methods[0] = data[58];
  compression_methods[1] = data[59];
  if (compression_methods[0] != 1 || compression_methods[1] != 0) {
    spdlog::trace("Invalid TLS compression methods");
    return;
  }

  extensions_length = utopia::common::be16_dec(data.data() + 60);
  extension0_type = utopia::common::be16_dec(data.data() + 62);
  extension0_length = utopia::common::be16_dec(data.data() + 64);
  if (extension0_type != 0xADAE) {
    spdlog::trace("Invalid TLS extension type: {}", extension0_type);
    return;
  }
  if (extension0_length != 0) {
    spdlog::trace("Invalid TLS extension length: {}", extension0_length);
    return;
  }

  extension_srp_type = utopia::common::be16_dec(data.data() + 66);
  if (extension_srp_type != 0x000c) {
    spdlog::trace("Invalid TLS SRP extension type: {}", extension_srp_type);
    return;
  }

  extension_srp_length = utopia::common::be16_dec(data.data() + 68);
  if (extension_srp_length + 70 != data.size()) {
    spdlog::trace("Invalid TLS SRP extension length: {}", extension_srp_length);
    return;
  }

  extension_srp_data_length = data[70];
  if (extension_srp_data_length != extension_srp_length - 1) {
    spdlog::trace("Invalid TLS SRP extension data length: {}",
                  extension_srp_data_length);
  }

  if (data.size() < 71 + extension_srp_data_length) {
    spdlog::trace(
        "Data size is too small for the specified SRP extension data length");
    return;
  }

  extension_srp_data.assign(data.begin() + 71,
                            data.begin() + 71 + extension_srp_data_length);

  is_valid_ = true;
}

std::uint32_t TlsClientHelloPacket::get_packet_size() const noexcept {
  return 71 + static_cast<std::uint32_t>(extension_srp_data.size());
}

std::vector<uint8_t> TlsClientHelloPacket::serialize() {
  // Preallocate the vector with the exact size needed
  std::vector<uint8_t> packet(71 + extension_srp_data.size());

  // Update data members that are not hardcoded
  extension_srp_length =
      static_cast<std::uint32_t>(extension_srp_data.size()) + 1;
  extension_srp_data_length =
      static_cast<std::uint32_t>(extension_srp_data.size());
  extensions_length = extension_srp_data_length + 9;
  size = static_cast<std::uint32_t>(packet.size()) - 5;

  // The msg_length will never need 24 bytes. So we can just use be16_enc on the
  // last 2 bytes.
  utopia::common::be16_enc(&msg_length[1], size - 4);

  // Assign values directly using hardcoded indexes
  packet.at(0) = type;
  utopia::common::be16_enc(&packet.at(1), tls_version);
  utopia::common::be16_enc(&packet.at(3), size);
  packet.at(5) = msg_type;

  std::copy(msg_length.begin(), msg_length.end(), packet.begin() + 6);

  utopia::common::be16_enc(&packet.at(9), client_version);

  std::copy(random.begin(), random.end(), packet.begin() + 11);

  packet.at(43) = session_id;

  utopia::common::be16_enc(&packet.at(44), num_cipher_bytes);

  for (int i = 0; i < 6; ++i) {
    utopia::common::be16_enc(&packet.at(46 + i * 2), cipher_suites[i]);
  }

  packet.at(58) = compression_methods[0];
  packet.at(59) = compression_methods[1];

  utopia::common::be16_enc(&packet.at(60), extensions_length);
  utopia::common::be16_enc(&packet.at(62), extension0_type);
  utopia::common::be16_enc(&packet.at(64), extension0_length);
  utopia::common::be16_enc(&packet.at(66), extension_srp_type);

  utopia::common::be16_enc(&packet.at(68), extension_srp_length);

  packet.at(70) = extension_srp_data_length;

  std::copy(extension_srp_data.begin(), extension_srp_data.end(),
            packet.begin() + 71);

  return packet;
}

} // namespace utopia::portal::client_connection
