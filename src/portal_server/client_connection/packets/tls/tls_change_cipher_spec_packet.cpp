#include "utopia/portal_server/client_connection/packets/tls/tls_change_cipher_spec_packet.hpp"

#include "utopia/common/network/endian/endian.hpp"

#include <spdlog/spdlog.h>

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

TlsChangeCipherSpecPacket::TlsChangeCipherSpecPacket(
    std::vector<uint8_t> &data) {
  if (data.size() < 6) {
    spdlog::trace("Invalid TLS server key exchange packet size: {}",
                  data.size());
    return;
  }

  type = data[0];
  if (type != 0x14) {
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

  payload = data[5];
  if (payload != 1) {
    spdlog::trace("Invalid TLS  Change Cipher Spec payload: {}", payload);
    return;
  }

  is_valid_ = true;
}

std::uint32_t TlsChangeCipherSpecPacket::get_packet_size() const noexcept {
  return 6;
}

std::vector<uint8_t> TlsChangeCipherSpecPacket::serialize() {
  // Preallocate the vector with the exact size needed
  std::vector<uint8_t> packet(6);

  size = static_cast<std::uint32_t>(packet.size()) - 5;

  // Assign values directly using hardcoded indexes
  packet.at(0) = type;
  utopia::common::be16_enc(&packet.at(1), tls_version);
  utopia::common::be16_enc(&packet.at(3), size);
  packet.at(5) = payload;

  return packet;
}

} // namespace utopia::portal::client_connection
