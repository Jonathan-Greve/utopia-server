#pragma once

#include <cstdint>

namespace argparse {
class ArgumentParser;
}

namespace asio {
class io_context;
}

namespace utopia::portal::app {

class App {
public:
  App() = delete;
  App(const argparse::ArgumentParser &arg_parser) noexcept;

  App(const App &) = delete;
  App &operator=(const App &) = delete;

  ~App();

  void run() noexcept;

private:
  const std::uint32_t port_;
};

} // namespace utopia::portal::app
