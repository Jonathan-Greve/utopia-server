#include "utopia/utopia_pch.hpp"

#include "utopia/auth_server/app/auth_app.hpp"

#include "utopia/auth_server/app/auth_app_context.hpp"
#include "utopia/auth_server/app/auth_app_logger.hpp"
#include "utopia/auth_server/app/auth_app_state_machine.hpp"
#include "utopia/auth_server/app/events/auth_app_event.hpp"
#include "utopia/common/network/connection_manager.hpp"
#include "utopia/common/network/diffie_hellman_key.hpp"

#include <argparse/argparse.hpp>
#include <asio.hpp>
#include <boost/sml.hpp>
#include <concurrentqueue.h>
#include <spdlog/spdlog.h>

#include <chrono>
#include <csignal>
#include <cstdint>
#include <string>
#include <thread>
#include <variant>
#include <vector>

namespace sml = boost::sml;

namespace utopia::auth::app {

volatile bool sigint_received = false;

// Signal handler function
void sig_int_handler(int signal) { sigint_received = true; }

AuthApp::AuthApp(const argparse::ArgumentParser &arg_parser,
                 const common::DiffieHellmanKey &diffie_hellman_key) noexcept
    : port_(arg_parser.get<std::uint32_t>("--port")),
      game_version_(arg_parser.get<std::uint32_t>("--game-version")),
      key_path_(arg_parser.get<std::string>("--key-path")),
      diffie_hellman_key_(diffie_hellman_key) {
  spdlog::info("Game version: {}.", game_version_);
  spdlog::info("Key path: \"{}\".", key_path_);
  spdlog::info("Port: {}.", port_);

  std::signal(SIGINT, sig_int_handler);
}

void AuthApp::run() noexcept {
  using namespace sml;

  auto event_queue =
      std::make_unique<moodycamel::ConcurrentQueue<AuthAppEvent>>();

  asio::io_context io;

  AuthAppContext app_sm_context{.port = port_};

  AuthAppLogger app_logger{app_sm_context};

  common::ConnectionManager connection_manager{io};

  sm<AuthAppStateMachine, logger<AuthAppLogger>> app_sm{
      io, app_logger, event_queue.get(), app_sm_context, connection_manager};

  spdlog::trace("Running the login Auth app.");
  // Create a work guard to prevent the io_context from running out of work
  asio::executor_work_guard<asio::io_context::executor_type> work_guard(
      io.get_executor());

  // Thread pool for doing work
  std::vector<std::thread> threads;
  for (std::size_t i = 0; i < std::thread::hardware_concurrency(); ++i) {
    threads.emplace_back([&]() { io.run(); });
  }

  // Process an event in the event_queue
  auto process_event_in_queue = [&](auto &&x) { app_sm.process_event(x); };

  while (!app_sm.is(X)) {
    if (sigint_received) {
      app_sm.process_event(AuthAppEvents::Stop{});
    }

    AuthAppEvent event;
    while (event_queue->try_dequeue(event)) {
      std::visit(process_event_in_queue, event);
    }

    app_sm.process_event(AuthAppEvents::Tick{});

    // Remove all connections that are not connected
    const auto &connections = connection_manager.get_all_connections();
    for (auto *connection : connections) {
      assert(connection != nullptr);
      if (!connection->is_connected()) {
        connection_manager.remove_connection(connection);
        spdlog::debug("Removed a connection that was not connected.");
      }
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  io.stop();
  for (auto &thread : threads) {
    thread.join();
  }

  spdlog::debug("The app has stopped.");
}

AuthApp::~AuthApp() = default;

} // namespace utopia::auth::app
