#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/client_connection/client_connection.hpp"

#include "utopia/common/network/connection_base.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"

#include <asio.hpp>
#include <spdlog/spdlog.h>

#include <optional>

namespace utopia::portal::client_connection {

ClientConnection::ClientConnection(asio::io_context &io_context,
                                   unsigned short port)
    : ConnectionBase(io_context) {
  if (accept_connection(port)) {
    spdlog::info("Accepted incoming connection on port {}", port);
  }

  io_context.post([this] { run(); });
}

void ClientConnection::run() {
  auto event_queue =
      std::make_unique<moodycamel::ConcurrentQueue<ClientConnectionEvent>>();

  spdlog::info("Running client connection.");
  while (is_connected()) {
    ClientConnectionEvents::ClientDataReceived client_data_received_event;
    client_data_received_event.data.resize(4096);
    auto num_bytes_read = read_some(client_data_received_event.data);

    if (num_bytes_read) {
      spdlog::info("Received {} bytes.", num_bytes_read.value());

      std::string recv_data(client_data_received_event.data.begin(),
                            client_data_received_event.data.begin() +
                                num_bytes_read.value());
      spdlog::info("Received data (ASCII): {}", recv_data);
    }
  }
}

} // namespace utopia::portal::client_connection
