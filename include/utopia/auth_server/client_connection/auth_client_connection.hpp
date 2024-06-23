#pragma once

#include <asio.hpp>
#include <utopia/common/network/connection_base.hpp>

namespace utopia::auth::client_connection {

class AuthClientConnection : public common::ConnectionBase {
public:
  AuthClientConnection(asio::io_context &io_context, std::uint32_t port);

  void run(const std::uint32_t game_version,
           const common::DiffieHellmanKey &diffie_hellman_key,
           const std::array<std::uint8_t, 64> private_key);

private:
  asio::io_context &io_context_;
};

} // namespace utopia::auth::client_connection
