#pragma once

#include "utopia/portal_server/client_connection/packets/tls/tls_client_key_exchange_packet.hpp"

#include "utopia/common/network/endian/endian.hpp"

#include <spdlog/spdlog.h>

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

TlsClientKeyExchangePacket::TlsClientKeyExchangePacket(
    std::vector<uint8_t> &data) {
  if (data.size() < 139) {
    spdlog::trace("Invalid TLS client key exchange packet size: {}",
                  data.size());
    return;
  }

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
  if (size != get_packet_size() - 5) {
    spdlog::trace("Invalid TLS packet size: {}", size);
    return;
  }

  msg_type = data[5];
  if (msg_type != 16) {
    spdlog::trace("Invalid TLS message type: {}", msg_type);
    return;
  }

  std::copy(data.begin() + 6, data.begin() + 9, msg_length.begin());

  public_key_length = utopia::common::be16_dec(data.data() + 9);
  if (public_key_length != 128) {
    spdlog::trace("Invalid TLS prime length: {}", public_key_length);
    return;
  }

  std::copy(data.begin() + 11, data.begin() + 139, public_key.begin());

  is_valid_ = true;
}

std::uint32_t TlsClientKeyExchangePacket::get_packet_size() const noexcept {
  return 139;
}

std::vector<uint8_t> TlsClientKeyExchangePacket::serialize() {
  // Preallocate the vector with the exact size needed
  std::vector<uint8_t> packet(139);

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

  utopia::common::be16_enc(&packet.at(9), public_key_length);
  std::copy(public_key.begin(), public_key.end(), packet.begin() + 11);

  return packet;
}

} // namespace utopia::portal::client_connection
