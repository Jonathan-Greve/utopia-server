#pragma once

namespace utopia::portal::app {

// All events in the state machine needs and id in order for the
// make_dispatch_table to compile.
struct AppEvents {
  struct Start {};
  struct Stop {};
  struct Tick {};
};

} // namespace utopia::portal::app
