#pragma once

#include "utopia/auth_server/client_connection/auth_client_connection_context.hpp"
#include "utopia/auth_server/client_connection/auth_client_connection_logger.hpp"
#include "utopia/auth_server/client_connection/events/auth_client_connection_event.hpp"
#include "utopia/common/network/connection_base.hpp"

#include <asio.hpp>
#include <boost/sml.hpp>
#include <concurrentqueue.h>

#include <memory>

namespace sml = boost::sml;

namespace utopia::auth::client_connection {

struct AuthClientConnectionStateMachine;

class AuthClientConnection : public common::ConnectionBase {
public:
  AuthClientConnection(asio::io_context &io_context, std::uint32_t port);
  void run(const std::uint32_t game_version,
           const common::DiffieHellmanKey &diffie_hellman_key,
           const std::array<std::uint8_t, 64> private_key);

  void process_event(const AuthClientPacket &packet) noexcept;

private:
  asio::io_context &io_context_;

  moodycamel::ConcurrentQueue<AuthClientConnectionEvent> event_queue_;
  AuthClientConnectionContext client_connection_sm_context_;
  AuthClientConnectionLogger client_connection_logger_;
  std::unique_ptr<sml::sm<AuthClientConnectionStateMachine,
                          sml::logger<AuthClientConnectionLogger>>>
      client_connection_sm_;

  std::vector<std::uint8_t> auth_client_recv_buf_;

  void process_event_queue();
};

} // namespace utopia::auth::client_connection
