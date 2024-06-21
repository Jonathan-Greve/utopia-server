#pragma once

namespace utopia::auth::app {

struct AuthAppEvents {
  struct Start {};
  struct Stop {};
  struct Tick {};
};

} // namespace utopia::auth::app
