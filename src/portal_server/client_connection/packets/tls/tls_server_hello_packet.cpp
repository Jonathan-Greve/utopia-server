#include "utopia/portal_server/client_connection/packets/tls/tls_server_hello_packet.hpp"

#include "utopia/common/network/endian/endian.hpp"

#include <spdlog/spdlog.h>

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

TlsServerHelloPacket::TlsServerHelloPacket(std::vector<uint8_t> &data) {
  if (data.size() < 53) {
    spdlog::trace("Invalid TLS packet size: {}", data.size());
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
  if (msg_type != 2) {
    spdlog::trace("Invalid TLS message type: {}", msg_type);
    return;
  }

  std::copy(data.begin() + 6, data.begin() + 9, msg_length.begin());
  server_version = utopia::common::be16_dec(data.data() + 9);
  if (server_version != 0x0303) {
    spdlog::trace("Invalid TLS client version: {}", server_version);
    return;
  }

  std::copy(data.begin() + 11, data.begin() + 43, random.begin());
  session_id = data[43];
  if (session_id != 0) {
    spdlog::trace("Invalid TLS session id: {}", session_id);
    return;
  }

  cipher_suite = utopia::common::be16_dec(data.data() + 44);
  if (cipher_suite != 0xFF04) {
    spdlog::trace("Invalid TLS cipher suite: {}", cipher_suite);
    return;
  }

  compression_method = data[46];
  if (compression_method != 0) {
    spdlog::trace("Invalid TLS compression method.");
    return;
  }

  extensions_length = utopia::common::be16_dec(data.data() + 47);
  extension0_type = utopia::common::be16_dec(data.data() + 49);
  extension0_length = utopia::common::be16_dec(data.data() + 51);
  if (extension0_type != 0xADAE) {
    spdlog::trace("Invalid TLS extension type: {}", extension0_type);
    return;
  }
  if (extension0_length != 0) {
    spdlog::trace("Invalid TLS extension length: {}", extension0_length);
    return;
  }

  is_valid_ = true;
}

std::uint32_t TlsServerHelloPacket::get_packet_size() const noexcept {
  return 53;
}

std::vector<uint8_t> TlsServerHelloPacket::serialize() {
  // Preallocate the vector with the exact size needed
  std::vector<uint8_t> packet(53);

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

  utopia::common::be16_enc(&packet.at(9), server_version);

  std::copy(random.begin(), random.end(), packet.begin() + 11);

  packet.at(43) = session_id;

  utopia::common::be16_enc(&packet.at(44), cipher_suite);

  packet.at(46) = compression_method;

  utopia::common::be16_enc(&packet.at(47), extensions_length);
  utopia::common::be16_enc(&packet.at(49), extension0_type);
  utopia::common::be16_enc(&packet.at(51), extension0_length);

  return packet;
}

} // namespace utopia::portal::client_connection
