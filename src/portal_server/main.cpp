#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/app/portal_app.hpp"

#include <argparse/argparse.hpp>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include <cstdint>
#include <exception>
#include <optional>
#include <string>

static std::optional<std::string>
parse_arguments(argparse::ArgumentParser &arg_parser, const int argc,
                char *const argv[]) noexcept {
  arg_parser.add_argument("--log-level")
      .help("Set output verbosity level (trace, debug, info, warn, error, "
            "critical, off)")
      .default_value(std::string{"debug"});

  constexpr std::uint32_t default_port = 6112;
  arg_parser.add_argument("--port")
      .help("Port to connect to")
      .default_value(default_port);

  arg_parser.add_argument("--auth_port")
      .help("Auth server port that the portal server will connect to.")
      .default_value(default_port + 1);
  arg_parser.add_argument("--auth-host")
      .help("Auth server hostname that the portal server will connect to.")
      .default_value(std::string{"localhost"});

  try {
    arg_parser.parse_args(argc, argv);
    return std::nullopt;
  } catch (const std::exception &err) {
    return std::string{err.what()};
  }
}

static void set_log_level(const argparse::ArgumentParser &arg_parser) noexcept {
  if (arg_parser.is_used("--log-level")) {
    auto log_level = arg_parser.get<std::string>("--log-level");

    if (log_level == "trace") {
      spdlog::set_level(spdlog::level::trace);
    } else if (log_level == "debug") {
      spdlog::set_level(spdlog::level::debug);
    } else if (log_level == "info") {
      spdlog::set_level(spdlog::level::info);
    } else if (log_level == "warn") {
      spdlog::set_level(spdlog::level::warn);
    } else if (log_level == "error") {
      spdlog::set_level(spdlog::level::err);
    } else if (log_level == "critical") {
      spdlog::set_level(spdlog::level::critical);
    } else if (log_level == "off") {
      spdlog::set_level(spdlog::level::off);
    } else {
      spdlog::warn("Invalid log level: {}. Using default level (info).",
                   log_level);
      spdlog::set_level(spdlog::level::info);
    }
  } else {
    spdlog::set_level(spdlog::level::info);
  }

  spdlog::info("Log level set to: {}.",
               spdlog::level::to_string_view(spdlog::get_level()));
}

int main(int argc, char *argv[]) {
  // auto file_sink =
  //     std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/log.log",
  //     true);

  // // Set the default logger to use the file sink
  // spdlog::set_default_logger(
  //     std::make_shared<spdlog::logger>("default_logger", file_sink));

  // spdlog::flush_every(std::chrono::seconds(1));

  argparse::ArgumentParser arg_parser("Utopia Client");
  auto parse_result = parse_arguments(arg_parser, argc, argv);
  if (parse_result.has_value()) {
    spdlog::error("Error parsing arguments: {}", parse_result.value());
    spdlog::error(arg_parser.help().str());
    std::exit(1);
  }
  spdlog::debug("Arguments parsed.");

  set_log_level(arg_parser);

  spdlog::info("Starting the login portal app.");
  utopia::portal::app::PortalApp app(arg_parser);
  app.run();

  spdlog::info("Exiting the program.");
  return 0;
}
