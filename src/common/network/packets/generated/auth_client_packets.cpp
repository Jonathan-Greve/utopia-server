#include "utopia/utopia_pch.hpp"

#include "utopia/common/network/packets/generated/auth_client_packets.hpp"

#include "utopia/common/network/packets/packet_reader.hpp"
#include "utopia/common/strings/u16string_to_string.hpp"

#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace utopia {
namespace common {
AuthClientHeartbeat::AuthClientHeartbeat(const std::vector<std::uint8_t> &data)
    : PacketReader(0) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientHeartbeat::get_packet_name() const {
  return "AuthClientHeartbeat";
}

std::string AuthClientHeartbeat::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientHeartbeat"
     << "\n";
  ss << "  uptime: " << uptime << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientHeartbeat::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientHeartbeat::get_packet_size() const {
  return packet_size;
}
bool AuthClientHeartbeat::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(uptime, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientHeartbeat::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(uptime, data);
  return data;
}
AuthClientComputerUserInfo::AuthClientComputerUserInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(1) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientComputerUserInfo::get_packet_name() const {
  return "AuthClientComputerUserInfo";
}

std::string AuthClientComputerUserInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientComputerUserInfo"
     << "\n";
  ss << "  pc_username: " << common::u16string_to_string(pc_username) << "\n";
  ss << "  pc_name: " << common::u16string_to_string(pc_name) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientComputerUserInfo::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientComputerUserInfo::get_packet_size() const {
  return packet_size;
}
bool AuthClientComputerUserInfo::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(pc_username, 32, it, data, packet_size))
    return false;
  if (!read_string(pc_name, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientComputerUserInfo::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(pc_username, data);
  pack_string(pc_name, data);
  return data;
}
AuthClientGameInfo::AuthClientGameInfo(const std::vector<std::uint8_t> &data)
    : PacketReader(2) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientGameInfo::get_packet_name() const {
  return "AuthClientGameInfo";
}

std::string AuthClientGameInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientGameInfo"
     << "\n";
  ss << "  game_version: " << game_version << "\n";
  ss << "  hash: ";
  for (const auto &item : hash) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientGameInfo::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientGameInfo::get_packet_size() const {
  return packet_size;
}
bool AuthClientGameInfo::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(game_version, it, data, packet_size))
    return false;
  if (!read_blob(hash, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientGameInfo::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(game_version, data);
  pack_blob(hash, data);
  return data;
}
AuthClientPacket003::AuthClientPacket003(const std::vector<std::uint8_t> &data)
    : PacketReader(3) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket003::get_packet_name() const {
  return "AuthClientPacket003";
}

std::string AuthClientPacket003::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket003"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: ";
  for (const auto &item : field_2) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket003::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket003::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket003::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 64, it, data, packet_size))
    return false;
  if (!read_blob(field_2, it, data, packet_size))
    return false;
  if (!read_string(field_3, 26, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket003::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_blob(field_2, data);
  pack_string(field_3, data);
  return data;
}
AuthClientPacket004::AuthClientPacket004(const std::vector<std::uint8_t> &data)
    : PacketReader(4) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket004::get_packet_name() const {
  return "AuthClientPacket004";
}

std::string AuthClientPacket004::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket004"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket004::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket004::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket004::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket004::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
AuthClientPacket005::AuthClientPacket005(const std::vector<std::uint8_t> &data)
    : PacketReader(5) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket005::get_packet_name() const {
  return "AuthClientPacket005";
}

std::string AuthClientPacket005::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket005"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: ";
  for (const auto &item : field_2) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_3: ";
  for (const auto &item : field_3) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket005::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket005::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket005::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_blob(field_2, it, data, packet_size))
    return false;
  if (!read_blob(field_3, it, data, packet_size))
    return false;
  if (!read_string(field_4, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket005::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_blob(field_2, data);
  pack_blob(field_3, data);
  pack_string(field_4, data);
  return data;
}
AuthClientPacket006::AuthClientPacket006(const std::vector<std::uint8_t> &data)
    : PacketReader(6) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket006::get_packet_name() const {
  return "AuthClientPacket006";
}

std::string AuthClientPacket006::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket006"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket006::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket006::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket006::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket006::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
AuthClientPacket007::AuthClientPacket007(const std::vector<std::uint8_t> &data)
    : PacketReader(7) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket007::get_packet_name() const {
  return "AuthClientPacket007";
}

std::string AuthClientPacket007::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket007"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket007::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket007::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket007::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket007::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
AuthClientPacket008::AuthClientPacket008(const std::vector<std::uint8_t> &data)
    : PacketReader(8) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket008::get_packet_name() const {
  return "AuthClientPacket008";
}

std::string AuthClientPacket008::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket008"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket008::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket008::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket008::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket008::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
AuthClientPacket009::AuthClientPacket009(const std::vector<std::uint8_t> &data)
    : PacketReader(9) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket009::get_packet_name() const {
  return "AuthClientPacket009";
}

std::string AuthClientPacket009::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket009"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: ";
  for (const auto &item : field_2) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket009::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket009::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket009::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;
  if (!read_array(field_2, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket009::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_array(field_2, data);
  return data;
}
AuthClientChangePlayCharacter::AuthClientChangePlayCharacter(
    const std::vector<std::uint8_t> &data)
    : PacketReader(10) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientChangePlayCharacter::get_packet_name() const {
  return "AuthClientChangePlayCharacter";
}

std::string AuthClientChangePlayCharacter::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientChangePlayCharacter"
     << "\n";
  ss << "  transaction_id: " << transaction_id << "\n";
  ss << "  character_name: " << common::u16string_to_string(character_name)
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
AuthClientChangePlayCharacter::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientChangePlayCharacter::get_packet_size() const {
  return packet_size;
}
bool AuthClientChangePlayCharacter::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(transaction_id, it, data, packet_size))
    return false;
  if (!read_string(character_name, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientChangePlayCharacter::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(transaction_id, data);
  pack_string(character_name, data);
  return data;
}
AuthClientPacket011::AuthClientPacket011(const std::vector<std::uint8_t> &data)
    : PacketReader(11) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket011::get_packet_name() const {
  return "AuthClientPacket011";
}

std::string AuthClientPacket011::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket011"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket011::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket011::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket011::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket011::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
AuthClientPacket012::AuthClientPacket012(const std::vector<std::uint8_t> &data)
    : PacketReader(12) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket012::get_packet_name() const {
  return "AuthClientPacket012";
}

std::string AuthClientPacket012::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket012"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: ";
  for (const auto &item : field_2) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket012::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket012::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket012::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_blob(field_2, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket012::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_blob(field_2, data);
  return data;
}
AuthClientPacket013::AuthClientPacket013(const std::vector<std::uint8_t> &data)
    : PacketReader(13) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket013::get_packet_name() const {
  return "AuthClientPacket013";
}

std::string AuthClientPacket013::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket013"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket013::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket013::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket013::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket013::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
AuthClientSetPlayerStatus::AuthClientSetPlayerStatus(
    const std::vector<std::uint8_t> &data)
    : PacketReader(14) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientSetPlayerStatus::get_packet_name() const {
  return "AuthClientSetPlayerStatus";
}

std::string AuthClientSetPlayerStatus::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientSetPlayerStatus"
     << "\n";
  ss << "  status: " << status << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientSetPlayerStatus::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientSetPlayerStatus::get_packet_size() const {
  return packet_size;
}
bool AuthClientSetPlayerStatus::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(status, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientSetPlayerStatus::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(status, data);
  return data;
}
AuthClientHardwareInfo::AuthClientHardwareInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(15) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientHardwareInfo::get_packet_name() const {
  return "AuthClientHardwareInfo";
}

std::string AuthClientHardwareInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientHardwareInfo"
     << "\n";
  ss << "  info: ";
  for (const auto &item : info) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  hash: ";
  for (const auto &item : hash) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientHardwareInfo::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientHardwareInfo::get_packet_size() const {
  return packet_size;
}
bool AuthClientHardwareInfo::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(info, 92, it, data, packet_size))
    return false;
  if (!read_blob(hash, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientHardwareInfo::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(info, data);
  pack_blob(hash, data);
  return data;
}
AuthClientPacket016::AuthClientPacket016(const std::vector<std::uint8_t> &data)
    : PacketReader(16) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket016::get_packet_name() const {
  return "AuthClientPacket016";
}

std::string AuthClientPacket016::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket016"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket016::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket016::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket016::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket016::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
AuthClientPacket017::AuthClientPacket017(const std::vector<std::uint8_t> &data)
    : PacketReader(17) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket017::get_packet_name() const {
  return "AuthClientPacket017";
}

std::string AuthClientPacket017::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket017"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket017::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket017::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket017::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 256, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket017::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
AuthClientPacket018::AuthClientPacket018(const std::vector<std::uint8_t> &data)
    : PacketReader(18) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket018::get_packet_name() const {
  return "AuthClientPacket018";
}

std::string AuthClientPacket018::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket018"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket018::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket018::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket018::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket018::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
AuthClientPacket019::AuthClientPacket019(const std::vector<std::uint8_t> &data)
    : PacketReader(19) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket019::get_packet_name() const {
  return "AuthClientPacket019";
}

std::string AuthClientPacket019::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket019"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket019::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket019::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket019::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket019::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
AuthClientPacket020::AuthClientPacket020(const std::vector<std::uint8_t> &data)
    : PacketReader(20) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket020::get_packet_name() const {
  return "AuthClientPacket020";
}

std::string AuthClientPacket020::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket020"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket020::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket020::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket020::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 64, it, data, packet_size))
    return false;
  if (!read_string(field_3, 64, it, data, packet_size))
    return false;
  if (!read_string(field_4, 256, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket020::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  pack_string(field_3, data);
  pack_string(field_4, data);
  return data;
}
AuthClientPacket021::AuthClientPacket021(const std::vector<std::uint8_t> &data)
    : PacketReader(21) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket021::get_packet_name() const {
  return "AuthClientPacket021";
}

std::string AuthClientPacket021::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket021"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket021::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket021::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket021::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket021::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
AuthClientPacket022::AuthClientPacket022(const std::vector<std::uint8_t> &data)
    : PacketReader(22) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket022::get_packet_name() const {
  return "AuthClientPacket022";
}

std::string AuthClientPacket022::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket022"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket022::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket022::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket022::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket022::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
AuthClientPacket023::AuthClientPacket023(const std::vector<std::uint8_t> &data)
    : PacketReader(23) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket023::get_packet_name() const {
  return "AuthClientPacket023";
}

std::string AuthClientPacket023::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket023"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket023::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket023::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket023::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket023::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
AuthClientPacket024::AuthClientPacket024(const std::vector<std::uint8_t> &data)
    : PacketReader(24) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket024::get_packet_name() const {
  return "AuthClientPacket024";
}

std::string AuthClientPacket024::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket024"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket024::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket024::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket024::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket024::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
AuthClientPacket025::AuthClientPacket025(const std::vector<std::uint8_t> &data)
    : PacketReader(25) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket025::get_packet_name() const {
  return "AuthClientPacket025";
}

std::string AuthClientPacket025::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket025"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: ";
  for (const auto &item : field_2) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_3: ";
  for (const auto &item : field_3) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket025::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket025::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket025::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_blob(field_2, it, data, packet_size))
    return false;
  if (!read_blob(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket025::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_blob(field_2, data);
  pack_blob(field_3, data);
  return data;
}
AuthClientPacket026::AuthClientPacket026(const std::vector<std::uint8_t> &data)
    : PacketReader(26) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket026::get_packet_name() const {
  return "AuthClientPacket026";
}

std::string AuthClientPacket026::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket026"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket026::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket026::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket026::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 20, it, data, packet_size))
    return false;
  if (!read_string(field_3, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket026::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  pack_string(field_3, data);
  return data;
}
AuthClientPacket027::AuthClientPacket027(const std::vector<std::uint8_t> &data)
    : PacketReader(27) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket027::get_packet_name() const {
  return "AuthClientPacket027";
}

std::string AuthClientPacket027::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket027"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket027::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket027::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket027::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_blob(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket027::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_blob(field_1, data);
  pack_string(field_2, data);
  return data;
}
AuthClientPacket028::AuthClientPacket028(const std::vector<std::uint8_t> &data)
    : PacketReader(28) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket028::get_packet_name() const {
  return "AuthClientPacket028";
}

std::string AuthClientPacket028::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket028"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket028::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket028::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket028::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 26, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket028::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
AuthClientPacket029::AuthClientPacket029(const std::vector<std::uint8_t> &data)
    : PacketReader(29) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket029::get_packet_name() const {
  return "AuthClientPacket029";
}

std::string AuthClientPacket029::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket029"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket029::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket029::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket029::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket029::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
AuthClientPacket030::AuthClientPacket030(const std::vector<std::uint8_t> &data)
    : PacketReader(30) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket030::get_packet_name() const {
  return "AuthClientPacket030";
}

std::string AuthClientPacket030::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket030"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket030::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket030::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket030::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 26, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket030::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  return data;
}
AuthClientPacket031::AuthClientPacket031(const std::vector<std::uint8_t> &data)
    : PacketReader(31) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket031::get_packet_name() const {
  return "AuthClientPacket031";
}

std::string AuthClientPacket031::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket031"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << common::u16string_to_string(field_6) << "\n";
  ss << "  field_7: " << common::u16string_to_string(field_7) << "\n";
  ss << "  field_8: " << common::u16string_to_string(field_8) << "\n";
  ss << "  field_9: " << common::u16string_to_string(field_9) << "\n";
  ss << "  field_10: " << common::u16string_to_string(field_10) << "\n";
  ss << "  field_11: " << common::u16string_to_string(field_11) << "\n";
  ss << "  field_12: " << common::u16string_to_string(field_12) << "\n";
  ss << "  field_13: " << common::u16string_to_string(field_13) << "\n";
  ss << "  field_14: " << common::u16string_to_string(field_14) << "\n";
  ss << "  field_15: " << common::u16string_to_string(field_15) << "\n";
  ss << "  field_16: " << common::u16string_to_string(field_16) << "\n";
  ss << "  field_17: " << common::u16string_to_string(field_17) << "\n";
  ss << "  field_18: " << common::u16string_to_string(field_18) << "\n";
  ss << "  field_19: " << common::u16string_to_string(field_19) << "\n";
  ss << "  field_20: " << common::u16string_to_string(field_20) << "\n";
  ss << "  field_21: " << common::u16string_to_string(field_21) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket031::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket031::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket031::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_field(field_5, it, data, packet_size))
    return false;
  if (!read_string(field_6, 64, it, data, packet_size))
    return false;
  if (!read_string(field_7, 16, it, data, packet_size))
    return false;
  if (!read_string(field_8, 256, it, data, packet_size))
    return false;
  if (!read_string(field_9, 32, it, data, packet_size))
    return false;
  if (!read_string(field_10, 28, it, data, packet_size))
    return false;
  if (!read_string(field_11, 28, it, data, packet_size))
    return false;
  if (!read_string(field_12, 32, it, data, packet_size))
    return false;
  if (!read_string(field_13, 32, it, data, packet_size))
    return false;
  if (!read_string(field_14, 28, it, data, packet_size))
    return false;
  if (!read_string(field_15, 4, it, data, packet_size))
    return false;
  if (!read_string(field_16, 32, it, data, packet_size))
    return false;
  if (!read_string(field_17, 4, it, data, packet_size))
    return false;
  if (!read_string(field_18, 28, it, data, packet_size))
    return false;
  if (!read_string(field_19, 12, it, data, packet_size))
    return false;
  if (!read_string(field_20, 20, it, data, packet_size))
    return false;
  if (!read_string(field_21, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket031::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_string(field_6, data);
  pack_string(field_7, data);
  pack_string(field_8, data);
  pack_string(field_9, data);
  pack_string(field_10, data);
  pack_string(field_11, data);
  pack_string(field_12, data);
  pack_string(field_13, data);
  pack_string(field_14, data);
  pack_string(field_15, data);
  pack_string(field_16, data);
  pack_string(field_17, data);
  pack_string(field_18, data);
  pack_string(field_19, data);
  pack_string(field_20, data);
  pack_string(field_21, data);
  return data;
}
AuthClientPacket032::AuthClientPacket032(const std::vector<std::uint8_t> &data)
    : PacketReader(32) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket032::get_packet_name() const {
  return "AuthClientPacket032";
}

std::string AuthClientPacket032::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket032"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket032::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket032::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket032::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_array(field_1, 512, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket032::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_array(field_1, data);
  return data;
}
AuthClientPacket033::AuthClientPacket033(const std::vector<std::uint8_t> &data)
    : PacketReader(33) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket033::get_packet_name() const {
  return "AuthClientPacket033";
}

std::string AuthClientPacket033::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket033"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket033::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket033::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket033::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket033::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
AuthClientPacket034::AuthClientPacket034(const std::vector<std::uint8_t> &data)
    : PacketReader(34) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket034::get_packet_name() const {
  return "AuthClientPacket034";
}

std::string AuthClientPacket034::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket034"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket034::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket034::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket034::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket034::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
AuthClientPacket035::AuthClientPacket035(const std::vector<std::uint8_t> &data)
    : PacketReader(35) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket035::get_packet_name() const {
  return "AuthClientPacket035";
}

std::string AuthClientPacket035::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket035"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket035::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket035::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket035::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket035::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
AuthClientPacket036::AuthClientPacket036(const std::vector<std::uint8_t> &data)
    : PacketReader(36) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket036::get_packet_name() const {
  return "AuthClientPacket036";
}

std::string AuthClientPacket036::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket036"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket036::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket036::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket036::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 64, it, data, packet_size))
    return false;
  if (!read_string(field_2, 16, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket036::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_string(field_2, data);
  return data;
}
AuthClientPacket037::AuthClientPacket037(const std::vector<std::uint8_t> &data)
    : PacketReader(37) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket037::get_packet_name() const {
  return "AuthClientPacket037";
}

std::string AuthClientPacket037::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket037"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: ";
  for (const auto &item : field_5) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket037::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket037::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket037::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_blob(field_5, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket037::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_blob(field_5, data);
  return data;
}
AuthClientPacket038::AuthClientPacket038(const std::vector<std::uint8_t> &data)
    : PacketReader(38) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket038::get_packet_name() const {
  return "AuthClientPacket038";
}

std::string AuthClientPacket038::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket038"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket038::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket038::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket038::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket038::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
AuthClientPacket039::AuthClientPacket039(const std::vector<std::uint8_t> &data)
    : PacketReader(39) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket039::get_packet_name() const {
  return "AuthClientPacket039";
}

std::string AuthClientPacket039::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket039"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket039::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket039::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket039::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket039::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
AuthClientPacket040::AuthClientPacket040(const std::vector<std::uint8_t> &data)
    : PacketReader(40) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket040::get_packet_name() const {
  return "AuthClientPacket040";
}

std::string AuthClientPacket040::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket040"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  ss << "  field_5: " << common::u16string_to_string(field_5) << "\n";
  ss << "  field_6: " << common::u16string_to_string(field_6) << "\n";
  ss << "  field_7: " << common::u16string_to_string(field_7) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket040::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket040::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket040::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 28, it, data, packet_size))
    return false;
  if (!read_string(field_2, 28, it, data, packet_size))
    return false;
  if (!read_string(field_3, 32, it, data, packet_size))
    return false;
  if (!read_string(field_4, 32, it, data, packet_size))
    return false;
  if (!read_string(field_5, 12, it, data, packet_size))
    return false;
  if (!read_string(field_6, 28, it, data, packet_size))
    return false;
  if (!read_string(field_7, 28, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket040::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_string(field_2, data);
  pack_string(field_3, data);
  pack_string(field_4, data);
  pack_string(field_5, data);
  pack_string(field_6, data);
  pack_string(field_7, data);
  return data;
}
AuthClientRequestInstance::AuthClientRequestInstance(
    const std::vector<std::uint8_t> &data)
    : PacketReader(41) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientRequestInstance::get_packet_name() const {
  return "AuthClientRequestInstance";
}

std::string AuthClientRequestInstance::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientRequestInstance"
     << "\n";
  ss << "  transaction_id: " << transaction_id << "\n";
  ss << "  map_type: " << map_type << "\n";
  ss << "  map_id: " << map_id << "\n";
  ss << "  region: " << region << "\n";
  ss << "  district: " << district << "\n";
  ss << "  language: " << language << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientRequestInstance::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientRequestInstance::get_packet_size() const {
  return packet_size;
}
bool AuthClientRequestInstance::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(transaction_id, it, data, packet_size))
    return false;
  if (!read_field(map_type, it, data, packet_size))
    return false;
  if (!read_field(map_id, it, data, packet_size))
    return false;
  if (!read_field(region, it, data, packet_size))
    return false;
  if (!read_field(district, it, data, packet_size))
    return false;
  if (!read_field(language, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientRequestInstance::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(transaction_id, data);
  pack_field(map_type, data);
  pack_field(map_id, data);
  pack_field(region, data);
  pack_field(district, data);
  pack_field(language, data);
  return data;
}
AuthClientPacket042::AuthClientPacket042(const std::vector<std::uint8_t> &data)
    : PacketReader(42) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket042::get_packet_name() const {
  return "AuthClientPacket042";
}

std::string AuthClientPacket042::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket042"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket042::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket042::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket042::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;
  if (!read_string(field_2, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket042::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_string(field_2, data);
  return data;
}
AuthClientPacket043::AuthClientPacket043(const std::vector<std::uint8_t> &data)
    : PacketReader(43) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket043::get_packet_name() const {
  return "AuthClientPacket043";
}

std::string AuthClientPacket043::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket043"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_2: ";
  for (const auto &item : field_2) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket043::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket043::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket043::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_array(field_1, 128, it, data, packet_size))
    return false;
  if (!read_array(field_2, 128, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket043::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_array(field_1, data);
  pack_array(field_2, data);
  return data;
}
AuthClientPacket044::AuthClientPacket044(const std::vector<std::uint8_t> &data)
    : PacketReader(44) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket044::get_packet_name() const {
  return "AuthClientPacket044";
}

std::string AuthClientPacket044::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket044"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << common::u16string_to_string(field_6) << "\n";
  ss << "  field_7: " << common::u16string_to_string(field_7) << "\n";
  ss << "  field_8: " << common::u16string_to_string(field_8) << "\n";
  ss << "  field_9: " << common::u16string_to_string(field_9) << "\n";
  ss << "  field_10: " << common::u16string_to_string(field_10) << "\n";
  ss << "  field_11: " << common::u16string_to_string(field_11) << "\n";
  ss << "  field_12: " << common::u16string_to_string(field_12) << "\n";
  ss << "  field_13: " << common::u16string_to_string(field_13) << "\n";
  ss << "  field_14: " << common::u16string_to_string(field_14) << "\n";
  ss << "  field_15: " << common::u16string_to_string(field_15) << "\n";
  ss << "  field_16: " << common::u16string_to_string(field_16) << "\n";
  ss << "  field_17: " << common::u16string_to_string(field_17) << "\n";
  ss << "  field_18: " << common::u16string_to_string(field_18) << "\n";
  ss << "  field_19: " << common::u16string_to_string(field_19) << "\n";
  ss << "  field_20: ";
  for (const auto &item : field_20) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_21: ";
  for (const auto &item : field_21) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket044::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket044::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket044::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_field(field_5, it, data, packet_size))
    return false;
  if (!read_string(field_6, 32, it, data, packet_size))
    return false;
  if (!read_string(field_7, 64, it, data, packet_size))
    return false;
  if (!read_string(field_8, 64, it, data, packet_size))
    return false;
  if (!read_string(field_9, 28, it, data, packet_size))
    return false;
  if (!read_string(field_10, 4, it, data, packet_size))
    return false;
  if (!read_string(field_11, 4, it, data, packet_size))
    return false;
  if (!read_string(field_12, 12, it, data, packet_size))
    return false;
  if (!read_string(field_13, 8, it, data, packet_size))
    return false;
  if (!read_string(field_14, 32, it, data, packet_size))
    return false;
  if (!read_string(field_15, 28, it, data, packet_size))
    return false;
  if (!read_string(field_16, 64, it, data, packet_size))
    return false;
  if (!read_string(field_17, 64, it, data, packet_size))
    return false;
  if (!read_string(field_18, 10, it, data, packet_size))
    return false;
  if (!read_string(field_19, 6, it, data, packet_size))
    return false;
  if (!read_array(field_20, 128, it, data, packet_size))
    return false;
  if (!read_array(field_21, 128, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket044::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_string(field_6, data);
  pack_string(field_7, data);
  pack_string(field_8, data);
  pack_string(field_9, data);
  pack_string(field_10, data);
  pack_string(field_11, data);
  pack_string(field_12, data);
  pack_string(field_13, data);
  pack_string(field_14, data);
  pack_string(field_15, data);
  pack_string(field_16, data);
  pack_string(field_17, data);
  pack_string(field_18, data);
  pack_string(field_19, data);
  pack_array(field_20, data);
  pack_array(field_21, data);
  return data;
}
AuthClientPacket045::AuthClientPacket045(const std::vector<std::uint8_t> &data)
    : PacketReader(45) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket045::get_packet_name() const {
  return "AuthClientPacket045";
}

std::string AuthClientPacket045::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket045"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket045::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket045::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket045::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket045::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
AuthClientPacket046::AuthClientPacket046(const std::vector<std::uint8_t> &data)
    : PacketReader(46) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket046::get_packet_name() const {
  return "AuthClientPacket046";
}

std::string AuthClientPacket046::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket046"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket046::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket046::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket046::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket046::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
AuthClientPacket047::AuthClientPacket047(const std::vector<std::uint8_t> &data)
    : PacketReader(47) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket047::get_packet_name() const {
  return "AuthClientPacket047";
}

std::string AuthClientPacket047::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket047"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket047::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket047::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket047::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket047::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
AuthClientPacket048::AuthClientPacket048(const std::vector<std::uint8_t> &data)
    : PacketReader(48) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket048::get_packet_name() const {
  return "AuthClientPacket048";
}

std::string AuthClientPacket048::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket048"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket048::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket048::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket048::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket048::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
AuthClientPacket049::AuthClientPacket049(const std::vector<std::uint8_t> &data)
    : PacketReader(49) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket049::get_packet_name() const {
  return "AuthClientPacket049";
}

std::string AuthClientPacket049::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket049"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket049::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket049::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket049::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket049::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
AuthClientPacket050::AuthClientPacket050(const std::vector<std::uint8_t> &data)
    : PacketReader(50) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket050::get_packet_name() const {
  return "AuthClientPacket050";
}

std::string AuthClientPacket050::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket050"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket050::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket050::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket050::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 10, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket050::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
AuthClientPacket051::AuthClientPacket051(const std::vector<std::uint8_t> &data)
    : PacketReader(51) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket051::get_packet_name() const {
  return "AuthClientPacket051";
}

std::string AuthClientPacket051::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket051"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket051::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket051::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket051::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_string(field_4, 18, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket051::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_string(field_4, data);
  return data;
}
AuthClientPacket052::AuthClientPacket052(const std::vector<std::uint8_t> &data)
    : PacketReader(52) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket052::get_packet_name() const {
  return "AuthClientPacket052";
}

std::string AuthClientPacket052::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket052"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket052::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket052::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket052::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket052::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
AuthClientAskServerResponse::AuthClientAskServerResponse(
    const std::vector<std::uint8_t> &data)
    : PacketReader(53) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientAskServerResponse::get_packet_name() const {
  return "AuthClientAskServerResponse";
}

std::string AuthClientAskServerResponse::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientAskServerResponse"
     << "\n";
  ss << "  transaction_id: " << transaction_id << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientAskServerResponse::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientAskServerResponse::get_packet_size() const {
  return packet_size;
}
bool AuthClientAskServerResponse::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(transaction_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientAskServerResponse::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(transaction_id, data);
  return data;
}
AuthClientPacket054::AuthClientPacket054(const std::vector<std::uint8_t> &data)
    : PacketReader(54) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket054::get_packet_name() const {
  return "AuthClientPacket054";
}

std::string AuthClientPacket054::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket054"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: ";
  for (const auto &item : field_6) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_7: " << common::u16string_to_string(field_7) << "\n";
  ss << "  field_8: " << common::u16string_to_string(field_8) << "\n";
  ss << "  field_9: " << common::u16string_to_string(field_9) << "\n";
  ss << "  field_10: " << common::u16string_to_string(field_10) << "\n";
  ss << "  field_11: " << common::u16string_to_string(field_11) << "\n";
  ss << "  field_12: " << common::u16string_to_string(field_12) << "\n";
  ss << "  field_13: " << common::u16string_to_string(field_13) << "\n";
  ss << "  field_14: " << common::u16string_to_string(field_14) << "\n";
  ss << "  field_15: " << common::u16string_to_string(field_15) << "\n";
  ss << "  field_16: " << common::u16string_to_string(field_16) << "\n";
  ss << "  field_17: " << common::u16string_to_string(field_17) << "\n";
  ss << "  field_18: " << common::u16string_to_string(field_18) << "\n";
  ss << "  field_19: " << common::u16string_to_string(field_19) << "\n";
  ss << "  field_20: ";
  for (const auto &item : field_20) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_21: ";
  for (const auto &item : field_21) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket054::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket054::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket054::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_field(field_5, it, data, packet_size))
    return false;
  if (!read_blob(field_6, it, data, packet_size))
    return false;
  if (!read_string(field_7, 32, it, data, packet_size))
    return false;
  if (!read_string(field_8, 64, it, data, packet_size))
    return false;
  if (!read_string(field_9, 64, it, data, packet_size))
    return false;
  if (!read_string(field_10, 28, it, data, packet_size))
    return false;
  if (!read_string(field_11, 4, it, data, packet_size))
    return false;
  if (!read_string(field_12, 4, it, data, packet_size))
    return false;
  if (!read_string(field_13, 12, it, data, packet_size))
    return false;
  if (!read_string(field_14, 8, it, data, packet_size))
    return false;
  if (!read_string(field_15, 32, it, data, packet_size))
    return false;
  if (!read_string(field_16, 28, it, data, packet_size))
    return false;
  if (!read_string(field_17, 64, it, data, packet_size))
    return false;
  if (!read_string(field_18, 64, it, data, packet_size))
    return false;
  if (!read_string(field_19, 10, it, data, packet_size))
    return false;
  if (!read_array(field_20, 128, it, data, packet_size))
    return false;
  if (!read_array(field_21, 128, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket054::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_blob(field_6, data);
  pack_string(field_7, data);
  pack_string(field_8, data);
  pack_string(field_9, data);
  pack_string(field_10, data);
  pack_string(field_11, data);
  pack_string(field_12, data);
  pack_string(field_13, data);
  pack_string(field_14, data);
  pack_string(field_15, data);
  pack_string(field_16, data);
  pack_string(field_17, data);
  pack_string(field_18, data);
  pack_string(field_19, data);
  pack_array(field_20, data);
  pack_array(field_21, data);
  return data;
}
AuthClientPacket055::AuthClientPacket055(const std::vector<std::uint8_t> &data)
    : PacketReader(55) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPacket055::get_packet_name() const {
  return "AuthClientPacket055";
}

std::string AuthClientPacket055::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPacket055"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthClientPacket055::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPacket055::get_packet_size() const {
  return packet_size;
}
bool AuthClientPacket055::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;
  if (!read_string(field_2, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPacket055::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_string(field_2, data);
  return data;
}
AuthClientPortalAccountLogin::AuthClientPortalAccountLogin(
    const std::vector<std::uint8_t> &data)
    : PacketReader(56) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthClientPortalAccountLogin::get_packet_name() const {
  return "AuthClientPortalAccountLogin";
}

std::string AuthClientPortalAccountLogin::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthClientPortalAccountLogin"
     << "\n";
  ss << "  transaction_id: " << transaction_id << "\n";
  ss << "  user_id: ";
  for (const auto &item : user_id) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  session_id: ";
  for (const auto &item : session_id) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  character_name: " << common::u16string_to_string(character_name)
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
AuthClientPortalAccountLogin::get_packed_data() const {
  return pack();
}
std::uint16_t AuthClientPortalAccountLogin::get_packet_size() const {
  return packet_size;
}
bool AuthClientPortalAccountLogin::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(transaction_id, it, data, packet_size))
    return false;
  if (!read_blob(user_id, it, data, packet_size))
    return false;
  if (!read_blob(session_id, it, data, packet_size))
    return false;
  if (!read_string(character_name, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthClientPortalAccountLogin::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(transaction_id, data);
  pack_blob(user_id, data);
  pack_blob(session_id, data);
  pack_string(character_name, data);
  return data;
}
} // namespace common
} // namespace utopia
