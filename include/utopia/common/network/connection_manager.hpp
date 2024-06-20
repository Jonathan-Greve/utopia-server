
#pragma once

#include "utopia/common/network/connection_base.hpp"

#include <asio.hpp>

#include <cstdint>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>

namespace utopia::common {

class ConnectionManager {
public:
  ConnectionManager(asio::io_context &io_context);
  std::uint32_t
  add_connection(std::unique_ptr<common::ConnectionBase> connection);
  void remove_connection(common::ConnectionBase *connection);
  common::ConnectionBase *get_connection(std::size_t id) const;
  std::vector<common::ConnectionBase *> get_all_connections() const;

private:
  asio::io_context &io_context_;
  std::unordered_map<std::size_t, std::unique_ptr<common::ConnectionBase>>
      connections_;
  mutable std::mutex connections_mutex_;
  std::size_t next_id_ = 0;
};

} // namespace utopia::common
