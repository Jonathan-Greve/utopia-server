#include "utopia/utopia_pch.hpp"

#include "utopia/common/network/packets/generated/game_server_packets.hpp"

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
GameServerTradeRequest::GameServerTradeRequest(
    const std::vector<std::uint8_t> &data)
    : PacketReader(0) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTradeRequest::get_packet_name() const {
  return "GameServerTradeRequest";
}

std::string GameServerTradeRequest::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTradeRequest"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTradeRequest::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTradeRequest::get_packet_size() const {
  return packet_size;
}
bool GameServerTradeRequest::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTradeRequest::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerTradeTerminate::GameServerTradeTerminate(
    const std::vector<std::uint8_t> &data)
    : PacketReader(1) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTradeTerminate::get_packet_name() const {
  return "GameServerTradeTerminate";
}

std::string GameServerTradeTerminate::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTradeTerminate"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTradeTerminate::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTradeTerminate::get_packet_size() const {
  return packet_size;
}
bool GameServerTradeTerminate::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTradeTerminate::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerTradeChangeOffer::GameServerTradeChangeOffer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(2) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTradeChangeOffer::get_packet_name() const {
  return "GameServerTradeChangeOffer";
}

std::string GameServerTradeChangeOffer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTradeChangeOffer"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTradeChangeOffer::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTradeChangeOffer::get_packet_size() const {
  return packet_size;
}
bool GameServerTradeChangeOffer::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTradeChangeOffer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerTradeReceiveOffer::GameServerTradeReceiveOffer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(3) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTradeReceiveOffer::get_packet_name() const {
  return "GameServerTradeReceiveOffer";
}

std::string GameServerTradeReceiveOffer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTradeReceiveOffer"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTradeReceiveOffer::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTradeReceiveOffer::get_packet_size() const {
  return packet_size;
}
bool GameServerTradeReceiveOffer::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTradeReceiveOffer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerTradeAddItem::GameServerTradeAddItem(
    const std::vector<std::uint8_t> &data)
    : PacketReader(4) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTradeAddItem::get_packet_name() const {
  return "GameServerTradeAddItem";
}

std::string GameServerTradeAddItem::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTradeAddItem"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTradeAddItem::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTradeAddItem::get_packet_size() const {
  return packet_size;
}
bool GameServerTradeAddItem::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTradeAddItem::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerTradeAcknowledge::GameServerTradeAcknowledge(
    const std::vector<std::uint8_t> &data)
    : PacketReader(5) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTradeAcknowledge::get_packet_name() const {
  return "GameServerTradeAcknowledge";
}

std::string GameServerTradeAcknowledge::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTradeAcknowledge"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTradeAcknowledge::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTradeAcknowledge::get_packet_size() const {
  return packet_size;
}
bool GameServerTradeAcknowledge::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTradeAcknowledge::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerTradeAccept::GameServerTradeAccept(
    const std::vector<std::uint8_t> &data)
    : PacketReader(6) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTradeAccept::get_packet_name() const {
  return "GameServerTradeAccept";
}

std::string GameServerTradeAccept::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTradeAccept"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTradeAccept::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTradeAccept::get_packet_size() const {
  return packet_size;
}
bool GameServerTradeAccept::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTradeAccept::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket007::GameServerPacket007(const std::vector<std::uint8_t> &data)
    : PacketReader(7) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket007::get_packet_name() const {
  return "GameServerPacket007";
}

std::string GameServerPacket007::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket007"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket007::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket007::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket007::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket007::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerTradeOfferedCount::GameServerTradeOfferedCount(
    const std::vector<std::uint8_t> &data)
    : PacketReader(8) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTradeOfferedCount::get_packet_name() const {
  return "GameServerTradeOfferedCount";
}

std::string GameServerTradeOfferedCount::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTradeOfferedCount"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTradeOfferedCount::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTradeOfferedCount::get_packet_size() const {
  return packet_size;
}
bool GameServerTradeOfferedCount::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTradeOfferedCount::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket009::GameServerPacket009(const std::vector<std::uint8_t> &data)
    : PacketReader(9) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket009::get_packet_name() const {
  return "GameServerPacket009";
}

std::string GameServerPacket009::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket009"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket009::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket009::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket009::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket009::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket010::GameServerPacket010(const std::vector<std::uint8_t> &data)
    : PacketReader(10) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket010::get_packet_name() const {
  return "GameServerPacket010";
}

std::string GameServerPacket010::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket010"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket010::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket010::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket010::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket010::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket011::GameServerPacket011(const std::vector<std::uint8_t> &data)
    : PacketReader(11) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket011::get_packet_name() const {
  return "GameServerPacket011";
}

std::string GameServerPacket011::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket011"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket011::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket011::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket011::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket011::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPingRequest::GameServerPingRequest(
    const std::vector<std::uint8_t> &data)
    : PacketReader(12) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPingRequest::get_packet_name() const {
  return "GameServerPingRequest";
}

std::string GameServerPingRequest::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPingRequest"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPingRequest::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPingRequest::get_packet_size() const {
  return packet_size;
}
bool GameServerPingRequest::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPingRequest::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPingReply::GameServerPingReply(const std::vector<std::uint8_t> &data)
    : PacketReader(13) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPingReply::get_packet_name() const {
  return "GameServerPingReply";
}

std::string GameServerPingReply::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPingReply"
     << "\n";
  ss << "  ping_ms: " << ping_ms << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPingReply::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPingReply::get_packet_size() const {
  return packet_size;
}
bool GameServerPingReply::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(ping_ms, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPingReply::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(ping_ms, data);
  return data;
}
GameServerFriendlistMessage::GameServerFriendlistMessage(
    const std::vector<std::uint8_t> &data)
    : PacketReader(14) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerFriendlistMessage::get_packet_name() const {
  return "GameServerFriendlistMessage";
}

std::string GameServerFriendlistMessage::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerFriendlistMessage"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerFriendlistMessage::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerFriendlistMessage::get_packet_size() const {
  return packet_size;
}
bool GameServerFriendlistMessage::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerFriendlistMessage::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  pack_string(field_3, data);
  return data;
}
GameServerAccountCurrency::GameServerAccountCurrency(
    const std::vector<std::uint8_t> &data)
    : PacketReader(15) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAccountCurrency::get_packet_name() const {
  return "GameServerAccountCurrency";
}

std::string GameServerAccountCurrency::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAccountCurrency"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAccountCurrency::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAccountCurrency::get_packet_size() const {
  return packet_size;
}
bool GameServerAccountCurrency::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerAccountCurrency::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket016::GameServerPacket016(const std::vector<std::uint8_t> &data)
    : PacketReader(16) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket016::get_packet_name() const {
  return "GameServerPacket016";
}

std::string GameServerPacket016::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket016"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket016::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket016::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket016::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket016::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket017::GameServerPacket017(const std::vector<std::uint8_t> &data)
    : PacketReader(17) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket017::get_packet_name() const {
  return "GameServerPacket017";
}

std::string GameServerPacket017::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket017"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket017::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket017::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket017::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket017::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket018::GameServerPacket018(const std::vector<std::uint8_t> &data)
    : PacketReader(18) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket018::get_packet_name() const {
  return "GameServerPacket018";
}

std::string GameServerPacket018::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket018"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket018::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket018::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket018::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket018::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket019::GameServerPacket019(const std::vector<std::uint8_t> &data)
    : PacketReader(19) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket019::get_packet_name() const {
  return "GameServerPacket019";
}

std::string GameServerPacket019::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket019"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket019::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket019::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket019::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket019::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket020::GameServerPacket020(const std::vector<std::uint8_t> &data)
    : PacketReader(20) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket020::get_packet_name() const {
  return "GameServerPacket020";
}

std::string GameServerPacket020::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket020"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket020::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket020::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket020::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket020::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket021::GameServerPacket021(const std::vector<std::uint8_t> &data)
    : PacketReader(21) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket021::get_packet_name() const {
  return "GameServerPacket021";
}

std::string GameServerPacket021::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket021"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket021::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket021::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket021::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket021::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket022::GameServerPacket022(const std::vector<std::uint8_t> &data)
    : PacketReader(22) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket022::get_packet_name() const {
  return "GameServerPacket022";
}

std::string GameServerPacket022::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket022"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket022::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket022::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket022::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket022::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerPacket023::GameServerPacket023(const std::vector<std::uint8_t> &data)
    : PacketReader(23) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket023::get_packet_name() const {
  return "GameServerPacket023";
}

std::string GameServerPacket023::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket023"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket023::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket023::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket023::parse(const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameServerPacket023::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  return data;
}
GameServerPacket024::GameServerPacket024(const std::vector<std::uint8_t> &data)
    : PacketReader(24) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket024::get_packet_name() const {
  return "GameServerPacket024";
}

std::string GameServerPacket024::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket024"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket024::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket024::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket024::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 8, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket024::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerPacket025::GameServerPacket025(const std::vector<std::uint8_t> &data)
    : PacketReader(25) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket025::get_packet_name() const {
  return "GameServerPacket025";
}

std::string GameServerPacket025::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket025"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: "
     << "\n";
  for (const auto &ns : field_2) {
    ss << "    field_0: " << ns.field_0 << "\n";
  }
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket025::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket025::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket025::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
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
bool GameServerPacket025::read_struct(
    std::vector<std::uint8_t>::const_iterator &it,
    const std::vector<std::uint8_t> &data) {
  some_struct ns;
  if (!read_field(ns.field_0, it, data, packet_size))
    return false;
  field_2.push_back(ns);

  return true;
}
std::vector<std::uint8_t> GameServerPacket025::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  std::uint8_t struct_count = static_cast<std::uint8_t>(field_2.size());
  pack_field(struct_count, data);
  for (const auto &ns : field_2) {
    pack_field(ns.field_0, data);
  }
  return data;
}
GameServerPacket026::GameServerPacket026(const std::vector<std::uint8_t> &data)
    : PacketReader(26) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket026::get_packet_name() const {
  return "GameServerPacket026";
}

std::string GameServerPacket026::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket026"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: "
     << "\n";
  for (const auto &ns : field_1) {
    ss << "    field_0: " << ns.field_0 << "\n";
  }
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket026::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket026::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket026::parse(const std::vector<std::uint8_t> &data) {
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
bool GameServerPacket026::read_struct(
    std::vector<std::uint8_t>::const_iterator &it,
    const std::vector<std::uint8_t> &data) {
  some_struct ns;
  if (!read_field(ns.field_0, it, data, packet_size))
    return false;
  field_1.push_back(ns);

  return true;
}
std::vector<std::uint8_t> GameServerPacket026::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  std::uint8_t struct_count = static_cast<std::uint8_t>(field_1.size());
  pack_field(struct_count, data);
  for (const auto &ns : field_1) {
    pack_field(ns.field_0, data);
  }
  return data;
}
GameServerPacket027::GameServerPacket027(const std::vector<std::uint8_t> &data)
    : PacketReader(27) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket027::get_packet_name() const {
  return "GameServerPacket027";
}

std::string GameServerPacket027::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket027"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket027::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket027::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket027::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket027::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket028::GameServerPacket028(const std::vector<std::uint8_t> &data)
    : PacketReader(28) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket028::get_packet_name() const {
  return "GameServerPacket028";
}

std::string GameServerPacket028::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket028"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket028::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket028::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket028::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket028::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket029::GameServerPacket029(const std::vector<std::uint8_t> &data)
    : PacketReader(29) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket029::get_packet_name() const {
  return "GameServerPacket029";
}

std::string GameServerPacket029::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket029"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket029::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket029::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket029::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 128, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket029::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerAgentMovementTick::GameServerAgentMovementTick(
    const std::vector<std::uint8_t> &data)
    : PacketReader(30) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentMovementTick::get_packet_name() const {
  return "GameServerAgentMovementTick";
}

std::string GameServerAgentMovementTick::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentMovementTick"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentMovementTick::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentMovementTick::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentMovementTick::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentMovementTick::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerAgentInstanceTimer::GameServerAgentInstanceTimer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(31) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentInstanceTimer::get_packet_name() const {
  return "GameServerAgentInstanceTimer";
}

std::string GameServerAgentInstanceTimer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentInstanceTimer"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentInstanceTimer::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentInstanceTimer::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentInstanceTimer::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentInstanceTimer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerAgentSpawned::GameServerAgentSpawned(
    const std::vector<std::uint8_t> &data)
    : PacketReader(32) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentSpawned::get_packet_name() const {
  return "GameServerAgentSpawned";
}

std::string GameServerAgentSpawned::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentSpawned"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4.x << " " << field_4.y << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6.x << " " << field_6.y << "\n";
  ss << "  field_7: " << field_7 << "\n";
  ss << "  field_8: " << field_8 << "\n";
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << field_11 << "\n";
  ss << "  field_12: " << field_12 << "\n";
  ss << "  field_13: " << field_13 << "\n";
  ss << "  field_14: " << field_14 << "\n";
  ss << "  field_15: " << field_15 << "\n";
  ss << "  field_16: " << field_16 << "\n";
  ss << "  field_17: " << field_17.x << " " << field_17.y << "\n";
  ss << "  field_18: " << field_18.x << " " << field_18.y << "\n";
  ss << "  field_19: " << field_19 << "\n";
  ss << "  field_20: " << field_20 << "\n";
  ss << "  field_21: " << field_21.x << " " << field_21.y << "\n";
  ss << "  field_22: " << field_22 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentSpawned::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentSpawned::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentSpawned::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_vec2(field_4, it, data, packet_size))
    return false;
  if (!read_field(field_5, it, data, packet_size))
    return false;
  if (!read_vec2(field_6, it, data, packet_size))
    return false;
  if (!read_field(field_7, it, data, packet_size))
    return false;
  if (!read_field(field_8, it, data, packet_size))
    return false;
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_field(field_11, it, data, packet_size))
    return false;
  if (!read_field(field_12, it, data, packet_size))
    return false;
  if (!read_field(field_13, it, data, packet_size))
    return false;
  if (!read_field(field_14, it, data, packet_size))
    return false;
  if (!read_field(field_15, it, data, packet_size))
    return false;
  if (!read_field(field_16, it, data, packet_size))
    return false;
  if (!read_vec2(field_17, it, data, packet_size))
    return false;
  if (!read_vec2(field_18, it, data, packet_size))
    return false;
  if (!read_field(field_19, it, data, packet_size))
    return false;
  if (!read_field(field_20, it, data, packet_size))
    return false;
  if (!read_vec2(field_21, it, data, packet_size))
    return false;
  if (!read_field(field_22, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentSpawned::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_vec2(field_4, data);
  pack_field(field_5, data);
  pack_vec2(field_6, data);
  pack_field(field_7, data);
  pack_field(field_8, data);
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_field(field_11, data);
  pack_field(field_12, data);
  pack_field(field_13, data);
  pack_field(field_14, data);
  pack_field(field_15, data);
  pack_field(field_16, data);
  pack_vec2(field_17, data);
  pack_vec2(field_18, data);
  pack_field(field_19, data);
  pack_field(field_20, data);
  pack_vec2(field_21, data);
  pack_field(field_22, data);
  return data;
}
GameServerAgentDespawned::GameServerAgentDespawned(
    const std::vector<std::uint8_t> &data)
    : PacketReader(33) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentDespawned::get_packet_name() const {
  return "GameServerAgentDespawned";
}

std::string GameServerAgentDespawned::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentDespawned"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentDespawned::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentDespawned::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentDespawned::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentDespawned::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerAgentSetPlayer::GameServerAgentSetPlayer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(34) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentSetPlayer::get_packet_name() const {
  return "GameServerAgentSetPlayer";
}

std::string GameServerAgentSetPlayer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentSetPlayer"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentSetPlayer::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentSetPlayer::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentSetPlayer::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentSetPlayer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket035::GameServerPacket035(const std::vector<std::uint8_t> &data)
    : PacketReader(35) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket035::get_packet_name() const {
  return "GameServerPacket035";
}

std::string GameServerPacket035::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket035"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket035::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket035::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket035::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket035::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket036::GameServerPacket036(const std::vector<std::uint8_t> &data)
    : PacketReader(36) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket036::get_packet_name() const {
  return "GameServerPacket036";
}

std::string GameServerPacket036::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket036"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket036::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket036::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket036::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket036::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerAgentUpdateDirection::GameServerAgentUpdateDirection(
    const std::vector<std::uint8_t> &data)
    : PacketReader(37) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentUpdateDirection::get_packet_name() const {
  return "GameServerAgentUpdateDirection";
}

std::string GameServerAgentUpdateDirection::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentUpdateDirection"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1.x << " " << field_1.y << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentUpdateDirection::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentUpdateDirection::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentUpdateDirection::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_vec2(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentUpdateDirection::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_vec2(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket038::GameServerPacket038(const std::vector<std::uint8_t> &data)
    : PacketReader(38) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket038::get_packet_name() const {
  return "GameServerPacket038";
}

std::string GameServerPacket038::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket038"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket038::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket038::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket038::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket038::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerAgentUpdateSpeedBase::GameServerAgentUpdateSpeedBase(
    const std::vector<std::uint8_t> &data)
    : PacketReader(39) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentUpdateSpeedBase::get_packet_name() const {
  return "GameServerAgentUpdateSpeedBase";
}

std::string GameServerAgentUpdateSpeedBase::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentUpdateSpeedBase"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentUpdateSpeedBase::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentUpdateSpeedBase::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentUpdateSpeedBase::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentUpdateSpeedBase::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerAgentStopMoving::GameServerAgentStopMoving(
    const std::vector<std::uint8_t> &data)
    : PacketReader(40) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentStopMoving::get_packet_name() const {
  return "GameServerAgentStopMoving";
}

std::string GameServerAgentStopMoving::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentStopMoving"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentStopMoving::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentStopMoving::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentStopMoving::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentStopMoving::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerAgentMoveToPoint::GameServerAgentMoveToPoint(
    const std::vector<std::uint8_t> &data)
    : PacketReader(41) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentMoveToPoint::get_packet_name() const {
  return "GameServerAgentMoveToPoint";
}

std::string GameServerAgentMoveToPoint::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentMoveToPoint"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1.x << " " << field_1.y << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentMoveToPoint::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentMoveToPoint::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentMoveToPoint::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_vec2(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentMoveToPoint::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_vec2(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerAgentUpdateDestination::GameServerAgentUpdateDestination(
    const std::vector<std::uint8_t> &data)
    : PacketReader(42) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentUpdateDestination::get_packet_name() const {
  return "GameServerAgentUpdateDestination";
}

std::string GameServerAgentUpdateDestination::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentUpdateDestination"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1.x << " " << field_1.y << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentUpdateDestination::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentUpdateDestination::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentUpdateDestination::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_vec2(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentUpdateDestination::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_vec2(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  return data;
}
GameServerAgentUpdateSpeed::GameServerAgentUpdateSpeed(
    const std::vector<std::uint8_t> &data)
    : PacketReader(43) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentUpdateSpeed::get_packet_name() const {
  return "GameServerAgentUpdateSpeed";
}

std::string GameServerAgentUpdateSpeed::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentUpdateSpeed"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentUpdateSpeed::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentUpdateSpeed::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentUpdateSpeed::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerAgentUpdateSpeed::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerAgentUpdatePosition::GameServerAgentUpdatePosition(
    const std::vector<std::uint8_t> &data)
    : PacketReader(44) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentUpdatePosition::get_packet_name() const {
  return "GameServerAgentUpdatePosition";
}

std::string GameServerAgentUpdatePosition::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentUpdatePosition"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1.x << " " << field_1.y << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentUpdatePosition::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentUpdatePosition::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentUpdatePosition::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_vec2(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentUpdatePosition::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_vec2(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerAgentPlayerDie::GameServerAgentPlayerDie(
    const std::vector<std::uint8_t> &data)
    : PacketReader(45) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentPlayerDie::get_packet_name() const {
  return "GameServerAgentPlayerDie";
}

std::string GameServerAgentPlayerDie::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentPlayerDie"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentPlayerDie::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentPlayerDie::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentPlayerDie::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentPlayerDie::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerAgentUpdateRotation::GameServerAgentUpdateRotation(
    const std::vector<std::uint8_t> &data)
    : PacketReader(46) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentUpdateRotation::get_packet_name() const {
  return "GameServerAgentUpdateRotation";
}

std::string GameServerAgentUpdateRotation::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentUpdateRotation"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentUpdateRotation::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentUpdateRotation::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentUpdateRotation::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerAgentUpdateRotation::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerAgentUpdateAllegiance::GameServerAgentUpdateAllegiance(
    const std::vector<std::uint8_t> &data)
    : PacketReader(47) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentUpdateAllegiance::get_packet_name() const {
  return "GameServerAgentUpdateAllegiance";
}

std::string GameServerAgentUpdateAllegiance::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentUpdateAllegiance"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentUpdateAllegiance::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentUpdateAllegiance::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentUpdateAllegiance::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentUpdateAllegiance::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket048::GameServerPacket048(const std::vector<std::uint8_t> &data)
    : PacketReader(48) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket048::get_packet_name() const {
  return "GameServerPacket048";
}

std::string GameServerPacket048::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket048"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket048::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket048::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket048::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 32, it, data, packet_size))
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

  return true;
}
std::vector<std::uint8_t> GameServerPacket048::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_field(field_6, data);
  return data;
}
GameServerHeroAccountName::GameServerHeroAccountName(
    const std::vector<std::uint8_t> &data)
    : PacketReader(49) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerHeroAccountName::get_packet_name() const {
  return "GameServerHeroAccountName";
}

std::string GameServerHeroAccountName::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerHeroAccountName"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerHeroAccountName::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerHeroAccountName::get_packet_size() const {
  return packet_size;
}
bool GameServerHeroAccountName::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerHeroAccountName::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerPacket050::GameServerPacket050(const std::vector<std::uint8_t> &data)
    : PacketReader(50) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket050::get_packet_name() const {
  return "GameServerPacket050";
}

std::string GameServerPacket050::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket050"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket050::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket050::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket050::parse(const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameServerPacket050::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  return data;
}
GameServerMessageOfTheDay::GameServerMessageOfTheDay(
    const std::vector<std::uint8_t> &data)
    : PacketReader(51) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerMessageOfTheDay::get_packet_name() const {
  return "GameServerMessageOfTheDay";
}

std::string GameServerMessageOfTheDay::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerMessageOfTheDay"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerMessageOfTheDay::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerMessageOfTheDay::get_packet_size() const {
  return packet_size;
}
bool GameServerMessageOfTheDay::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerMessageOfTheDay::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerAgentPinged::GameServerAgentPinged(
    const std::vector<std::uint8_t> &data)
    : PacketReader(52) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentPinged::get_packet_name() const {
  return "GameServerAgentPinged";
}

std::string GameServerAgentPinged::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentPinged"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentPinged::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentPinged::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentPinged::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentPinged::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket053::GameServerPacket053(const std::vector<std::uint8_t> &data)
    : PacketReader(53) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket053::get_packet_name() const {
  return "GameServerPacket053";
}

std::string GameServerPacket053::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket053"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket053::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket053::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket053::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket053::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket054::GameServerPacket054(const std::vector<std::uint8_t> &data)
    : PacketReader(54) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket054::get_packet_name() const {
  return "GameServerPacket054";
}

std::string GameServerPacket054::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket054"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket054::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket054::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket054::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket054::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket055::GameServerPacket055(const std::vector<std::uint8_t> &data)
    : PacketReader(55) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket055::get_packet_name() const {
  return "GameServerPacket055";
}

std::string GameServerPacket055::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket055"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket055::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket055::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket055::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket055::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket056::GameServerPacket056(const std::vector<std::uint8_t> &data)
    : PacketReader(56) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket056::get_packet_name() const {
  return "GameServerPacket056";
}

std::string GameServerPacket056::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket056"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket056::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket056::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket056::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket056::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket057::GameServerPacket057(const std::vector<std::uint8_t> &data)
    : PacketReader(57) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket057::get_packet_name() const {
  return "GameServerPacket057";
}

std::string GameServerPacket057::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket057"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket057::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket057::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket057::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket057::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerAgentUpdateAttribute::GameServerAgentUpdateAttribute(
    const std::vector<std::uint8_t> &data)
    : PacketReader(58) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentUpdateAttribute::get_packet_name() const {
  return "GameServerAgentUpdateAttribute";
}

std::string GameServerAgentUpdateAttribute::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentUpdateAttribute"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentUpdateAttribute::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentUpdateAttribute::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentUpdateAttribute::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_array(field_1, 48, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentUpdateAttribute::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_array(field_1, data);
  return data;
}
GameServerPacket059::GameServerPacket059(const std::vector<std::uint8_t> &data)
    : PacketReader(59) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket059::get_packet_name() const {
  return "GameServerPacket059";
}

std::string GameServerPacket059::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket059"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket059::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket059::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket059::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket059::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerPacket060::GameServerPacket060(const std::vector<std::uint8_t> &data)
    : PacketReader(60) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket060::get_packet_name() const {
  return "GameServerPacket060";
}

std::string GameServerPacket060::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket060"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket060::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket060::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket060::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 8, it, data, packet_size))
    return false;
  if (!read_string(field_1, 128, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket060::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_string(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerAgentAllyDestroy::GameServerAgentAllyDestroy(
    const std::vector<std::uint8_t> &data)
    : PacketReader(61) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentAllyDestroy::get_packet_name() const {
  return "GameServerAgentAllyDestroy";
}

std::string GameServerAgentAllyDestroy::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentAllyDestroy"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentAllyDestroy::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentAllyDestroy::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentAllyDestroy::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentAllyDestroy::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerEffectUpkeepAdded::GameServerEffectUpkeepAdded(
    const std::vector<std::uint8_t> &data)
    : PacketReader(62) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerEffectUpkeepAdded::get_packet_name() const {
  return "GameServerEffectUpkeepAdded";
}

std::string GameServerEffectUpkeepAdded::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerEffectUpkeepAdded"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerEffectUpkeepAdded::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerEffectUpkeepAdded::get_packet_size() const {
  return packet_size;
}
bool GameServerEffectUpkeepAdded::parse(const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameServerEffectUpkeepAdded::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  return data;
}
GameServerEffectUpkeepRemoved::GameServerEffectUpkeepRemoved(
    const std::vector<std::uint8_t> &data)
    : PacketReader(63) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerEffectUpkeepRemoved::get_packet_name() const {
  return "GameServerEffectUpkeepRemoved";
}

std::string GameServerEffectUpkeepRemoved::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerEffectUpkeepRemoved"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerEffectUpkeepRemoved::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerEffectUpkeepRemoved::get_packet_size() const {
  return packet_size;
}
bool GameServerEffectUpkeepRemoved::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerEffectUpkeepRemoved::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerEffectUpkeepApplied::GameServerEffectUpkeepApplied(
    const std::vector<std::uint8_t> &data)
    : PacketReader(64) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerEffectUpkeepApplied::get_packet_name() const {
  return "GameServerEffectUpkeepApplied";
}

std::string GameServerEffectUpkeepApplied::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerEffectUpkeepApplied"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerEffectUpkeepApplied::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerEffectUpkeepApplied::get_packet_size() const {
  return packet_size;
}
bool GameServerEffectUpkeepApplied::parse(
    const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameServerEffectUpkeepApplied::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  return data;
}
GameServerEffectApplied::GameServerEffectApplied(
    const std::vector<std::uint8_t> &data)
    : PacketReader(65) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerEffectApplied::get_packet_name() const {
  return "GameServerEffectApplied";
}

std::string GameServerEffectApplied::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerEffectApplied"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerEffectApplied::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerEffectApplied::get_packet_size() const {
  return packet_size;
}
bool GameServerEffectApplied::parse(const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameServerEffectApplied::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  return data;
}
GameServerEffectRenewed::GameServerEffectRenewed(
    const std::vector<std::uint8_t> &data)
    : PacketReader(66) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerEffectRenewed::get_packet_name() const {
  return "GameServerEffectRenewed";
}

std::string GameServerEffectRenewed::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerEffectRenewed"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerEffectRenewed::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerEffectRenewed::get_packet_size() const {
  return packet_size;
}
bool GameServerEffectRenewed::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerEffectRenewed::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerEffectRemoved::GameServerEffectRemoved(
    const std::vector<std::uint8_t> &data)
    : PacketReader(67) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerEffectRemoved::get_packet_name() const {
  return "GameServerEffectRemoved";
}

std::string GameServerEffectRemoved::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerEffectRemoved"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerEffectRemoved::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerEffectRemoved::get_packet_size() const {
  return packet_size;
}
bool GameServerEffectRemoved::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerEffectRemoved::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket068::GameServerPacket068(const std::vector<std::uint8_t> &data)
    : PacketReader(68) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket068::get_packet_name() const {
  return "GameServerPacket068";
}

std::string GameServerPacket068::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket068"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket068::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket068::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket068::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket068::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerScreenShake::GameServerScreenShake(
    const std::vector<std::uint8_t> &data)
    : PacketReader(69) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerScreenShake::get_packet_name() const {
  return "GameServerScreenShake";
}

std::string GameServerScreenShake::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerScreenShake"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerScreenShake::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerScreenShake::get_packet_size() const {
  return packet_size;
}
bool GameServerScreenShake::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerScreenShake::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket070::GameServerPacket070(const std::vector<std::uint8_t> &data)
    : PacketReader(70) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket070::get_packet_name() const {
  return "GameServerPacket070";
}

std::string GameServerPacket070::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket070"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2.x << " " << field_2.y << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket070::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket070::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket070::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_vec2(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket070::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_vec2(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerAgentDisplayCape::GameServerAgentDisplayCape(
    const std::vector<std::uint8_t> &data)
    : PacketReader(71) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentDisplayCape::get_packet_name() const {
  return "GameServerAgentDisplayCape";
}

std::string GameServerAgentDisplayCape::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentDisplayCape"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentDisplayCape::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentDisplayCape::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentDisplayCape::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentDisplayCape::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerQuestGeneralInfo::GameServerQuestGeneralInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(72) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerQuestGeneralInfo::get_packet_name() const {
  return "GameServerQuestGeneralInfo";
}

std::string GameServerQuestGeneralInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerQuestGeneralInfo"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1.x << " " << field_1.y << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << common::u16string_to_string(field_5) << "\n";
  ss << "  field_6: " << common::u16string_to_string(field_6) << "\n";
  ss << "  field_7: " << common::u16string_to_string(field_7) << "\n";
  ss << "  field_8: " << field_8 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerQuestGeneralInfo::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerQuestGeneralInfo::get_packet_size() const {
  return packet_size;
}
bool GameServerQuestGeneralInfo::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_vec2(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_string(field_5, 8, it, data, packet_size))
    return false;
  if (!read_string(field_6, 8, it, data, packet_size))
    return false;
  if (!read_string(field_7, 8, it, data, packet_size))
    return false;
  if (!read_field(field_8, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerQuestGeneralInfo::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_vec2(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_string(field_5, data);
  pack_string(field_6, data);
  pack_string(field_7, data);
  pack_field(field_8, data);
  return data;
}
GameServerPacket073::GameServerPacket073(const std::vector<std::uint8_t> &data)
    : PacketReader(73) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket073::get_packet_name() const {
  return "GameServerPacket073";
}

std::string GameServerPacket073::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket073"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket073::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket073::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket073::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket073::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket074::GameServerPacket074(const std::vector<std::uint8_t> &data)
    : PacketReader(74) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket074::get_packet_name() const {
  return "GameServerPacket074";
}

std::string GameServerPacket074::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket074"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket074::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket074::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket074::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket074::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerQuestDescription::GameServerQuestDescription(
    const std::vector<std::uint8_t> &data)
    : PacketReader(75) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerQuestDescription::get_packet_name() const {
  return "GameServerQuestDescription";
}

std::string GameServerQuestDescription::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerQuestDescription"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerQuestDescription::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerQuestDescription::get_packet_size() const {
  return packet_size;
}
bool GameServerQuestDescription::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 128, it, data, packet_size))
    return false;
  if (!read_string(field_2, 128, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerQuestDescription::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_string(field_2, data);
  return data;
}
GameServerPacket076::GameServerPacket076(const std::vector<std::uint8_t> &data)
    : PacketReader(76) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket076::get_packet_name() const {
  return "GameServerPacket076";
}

std::string GameServerPacket076::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket076"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1.x << " " << field_1.y << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket076::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket076::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket076::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_vec2(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket076::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_vec2(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerPacket077::GameServerPacket077(const std::vector<std::uint8_t> &data)
    : PacketReader(77) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket077::get_packet_name() const {
  return "GameServerPacket077";
}

std::string GameServerPacket077::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket077"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket077::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket077::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket077::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket077::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket078::GameServerPacket078(const std::vector<std::uint8_t> &data)
    : PacketReader(78) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket078::get_packet_name() const {
  return "GameServerPacket078";
}

std::string GameServerPacket078::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket078"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket078::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket078::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket078::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket078::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerQuestAdd::GameServerQuestAdd(const std::vector<std::uint8_t> &data)
    : PacketReader(79) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerQuestAdd::get_packet_name() const {
  return "GameServerQuestAdd";
}

std::string GameServerQuestAdd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerQuestAdd"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  ss << "  field_5: " << field_5 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerQuestAdd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerQuestAdd::get_packet_size() const {
  return packet_size;
}
bool GameServerQuestAdd::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 8, it, data, packet_size))
    return false;
  if (!read_string(field_3, 8, it, data, packet_size))
    return false;
  if (!read_string(field_4, 8, it, data, packet_size))
    return false;
  if (!read_field(field_5, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerQuestAdd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  pack_string(field_3, data);
  pack_string(field_4, data);
  pack_field(field_5, data);
  return data;
}
GameServerQuestUpdateMarker::GameServerQuestUpdateMarker(
    const std::vector<std::uint8_t> &data)
    : PacketReader(80) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerQuestUpdateMarker::get_packet_name() const {
  return "GameServerQuestUpdateMarker";
}

std::string GameServerQuestUpdateMarker::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerQuestUpdateMarker"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1.x << " " << field_1.y << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerQuestUpdateMarker::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerQuestUpdateMarker::get_packet_size() const {
  return packet_size;
}
bool GameServerQuestUpdateMarker::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_vec2(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerQuestUpdateMarker::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_vec2(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerQuestRemove::GameServerQuestRemove(
    const std::vector<std::uint8_t> &data)
    : PacketReader(81) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerQuestRemove::get_packet_name() const {
  return "GameServerQuestRemove";
}

std::string GameServerQuestRemove::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerQuestRemove"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerQuestRemove::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerQuestRemove::get_packet_size() const {
  return packet_size;
}
bool GameServerQuestRemove::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerQuestRemove::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerQuestAddMarker::GameServerQuestAddMarker(
    const std::vector<std::uint8_t> &data)
    : PacketReader(82) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerQuestAddMarker::get_packet_name() const {
  return "GameServerQuestAddMarker";
}

std::string GameServerQuestAddMarker::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerQuestAddMarker"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1.x << " " << field_1.y << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerQuestAddMarker::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerQuestAddMarker::get_packet_size() const {
  return packet_size;
}
bool GameServerQuestAddMarker::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_vec2(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerQuestAddMarker::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_vec2(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerPacket083::GameServerPacket083(const std::vector<std::uint8_t> &data)
    : PacketReader(83) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket083::get_packet_name() const {
  return "GameServerPacket083";
}

std::string GameServerPacket083::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket083"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket083::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket083::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket083::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 128, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket083::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerPacket084::GameServerPacket084(const std::vector<std::uint8_t> &data)
    : PacketReader(84) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket084::get_packet_name() const {
  return "GameServerPacket084";
}

std::string GameServerPacket084::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket084"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket084::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket084::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket084::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket084::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerNPCUpdateProperties::GameServerNPCUpdateProperties(
    const std::vector<std::uint8_t> &data)
    : PacketReader(85) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerNPCUpdateProperties::get_packet_name() const {
  return "GameServerNPCUpdateProperties";
}

std::string GameServerNPCUpdateProperties::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerNPCUpdateProperties"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  ss << "  field_7: " << field_7 << "\n";
  ss << "  field_8: " << common::u16string_to_string(field_8) << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerNPCUpdateProperties::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerNPCUpdateProperties::get_packet_size() const {
  return packet_size;
}
bool GameServerNPCUpdateProperties::parse(
    const std::vector<std::uint8_t> &data) {
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
  if (!read_string(field_8, 8, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerNPCUpdateProperties::pack() const {
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
  pack_string(field_8, data);
  return data;
}
GameServerNPCUpdateModel::GameServerNPCUpdateModel(
    const std::vector<std::uint8_t> &data)
    : PacketReader(86) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerNPCUpdateModel::get_packet_name() const {
  return "GameServerNPCUpdateModel";
}

std::string GameServerNPCUpdateModel::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerNPCUpdateModel"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerNPCUpdateModel::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerNPCUpdateModel::get_packet_size() const {
  return packet_size;
}
bool GameServerNPCUpdateModel::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_array(field_1, 8, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerNPCUpdateModel::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_array(field_1, data);
  return data;
}
GameServerPacket087::GameServerPacket087(const std::vector<std::uint8_t> &data)
    : PacketReader(87) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket087::get_packet_name() const {
  return "GameServerPacket087";
}

std::string GameServerPacket087::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket087"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket087::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket087::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket087::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket087::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerAgentCreatePlayer::GameServerAgentCreatePlayer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(88) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentCreatePlayer::get_packet_name() const {
  return "GameServerAgentCreatePlayer";
}

std::string GameServerAgentCreatePlayer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentCreatePlayer"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << common::u16string_to_string(field_6) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentCreatePlayer::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentCreatePlayer::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentCreatePlayer::parse(const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameServerAgentCreatePlayer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_string(field_6, data);
  return data;
}
GameServerAgentDestroyPlayer::GameServerAgentDestroyPlayer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(89) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentDestroyPlayer::get_packet_name() const {
  return "GameServerAgentDestroyPlayer";
}

std::string GameServerAgentDestroyPlayer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentDestroyPlayer"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentDestroyPlayer::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentDestroyPlayer::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentDestroyPlayer::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentDestroyPlayer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket090::GameServerPacket090(const std::vector<std::uint8_t> &data)
    : PacketReader(90) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket090::get_packet_name() const {
  return "GameServerPacket090";
}

std::string GameServerPacket090::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket090"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket090::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket090::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket090::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket090::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket091::GameServerPacket091(const std::vector<std::uint8_t> &data)
    : PacketReader(91) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket091::get_packet_name() const {
  return "GameServerPacket091";
}

std::string GameServerPacket091::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket091"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket091::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket091::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket091::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket091::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerChatMessageCore::GameServerChatMessageCore(
    const std::vector<std::uint8_t> &data)
    : PacketReader(92) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerChatMessageCore::get_packet_name() const {
  return "GameServerChatMessageCore";
}

std::string GameServerChatMessageCore::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerChatMessageCore"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerChatMessageCore::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerChatMessageCore::get_packet_size() const {
  return packet_size;
}
bool GameServerChatMessageCore::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerChatMessageCore::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerChatMessageServer::GameServerChatMessageServer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(93) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerChatMessageServer::get_packet_name() const {
  return "GameServerChatMessageServer";
}

std::string GameServerChatMessageServer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerChatMessageServer"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerChatMessageServer::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerChatMessageServer::get_packet_size() const {
  return packet_size;
}
bool GameServerChatMessageServer::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerChatMessageServer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerChatMessageNPC::GameServerChatMessageNPC(
    const std::vector<std::uint8_t> &data)
    : PacketReader(94) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerChatMessageNPC::get_packet_name() const {
  return "GameServerChatMessageNPC";
}

std::string GameServerChatMessageNPC::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerChatMessageNPC"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerChatMessageNPC::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerChatMessageNPC::get_packet_size() const {
  return packet_size;
}
bool GameServerChatMessageNPC::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 8, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerChatMessageNPC::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  return data;
}
GameServerChatMessageGlobal::GameServerChatMessageGlobal(
    const std::vector<std::uint8_t> &data)
    : PacketReader(95) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerChatMessageGlobal::get_packet_name() const {
  return "GameServerChatMessageGlobal";
}

std::string GameServerChatMessageGlobal::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerChatMessageGlobal"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerChatMessageGlobal::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerChatMessageGlobal::get_packet_size() const {
  return packet_size;
}
bool GameServerChatMessageGlobal::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 32, it, data, packet_size))
    return false;
  if (!read_string(field_2, 6, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerChatMessageGlobal::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_string(field_2, data);
  return data;
}
GameServerChatMessageLocal::GameServerChatMessageLocal(
    const std::vector<std::uint8_t> &data)
    : PacketReader(96) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerChatMessageLocal::get_packet_name() const {
  return "GameServerChatMessageLocal";
}

std::string GameServerChatMessageLocal::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerChatMessageLocal"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerChatMessageLocal::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerChatMessageLocal::get_packet_size() const {
  return packet_size;
}
bool GameServerChatMessageLocal::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerChatMessageLocal::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerHeroBehavior::GameServerHeroBehavior(
    const std::vector<std::uint8_t> &data)
    : PacketReader(97) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerHeroBehavior::get_packet_name() const {
  return "GameServerHeroBehavior";
}

std::string GameServerHeroBehavior::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerHeroBehavior"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerHeroBehavior::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerHeroBehavior::get_packet_size() const {
  return packet_size;
}
bool GameServerHeroBehavior::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerHeroBehavior::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket098::GameServerPacket098(const std::vector<std::uint8_t> &data)
    : PacketReader(98) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket098::get_packet_name() const {
  return "GameServerPacket098";
}

std::string GameServerPacket098::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket098"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket098::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket098::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket098::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket098::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerHeroSkillStatus::GameServerHeroSkillStatus(
    const std::vector<std::uint8_t> &data)
    : PacketReader(99) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerHeroSkillStatus::get_packet_name() const {
  return "GameServerHeroSkillStatus";
}

std::string GameServerHeroSkillStatus::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerHeroSkillStatus"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerHeroSkillStatus::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerHeroSkillStatus::get_packet_size() const {
  return packet_size;
}
bool GameServerHeroSkillStatus::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerHeroSkillStatus::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerHeroSkillStatusBitmap::GameServerHeroSkillStatusBitmap(
    const std::vector<std::uint8_t> &data)
    : PacketReader(100) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerHeroSkillStatusBitmap::get_packet_name() const {
  return "GameServerHeroSkillStatusBitmap";
}

std::string GameServerHeroSkillStatusBitmap::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerHeroSkillStatusBitmap"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerHeroSkillStatusBitmap::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerHeroSkillStatusBitmap::get_packet_size() const {
  return packet_size;
}
bool GameServerHeroSkillStatusBitmap::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerHeroSkillStatusBitmap::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket101::GameServerPacket101(const std::vector<std::uint8_t> &data)
    : PacketReader(101) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket101::get_packet_name() const {
  return "GameServerPacket101";
}

std::string GameServerPacket101::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket101"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1.x << " " << field_1.y << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket101::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket101::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket101::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_vec2(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket101::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_vec2(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket102::GameServerPacket102(const std::vector<std::uint8_t> &data)
    : PacketReader(102) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket102::get_packet_name() const {
  return "GameServerPacket102";
}

std::string GameServerPacket102::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket102"
     << "\n";
  ss << "  field_0: " << field_0.x << " " << field_0.y << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket102::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket102::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket102::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_vec2(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket102::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_vec2(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket103::GameServerPacket103(const std::vector<std::uint8_t> &data)
    : PacketReader(103) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket103::get_packet_name() const {
  return "GameServerPacket103";
}

std::string GameServerPacket103::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket103"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket103::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket103::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket103::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket103::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket104::GameServerPacket104(const std::vector<std::uint8_t> &data)
    : PacketReader(104) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket104::get_packet_name() const {
  return "GameServerPacket104";
}

std::string GameServerPacket104::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket104"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket104::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket104::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket104::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket104::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket105::GameServerPacket105(const std::vector<std::uint8_t> &data)
    : PacketReader(105) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket105::get_packet_name() const {
  return "GameServerPacket105";
}

std::string GameServerPacket105::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket105"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket105::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket105::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket105::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket105::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPostProcess::GameServerPostProcess(
    const std::vector<std::uint8_t> &data)
    : PacketReader(106) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPostProcess::get_packet_name() const {
  return "GameServerPostProcess";
}

std::string GameServerPostProcess::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPostProcess"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPostProcess::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPostProcess::get_packet_size() const {
  return packet_size;
}
bool GameServerPostProcess::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPostProcess::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerDungeonReward::GameServerDungeonReward(
    const std::vector<std::uint8_t> &data)
    : PacketReader(107) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerDungeonReward::get_packet_name() const {
  return "GameServerDungeonReward";
}

std::string GameServerDungeonReward::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerDungeonReward"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerDungeonReward::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerDungeonReward::get_packet_size() const {
  return packet_size;
}
bool GameServerDungeonReward::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerDungeonReward::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerNPCUpdateWeapons::GameServerNPCUpdateWeapons(
    const std::vector<std::uint8_t> &data)
    : PacketReader(108) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerNPCUpdateWeapons::get_packet_name() const {
  return "GameServerNPCUpdateWeapons";
}

std::string GameServerNPCUpdateWeapons::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerNPCUpdateWeapons"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerNPCUpdateWeapons::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerNPCUpdateWeapons::get_packet_size() const {
  return packet_size;
}
bool GameServerNPCUpdateWeapons::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerNPCUpdateWeapons::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket109::GameServerPacket109(const std::vector<std::uint8_t> &data)
    : PacketReader(109) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket109::get_packet_name() const {
  return "GameServerPacket109";
}

std::string GameServerPacket109::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket109"
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
  ss << "  field_9: " << field_9 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket109::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket109::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket109::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_field(field_9, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket109::pack() const {
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
  pack_field(field_9, data);
  return data;
}
GameServerPacket110::GameServerPacket110(const std::vector<std::uint8_t> &data)
    : PacketReader(110) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket110::get_packet_name() const {
  return "GameServerPacket110";
}

std::string GameServerPacket110::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket110"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket110::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket110::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket110::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket110::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket111::GameServerPacket111(const std::vector<std::uint8_t> &data)
    : PacketReader(111) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket111::get_packet_name() const {
  return "GameServerPacket111";
}

std::string GameServerPacket111::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket111"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket111::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket111::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket111::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket111::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket112::GameServerPacket112(const std::vector<std::uint8_t> &data)
    : PacketReader(112) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket112::get_packet_name() const {
  return "GameServerPacket112";
}

std::string GameServerPacket112::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket112"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket112::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket112::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket112::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket112::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket113::GameServerPacket113(const std::vector<std::uint8_t> &data)
    : PacketReader(113) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket113::get_packet_name() const {
  return "GameServerPacket113";
}

std::string GameServerPacket113::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket113"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket113::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket113::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket113::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket113::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerPacket114::GameServerPacket114(const std::vector<std::uint8_t> &data)
    : PacketReader(114) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket114::get_packet_name() const {
  return "GameServerPacket114";
}

std::string GameServerPacket114::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket114"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  ss << "  field_7: " << field_7 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket114::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket114::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket114::parse(const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameServerPacket114::pack() const {
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
  return data;
}
GameServerMercenaryInfo::GameServerMercenaryInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(115) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerMercenaryInfo::get_packet_name() const {
  return "GameServerMercenaryInfo";
}

std::string GameServerMercenaryInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerMercenaryInfo"
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
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << field_11 << "\n";
  ss << "  field_12: " << field_12 << "\n";
  ss << "  field_13: " << field_13 << "\n";
  ss << "  field_14: " << field_14 << "\n";
  ss << "  field_15: " << field_15 << "\n";
  ss << "  field_16: " << field_16 << "\n";
  ss << "  field_17: " << field_17 << "\n";
  ss << "  field_18: " << field_18 << "\n";
  ss << "  field_19: " << common::u16string_to_string(field_19) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerMercenaryInfo::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerMercenaryInfo::get_packet_size() const {
  return packet_size;
}
bool GameServerMercenaryInfo::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_field(field_11, it, data, packet_size))
    return false;
  if (!read_field(field_12, it, data, packet_size))
    return false;
  if (!read_field(field_13, it, data, packet_size))
    return false;
  if (!read_field(field_14, it, data, packet_size))
    return false;
  if (!read_field(field_15, it, data, packet_size))
    return false;
  if (!read_field(field_16, it, data, packet_size))
    return false;
  if (!read_field(field_17, it, data, packet_size))
    return false;
  if (!read_field(field_18, it, data, packet_size))
    return false;
  if (!read_string(field_19, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerMercenaryInfo::pack() const {
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
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_field(field_11, data);
  pack_field(field_12, data);
  pack_field(field_13, data);
  pack_field(field_14, data);
  pack_field(field_15, data);
  pack_field(field_16, data);
  pack_field(field_17, data);
  pack_field(field_18, data);
  pack_string(field_19, data);
  return data;
}
GameServerPacket116::GameServerPacket116(const std::vector<std::uint8_t> &data)
    : PacketReader(116) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket116::get_packet_name() const {
  return "GameServerPacket116";
}

std::string GameServerPacket116::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket116"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket116::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket116::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket116::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket116::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket117::GameServerPacket117(const std::vector<std::uint8_t> &data)
    : PacketReader(117) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket117::get_packet_name() const {
  return "GameServerPacket117";
}

std::string GameServerPacket117::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket117"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket117::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket117::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket117::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket117::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket118::GameServerPacket118(const std::vector<std::uint8_t> &data)
    : PacketReader(118) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket118::get_packet_name() const {
  return "GameServerPacket118";
}

std::string GameServerPacket118::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket118"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket118::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket118::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket118::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket118::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket119::GameServerPacket119(const std::vector<std::uint8_t> &data)
    : PacketReader(119) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket119::get_packet_name() const {
  return "GameServerPacket119";
}

std::string GameServerPacket119::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket119"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: "
     << "\n";
  for (const auto &ns : field_1) {
    ss << "    field_0: " << ns.field_0 << "\n";
    ss << "    field_1: " << ns.field_1 << "\n";
    ss << "    field_2: " << ns.field_2 << "\n";
    ss << "    field_3: " << ns.field_3 << "\n";
    ss << "    field_4: " << ns.field_4 << "\n";
  }
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket119::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket119::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket119::parse(const std::vector<std::uint8_t> &data) {
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
bool GameServerPacket119::read_struct(
    std::vector<std::uint8_t>::const_iterator &it,
    const std::vector<std::uint8_t> &data) {
  some_struct ns;
  if (!read_field(ns.field_0, it, data, packet_size))
    return false;
  if (!read_field(ns.field_1, it, data, packet_size))
    return false;
  if (!read_field(ns.field_2, it, data, packet_size))
    return false;
  if (!read_field(ns.field_3, it, data, packet_size))
    return false;
  if (!read_field(ns.field_4, it, data, packet_size))
    return false;
  field_1.push_back(ns);

  return true;
}
std::vector<std::uint8_t> GameServerPacket119::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  std::uint8_t struct_count = static_cast<std::uint8_t>(field_1.size());
  pack_field(struct_count, data);
  for (const auto &ns : field_1) {
    pack_field(ns.field_0, data);
    pack_field(ns.field_1, data);
    pack_field(ns.field_2, data);
    pack_field(ns.field_3, data);
    pack_field(ns.field_4, data);
  }
  return data;
}
GameServerPacket120::GameServerPacket120(const std::vector<std::uint8_t> &data)
    : PacketReader(120) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket120::get_packet_name() const {
  return "GameServerPacket120";
}

std::string GameServerPacket120::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket120"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket120::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket120::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket120::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket120::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket121::GameServerPacket121(const std::vector<std::uint8_t> &data)
    : PacketReader(121) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket121::get_packet_name() const {
  return "GameServerPacket121";
}

std::string GameServerPacket121::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket121"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket121::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket121::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket121::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 8, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket121::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  return data;
}
GameServerPacket122::GameServerPacket122(const std::vector<std::uint8_t> &data)
    : PacketReader(122) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket122::get_packet_name() const {
  return "GameServerPacket122";
}

std::string GameServerPacket122::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket122"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket122::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket122::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket122::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket122::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket123::GameServerPacket123(const std::vector<std::uint8_t> &data)
    : PacketReader(123) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket123::get_packet_name() const {
  return "GameServerPacket123";
}

std::string GameServerPacket123::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket123"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket123::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket123::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket123::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket123::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket124::GameServerPacket124(const std::vector<std::uint8_t> &data)
    : PacketReader(124) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket124::get_packet_name() const {
  return "GameServerPacket124";
}

std::string GameServerPacket124::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket124"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket124::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket124::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket124::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket124::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerDialogButton::GameServerDialogButton(
    const std::vector<std::uint8_t> &data)
    : PacketReader(125) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerDialogButton::get_packet_name() const {
  return "GameServerDialogButton";
}

std::string GameServerDialogButton::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerDialogButton"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerDialogButton::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerDialogButton::get_packet_size() const {
  return packet_size;
}
bool GameServerDialogButton::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 128, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerDialogButton::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerPacket126::GameServerPacket126(const std::vector<std::uint8_t> &data)
    : PacketReader(126) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket126::get_packet_name() const {
  return "GameServerPacket126";
}

std::string GameServerPacket126::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket126"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket126::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket126::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket126::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket126::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerDialogBody::GameServerDialogBody(
    const std::vector<std::uint8_t> &data)
    : PacketReader(127) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerDialogBody::get_packet_name() const {
  return "GameServerDialogBody";
}

std::string GameServerDialogBody::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerDialogBody"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerDialogBody::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerDialogBody::get_packet_size() const {
  return packet_size;
}
bool GameServerDialogBody::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerDialogBody::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerDialogSender::GameServerDialogSender(
    const std::vector<std::uint8_t> &data)
    : PacketReader(128) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerDialogSender::get_packet_name() const {
  return "GameServerDialogSender";
}

std::string GameServerDialogSender::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerDialogSender"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerDialogSender::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerDialogSender::get_packet_size() const {
  return packet_size;
}
bool GameServerDialogSender::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerDialogSender::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket129::GameServerPacket129(const std::vector<std::uint8_t> &data)
    : PacketReader(129) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket129::get_packet_name() const {
  return "GameServerPacket129";
}

std::string GameServerPacket129::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket129"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket129::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket129::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket129::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket129::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerWindowOpen::GameServerWindowOpen(
    const std::vector<std::uint8_t> &data)
    : PacketReader(130) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerWindowOpen::get_packet_name() const {
  return "GameServerWindowOpen";
}

std::string GameServerWindowOpen::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerWindowOpen"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerWindowOpen::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerWindowOpen::get_packet_size() const {
  return packet_size;
}
bool GameServerWindowOpen::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerWindowOpen::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerWindowAddItems::GameServerWindowAddItems(
    const std::vector<std::uint8_t> &data)
    : PacketReader(131) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerWindowAddItems::get_packet_name() const {
  return "GameServerWindowAddItems";
}

std::string GameServerWindowAddItems::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerWindowAddItems"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerWindowAddItems::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerWindowAddItems::get_packet_size() const {
  return packet_size;
}
bool GameServerWindowAddItems::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 16, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerWindowAddItems::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerWindowItemsEnd::GameServerWindowItemsEnd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(132) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerWindowItemsEnd::get_packet_name() const {
  return "GameServerWindowItemsEnd";
}

std::string GameServerWindowItemsEnd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerWindowItemsEnd"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerWindowItemsEnd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerWindowItemsEnd::get_packet_size() const {
  return packet_size;
}
bool GameServerWindowItemsEnd::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerWindowItemsEnd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerWindowItemStreamEnd::GameServerWindowItemStreamEnd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(133) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerWindowItemStreamEnd::get_packet_name() const {
  return "GameServerWindowItemStreamEnd";
}

std::string GameServerWindowItemStreamEnd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerWindowItemStreamEnd"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerWindowItemStreamEnd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerWindowItemStreamEnd::get_packet_size() const {
  return packet_size;
}
bool GameServerWindowItemStreamEnd::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerWindowItemStreamEnd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket134::GameServerPacket134(const std::vector<std::uint8_t> &data)
    : PacketReader(134) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket134::get_packet_name() const {
  return "GameServerPacket134";
}

std::string GameServerPacket134::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket134"
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
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << field_11 << "\n";
  ss << "  field_12: " << field_12 << "\n";
  ss << "  field_13: " << field_13 << "\n";
  ss << "  field_14: " << field_14 << "\n";
  ss << "  field_15: " << field_15 << "\n";
  ss << "  field_16: " << field_16 << "\n";
  ss << "  field_17: " << field_17 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket134::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket134::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket134::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_field(field_11, it, data, packet_size))
    return false;
  if (!read_field(field_12, it, data, packet_size))
    return false;
  if (!read_field(field_13, it, data, packet_size))
    return false;
  if (!read_field(field_14, it, data, packet_size))
    return false;
  if (!read_field(field_15, it, data, packet_size))
    return false;
  if (!read_field(field_16, it, data, packet_size))
    return false;
  if (!read_field(field_17, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket134::pack() const {
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
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_field(field_11, data);
  pack_field(field_12, data);
  pack_field(field_13, data);
  pack_field(field_14, data);
  pack_field(field_15, data);
  pack_field(field_16, data);
  pack_field(field_17, data);
  return data;
}
GameServerPacket135::GameServerPacket135(const std::vector<std::uint8_t> &data)
    : PacketReader(135) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket135::get_packet_name() const {
  return "GameServerPacket135";
}

std::string GameServerPacket135::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket135"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket135::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket135::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket135::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket135::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket136::GameServerPacket136(const std::vector<std::uint8_t> &data)
    : PacketReader(136) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket136::get_packet_name() const {
  return "GameServerPacket136";
}

std::string GameServerPacket136::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket136"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1.x << " " << field_1.y << " " << field_1.z
     << "\n";
  ss << "  field_2: " << field_2.x << " " << field_2.y << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket136::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket136::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket136::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_vec3(field_1, it, data, packet_size))
    return false;
  if (!read_vec2(field_2, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket136::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_vec3(field_1, data);
  pack_vec2(field_2, data);
  return data;
}
GameServerCartographyData::GameServerCartographyData(
    const std::vector<std::uint8_t> &data)
    : PacketReader(137) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerCartographyData::get_packet_name() const {
  return "GameServerCartographyData";
}

std::string GameServerCartographyData::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerCartographyData"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerCartographyData::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerCartographyData::get_packet_size() const {
  return packet_size;
}
bool GameServerCartographyData::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerCartographyData::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerPacket138::GameServerPacket138(const std::vector<std::uint8_t> &data)
    : PacketReader(138) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket138::get_packet_name() const {
  return "GameServerPacket138";
}

std::string GameServerPacket138::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket138"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket138::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket138::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket138::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket138::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket139::GameServerPacket139(const std::vector<std::uint8_t> &data)
    : PacketReader(139) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket139::get_packet_name() const {
  return "GameServerPacket139";
}

std::string GameServerPacket139::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket139"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket139::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket139::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket139::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket139::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket140::GameServerPacket140(const std::vector<std::uint8_t> &data)
    : PacketReader(140) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket140::get_packet_name() const {
  return "GameServerPacket140";
}

std::string GameServerPacket140::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket140"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1.x << " " << field_1.y << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << common::u16string_to_string(field_6) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket140::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket140::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket140::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_vec2(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_field(field_5, it, data, packet_size))
    return false;
  if (!read_string(field_6, 8, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket140::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_vec2(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_string(field_6, data);
  return data;
}
GameServerPacket141::GameServerPacket141(const std::vector<std::uint8_t> &data)
    : PacketReader(141) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket141::get_packet_name() const {
  return "GameServerPacket141";
}

std::string GameServerPacket141::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket141"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket141::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket141::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket141::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket141::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket142::GameServerPacket142(const std::vector<std::uint8_t> &data)
    : PacketReader(142) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket142::get_packet_name() const {
  return "GameServerPacket142";
}

std::string GameServerPacket142::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket142"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket142::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket142::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket142::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket142::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket143::GameServerPacket143(const std::vector<std::uint8_t> &data)
    : PacketReader(143) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket143::get_packet_name() const {
  return "GameServerPacket143";
}

std::string GameServerPacket143::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket143"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket143::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket143::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket143::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket143::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerCompassDrawing::GameServerCompassDrawing(
    const std::vector<std::uint8_t> &data)
    : PacketReader(144) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerCompassDrawing::get_packet_name() const {
  return "GameServerCompassDrawing";
}

std::string GameServerCompassDrawing::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerCompassDrawing"
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
std::vector<std::uint8_t> GameServerCompassDrawing::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerCompassDrawing::get_packet_size() const {
  return packet_size;
}
bool GameServerCompassDrawing::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_array(field_2, 16, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerCompassDrawing::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_array(field_2, data);
  return data;
}
GameServerPacket145::GameServerPacket145(const std::vector<std::uint8_t> &data)
    : PacketReader(145) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket145::get_packet_name() const {
  return "GameServerPacket145";
}

std::string GameServerPacket145::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket145"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket145::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket145::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket145::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket145::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket146::GameServerPacket146(const std::vector<std::uint8_t> &data)
    : PacketReader(146) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket146::get_packet_name() const {
  return "GameServerPacket146";
}

std::string GameServerPacket146::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket146"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket146::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket146::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket146::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket146::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerMapsUnlocked::GameServerMapsUnlocked(
    const std::vector<std::uint8_t> &data)
    : PacketReader(147) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerMapsUnlocked::get_packet_name() const {
  return "GameServerMapsUnlocked";
}

std::string GameServerMapsUnlocked::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerMapsUnlocked"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
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
  return ss.str();
}
std::vector<std::uint8_t> GameServerMapsUnlocked::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerMapsUnlocked::get_packet_size() const {
  return packet_size;
}
bool GameServerMapsUnlocked::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 32, it, data, packet_size))
    return false;
  if (!read_array(field_1, 32, it, data, packet_size))
    return false;
  if (!read_array(field_2, 32, it, data, packet_size))
    return false;
  if (!read_array(field_3, 32, it, data, packet_size))
    return false;
  if (!read_array(field_4, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerMapsUnlocked::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  pack_array(field_1, data);
  pack_array(field_2, data);
  pack_array(field_3, data);
  pack_array(field_4, data);
  return data;
}
GameServerPacket148::GameServerPacket148(const std::vector<std::uint8_t> &data)
    : PacketReader(148) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket148::get_packet_name() const {
  return "GameServerPacket148";
}

std::string GameServerPacket148::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket148"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket148::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket148::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket148::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket148::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket149::GameServerPacket149(const std::vector<std::uint8_t> &data)
    : PacketReader(149) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket149::get_packet_name() const {
  return "GameServerPacket149";
}

std::string GameServerPacket149::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket149"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket149::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket149::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket149::parse(const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameServerPacket149::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  return data;
}
GameServerPacket150::GameServerPacket150(const std::vector<std::uint8_t> &data)
    : PacketReader(150) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket150::get_packet_name() const {
  return "GameServerPacket150";
}

std::string GameServerPacket150::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket150"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket150::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket150::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket150::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 128, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket150::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerPacket151::GameServerPacket151(const std::vector<std::uint8_t> &data)
    : PacketReader(151) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket151::get_packet_name() const {
  return "GameServerPacket151";
}

std::string GameServerPacket151::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket151"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket151::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket151::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket151::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket151::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerPacket152::GameServerPacket152(const std::vector<std::uint8_t> &data)
    : PacketReader(152) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket152::get_packet_name() const {
  return "GameServerPacket152";
}

std::string GameServerPacket152::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket152"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket152::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket152::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket152::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket152::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerAgentUpdateScale::GameServerAgentUpdateScale(
    const std::vector<std::uint8_t> &data)
    : PacketReader(153) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentUpdateScale::get_packet_name() const {
  return "GameServerAgentUpdateScale";
}

std::string GameServerAgentUpdateScale::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentUpdateScale"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentUpdateScale::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentUpdateScale::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentUpdateScale::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentUpdateScale::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerAgentUpdateNPCName::GameServerAgentUpdateNPCName(
    const std::vector<std::uint8_t> &data)
    : PacketReader(154) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentUpdateNPCName::get_packet_name() const {
  return "GameServerAgentUpdateNPCName";
}

std::string GameServerAgentUpdateNPCName::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentUpdateNPCName"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentUpdateNPCName::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentUpdateNPCName::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentUpdateNPCName::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentUpdateNPCName::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerPacket155::GameServerPacket155(const std::vector<std::uint8_t> &data)
    : PacketReader(155) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket155::get_packet_name() const {
  return "GameServerPacket155";
}

std::string GameServerPacket155::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket155"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket155::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket155::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket155::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket155::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket156::GameServerPacket156(const std::vector<std::uint8_t> &data)
    : PacketReader(156) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket156::get_packet_name() const {
  return "GameServerPacket156";
}

std::string GameServerPacket156::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket156"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket156::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket156::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket156::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket156::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerAgentDisplayDialog::GameServerAgentDisplayDialog(
    const std::vector<std::uint8_t> &data)
    : PacketReader(157) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentDisplayDialog::get_packet_name() const {
  return "GameServerAgentDisplayDialog";
}

std::string GameServerAgentDisplayDialog::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentDisplayDialog"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentDisplayDialog::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentDisplayDialog::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentDisplayDialog::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 32, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_string(field_3, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentDisplayDialog::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_field(field_2, data);
  pack_string(field_3, data);
  return data;
}
GameServerAgentAttrUpdateInt::GameServerAgentAttrUpdateInt(
    const std::vector<std::uint8_t> &data)
    : PacketReader(158) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentAttrUpdateInt::get_packet_name() const {
  return "GameServerAgentAttrUpdateInt";
}

std::string GameServerAgentAttrUpdateInt::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentAttrUpdateInt"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentAttrUpdateInt::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentAttrUpdateInt::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentAttrUpdateInt::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerAgentAttrUpdateInt::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerAgentAttrUpdateIntTarget::GameServerAgentAttrUpdateIntTarget(
    const std::vector<std::uint8_t> &data)
    : PacketReader(159) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentAttrUpdateIntTarget::get_packet_name() const {
  return "GameServerAgentAttrUpdateIntTarget";
}

std::string
GameServerAgentAttrUpdateIntTarget::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentAttrUpdateIntTarget"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentAttrUpdateIntTarget::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentAttrUpdateIntTarget::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentAttrUpdateIntTarget::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerAgentAttrUpdateIntTarget::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerAgentAttrPlayEffect::GameServerAgentAttrPlayEffect(
    const std::vector<std::uint8_t> &data)
    : PacketReader(160) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentAttrPlayEffect::get_packet_name() const {
  return "GameServerAgentAttrPlayEffect";
}

std::string GameServerAgentAttrPlayEffect::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentAttrPlayEffect"
     << "\n";
  ss << "  field_0: " << field_0.x << " " << field_0.y << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentAttrPlayEffect::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentAttrPlayEffect::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentAttrPlayEffect::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_vec2(field_0, it, data, packet_size))
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

  return true;
}
std::vector<std::uint8_t> GameServerAgentAttrPlayEffect::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_vec2(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  return data;
}
GameServerAgentAttrUpdateFloat::GameServerAgentAttrUpdateFloat(
    const std::vector<std::uint8_t> &data)
    : PacketReader(161) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentAttrUpdateFloat::get_packet_name() const {
  return "GameServerAgentAttrUpdateFloat";
}

std::string GameServerAgentAttrUpdateFloat::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentAttrUpdateFloat"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentAttrUpdateFloat::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentAttrUpdateFloat::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentAttrUpdateFloat::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerAgentAttrUpdateFloat::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerAgentAttrUpdateFloatTarget::GameServerAgentAttrUpdateFloatTarget(
    const std::vector<std::uint8_t> &data)
    : PacketReader(162) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentAttrUpdateFloatTarget::get_packet_name() const {
  return "GameServerAgentAttrUpdateFloatTarget";
}

std::string
GameServerAgentAttrUpdateFloatTarget::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentAttrUpdateFloatTarget"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentAttrUpdateFloatTarget::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentAttrUpdateFloatTarget::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentAttrUpdateFloatTarget::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerAgentAttrUpdateFloatTarget::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerAgentProjectileLaunched::GameServerAgentProjectileLaunched(
    const std::vector<std::uint8_t> &data)
    : PacketReader(163) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentProjectileLaunched::get_packet_name() const {
  return "GameServerAgentProjectileLaunched";
}

std::string GameServerAgentProjectileLaunched::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentProjectileLaunched"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1.x << " " << field_1.y << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentProjectileLaunched::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentProjectileLaunched::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentProjectileLaunched::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_vec2(field_1, it, data, packet_size))
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

  return true;
}
std::vector<std::uint8_t> GameServerAgentProjectileLaunched::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_vec2(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_field(field_6, data);
  return data;
}
GameServerSpeechBubble::GameServerSpeechBubble(
    const std::vector<std::uint8_t> &data)
    : PacketReader(164) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSpeechBubble::get_packet_name() const {
  return "GameServerSpeechBubble";
}

std::string GameServerSpeechBubble::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSpeechBubble"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerSpeechBubble::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSpeechBubble::get_packet_size() const {
  return packet_size;
}
bool GameServerSpeechBubble::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerSpeechBubble::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerAgentUpdateProfession::GameServerAgentUpdateProfession(
    const std::vector<std::uint8_t> &data)
    : PacketReader(165) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentUpdateProfession::get_packet_name() const {
  return "GameServerAgentUpdateProfession";
}

std::string GameServerAgentUpdateProfession::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentUpdateProfession"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentUpdateProfession::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentUpdateProfession::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentUpdateProfession::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerAgentUpdateProfession::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket166::GameServerPacket166(const std::vector<std::uint8_t> &data)
    : PacketReader(166) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket166::get_packet_name() const {
  return "GameServerPacket166";
}

std::string GameServerPacket166::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket166"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket166::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket166::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket166::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket166::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket167::GameServerPacket167(const std::vector<std::uint8_t> &data)
    : PacketReader(167) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket167::get_packet_name() const {
  return "GameServerPacket167";
}

std::string GameServerPacket167::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket167"
     << "\n";
  ss << "  field_0: " << field_0.x << " " << field_0.y << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket167::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket167::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket167::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_vec2(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket167::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_vec2(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket168::GameServerPacket168(const std::vector<std::uint8_t> &data)
    : PacketReader(168) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket168::get_packet_name() const {
  return "GameServerPacket168";
}

std::string GameServerPacket168::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket168"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket168::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket168::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket168::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket168::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerAgentCreateNPC::GameServerAgentCreateNPC(
    const std::vector<std::uint8_t> &data)
    : PacketReader(169) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentCreateNPC::get_packet_name() const {
  return "GameServerAgentCreateNPC";
}

std::string GameServerAgentCreateNPC::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentCreateNPC"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerAgentCreateNPC::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentCreateNPC::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentCreateNPC::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerAgentCreateNPC::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket170::GameServerPacket170(const std::vector<std::uint8_t> &data)
    : PacketReader(170) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket170::get_packet_name() const {
  return "GameServerPacket170";
}

std::string GameServerPacket170::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket170"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket170::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket170::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket170::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket170::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket171::GameServerPacket171(const std::vector<std::uint8_t> &data)
    : PacketReader(171) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket171::get_packet_name() const {
  return "GameServerPacket171";
}

std::string GameServerPacket171::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket171"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket171::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket171::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket171::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket171::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket172::GameServerPacket172(const std::vector<std::uint8_t> &data)
    : PacketReader(172) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket172::get_packet_name() const {
  return "GameServerPacket172";
}

std::string GameServerPacket172::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket172"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket172::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket172::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket172::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket172::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerUpdateAgentModel::GameServerUpdateAgentModel(
    const std::vector<std::uint8_t> &data)
    : PacketReader(173) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerUpdateAgentModel::get_packet_name() const {
  return "GameServerUpdateAgentModel";
}

std::string GameServerUpdateAgentModel::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerUpdateAgentModel"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerUpdateAgentModel::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerUpdateAgentModel::get_packet_size() const {
  return packet_size;
}
bool GameServerUpdateAgentModel::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerUpdateAgentModel::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket174::GameServerPacket174(const std::vector<std::uint8_t> &data)
    : PacketReader(174) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket174::get_packet_name() const {
  return "GameServerPacket174";
}

std::string GameServerPacket174::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket174"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket174::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket174::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket174::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket174::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerUpdateAgentPartysize::GameServerUpdateAgentPartysize(
    const std::vector<std::uint8_t> &data)
    : PacketReader(175) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerUpdateAgentPartysize::get_packet_name() const {
  return "GameServerUpdateAgentPartysize";
}

std::string GameServerUpdateAgentPartysize::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerUpdateAgentPartysize"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerUpdateAgentPartysize::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerUpdateAgentPartysize::get_packet_size() const {
  return packet_size;
}
bool GameServerUpdateAgentPartysize::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerUpdateAgentPartysize::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket176::GameServerPacket176(const std::vector<std::uint8_t> &data)
    : PacketReader(176) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket176::get_packet_name() const {
  return "GameServerPacket176";
}

std::string GameServerPacket176::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket176"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket176::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket176::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket176::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket176::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket177::GameServerPacket177(const std::vector<std::uint8_t> &data)
    : PacketReader(177) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket177::get_packet_name() const {
  return "GameServerPacket177";
}

std::string GameServerPacket177::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket177"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket177::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket177::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket177::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 32, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_field(field_5, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket177::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  return data;
}
GameServerPacket178::GameServerPacket178(const std::vector<std::uint8_t> &data)
    : PacketReader(178) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket178::get_packet_name() const {
  return "GameServerPacket178";
}

std::string GameServerPacket178::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket178"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket178::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket178::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket178::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket178::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket179::GameServerPacket179(const std::vector<std::uint8_t> &data)
    : PacketReader(179) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket179::get_packet_name() const {
  return "GameServerPacket179";
}

std::string GameServerPacket179::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket179"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket179::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket179::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket179::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket179::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerPacket180::GameServerPacket180(const std::vector<std::uint8_t> &data)
    : PacketReader(180) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket180::get_packet_name() const {
  return "GameServerPacket180";
}

std::string GameServerPacket180::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket180"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket180::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket180::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket180::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 256, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket180::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerPlayerUnlockedProfession::GameServerPlayerUnlockedProfession(
    const std::vector<std::uint8_t> &data)
    : PacketReader(181) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPlayerUnlockedProfession::get_packet_name() const {
  return "GameServerPlayerUnlockedProfession";
}

std::string
GameServerPlayerUnlockedProfession::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPlayerUnlockedProfession"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPlayerUnlockedProfession::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPlayerUnlockedProfession::get_packet_size() const {
  return packet_size;
}
bool GameServerPlayerUnlockedProfession::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPlayerUnlockedProfession::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPlayerUpdateProfession::GameServerPlayerUpdateProfession(
    const std::vector<std::uint8_t> &data)
    : PacketReader(182) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPlayerUpdateProfession::get_packet_name() const {
  return "GameServerPlayerUpdateProfession";
}

std::string GameServerPlayerUpdateProfession::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPlayerUpdateProfession"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPlayerUpdateProfession::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPlayerUpdateProfession::get_packet_size() const {
  return packet_size;
}
bool GameServerPlayerUpdateProfession::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPlayerUpdateProfession::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerPacket183::GameServerPacket183(const std::vector<std::uint8_t> &data)
    : PacketReader(183) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket183::get_packet_name() const {
  return "GameServerPacket183";
}

std::string GameServerPacket183::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket183"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket183::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket183::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket183::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket183::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerMissionInfoboxAdd::GameServerMissionInfoboxAdd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(184) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerMissionInfoboxAdd::get_packet_name() const {
  return "GameServerMissionInfoboxAdd";
}

std::string GameServerMissionInfoboxAdd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerMissionInfoboxAdd"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerMissionInfoboxAdd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerMissionInfoboxAdd::get_packet_size() const {
  return packet_size;
}
bool GameServerMissionInfoboxAdd::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 128, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerMissionInfoboxAdd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerMissionStreamStart::GameServerMissionStreamStart(
    const std::vector<std::uint8_t> &data)
    : PacketReader(185) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerMissionStreamStart::get_packet_name() const {
  return "GameServerMissionStreamStart";
}

std::string GameServerMissionStreamStart::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerMissionStreamStart"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerMissionStreamStart::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerMissionStreamStart::get_packet_size() const {
  return packet_size;
}
bool GameServerMissionStreamStart::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerMissionStreamStart::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerMissionObjectiveAdd::GameServerMissionObjectiveAdd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(186) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerMissionObjectiveAdd::get_packet_name() const {
  return "GameServerMissionObjectiveAdd";
}

std::string GameServerMissionObjectiveAdd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerMissionObjectiveAdd"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerMissionObjectiveAdd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerMissionObjectiveAdd::get_packet_size() const {
  return packet_size;
}
bool GameServerMissionObjectiveAdd::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 128, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerMissionObjectiveAdd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  return data;
}
GameServerMissionObjectiveComplete::GameServerMissionObjectiveComplete(
    const std::vector<std::uint8_t> &data)
    : PacketReader(187) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerMissionObjectiveComplete::get_packet_name() const {
  return "GameServerMissionObjectiveComplete";
}

std::string
GameServerMissionObjectiveComplete::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerMissionObjectiveComplete"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerMissionObjectiveComplete::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerMissionObjectiveComplete::get_packet_size() const {
  return packet_size;
}
bool GameServerMissionObjectiveComplete::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerMissionObjectiveComplete::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerMissionObjectiveUpdateString::GameServerMissionObjectiveUpdateString(
    const std::vector<std::uint8_t> &data)
    : PacketReader(188) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerMissionObjectiveUpdateString::get_packet_name() const {
  return "GameServerMissionObjectiveUpdateString";
}

std::string
GameServerMissionObjectiveUpdateString::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerMissionObjectiveUpdateString"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerMissionObjectiveUpdateString::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerMissionObjectiveUpdateString::get_packet_size() const {
  return packet_size;
}
bool GameServerMissionObjectiveUpdateString::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 128, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerMissionObjectiveUpdateString::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerPacket189::GameServerPacket189(const std::vector<std::uint8_t> &data)
    : PacketReader(189) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket189::get_packet_name() const {
  return "GameServerPacket189";
}

std::string GameServerPacket189::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket189"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket189::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket189::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket189::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket189::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket190::GameServerPacket190(const std::vector<std::uint8_t> &data)
    : PacketReader(190) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket190::get_packet_name() const {
  return "GameServerPacket190";
}

std::string GameServerPacket190::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket190"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket190::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket190::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket190::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket190::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerPacket191::GameServerPacket191(const std::vector<std::uint8_t> &data)
    : PacketReader(191) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket191::get_packet_name() const {
  return "GameServerPacket191";
}

std::string GameServerPacket191::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket191"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket191::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket191::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket191::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_string(field_3, 128, it, data, packet_size))
    return false;
  if (!read_string(field_4, 128, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket191::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_string(field_3, data);
  pack_string(field_4, data);
  return data;
}
GameServerPacket192::GameServerPacket192(const std::vector<std::uint8_t> &data)
    : PacketReader(192) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket192::get_packet_name() const {
  return "GameServerPacket192";
}

std::string GameServerPacket192::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket192"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket192::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket192::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket192::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket192::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket193::GameServerPacket193(const std::vector<std::uint8_t> &data)
    : PacketReader(193) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket193::get_packet_name() const {
  return "GameServerPacket193";
}

std::string GameServerPacket193::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket193"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket193::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket193::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket193::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket193::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerWindowMerchant::GameServerWindowMerchant(
    const std::vector<std::uint8_t> &data)
    : PacketReader(194) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerWindowMerchant::get_packet_name() const {
  return "GameServerWindowMerchant";
}

std::string GameServerWindowMerchant::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerWindowMerchant"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerWindowMerchant::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerWindowMerchant::get_packet_size() const {
  return packet_size;
}
bool GameServerWindowMerchant::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerWindowMerchant::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerWindowOwner::GameServerWindowOwner(
    const std::vector<std::uint8_t> &data)
    : PacketReader(195) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerWindowOwner::get_packet_name() const {
  return "GameServerWindowOwner";
}

std::string GameServerWindowOwner::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerWindowOwner"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerWindowOwner::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerWindowOwner::get_packet_size() const {
  return packet_size;
}
bool GameServerWindowOwner::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerWindowOwner::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket196::GameServerPacket196(const std::vector<std::uint8_t> &data)
    : PacketReader(196) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket196::get_packet_name() const {
  return "GameServerPacket196";
}

std::string GameServerPacket196::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket196"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket196::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket196::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket196::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket196::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerTransactionReject::GameServerTransactionReject(
    const std::vector<std::uint8_t> &data)
    : PacketReader(197) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTransactionReject::get_packet_name() const {
  return "GameServerTransactionReject";
}

std::string GameServerTransactionReject::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTransactionReject"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTransactionReject::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTransactionReject::get_packet_size() const {
  return packet_size;
}
bool GameServerTransactionReject::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTransactionReject::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket198::GameServerPacket198(const std::vector<std::uint8_t> &data)
    : PacketReader(198) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket198::get_packet_name() const {
  return "GameServerPacket198";
}

std::string GameServerPacket198::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket198"
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
std::vector<std::uint8_t> GameServerPacket198::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket198::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket198::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_array(field_2, 16, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket198::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_array(field_2, data);
  return data;
}
GameServerPacket199::GameServerPacket199(const std::vector<std::uint8_t> &data)
    : PacketReader(199) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket199::get_packet_name() const {
  return "GameServerPacket199";
}

std::string GameServerPacket199::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket199"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket199::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket199::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket199::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket199::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket200::GameServerPacket200(const std::vector<std::uint8_t> &data)
    : PacketReader(200) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket200::get_packet_name() const {
  return "GameServerPacket200";
}

std::string GameServerPacket200::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket200"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket200::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket200::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket200::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket200::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket201::GameServerPacket201(const std::vector<std::uint8_t> &data)
    : PacketReader(201) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket201::get_packet_name() const {
  return "GameServerPacket201";
}

std::string GameServerPacket201::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket201"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket201::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket201::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket201::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket201::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket202::GameServerPacket202(const std::vector<std::uint8_t> &data)
    : PacketReader(202) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket202::get_packet_name() const {
  return "GameServerPacket202";
}

std::string GameServerPacket202::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket202"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket202::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket202::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket202::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket202::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerTransactionDone::GameServerTransactionDone(
    const std::vector<std::uint8_t> &data)
    : PacketReader(203) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTransactionDone::get_packet_name() const {
  return "GameServerTransactionDone";
}

std::string GameServerTransactionDone::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTransactionDone"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTransactionDone::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTransactionDone::get_packet_size() const {
  return packet_size;
}
bool GameServerTransactionDone::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTransactionDone::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket204::GameServerPacket204(const std::vector<std::uint8_t> &data)
    : PacketReader(204) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket204::get_packet_name() const {
  return "GameServerPacket204";
}

std::string GameServerPacket204::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket204"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket204::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket204::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket204::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket204::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerPacket205::GameServerPacket205(const std::vector<std::uint8_t> &data)
    : PacketReader(205) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket205::get_packet_name() const {
  return "GameServerPacket205";
}

std::string GameServerPacket205::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket205"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket205::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket205::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket205::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket205::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket206::GameServerPacket206(const std::vector<std::uint8_t> &data)
    : PacketReader(206) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket206::get_packet_name() const {
  return "GameServerPacket206";
}

std::string GameServerPacket206::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket206"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket206::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket206::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket206::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket206::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket207::GameServerPacket207(const std::vector<std::uint8_t> &data)
    : PacketReader(207) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket207::get_packet_name() const {
  return "GameServerPacket207";
}

std::string GameServerPacket207::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket207"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket207::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket207::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket207::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket207::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket208::GameServerPacket208(const std::vector<std::uint8_t> &data)
    : PacketReader(208) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket208::get_packet_name() const {
  return "GameServerPacket208";
}

std::string GameServerPacket208::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket208"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket208::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket208::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket208::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket208::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerPacket209::GameServerPacket209(const std::vector<std::uint8_t> &data)
    : PacketReader(209) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket209::get_packet_name() const {
  return "GameServerPacket209";
}

std::string GameServerPacket209::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket209"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket209::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket209::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket209::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket209::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket210::GameServerPacket210(const std::vector<std::uint8_t> &data)
    : PacketReader(210) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket210::get_packet_name() const {
  return "GameServerPacket210";
}

std::string GameServerPacket210::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket210"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket210::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket210::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket210::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 128, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket210::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerPacket211::GameServerPacket211(const std::vector<std::uint8_t> &data)
    : PacketReader(211) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket211::get_packet_name() const {
  return "GameServerPacket211";
}

std::string GameServerPacket211::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket211"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket211::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket211::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket211::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket211::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket212::GameServerPacket212(const std::vector<std::uint8_t> &data)
    : PacketReader(212) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket212::get_packet_name() const {
  return "GameServerPacket212";
}

std::string GameServerPacket212::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket212"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket212::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket212::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket212::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket212::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket213::GameServerPacket213(const std::vector<std::uint8_t> &data)
    : PacketReader(213) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket213::get_packet_name() const {
  return "GameServerPacket213";
}

std::string GameServerPacket213::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket213"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket213::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket213::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket213::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket213::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket214::GameServerPacket214(const std::vector<std::uint8_t> &data)
    : PacketReader(214) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket214::get_packet_name() const {
  return "GameServerPacket214";
}

std::string GameServerPacket214::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket214"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket214::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket214::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket214::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 8, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket214::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerPacket215::GameServerPacket215(const std::vector<std::uint8_t> &data)
    : PacketReader(215) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket215::get_packet_name() const {
  return "GameServerPacket215";
}

std::string GameServerPacket215::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket215"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket215::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket215::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket215::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 4, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket215::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerSkillbarUpdateSkill::GameServerSkillbarUpdateSkill(
    const std::vector<std::uint8_t> &data)
    : PacketReader(216) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSkillbarUpdateSkill::get_packet_name() const {
  return "GameServerSkillbarUpdateSkill";
}

std::string GameServerSkillbarUpdateSkill::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSkillbarUpdateSkill"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerSkillbarUpdateSkill::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSkillbarUpdateSkill::get_packet_size() const {
  return packet_size;
}
bool GameServerSkillbarUpdateSkill::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerSkillbarUpdateSkill::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerSkillbarUpdate::GameServerSkillbarUpdate(
    const std::vector<std::uint8_t> &data)
    : PacketReader(217) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSkillbarUpdate::get_packet_name() const {
  return "GameServerSkillbarUpdate";
}

std::string GameServerSkillbarUpdate::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSkillbarUpdate"
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
  return ss.str();
}
std::vector<std::uint8_t> GameServerSkillbarUpdate::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSkillbarUpdate::get_packet_size() const {
  return packet_size;
}
bool GameServerSkillbarUpdate::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_array(field_1, 8, it, data, packet_size))
    return false;
  if (!read_array(field_2, 8, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerSkillbarUpdate::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_array(field_1, data);
  pack_array(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerSkillsUnlocked::GameServerSkillsUnlocked(
    const std::vector<std::uint8_t> &data)
    : PacketReader(218) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSkillsUnlocked::get_packet_name() const {
  return "GameServerSkillsUnlocked";
}

std::string GameServerSkillsUnlocked::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSkillsUnlocked"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerSkillsUnlocked::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSkillsUnlocked::get_packet_size() const {
  return packet_size;
}
bool GameServerSkillsUnlocked::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 128, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerSkillsUnlocked::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerSkillAddToWindowCount::GameServerSkillAddToWindowCount(
    const std::vector<std::uint8_t> &data)
    : PacketReader(219) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSkillAddToWindowCount::get_packet_name() const {
  return "GameServerSkillAddToWindowCount";
}

std::string GameServerSkillAddToWindowCount::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSkillAddToWindowCount"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerSkillAddToWindowCount::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSkillAddToWindowCount::get_packet_size() const {
  return packet_size;
}
bool GameServerSkillAddToWindowCount::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerSkillAddToWindowCount::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket220::GameServerPacket220(const std::vector<std::uint8_t> &data)
    : PacketReader(220) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket220::get_packet_name() const {
  return "GameServerPacket220";
}

std::string GameServerPacket220::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket220"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket220::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket220::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket220::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket220::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket221::GameServerPacket221(const std::vector<std::uint8_t> &data)
    : PacketReader(221) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket221::get_packet_name() const {
  return "GameServerPacket221";
}

std::string GameServerPacket221::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket221"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket221::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket221::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket221::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket221::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket222::GameServerPacket222(const std::vector<std::uint8_t> &data)
    : PacketReader(222) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket222::get_packet_name() const {
  return "GameServerPacket222";
}

std::string GameServerPacket222::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket222"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket222::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket222::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket222::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket222::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerSkillAddToWindowsData::GameServerSkillAddToWindowsData(
    const std::vector<std::uint8_t> &data)
    : PacketReader(223) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSkillAddToWindowsData::get_packet_name() const {
  return "GameServerSkillAddToWindowsData";
}

std::string GameServerSkillAddToWindowsData::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSkillAddToWindowsData"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerSkillAddToWindowsData::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSkillAddToWindowsData::get_packet_size() const {
  return packet_size;
}
bool GameServerSkillAddToWindowsData::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_array(field_1, 16, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerSkillAddToWindowsData::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_array(field_1, data);
  return data;
}
GameServerSkillAddToWindowsEnd::GameServerSkillAddToWindowsEnd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(224) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSkillAddToWindowsEnd::get_packet_name() const {
  return "GameServerSkillAddToWindowsEnd";
}

std::string GameServerSkillAddToWindowsEnd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSkillAddToWindowsEnd"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerSkillAddToWindowsEnd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSkillAddToWindowsEnd::get_packet_size() const {
  return packet_size;
}
bool GameServerSkillAddToWindowsEnd::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerSkillAddToWindowsEnd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerSkillInterupted::GameServerSkillInterupted(
    const std::vector<std::uint8_t> &data)
    : PacketReader(225) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSkillInterupted::get_packet_name() const {
  return "GameServerSkillInterupted";
}

std::string GameServerSkillInterupted::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSkillInterupted"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerSkillInterupted::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSkillInterupted::get_packet_size() const {
  return packet_size;
}
bool GameServerSkillInterupted::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerSkillInterupted::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerSkillActivatedOrCanceled::GameServerSkillActivatedOrCanceled(
    const std::vector<std::uint8_t> &data)
    : PacketReader(226) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSkillActivatedOrCanceled::get_packet_name() const {
  return "GameServerSkillActivatedOrCanceled";
}

std::string
GameServerSkillActivatedOrCanceled::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSkillActivatedOrCanceled"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerSkillActivatedOrCanceled::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSkillActivatedOrCanceled::get_packet_size() const {
  return packet_size;
}
bool GameServerSkillActivatedOrCanceled::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerSkillActivatedOrCanceled::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerSkillActivate::GameServerSkillActivate(
    const std::vector<std::uint8_t> &data)
    : PacketReader(227) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSkillActivate::get_packet_name() const {
  return "GameServerSkillActivate";
}

std::string GameServerSkillActivate::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSkillActivate"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerSkillActivate::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSkillActivate::get_packet_size() const {
  return packet_size;
}
bool GameServerSkillActivate::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerSkillActivate::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerSkillRecharge::GameServerSkillRecharge(
    const std::vector<std::uint8_t> &data)
    : PacketReader(228) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSkillRecharge::get_packet_name() const {
  return "GameServerSkillRecharge";
}

std::string GameServerSkillRecharge::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSkillRecharge"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerSkillRecharge::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSkillRecharge::get_packet_size() const {
  return packet_size;
}
bool GameServerSkillRecharge::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerSkillRecharge::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerSkillRecharged::GameServerSkillRecharged(
    const std::vector<std::uint8_t> &data)
    : PacketReader(229) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSkillRecharged::get_packet_name() const {
  return "GameServerSkillRecharged";
}

std::string GameServerSkillRecharged::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSkillRecharged"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerSkillRecharged::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSkillRecharged::get_packet_size() const {
  return packet_size;
}
bool GameServerSkillRecharged::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerSkillRecharged::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket230::GameServerPacket230(const std::vector<std::uint8_t> &data)
    : PacketReader(230) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket230::get_packet_name() const {
  return "GameServerPacket230";
}

std::string GameServerPacket230::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket230"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket230::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket230::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket230::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket230::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket231::GameServerPacket231(const std::vector<std::uint8_t> &data)
    : PacketReader(231) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket231::get_packet_name() const {
  return "GameServerPacket231";
}

std::string GameServerPacket231::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket231"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket231::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket231::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket231::parse(const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameServerPacket231::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  return data;
}
GameServerPlayerAttrSet::GameServerPlayerAttrSet(
    const std::vector<std::uint8_t> &data)
    : PacketReader(232) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPlayerAttrSet::get_packet_name() const {
  return "GameServerPlayerAttrSet";
}

std::string GameServerPlayerAttrSet::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPlayerAttrSet"
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
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << field_11 << "\n";
  ss << "  field_12: " << field_12 << "\n";
  ss << "  field_13: " << field_13 << "\n";
  ss << "  field_14: " << field_14 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPlayerAttrSet::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPlayerAttrSet::get_packet_size() const {
  return packet_size;
}
bool GameServerPlayerAttrSet::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_field(field_11, it, data, packet_size))
    return false;
  if (!read_field(field_12, it, data, packet_size))
    return false;
  if (!read_field(field_13, it, data, packet_size))
    return false;
  if (!read_field(field_14, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPlayerAttrSet::pack() const {
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
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_field(field_11, data);
  pack_field(field_12, data);
  pack_field(field_13, data);
  pack_field(field_14, data);
  return data;
}
GameServerPlayerAttrMaxKurzick::GameServerPlayerAttrMaxKurzick(
    const std::vector<std::uint8_t> &data)
    : PacketReader(233) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPlayerAttrMaxKurzick::get_packet_name() const {
  return "GameServerPlayerAttrMaxKurzick";
}

std::string GameServerPlayerAttrMaxKurzick::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPlayerAttrMaxKurzick"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPlayerAttrMaxKurzick::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPlayerAttrMaxKurzick::get_packet_size() const {
  return packet_size;
}
bool GameServerPlayerAttrMaxKurzick::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPlayerAttrMaxKurzick::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPlayerAttrMaxLuxon::GameServerPlayerAttrMaxLuxon(
    const std::vector<std::uint8_t> &data)
    : PacketReader(234) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPlayerAttrMaxLuxon::get_packet_name() const {
  return "GameServerPlayerAttrMaxLuxon";
}

std::string GameServerPlayerAttrMaxLuxon::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPlayerAttrMaxLuxon"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPlayerAttrMaxLuxon::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPlayerAttrMaxLuxon::get_packet_size() const {
  return packet_size;
}
bool GameServerPlayerAttrMaxLuxon::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPlayerAttrMaxLuxon::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPlayerAttrMaxBalthazar::GameServerPlayerAttrMaxBalthazar(
    const std::vector<std::uint8_t> &data)
    : PacketReader(235) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPlayerAttrMaxBalthazar::get_packet_name() const {
  return "GameServerPlayerAttrMaxBalthazar";
}

std::string GameServerPlayerAttrMaxBalthazar::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPlayerAttrMaxBalthazar"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPlayerAttrMaxBalthazar::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPlayerAttrMaxBalthazar::get_packet_size() const {
  return packet_size;
}
bool GameServerPlayerAttrMaxBalthazar::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPlayerAttrMaxBalthazar::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPlayerAttrMaxImperial::GameServerPlayerAttrMaxImperial(
    const std::vector<std::uint8_t> &data)
    : PacketReader(236) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPlayerAttrMaxImperial::get_packet_name() const {
  return "GameServerPlayerAttrMaxImperial";
}

std::string GameServerPlayerAttrMaxImperial::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPlayerAttrMaxImperial"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPlayerAttrMaxImperial::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPlayerAttrMaxImperial::get_packet_size() const {
  return packet_size;
}
bool GameServerPlayerAttrMaxImperial::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPlayerAttrMaxImperial::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPlayerAttrUpdate::GameServerPlayerAttrUpdate(
    const std::vector<std::uint8_t> &data)
    : PacketReader(237) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPlayerAttrUpdate::get_packet_name() const {
  return "GameServerPlayerAttrUpdate";
}

std::string GameServerPlayerAttrUpdate::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPlayerAttrUpdate"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPlayerAttrUpdate::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPlayerAttrUpdate::get_packet_size() const {
  return packet_size;
}
bool GameServerPlayerAttrUpdate::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPlayerAttrUpdate::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket238::GameServerPacket238(const std::vector<std::uint8_t> &data)
    : PacketReader(238) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket238::get_packet_name() const {
  return "GameServerPacket238";
}

std::string GameServerPacket238::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket238"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket238::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket238::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket238::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket238::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerAgentInitialEffects::GameServerAgentInitialEffects(
    const std::vector<std::uint8_t> &data)
    : PacketReader(239) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentInitialEffects::get_packet_name() const {
  return "GameServerAgentInitialEffects";
}

std::string GameServerAgentInitialEffects::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentInitialEffects"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentInitialEffects::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentInitialEffects::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentInitialEffects::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentInitialEffects::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerAgentUpdateEffects::GameServerAgentUpdateEffects(
    const std::vector<std::uint8_t> &data)
    : PacketReader(240) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerAgentUpdateEffects::get_packet_name() const {
  return "GameServerAgentUpdateEffects";
}

std::string GameServerAgentUpdateEffects::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerAgentUpdateEffects"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerAgentUpdateEffects::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerAgentUpdateEffects::get_packet_size() const {
  return packet_size;
}
bool GameServerAgentUpdateEffects::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerAgentUpdateEffects::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerInstanceLoaded::GameServerInstanceLoaded(
    const std::vector<std::uint8_t> &data)
    : PacketReader(241) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInstanceLoaded::get_packet_name() const {
  return "GameServerInstanceLoaded";
}

std::string GameServerInstanceLoaded::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInstanceLoaded"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerInstanceLoaded::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInstanceLoaded::get_packet_size() const {
  return packet_size;
}
bool GameServerInstanceLoaded::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerInstanceLoaded::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerTitleRankData::GameServerTitleRankData(
    const std::vector<std::uint8_t> &data)
    : PacketReader(242) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTitleRankData::get_packet_name() const {
  return "GameServerTitleRankData";
}

std::string GameServerTitleRankData::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTitleRankData"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTitleRankData::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTitleRankData::get_packet_size() const {
  return packet_size;
}
bool GameServerTitleRankData::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_string(field_3, 8, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTitleRankData::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_string(field_3, data);
  return data;
}
GameServerTitleRankDisplay::GameServerTitleRankDisplay(
    const std::vector<std::uint8_t> &data)
    : PacketReader(243) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTitleRankDisplay::get_packet_name() const {
  return "GameServerTitleRankDisplay";
}

std::string GameServerTitleRankDisplay::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTitleRankDisplay"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTitleRankDisplay::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTitleRankDisplay::get_packet_size() const {
  return packet_size;
}
bool GameServerTitleRankDisplay::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTitleRankDisplay::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket244::GameServerPacket244(const std::vector<std::uint8_t> &data)
    : PacketReader(244) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket244::get_packet_name() const {
  return "GameServerPacket244";
}

std::string GameServerPacket244::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket244"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket244::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket244::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket244::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket244::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerTitleTrackInfo::GameServerTitleTrackInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(245) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTitleTrackInfo::get_packet_name() const {
  return "GameServerTitleTrackInfo";
}

std::string GameServerTitleTrackInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTitleTrackInfo"
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
  ss << "  field_9: " << common::u16string_to_string(field_9) << "\n";
  ss << "  field_10: " << common::u16string_to_string(field_10) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTitleTrackInfo::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTitleTrackInfo::get_packet_size() const {
  return packet_size;
}
bool GameServerTitleTrackInfo::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_string(field_9, 8, it, data, packet_size))
    return false;
  if (!read_string(field_10, 8, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTitleTrackInfo::pack() const {
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
  pack_string(field_9, data);
  pack_string(field_10, data);
  return data;
}
GameServerItemPriceQuote::GameServerItemPriceQuote(
    const std::vector<std::uint8_t> &data)
    : PacketReader(246) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemPriceQuote::get_packet_name() const {
  return "GameServerItemPriceQuote";
}

std::string GameServerItemPriceQuote::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemPriceQuote"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerItemPriceQuote::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemPriceQuote::get_packet_size() const {
  return packet_size;
}
bool GameServerItemPriceQuote::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerItemPriceQuote::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket247::GameServerPacket247(const std::vector<std::uint8_t> &data)
    : PacketReader(247) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket247::get_packet_name() const {
  return "GameServerPacket247";
}

std::string GameServerPacket247::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket247"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket247::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket247::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket247::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket247::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerItemPrices::GameServerItemPrices(
    const std::vector<std::uint8_t> &data)
    : PacketReader(248) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemPrices::get_packet_name() const {
  return "GameServerItemPrices";
}

std::string GameServerItemPrices::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemPrices"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerItemPrices::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemPrices::get_packet_size() const {
  return packet_size;
}
bool GameServerItemPrices::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 16, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerItemPrices::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerVanquishProgress::GameServerVanquishProgress(
    const std::vector<std::uint8_t> &data)
    : PacketReader(249) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerVanquishProgress::get_packet_name() const {
  return "GameServerVanquishProgress";
}

std::string GameServerVanquishProgress::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerVanquishProgress"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerVanquishProgress::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerVanquishProgress::get_packet_size() const {
  return packet_size;
}
bool GameServerVanquishProgress::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerVanquishProgress::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerVanquishComplete::GameServerVanquishComplete(
    const std::vector<std::uint8_t> &data)
    : PacketReader(250) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerVanquishComplete::get_packet_name() const {
  return "GameServerVanquishComplete";
}

std::string GameServerVanquishComplete::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerVanquishComplete"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerVanquishComplete::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerVanquishComplete::get_packet_size() const {
  return packet_size;
}
bool GameServerVanquishComplete::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerVanquishComplete::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket251::GameServerPacket251(const std::vector<std::uint8_t> &data)
    : PacketReader(251) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket251::get_packet_name() const {
  return "GameServerPacket251";
}

std::string GameServerPacket251::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket251"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket251::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket251::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket251::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket251::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket252::GameServerPacket252(const std::vector<std::uint8_t> &data)
    : PacketReader(252) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket252::get_packet_name() const {
  return "GameServerPacket252";
}

std::string GameServerPacket252::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket252"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket252::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket252::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket252::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 32, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket252::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerCinematicSkipEveryone::GameServerCinematicSkipEveryone(
    const std::vector<std::uint8_t> &data)
    : PacketReader(253) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerCinematicSkipEveryone::get_packet_name() const {
  return "GameServerCinematicSkipEveryone";
}

std::string GameServerCinematicSkipEveryone::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerCinematicSkipEveryone"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerCinematicSkipEveryone::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerCinematicSkipEveryone::get_packet_size() const {
  return packet_size;
}
bool GameServerCinematicSkipEveryone::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerCinematicSkipEveryone::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerCinematicSkipCount::GameServerCinematicSkipCount(
    const std::vector<std::uint8_t> &data)
    : PacketReader(254) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerCinematicSkipCount::get_packet_name() const {
  return "GameServerCinematicSkipCount";
}

std::string GameServerCinematicSkipCount::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerCinematicSkipCount"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerCinematicSkipCount::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerCinematicSkipCount::get_packet_size() const {
  return packet_size;
}
bool GameServerCinematicSkipCount::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerCinematicSkipCount::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerCinematicStart::GameServerCinematicStart(
    const std::vector<std::uint8_t> &data)
    : PacketReader(255) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerCinematicStart::get_packet_name() const {
  return "GameServerCinematicStart";
}

std::string GameServerCinematicStart::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerCinematicStart"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerCinematicStart::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerCinematicStart::get_packet_size() const {
  return packet_size;
}
bool GameServerCinematicStart::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerCinematicStart::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket256::GameServerPacket256(const std::vector<std::uint8_t> &data)
    : PacketReader(256) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket256::get_packet_name() const {
  return "GameServerPacket256";
}

std::string GameServerPacket256::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket256"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket256::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket256::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket256::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket256::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerCinematicText::GameServerCinematicText(
    const std::vector<std::uint8_t> &data)
    : PacketReader(257) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerCinematicText::get_packet_name() const {
  return "GameServerCinematicText";
}

std::string GameServerCinematicText::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerCinematicText"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerCinematicText::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerCinematicText::get_packet_size() const {
  return packet_size;
}
bool GameServerCinematicText::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 80, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerCinematicText::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  return data;
}
GameServerCinematicDataEnd::GameServerCinematicDataEnd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(258) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerCinematicDataEnd::get_packet_name() const {
  return "GameServerCinematicDataEnd";
}

std::string GameServerCinematicDataEnd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerCinematicDataEnd"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerCinematicDataEnd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerCinematicDataEnd::get_packet_size() const {
  return packet_size;
}
bool GameServerCinematicDataEnd::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerCinematicDataEnd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerCinematicData::GameServerCinematicData(
    const std::vector<std::uint8_t> &data)
    : PacketReader(259) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerCinematicData::get_packet_name() const {
  return "GameServerCinematicData";
}

std::string GameServerCinematicData::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerCinematicData"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerCinematicData::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerCinematicData::get_packet_size() const {
  return packet_size;
}
bool GameServerCinematicData::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 1024, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerCinematicData::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerCinematicEnd::GameServerCinematicEnd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(260) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerCinematicEnd::get_packet_name() const {
  return "GameServerCinematicEnd";
}

std::string GameServerCinematicEnd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerCinematicEnd"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerCinematicEnd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerCinematicEnd::get_packet_size() const {
  return packet_size;
}
bool GameServerCinematicEnd::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerCinematicEnd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket261::GameServerPacket261(const std::vector<std::uint8_t> &data)
    : PacketReader(261) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket261::get_packet_name() const {
  return "GameServerPacket261";
}

std::string GameServerPacket261::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket261"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket261::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket261::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket261::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket261::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket262::GameServerPacket262(const std::vector<std::uint8_t> &data)
    : PacketReader(262) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket262::get_packet_name() const {
  return "GameServerPacket262";
}

std::string GameServerPacket262::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket262"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket262::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket262::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket262::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_string(field_4, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket262::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_string(field_4, data);
  return data;
}
GameServerPacket263::GameServerPacket263(const std::vector<std::uint8_t> &data)
    : PacketReader(263) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket263::get_packet_name() const {
  return "GameServerPacket263";
}

std::string GameServerPacket263::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket263"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket263::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket263::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket263::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket263::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket264::GameServerPacket264(const std::vector<std::uint8_t> &data)
    : PacketReader(264) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket264::get_packet_name() const {
  return "GameServerPacket264";
}

std::string GameServerPacket264::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket264"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket264::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket264::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket264::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket264::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerSignpostButton::GameServerSignpostButton(
    const std::vector<std::uint8_t> &data)
    : PacketReader(265) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSignpostButton::get_packet_name() const {
  return "GameServerSignpostButton";
}

std::string GameServerSignpostButton::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSignpostButton"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerSignpostButton::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSignpostButton::get_packet_size() const {
  return packet_size;
}
bool GameServerSignpostButton::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 122, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerSignpostButton::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerSignpostBody::GameServerSignpostBody(
    const std::vector<std::uint8_t> &data)
    : PacketReader(266) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSignpostBody::get_packet_name() const {
  return "GameServerSignpostBody";
}

std::string GameServerSignpostBody::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSignpostBody"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerSignpostBody::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSignpostBody::get_packet_size() const {
  return packet_size;
}
bool GameServerSignpostBody::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerSignpostBody::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerSignpostSender::GameServerSignpostSender(
    const std::vector<std::uint8_t> &data)
    : PacketReader(267) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSignpostSender::get_packet_name() const {
  return "GameServerSignpostSender";
}

std::string GameServerSignpostSender::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSignpostSender"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerSignpostSender::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSignpostSender::get_packet_size() const {
  return packet_size;
}
bool GameServerSignpostSender::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerSignpostSender::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket268::GameServerPacket268(const std::vector<std::uint8_t> &data)
    : PacketReader(268) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket268::get_packet_name() const {
  return "GameServerPacket268";
}

std::string GameServerPacket268::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket268"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket268::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket268::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket268::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket268::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerManipulateMapObject::GameServerManipulateMapObject(
    const std::vector<std::uint8_t> &data)
    : PacketReader(269) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerManipulateMapObject::get_packet_name() const {
  return "GameServerManipulateMapObject";
}

std::string GameServerManipulateMapObject::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerManipulateMapObject"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerManipulateMapObject::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerManipulateMapObject::get_packet_size() const {
  return packet_size;
}
bool GameServerManipulateMapObject::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerManipulateMapObject::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket270::GameServerPacket270(const std::vector<std::uint8_t> &data)
    : PacketReader(270) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket270::get_packet_name() const {
  return "GameServerPacket270";
}

std::string GameServerPacket270::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket270"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket270::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket270::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket270::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket270::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket271::GameServerPacket271(const std::vector<std::uint8_t> &data)
    : PacketReader(271) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket271::get_packet_name() const {
  return "GameServerPacket271";
}

std::string GameServerPacket271::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket271"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket271::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket271::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket271::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket271::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerManipulateMapObject2::GameServerManipulateMapObject2(
    const std::vector<std::uint8_t> &data)
    : PacketReader(272) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerManipulateMapObject2::get_packet_name() const {
  return "GameServerManipulateMapObject2";
}

std::string GameServerManipulateMapObject2::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerManipulateMapObject2"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerManipulateMapObject2::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerManipulateMapObject2::get_packet_size() const {
  return packet_size;
}
bool GameServerManipulateMapObject2::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerManipulateMapObject2::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket273::GameServerPacket273(const std::vector<std::uint8_t> &data)
    : PacketReader(273) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket273::get_packet_name() const {
  return "GameServerPacket273";
}

std::string GameServerPacket273::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket273"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket273::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket273::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket273::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket273::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket274::GameServerPacket274(const std::vector<std::uint8_t> &data)
    : PacketReader(274) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket274::get_packet_name() const {
  return "GameServerPacket274";
}

std::string GameServerPacket274::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket274"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket274::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket274::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket274::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket274::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerPacket275::GameServerPacket275(const std::vector<std::uint8_t> &data)
    : PacketReader(275) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket275::get_packet_name() const {
  return "GameServerPacket275";
}

std::string GameServerPacket275::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket275"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket275::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket275::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket275::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket275::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket276::GameServerPacket276(const std::vector<std::uint8_t> &data)
    : PacketReader(276) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket276::get_packet_name() const {
  return "GameServerPacket276";
}

std::string GameServerPacket276::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket276"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket276::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket276::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket276::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket276::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket277::GameServerPacket277(const std::vector<std::uint8_t> &data)
    : PacketReader(277) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket277::get_packet_name() const {
  return "GameServerPacket277";
}

std::string GameServerPacket277::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket277"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket277::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket277::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket277::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_blob(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket277::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_blob(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerPacket278::GameServerPacket278(const std::vector<std::uint8_t> &data)
    : PacketReader(278) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket278::get_packet_name() const {
  return "GameServerPacket278";
}

std::string GameServerPacket278::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket278"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket278::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket278::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket278::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_blob(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket278::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_blob(field_0, data);
  return data;
}
GameServerGuildPlayerRole::GameServerGuildPlayerRole(
    const std::vector<std::uint8_t> &data)
    : PacketReader(279) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGuildPlayerRole::get_packet_name() const {
  return "GameServerGuildPlayerRole";
}

std::string GameServerGuildPlayerRole::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGuildPlayerRole"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerGuildPlayerRole::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGuildPlayerRole::get_packet_size() const {
  return packet_size;
}
bool GameServerGuildPlayerRole::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_blob(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerGuildPlayerRole::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_blob(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket280::GameServerPacket280(const std::vector<std::uint8_t> &data)
    : PacketReader(280) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket280::get_packet_name() const {
  return "GameServerPacket280";
}

std::string GameServerPacket280::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket280"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket280::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket280::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket280::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket280::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerTownAllianceObject::GameServerTownAllianceObject(
    const std::vector<std::uint8_t> &data)
    : PacketReader(281) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTownAllianceObject::get_packet_name() const {
  return "GameServerTownAllianceObject";
}

std::string GameServerTownAllianceObject::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTownAllianceObject"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  ss << "  field_5: " << common::u16string_to_string(field_5) << "\n";
  ss << "  field_6: " << field_6 << "\n";
  ss << "  field_7: " << field_7 << "\n";
  ss << "  field_8: " << field_8 << "\n";
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << field_11 << "\n";
  ss << "  field_12: " << field_12 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerTownAllianceObject::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTownAllianceObject::get_packet_size() const {
  return packet_size;
}
bool GameServerTownAllianceObject::parse(
    const std::vector<std::uint8_t> &data) {
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
  if (!read_string(field_4, 32, it, data, packet_size))
    return false;
  if (!read_string(field_5, 6, it, data, packet_size))
    return false;
  if (!read_field(field_6, it, data, packet_size))
    return false;
  if (!read_field(field_7, it, data, packet_size))
    return false;
  if (!read_field(field_8, it, data, packet_size))
    return false;
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_field(field_11, it, data, packet_size))
    return false;
  if (!read_field(field_12, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTownAllianceObject::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_string(field_4, data);
  pack_string(field_5, data);
  pack_field(field_6, data);
  pack_field(field_7, data);
  pack_field(field_8, data);
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_field(field_11, data);
  pack_field(field_12, data);
  return data;
}
GameServerPacket282::GameServerPacket282(const std::vector<std::uint8_t> &data)
    : PacketReader(282) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket282::get_packet_name() const {
  return "GameServerPacket282";
}

std::string GameServerPacket282::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket282"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket282::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket282::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket282::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket282::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket283::GameServerPacket283(const std::vector<std::uint8_t> &data)
    : PacketReader(283) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket283::get_packet_name() const {
  return "GameServerPacket283";
}

std::string GameServerPacket283::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket283"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket283::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket283::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket283::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket283::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket284::GameServerPacket284(const std::vector<std::uint8_t> &data)
    : PacketReader(284) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket284::get_packet_name() const {
  return "GameServerPacket284";
}

std::string GameServerPacket284::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket284"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket284::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket284::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket284::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket284::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket285::GameServerPacket285(const std::vector<std::uint8_t> &data)
    : PacketReader(285) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket285::get_packet_name() const {
  return "GameServerPacket285";
}

std::string GameServerPacket285::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket285"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket285::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket285::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket285::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket285::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket286::GameServerPacket286(const std::vector<std::uint8_t> &data)
    : PacketReader(286) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket286::get_packet_name() const {
  return "GameServerPacket286";
}

std::string GameServerPacket286::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket286"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket286::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket286::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket286::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket286::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerGuildAllianceInfo::GameServerGuildAllianceInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(287) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGuildAllianceInfo::get_packet_name() const {
  return "GameServerGuildAllianceInfo";
}

std::string GameServerGuildAllianceInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGuildAllianceInfo"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  ss << "  field_7: " << field_7 << "\n";
  ss << "  field_8: " << field_8 << "\n";
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << field_11 << "\n";
  ss << "  field_12: " << field_12 << "\n";
  ss << "  field_13: " << field_13 << "\n";
  ss << "  field_14: " << field_14 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerGuildAllianceInfo::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGuildAllianceInfo::get_packet_size() const {
  return packet_size;
}
bool GameServerGuildAllianceInfo::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_blob(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 32, it, data, packet_size))
    return false;
  if (!read_string(field_3, 6, it, data, packet_size))
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
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_field(field_11, it, data, packet_size))
    return false;
  if (!read_field(field_12, it, data, packet_size))
    return false;
  if (!read_field(field_13, it, data, packet_size))
    return false;
  if (!read_field(field_14, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerGuildAllianceInfo::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_blob(field_1, data);
  pack_string(field_2, data);
  pack_string(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_field(field_6, data);
  pack_field(field_7, data);
  pack_field(field_8, data);
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_field(field_11, data);
  pack_field(field_12, data);
  pack_field(field_13, data);
  pack_field(field_14, data);
  return data;
}
GameServerGuildGeneralInfo::GameServerGuildGeneralInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(288) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGuildGeneralInfo::get_packet_name() const {
  return "GameServerGuildGeneralInfo";
}

std::string GameServerGuildGeneralInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGuildGeneralInfo"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  ss << "  field_7: " << field_7 << "\n";
  ss << "  field_8: " << field_8 << "\n";
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << field_11 << "\n";
  ss << "  field_12: " << field_12 << "\n";
  ss << "  field_13: " << field_13 << "\n";
  ss << "  field_14: " << field_14 << "\n";
  ss << "  field_15: " << field_15 << "\n";
  ss << "  field_16: " << field_16 << "\n";
  ss << "  field_17: " << field_17 << "\n";
  ss << "  field_18: " << field_18 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerGuildGeneralInfo::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGuildGeneralInfo::get_packet_size() const {
  return packet_size;
}
bool GameServerGuildGeneralInfo::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_blob(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 32, it, data, packet_size))
    return false;
  if (!read_string(field_3, 6, it, data, packet_size))
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
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_field(field_11, it, data, packet_size))
    return false;
  if (!read_field(field_12, it, data, packet_size))
    return false;
  if (!read_field(field_13, it, data, packet_size))
    return false;
  if (!read_field(field_14, it, data, packet_size))
    return false;
  if (!read_field(field_15, it, data, packet_size))
    return false;
  if (!read_field(field_16, it, data, packet_size))
    return false;
  if (!read_field(field_17, it, data, packet_size))
    return false;
  if (!read_field(field_18, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerGuildGeneralInfo::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_blob(field_1, data);
  pack_string(field_2, data);
  pack_string(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_field(field_6, data);
  pack_field(field_7, data);
  pack_field(field_8, data);
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_field(field_11, data);
  pack_field(field_12, data);
  pack_field(field_13, data);
  pack_field(field_14, data);
  pack_field(field_15, data);
  pack_field(field_16, data);
  pack_field(field_17, data);
  pack_field(field_18, data);
  return data;
}
GameServerGuildChangeFaction::GameServerGuildChangeFaction(
    const std::vector<std::uint8_t> &data)
    : PacketReader(289) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGuildChangeFaction::get_packet_name() const {
  return "GameServerGuildChangeFaction";
}

std::string GameServerGuildChangeFaction::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGuildChangeFaction"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerGuildChangeFaction::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGuildChangeFaction::get_packet_size() const {
  return packet_size;
}
bool GameServerGuildChangeFaction::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerGuildChangeFaction::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerGuildInviteReceived::GameServerGuildInviteReceived(
    const std::vector<std::uint8_t> &data)
    : PacketReader(290) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGuildInviteReceived::get_packet_name() const {
  return "GameServerGuildInviteReceived";
}

std::string GameServerGuildInviteReceived::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGuildInviteReceived"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerGuildInviteReceived::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGuildInviteReceived::get_packet_size() const {
  return packet_size;
}
bool GameServerGuildInviteReceived::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_blob(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 32, it, data, packet_size))
    return false;
  if (!read_string(field_2, 6, it, data, packet_size))
    return false;
  if (!read_string(field_3, 20, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_field(field_5, it, data, packet_size))
    return false;
  if (!read_field(field_6, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerGuildInviteReceived::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_blob(field_0, data);
  pack_string(field_1, data);
  pack_string(field_2, data);
  pack_string(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_field(field_6, data);
  return data;
}
GameServerPacket291::GameServerPacket291(const std::vector<std::uint8_t> &data)
    : PacketReader(291) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket291::get_packet_name() const {
  return "GameServerPacket291";
}

std::string GameServerPacket291::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket291"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket291::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket291::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket291::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_blob(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket291::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_blob(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket292::GameServerPacket292(const std::vector<std::uint8_t> &data)
    : PacketReader(292) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket292::get_packet_name() const {
  return "GameServerPacket292";
}

std::string GameServerPacket292::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket292"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket292::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket292::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket292::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket292::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket293::GameServerPacket293(const std::vector<std::uint8_t> &data)
    : PacketReader(293) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket293::get_packet_name() const {
  return "GameServerPacket293";
}

std::string GameServerPacket293::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket293"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket293::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket293::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket293::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket293::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerGuildPlayerInfo::GameServerGuildPlayerInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(294) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGuildPlayerInfo::get_packet_name() const {
  return "GameServerGuildPlayerInfo";
}

std::string GameServerGuildPlayerInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGuildPlayerInfo"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  ss << "  field_7: " << field_7 << "\n";
  ss << "  field_8: " << field_8 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerGuildPlayerInfo::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGuildPlayerInfo::get_packet_size() const {
  return packet_size;
}
bool GameServerGuildPlayerInfo::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 20, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;
  if (!read_string(field_2, 20, it, data, packet_size))
    return false;
  if (!read_string(field_3, 64, it, data, packet_size))
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
std::vector<std::uint8_t> GameServerGuildPlayerInfo::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_string(field_1, data);
  pack_string(field_2, data);
  pack_string(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_field(field_6, data);
  pack_field(field_7, data);
  pack_field(field_8, data);
  return data;
}
GameServerGuildPlayerRemove::GameServerGuildPlayerRemove(
    const std::vector<std::uint8_t> &data)
    : PacketReader(295) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGuildPlayerRemove::get_packet_name() const {
  return "GameServerGuildPlayerRemove";
}

std::string GameServerGuildPlayerRemove::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGuildPlayerRemove"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerGuildPlayerRemove::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGuildPlayerRemove::get_packet_size() const {
  return packet_size;
}
bool GameServerGuildPlayerRemove::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerGuildPlayerRemove::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerPacket296::GameServerPacket296(const std::vector<std::uint8_t> &data)
    : PacketReader(296) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket296::get_packet_name() const {
  return "GameServerPacket296";
}

std::string GameServerPacket296::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket296"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket296::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket296::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket296::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket296::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerGuildPlayerChangeComplete::GameServerGuildPlayerChangeComplete(
    const std::vector<std::uint8_t> &data)
    : PacketReader(297) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGuildPlayerChangeComplete::get_packet_name() const {
  return "GameServerGuildPlayerChangeComplete";
}

std::string
GameServerGuildPlayerChangeComplete::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGuildPlayerChangeComplete"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerGuildPlayerChangeComplete::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGuildPlayerChangeComplete::get_packet_size() const {
  return packet_size;
}
bool GameServerGuildPlayerChangeComplete::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerGuildPlayerChangeComplete::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerGuildChangePlayerContext::GameServerGuildChangePlayerContext(
    const std::vector<std::uint8_t> &data)
    : PacketReader(298) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGuildChangePlayerContext::get_packet_name() const {
  return "GameServerGuildChangePlayerContext";
}

std::string
GameServerGuildChangePlayerContext::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGuildChangePlayerContext"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerGuildChangePlayerContext::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGuildChangePlayerContext::get_packet_size() const {
  return packet_size;
}
bool GameServerGuildChangePlayerContext::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerGuildChangePlayerContext::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerGuildChangePlayerStatus::GameServerGuildChangePlayerStatus(
    const std::vector<std::uint8_t> &data)
    : PacketReader(299) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGuildChangePlayerStatus::get_packet_name() const {
  return "GameServerGuildChangePlayerStatus";
}

std::string GameServerGuildChangePlayerStatus::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGuildChangePlayerStatus"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerGuildChangePlayerStatus::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGuildChangePlayerStatus::get_packet_size() const {
  return packet_size;
}
bool GameServerGuildChangePlayerStatus::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerGuildChangePlayerStatus::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerGuildChangePlayerType::GameServerGuildChangePlayerType(
    const std::vector<std::uint8_t> &data)
    : PacketReader(300) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGuildChangePlayerType::get_packet_name() const {
  return "GameServerGuildChangePlayerType";
}

std::string GameServerGuildChangePlayerType::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGuildChangePlayerType"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerGuildChangePlayerType::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGuildChangePlayerType::get_packet_size() const {
  return packet_size;
}
bool GameServerGuildChangePlayerType::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerGuildChangePlayerType::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket301::GameServerPacket301(const std::vector<std::uint8_t> &data)
    : PacketReader(301) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket301::get_packet_name() const {
  return "GameServerPacket301";
}

std::string GameServerPacket301::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket301"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket301::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket301::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket301::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket301::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket302::GameServerPacket302(const std::vector<std::uint8_t> &data)
    : PacketReader(302) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket302::get_packet_name() const {
  return "GameServerPacket302";
}

std::string GameServerPacket302::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket302"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket302::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket302::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket302::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 256, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket302::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerPacket303::GameServerPacket303(const std::vector<std::uint8_t> &data)
    : PacketReader(303) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket303::get_packet_name() const {
  return "GameServerPacket303";
}

std::string GameServerPacket303::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket303"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket303::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket303::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket303::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket303::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket304::GameServerPacket304(const std::vector<std::uint8_t> &data)
    : PacketReader(304) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket304::get_packet_name() const {
  return "GameServerPacket304";
}

std::string GameServerPacket304::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket304"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket304::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket304::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket304::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket304::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket305::GameServerPacket305(const std::vector<std::uint8_t> &data)
    : PacketReader(305) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket305::get_packet_name() const {
  return "GameServerPacket305";
}

std::string GameServerPacket305::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket305"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket305::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket305::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket305::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket305::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket306::GameServerPacket306(const std::vector<std::uint8_t> &data)
    : PacketReader(306) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket306::get_packet_name() const {
  return "GameServerPacket306";
}

std::string GameServerPacket306::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket306"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket306::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket306::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket306::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket306::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket307::GameServerPacket307(const std::vector<std::uint8_t> &data)
    : PacketReader(307) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket307::get_packet_name() const {
  return "GameServerPacket307";
}

std::string GameServerPacket307::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket307"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket307::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket307::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket307::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket307::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket308::GameServerPacket308(const std::vector<std::uint8_t> &data)
    : PacketReader(308) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket308::get_packet_name() const {
  return "GameServerPacket308";
}

std::string GameServerPacket308::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket308"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket308::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket308::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket308::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket308::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket309::GameServerPacket309(const std::vector<std::uint8_t> &data)
    : PacketReader(309) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket309::get_packet_name() const {
  return "GameServerPacket309";
}

std::string GameServerPacket309::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket309"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket309::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket309::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket309::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket309::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket310::GameServerPacket310(const std::vector<std::uint8_t> &data)
    : PacketReader(310) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket310::get_packet_name() const {
  return "GameServerPacket310";
}

std::string GameServerPacket310::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket310"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket310::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket310::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket310::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket310::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket311::GameServerPacket311(const std::vector<std::uint8_t> &data)
    : PacketReader(311) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket311::get_packet_name() const {
  return "GameServerPacket311";
}

std::string GameServerPacket311::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket311"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: " << common::u16string_to_string(field_4) << "\n";
  ss << "  field_5: " << common::u16string_to_string(field_5) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket311::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket311::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket311::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 8, it, data, packet_size))
    return false;
  if (!read_string(field_3, 8, it, data, packet_size))
    return false;
  if (!read_string(field_4, 8, it, data, packet_size))
    return false;
  if (!read_string(field_5, 8, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket311::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  pack_string(field_3, data);
  pack_string(field_4, data);
  pack_string(field_5, data);
  return data;
}
GameServerInventoryItemQuantity::GameServerInventoryItemQuantity(
    const std::vector<std::uint8_t> &data)
    : PacketReader(312) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInventoryItemQuantity::get_packet_name() const {
  return "GameServerInventoryItemQuantity";
}

std::string GameServerInventoryItemQuantity::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInventoryItemQuantity"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerInventoryItemQuantity::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInventoryItemQuantity::get_packet_size() const {
  return packet_size;
}
bool GameServerInventoryItemQuantity::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerInventoryItemQuantity::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerItemUpdateName::GameServerItemUpdateName(
    const std::vector<std::uint8_t> &data)
    : PacketReader(313) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemUpdateName::get_packet_name() const {
  return "GameServerItemUpdateName";
}

std::string GameServerItemUpdateName::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemUpdateName"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerItemUpdateName::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemUpdateName::get_packet_size() const {
  return packet_size;
}
bool GameServerItemUpdateName::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerItemUpdateName::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerPacket314::GameServerPacket314(const std::vector<std::uint8_t> &data)
    : PacketReader(314) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket314::get_packet_name() const {
  return "GameServerPacket314";
}

std::string GameServerPacket314::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket314"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket314::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket314::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket314::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket314::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket315::GameServerPacket315(const std::vector<std::uint8_t> &data)
    : PacketReader(315) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket315::get_packet_name() const {
  return "GameServerPacket315";
}

std::string GameServerPacket315::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket315"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket315::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket315::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket315::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket315::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket316::GameServerPacket316(const std::vector<std::uint8_t> &data)
    : PacketReader(316) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket316::get_packet_name() const {
  return "GameServerPacket316";
}

std::string GameServerPacket316::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket316"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket316::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket316::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket316::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket316::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerInventoryItemLocation::GameServerInventoryItemLocation(
    const std::vector<std::uint8_t> &data)
    : PacketReader(317) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInventoryItemLocation::get_packet_name() const {
  return "GameServerInventoryItemLocation";
}

std::string GameServerInventoryItemLocation::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInventoryItemLocation"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerInventoryItemLocation::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInventoryItemLocation::get_packet_size() const {
  return packet_size;
}
bool GameServerInventoryItemLocation::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerInventoryItemLocation::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerInventoryCreateBag::GameServerInventoryCreateBag(
    const std::vector<std::uint8_t> &data)
    : PacketReader(318) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInventoryCreateBag::get_packet_name() const {
  return "GameServerInventoryCreateBag";
}

std::string GameServerInventoryCreateBag::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInventoryCreateBag"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerInventoryCreateBag::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInventoryCreateBag::get_packet_size() const {
  return packet_size;
}
bool GameServerInventoryCreateBag::parse(
    const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameServerInventoryCreateBag::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  return data;
}
GameServerGoldCharacterAdd::GameServerGoldCharacterAdd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(319) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGoldCharacterAdd::get_packet_name() const {
  return "GameServerGoldCharacterAdd";
}

std::string GameServerGoldCharacterAdd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGoldCharacterAdd"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerGoldCharacterAdd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGoldCharacterAdd::get_packet_size() const {
  return packet_size;
}
bool GameServerGoldCharacterAdd::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerGoldCharacterAdd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerGoldStorageAdd::GameServerGoldStorageAdd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(320) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGoldStorageAdd::get_packet_name() const {
  return "GameServerGoldStorageAdd";
}

std::string GameServerGoldStorageAdd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGoldStorageAdd"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerGoldStorageAdd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGoldStorageAdd::get_packet_size() const {
  return packet_size;
}
bool GameServerGoldStorageAdd::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerGoldStorageAdd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket321::GameServerPacket321(const std::vector<std::uint8_t> &data)
    : PacketReader(321) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket321::get_packet_name() const {
  return "GameServerPacket321";
}

std::string GameServerPacket321::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket321"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket321::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket321::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket321::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket321::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket322::GameServerPacket322(const std::vector<std::uint8_t> &data)
    : PacketReader(322) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket322::get_packet_name() const {
  return "GameServerPacket322";
}

std::string GameServerPacket322::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket322"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket322::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket322::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket322::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket322::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerItemStreamCreate::GameServerItemStreamCreate(
    const std::vector<std::uint8_t> &data)
    : PacketReader(323) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemStreamCreate::get_packet_name() const {
  return "GameServerItemStreamCreate";
}

std::string GameServerItemStreamCreate::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemStreamCreate"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerItemStreamCreate::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemStreamCreate::get_packet_size() const {
  return packet_size;
}
bool GameServerItemStreamCreate::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerItemStreamCreate::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerItemStreamDestroy::GameServerItemStreamDestroy(
    const std::vector<std::uint8_t> &data)
    : PacketReader(324) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemStreamDestroy::get_packet_name() const {
  return "GameServerItemStreamDestroy";
}

std::string GameServerItemStreamDestroy::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemStreamDestroy"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerItemStreamDestroy::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemStreamDestroy::get_packet_size() const {
  return packet_size;
}
bool GameServerItemStreamDestroy::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerItemStreamDestroy::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket325::GameServerPacket325(const std::vector<std::uint8_t> &data)
    : PacketReader(325) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket325::get_packet_name() const {
  return "GameServerPacket325";
}

std::string GameServerPacket325::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket325"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket325::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket325::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket325::parse(const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameServerPacket325::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  return data;
}
GameServerItemWeaponSet::GameServerItemWeaponSet(
    const std::vector<std::uint8_t> &data)
    : PacketReader(326) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemWeaponSet::get_packet_name() const {
  return "GameServerItemWeaponSet";
}

std::string GameServerItemWeaponSet::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemWeaponSet"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerItemWeaponSet::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemWeaponSet::get_packet_size() const {
  return packet_size;
}
bool GameServerItemWeaponSet::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerItemWeaponSet::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerItemSetActiveWeaponSet::GameServerItemSetActiveWeaponSet(
    const std::vector<std::uint8_t> &data)
    : PacketReader(327) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemSetActiveWeaponSet::get_packet_name() const {
  return "GameServerItemSetActiveWeaponSet";
}

std::string GameServerItemSetActiveWeaponSet::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemSetActiveWeaponSet"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerItemSetActiveWeaponSet::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemSetActiveWeaponSet::get_packet_size() const {
  return packet_size;
}
bool GameServerItemSetActiveWeaponSet::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerItemSetActiveWeaponSet::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket328::GameServerPacket328(const std::vector<std::uint8_t> &data)
    : PacketReader(328) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket328::get_packet_name() const {
  return "GameServerPacket328";
}

std::string GameServerPacket328::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket328"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket328::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket328::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket328::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket328::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket329::GameServerPacket329(const std::vector<std::uint8_t> &data)
    : PacketReader(329) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket329::get_packet_name() const {
  return "GameServerPacket329";
}

std::string GameServerPacket329::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket329"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket329::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket329::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket329::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket329::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerItemChangeLocation::GameServerItemChangeLocation(
    const std::vector<std::uint8_t> &data)
    : PacketReader(330) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemChangeLocation::get_packet_name() const {
  return "GameServerItemChangeLocation";
}

std::string GameServerItemChangeLocation::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemChangeLocation"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerItemChangeLocation::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemChangeLocation::get_packet_size() const {
  return packet_size;
}
bool GameServerItemChangeLocation::parse(
    const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerItemChangeLocation::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerPacket331::GameServerPacket331(const std::vector<std::uint8_t> &data)
    : PacketReader(331) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket331::get_packet_name() const {
  return "GameServerPacket331";
}

std::string GameServerPacket331::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket331"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket331::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket331::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket331::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket331::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerItemRemove::GameServerItemRemove(
    const std::vector<std::uint8_t> &data)
    : PacketReader(332) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemRemove::get_packet_name() const {
  return "GameServerItemRemove";
}

std::string GameServerItemRemove::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemRemove"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerItemRemove::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemRemove::get_packet_size() const {
  return packet_size;
}
bool GameServerItemRemove::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerItemRemove::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket333::GameServerPacket333(const std::vector<std::uint8_t> &data)
    : PacketReader(333) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket333::get_packet_name() const {
  return "GameServerPacket333";
}

std::string GameServerPacket333::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket333"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket333::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket333::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket333::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket333::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerGoldCharacterRemove::GameServerGoldCharacterRemove(
    const std::vector<std::uint8_t> &data)
    : PacketReader(334) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGoldCharacterRemove::get_packet_name() const {
  return "GameServerGoldCharacterRemove";
}

std::string GameServerGoldCharacterRemove::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGoldCharacterRemove"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerGoldCharacterRemove::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGoldCharacterRemove::get_packet_size() const {
  return packet_size;
}
bool GameServerGoldCharacterRemove::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerGoldCharacterRemove::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerGoldStorageRemove::GameServerGoldStorageRemove(
    const std::vector<std::uint8_t> &data)
    : PacketReader(335) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerGoldStorageRemove::get_packet_name() const {
  return "GameServerGoldStorageRemove";
}

std::string GameServerGoldStorageRemove::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerGoldStorageRemove"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerGoldStorageRemove::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerGoldStorageRemove::get_packet_size() const {
  return packet_size;
}
bool GameServerGoldStorageRemove::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerGoldStorageRemove::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket336::GameServerPacket336(const std::vector<std::uint8_t> &data)
    : PacketReader(336) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket336::get_packet_name() const {
  return "GameServerPacket336";
}

std::string GameServerPacket336::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket336"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket336::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket336::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket336::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket336::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket337::GameServerPacket337(const std::vector<std::uint8_t> &data)
    : PacketReader(337) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket337::get_packet_name() const {
  return "GameServerPacket337";
}

std::string GameServerPacket337::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket337"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket337::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket337::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket337::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket337::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket338::GameServerPacket338(const std::vector<std::uint8_t> &data)
    : PacketReader(338) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket338::get_packet_name() const {
  return "GameServerPacket338";
}

std::string GameServerPacket338::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket338"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket338::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket338::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket338::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket338::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerTomeShowSkills::GameServerTomeShowSkills(
    const std::vector<std::uint8_t> &data)
    : PacketReader(339) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTomeShowSkills::get_packet_name() const {
  return "GameServerTomeShowSkills";
}

std::string GameServerTomeShowSkills::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTomeShowSkills"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerTomeShowSkills::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTomeShowSkills::get_packet_size() const {
  return packet_size;
}
bool GameServerTomeShowSkills::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerTomeShowSkills::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket340::GameServerPacket340(const std::vector<std::uint8_t> &data)
    : PacketReader(340) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket340::get_packet_name() const {
  return "GameServerPacket340";
}

std::string GameServerPacket340::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket340"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket340::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket340::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket340::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket340::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket341::GameServerPacket341(const std::vector<std::uint8_t> &data)
    : PacketReader(341) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket341::get_packet_name() const {
  return "GameServerPacket341";
}

std::string GameServerPacket341::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket341"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket341::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket341::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket341::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket341::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket342::GameServerPacket342(const std::vector<std::uint8_t> &data)
    : PacketReader(342) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket342::get_packet_name() const {
  return "GameServerPacket342";
}

std::string GameServerPacket342::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket342"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket342::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket342::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket342::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket342::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerPacket343::GameServerPacket343(const std::vector<std::uint8_t> &data)
    : PacketReader(343) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket343::get_packet_name() const {
  return "GameServerPacket343";
}

std::string GameServerPacket343::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket343"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket343::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket343::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket343::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket343::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket344::GameServerPacket344(const std::vector<std::uint8_t> &data)
    : PacketReader(344) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket344::get_packet_name() const {
  return "GameServerPacket344";
}

std::string GameServerPacket344::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket344"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket344::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket344::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket344::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket344::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket345::GameServerPacket345(const std::vector<std::uint8_t> &data)
    : PacketReader(345) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket345::get_packet_name() const {
  return "GameServerPacket345";
}

std::string GameServerPacket345::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket345"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket345::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket345::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket345::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket345::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket346::GameServerPacket346(const std::vector<std::uint8_t> &data)
    : PacketReader(346) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket346::get_packet_name() const {
  return "GameServerPacket346";
}

std::string GameServerPacket346::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket346"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket346::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket346::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket346::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket346::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket347::GameServerPacket347(const std::vector<std::uint8_t> &data)
    : PacketReader(347) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket347::get_packet_name() const {
  return "GameServerPacket347";
}

std::string GameServerPacket347::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket347"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: "
     << "\n";
  for (const auto &ns : field_1) {
    ss << "    field_0: " << ns.field_0 << "\n";
    ss << "    field_1: " << ns.field_1 << "\n";
    ss << "    field_2: " << ns.field_2 << "\n";
    ss << "    field_3: " << ns.field_3 << "\n";
    ss << "    field_4: " << ns.field_4 << "\n";
    ss << "    field_5: " << ns.field_5 << "\n";
    ss << "    field_6: " << ns.field_6 << "\n";
  }
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket347::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket347::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket347::parse(const std::vector<std::uint8_t> &data) {
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
bool GameServerPacket347::read_struct(
    std::vector<std::uint8_t>::const_iterator &it,
    const std::vector<std::uint8_t> &data) {
  some_struct ns;
  if (!read_field(ns.field_0, it, data, packet_size))
    return false;
  if (!read_field(ns.field_1, it, data, packet_size))
    return false;
  if (!read_field(ns.field_2, it, data, packet_size))
    return false;
  if (!read_field(ns.field_3, it, data, packet_size))
    return false;
  if (!read_field(ns.field_4, it, data, packet_size))
    return false;
  if (!read_field(ns.field_5, it, data, packet_size))
    return false;
  if (!read_field(ns.field_6, it, data, packet_size))
    return false;
  field_1.push_back(ns);

  return true;
}
std::vector<std::uint8_t> GameServerPacket347::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  std::uint8_t struct_count = static_cast<std::uint8_t>(field_1.size());
  pack_field(struct_count, data);
  for (const auto &ns : field_1) {
    pack_field(ns.field_0, data);
    pack_field(ns.field_1, data);
    pack_field(ns.field_2, data);
    pack_field(ns.field_3, data);
    pack_field(ns.field_4, data);
    pack_field(ns.field_5, data);
    pack_field(ns.field_6, data);
  }
  return data;
}
GameServerPacket348::GameServerPacket348(const std::vector<std::uint8_t> &data)
    : PacketReader(348) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket348::get_packet_name() const {
  return "GameServerPacket348";
}

std::string GameServerPacket348::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket348"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket348::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket348::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket348::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket348::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket349::GameServerPacket349(const std::vector<std::uint8_t> &data)
    : PacketReader(349) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket349::get_packet_name() const {
  return "GameServerPacket349";
}

std::string GameServerPacket349::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket349"
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
std::vector<std::uint8_t> GameServerPacket349::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket349::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket349::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket349::pack() const {
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
GameServerPacket350::GameServerPacket350(const std::vector<std::uint8_t> &data)
    : PacketReader(350) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket350::get_packet_name() const {
  return "GameServerPacket350";
}

std::string GameServerPacket350::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket350"
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
std::vector<std::uint8_t> GameServerPacket350::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket350::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket350::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket350::pack() const {
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
GameServerPacket351::GameServerPacket351(const std::vector<std::uint8_t> &data)
    : PacketReader(351) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket351::get_packet_name() const {
  return "GameServerPacket351";
}

std::string GameServerPacket351::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket351"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: "
     << "\n";
  for (const auto &ns : field_4) {
    ss << "    field_0: " << ns.field_0 << "\n";
  }
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket351::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket351::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket351::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_string(field_3, 64, it, data, packet_size))
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
bool GameServerPacket351::read_struct(
    std::vector<std::uint8_t>::const_iterator &it,
    const std::vector<std::uint8_t> &data) {
  some_struct ns;
  if (!read_field(ns.field_0, it, data, packet_size))
    return false;
  field_4.push_back(ns);

  return true;
}
std::vector<std::uint8_t> GameServerPacket351::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_string(field_3, data);
  std::uint8_t struct_count = static_cast<std::uint8_t>(field_4.size());
  pack_field(struct_count, data);
  for (const auto &ns : field_4) {
    pack_field(ns.field_0, data);
  }
  return data;
}
GameServerItemGeneralInfo::GameServerItemGeneralInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(352) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemGeneralInfo::get_packet_name() const {
  return "GameServerItemGeneralInfo";
}

std::string GameServerItemGeneralInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemGeneralInfo"
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
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << common::u16string_to_string(field_11) << "\n";
  ss << "  field_12: "
     << "\n";
  for (const auto &ns : field_12) {
    ss << "    field_0: " << ns.field_0 << "\n";
  }
  return ss.str();
}
std::vector<std::uint8_t> GameServerItemGeneralInfo::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemGeneralInfo::get_packet_size() const {
  return packet_size;
}
bool GameServerItemGeneralInfo::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_string(field_11, 64, it, data, packet_size))
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
bool GameServerItemGeneralInfo::read_struct(
    std::vector<std::uint8_t>::const_iterator &it,
    const std::vector<std::uint8_t> &data) {
  some_struct ns;
  if (!read_field(ns.field_0, it, data, packet_size))
    return false;
  field_12.push_back(ns);

  return true;
}
std::vector<std::uint8_t> GameServerItemGeneralInfo::pack() const {
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
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_string(field_11, data);
  std::uint8_t struct_count = static_cast<std::uint8_t>(field_12.size());
  pack_field(struct_count, data);
  for (const auto &ns : field_12) {
    pack_field(ns.field_0, data);
  }
  return data;
}
GameServerPacket353::GameServerPacket353(const std::vector<std::uint8_t> &data)
    : PacketReader(353) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket353::get_packet_name() const {
  return "GameServerPacket353";
}

std::string GameServerPacket353::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket353"
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
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << common::u16string_to_string(field_11) << "\n";
  ss << "  field_12: "
     << "\n";
  for (const auto &ns : field_12) {
    ss << "    field_0: " << ns.field_0 << "\n";
  }
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket353::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket353::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket353::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_string(field_11, 64, it, data, packet_size))
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
bool GameServerPacket353::read_struct(
    std::vector<std::uint8_t>::const_iterator &it,
    const std::vector<std::uint8_t> &data) {
  some_struct ns;
  if (!read_field(ns.field_0, it, data, packet_size))
    return false;
  field_12.push_back(ns);

  return true;
}
std::vector<std::uint8_t> GameServerPacket353::pack() const {
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
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_string(field_11, data);
  std::uint8_t struct_count = static_cast<std::uint8_t>(field_12.size());
  pack_field(struct_count, data);
  for (const auto &ns : field_12) {
    pack_field(ns.field_0, data);
  }
  return data;
}
GameServerItemSalvageSessionStart::GameServerItemSalvageSessionStart(
    const std::vector<std::uint8_t> &data)
    : PacketReader(354) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemSalvageSessionStart::get_packet_name() const {
  return "GameServerItemSalvageSessionStart";
}

std::string GameServerItemSalvageSessionStart::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemSalvageSessionStart"
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
std::vector<std::uint8_t>
GameServerItemSalvageSessionStart::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemSalvageSessionStart::get_packet_size() const {
  return packet_size;
}
bool GameServerItemSalvageSessionStart::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_array(field_2, 3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerItemSalvageSessionStart::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_array(field_2, data);
  return data;
}
GameServerItemSalvageSessionCancel::GameServerItemSalvageSessionCancel(
    const std::vector<std::uint8_t> &data)
    : PacketReader(355) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemSalvageSessionCancel::get_packet_name() const {
  return "GameServerItemSalvageSessionCancel";
}

std::string
GameServerItemSalvageSessionCancel::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemSalvageSessionCancel"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerItemSalvageSessionCancel::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemSalvageSessionCancel::get_packet_size() const {
  return packet_size;
}
bool GameServerItemSalvageSessionCancel::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerItemSalvageSessionCancel::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerItemSalvageSessionDone::GameServerItemSalvageSessionDone(
    const std::vector<std::uint8_t> &data)
    : PacketReader(356) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemSalvageSessionDone::get_packet_name() const {
  return "GameServerItemSalvageSessionDone";
}

std::string GameServerItemSalvageSessionDone::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemSalvageSessionDone"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerItemSalvageSessionDone::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemSalvageSessionDone::get_packet_size() const {
  return packet_size;
}
bool GameServerItemSalvageSessionDone::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerItemSalvageSessionDone::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerItemSalvageSessionSuccess::GameServerItemSalvageSessionSuccess(
    const std::vector<std::uint8_t> &data)
    : PacketReader(357) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemSalvageSessionSuccess::get_packet_name() const {
  return "GameServerItemSalvageSessionSuccess";
}

std::string
GameServerItemSalvageSessionSuccess::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemSalvageSessionSuccess"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerItemSalvageSessionSuccess::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemSalvageSessionSuccess::get_packet_size() const {
  return packet_size;
}
bool GameServerItemSalvageSessionSuccess::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerItemSalvageSessionSuccess::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerItemSalvageSessionItemKept::GameServerItemSalvageSessionItemKept(
    const std::vector<std::uint8_t> &data)
    : PacketReader(358) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerItemSalvageSessionItemKept::get_packet_name() const {
  return "GameServerItemSalvageSessionItemKept";
}

std::string
GameServerItemSalvageSessionItemKept::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerItemSalvageSessionItemKept"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerItemSalvageSessionItemKept::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerItemSalvageSessionItemKept::get_packet_size() const {
  return packet_size;
}
bool GameServerItemSalvageSessionItemKept::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerItemSalvageSessionItemKept::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket359::GameServerPacket359(const std::vector<std::uint8_t> &data)
    : PacketReader(359) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket359::get_packet_name() const {
  return "GameServerPacket359";
}

std::string GameServerPacket359::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket359"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket359::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket359::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket359::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket359::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket360::GameServerPacket360(const std::vector<std::uint8_t> &data)
    : PacketReader(360) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket360::get_packet_name() const {
  return "GameServerPacket360";
}

std::string GameServerPacket360::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket360"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket360::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket360::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket360::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket360::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket361::GameServerPacket361(const std::vector<std::uint8_t> &data)
    : PacketReader(361) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket361::get_packet_name() const {
  return "GameServerPacket361";
}

std::string GameServerPacket361::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket361"
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
std::vector<std::uint8_t> GameServerPacket361::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket361::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket361::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_array(field_2, 3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket361::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_array(field_2, data);
  return data;
}
GameServerPacket362::GameServerPacket362(const std::vector<std::uint8_t> &data)
    : PacketReader(362) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket362::get_packet_name() const {
  return "GameServerPacket362";
}

std::string GameServerPacket362::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket362"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket362::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket362::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket362::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket362::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket363::GameServerPacket363(const std::vector<std::uint8_t> &data)
    : PacketReader(363) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket363::get_packet_name() const {
  return "GameServerPacket363";
}

std::string GameServerPacket363::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket363"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket363::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket363::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket363::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket363::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket364::GameServerPacket364(const std::vector<std::uint8_t> &data)
    : PacketReader(364) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket364::get_packet_name() const {
  return "GameServerPacket364";
}

std::string GameServerPacket364::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket364"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket364::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket364::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket364::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket364::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket365::GameServerPacket365(const std::vector<std::uint8_t> &data)
    : PacketReader(365) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket365::get_packet_name() const {
  return "GameServerPacket365";
}

std::string GameServerPacket365::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket365"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket365::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket365::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket365::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket365::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket366::GameServerPacket366(const std::vector<std::uint8_t> &data)
    : PacketReader(366) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket366::get_packet_name() const {
  return "GameServerPacket366";
}

std::string GameServerPacket366::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket366"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket366::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket366::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket366::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket366::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket367::GameServerPacket367(const std::vector<std::uint8_t> &data)
    : PacketReader(367) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket367::get_packet_name() const {
  return "GameServerPacket367";
}

std::string GameServerPacket367::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket367"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket367::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket367::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket367::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket367::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket368::GameServerPacket368(const std::vector<std::uint8_t> &data)
    : PacketReader(368) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket368::get_packet_name() const {
  return "GameServerPacket368";
}

std::string GameServerPacket368::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket368"
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
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << field_11 << "\n";
  ss << "  field_12: " << field_12 << "\n";
  ss << "  field_13: " << field_13 << "\n";
  ss << "  field_14: " << field_14 << "\n";
  ss << "  field_15: " << field_15 << "\n";
  ss << "  field_16: " << field_16 << "\n";
  ss << "  field_17: " << field_17 << "\n";
  ss << "  field_18: " << field_18 << "\n";
  ss << "  field_19: " << field_19 << "\n";
  ss << "  field_20: " << field_20 << "\n";
  ss << "  field_21: " << field_21 << "\n";
  ss << "  field_22: " << field_22 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket368::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket368::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket368::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_field(field_11, it, data, packet_size))
    return false;
  if (!read_field(field_12, it, data, packet_size))
    return false;
  if (!read_field(field_13, it, data, packet_size))
    return false;
  if (!read_field(field_14, it, data, packet_size))
    return false;
  if (!read_field(field_15, it, data, packet_size))
    return false;
  if (!read_field(field_16, it, data, packet_size))
    return false;
  if (!read_field(field_17, it, data, packet_size))
    return false;
  if (!read_field(field_18, it, data, packet_size))
    return false;
  if (!read_field(field_19, it, data, packet_size))
    return false;
  if (!read_field(field_20, it, data, packet_size))
    return false;
  if (!read_field(field_21, it, data, packet_size))
    return false;
  if (!read_field(field_22, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket368::pack() const {
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
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_field(field_11, data);
  pack_field(field_12, data);
  pack_field(field_13, data);
  pack_field(field_14, data);
  pack_field(field_15, data);
  pack_field(field_16, data);
  pack_field(field_17, data);
  pack_field(field_18, data);
  pack_field(field_19, data);
  pack_field(field_20, data);
  pack_field(field_21, data);
  pack_field(field_22, data);
  return data;
}
GameServerPacket369::GameServerPacket369(const std::vector<std::uint8_t> &data)
    : PacketReader(369) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket369::get_packet_name() const {
  return "GameServerPacket369";
}

std::string GameServerPacket369::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket369"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket369::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket369::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket369::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket369::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket370::GameServerPacket370(const std::vector<std::uint8_t> &data)
    : PacketReader(370) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket370::get_packet_name() const {
  return "GameServerPacket370";
}

std::string GameServerPacket370::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket370"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket370::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket370::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket370::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket370::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket371::GameServerPacket371(const std::vector<std::uint8_t> &data)
    : PacketReader(371) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket371::get_packet_name() const {
  return "GameServerPacket371";
}

std::string GameServerPacket371::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket371"
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
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << field_11 << "\n";
  ss << "  field_12: " << field_12 << "\n";
  ss << "  field_13: " << field_13 << "\n";
  ss << "  field_14: " << field_14 << "\n";
  ss << "  field_15: " << field_15 << "\n";
  ss << "  field_16: " << field_16 << "\n";
  ss << "  field_17: " << field_17 << "\n";
  ss << "  field_18: " << field_18 << "\n";
  ss << "  field_19: " << field_19 << "\n";
  ss << "  field_20: " << field_20 << "\n";
  ss << "  field_21: " << field_21 << "\n";
  ss << "  field_22: " << field_22 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket371::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket371::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket371::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_field(field_11, it, data, packet_size))
    return false;
  if (!read_field(field_12, it, data, packet_size))
    return false;
  if (!read_field(field_13, it, data, packet_size))
    return false;
  if (!read_field(field_14, it, data, packet_size))
    return false;
  if (!read_field(field_15, it, data, packet_size))
    return false;
  if (!read_field(field_16, it, data, packet_size))
    return false;
  if (!read_field(field_17, it, data, packet_size))
    return false;
  if (!read_field(field_18, it, data, packet_size))
    return false;
  if (!read_field(field_19, it, data, packet_size))
    return false;
  if (!read_field(field_20, it, data, packet_size))
    return false;
  if (!read_field(field_21, it, data, packet_size))
    return false;
  if (!read_field(field_22, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket371::pack() const {
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
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_field(field_11, data);
  pack_field(field_12, data);
  pack_field(field_13, data);
  pack_field(field_14, data);
  pack_field(field_15, data);
  pack_field(field_16, data);
  pack_field(field_17, data);
  pack_field(field_18, data);
  pack_field(field_19, data);
  pack_field(field_20, data);
  pack_field(field_21, data);
  pack_field(field_22, data);
  return data;
}
GameServerPacket372::GameServerPacket372(const std::vector<std::uint8_t> &data)
    : PacketReader(372) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket372::get_packet_name() const {
  return "GameServerPacket372";
}

std::string GameServerPacket372::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket372"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket372::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket372::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket372::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_string(field_3, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket372::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_string(field_3, data);
  return data;
}
GameServerPacket373::GameServerPacket373(const std::vector<std::uint8_t> &data)
    : PacketReader(373) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket373::get_packet_name() const {
  return "GameServerPacket373";
}

std::string GameServerPacket373::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket373"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket373::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket373::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket373::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket373::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket374::GameServerPacket374(const std::vector<std::uint8_t> &data)
    : PacketReader(374) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket374::get_packet_name() const {
  return "GameServerPacket374";
}

std::string GameServerPacket374::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket374"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket374::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket374::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket374::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_string(field_3, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket374::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_string(field_3, data);
  return data;
}
GameServerPacket375::GameServerPacket375(const std::vector<std::uint8_t> &data)
    : PacketReader(375) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket375::get_packet_name() const {
  return "GameServerPacket375";
}

std::string GameServerPacket375::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket375"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  ss << "  field_7: " << field_7 << "\n";
  ss << "  field_8: " << field_8 << "\n";
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << field_11 << "\n";
  ss << "  field_12: " << field_12 << "\n";
  ss << "  field_13: " << field_13 << "\n";
  ss << "  field_14: " << field_14 << "\n";
  ss << "  field_15: " << field_15 << "\n";
  ss << "  field_16: " << field_16 << "\n";
  ss << "  field_17: " << field_17 << "\n";
  ss << "  field_18: " << field_18 << "\n";
  ss << "  field_19: " << field_19 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket375::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket375::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket375::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 64, it, data, packet_size))
    return false;
  if (!read_string(field_2, 6, it, data, packet_size))
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
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_field(field_11, it, data, packet_size))
    return false;
  if (!read_field(field_12, it, data, packet_size))
    return false;
  if (!read_field(field_13, it, data, packet_size))
    return false;
  if (!read_field(field_14, it, data, packet_size))
    return false;
  if (!read_field(field_15, it, data, packet_size))
    return false;
  if (!read_field(field_16, it, data, packet_size))
    return false;
  if (!read_field(field_17, it, data, packet_size))
    return false;
  if (!read_field(field_18, it, data, packet_size))
    return false;
  if (!read_field(field_19, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket375::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_string(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_field(field_6, data);
  pack_field(field_7, data);
  pack_field(field_8, data);
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_field(field_11, data);
  pack_field(field_12, data);
  pack_field(field_13, data);
  pack_field(field_14, data);
  pack_field(field_15, data);
  pack_field(field_16, data);
  pack_field(field_17, data);
  pack_field(field_18, data);
  pack_field(field_19, data);
  return data;
}
GameServerPacket376::GameServerPacket376(const std::vector<std::uint8_t> &data)
    : PacketReader(376) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket376::get_packet_name() const {
  return "GameServerPacket376";
}

std::string GameServerPacket376::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket376"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket376::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket376::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket376::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket376::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket377::GameServerPacket377(const std::vector<std::uint8_t> &data)
    : PacketReader(377) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket377::get_packet_name() const {
  return "GameServerPacket377";
}

std::string GameServerPacket377::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket377"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket377::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket377::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket377::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket377::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerInstanceShowWin::GameServerInstanceShowWin(
    const std::vector<std::uint8_t> &data)
    : PacketReader(378) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInstanceShowWin::get_packet_name() const {
  return "GameServerInstanceShowWin";
}

std::string GameServerInstanceShowWin::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInstanceShowWin"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerInstanceShowWin::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInstanceShowWin::get_packet_size() const {
  return packet_size;
}
bool GameServerInstanceShowWin::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerInstanceShowWin::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerInstanceLoadHead::GameServerInstanceLoadHead(
    const std::vector<std::uint8_t> &data)
    : PacketReader(379) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInstanceLoadHead::get_packet_name() const {
  return "GameServerInstanceLoadHead";
}

std::string GameServerInstanceLoadHead::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInstanceLoadHead"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerInstanceLoadHead::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInstanceLoadHead::get_packet_size() const {
  return packet_size;
}
bool GameServerInstanceLoadHead::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerInstanceLoadHead::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerInstanceLoadPlayerName::GameServerInstanceLoadPlayerName(
    const std::vector<std::uint8_t> &data)
    : PacketReader(380) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInstanceLoadPlayerName::get_packet_name() const {
  return "GameServerInstanceLoadPlayerName";
}

std::string GameServerInstanceLoadPlayerName::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInstanceLoadPlayerName"
     << "\n";
  ss << "  player_name: " << common::u16string_to_string(player_name) << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerInstanceLoadPlayerName::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInstanceLoadPlayerName::get_packet_size() const {
  return packet_size;
}
bool GameServerInstanceLoadPlayerName::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(player_name, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerInstanceLoadPlayerName::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(player_name, data);
  return data;
}
GameServerInstanceCountdownStop::GameServerInstanceCountdownStop(
    const std::vector<std::uint8_t> &data)
    : PacketReader(381) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInstanceCountdownStop::get_packet_name() const {
  return "GameServerInstanceCountdownStop";
}

std::string GameServerInstanceCountdownStop::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInstanceCountdownStop"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerInstanceCountdownStop::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInstanceCountdownStop::get_packet_size() const {
  return packet_size;
}
bool GameServerInstanceCountdownStop::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerInstanceCountdownStop::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket382::GameServerPacket382(const std::vector<std::uint8_t> &data)
    : PacketReader(382) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket382::get_packet_name() const {
  return "GameServerPacket382";
}

std::string GameServerPacket382::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket382"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket382::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket382::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket382::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket382::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerInstanceCountdown::GameServerInstanceCountdown(
    const std::vector<std::uint8_t> &data)
    : PacketReader(383) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInstanceCountdown::get_packet_name() const {
  return "GameServerInstanceCountdown";
}

std::string GameServerInstanceCountdown::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInstanceCountdown"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerInstanceCountdown::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInstanceCountdown::get_packet_size() const {
  return packet_size;
}
bool GameServerInstanceCountdown::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 122, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerInstanceCountdown::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameServerPacket384::GameServerPacket384(const std::vector<std::uint8_t> &data)
    : PacketReader(384) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket384::get_packet_name() const {
  return "GameServerPacket384";
}

std::string GameServerPacket384::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket384"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket384::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket384::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket384::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket384::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket385::GameServerPacket385(const std::vector<std::uint8_t> &data)
    : PacketReader(385) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket385::get_packet_name() const {
  return "GameServerPacket385";
}

std::string GameServerPacket385::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket385"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket385::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket385::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket385::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 122, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket385::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket386::GameServerPacket386(const std::vector<std::uint8_t> &data)
    : PacketReader(386) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket386::get_packet_name() const {
  return "GameServerPacket386";
}

std::string GameServerPacket386::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket386"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket386::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket386::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket386::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 128, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket386::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket387::GameServerPacket387(const std::vector<std::uint8_t> &data)
    : PacketReader(387) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket387::get_packet_name() const {
  return "GameServerPacket387";
}

std::string GameServerPacket387::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket387"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket387::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket387::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket387::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 128, it, data, packet_size))
    return false;
  if (!read_string(field_1, 256, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket387::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameServerPacket388::GameServerPacket388(const std::vector<std::uint8_t> &data)
    : PacketReader(388) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket388::get_packet_name() const {
  return "GameServerPacket388";
}

std::string GameServerPacket388::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket388"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket388::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket388::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket388::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 128, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket388::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerSentAfterInstanceLoadHead::GameServerSentAfterInstanceLoadHead(
    const std::vector<std::uint8_t> &data)
    : PacketReader(389) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerSentAfterInstanceLoadHead::get_packet_name() const {
  return "GameServerSentAfterInstanceLoadHead";
}

std::string
GameServerSentAfterInstanceLoadHead::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerSentAfterInstanceLoadHead"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerSentAfterInstanceLoadHead::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerSentAfterInstanceLoadHead::get_packet_size() const {
  return packet_size;
}
bool GameServerSentAfterInstanceLoadHead::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerSentAfterInstanceLoadHead::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket390::GameServerPacket390(const std::vector<std::uint8_t> &data)
    : PacketReader(390) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket390::get_packet_name() const {
  return "GameServerPacket390";
}

std::string GameServerPacket390::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket390"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket390::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket390::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket390::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket390::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket391::GameServerPacket391(const std::vector<std::uint8_t> &data)
    : PacketReader(391) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket391::get_packet_name() const {
  return "GameServerPacket391";
}

std::string GameServerPacket391::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket391"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: ";
  for (const auto &item : field_3) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket391::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket391::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket391::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_blob(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_array(field_3, 1024, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket391::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_blob(field_0, data);
  pack_string(field_1, data);
  pack_field(field_2, data);
  pack_array(field_3, data);
  return data;
}
GameServerPacket392::GameServerPacket392(const std::vector<std::uint8_t> &data)
    : PacketReader(392) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket392::get_packet_name() const {
  return "GameServerPacket392";
}

std::string GameServerPacket392::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket392"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket392::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket392::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket392::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket392::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket393::GameServerPacket393(const std::vector<std::uint8_t> &data)
    : PacketReader(393) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket393::get_packet_name() const {
  return "GameServerPacket393";
}

std::string GameServerPacket393::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket393"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket393::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket393::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket393::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket393::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket394::GameServerPacket394(const std::vector<std::uint8_t> &data)
    : PacketReader(394) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket394::get_packet_name() const {
  return "GameServerPacket394";
}

std::string GameServerPacket394::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket394"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket394::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket394::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket394::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket394::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket395::GameServerPacket395(const std::vector<std::uint8_t> &data)
    : PacketReader(395) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket395::get_packet_name() const {
  return "GameServerPacket395";
}

std::string GameServerPacket395::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket395"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket395::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket395::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket395::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket395::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket396::GameServerPacket396(const std::vector<std::uint8_t> &data)
    : PacketReader(396) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket396::get_packet_name() const {
  return "GameServerPacket396";
}

std::string GameServerPacket396::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket396"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket396::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket396::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket396::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket396::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerInstanceLoadFinish::GameServerInstanceLoadFinish(
    const std::vector<std::uint8_t> &data)
    : PacketReader(397) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInstanceLoadFinish::get_packet_name() const {
  return "GameServerInstanceLoadFinish";
}

std::string GameServerInstanceLoadFinish::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInstanceLoadFinish"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerInstanceLoadFinish::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInstanceLoadFinish::get_packet_size() const {
  return packet_size;
}
bool GameServerInstanceLoadFinish::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerInstanceLoadFinish::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket398::GameServerPacket398(const std::vector<std::uint8_t> &data)
    : PacketReader(398) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket398::get_packet_name() const {
  return "GameServerPacket398";
}

std::string GameServerPacket398::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket398"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket398::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket398::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket398::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket398::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerJumboMessage::GameServerJumboMessage(
    const std::vector<std::uint8_t> &data)
    : PacketReader(399) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerJumboMessage::get_packet_name() const {
  return "GameServerJumboMessage";
}

std::string GameServerJumboMessage::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerJumboMessage"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerJumboMessage::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerJumboMessage::get_packet_size() const {
  return packet_size;
}
bool GameServerJumboMessage::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerJumboMessage::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket400::GameServerPacket400(const std::vector<std::uint8_t> &data)
    : PacketReader(400) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket400::get_packet_name() const {
  return "GameServerPacket400";
}

std::string GameServerPacket400::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket400"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket400::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket400::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket400::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket400::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket401::GameServerPacket401(const std::vector<std::uint8_t> &data)
    : PacketReader(401) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket401::get_packet_name() const {
  return "GameServerPacket401";
}

std::string GameServerPacket401::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket401"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << common::u16string_to_string(field_5) << "\n";
  ss << "  field_6: "
     << "\n";
  for (const auto &ns : field_6) {
    ss << "    field_0: " << common::u16string_to_string(ns.field_0) << "\n";
  }
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket401::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket401::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket401::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_string(field_5, 64, it, data, packet_size))
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
bool GameServerPacket401::read_struct(
    std::vector<std::uint8_t>::const_iterator &it,
    const std::vector<std::uint8_t> &data) {
  some_struct ns;
  if (!read_string(ns.field_0, 20, it, data, packet_size))
    return false;
  field_6.push_back(ns);

  return true;
}
std::vector<std::uint8_t> GameServerPacket401::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_string(field_5, data);
  std::uint8_t struct_count = static_cast<std::uint8_t>(field_6.size());
  pack_field(struct_count, data);
  for (const auto &ns : field_6) {
    pack_field(ns.field_0, data);
  }
  return data;
}
GameServerPacket402::GameServerPacket402(const std::vector<std::uint8_t> &data)
    : PacketReader(402) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket402::get_packet_name() const {
  return "GameServerPacket402";
}

std::string GameServerPacket402::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket402"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket402::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket402::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket402::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket402::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket403::GameServerPacket403(const std::vector<std::uint8_t> &data)
    : PacketReader(403) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket403::get_packet_name() const {
  return "GameServerPacket403";
}

std::string GameServerPacket403::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket403"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket403::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket403::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket403::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket403::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerInstanceLoadSpawnPoint::GameServerInstanceLoadSpawnPoint(
    const std::vector<std::uint8_t> &data)
    : PacketReader(404) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInstanceLoadSpawnPoint::get_packet_name() const {
  return "GameServerInstanceLoadSpawnPoint";
}

std::string GameServerInstanceLoadSpawnPoint::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInstanceLoadSpawnPoint"
     << "\n";
  ss << "  map_file_id: " << map_file_id << "\n";
  ss << "  spawn_position: " << spawn_position.x << " " << spawn_position.y
     << "\n";
  ss << "  plane_id: " << plane_id << "\n";
  ss << "  unk0: " << unk0 << "\n";
  ss << "  is_cinematic: " << is_cinematic << "\n";
  ss << "  unk1: ";
  for (const auto &item : unk1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerInstanceLoadSpawnPoint::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInstanceLoadSpawnPoint::get_packet_size() const {
  return packet_size;
}
bool GameServerInstanceLoadSpawnPoint::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(map_file_id, it, data, packet_size))
    return false;
  if (!read_vec2(spawn_position, it, data, packet_size))
    return false;
  if (!read_field(plane_id, it, data, packet_size))
    return false;
  if (!read_field(unk0, it, data, packet_size))
    return false;
  if (!read_field(is_cinematic, it, data, packet_size))
    return false;
  if (!read_blob(unk1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerInstanceLoadSpawnPoint::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(map_file_id, data);
  pack_vec2(spawn_position, data);
  pack_field(plane_id, data);
  pack_field(unk0, data);
  pack_field(is_cinematic, data);
  pack_blob(unk1, data);
  return data;
}
GameServerPacket405::GameServerPacket405(const std::vector<std::uint8_t> &data)
    : PacketReader(405) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket405::get_packet_name() const {
  return "GameServerPacket405";
}

std::string GameServerPacket405::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket405"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket405::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket405::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket405::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 1024, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket405::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameServerPacket406::GameServerPacket406(const std::vector<std::uint8_t> &data)
    : PacketReader(406) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket406::get_packet_name() const {
  return "GameServerPacket406";
}

std::string GameServerPacket406::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket406"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket406::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket406::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket406::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket406::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket407::GameServerPacket407(const std::vector<std::uint8_t> &data)
    : PacketReader(407) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket407::get_packet_name() const {
  return "GameServerPacket407";
}

std::string GameServerPacket407::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket407"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket407::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket407::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket407::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket407::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerInstanceLoadInfo::GameServerInstanceLoadInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(408) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInstanceLoadInfo::get_packet_name() const {
  return "GameServerInstanceLoadInfo";
}

std::string GameServerInstanceLoadInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInstanceLoadInfo"
     << "\n";
  ss << "  agent_id: " << agent_id << "\n";
  ss << "  map_id: " << map_id << "\n";
  ss << "  is_explorable: " << is_explorable << "\n";
  ss << "  district: " << district << "\n";
  ss << "  language: " << language << "\n";
  ss << "  is_observer: " << is_observer << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerInstanceLoadInfo::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInstanceLoadInfo::get_packet_size() const {
  return packet_size;
}
bool GameServerInstanceLoadInfo::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(agent_id, it, data, packet_size))
    return false;
  if (!read_field(map_id, it, data, packet_size))
    return false;
  if (!read_field(is_explorable, it, data, packet_size))
    return false;
  if (!read_field(district, it, data, packet_size))
    return false;
  if (!read_field(language, it, data, packet_size))
    return false;
  if (!read_field(is_observer, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerInstanceLoadInfo::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(agent_id, data);
  pack_field(map_id, data);
  pack_field(is_explorable, data);
  pack_field(district, data);
  pack_field(language, data);
  pack_field(is_observer, data);
  return data;
}
GameServerPacket409::GameServerPacket409(const std::vector<std::uint8_t> &data)
    : PacketReader(409) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket409::get_packet_name() const {
  return "GameServerPacket409";
}

std::string GameServerPacket409::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket409"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket409::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket409::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket409::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket409::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket410::GameServerPacket410(const std::vector<std::uint8_t> &data)
    : PacketReader(410) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket410::get_packet_name() const {
  return "GameServerPacket410";
}

std::string GameServerPacket410::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket410"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket410::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket410::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket410::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket410::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket411::GameServerPacket411(const std::vector<std::uint8_t> &data)
    : PacketReader(411) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket411::get_packet_name() const {
  return "GameServerPacket411";
}

std::string GameServerPacket411::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket411"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket411::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket411::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket411::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket411::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerPacket412::GameServerPacket412(const std::vector<std::uint8_t> &data)
    : PacketReader(412) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket412::get_packet_name() const {
  return "GameServerPacket412";
}

std::string GameServerPacket412::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket412"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: "
     << "\n";
  for (const auto &ns : field_6) {
    ss << "    field_0: " << ns.field_0 << "\n";
    ss << "    field_1: " << ns.field_1 << "\n";
    ss << "    field_2: " << ns.field_2 << "\n";
    ss << "    field_3: " << ns.field_3 << "\n";
    ss << "    field_4: " << ns.field_4 << "\n";
    ss << "    field_5: " << ns.field_5 << "\n";
    ss << "    field_6: " << ns.field_6 << "\n";
    ss << "    field_7: " << ns.field_7 << "\n";
    ss << "    field_8: " << ns.field_8 << "\n";
    ss << "    field_9: " << common::u16string_to_string(ns.field_9) << "\n";
  }
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket412::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket412::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket412::parse(const std::vector<std::uint8_t> &data) {
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
bool GameServerPacket412::read_struct(
    std::vector<std::uint8_t>::const_iterator &it,
    const std::vector<std::uint8_t> &data) {
  some_struct ns;
  if (!read_field(ns.field_0, it, data, packet_size))
    return false;
  if (!read_field(ns.field_1, it, data, packet_size))
    return false;
  if (!read_field(ns.field_2, it, data, packet_size))
    return false;
  if (!read_field(ns.field_3, it, data, packet_size))
    return false;
  if (!read_field(ns.field_4, it, data, packet_size))
    return false;
  if (!read_field(ns.field_5, it, data, packet_size))
    return false;
  if (!read_field(ns.field_6, it, data, packet_size))
    return false;
  if (!read_field(ns.field_7, it, data, packet_size))
    return false;
  if (!read_field(ns.field_8, it, data, packet_size))
    return false;
  if (!read_string(ns.field_9, 48, it, data, packet_size))
    return false;
  field_6.push_back(ns);

  return true;
}
std::vector<std::uint8_t> GameServerPacket412::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  std::uint8_t struct_count = static_cast<std::uint8_t>(field_6.size());
  pack_field(struct_count, data);
  for (const auto &ns : field_6) {
    pack_field(ns.field_0, data);
    pack_field(ns.field_1, data);
    pack_field(ns.field_2, data);
    pack_field(ns.field_3, data);
    pack_field(ns.field_4, data);
    pack_field(ns.field_5, data);
    pack_field(ns.field_6, data);
    pack_field(ns.field_7, data);
    pack_field(ns.field_8, data);
    pack_field(ns.field_9, data);
  }
  return data;
}
GameServerPacket413::GameServerPacket413(const std::vector<std::uint8_t> &data)
    : PacketReader(413) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket413::get_packet_name() const {
  return "GameServerPacket413";
}

std::string GameServerPacket413::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket413"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket413::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket413::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket413::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket413::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket414::GameServerPacket414(const std::vector<std::uint8_t> &data)
    : PacketReader(414) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket414::get_packet_name() const {
  return "GameServerPacket414";
}

std::string GameServerPacket414::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket414"
     << "\n";
  ss << "  field_0: "
     << "\n";
  for (const auto &ns : field_0) {
    ss << "    field_0: " << ns.field_0 << "\n";
    ss << "    field_1: " << ns.field_1 << "\n";
  }
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket414::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket414::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket414::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
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
bool GameServerPacket414::read_struct(
    std::vector<std::uint8_t>::const_iterator &it,
    const std::vector<std::uint8_t> &data) {
  some_struct ns;
  if (!read_field(ns.field_0, it, data, packet_size))
    return false;
  if (!read_field(ns.field_1, it, data, packet_size))
    return false;
  field_0.push_back(ns);

  return true;
}
std::vector<std::uint8_t> GameServerPacket414::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  std::uint8_t struct_count = static_cast<std::uint8_t>(field_0.size());
  pack_field(struct_count, data);
  for (const auto &ns : field_0) {
    pack_field(ns.field_0, data);
    pack_field(ns.field_1, data);
  }
  return data;
}
GameServerCreateMissionProgress::GameServerCreateMissionProgress(
    const std::vector<std::uint8_t> &data)
    : PacketReader(415) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerCreateMissionProgress::get_packet_name() const {
  return "GameServerCreateMissionProgress";
}

std::string GameServerCreateMissionProgress::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerCreateMissionProgress"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  ss << "  field_7: " << field_7 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerCreateMissionProgress::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerCreateMissionProgress::get_packet_size() const {
  return packet_size;
}
bool GameServerCreateMissionProgress::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 122, it, data, packet_size))
    return false;
  if (!read_string(field_2, 122, it, data, packet_size))
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

  return true;
}
std::vector<std::uint8_t> GameServerCreateMissionProgress::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_string(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_field(field_6, data);
  pack_field(field_7, data);
  return data;
}
GameServerPacket416::GameServerPacket416(const std::vector<std::uint8_t> &data)
    : PacketReader(416) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket416::get_packet_name() const {
  return "GameServerPacket416";
}

std::string GameServerPacket416::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket416"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket416::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket416::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket416::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket416::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerUpdateMissionProgress::GameServerUpdateMissionProgress(
    const std::vector<std::uint8_t> &data)
    : PacketReader(417) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerUpdateMissionProgress::get_packet_name() const {
  return "GameServerUpdateMissionProgress";
}

std::string GameServerUpdateMissionProgress::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerUpdateMissionProgress"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerUpdateMissionProgress::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerUpdateMissionProgress::get_packet_size() const {
  return packet_size;
}
bool GameServerUpdateMissionProgress::parse(
    const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameServerUpdateMissionProgress::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  return data;
}
GameServerPacket418::GameServerPacket418(const std::vector<std::uint8_t> &data)
    : PacketReader(418) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket418::get_packet_name() const {
  return "GameServerPacket418";
}

std::string GameServerPacket418::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket418"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket418::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket418::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket418::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 122, it, data, packet_size))
    return false;
  if (!read_string(field_2, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket418::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_string(field_2, data);
  return data;
}
GameServerPacket419::GameServerPacket419(const std::vector<std::uint8_t> &data)
    : PacketReader(419) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket419::get_packet_name() const {
  return "GameServerPacket419";
}

std::string GameServerPacket419::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket419"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  ss << "  field_7: " << field_7.x << " " << field_7.y << "\n";
  ss << "  field_8: " << field_8 << "\n";
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << common::u16string_to_string(field_11) << "\n";
  ss << "  field_12: ";
  for (const auto &item : field_12) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket419::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket419::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket419::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_vec2(field_7, it, data, packet_size))
    return false;
  if (!read_field(field_8, it, data, packet_size))
    return false;
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_string(field_11, 20, it, data, packet_size))
    return false;
  if (!read_blob(field_12, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket419::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_field(field_6, data);
  pack_vec2(field_7, data);
  pack_field(field_8, data);
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_string(field_11, data);
  pack_blob(field_12, data);
  return data;
}
GameServerTransferGameServerInfo::GameServerTransferGameServerInfo(
    const std::vector<std::uint8_t> &data)
    : PacketReader(420) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerTransferGameServerInfo::get_packet_name() const {
  return "GameServerTransferGameServerInfo";
}

std::string GameServerTransferGameServerInfo::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerTransferGameServerInfo"
     << "\n";
  ss << "  host: ";
  for (const auto &item : host) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  world_id: " << world_id << "\n";
  ss << "  region: " << region << "\n";
  ss << "  map_id: " << map_id << "\n";
  ss << "  is_explorable: " << is_explorable << "\n";
  ss << "  player_id: " << player_id << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerTransferGameServerInfo::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerTransferGameServerInfo::get_packet_size() const {
  return packet_size;
}
bool GameServerTransferGameServerInfo::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_blob(host, it, data, packet_size))
    return false;
  if (!read_field(world_id, it, data, packet_size))
    return false;
  if (!read_field(region, it, data, packet_size))
    return false;
  if (!read_field(map_id, it, data, packet_size))
    return false;
  if (!read_field(is_explorable, it, data, packet_size))
    return false;
  if (!read_field(player_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerTransferGameServerInfo::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_blob(host, data);
  pack_field(world_id, data);
  pack_field(region, data);
  pack_field(map_id, data);
  pack_field(is_explorable, data);
  pack_field(player_id, data);
  return data;
}
GameServerPacket421::GameServerPacket421(const std::vector<std::uint8_t> &data)
    : PacketReader(421) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket421::get_packet_name() const {
  return "GameServerPacket421";
}

std::string GameServerPacket421::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket421"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << common::u16string_to_string(field_5) << "\n";
  ss << "  field_6: " << field_6 << "\n";
  ss << "  field_7: " << field_7 << "\n";
  ss << "  field_8: " << field_8 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket421::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket421::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket421::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_string(field_3, 122, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_string(field_5, 122, it, data, packet_size))
    return false;
  if (!read_field(field_6, it, data, packet_size))
    return false;
  if (!read_field(field_7, it, data, packet_size))
    return false;
  if (!read_field(field_8, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket421::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_string(field_3, data);
  pack_field(field_4, data);
  pack_string(field_5, data);
  pack_field(field_6, data);
  pack_field(field_7, data);
  pack_field(field_8, data);
  return data;
}
GameServerPacket422::GameServerPacket422(const std::vector<std::uint8_t> &data)
    : PacketReader(422) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket422::get_packet_name() const {
  return "GameServerPacket422";
}

std::string GameServerPacket422::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket422"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket422::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket422::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket422::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket422::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket423::GameServerPacket423(const std::vector<std::uint8_t> &data)
    : PacketReader(423) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket423::get_packet_name() const {
  return "GameServerPacket423";
}

std::string GameServerPacket423::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket423"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket423::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket423::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket423::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket423::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket424::GameServerPacket424(const std::vector<std::uint8_t> &data)
    : PacketReader(424) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket424::get_packet_name() const {
  return "GameServerPacket424";
}

std::string GameServerPacket424::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket424"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket424::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket424::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket424::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket424::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket425::GameServerPacket425(const std::vector<std::uint8_t> &data)
    : PacketReader(425) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket425::get_packet_name() const {
  return "GameServerPacket425";
}

std::string GameServerPacket425::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket425"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket425::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket425::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket425::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket425::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerReadyForMapSpawn::GameServerReadyForMapSpawn(
    const std::vector<std::uint8_t> &data)
    : PacketReader(426) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerReadyForMapSpawn::get_packet_name() const {
  return "GameServerReadyForMapSpawn";
}

std::string GameServerReadyForMapSpawn::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerReadyForMapSpawn"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerReadyForMapSpawn::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerReadyForMapSpawn::get_packet_size() const {
  return packet_size;
}
bool GameServerReadyForMapSpawn::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerReadyForMapSpawn::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket427::GameServerPacket427(const std::vector<std::uint8_t> &data)
    : PacketReader(427) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket427::get_packet_name() const {
  return "GameServerPacket427";
}

std::string GameServerPacket427::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket427"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << common::u16string_to_string(field_3) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket427::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket427::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket427::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_string(field_3, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket427::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_string(field_3, data);
  return data;
}
GameServerPacket428::GameServerPacket428(const std::vector<std::uint8_t> &data)
    : PacketReader(428) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket428::get_packet_name() const {
  return "GameServerPacket428";
}

std::string GameServerPacket428::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket428"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << common::u16string_to_string(field_5) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket428::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket428::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket428::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_string(field_5, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket428::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_string(field_5, data);
  return data;
}
GameServerPacket429::GameServerPacket429(const std::vector<std::uint8_t> &data)
    : PacketReader(429) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket429::get_packet_name() const {
  return "GameServerPacket429";
}

std::string GameServerPacket429::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket429"
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
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << common::u16string_to_string(field_10) << "\n";
  ss << "  field_11: " << common::u16string_to_string(field_11) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket429::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket429::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket429::parse(const std::vector<std::uint8_t> &data) {
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
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_string(field_10, 32, it, data, packet_size))
    return false;
  if (!read_string(field_11, 6, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket429::pack() const {
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
  pack_field(field_9, data);
  pack_string(field_10, data);
  pack_string(field_11, data);
  return data;
}
GameServerDOACompleteZone::GameServerDOACompleteZone(
    const std::vector<std::uint8_t> &data)
    : PacketReader(430) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerDOACompleteZone::get_packet_name() const {
  return "GameServerDOACompleteZone";
}

std::string GameServerDOACompleteZone::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerDOACompleteZone"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerDOACompleteZone::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerDOACompleteZone::get_packet_size() const {
  return packet_size;
}
bool GameServerDOACompleteZone::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerDOACompleteZone::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerPacket431::GameServerPacket431(const std::vector<std::uint8_t> &data)
    : PacketReader(431) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket431::get_packet_name() const {
  return "GameServerPacket431";
}

std::string GameServerPacket431::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket431"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket431::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket431::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket431::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket431::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket432::GameServerPacket432(const std::vector<std::uint8_t> &data)
    : PacketReader(432) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket432::get_packet_name() const {
  return "GameServerPacket432";
}

std::string GameServerPacket432::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket432"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket432::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket432::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket432::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPacket432::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket433::GameServerPacket433(const std::vector<std::uint8_t> &data)
    : PacketReader(433) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket433::get_packet_name() const {
  return "GameServerPacket433";
}

std::string GameServerPacket433::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket433"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket433::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket433::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket433::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket433::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket434::GameServerPacket434(const std::vector<std::uint8_t> &data)
    : PacketReader(434) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket434::get_packet_name() const {
  return "GameServerPacket434";
}

std::string GameServerPacket434::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket434"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket434::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket434::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket434::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 32, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_field(field_5, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket434::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  return data;
}
GameServerPacket435::GameServerPacket435(const std::vector<std::uint8_t> &data)
    : PacketReader(435) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket435::get_packet_name() const {
  return "GameServerPacket435";
}

std::string GameServerPacket435::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket435"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket435::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket435::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket435::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket435::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket436::GameServerPacket436(const std::vector<std::uint8_t> &data)
    : PacketReader(436) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket436::get_packet_name() const {
  return "GameServerPacket436";
}

std::string GameServerPacket436::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket436"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket436::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket436::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket436::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 32, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_field(field_5, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket436::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  return data;
}
GameServerPacket437::GameServerPacket437(const std::vector<std::uint8_t> &data)
    : PacketReader(437) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket437::get_packet_name() const {
  return "GameServerPacket437";
}

std::string GameServerPacket437::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket437"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket437::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket437::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket437::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket437::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket438::GameServerPacket438(const std::vector<std::uint8_t> &data)
    : PacketReader(438) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket438::get_packet_name() const {
  return "GameServerPacket438";
}

std::string GameServerPacket438::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket438"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket438::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket438::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket438::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket438::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket439::GameServerPacket439(const std::vector<std::uint8_t> &data)
    : PacketReader(439) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket439::get_packet_name() const {
  return "GameServerPacket439";
}

std::string GameServerPacket439::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket439"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket439::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket439::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket439::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket439::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket440::GameServerPacket440(const std::vector<std::uint8_t> &data)
    : PacketReader(440) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket440::get_packet_name() const {
  return "GameServerPacket440";
}

std::string GameServerPacket440::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket440"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket440::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket440::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket440::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket440::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket441::GameServerPacket441(const std::vector<std::uint8_t> &data)
    : PacketReader(441) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket441::get_packet_name() const {
  return "GameServerPacket441";
}

std::string GameServerPacket441::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket441"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket441::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket441::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket441::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket441::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerInstanceTravelTimer::GameServerInstanceTravelTimer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(442) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInstanceTravelTimer::get_packet_name() const {
  return "GameServerInstanceTravelTimer";
}

std::string GameServerInstanceTravelTimer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInstanceTravelTimer"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerInstanceTravelTimer::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInstanceTravelTimer::get_packet_size() const {
  return packet_size;
}
bool GameServerInstanceTravelTimer::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerInstanceTravelTimer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  return data;
}
GameServerInstanceCantEnter::GameServerInstanceCantEnter(
    const std::vector<std::uint8_t> &data)
    : PacketReader(443) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerInstanceCantEnter::get_packet_name() const {
  return "GameServerInstanceCantEnter";
}

std::string GameServerInstanceCantEnter::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerInstanceCantEnter"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerInstanceCantEnter::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerInstanceCantEnter::get_packet_size() const {
  return packet_size;
}
bool GameServerInstanceCantEnter::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerInstanceCantEnter::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket444::GameServerPacket444(const std::vector<std::uint8_t> &data)
    : PacketReader(444) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket444::get_packet_name() const {
  return "GameServerPacket444";
}

std::string GameServerPacket444::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket444"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket444::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket444::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket444::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket444::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPartySetDifficulty::GameServerPartySetDifficulty(
    const std::vector<std::uint8_t> &data)
    : PacketReader(445) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartySetDifficulty::get_packet_name() const {
  return "GameServerPartySetDifficulty";
}

std::string GameServerPartySetDifficulty::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartySetDifficulty"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPartySetDifficulty::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartySetDifficulty::get_packet_size() const {
  return packet_size;
}
bool GameServerPartySetDifficulty::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartySetDifficulty::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPartyHenchmanAdd::GameServerPartyHenchmanAdd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(446) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyHenchmanAdd::get_packet_name() const {
  return "GameServerPartyHenchmanAdd";
}

std::string GameServerPartyHenchmanAdd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyHenchmanAdd"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartyHenchmanAdd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyHenchmanAdd::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyHenchmanAdd::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 20, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyHenchmanAdd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  return data;
}
GameServerPartyHenchmanRemove::GameServerPartyHenchmanRemove(
    const std::vector<std::uint8_t> &data)
    : PacketReader(447) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyHenchmanRemove::get_packet_name() const {
  return "GameServerPartyHenchmanRemove";
}

std::string GameServerPartyHenchmanRemove::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyHenchmanRemove"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPartyHenchmanRemove::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyHenchmanRemove::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyHenchmanRemove::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyHenchmanRemove::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket448::GameServerPacket448(const std::vector<std::uint8_t> &data)
    : PacketReader(448) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket448::get_packet_name() const {
  return "GameServerPacket448";
}

std::string GameServerPacket448::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket448"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket448::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket448::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket448::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket448::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPartyHeroAdd::GameServerPartyHeroAdd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(449) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyHeroAdd::get_packet_name() const {
  return "GameServerPartyHeroAdd";
}

std::string GameServerPartyHeroAdd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyHeroAdd"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartyHeroAdd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyHeroAdd::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyHeroAdd::parse(const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameServerPartyHeroAdd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  return data;
}
GameServerPartyHeroRemove::GameServerPartyHeroRemove(
    const std::vector<std::uint8_t> &data)
    : PacketReader(450) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyHeroRemove::get_packet_name() const {
  return "GameServerPartyHeroRemove";
}

std::string GameServerPartyHeroRemove::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyHeroRemove"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartyHeroRemove::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyHeroRemove::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyHeroRemove::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPartyHeroRemove::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPartyInviteAdd::GameServerPartyInviteAdd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(451) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyInviteAdd::get_packet_name() const {
  return "GameServerPartyInviteAdd";
}

std::string GameServerPartyInviteAdd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyInviteAdd"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartyInviteAdd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyInviteAdd::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyInviteAdd::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyInviteAdd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPartyJoinRequest::GameServerPartyJoinRequest(
    const std::vector<std::uint8_t> &data)
    : PacketReader(452) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyJoinRequest::get_packet_name() const {
  return "GameServerPartyJoinRequest";
}

std::string GameServerPartyJoinRequest::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyJoinRequest"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartyJoinRequest::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyJoinRequest::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyJoinRequest::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyJoinRequest::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPartyInviteCancel::GameServerPartyInviteCancel(
    const std::vector<std::uint8_t> &data)
    : PacketReader(453) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyInviteCancel::get_packet_name() const {
  return "GameServerPartyInviteCancel";
}

std::string GameServerPartyInviteCancel::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyInviteCancel"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartyInviteCancel::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyInviteCancel::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyInviteCancel::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyInviteCancel::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPartyRequestCancel::GameServerPartyRequestCancel(
    const std::vector<std::uint8_t> &data)
    : PacketReader(454) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyRequestCancel::get_packet_name() const {
  return "GameServerPartyRequestCancel";
}

std::string GameServerPartyRequestCancel::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyRequestCancel"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPartyRequestCancel::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyRequestCancel::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyRequestCancel::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyRequestCancel::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPartyRequestResponse::GameServerPartyRequestResponse(
    const std::vector<std::uint8_t> &data)
    : PacketReader(455) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyRequestResponse::get_packet_name() const {
  return "GameServerPartyRequestResponse";
}

std::string GameServerPartyRequestResponse::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyRequestResponse"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPartyRequestResponse::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyRequestResponse::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyRequestResponse::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyRequestResponse::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPartyInviteResponse::GameServerPartyInviteResponse(
    const std::vector<std::uint8_t> &data)
    : PacketReader(456) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyInviteResponse::get_packet_name() const {
  return "GameServerPartyInviteResponse";
}

std::string GameServerPartyInviteResponse::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyInviteResponse"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPartyInviteResponse::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyInviteResponse::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyInviteResponse::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyInviteResponse::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPartyYouAreLeader::GameServerPartyYouAreLeader(
    const std::vector<std::uint8_t> &data)
    : PacketReader(457) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyYouAreLeader::get_packet_name() const {
  return "GameServerPartyYouAreLeader";
}

std::string GameServerPartyYouAreLeader::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyYouAreLeader"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartyYouAreLeader::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyYouAreLeader::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyYouAreLeader::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyYouAreLeader::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPartyPlayerAdd::GameServerPartyPlayerAdd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(458) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyPlayerAdd::get_packet_name() const {
  return "GameServerPartyPlayerAdd";
}

std::string GameServerPartyPlayerAdd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyPlayerAdd"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartyPlayerAdd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyPlayerAdd::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyPlayerAdd::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPartyPlayerAdd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket459::GameServerPacket459(const std::vector<std::uint8_t> &data)
    : PacketReader(459) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket459::get_packet_name() const {
  return "GameServerPacket459";
}

std::string GameServerPacket459::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket459"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket459::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket459::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket459::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket459::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket460::GameServerPacket460(const std::vector<std::uint8_t> &data)
    : PacketReader(460) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket460::get_packet_name() const {
  return "GameServerPacket460";
}

std::string GameServerPacket460::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket460"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket460::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket460::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket460::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket460::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket461::GameServerPacket461(const std::vector<std::uint8_t> &data)
    : PacketReader(461) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket461::get_packet_name() const {
  return "GameServerPacket461";
}

std::string GameServerPacket461::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket461"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket461::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket461::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket461::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket461::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPacket462::GameServerPacket462(const std::vector<std::uint8_t> &data)
    : PacketReader(462) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket462::get_packet_name() const {
  return "GameServerPacket462";
}

std::string GameServerPacket462::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket462"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket462::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket462::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket462::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket462::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPartyPlayerRemove::GameServerPartyPlayerRemove(
    const std::vector<std::uint8_t> &data)
    : PacketReader(463) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyPlayerRemove::get_packet_name() const {
  return "GameServerPartyPlayerRemove";
}

std::string GameServerPartyPlayerRemove::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyPlayerRemove"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartyPlayerRemove::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyPlayerRemove::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyPlayerRemove::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyPlayerRemove::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPartyPlayerReady::GameServerPartyPlayerReady(
    const std::vector<std::uint8_t> &data)
    : PacketReader(464) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyPlayerReady::get_packet_name() const {
  return "GameServerPartyPlayerReady";
}

std::string GameServerPartyPlayerReady::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyPlayerReady"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartyPlayerReady::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyPlayerReady::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyPlayerReady::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPartyPlayerReady::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPartyCreate::GameServerPartyCreate(
    const std::vector<std::uint8_t> &data)
    : PacketReader(465) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyCreate::get_packet_name() const {
  return "GameServerPartyCreate";
}

std::string GameServerPartyCreate::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyCreate"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartyCreate::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyCreate::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyCreate::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyCreate::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPartyMemberStreamEnd::GameServerPartyMemberStreamEnd(
    const std::vector<std::uint8_t> &data)
    : PacketReader(466) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyMemberStreamEnd::get_packet_name() const {
  return "GameServerPartyMemberStreamEnd";
}

std::string GameServerPartyMemberStreamEnd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyMemberStreamEnd"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPartyMemberStreamEnd::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyMemberStreamEnd::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyMemberStreamEnd::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyMemberStreamEnd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket467::GameServerPacket467(const std::vector<std::uint8_t> &data)
    : PacketReader(467) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket467::get_packet_name() const {
  return "GameServerPacket467";
}

std::string GameServerPacket467::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket467"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket467::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket467::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket467::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket467::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerPacket468::GameServerPacket468(const std::vector<std::uint8_t> &data)
    : PacketReader(468) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket468::get_packet_name() const {
  return "GameServerPacket468";
}

std::string GameServerPacket468::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket468"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket468::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket468::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket468::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket468::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPacket469::GameServerPacket469(const std::vector<std::uint8_t> &data)
    : PacketReader(469) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket469::get_packet_name() const {
  return "GameServerPacket469";
}

std::string GameServerPacket469::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket469"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket469::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket469::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket469::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket469::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket470::GameServerPacket470(const std::vector<std::uint8_t> &data)
    : PacketReader(470) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket470::get_packet_name() const {
  return "GameServerPacket470";
}

std::string GameServerPacket470::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket470"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_1: "
     << "\n";
  for (const auto &ns : field_1) {
    ss << "    field_0: " << ns.field_0 << "\n";
    ss << "    field_1: " << ns.field_1 << "\n";
    ss << "    field_2: " << ns.field_2 << "\n";
  }
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket470::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket470::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket470::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 16, it, data, packet_size))
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
bool GameServerPacket470::read_struct(
    std::vector<std::uint8_t>::const_iterator &it,
    const std::vector<std::uint8_t> &data) {
  some_struct ns;
  if (!read_field(ns.field_0, it, data, packet_size))
    return false;
  if (!read_field(ns.field_1, it, data, packet_size))
    return false;
  if (!read_field(ns.field_2, it, data, packet_size))
    return false;
  field_1.push_back(ns);

  return true;
}
std::vector<std::uint8_t> GameServerPacket470::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  std::uint8_t struct_count = static_cast<std::uint8_t>(field_1.size());
  pack_field(struct_count, data);
  for (const auto &ns : field_1) {
    pack_field(ns.field_0, data);
    pack_field(ns.field_1, data);
    pack_field(ns.field_2, data);
  }
  return data;
}
GameServerPartyDefeated::GameServerPartyDefeated(
    const std::vector<std::uint8_t> &data)
    : PacketReader(471) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyDefeated::get_packet_name() const {
  return "GameServerPartyDefeated";
}

std::string GameServerPartyDefeated::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyDefeated"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartyDefeated::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyDefeated::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyDefeated::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyDefeated::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameServerPartyLock::GameServerPartyLock(const std::vector<std::uint8_t> &data)
    : PacketReader(472) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartyLock::get_packet_name() const {
  return "GameServerPartyLock";
}

std::string GameServerPartyLock::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartyLock"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartyLock::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartyLock::get_packet_size() const {
  return packet_size;
}
bool GameServerPartyLock::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartyLock::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  return data;
}
GameServerPacket473::GameServerPacket473(const std::vector<std::uint8_t> &data)
    : PacketReader(473) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket473::get_packet_name() const {
  return "GameServerPacket473";
}

std::string GameServerPacket473::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket473"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket473::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket473::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket473::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket473::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPartySearchRequestJoin::GameServerPartySearchRequestJoin(
    const std::vector<std::uint8_t> &data)
    : PacketReader(474) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartySearchRequestJoin::get_packet_name() const {
  return "GameServerPartySearchRequestJoin";
}

std::string GameServerPartySearchRequestJoin::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartySearchRequestJoin"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPartySearchRequestJoin::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartySearchRequestJoin::get_packet_size() const {
  return packet_size;
}
bool GameServerPartySearchRequestJoin::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartySearchRequestJoin::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPartySearchRequestDone::GameServerPartySearchRequestDone(
    const std::vector<std::uint8_t> &data)
    : PacketReader(475) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartySearchRequestDone::get_packet_name() const {
  return "GameServerPartySearchRequestDone";
}

std::string GameServerPartySearchRequestDone::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartySearchRequestDone"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPartySearchRequestDone::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartySearchRequestDone::get_packet_size() const {
  return packet_size;
}
bool GameServerPartySearchRequestDone::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartySearchRequestDone::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameServerPartySearchAdvertisement::GameServerPartySearchAdvertisement(
    const std::vector<std::uint8_t> &data)
    : PacketReader(476) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartySearchAdvertisement::get_packet_name() const {
  return "GameServerPartySearchAdvertisement";
}

std::string
GameServerPartySearchAdvertisement::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartySearchAdvertisement"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  ss << "  field_7: " << common::u16string_to_string(field_7) << "\n";
  ss << "  field_8: " << common::u16string_to_string(field_8) << "\n";
  ss << "  field_9: " << field_9 << "\n";
  ss << "  field_10: " << field_10 << "\n";
  ss << "  field_11: " << field_11 << "\n";
  ss << "  field_12: " << field_12 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameServerPartySearchAdvertisement::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartySearchAdvertisement::get_packet_size() const {
  return packet_size;
}
bool GameServerPartySearchAdvertisement::parse(
    const std::vector<std::uint8_t> &data) {
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
  if (!read_string(field_7, 32, it, data, packet_size))
    return false;
  if (!read_string(field_8, 20, it, data, packet_size))
    return false;
  if (!read_field(field_9, it, data, packet_size))
    return false;
  if (!read_field(field_10, it, data, packet_size))
    return false;
  if (!read_field(field_11, it, data, packet_size))
    return false;
  if (!read_field(field_12, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartySearchAdvertisement::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_field(field_6, data);
  pack_string(field_7, data);
  pack_string(field_8, data);
  pack_field(field_9, data);
  pack_field(field_10, data);
  pack_field(field_11, data);
  pack_field(field_12, data);
  return data;
}
GameServerPartySearchSeek::GameServerPartySearchSeek(
    const std::vector<std::uint8_t> &data)
    : PacketReader(477) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartySearchSeek::get_packet_name() const {
  return "GameServerPartySearchSeek";
}

std::string GameServerPartySearchSeek::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartySearchSeek"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartySearchSeek::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartySearchSeek::get_packet_size() const {
  return packet_size;
}
bool GameServerPartySearchSeek::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartySearchSeek::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPartySearchRemove::GameServerPartySearchRemove(
    const std::vector<std::uint8_t> &data)
    : PacketReader(478) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartySearchRemove::get_packet_name() const {
  return "GameServerPartySearchRemove";
}

std::string GameServerPartySearchRemove::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartySearchRemove"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartySearchRemove::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartySearchRemove::get_packet_size() const {
  return packet_size;
}
bool GameServerPartySearchRemove::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPartySearchRemove::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPartySearchSize::GameServerPartySearchSize(
    const std::vector<std::uint8_t> &data)
    : PacketReader(479) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartySearchSize::get_packet_name() const {
  return "GameServerPartySearchSize";
}

std::string GameServerPartySearchSize::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartySearchSize"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartySearchSize::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartySearchSize::get_packet_size() const {
  return packet_size;
}
bool GameServerPartySearchSize::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPartySearchSize::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPartySearchType::GameServerPartySearchType(
    const std::vector<std::uint8_t> &data)
    : PacketReader(480) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPartySearchType::get_packet_name() const {
  return "GameServerPartySearchType";
}

std::string GameServerPartySearchType::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPartySearchType"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPartySearchType::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPartySearchType::get_packet_size() const {
  return packet_size;
}
bool GameServerPartySearchType::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameServerPartySearchType::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameServerPacket481::GameServerPacket481(const std::vector<std::uint8_t> &data)
    : PacketReader(481) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket481::get_packet_name() const {
  return "GameServerPacket481";
}

std::string GameServerPacket481::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket481"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket481::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket481::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket481::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket481::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket482::GameServerPacket482(const std::vector<std::uint8_t> &data)
    : PacketReader(482) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket482::get_packet_name() const {
  return "GameServerPacket482";
}

std::string GameServerPacket482::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket482"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket482::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket482::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket482::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket482::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameServerPacket483::GameServerPacket483(const std::vector<std::uint8_t> &data)
    : PacketReader(483) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket483::get_packet_name() const {
  return "GameServerPacket483";
}

std::string GameServerPacket483::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket483"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket483::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket483::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket483::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket483::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameServerPacket484::GameServerPacket484(const std::vector<std::uint8_t> &data)
    : PacketReader(484) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameServerPacket484::get_packet_name() const {
  return "GameServerPacket484";
}

std::string GameServerPacket484::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameServerPacket484"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameServerPacket484::get_packed_data() const {
  return pack();
}
std::uint16_t GameServerPacket484::get_packet_size() const {
  return packet_size;
}
bool GameServerPacket484::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameServerPacket484::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
} // namespace common
} // namespace utopia
