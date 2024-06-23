#pragma once

#include "utopia/auth_server/app/auth_app_context.hpp"

#include <cstdint>
#include <string>

namespace argparse {
class ArgumentParser;
}

namespace asio {
class io_context;
}

namespace utopia::common {
class DiffieHellmanKey;
}

namespace utopia::auth::app {

class AuthApp {
public:
  AuthApp() = delete;
  AuthApp(const argparse::ArgumentParser &arg_parser,
          const common::DiffieHellmanKey &diffie_hellman_key,
          const std::array<std::uint8_t, 64> private_key) noexcept;

  AuthApp(const AuthApp &) = delete;
  AuthApp &operator=(const AuthApp &) = delete;

  ~AuthApp();

  void run() noexcept;

private:
  const std::uint32_t port_;
  const std::uint32_t game_version_;

  const common::DiffieHellmanKey &diffie_hellman_key_;
  const std::array<std::uint8_t, 64> private_key_;
};

} // namespace utopia::auth::app
