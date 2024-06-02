#include "utopia/utopia_pch.hpp"

#include "utopia/common/network/packets/generated/auth_server_packets.hpp"

#include "utopia/common/network/packets/packet_reader.hpp"
#include "utopia/common/strings/u16string_to_string.hpp"

#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>


namespace utopia {
namespace core {
AuthServerHeartbeat::AuthServerHeartbeat(const std::vector<std::uint8_t> &data)
    : PacketReader(0) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerHeartbeat::get_packet_name() const {
  return "AuthServerHeartbeat";
}

std::string AuthServerHeartbeat::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerHeartbeat"
     << "\n";
  ss << "  unknown: " << unknown << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerHeartbeat::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerHeartbeat::get_packet_size() const {
  return packet_size;
}
bool AuthServerHeartbeat::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(unknown, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerHeartbeat::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(unknown, data);
  return data;
}
AuthServerSessionInfo::AuthServerSessionInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(1) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerSessionInfo::get_packet_name() const {
  return "AuthServerSessionInfo";
}

std::string AuthServerSessionInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerSessionInfo"
     << "\n";
  ss << "  salt: " << salt << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerSessionInfo::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerSessionInfo::get_packet_size() const {
  return packet_size;
}
bool AuthServerSessionInfo::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(salt, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerSessionInfo::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(salt, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
AuthServerPacket002::AuthServerPacket002(const std::vector<std::uint8_t> &data)
    : PacketReader(2) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket002::get_packet_name() const {
  return "AuthServerPacket002";
}

std::string AuthServerPacket002::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket002"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket002::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket002::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket002::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket002::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
AuthServerErrorMessage::AuthServerErrorMessage(
    const std::vector<std::uint8_t> &data)
    : PacketReader(3) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerErrorMessage::get_packet_name() const {
  return "AuthServerErrorMessage";
}

std::string AuthServerErrorMessage::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerErrorMessage"
     << "\n";
  ss << "  transaction_id: " << transaction_id << "\n";
  ss << "  error_code: " << error_code << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerErrorMessage::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerErrorMessage::get_packet_size() const {
  return packet_size;
}
bool AuthServerErrorMessage::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(transaction_id, it, data, packet_size))
    return false;
  if (!read_field(error_code, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerErrorMessage::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(transaction_id, data);
  pack_field(error_code, data);
  return data;
}
AuthServerPacket004::AuthServerPacket004(const std::vector<std::uint8_t> &data)
    : PacketReader(4) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket004::get_packet_name() const {
  return "AuthServerPacket004";
}

std::string AuthServerPacket004::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket004"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket004::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket004::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket004::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 2048, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket004::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
AuthServerPacket005::AuthServerPacket005(const std::vector<std::uint8_t> &data)
    : PacketReader(5) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket005::get_packet_name() const {
  return "AuthServerPacket005";
}

std::string AuthServerPacket005::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket005"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket005::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket005::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket005::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket005::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
AuthServerPacket006::AuthServerPacket006(const std::vector<std::uint8_t> &data)
    : PacketReader(6) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket006::get_packet_name() const {
  return "AuthServerPacket006";
}

std::string AuthServerPacket006::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket006"
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
  ss << "  field_3: ";
  for (const auto &item : field_3) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_4: ";
  for (const auto &item : field_4) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_5: " << field_5 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket006::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket006::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket006::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_blob(field_1, it, data, packet_size))
    return false;
  if (!read_blob(field_2, it, data, packet_size))
    return false;
  if (!read_blob(field_3, it, data, packet_size))
    return false;
  if (!read_blob(field_4, it, data, packet_size))
    return false;
  if (!read_field(field_5, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket006::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_blob(field_1, data);
  pack_blob(field_2, data);
  pack_blob(field_3, data);
  pack_blob(field_4, data);
  pack_field(field_5, data);
  return data;
}
AuthServerCharacterInfo::AuthServerCharacterInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(7) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerCharacterInfo::get_packet_name() const {
  return "AuthServerCharacterInfo";
}

std::string AuthServerCharacterInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerCharacterInfo"
     << "\n";
  ss << "  transaction_id: " << transaction_id << "\n";
  ss << "  uuid: ";
  for (const auto &item : uuid) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  name: " << common::u16string_to_string(name) << "\n";
  ss << "  extra_info: "
     << "\n";
  ss << "    es_field_0: " << extra_info.es_field_0 << "\n";
  ss << "    last_map_id: " << extra_info.last_map_id << "\n";
  ss << "    es_field_2: ";
  for (const auto &item : extra_info.es_field_2) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "    es_field_3: ";
  for (const auto &item : extra_info.es_field_3) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerCharacterInfo::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerCharacterInfo::get_packet_size() const {
  return packet_size;
}
bool AuthServerCharacterInfo::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(transaction_id, it, data, packet_size))
    return false;
  if (!read_blob(uuid, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_string(name, 20, it, data, packet_size))
    return false;
  if (!read_extra_struct(reinterpret_cast<std::uint8_t *>(&extra_info),
                         extra_struct_data_size, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerCharacterInfo::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(transaction_id, data);
  pack_blob(uuid, data);
  pack_field(field_2, data);
  pack_string(name, data);
  pack_extra_struct(&extra_info, extra_struct_data_size, data);
  return data;
}
AuthServerPacket008::AuthServerPacket008(const std::vector<std::uint8_t> &data)
    : PacketReader(8) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket008::get_packet_name() const {
  return "AuthServerPacket008";
}

std::string AuthServerPacket008::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket008"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: ";
  for (const auto &item : field_2) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket008::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket008::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket008::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_blob(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket008::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_blob(field_2, data);
  pack_field(field_3, data);
  return data;
}
AuthServerGameServerInfo::AuthServerGameServerInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(9) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerGameServerInfo::get_packet_name() const {
  return "AuthServerGameServerInfo";
}

std::string AuthServerGameServerInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerGameServerInfo"
     << "\n";
  ss << "  request: " << request << "\n";
  ss << "  world_id: " << world_id << "\n";
  ss << "  map_id: " << map_id << "\n";
  ss << "  host: ";
  for (const auto &item : host) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  player_id: " << player_id << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerGameServerInfo::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerGameServerInfo::get_packet_size() const {
  return packet_size;
}
bool AuthServerGameServerInfo::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(request, it, data, packet_size))
    return false;
  if (!read_field(world_id, it, data, packet_size))
    return false;
  if (!read_field(map_id, it, data, packet_size))
    return false;
  if (!read_blob(host, it, data, packet_size))
    return false;
  if (!read_field(player_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerGameServerInfo::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(request, data);
  pack_field(world_id, data);
  pack_field(map_id, data);
  pack_blob(host, data);
  pack_field(player_id, data);
  return data;
}
AuthServerPacket010::AuthServerPacket010(const std::vector<std::uint8_t> &data)
    : PacketReader(10) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket010::get_packet_name() const {
  return "AuthServerPacket010";
}

std::string AuthServerPacket010::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket010"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: ";
  for (const auto &item : field_2) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket010::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket010::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket010::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_blob(field_2, it, data, packet_size))
    return false;
  if (!read_string(field_3, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket010::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_blob(field_2, data);
  pack_string(field_3, data);
  return data;
}
AuthServerPacket011::AuthServerPacket011(const std::vector<std::uint8_t> &data)
    : PacketReader(11) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket011::get_packet_name() const {
  return "AuthServerPacket011";
}

std::string AuthServerPacket011::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket011"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket011::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket011::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket011::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_blob(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 20, it, data, packet_size))
    return false;
  if (!read_string(field_3, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket011::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_blob(field_1, data);
  pack_string(field_2, data);
  pack_string(field_3, data);
  return data;
}
AuthServerPacket012::AuthServerPacket012(const std::vector<std::uint8_t> &data)
    : PacketReader(12) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket012::get_packet_name() const {
  return "AuthServerPacket012";
}

std::string AuthServerPacket012::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket012"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket012::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket012::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket012::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;
  if (!read_string(field_2, 256, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket012::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_string(field_2, data);
  return data;
}
AuthServerPacket013::AuthServerPacket013(const std::vector<std::uint8_t> &data)
    : PacketReader(13) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket013::get_packet_name() const {
  return "AuthServerPacket013";
}

std::string AuthServerPacket013::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket013"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket013::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket013::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket013::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 256, it, data, packet_size))
    return false;
  if (!read_string(field_3, 256, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket013::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  pack_string(field_3, data);
  return data;
}
AuthServerPacket014::AuthServerPacket014(const std::vector<std::uint8_t> &data)
    : PacketReader(14) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket014::get_packet_name() const {
  return "AuthServerPacket014";
}

std::string AuthServerPacket014::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket014"
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
std::vector<std::uint8_t> AuthServerPacket014::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket014::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket014::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_array(field_2, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket014::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_array(field_2, data);
  return data;
}
AuthServerPacket015::AuthServerPacket015(const std::vector<std::uint8_t> &data)
    : PacketReader(15) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket015::get_packet_name() const {
  return "AuthServerPacket015";
}

std::string AuthServerPacket015::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket015"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket015::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket015::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket015::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket015::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
AuthServerPacket016::AuthServerPacket016(const std::vector<std::uint8_t> &data)
    : PacketReader(16) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket016::get_packet_name() const {
  return "AuthServerPacket016";
}

std::string AuthServerPacket016::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket016"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: ";
  for (const auto &item : field_2) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  ss << "  field_5: " << common::u16string_to_string(field_5) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket016::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket016::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket016::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_blob(field_2, it, data, packet_size))
    return false;
  if (!read_string(field_3, 20, it, data, packet_size))
    return false;
  if (!read_string(field_4, 20, it, data, packet_size))
    return false;
  if (!read_string(field_5, 256, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket016::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_blob(field_2, data);
  pack_string(field_3, data);
  pack_string(field_4, data);
  pack_string(field_5, data);
  return data;
}
AuthServerAccountInfo::AuthServerAccountInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(17) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerAccountInfo::get_packet_name() const {
  return "AuthServerAccountInfo";
}

std::string AuthServerAccountInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerAccountInfo"
     << "\n";
  ss << "  transaction_id: " << transaction_id << "\n";
  ss << "  territory_id: " << territory_id << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: ";
  for (const auto &item : field_3) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_4: ";
  for (const auto &item : field_4) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  account_uuid: ";
  for (const auto &item : account_uuid) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  char_select_character_uuid: ";
  for (const auto &item : char_select_character_uuid) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_7: " << field_7 << "\n";
  ss << "  field_8: ";
  for (const auto &item : field_8) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_9: " << field_9 << "\n";
  ss << "  eula_accepted: " << eula_accepted << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerAccountInfo::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerAccountInfo::get_packet_size() const {
  return packet_size;
}
bool AuthServerAccountInfo::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(transaction_id, it, data, packet_size))
    return false;
  if (!read_field(territory_id, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_blob(field_3, it, data, packet_size))
    return false;
  if (!read_blob(field_4, it, data, packet_size))
    return false;
  if (!read_blob(account_uuid, it, data, packet_size))
    return false;
  if (!read_blob(char_select_character_uuid, it, data, packet_size))
    return false;
  if (!read_field(field_7, it, data, packet_size))
    return false;
  if (!read_array(field_8, 200, it, data, packet_size))
    return false;
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(eula_accepted, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerAccountInfo::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(transaction_id, data);
  pack_field(territory_id, data);
  pack_field(field_2, data);
  pack_blob(field_3, data);
  pack_blob(field_4, data);
  pack_blob(account_uuid, data);
  pack_blob(char_select_character_uuid, data);
  pack_field(field_7, data);
  pack_array(field_8, data);
  pack_field(field_9, data);
  pack_field(eula_accepted, data);
  return data;
}
AuthServerPacket018::AuthServerPacket018(const std::vector<std::uint8_t> &data)
    : PacketReader(18) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket018::get_packet_name() const {
  return "AuthServerPacket018";
}

std::string AuthServerPacket018::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket018"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: ";
  for (const auto &item : field_2) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  ss << "  field_5: " << common::u16string_to_string(field_5) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket018::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket018::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket018::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_blob(field_2, it, data, packet_size))
    return false;
  if (!read_string(field_3, 20, it, data, packet_size))
    return false;
  if (!read_string(field_4, 20, it, data, packet_size))
    return false;
  if (!read_string(field_5, 256, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket018::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_blob(field_2, data);
  pack_string(field_3, data);
  pack_string(field_4, data);
  pack_string(field_5, data);
  return data;
}
AuthServerPacket019::AuthServerPacket019(const std::vector<std::uint8_t> &data)
    : PacketReader(19) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket019::get_packet_name() const {
  return "AuthServerPacket019";
}

std::string AuthServerPacket019::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket019"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket019::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket019::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket019::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket019::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
AuthServerPacket020::AuthServerPacket020(const std::vector<std::uint8_t> &data)
    : PacketReader(20) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket020::get_packet_name() const {
  return "AuthServerPacket020";
}

std::string AuthServerPacket020::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket020"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket020::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket020::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket020::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket020::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
AuthServerPacket021::AuthServerPacket021(const std::vector<std::uint8_t> &data)
    : PacketReader(21) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket021::get_packet_name() const {
  return "AuthServerPacket021";
}

std::string AuthServerPacket021::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket021"
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
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket021::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket021::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket021::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_blob(field_1, it, data, packet_size))
    return false;
  if (!read_blob(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_field(field_5, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket021::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_blob(field_1, data);
  pack_blob(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  return data;
}
AuthServerAccountSettings::AuthServerAccountSettings(
    const std::vector<std::uint8_t> &data)
    : PacketReader(22) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerAccountSettings::get_packet_name() const {
  return "AuthServerAccountSettings";
}

std::string AuthServerAccountSettings::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerAccountSettings"
     << "\n";
  ss << "  transaction_id: " << transaction_id << "\n";
  ss << "  account_settings_data: ";
  for (const auto &item : account_settings_data) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerAccountSettings::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerAccountSettings::get_packet_size() const {
  return packet_size;
}
bool AuthServerAccountSettings::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(transaction_id, it, data, packet_size))
    return false;
  if (!read_array(account_settings_data, 2048, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerAccountSettings::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(transaction_id, data);
  pack_array(account_settings_data, data);
  return data;
}
AuthServerPacket023::AuthServerPacket023(const std::vector<std::uint8_t> &data)
    : PacketReader(23) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket023::get_packet_name() const {
  return "AuthServerPacket023";
}

std::string AuthServerPacket023::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket023"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket023::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket023::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket023::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 4096, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket023::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
AuthServerPacket024::AuthServerPacket024(const std::vector<std::uint8_t> &data)
    : PacketReader(24) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket024::get_packet_name() const {
  return "AuthServerPacket024";
}

std::string AuthServerPacket024::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket024"
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
  ss << "  field_3: ";
  for (const auto &item : field_3) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket024::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket024::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket024::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_blob(field_1, it, data, packet_size))
    return false;
  if (!read_blob(field_2, it, data, packet_size))
    return false;
  if (!read_array(field_3, 200, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket024::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_blob(field_1, data);
  pack_blob(field_2, data);
  pack_array(field_3, data);
  return data;
}
AuthServerPacket025::AuthServerPacket025(const std::vector<std::uint8_t> &data)
    : PacketReader(25) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket025::get_packet_name() const {
  return "AuthServerPacket025";
}

std::string AuthServerPacket025::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket025"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket025::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket025::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket025::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket025::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
AuthServerPacket026::AuthServerPacket026(const std::vector<std::uint8_t> &data)
    : PacketReader(26) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket026::get_packet_name() const {
  return "AuthServerPacket026";
}

std::string AuthServerPacket026::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket026"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: "
     << "\n";
  for (const auto &ns : field_1) {
    ss << "    field_0: " << ns.field_0 << "\n";
    ss << "    field_1: " << ns.field_1 << "\n";
  }
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket026::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket026::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket026::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  // Read the number of structs
  std::uint8_t struct_count;
  if (!read_field(struct_count, it, data, packet_size))
    return false;
  for (std::uint8_t i = 0; i < struct_count; ++i) {
    if (!read_struct(it, data))
      return false;
  }

  return true;
}
bool AuthServerPacket026::read_struct(
    std::vector<std::uint8_t>::const_iterator &it,
    const std::vector<std::uint8_t> &data) {
  some_struct ns;
  if (!read_field(ns.field_0, it, data, packet_size))
    return false;
  if (!read_field(ns.field_1, it, data, packet_size))
    return false;
  field_1.push_back(ns);

  return true;
}
std::vector<std::uint8_t> AuthServerPacket026::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  std::uint8_t struct_count = static_cast<std::uint8_t>(field_1.size());
  pack_field(struct_count, data);
  for (const auto &ns : field_1) {
    pack_field(ns.field_0, data);
    pack_field(ns.field_1, data);
  }
  return data;
}
AuthServerPacket027::AuthServerPacket027(const std::vector<std::uint8_t> &data)
    : PacketReader(27) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket027::get_packet_name() const {
  return "AuthServerPacket027";
}

std::string AuthServerPacket027::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket027"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket027::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket027::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket027::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> AuthServerPacket027::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
AuthServerPacket028::AuthServerPacket028(const std::vector<std::uint8_t> &data)
    : PacketReader(28) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket028::get_packet_name() const {
  return "AuthServerPacket028";
}

std::string AuthServerPacket028::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket028"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket028::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket028::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket028::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket028::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
AuthServerPacket029::AuthServerPacket029(const std::vector<std::uint8_t> &data)
    : PacketReader(29) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket029::get_packet_name() const {
  return "AuthServerPacket029";
}

std::string AuthServerPacket029::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket029"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket029::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket029::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket029::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> AuthServerPacket029::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
AuthServerPacket030::AuthServerPacket030(const std::vector<std::uint8_t> &data)
    : PacketReader(30) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket030::get_packet_name() const {
  return "AuthServerPacket030";
}

std::string AuthServerPacket030::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket030"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  ss << "  field_7: " << field_7 << "\n";
  ss << "  field_8: " << field_8 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket030::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket030::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket030::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_field(field_6, it, data, packet_size))
    return false;
  if (!read_field(field_7, it, data, packet_size))
    return false;
  if (!read_field(field_8, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket030::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_field(field_6, data);
  pack_field(field_7, data);
  pack_field(field_8, data);
  return data;
}
AuthServerPacket031::AuthServerPacket031(const std::vector<std::uint8_t> &data)
    : PacketReader(31) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket031::get_packet_name() const {
  return "AuthServerPacket031";
}

std::string AuthServerPacket031::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket031"
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
std::vector<std::uint8_t> AuthServerPacket031::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket031::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket031::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_array(field_1, 16, it, data, packet_size))
    return false;
  if (!read_array(field_2, 16, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket031::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_array(field_1, data);
  pack_array(field_2, data);
  return data;
}
AuthServerPacket032::AuthServerPacket032(const std::vector<std::uint8_t> &data)
    : PacketReader(32) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket032::get_packet_name() const {
  return "AuthServerPacket032";
}

std::string AuthServerPacket032::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket032"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket032::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket032::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket032::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_string(field_4, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket032::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_string(field_4, data);
  return data;
}
AuthServerPacket033::AuthServerPacket033(const std::vector<std::uint8_t> &data)
    : PacketReader(33) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket033::get_packet_name() const {
  return "AuthServerPacket033";
}

std::string AuthServerPacket033::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket033"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket033::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket033::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket033::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_string(field_4, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket033::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_string(field_4, data);
  return data;
}
AuthServerPacket034::AuthServerPacket034(const std::vector<std::uint8_t> &data)
    : PacketReader(34) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket034::get_packet_name() const {
  return "AuthServerPacket034";
}

std::string AuthServerPacket034::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket034"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket034::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket034::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket034::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_blob(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket034::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_blob(field_1, data);
  return data;
}
AuthServerPacket035::AuthServerPacket035(const std::vector<std::uint8_t> &data)
    : PacketReader(35) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket035::get_packet_name() const {
  return "AuthServerPacket035";
}

std::string AuthServerPacket035::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket035"
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
  ss << "  field_4: ";
  for (const auto &item : field_4) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_5: " << common::u16string_to_string(field_5) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket035::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket035::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket035::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_blob(field_4, it, data, packet_size))
    return false;
  if (!read_string(field_5, 16, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket035::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_blob(field_2, data);
  pack_blob(field_3, data);
  pack_blob(field_4, data);
  pack_string(field_5, data);
  return data;
}
AuthServerPacket036::AuthServerPacket036(const std::vector<std::uint8_t> &data)
    : PacketReader(36) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket036::get_packet_name() const {
  return "AuthServerPacket036";
}

std::string AuthServerPacket036::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket036"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  ss << "  field_5: " << common::u16string_to_string(field_5) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket036::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket036::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket036::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_string(field_3, 4, it, data, packet_size))
    return false;
  if (!read_string(field_4, 20, it, data, packet_size))
    return false;
  if (!read_string(field_5, 16, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket036::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_string(field_3, data);
  pack_string(field_4, data);
  pack_string(field_5, data);
  return data;
}
AuthServerPacket037::AuthServerPacket037(const std::vector<std::uint8_t> &data)
    : PacketReader(37) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket037::get_packet_name() const {
  return "AuthServerPacket037";
}

std::string AuthServerPacket037::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket037"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket037::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket037::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket037::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket037::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
AuthServerPacket038::AuthServerPacket038(const std::vector<std::uint8_t> &data)
    : PacketReader(38) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string AuthServerPacket038::get_packet_name() const {
  return "AuthServerPacket038";
}

std::string AuthServerPacket038::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "AuthServerPacket038"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> AuthServerPacket038::get_packed_data() const {
  return pack();
}
std::uint16_t AuthServerPacket038::get_packet_size() const {
  return packet_size;
}
bool AuthServerPacket038::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> AuthServerPacket038::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
} // namespace core
} // namespace utopia
