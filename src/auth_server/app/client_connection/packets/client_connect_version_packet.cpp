#pragma once

#include "utopia/auth_server/client_connection/packets/client_connect_version_packet.hpp"

#include <spdlog/spdlog.h>

#include <cstdint>
#include <string>
#include <vector>

namespace utopia::auth::client_connection {

// Packet is send using Little Endian
ClientConnectVersionPacket::ClientConnectVersionPacket(
    const std::vector<std::uint8_t> &data) {
  if (data.size() < 16) {
    spdlog::error("ClientConnectVersionPacket: Invalid data size");
    is_valid_ = false;
    return;
  }

  source = data[0];
  length = data[1];
  std::copy(data.begin() + 2, data.begin() + 4,
            reinterpret_cast<std::uint8_t *>(&size));
  std::copy(data.begin() + 4, data.begin() + 8,
            reinterpret_cast<std::uint8_t *>(&version));
  std::copy(data.begin() + 8, data.begin() + 12,
            reinterpret_cast<std::uint8_t *>(&unk0));
  std::copy(data.begin() + 12, data.begin() + 16,
            reinterpret_cast<std::uint8_t *>(&unk1));

  is_valid_ = true;
}

std::string ClientConnectVersionPacket::get_packet_name() const {
  return "ClientConnectVersionPacket";
}

std::string ClientConnectVersionPacket::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "ClientConnectVersionPacket"
     << "\n";
  ss << "  source: " << std::to_string(source) << "\n";
  ss << "  length: " << std::to_string(length) << "\n";
  ss << "  size: " << std::to_string(size) << "\n";
  ss << "  version: " << std::to_string(version) << "\n";
  ss << "  unk0: " << std::to_string(unk0) << "\n";
  ss << "  unk1: " << std::to_string(unk1) << "\n";

  return ss.str();
}

std::vector<std::uint8_t> ClientConnectVersionPacket::get_packed_data() const {
  std::vector<std::uint8_t> data;
  data.push_back(source);
  data.push_back(length);
  data.insert(data.end(), reinterpret_cast<const std::uint8_t *>(&size),
              reinterpret_cast<const std::uint8_t *>(&size) + sizeof(size));
  data.insert(data.end(), reinterpret_cast<const std::uint8_t *>(&version),
              reinterpret_cast<const std::uint8_t *>(&version) +
                  sizeof(version));
  data.insert(data.end(), reinterpret_cast<const std::uint8_t *>(&unk0),
              reinterpret_cast<const std::uint8_t *>(&unk0) + sizeof(unk0));
  data.insert(data.end(), reinterpret_cast<const std::uint8_t *>(&unk1),
              reinterpret_cast<const std::uint8_t *>(&unk1) + sizeof(unk1));

  return data;
}

std::uint16_t ClientConnectVersionPacket::get_packet_size() const { return 16; }

} // namespace utopia::auth::client_connection
