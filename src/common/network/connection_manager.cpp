#include "utopia/utopia_pch.hpp"

#include "utopia/common/network/connection_manager.hpp"

#include "utopia/common/network/connection_base.hpp"

namespace utopia::common {

ConnectionManager::ConnectionManager(asio::io_context &io_context)
    : io_context_(io_context) {}

std::uint32_t
ConnectionManager::add_connection(std::unique_ptr<ConnectionBase> connection) {
  std::lock_guard<std::mutex> lock(connections_mutex_);

  connections_.emplace(next_id_++, std::move(connection));
  spdlog::info("Added a new connection with ID {}", next_id_ - 1);

  return next_id_ - 1;
}

void ConnectionManager::remove_connection(common::ConnectionBase *connection) {
  std::lock_guard<std::mutex> lock(connections_mutex_);
  for (auto it = connections_.begin(); it != connections_.end(); ++it) {
    if (it->second.get() == connection) {
      connections_.erase(it);
      spdlog::info("Removed a connection.");
      return;
    }
  }
}

common::ConnectionBase *
ConnectionManager::get_connection(std::size_t id) const {
  std::lock_guard<std::mutex> lock(connections_mutex_);
  auto it = connections_.find(id);
  return (it != connections_.end()) ? it->second.get() : nullptr;
}

std::vector<common::ConnectionBase *>
ConnectionManager::get_all_connections() const {
  std::lock_guard<std::mutex> lock(connections_mutex_);
  std::vector<common::ConnectionBase *> result;
  result.reserve(connections_.size());
  for (const auto &[id, connection] : connections_) {
    result.push_back(connection.get());
  }
  return result;
}

} // namespace utopia::common
