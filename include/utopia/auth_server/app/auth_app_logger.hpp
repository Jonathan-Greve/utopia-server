#pragma once

#include "utopia/auth_server/app/auth_app_context.hpp"
#include "utopia/common/sml/logging/get_last_2_parts.hpp"
#include "utopia/common/sml/logging/state_transition_log_entry.hpp"

#include <boost/sml.hpp>

namespace sml = boost::sml;

namespace utopia::auth::app {

struct AuthAppLogger {
  AuthAppLogger(AuthAppContext &context) : context(context) {}

  template <class SM, class TEvent>
  inline void log_process_event(const TEvent &) {
    // LogEntry entry;
    // entry.type = "event";
    // entry.name = sml::aux::get_type_name<SM>();
    // entry.event = sml::aux::get_type_name<TEvent>();

    // context.log.push_back(entry);
  }

  template <class SM, class TGuard, class TEvent>
  inline void log_guard(const TGuard &, const TEvent &, bool result) {
    // LogEntry entry;
    // entry.type = "guard";
    // entry.name = sml::aux::get_type_name<TGuard>();
    // entry.event = sml::aux::get_type_name<TEvent>();
    // entry.result = result ? "OK" : "Reject";

    // context.log.push_back(entry);
  }

  template <class SM, class TAction, class TEvent>
  inline void log_action(const TAction &, const TEvent &) {
    // LogEntry entry;
    // entry.type = "action";
    // entry.name = sml::aux::get_type_name<TAction>();
    // entry.event = sml::aux::get_type_name<TEvent>();

    // context.log.push_back(entry);
  }

  template <class SM, class TSrcState, class TDstState>
  inline void log_state_change(const TSrcState &src, const TDstState &dst) {
    using namespace utopia::common;
    StateTransitionLogEntry entry;
    entry.src_state = get_last_two_parts(sml::aux::get_type_name<TSrcState>());
    entry.dst_state = get_last_two_parts(sml::aux::get_type_name<TDstState>());
    entry.timestamp = std::chrono::system_clock::now();

    context.state_log.push_back(entry);
  }

private:
  AuthAppContext &context;
};
} // namespace utopia::auth::app
