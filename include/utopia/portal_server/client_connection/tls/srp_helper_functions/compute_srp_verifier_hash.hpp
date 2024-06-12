#pragma once

#include "utopia/portal_server/client_connection/tls/srp_helper_functions/concat.hpp"
#include "utopia/portal_server/client_connection/tls/srp_helper_functions/sha1.hpp"

#include <mbedtls/sha1.h>

#include <array>
#include <cstdint>
#include <optional>
#include <vector>

namespace utopia::portal::client_connection {

inline std::optional<std::array<std::uint8_t, 20>>
compute_srp_verifier_hash(const std::vector<std::uint8_t> &username,
                          const std::vector<std::uint8_t> &password) {

  constexpr std::array<std::uint8_t, 1> sep = {':'};
  return sha1(concat(username, sep, password));
}

} // namespace utopia::portal::client_connection
