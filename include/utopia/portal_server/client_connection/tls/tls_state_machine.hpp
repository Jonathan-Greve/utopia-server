#pragma once
#include "utopia/portal_server/client_connection/packets/tls/tls_change_cipher_spec_packet.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_hello_packet.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_key_exchange_packet.hpp"
#include "utopia/portal_server/client_connection/tls/actions/handle_tls_client_change_cipher_spec.hpp"
#include "utopia/portal_server/client_connection/tls/actions/handle_tls_client_handshake_finished.hpp"
#include "utopia/portal_server/client_connection/tls/actions/handle_tls_client_hello_packet.hpp"
#include "utopia/portal_server/client_connection/tls/actions/handle_tls_client_key_exchange.hpp"
#include "utopia/portal_server/client_connection/tls/actions/send_tls_server_hello.hpp"
#include "utopia/portal_server/client_connection/tls/actions/send_tls_server_hello_done.hpp"
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

      , state<TlsStates::SentServerKeyExchange> + on_entry<_> / send_tls_server_hello_done
      , state<TlsStates::SentServerKeyExchange> + event<TlsEvents::SentServerHelloDonePacket> = state<TlsStates::SentServerHelloDone>
      , state<TlsStates::SentServerKeyExchange> + event<TlsEvents::UnableToSendPacket> = X

      ,  state<TlsStates::SentServerHelloDone> + event<TlsClientKeyExchangePacket> / handle_tls_client_key_exchange = state<TlsStates::ReceivedClientKeyExchange>

      , state<TlsStates::ReceivedClientKeyExchange> + event<TlsChangeCipherSpecPacket> = state<TlsStates::ReceivedChangeCipherSpec>

      // , state<TlsStates::ReceivedChangeCipherSpec> + event<TlsEvents::ReceivedClientHandshakeFinished> = state<TlsStates::ReceivedClientHadnshakeFinished>

    );
    // clang-format on
  }
};

} // namespace utopia::portal::client_connection
