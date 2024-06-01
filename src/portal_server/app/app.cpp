#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/app/app.hpp"

#include "utopia/portal_server/app/app_context.hpp"
#include "utopia/portal_server/app/app_logger.hpp"
#include "utopia/portal_server/app/app_state_machine.hpp"
#include "utopia/portal_server/app/events/app_event.hpp"

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

App::App(const argparse::ArgumentParser &arg_parser) noexcept
    : port_(arg_parser.get<std::uint32_t>("--port")) {
  spdlog::info("Port: {}.", port_);

  std::signal(SIGINT, sig_int_handler);
}

void App::run() noexcept {
  using namespace sml;

  auto event_queue = std::make_unique<moodycamel::ConcurrentQueue<AppEvent>>();

  asio::io_context io;

  AppContext app_sm_context;

  AppLogger app_logger{app_sm_context};

  sm<AppStateMachine, logger<AppLogger>> app_sm{
      io, app_logger, event_queue.get(), app_sm_context};

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
      app_sm.process_event(AppEvents::Stop{});
    }

    AppEvent event;
    while (event_queue->try_dequeue(event)) {
      std::visit(process_event_in_queue, event);
    }

    app_sm.process_event(AppEvents::Tick{});
  }

  io.stop();
  for (auto &thread : threads) {
    thread.join();
  }

  spdlog::debug("The app has stopped.");
}

App::~App() = default;

} // namespace utopia::portal::app
