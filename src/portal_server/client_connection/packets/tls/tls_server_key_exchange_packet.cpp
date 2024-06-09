#pragma once

#include "utopia/portal_server/client_connection/packets/tls/tls_server_key_exchange_packet.hpp"

#include "utopia/common/network/endian/endian.hpp"

#include <spdlog/spdlog.h>

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

TlsServerKeyExchangePacket::TlsServerKeyExchangePacket(
    std::vector<uint8_t> &data) {
  if (data.size() != 281) {
    spdlog::trace("Invalid TLS server key exchange packet size: {}",
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
  if (size != data.size() - 5) {
    spdlog::trace("Invalid TLS packet size: {}", size);
    return;
  }

  msg_type = data[5];
  if (msg_type != 12) {
    spdlog::trace("Invalid TLS message type: {}", msg_type);
    return;
  }

  std::copy(data.begin() + 6, data.begin() + 9, msg_length.begin());

  prime_length = utopia::common::be16_dec(data.data() + 9);
  if (prime_length != 128) {
    spdlog::trace("Invalid TLS prime length: {}", prime_length);
    return;
  }

  std::copy(data.begin() + 11, data.begin() + 139, prime.begin());

  generator_length = utopia::common::be16_dec(data.data() + 139);
  if (generator_length != 1) {
    spdlog::trace("Invalid TLS generator length: {}", generator_length);
    return;
  }

  std::copy(data.begin() + 141, data.begin() + 142, generator.begin());

  salt_length = data[142];
  if (salt_length != 8) {
    spdlog::trace("Invalid TLS salt length: {}", salt_length);
    return;
  }

  std::copy(data.begin() + 143, data.begin() + 151, salt.begin());

  server_public_length = utopia::common::be16_dec(data.data() + 151);
  if (server_public_length != 128) {
    spdlog::trace("Invalid TLS server public length: {}", server_public_length);
    return;
  }

  std::copy(data.begin() + 153, data.begin() + 281, server_public.begin());

  is_valid_ = true;
}

std::uint32_t TlsServerKeyExchangePacket::get_packet_size() const noexcept {
  return 281;
}

std::vector<uint8_t> TlsServerKeyExchangePacket::serialize() {
  // Preallocate the vector with the exact size needed
  std::vector<uint8_t> packet(281);

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

  utopia::common::be16_enc(&packet.at(9), prime_length);
  std::copy(prime.begin(), prime.end(), packet.begin() + 11);

  utopia::common::be16_enc(&packet.at(139), generator_length);
  std::copy(generator.begin(), generator.end(), packet.begin() + 141);

  packet.at(142) = salt_length;
  std::copy(salt.begin(), salt.end(), packet.begin() + 143);

  utopia::common::be16_enc(&packet.at(151), server_public_length);
  std::copy(server_public.begin(), server_public.end(), packet.begin() + 153);

  return packet;
}

} // namespace utopia::portal::client_connection
