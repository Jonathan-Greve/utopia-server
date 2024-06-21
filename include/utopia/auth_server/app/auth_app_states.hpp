#pragma once

namespace utopia::auth::app {

struct AuthAppStates {
  struct Initializing {};
  struct Running {};
  struct Stopping {};
};

} // namespace utopia::auth::app
