#pragma once

#include <cstdint>
#include <vector>

namespace utopia::auth::client_connection {
class AuthClientConnection;

bool dispatch_auth_client_packet(AuthClientConnection *client_connection,
                                 std::vector<std::uint8_t> &recv_buf);

} // namespace utopia::auth::client_connection
