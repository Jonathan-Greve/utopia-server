#pragma once

#include "utopia/portal_server/app/app_context.hpp"

#include <cstdint>

namespace argparse {
class ArgumentParser;
}

namespace asio {
class io_context;
}

namespace utopia::common {
class DiffieHellmanKey;
}

namespace utopia::portal::app {

class App {
public:
  App() = delete;
  App(const argparse::ArgumentParser &arg_parser,
      const common::DiffieHellmanKey &diffie_hellman_key) noexcept;

  App(const App &) = delete;
  App &operator=(const App &) = delete;

  ~App();

  void run() noexcept;

private:
  std::uint32_t port_;
  const std::uint32_t game_version_;
  const std::string key_path_;
  const std::string auth_host_;
  const std::uint32_t auth_port_;

  const common::DiffieHellmanKey &diffie_hellman_key_;
};

} // namespace utopia::portal::app
