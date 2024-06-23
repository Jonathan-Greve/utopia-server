#include "utopia/utopia_pch.hpp"

#include "utopia/auth_server/client_connection/events/dispatch_auth_client_packet.hpp"

#include "utopia/auth_server/client_connection/auth_client_connection.hpp"
#include "utopia/auth_server/client_connection/events/auth_client_connection_event.hpp"
#include "utopia/common/network/packets/packet_reader.hpp"
#include "utopia/common/sml/events/create_variant.hpp"

#include <spdlog/spdlog.h>

#include <cstdint>
#include <variant>
#include <vector>

namespace utopia::auth::client_connection {

void dispatch_auth_client_packet(AuthClientConnection *client_connection,
                                 std::vector<std::uint8_t> &recv_buf) {
  using namespace utopia::common;
  const auto header_id = PacketReader::be16_to_le16(recv_buf.data());
  auto packet = create_variant<AuthClientPacket>(header_id, recv_buf);
  std::visit(
      [&](auto &&x) {
        if (x.packet_valid) {
          client_connection->process_event(packet);
          recv_buf.erase(recv_buf.begin(),
                         recv_buf.begin() + x.get_packet_size());
        }
      },
      packet);
}
} // namespace utopia::auth::client_connection
