#pragma once

#include "utopia/portal_server/client_connection/packets/tls/tls_server_hello_done_packet.hpp"

#include "utopia/common/network/endian/endian.hpp"

#include <spdlog/spdlog.h>

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

TlsServerHelloDonePacket::TlsServerHelloDonePacket(std::vector<uint8_t> &data) {
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
  if (msg_type != 14) {
    spdlog::trace("Invalid TLS message type: {}", msg_type);
    return;
  }

  std::copy(data.begin() + 6, data.begin() + 9, msg_length.begin());

  is_valid_ = true;
}

std::uint32_t TlsServerHelloDonePacket::get_packet_size() const noexcept {
  return 9;
}

std::vector<uint8_t> TlsServerHelloDonePacket::serialize() {
  // Preallocate the vector with the exact size needed
  std::vector<uint8_t> packet(9);

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

  return packet;
}

} // namespace utopia::portal::client_connection
