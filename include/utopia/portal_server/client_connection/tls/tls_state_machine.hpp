#pragma once
#include "utopia/portal_server/client_connection/packets/tls/tls_client_hello_packet.hpp"
#include "utopia/portal_server/client_connection/tls/actions/handle_tls_client_hello_packet.hpp"
#include "utopia/portal_server/client_connection/tls/actions/send_tls_server_hello.hpp"
#include "utopia/portal_server/client_connection/tls/actions/send_tls_server_key_exchange.hpp"
#include "utopia/portal_server/client_connection/tls/tls_states.hpp"

#include <boost/sml.hpp>
#include <spdlog/spdlog.h>

namespace sml = boost::sml;

namespace utopia::portal::client_connection {

struct TlsStateMachine {
  auto operator()() const noexcept {
    using namespace sml;
    using namespace utopia::common;
    // clang-format off
    return make_transition_table(
      * state<TlsStates::WaitingOnClientHello> + event<TlsClientHelloPacket> / handle_tls_client_hello_packet = state<TlsStates::ReceivedClientHello>
      , state<TlsStates::WaitingOnClientHello> + event<_> / [](){spdlog::error("Unexpected event in WaitingOnClientHello state.");} = X

      , state<TlsStates::ReceivedClientHello> + on_entry<_> / send_tls_server_hello
      , state<TlsStates::ReceivedClientHello> + event<TlsEvents::SentServerHelloReply> = state<TlsStates::SentServerHelloReply>
      , state<TlsStates::ReceivedClientHello> + event<TlsEvents::UnableToSendPacket> = X

      , state<TlsStates::SentServerHelloReply> + on_entry<_> / send_tls_server_key_exchange
      , state<TlsStates::SentServerHelloReply> + event<TlsEvents::SentServerKeyExchangePacket> = state<TlsStates::SentServerKeyExchange>
      , state<TlsStates::SentServerHelloReply> + event<TlsEvents::UnableToSendPacket> = X
    );
    // clang-format on
  }
};

} // namespace utopia::portal::client_connection
