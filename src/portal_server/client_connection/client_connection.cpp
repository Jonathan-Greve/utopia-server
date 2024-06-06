#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/client_connection/client_connection.hpp"

#include "utopia/common/network/connection_base.hpp"
#include "utopia/portal_server/client_connection/client_connection_context.hpp"
#include "utopia/portal_server/client_connection/client_connection_logger.hpp"
#include "utopia/portal_server/client_connection/client_connection_state_machine.hpp"
#include "utopia/portal_server/client_connection/events/client_connection_event.hpp"
#include "utopia/portal_server/client_connection/packets/sts_connect_packet.hpp"

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
      client_connection_sm{*this, io_context_, client_connection_sm_context,
                           client_connection_logger, event_queue.get()};

  std::vector<std::uint8_t> recv_buf;

  spdlog::info("Running client connection.");
  while (is_connected()) {
    ClientConnectionEvent event;
    while (event_queue->try_dequeue(event)) {
      std::visit([&](auto &&x) { client_connection_sm.process_event(x); },
                 event);
    }

    auto num_bytes_read = read_some(recv_buf);
    if (!num_bytes_read) {
      continue;
    }

    // Try to dispatch the packet to the state machine if the received data
    // forms a valid packet
    StsConnectPacket sts_connect_packet(recv_buf);
    if (sts_connect_packet.is_valid()) {
      client_connection_sm.process_event(sts_connect_packet);
      recv_buf.erase(recv_buf.begin(),
                     recv_buf.begin() + sts_connect_packet.get_packet_size());
      continue;
    }

    StsConnectReplyPacket sts_connect_reply_packet(recv_buf);
    if (sts_connect_reply_packet.is_valid()) {
      client_connection_sm.process_event(sts_connect_reply_packet);
      recv_buf.erase(recv_buf.begin(),
                     recv_buf.begin() +
                         sts_connect_reply_packet.get_packet_size());
      continue;
    }

    // Log recv buf as ascii
    spdlog::debug("Received data ({} bytes) (ASCII):\n{}",
                  num_bytes_read.value(),
                  std::string(recv_buf.begin(), recv_buf.end()));
  }
}

} // namespace utopia::portal::client_connection
