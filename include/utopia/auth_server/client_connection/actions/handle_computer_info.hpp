#pragma once

#include <spdlog/spdlog.h>

namespace utopia::auth::client_connection {

inline const auto handle_computer_info = []() {
  spdlog::trace("Received computer info from client");
};

} // namespace utopia::auth::client_connection
