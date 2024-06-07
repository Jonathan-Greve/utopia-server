#pragma once

#include "utopia/common/network/connection_base.hpp"

#include <asio.hpp>
#include <boost/sml.hpp>

#include <string>

namespace utopia::portal::client_connection {

struct ClientConnectionStateMachine;
struct ClientConnectionLogger;

class ClientConnection : public common::ConnectionBase {
public:
  ClientConnection(asio::io_context &io_context, unsigned short port);

  void run();

private:
  asio::io_context &io_context_;

  template <typename PacketType, typename SM>
  inline bool dispatch_sts_packet(std::vector<uint8_t> &data, SM &sm) {
    PacketType packet(data);
    if (packet.is_valid()) {
      spdlog::debug("Packet size: {}", packet.get_packet_size());
      sm.process_event(packet);
      data.erase(data.begin(), data.begin() + packet.get_packet_size());
      return true;
    }
    return false;
  }

  bool dispatch_sts_packets(
      std::vector<uint8_t> &data,
      boost::sml::sm<ClientConnectionStateMachine,
                     boost::sml::logger<ClientConnectionLogger>> &sm);
};

} // namespace utopia::portal::client_connection
