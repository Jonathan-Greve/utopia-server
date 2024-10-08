#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/app/portal_app.hpp"

#include "utopia/common/network/connection_manager.hpp"
#include "utopia/portal_server/app/events/portal_app_event.hpp"
#include "utopia/portal_server/app/portal_app_context.hpp"
#include "utopia/portal_server/app/portal_app_logger.hpp"
#include "utopia/portal_server/app/portal_app_state_machine.hpp"

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

namespace utopia::portal::app {

volatile bool sigint_received = false;

// Signal handler function
void sig_int_handler(int signal) { sigint_received = true; }

PortalApp::PortalApp(const argparse::ArgumentParser &arg_parser) noexcept
    : port_(arg_parser.get<std::uint32_t>("--port")),
      auth_host_(arg_parser.get<std::string>("--auth-host")),
      auth_port_(arg_parser.get<std::uint32_t>("--auth_port")) {
  spdlog::info("Port: {}.", port_);
  spdlog::info("Auth host: {}.", auth_host_);
  spdlog::info("Auth port: {}.", auth_port_);

  std::signal(SIGINT, sig_int_handler);
}

void PortalApp::run() noexcept {
  using namespace sml;

  auto event_queue =
      std::make_unique<moodycamel::ConcurrentQueue<PortalAppEvent>>();

  asio::io_context io;

  PortalAppContext app_sm_context{.port = port_};

  PortalAppLogger app_logger{app_sm_context};

  common::ConnectionManager connection_manager{io};

  sm<PortalAppStateMachine, logger<PortalAppLogger>> app_sm{
      io, app_logger, event_queue.get(), app_sm_context, connection_manager};

  spdlog::trace("Running the login portal app.");
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
      app_sm.process_event(PortalAppEvents::Stop{});
    }

    PortalAppEvent event;
    while (event_queue->try_dequeue(event)) {
      std::visit(process_event_in_queue, event);
    }

    app_sm.process_event(PortalAppEvents::Tick{});

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

PortalApp::~PortalApp() = default;

} // namespace utopia::portal::app
