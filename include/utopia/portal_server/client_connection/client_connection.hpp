#pragma once

#include "utopia/common/network/connection_base.hpp"

#include <asio.hpp>

#include <string>

namespace utopia::portal::client_connection {

class ClientConnection : public common::ConnectionBase {
public:
  ClientConnection(asio::io_context &io_context, unsigned short port);

  void run();

private:
  asio::io_context &io_context_;

  template <typename PacketType>
  inline bool dispatch_sts_packet(std::vector<uint8_t> &data) {
    PacketType packet(data);
    if (packet.is_valid()) {
      data.erase(data.begin(), data.begin() + packet.get_packet_size());
      return true;
    }
    return false;
  }

  bool dispatch_sts_packets(std::vector<uint8_t> &data);
};

} // namespace utopia::portal::client_connection
