#pragma once

#include "utopia/common/sml/logging/state_transition_log_entry.hpp"

#include <boost/circular_buffer.hpp>

#include <cstdint>
#include <unordered_map>

namespace utopia::auth::client_connection {

using TransactionId = std::uint32_t;

enum class TransactionType {
  AccountLogin,
  PlayCharacter,
  RequestMapInstance,
  ServerTransfer,
  SendHardwareInfo,
  ChangeCharacter
};

struct Transaction {
  TransactionId transaction_id;
  TransactionType transaction_type;
};

struct AuthClientConnectionContext {
  boost::circular_buffer<common::StateTransitionLogEntry> state_log{100};

  TransactionId next_transaction_id = 2;
  std::unordered_map<TransactionId, Transaction> transactions;
};

} // namespace utopia::auth::client_connection
