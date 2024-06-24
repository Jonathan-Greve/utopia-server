#include "utopia/portal_server/client_connection/packets/tls/tls_server_finished_packet.hpp"

#include "utopia/common/network/endian/endian.hpp"

#include <spdlog/spdlog.h>

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

TlsServerFinishedPacket::TlsServerFinishedPacket(std::vector<uint8_t> &data) {
  if (data.size() < 69) {
    spdlog::trace("Invalid TLS server key exchange packet size: {}",
                  data.size());
    return;
  }

  type = data[0];
  if (type != 0x16) {

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

  std::copy(data.begin() + 5, data.begin() + 21, iv_enc.begin());

  std::copy(data.begin() + 21, data.begin() + 69, encrypted_msg.begin());

  is_valid_ = true;
}

std::uint32_t TlsServerFinishedPacket::get_packet_size() const noexcept {
  return 69;
}

std::vector<uint8_t> TlsServerFinishedPacket::serialize() {
  // Preallocate the vector with the exact size needed
  std::vector<uint8_t> packet(69);

  size = static_cast<std::uint32_t>(packet.size()) - 5;

  // Assign values directly using hardcoded indexes
  packet.at(0) = type;
  utopia::common::be16_enc(&packet.at(1), tls_version);
  utopia::common::be16_enc(&packet.at(3), size);
  std::copy(iv_enc.begin(), iv_enc.end(), packet.begin() + 5);
  std::copy(encrypted_msg.begin(), encrypted_msg.end(), packet.begin() + 21);

  return packet;
}

} // namespace utopia::portal::client_connection
