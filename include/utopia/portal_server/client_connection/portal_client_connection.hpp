#pragma once

#include "utopia/common/network/connection_base.hpp"
#include "utopia/portal_server/client_connection/events/portal_client_connection_event.hpp"

#include <asio.hpp>
#include <boost/sml.hpp>
#include <concurrentqueue.h>

#include <string>

namespace utopia::portal::client_connection {

struct TlsContext;

struct PortalClientConnectionStateMachine;
struct PortalClientConnectionLogger;

class PortalClientConnection : public common::ConnectionBase {
public:
  PortalClientConnection(asio::io_context &io_context, unsigned short port);

  void run();

private:
  asio::io_context &io_context_;

  template <typename PacketType, typename SM>
  inline bool process_tls_sts_packet(std::vector<uint8_t> &data, SM &sm) {
    PacketType packet(data);
    if (packet.is_valid()) {
      spdlog::debug("Packet size: {}", packet.get_packet_size());
      const auto ser_packet = packet.serialize();

      // Compare each byte in data and ser_packet
      if (!std::equal(data.begin(), data.begin() + packet.get_packet_size(),
                      ser_packet.begin())) {
        spdlog::error("Data and serialized packet do not match!");
      }

      sm.process_event(packet);
      data.erase(data.begin(), data.begin() + packet.get_packet_size());
      return true;
    }
    return false;
  }

  bool dispatch_sts_packet(
      std::vector<uint8_t> &data,
      boost::sml::sm<PortalClientConnectionStateMachine,
                     boost::sml::logger<PortalClientConnectionLogger>> &sm);

  bool dispatch_tls_sts_packet(
      std::vector<std::uint8_t> &recv_buf, TlsContext &tls_context,
      boost::sml::sm<PortalClientConnectionStateMachine,
                     boost::sml::logger<PortalClientConnectionLogger>> &sm);

  void process_event_queue(
      moodycamel::ConcurrentQueue<PortalClientConnectionEvent> *event_queue,
      boost::sml::sm<PortalClientConnectionStateMachine,
                     boost::sml::logger<PortalClientConnectionLogger>> &sm);
};

} // namespace utopia::portal::client_connection
