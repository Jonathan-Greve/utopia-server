#pragma once

#include "utopia/portal_server/app/portal_app_context.hpp"

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

class PortalApp {
public:
  PortalApp() = delete;
  PortalApp(const argparse::ArgumentParser &arg_parser) noexcept;

  PortalApp(const PortalApp &) = delete;
  PortalApp &operator=(const PortalApp &) = delete;

  ~PortalApp();

  void run() noexcept;

private:
  std::uint32_t port_;
  const std::string auth_host_;
  const std::uint32_t auth_port_;
};

} // namespace utopia::portal::app
