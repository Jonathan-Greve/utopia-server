#pragma once

#include "utopia/common/network/client_connection/client_connection.hpp"

#include <asio.hpp>

#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>

namespace utopia::common {

class ConnectionManager {
public:
  ConnectionManager(asio::io_context &io_context);
  void add_connection(std::unique_ptr<ClientConnection> connection);
  void remove_connection(ConnectionBase *connection);
  ConnectionBase *get_connection(std::size_t id) const;
  std::vector<ConnectionBase *> get_all_connections() const;

private:
  asio::io_context &io_context_;
  std::unordered_map<std::size_t, std::unique_ptr<ConnectionBase>> connections_;
  mutable std::mutex connections_mutex_;
  std::size_t next_id_ = 0;
};

} // namespace utopia::common
