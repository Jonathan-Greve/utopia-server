#pragma once
#include "utopia/portal_server/client_connection/events/client_connection_events.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_change_cipher_spec_packet.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_finished_packet.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_hello_packet.hpp"
#include "utopia/portal_server/client_connection/packets/tls/tls_client_key_exchange_packet.hpp"
#include "utopia/portal_server/client_connection/tls/actions/enqueue_handshake_complete_event.hpp"
#include "utopia/portal_server/client_connection/tls/actions/handle_tls_client_change_cipher_spec.hpp"
#include "utopia/portal_server/client_connection/tls/actions/handle_tls_client_finished.hpp"
#include "utopia/portal_server/client_connection/tls/actions/handle_tls_client_hello_packet.hpp"
#include "utopia/portal_server/client_connection/tls/actions/handle_tls_client_key_exchange.hpp"
#include "utopia/portal_server/client_connection/tls/actions/send_tls_change_cipher_spec.hpp"
#include "utopia/portal_server/client_connection/tls/actions/send_tls_server_finished.hpp"
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

      , state<TlsStates::SentServerHelloDone> + event<TlsClientKeyExchangePacket> / handle_tls_client_key_exchange = state<TlsStates::ReceivedClientKeyExchange>

      , state<TlsStates::ReceivedClientKeyExchange> + event<TlsChangeCipherSpecPacket> = state<TlsStates::ReceivedChangeCipherSpec>

      , state<TlsStates::ReceivedChangeCipherSpec> + event<TlsClientFinishedPacket> / handle_tls_client_finished
      , state<TlsStates::ReceivedChangeCipherSpec> + event<TlsEvents::ClientFinishedPacketHandled> = state<TlsStates::ClientFinished>
      , state<TlsStates::ReceivedChangeCipherSpec> + event<TlsEvents::FailedToDecryptMessage> = X
      , state<TlsStates::ReceivedChangeCipherSpec> + event<TlsEvents::HmacComputationFailed> = X
      , state<TlsStates::ReceivedChangeCipherSpec> + event<TlsEvents::HmacValidationFailed> = X
      , state<TlsStates::ReceivedChangeCipherSpec> + event<TlsEvents::ClientFinishedVerifyDataMismatch> = X

      , state<TlsStates::ClientFinished> + on_entry<_> / send_tls_change_cipher_spec
      , state<TlsStates::ClientFinished> + event<TlsEvents::SentCipherChangeSpecPacket> = state<TlsStates::SentCipherChangeSpec>
      , state<TlsStates::ClientFinished> + event<TlsEvents::UnableToSendPacket> = X

      , state<TlsStates::SentCipherChangeSpec> + on_entry<_> / send_tls_server_finished
      , state<TlsStates::SentCipherChangeSpec> + event<TlsEvents::SentServerFinishedPacket> = state<TlsStates::SentServerFinished>
      , state<TlsStates::SentCipherChangeSpec> + event<TlsEvents::FailedToIssueNextIV> = X
      , state<TlsStates::SentCipherChangeSpec> + event<TlsEvents::HmacComputationFailed> = X
      , state<TlsStates::SentCipherChangeSpec> + event<TlsEvents::UnableToSendPacket> = X

      // This will take us back to the ClientConnectionStateMachine
      , state<TlsStates::SentServerFinished> + on_entry<_> / enqueue_handshake_complete_event 
    );
    // clang-format on
  }
};

} // namespace utopia::portal::client_connection
