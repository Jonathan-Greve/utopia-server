#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/client_connection/client_connection.hpp"

#include "utopia/common/network/connection_base.hpp"
#include "utopia/portal_server/client_connection/client_connection_context.hpp"
#include "utopia/portal_server/client_connection/client_connection_logger.hpp"
#include "utopia/portal_server/client_connection/client_connection_state_machine.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"

#include <asio.hpp>
#include <spdlog/spdlog.h>

#include <optional>

namespace utopia::portal::client_connection {

ClientConnection::ClientConnection(asio::io_context &io_context,
                                   unsigned short port)
    : ConnectionBase(io_context), io_context_(io_context) {
  if (accept_connection(port)) {
    spdlog::info("Accepted incoming connection on port {}", port);
  }
}

void ClientConnection::run() {
  using namespace boost::sml;
  auto event_queue =
      std::make_unique<moodycamel::ConcurrentQueue<ClientConnectionEvent>>();

  ClientConnectionContext client_connection_sm_context{};

  ClientConnectionLogger client_connection_logger{client_connection_sm_context};

  sm<ClientConnectionStateMachine, logger<ClientConnectionLogger>>
      client_connection_sm{io_context_, client_connection_sm_context,
                           client_connection_logger};

  spdlog::info("Running client connection.");
  while (is_connected()) {
    ClientConnectionEvents::ClientDataReceived client_data_received_event;
    client_data_received_event.data.resize(4096);
    auto num_bytes_read = read_some(client_data_received_event.data);

    client_connection_sm.process_event(client_data_received_event);
  }
}

} // namespace utopia::portal::client_connection
