#include "utopia/utopia_pch.hpp"

#include "utopia/common/network/packets/generated/game_client_packets.hpp"

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
GameClientTradeAcknowledge::GameClientTradeAcknowledge(
    const std::vector<std::uint8_t> &data)
    : PacketReader(0) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientTradeAcknowledge::get_packet_name() const {
  return "GameClientTradeAcknowledge";
}

std::string GameClientTradeAcknowledge::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientTradeAcknowledge"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientTradeAcknowledge::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientTradeAcknowledge::get_packet_size() const {
  return packet_size;
}
bool GameClientTradeAcknowledge::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientTradeAcknowledge::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientTradeCancel::GameClientTradeCancel(
    const std::vector<std::uint8_t> &data)
    : PacketReader(1) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientTradeCancel::get_packet_name() const {
  return "GameClientTradeCancel";
}

std::string GameClientTradeCancel::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientTradeCancel"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientTradeCancel::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientTradeCancel::get_packet_size() const {
  return packet_size;
}
bool GameClientTradeCancel::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientTradeCancel::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientTradeAddItem::GameClientTradeAddItem(
    const std::vector<std::uint8_t> &data)
    : PacketReader(2) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientTradeAddItem::get_packet_name() const {
  return "GameClientTradeAddItem";
}

std::string GameClientTradeAddItem::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientTradeAddItem"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientTradeAddItem::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientTradeAddItem::get_packet_size() const {
  return packet_size;
}
bool GameClientTradeAddItem::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientTradeAddItem::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientTradeSendOffer::GameClientTradeSendOffer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(3) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientTradeSendOffer::get_packet_name() const {
  return "GameClientTradeSendOffer";
}

std::string GameClientTradeSendOffer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientTradeSendOffer"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientTradeSendOffer::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientTradeSendOffer::get_packet_size() const {
  return packet_size;
}
bool GameClientTradeSendOffer::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientTradeSendOffer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket004::GameClientPacket004(const std::vector<std::uint8_t> &data)
    : PacketReader(4) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket004::get_packet_name() const {
  return "GameClientPacket004";
}

std::string GameClientPacket004::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket004"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket004::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket004::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket004::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket004::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientTradeRemoveItem::GameClientTradeRemoveItem(
    const std::vector<std::uint8_t> &data)
    : PacketReader(5) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientTradeRemoveItem::get_packet_name() const {
  return "GameClientTradeRemoveItem";
}

std::string GameClientTradeRemoveItem::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientTradeRemoveItem"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientTradeRemoveItem::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientTradeRemoveItem::get_packet_size() const {
  return packet_size;
}
bool GameClientTradeRemoveItem::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientTradeRemoveItem::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientTradeCancelOffer::GameClientTradeCancelOffer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(6) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientTradeCancelOffer::get_packet_name() const {
  return "GameClientTradeCancelOffer";
}

std::string GameClientTradeCancelOffer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientTradeCancelOffer"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientTradeCancelOffer::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientTradeCancelOffer::get_packet_size() const {
  return packet_size;
}
bool GameClientTradeCancelOffer::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientTradeCancelOffer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientTradeAccept::GameClientTradeAccept(
    const std::vector<std::uint8_t> &data)
    : PacketReader(7) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientTradeAccept::get_packet_name() const {
  return "GameClientTradeAccept";
}

std::string GameClientTradeAccept::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientTradeAccept"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientTradeAccept::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientTradeAccept::get_packet_size() const {
  return packet_size;
}
bool GameClientTradeAccept::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientTradeAccept::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientDisconnect::GameClientDisconnect(
    const std::vector<std::uint8_t> &data)
    : PacketReader(8) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientDisconnect::get_packet_name() const {
  return "GameClientDisconnect";
}

std::string GameClientDisconnect::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientDisconnect"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientDisconnect::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientDisconnect::get_packet_size() const {
  return packet_size;
}
bool GameClientDisconnect::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientDisconnect::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPingReply::GameClientPingReply(const std::vector<std::uint8_t> &data)
    : PacketReader(9) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPingReply::get_packet_name() const {
  return "GameClientPingReply";
}

std::string GameClientPingReply::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPingReply"
     << "\n";
  ss << "  value: " << value << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPingReply::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPingReply::get_packet_size() const {
  return packet_size;
}
bool GameClientPingReply::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(value, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPingReply::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(value, data);
  return data;
}
GameClientHeartbeat::GameClientHeartbeat(const std::vector<std::uint8_t> &data)
    : PacketReader(10) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientHeartbeat::get_packet_name() const {
  return "GameClientHeartbeat";
}

std::string GameClientHeartbeat::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientHeartbeat"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientHeartbeat::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientHeartbeat::get_packet_size() const {
  return packet_size;
}
bool GameClientHeartbeat::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientHeartbeat::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPingRequest::GameClientPingRequest(
    const std::vector<std::uint8_t> &data)
    : PacketReader(11) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPingRequest::get_packet_name() const {
  return "GameClientPingRequest";
}

std::string GameClientPingRequest::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPingRequest"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPingRequest::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPingRequest::get_packet_size() const {
  return packet_size;
}
bool GameClientPingRequest::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPingRequest::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientAttributeDecrease::GameClientAttributeDecrease(
    const std::vector<std::uint8_t> &data)
    : PacketReader(12) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientAttributeDecrease::get_packet_name() const {
  return "GameClientAttributeDecrease";
}

std::string GameClientAttributeDecrease::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientAttributeDecrease"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientAttributeDecrease::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientAttributeDecrease::get_packet_size() const {
  return packet_size;
}
bool GameClientAttributeDecrease::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientAttributeDecrease::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientAttributeIncrease::GameClientAttributeIncrease(
    const std::vector<std::uint8_t> &data)
    : PacketReader(13) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientAttributeIncrease::get_packet_name() const {
  return "GameClientAttributeIncrease";
}

std::string GameClientAttributeIncrease::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientAttributeIncrease"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientAttributeIncrease::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientAttributeIncrease::get_packet_size() const {
  return packet_size;
}
bool GameClientAttributeIncrease::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientAttributeIncrease::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientAttributeLoad::GameClientAttributeLoad(
    const std::vector<std::uint8_t> &data)
    : PacketReader(14) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientAttributeLoad::get_packet_name() const {
  return "GameClientAttributeLoad";
}

std::string GameClientAttributeLoad::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientAttributeLoad"
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
std::vector<std::uint8_t> GameClientAttributeLoad::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientAttributeLoad::get_packet_size() const {
  return packet_size;
}
bool GameClientAttributeLoad::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientAttributeLoad::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_array(field_1, data);
  pack_array(field_2, data);
  return data;
}
GameClientQuestAbandon::GameClientQuestAbandon(
    const std::vector<std::uint8_t> &data)
    : PacketReader(15) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientQuestAbandon::get_packet_name() const {
  return "GameClientQuestAbandon";
}

std::string GameClientQuestAbandon::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientQuestAbandon"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientQuestAbandon::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientQuestAbandon::get_packet_size() const {
  return packet_size;
}
bool GameClientQuestAbandon::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientQuestAbandon::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientQuestRequestInfos::GameClientQuestRequestInfos(
    const std::vector<std::uint8_t> &data)
    : PacketReader(16) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientQuestRequestInfos::get_packet_name() const {
  return "GameClientQuestRequestInfos";
}

std::string GameClientQuestRequestInfos::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientQuestRequestInfos"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientQuestRequestInfos::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientQuestRequestInfos::get_packet_size() const {
  return packet_size;
}
bool GameClientQuestRequestInfos::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientQuestRequestInfos::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket017::GameClientPacket017(const std::vector<std::uint8_t> &data)
    : PacketReader(17) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket017::get_packet_name() const {
  return "GameClientPacket017";
}

std::string GameClientPacket017::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket017"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket017::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket017::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket017::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket017::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket018::GameClientPacket018(const std::vector<std::uint8_t> &data)
    : PacketReader(18) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket018::get_packet_name() const {
  return "GameClientPacket018";
}

std::string GameClientPacket018::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket018"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket018::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket018::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket018::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket018::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientHeroBehavior::GameClientHeroBehavior(
    const std::vector<std::uint8_t> &data)
    : PacketReader(19) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientHeroBehavior::get_packet_name() const {
  return "GameClientHeroBehavior";
}

std::string GameClientHeroBehavior::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientHeroBehavior"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientHeroBehavior::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientHeroBehavior::get_packet_size() const {
  return packet_size;
}
bool GameClientHeroBehavior::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientHeroBehavior::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientHeroLockTarget::GameClientHeroLockTarget(
    const std::vector<std::uint8_t> &data)
    : PacketReader(20) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientHeroLockTarget::get_packet_name() const {
  return "GameClientHeroLockTarget";
}

std::string GameClientHeroLockTarget::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientHeroLockTarget"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientHeroLockTarget::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientHeroLockTarget::get_packet_size() const {
  return packet_size;
}
bool GameClientHeroLockTarget::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientHeroLockTarget::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket021::GameClientPacket021(const std::vector<std::uint8_t> &data)
    : PacketReader(21) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket021::get_packet_name() const {
  return "GameClientPacket021";
}

std::string GameClientPacket021::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket021"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket021::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket021::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket021::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket021::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket022::GameClientPacket022(const std::vector<std::uint8_t> &data)
    : PacketReader(22) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket022::get_packet_name() const {
  return "GameClientPacket022";
}

std::string GameClientPacket022::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket022"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket022::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket022::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket022::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket022::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientHeroSkillToggle::GameClientHeroSkillToggle(
    const std::vector<std::uint8_t> &data)
    : PacketReader(23) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientHeroSkillToggle::get_packet_name() const {
  return "GameClientHeroSkillToggle";
}

std::string GameClientHeroSkillToggle::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientHeroSkillToggle"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientHeroSkillToggle::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientHeroSkillToggle::get_packet_size() const {
  return packet_size;
}
bool GameClientHeroSkillToggle::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientHeroSkillToggle::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientHeroFlagSingle::GameClientHeroFlagSingle(
    const std::vector<std::uint8_t> &data)
    : PacketReader(24) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientHeroFlagSingle::get_packet_name() const {
  return "GameClientHeroFlagSingle";
}

std::string GameClientHeroFlagSingle::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientHeroFlagSingle"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1.x << " " << field_1.y << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientHeroFlagSingle::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientHeroFlagSingle::get_packet_size() const {
  return packet_size;
}
bool GameClientHeroFlagSingle::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientHeroFlagSingle::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_vec2(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientHeroFlagAll::GameClientHeroFlagAll(
    const std::vector<std::uint8_t> &data)
    : PacketReader(25) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientHeroFlagAll::get_packet_name() const {
  return "GameClientHeroFlagAll";
}

std::string GameClientHeroFlagAll::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientHeroFlagAll"
     << "\n";
  ss << "  field_0: " << field_0.x << " " << field_0.y << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientHeroFlagAll::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientHeroFlagAll::get_packet_size() const {
  return packet_size;
}
bool GameClientHeroFlagAll::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_vec2(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientHeroFlagAll::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_vec2(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientHeroUseSkill::GameClientHeroUseSkill(
    const std::vector<std::uint8_t> &data)
    : PacketReader(26) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientHeroUseSkill::get_packet_name() const {
  return "GameClientHeroUseSkill";
}

std::string GameClientHeroUseSkill::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientHeroUseSkill"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientHeroUseSkill::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientHeroUseSkill::get_packet_size() const {
  return packet_size;
}
bool GameClientHeroUseSkill::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientHeroUseSkill::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameClientPacket027::GameClientPacket027(const std::vector<std::uint8_t> &data)
    : PacketReader(27) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket027::get_packet_name() const {
  return "GameClientPacket027";
}

std::string GameClientPacket027::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket027"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket027::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket027::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket027::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket027::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientHeroAdd::GameClientHeroAdd(const std::vector<std::uint8_t> &data)
    : PacketReader(28) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientHeroAdd::get_packet_name() const {
  return "GameClientHeroAdd";
}

std::string GameClientHeroAdd::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientHeroAdd"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientHeroAdd::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientHeroAdd::get_packet_size() const { return packet_size; }
bool GameClientHeroAdd::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientHeroAdd::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientHeroKick::GameClientHeroKick(const std::vector<std::uint8_t> &data)
    : PacketReader(29) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientHeroKick::get_packet_name() const {
  return "GameClientHeroKick";
}

std::string GameClientHeroKick::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientHeroKick"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientHeroKick::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientHeroKick::get_packet_size() const {
  return packet_size;
}
bool GameClientHeroKick::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientHeroKick::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket030::GameClientPacket030(const std::vector<std::uint8_t> &data)
    : PacketReader(30) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket030::get_packet_name() const {
  return "GameClientPacket030";
}

std::string GameClientPacket030::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket030"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket030::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket030::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket030::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket030::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket031::GameClientPacket031(const std::vector<std::uint8_t> &data)
    : PacketReader(31) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket031::get_packet_name() const {
  return "GameClientPacket031";
}

std::string GameClientPacket031::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket031"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket031::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket031::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket031::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket031::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket032::GameClientPacket032(const std::vector<std::uint8_t> &data)
    : PacketReader(32) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket032::get_packet_name() const {
  return "GameClientPacket032";
}

std::string GameClientPacket032::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket032"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket032::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket032::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket032::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket032::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientTargetCall::GameClientTargetCall(
    const std::vector<std::uint8_t> &data)
    : PacketReader(33) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientTargetCall::get_packet_name() const {
  return "GameClientTargetCall";
}

std::string GameClientTargetCall::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientTargetCall"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientTargetCall::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientTargetCall::get_packet_size() const {
  return packet_size;
}
bool GameClientTargetCall::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientTargetCall::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket034::GameClientPacket034(const std::vector<std::uint8_t> &data)
    : PacketReader(34) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket034::get_packet_name() const {
  return "GameClientPacket034";
}

std::string GameClientPacket034::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket034"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket034::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket034::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket034::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket034::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPingWeaponSet::GameClientPingWeaponSet(
    const std::vector<std::uint8_t> &data)
    : PacketReader(35) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPingWeaponSet::get_packet_name() const {
  return "GameClientPingWeaponSet";
}

std::string GameClientPingWeaponSet::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPingWeaponSet"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPingWeaponSet::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPingWeaponSet::get_packet_size() const {
  return packet_size;
}
bool GameClientPingWeaponSet::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPingWeaponSet::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientAttackAgent::GameClientAttackAgent(
    const std::vector<std::uint8_t> &data)
    : PacketReader(36) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientAttackAgent::get_packet_name() const {
  return "GameClientAttackAgent";
}

std::string GameClientAttackAgent::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientAttackAgent"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientAttackAgent::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientAttackAgent::get_packet_size() const {
  return packet_size;
}
bool GameClientAttackAgent::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientAttackAgent::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket037::GameClientPacket037(const std::vector<std::uint8_t> &data)
    : PacketReader(37) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket037::get_packet_name() const {
  return "GameClientPacket037";
}

std::string GameClientPacket037::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket037"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket037::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket037::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket037::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket037::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameClientCancelMovement::GameClientCancelMovement(
    const std::vector<std::uint8_t> &data)
    : PacketReader(38) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientCancelMovement::get_packet_name() const {
  return "GameClientCancelMovement";
}

std::string GameClientCancelMovement::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientCancelMovement"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientCancelMovement::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientCancelMovement::get_packet_size() const {
  return packet_size;
}
bool GameClientCancelMovement::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientCancelMovement::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientDropBuff::GameClientDropBuff(const std::vector<std::uint8_t> &data)
    : PacketReader(39) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientDropBuff::get_packet_name() const {
  return "GameClientDropBuff";
}

std::string GameClientDropBuff::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientDropBuff"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientDropBuff::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientDropBuff::get_packet_size() const {
  return packet_size;
}
bool GameClientDropBuff::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientDropBuff::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket040::GameClientPacket040(const std::vector<std::uint8_t> &data)
    : PacketReader(40) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket040::get_packet_name() const {
  return "GameClientPacket040";
}

std::string GameClientPacket040::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket040"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket040::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket040::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket040::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket040::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientDrawMap::GameClientDrawMap(const std::vector<std::uint8_t> &data)
    : PacketReader(41) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientDrawMap::get_packet_name() const {
  return "GameClientDrawMap";
}

std::string GameClientDrawMap::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientDrawMap"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientDrawMap::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientDrawMap::get_packet_size() const { return packet_size; }
bool GameClientDrawMap::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_array(field_1, 16, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientDrawMap::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_array(field_1, data);
  return data;
}
GameClientDropItem::GameClientDropItem(const std::vector<std::uint8_t> &data)
    : PacketReader(42) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientDropItem::get_packet_name() const {
  return "GameClientDropItem";
}

std::string GameClientDropItem::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientDropItem"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientDropItem::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientDropItem::get_packet_size() const {
  return packet_size;
}
bool GameClientDropItem::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientDropItem::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket043::GameClientPacket043(const std::vector<std::uint8_t> &data)
    : PacketReader(43) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket043::get_packet_name() const {
  return "GameClientPacket043";
}

std::string GameClientPacket043::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket043"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket043::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket043::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket043::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket043::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket044::GameClientPacket044(const std::vector<std::uint8_t> &data)
    : PacketReader(44) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket044::get_packet_name() const {
  return "GameClientPacket044";
}

std::string GameClientPacket044::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket044"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket044::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket044::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket044::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket044::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientDropGold::GameClientDropGold(const std::vector<std::uint8_t> &data)
    : PacketReader(45) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientDropGold::get_packet_name() const {
  return "GameClientDropGold";
}

std::string GameClientDropGold::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientDropGold"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientDropGold::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientDropGold::get_packet_size() const {
  return packet_size;
}
bool GameClientDropGold::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientDropGold::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientEquipItem::GameClientEquipItem(const std::vector<std::uint8_t> &data)
    : PacketReader(46) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientEquipItem::get_packet_name() const {
  return "GameClientEquipItem";
}

std::string GameClientEquipItem::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientEquipItem"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientEquipItem::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientEquipItem::get_packet_size() const {
  return packet_size;
}
bool GameClientEquipItem::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientEquipItem::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket047::GameClientPacket047(const std::vector<std::uint8_t> &data)
    : PacketReader(47) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket047::get_packet_name() const {
  return "GameClientPacket047";
}

std::string GameClientPacket047::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket047"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket047::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket047::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket047::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket047::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket048::GameClientPacket048(const std::vector<std::uint8_t> &data)
    : PacketReader(48) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket048::get_packet_name() const {
  return "GameClientPacket048";
}

std::string GameClientPacket048::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket048"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket048::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket048::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket048::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket048::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientInteractPlayer::GameClientInteractPlayer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(49) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientInteractPlayer::get_packet_name() const {
  return "GameClientInteractPlayer";
}

std::string GameClientInteractPlayer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientInteractPlayer"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientInteractPlayer::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientInteractPlayer::get_packet_size() const {
  return packet_size;
}
bool GameClientInteractPlayer::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientInteractPlayer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket050::GameClientPacket050(const std::vector<std::uint8_t> &data)
    : PacketReader(50) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket050::get_packet_name() const {
  return "GameClientPacket050";
}

std::string GameClientPacket050::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket050"
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
std::vector<std::uint8_t> GameClientPacket050::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket050::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket050::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_array(field_2, 4, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket050::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_array(field_2, data);
  return data;
}
GameClientDepositFaction::GameClientDepositFaction(
    const std::vector<std::uint8_t> &data)
    : PacketReader(51) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientDepositFaction::get_packet_name() const {
  return "GameClientDepositFaction";
}

std::string GameClientDepositFaction::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientDepositFaction"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientDepositFaction::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientDepositFaction::get_packet_size() const {
  return packet_size;
}
bool GameClientDepositFaction::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientDepositFaction::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientPacket052::GameClientPacket052(const std::vector<std::uint8_t> &data)
    : PacketReader(52) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket052::get_packet_name() const {
  return "GameClientPacket052";
}

std::string GameClientPacket052::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket052"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket052::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket052::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket052::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket052::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_string(field_2, data);
  return data;
}
GameClientPacket053::GameClientPacket053(const std::vector<std::uint8_t> &data)
    : PacketReader(53) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket053::get_packet_name() const {
  return "GameClientPacket053";
}

std::string GameClientPacket053::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket053"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket053::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket053::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket053::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_array(field_1, 4, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket053::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_array(field_1, data);
  return data;
}
GameClientPacket054::GameClientPacket054(const std::vector<std::uint8_t> &data)
    : PacketReader(54) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket054::get_packet_name() const {
  return "GameClientPacket054";
}

std::string GameClientPacket054::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket054"
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
std::vector<std::uint8_t> GameClientPacket054::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket054::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket054::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket054::pack() const {
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
GameClientInteractLiving::GameClientInteractLiving(
    const std::vector<std::uint8_t> &data)
    : PacketReader(55) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientInteractLiving::get_packet_name() const {
  return "GameClientInteractLiving";
}

std::string GameClientInteractLiving::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientInteractLiving"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientInteractLiving::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientInteractLiving::get_packet_size() const {
  return packet_size;
}
bool GameClientInteractLiving::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientInteractLiving::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket056::GameClientPacket056(const std::vector<std::uint8_t> &data)
    : PacketReader(56) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket056::get_packet_name() const {
  return "GameClientPacket056";
}

std::string GameClientPacket056::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket056"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket056::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket056::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket056::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_array(field_1, 4, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket056::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_array(field_1, data);
  return data;
}
GameClientSendDialog::GameClientSendDialog(
    const std::vector<std::uint8_t> &data)
    : PacketReader(57) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientSendDialog::get_packet_name() const {
  return "GameClientSendDialog";
}

std::string GameClientSendDialog::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientSendDialog"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientSendDialog::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientSendDialog::get_packet_size() const {
  return packet_size;
}
bool GameClientSendDialog::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientSendDialog::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket058::GameClientPacket058(const std::vector<std::uint8_t> &data)
    : PacketReader(58) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket058::get_packet_name() const {
  return "GameClientPacket058";
}

std::string GameClientPacket058::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket058"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket058::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket058::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket058::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket058::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket059::GameClientPacket059(const std::vector<std::uint8_t> &data)
    : PacketReader(59) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket059::get_packet_name() const {
  return "GameClientPacket059";
}

std::string GameClientPacket059::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket059"
     << "\n";
  ss << "  field_0: " << field_0.x << " " << field_0.y << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2.x << " " << field_2.y << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket059::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket059::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket059::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_vec2(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_vec2(field_2, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket059::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_vec2(field_0, data);
  pack_field(field_1, data);
  pack_vec2(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameClientMoveToCoord::GameClientMoveToCoord(
    const std::vector<std::uint8_t> &data)
    : PacketReader(60) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientMoveToCoord::get_packet_name() const {
  return "GameClientMoveToCoord";
}

std::string GameClientMoveToCoord::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientMoveToCoord"
     << "\n";
  ss << "  field_0: " << field_0.x << " " << field_0.y << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientMoveToCoord::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientMoveToCoord::get_packet_size() const {
  return packet_size;
}
bool GameClientMoveToCoord::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_vec2(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientMoveToCoord::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_vec2(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientInteractItem::GameClientInteractItem(
    const std::vector<std::uint8_t> &data)
    : PacketReader(61) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientInteractItem::get_packet_name() const {
  return "GameClientInteractItem";
}

std::string GameClientInteractItem::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientInteractItem"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientInteractItem::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientInteractItem::get_packet_size() const {
  return packet_size;
}
bool GameClientInteractItem::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientInteractItem::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientRotatePlayer::GameClientRotatePlayer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(62) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientRotatePlayer::get_packet_name() const {
  return "GameClientRotatePlayer";
}

std::string GameClientRotatePlayer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientRotatePlayer"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientRotatePlayer::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientRotatePlayer::get_packet_size() const {
  return packet_size;
}
bool GameClientRotatePlayer::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientRotatePlayer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientChangeSecondProfession::GameClientChangeSecondProfession(
    const std::vector<std::uint8_t> &data)
    : PacketReader(63) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientChangeSecondProfession::get_packet_name() const {
  return "GameClientChangeSecondProfession";
}

std::string GameClientChangeSecondProfession::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientChangeSecondProfession"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientChangeSecondProfession::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientChangeSecondProfession::get_packet_size() const {
  return packet_size;
}
bool GameClientChangeSecondProfession::parse(
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
std::vector<std::uint8_t> GameClientChangeSecondProfession::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket064::GameClientPacket064(const std::vector<std::uint8_t> &data)
    : PacketReader(64) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket064::get_packet_name() const {
  return "GameClientPacket064";
}

std::string GameClientPacket064::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket064"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket064::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket064::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket064::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket064::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket065::GameClientPacket065(const std::vector<std::uint8_t> &data)
    : PacketReader(65) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket065::get_packet_name() const {
  return "GameClientPacket065";
}

std::string GameClientPacket065::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket065"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket065::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket065::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket065::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket065::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket066::GameClientPacket066(const std::vector<std::uint8_t> &data)
    : PacketReader(66) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket066::get_packet_name() const {
  return "GameClientPacket066";
}

std::string GameClientPacket066::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket066"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket066::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket066::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket066::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket066::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket067::GameClientPacket067(const std::vector<std::uint8_t> &data)
    : PacketReader(67) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket067::get_packet_name() const {
  return "GameClientPacket067";
}

std::string GameClientPacket067::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket067"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket067::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket067::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket067::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 256, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket067::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameClientUseSkill::GameClientUseSkill(const std::vector<std::uint8_t> &data)
    : PacketReader(68) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientUseSkill::get_packet_name() const {
  return "GameClientUseSkill";
}

std::string GameClientUseSkill::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientUseSkill"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientUseSkill::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientUseSkill::get_packet_size() const {
  return packet_size;
}
bool GameClientUseSkill::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientUseSkill::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameClientPacket069::GameClientPacket069(const std::vector<std::uint8_t> &data)
    : PacketReader(69) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket069::get_packet_name() const {
  return "GameClientPacket069";
}

std::string GameClientPacket069::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket069"
     << "\n";
  ss << "  field_0: " << field_0.x << " " << field_0.y << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket069::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket069::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket069::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_vec2(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket069::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_vec2(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket070::GameClientPacket070(const std::vector<std::uint8_t> &data)
    : PacketReader(70) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket070::get_packet_name() const {
  return "GameClientPacket070";
}

std::string GameClientPacket070::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket070"
     << "\n";
  ss << "  field_0: " << field_0.x << " " << field_0.y << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket070::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket070::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket070::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_vec2(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket070::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_vec2(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientTradeInitiate::GameClientTradeInitiate(
    const std::vector<std::uint8_t> &data)
    : PacketReader(71) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientTradeInitiate::get_packet_name() const {
  return "GameClientTradeInitiate";
}

std::string GameClientTradeInitiate::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientTradeInitiate"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientTradeInitiate::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientTradeInitiate::get_packet_size() const {
  return packet_size;
}
bool GameClientTradeInitiate::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientTradeInitiate::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientBuyMaterials::GameClientBuyMaterials(
    const std::vector<std::uint8_t> &data)
    : PacketReader(72) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientBuyMaterials::get_packet_name() const {
  return "GameClientBuyMaterials";
}

std::string GameClientBuyMaterials::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientBuyMaterials"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: ";
  for (const auto &item : field_2) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: ";
  for (const auto &item : field_4) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientBuyMaterials::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientBuyMaterials::get_packet_size() const {
  return packet_size;
}
bool GameClientBuyMaterials::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_array(field_2, 16, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_array(field_4, 16, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientBuyMaterials::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_array(field_2, data);
  pack_field(field_3, data);
  pack_array(field_4, data);
  return data;
}
GameClientPacket073::GameClientPacket073(const std::vector<std::uint8_t> &data)
    : PacketReader(73) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket073::get_packet_name() const {
  return "GameClientPacket073";
}

std::string GameClientPacket073::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket073"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket073::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket073::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket073::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket073::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientRequestQuote::GameClientRequestQuote(
    const std::vector<std::uint8_t> &data)
    : PacketReader(74) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientRequestQuote::get_packet_name() const {
  return "GameClientRequestQuote";
}

std::string GameClientRequestQuote::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientRequestQuote"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: ";
  for (const auto &item : field_3) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: ";
  for (const auto &item : field_5) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientRequestQuote::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientRequestQuote::get_packet_size() const {
  return packet_size;
}
bool GameClientRequestQuote::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;
  if (!read_array(field_3, 16, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_array(field_5, 16, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientRequestQuote::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_array(field_3, data);
  pack_field(field_4, data);
  pack_array(field_5, data);
  return data;
}
GameClientTransactItems::GameClientTransactItems(
    const std::vector<std::uint8_t> &data)
    : PacketReader(75) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientTransactItems::get_packet_name() const {
  return "GameClientTransactItems";
}

std::string GameClientTransactItems::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientTransactItems"
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
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: ";
  for (const auto &item : field_5) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_6: ";
  for (const auto &item : field_6) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientTransactItems::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientTransactItems::get_packet_size() const {
  return packet_size;
}
bool GameClientTransactItems::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_array(field_2, 16, it, data, packet_size))
    return false;
  if (!read_array(field_3, 16, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_array(field_5, 16, it, data, packet_size))
    return false;
  if (!read_array(field_6, 16, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientTransactItems::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_array(field_2, data);
  pack_array(field_3, data);
  pack_field(field_4, data);
  pack_array(field_5, data);
  pack_array(field_6, data);
  return data;
}
GameClientPacket076::GameClientPacket076(const std::vector<std::uint8_t> &data)
    : PacketReader(76) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket076::get_packet_name() const {
  return "GameClientPacket076";
}

std::string GameClientPacket076::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket076"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket076::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket076::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket076::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 122, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket076::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameClientUnequipItem::GameClientUnequipItem(
    const std::vector<std::uint8_t> &data)
    : PacketReader(77) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientUnequipItem::get_packet_name() const {
  return "GameClientUnequipItem";
}

std::string GameClientUnequipItem::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientUnequipItem"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientUnequipItem::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientUnequipItem::get_packet_size() const {
  return packet_size;
}
bool GameClientUnequipItem::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientUnequipItem::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientPacket078::GameClientPacket078(const std::vector<std::uint8_t> &data)
    : PacketReader(78) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket078::get_packet_name() const {
  return "GameClientPacket078";
}

std::string GameClientPacket078::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket078"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket078::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket078::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket078::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket078::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameClientInteractGadget::GameClientInteractGadget(
    const std::vector<std::uint8_t> &data)
    : PacketReader(79) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientInteractGadget::get_packet_name() const {
  return "GameClientInteractGadget";
}

std::string GameClientInteractGadget::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientInteractGadget"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientInteractGadget::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientInteractGadget::get_packet_size() const {
  return packet_size;
}
bool GameClientInteractGadget::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientInteractGadget::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket080::GameClientPacket080(const std::vector<std::uint8_t> &data)
    : PacketReader(80) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket080::get_packet_name() const {
  return "GameClientPacket080";
}

std::string GameClientPacket080::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket080"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket080::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket080::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket080::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket080::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientOpenChest::GameClientOpenChest(const std::vector<std::uint8_t> &data)
    : PacketReader(81) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientOpenChest::get_packet_name() const {
  return "GameClientOpenChest";
}

std::string GameClientOpenChest::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientOpenChest"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientOpenChest::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientOpenChest::get_packet_size() const {
  return packet_size;
}
bool GameClientOpenChest::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientOpenChest::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket082::GameClientPacket082(const std::vector<std::uint8_t> &data)
    : PacketReader(82) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket082::get_packet_name() const {
  return "GameClientPacket082";
}

std::string GameClientPacket082::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket082"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  ss << "  field_5: " << field_5 << "\n";
  ss << "  field_6: " << field_6 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket082::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket082::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket082::parse(const std::vector<std::uint8_t> &data) {
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

  return true;
}
std::vector<std::uint8_t> GameClientPacket082::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  pack_field(field_6, data);
  return data;
}
GameClientPacket083::GameClientPacket083(const std::vector<std::uint8_t> &data)
    : PacketReader(83) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket083::get_packet_name() const {
  return "GameClientPacket083";
}

std::string GameClientPacket083::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket083"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket083::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket083::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket083::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket083::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket084::GameClientPacket084(const std::vector<std::uint8_t> &data)
    : PacketReader(84) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket084::get_packet_name() const {
  return "GameClientPacket084";
}

std::string GameClientPacket084::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket084"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket084::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket084::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket084::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket084::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientEquipVisibility::GameClientEquipVisibility(
    const std::vector<std::uint8_t> &data)
    : PacketReader(85) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientEquipVisibility::get_packet_name() const {
  return "GameClientEquipVisibility";
}

std::string GameClientEquipVisibility::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientEquipVisibility"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientEquipVisibility::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientEquipVisibility::get_packet_size() const {
  return packet_size;
}
bool GameClientEquipVisibility::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientEquipVisibility::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientTitleDisplay::GameClientTitleDisplay(
    const std::vector<std::uint8_t> &data)
    : PacketReader(86) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientTitleDisplay::get_packet_name() const {
  return "GameClientTitleDisplay";
}

std::string GameClientTitleDisplay::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientTitleDisplay"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientTitleDisplay::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientTitleDisplay::get_packet_size() const {
  return packet_size;
}
bool GameClientTitleDisplay::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientTitleDisplay::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientTitleHide::GameClientTitleHide(const std::vector<std::uint8_t> &data)
    : PacketReader(87) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientTitleHide::get_packet_name() const {
  return "GameClientTitleHide";
}

std::string GameClientTitleHide::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientTitleHide"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientTitleHide::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientTitleHide::get_packet_size() const {
  return packet_size;
}
bool GameClientTitleHide::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientTitleHide::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket088::GameClientPacket088(const std::vector<std::uint8_t> &data)
    : PacketReader(88) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket088::get_packet_name() const {
  return "GameClientPacket088";
}

std::string GameClientPacket088::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket088"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket088::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket088::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket088::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket088::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket089::GameClientPacket089(const std::vector<std::uint8_t> &data)
    : PacketReader(89) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket089::get_packet_name() const {
  return "GameClientPacket089";
}

std::string GameClientPacket089::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket089"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket089::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket089::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket089::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket089::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientSkillbarSkillSet::GameClientSkillbarSkillSet(
    const std::vector<std::uint8_t> &data)
    : PacketReader(90) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientSkillbarSkillSet::get_packet_name() const {
  return "GameClientSkillbarSkillSet";
}

std::string GameClientSkillbarSkillSet::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientSkillbarSkillSet"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientSkillbarSkillSet::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientSkillbarSkillSet::get_packet_size() const {
  return packet_size;
}
bool GameClientSkillbarSkillSet::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientSkillbarSkillSet::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameClientSkillbarLoad::GameClientSkillbarLoad(
    const std::vector<std::uint8_t> &data)
    : PacketReader(91) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientSkillbarLoad::get_packet_name() const {
  return "GameClientSkillbarLoad";
}

std::string GameClientSkillbarLoad::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientSkillbarLoad"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientSkillbarLoad::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientSkillbarLoad::get_packet_size() const {
  return packet_size;
}
bool GameClientSkillbarLoad::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_array(field_1, 8, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientSkillbarLoad::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_array(field_1, data);
  return data;
}
GameClientSkillbarSkillReplace::GameClientSkillbarSkillReplace(
    const std::vector<std::uint8_t> &data)
    : PacketReader(92) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientSkillbarSkillReplace::get_packet_name() const {
  return "GameClientSkillbarSkillReplace";
}

std::string GameClientSkillbarSkillReplace::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientSkillbarSkillReplace"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientSkillbarSkillReplace::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientSkillbarSkillReplace::get_packet_size() const {
  return packet_size;
}
bool GameClientSkillbarSkillReplace::parse(
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
std::vector<std::uint8_t> GameClientSkillbarSkillReplace::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  return data;
}
GameClientPacket093::GameClientPacket093(const std::vector<std::uint8_t> &data)
    : PacketReader(93) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket093::get_packet_name() const {
  return "GameClientPacket093";
}

std::string GameClientPacket093::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket093"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket093::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket093::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket093::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket093::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameClientPacket094::GameClientPacket094(const std::vector<std::uint8_t> &data)
    : PacketReader(94) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket094::get_packet_name() const {
  return "GameClientPacket094";
}

std::string GameClientPacket094::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket094"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket094::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket094::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket094::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket094::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket095::GameClientPacket095(const std::vector<std::uint8_t> &data)
    : PacketReader(95) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket095::get_packet_name() const {
  return "GameClientPacket095";
}

std::string GameClientPacket095::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket095"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket095::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket095::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket095::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket095::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameClientPacket096::GameClientPacket096(const std::vector<std::uint8_t> &data)
    : PacketReader(96) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket096::get_packet_name() const {
  return "GameClientPacket096";
}

std::string GameClientPacket096::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket096"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket096::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket096::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket096::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 32, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket096::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientSkipCinematic::GameClientSkipCinematic(
    const std::vector<std::uint8_t> &data)
    : PacketReader(97) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientSkipCinematic::get_packet_name() const {
  return "GameClientSkipCinematic";
}

std::string GameClientSkipCinematic::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientSkipCinematic"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientSkipCinematic::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientSkipCinematic::get_packet_size() const {
  return packet_size;
}
bool GameClientSkipCinematic::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientSkipCinematic::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientSendChatMessage::GameClientSendChatMessage(
    const std::vector<std::uint8_t> &data)
    : PacketReader(98) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientSendChatMessage::get_packet_name() const {
  return "GameClientSendChatMessage";
}

std::string GameClientSendChatMessage::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientSendChatMessage"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientSendChatMessage::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientSendChatMessage::get_packet_size() const {
  return packet_size;
}
bool GameClientSendChatMessage::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 138, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientSendChatMessage::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameClientPacket099::GameClientPacket099(const std::vector<std::uint8_t> &data)
    : PacketReader(99) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket099::get_packet_name() const {
  return "GameClientPacket099";
}

std::string GameClientPacket099::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket099"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket099::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket099::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket099::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket099::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket100::GameClientPacket100(const std::vector<std::uint8_t> &data)
    : PacketReader(100) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket100::get_packet_name() const {
  return "GameClientPacket100";
}

std::string GameClientPacket100::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket100"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket100::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket100::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket100::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket100::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientPacket101::GameClientPacket101(const std::vector<std::uint8_t> &data)
    : PacketReader(101) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket101::get_packet_name() const {
  return "GameClientPacket101";
}

std::string GameClientPacket101::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket101"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket101::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket101::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket101::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket101::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameClientPacket102::GameClientPacket102(const std::vector<std::uint8_t> &data)
    : PacketReader(102) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket102::get_packet_name() const {
  return "GameClientPacket102";
}

std::string GameClientPacket102::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket102"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket102::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket102::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket102::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket102::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientItemDestroy::GameClientItemDestroy(
    const std::vector<std::uint8_t> &data)
    : PacketReader(103) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientItemDestroy::get_packet_name() const {
  return "GameClientItemDestroy";
}

std::string GameClientItemDestroy::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientItemDestroy"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientItemDestroy::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientItemDestroy::get_packet_size() const {
  return packet_size;
}
bool GameClientItemDestroy::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientItemDestroy::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket104::GameClientPacket104(const std::vector<std::uint8_t> &data)
    : PacketReader(104) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket104::get_packet_name() const {
  return "GameClientPacket104";
}

std::string GameClientPacket104::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket104"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket104::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket104::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket104::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_array(field_1, 4, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket104::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_array(field_1, data);
  return data;
}
GameClientPacket105::GameClientPacket105(const std::vector<std::uint8_t> &data)
    : PacketReader(105) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket105::get_packet_name() const {
  return "GameClientPacket105";
}

std::string GameClientPacket105::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket105"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket105::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket105::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket105::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket105::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientItemIdentify::GameClientItemIdentify(
    const std::vector<std::uint8_t> &data)
    : PacketReader(106) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientItemIdentify::get_packet_name() const {
  return "GameClientItemIdentify";
}

std::string GameClientItemIdentify::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientItemIdentify"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientItemIdentify::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientItemIdentify::get_packet_size() const {
  return packet_size;
}
bool GameClientItemIdentify::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientItemIdentify::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientTomeUnlockSkill::GameClientTomeUnlockSkill(
    const std::vector<std::uint8_t> &data)
    : PacketReader(107) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientTomeUnlockSkill::get_packet_name() const {
  return "GameClientTomeUnlockSkill";
}

std::string GameClientTomeUnlockSkill::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientTomeUnlockSkill"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientTomeUnlockSkill::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientTomeUnlockSkill::get_packet_size() const {
  return packet_size;
}
bool GameClientTomeUnlockSkill::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientTomeUnlockSkill::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket108::GameClientPacket108(const std::vector<std::uint8_t> &data)
    : PacketReader(108) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket108::get_packet_name() const {
  return "GameClientPacket108";
}

std::string GameClientPacket108::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket108"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket108::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket108::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket108::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket108::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket109::GameClientPacket109(const std::vector<std::uint8_t> &data)
    : PacketReader(109) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket109::get_packet_name() const {
  return "GameClientPacket109";
}

std::string GameClientPacket109::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket109"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket109::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket109::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket109::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket109::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket110::GameClientPacket110(const std::vector<std::uint8_t> &data)
    : PacketReader(110) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket110::get_packet_name() const {
  return "GameClientPacket110";
}

std::string GameClientPacket110::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket110"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket110::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket110::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket110::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket110::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket111::GameClientPacket111(const std::vector<std::uint8_t> &data)
    : PacketReader(111) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket111::get_packet_name() const {
  return "GameClientPacket111";
}

std::string GameClientPacket111::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket111"
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
std::vector<std::uint8_t> GameClientPacket111::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket111::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket111::parse(const std::vector<std::uint8_t> &data) {
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
bool GameClientPacket111::read_struct(
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
std::vector<std::uint8_t> GameClientPacket111::pack() const {
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
GameClientItemMove::GameClientItemMove(const std::vector<std::uint8_t> &data)
    : PacketReader(112) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientItemMove::get_packet_name() const {
  return "GameClientItemMove";
}

std::string GameClientItemMove::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientItemMove"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientItemMove::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientItemMove::get_packet_size() const {
  return packet_size;
}
bool GameClientItemMove::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientItemMove::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientItemAcceptAll::GameClientItemAcceptAll(
    const std::vector<std::uint8_t> &data)
    : PacketReader(113) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientItemAcceptAll::get_packet_name() const {
  return "GameClientItemAcceptAll";
}

std::string GameClientItemAcceptAll::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientItemAcceptAll"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientItemAcceptAll::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientItemAcceptAll::get_packet_size() const {
  return packet_size;
}
bool GameClientItemAcceptAll::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientItemAcceptAll::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket114::GameClientPacket114(const std::vector<std::uint8_t> &data)
    : PacketReader(114) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket114::get_packet_name() const {
  return "GameClientPacket114";
}

std::string GameClientPacket114::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket114"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket114::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket114::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket114::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket114::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientItemSplitStack::GameClientItemSplitStack(
    const std::vector<std::uint8_t> &data)
    : PacketReader(115) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientItemSplitStack::get_packet_name() const {
  return "GameClientItemSplitStack";
}

std::string GameClientItemSplitStack::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientItemSplitStack"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientItemSplitStack::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientItemSplitStack::get_packet_size() const {
  return packet_size;
}
bool GameClientItemSplitStack::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientItemSplitStack::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  return data;
}
GameClientPacket116::GameClientPacket116(const std::vector<std::uint8_t> &data)
    : PacketReader(116) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket116::get_packet_name() const {
  return "GameClientPacket116";
}

std::string GameClientPacket116::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket116"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket116::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket116::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket116::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket116::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientItemSalvageSessionOpen::GameClientItemSalvageSessionOpen(
    const std::vector<std::uint8_t> &data)
    : PacketReader(117) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientItemSalvageSessionOpen::get_packet_name() const {
  return "GameClientItemSalvageSessionOpen";
}

std::string GameClientItemSalvageSessionOpen::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientItemSalvageSessionOpen"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientItemSalvageSessionOpen::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientItemSalvageSessionOpen::get_packet_size() const {
  return packet_size;
}
bool GameClientItemSalvageSessionOpen::parse(
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
std::vector<std::uint8_t> GameClientItemSalvageSessionOpen::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientItemSalvageSessionCancel::GameClientItemSalvageSessionCancel(
    const std::vector<std::uint8_t> &data)
    : PacketReader(118) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientItemSalvageSessionCancel::get_packet_name() const {
  return "GameClientItemSalvageSessionCancel";
}

std::string
GameClientItemSalvageSessionCancel::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientItemSalvageSessionCancel"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientItemSalvageSessionCancel::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientItemSalvageSessionCancel::get_packet_size() const {
  return packet_size;
}
bool GameClientItemSalvageSessionCancel::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientItemSalvageSessionCancel::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientItemSalvageSessionDone::GameClientItemSalvageSessionDone(
    const std::vector<std::uint8_t> &data)
    : PacketReader(119) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientItemSalvageSessionDone::get_packet_name() const {
  return "GameClientItemSalvageSessionDone";
}

std::string GameClientItemSalvageSessionDone::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientItemSalvageSessionDone"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientItemSalvageSessionDone::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientItemSalvageSessionDone::get_packet_size() const {
  return packet_size;
}
bool GameClientItemSalvageSessionDone::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientItemSalvageSessionDone::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientItemSalvageMaterials::GameClientItemSalvageMaterials(
    const std::vector<std::uint8_t> &data)
    : PacketReader(120) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientItemSalvageMaterials::get_packet_name() const {
  return "GameClientItemSalvageMaterials";
}

std::string GameClientItemSalvageMaterials::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientItemSalvageMaterials"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientItemSalvageMaterials::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientItemSalvageMaterials::get_packet_size() const {
  return packet_size;
}
bool GameClientItemSalvageMaterials::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientItemSalvageMaterials::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientItemSalvageUpgrade::GameClientItemSalvageUpgrade(
    const std::vector<std::uint8_t> &data)
    : PacketReader(121) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientItemSalvageUpgrade::get_packet_name() const {
  return "GameClientItemSalvageUpgrade";
}

std::string GameClientItemSalvageUpgrade::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientItemSalvageUpgrade"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientItemSalvageUpgrade::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientItemSalvageUpgrade::get_packet_size() const {
  return packet_size;
}
bool GameClientItemSalvageUpgrade::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientItemSalvageUpgrade::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientItemChangeGold::GameClientItemChangeGold(
    const std::vector<std::uint8_t> &data)
    : PacketReader(122) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientItemChangeGold::get_packet_name() const {
  return "GameClientItemChangeGold";
}

std::string GameClientItemChangeGold::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientItemChangeGold"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientItemChangeGold::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientItemChangeGold::get_packet_size() const {
  return packet_size;
}
bool GameClientItemChangeGold::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientItemChangeGold::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket123::GameClientPacket123(const std::vector<std::uint8_t> &data)
    : PacketReader(123) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket123::get_packet_name() const {
  return "GameClientPacket123";
}

std::string GameClientPacket123::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket123"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket123::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket123::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket123::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket123::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientItemUse::GameClientItemUse(const std::vector<std::uint8_t> &data)
    : PacketReader(124) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientItemUse::get_packet_name() const {
  return "GameClientItemUse";
}

std::string GameClientItemUse::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientItemUse"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientItemUse::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientItemUse::get_packet_size() const { return packet_size; }
bool GameClientItemUse::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientItemUse::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket125::GameClientPacket125(const std::vector<std::uint8_t> &data)
    : PacketReader(125) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket125::get_packet_name() const {
  return "GameClientPacket125";
}

std::string GameClientPacket125::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket125"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket125::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket125::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket125::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket125::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket126::GameClientPacket126(const std::vector<std::uint8_t> &data)
    : PacketReader(126) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket126::get_packet_name() const {
  return "GameClientPacket126";
}

std::string GameClientPacket126::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket126"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket126::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket126::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket126::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket126::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket127::GameClientPacket127(const std::vector<std::uint8_t> &data)
    : PacketReader(127) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket127::get_packet_name() const {
  return "GameClientPacket127";
}

std::string GameClientPacket127::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket127"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket127::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket127::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket127::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket127::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket128::GameClientPacket128(const std::vector<std::uint8_t> &data)
    : PacketReader(128) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket128::get_packet_name() const {
  return "GameClientPacket128";
}

std::string GameClientPacket128::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket128"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket128::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket128::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket128::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket128::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket129::GameClientPacket129(const std::vector<std::uint8_t> &data)
    : PacketReader(129) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket129::get_packet_name() const {
  return "GameClientPacket129";
}

std::string GameClientPacket129::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket129"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket129::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket129::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket129::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket129::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket130::GameClientPacket130(const std::vector<std::uint8_t> &data)
    : PacketReader(130) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket130::get_packet_name() const {
  return "GameClientPacket130";
}

std::string GameClientPacket130::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket130"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket130::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket130::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket130::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket130::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket131::GameClientPacket131(const std::vector<std::uint8_t> &data)
    : PacketReader(131) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket131::get_packet_name() const {
  return "GameClientPacket131";
}

std::string GameClientPacket131::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket131"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket131::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket131::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket131::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket131::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket132::GameClientPacket132(const std::vector<std::uint8_t> &data)
    : PacketReader(132) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket132::get_packet_name() const {
  return "GameClientPacket132";
}

std::string GameClientPacket132::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket132"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
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
std::vector<std::uint8_t> GameClientPacket132::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket132::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket132::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_array(field_2, 4, it, data, packet_size))
    return false;
  if (!read_field(field_3, it, data, packet_size))
    return false;
  if (!read_field(field_4, it, data, packet_size))
    return false;
  if (!read_field(field_5, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket132::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_array(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  pack_field(field_5, data);
  return data;
}
GameClientPacket133::GameClientPacket133(const std::vector<std::uint8_t> &data)
    : PacketReader(133) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket133::get_packet_name() const {
  return "GameClientPacket133";
}

std::string GameClientPacket133::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket133"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket133::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket133::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket133::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket133::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientInstanceLoadRequestSpawn::GameClientInstanceLoadRequestSpawn(
    const std::vector<std::uint8_t> &data)
    : PacketReader(134) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientInstanceLoadRequestSpawn::get_packet_name() const {
  return "GameClientInstanceLoadRequestSpawn";
}

std::string
GameClientInstanceLoadRequestSpawn::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientInstanceLoadRequestSpawn"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientInstanceLoadRequestSpawn::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientInstanceLoadRequestSpawn::get_packet_size() const {
  return packet_size;
}
bool GameClientInstanceLoadRequestSpawn::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientInstanceLoadRequestSpawn::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket135::GameClientPacket135(const std::vector<std::uint8_t> &data)
    : PacketReader(135) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket135::get_packet_name() const {
  return "GameClientPacket135";
}

std::string GameClientPacket135::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket135"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket135::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket135::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket135::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket135::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket136::GameClientPacket136(const std::vector<std::uint8_t> &data)
    : PacketReader(136) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket136::get_packet_name() const {
  return "GameClientPacket136";
}

std::string GameClientPacket136::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket136"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket136::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket136::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket136::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket136::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket137::GameClientPacket137(const std::vector<std::uint8_t> &data)
    : PacketReader(137) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket137::get_packet_name() const {
  return "GameClientPacket137";
}

std::string GameClientPacket137::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket137"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: ";
  for (const auto &item : field_1) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket137::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket137::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket137::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 20, it, data, packet_size))
    return false;
  if (!read_blob(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket137::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_blob(field_1, data);
  return data;
}
GameClientPacket138::GameClientPacket138(const std::vector<std::uint8_t> &data)
    : PacketReader(138) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket138::get_packet_name() const {
  return "GameClientPacket138";
}

std::string GameClientPacket138::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket138"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket138::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket138::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket138::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket138::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket139::GameClientPacket139(const std::vector<std::uint8_t> &data)
    : PacketReader(139) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket139::get_packet_name() const {
  return "GameClientPacket139";
}

std::string GameClientPacket139::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket139"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket139::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket139::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket139::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket139::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket140::GameClientPacket140(const std::vector<std::uint8_t> &data)
    : PacketReader(140) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket140::get_packet_name() const {
  return "GameClientPacket140";
}

std::string GameClientPacket140::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket140"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket140::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket140::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket140::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket140::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket141::GameClientPacket141(const std::vector<std::uint8_t> &data)
    : PacketReader(141) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket141::get_packet_name() const {
  return "GameClientPacket141";
}

std::string GameClientPacket141::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket141"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket141::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket141::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket141::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket141::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientInstanceLoadRequestPlayers::GameClientInstanceLoadRequestPlayers(
    const std::vector<std::uint8_t> &data)
    : PacketReader(142) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientInstanceLoadRequestPlayers::get_packet_name() const {
  return "GameClientInstanceLoadRequestPlayers";
}

std::string
GameClientInstanceLoadRequestPlayers::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientInstanceLoadRequestPlayers"
     << "\n";
  ss << "  request_data: ";
  for (const auto &item : request_data) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientInstanceLoadRequestPlayers::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientInstanceLoadRequestPlayers::get_packet_size() const {
  return packet_size;
}
bool GameClientInstanceLoadRequestPlayers::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_blob(request_data, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientInstanceLoadRequestPlayers::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_blob(request_data, data);
  return data;
}
GameClientRequestItems::GameClientRequestItems(
    const std::vector<std::uint8_t> &data)
    : PacketReader(143) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientRequestItems::get_packet_name() const {
  return "GameClientRequestItems";
}

std::string GameClientRequestItems::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientRequestItems"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientRequestItems::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientRequestItems::get_packet_size() const {
  return packet_size;
}
bool GameClientRequestItems::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientRequestItems::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket144::GameClientPacket144(const std::vector<std::uint8_t> &data)
    : PacketReader(144) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket144::get_packet_name() const {
  return "GameClientPacket144";
}

std::string GameClientPacket144::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket144"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket144::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket144::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket144::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_array(field_0, 112, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket144::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_array(field_0, data);
  return data;
}
GameClientPacket145::GameClientPacket145(const std::vector<std::uint8_t> &data)
    : PacketReader(145) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket145::get_packet_name() const {
  return "GameClientPacket145";
}

std::string GameClientPacket145::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket145"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket145::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket145::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket145::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket145::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket146::GameClientPacket146(const std::vector<std::uint8_t> &data)
    : PacketReader(146) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket146::get_packet_name() const {
  return "GameClientPacket146";
}

std::string GameClientPacket146::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket146"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket146::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket146::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket146::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket146::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket147::GameClientPacket147(const std::vector<std::uint8_t> &data)
    : PacketReader(147) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket147::get_packet_name() const {
  return "GameClientPacket147";
}

std::string GameClientPacket147::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket147"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket147::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket147::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket147::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket147::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket148::GameClientPacket148(const std::vector<std::uint8_t> &data)
    : PacketReader(148) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket148::get_packet_name() const {
  return "GameClientPacket148";
}

std::string GameClientPacket148::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket148"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket148::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket148::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket148::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket148::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientPacket149::GameClientPacket149(const std::vector<std::uint8_t> &data)
    : PacketReader(149) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket149::get_packet_name() const {
  return "GameClientPacket149";
}

std::string GameClientPacket149::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket149"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket149::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket149::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket149::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket149::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket150::GameClientPacket150(const std::vector<std::uint8_t> &data)
    : PacketReader(150) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket150::get_packet_name() const {
  return "GameClientPacket150";
}

std::string GameClientPacket150::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket150"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket150::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket150::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket150::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket150::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket151::GameClientPacket151(const std::vector<std::uint8_t> &data)
    : PacketReader(151) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket151::get_packet_name() const {
  return "GameClientPacket151";
}

std::string GameClientPacket151::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket151"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket151::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket151::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket151::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket151::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket152::GameClientPacket152(const std::vector<std::uint8_t> &data)
    : PacketReader(152) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket152::get_packet_name() const {
  return "GameClientPacket152";
}

std::string GameClientPacket152::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket152"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket152::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket152::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket152::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket152::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPartySetDifficulty::GameClientPartySetDifficulty(
    const std::vector<std::uint8_t> &data)
    : PacketReader(153) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartySetDifficulty::get_packet_name() const {
  return "GameClientPartySetDifficulty";
}

std::string GameClientPartySetDifficulty::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartySetDifficulty"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientPartySetDifficulty::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartySetDifficulty::get_packet_size() const {
  return packet_size;
}
bool GameClientPartySetDifficulty::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartySetDifficulty::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPartyAcceptInvite::GameClientPartyAcceptInvite(
    const std::vector<std::uint8_t> &data)
    : PacketReader(154) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyAcceptInvite::get_packet_name() const {
  return "GameClientPartyAcceptInvite";
}

std::string GameClientPartyAcceptInvite::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyAcceptInvite"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPartyAcceptInvite::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyAcceptInvite::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyAcceptInvite::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyAcceptInvite::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPartyAcceptCancel::GameClientPartyAcceptCancel(
    const std::vector<std::uint8_t> &data)
    : PacketReader(155) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyAcceptCancel::get_packet_name() const {
  return "GameClientPartyAcceptCancel";
}

std::string GameClientPartyAcceptCancel::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyAcceptCancel"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPartyAcceptCancel::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyAcceptCancel::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyAcceptCancel::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyAcceptCancel::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPartyAcceptRefuse::GameClientPartyAcceptRefuse(
    const std::vector<std::uint8_t> &data)
    : PacketReader(156) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyAcceptRefuse::get_packet_name() const {
  return "GameClientPartyAcceptRefuse";
}

std::string GameClientPartyAcceptRefuse::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyAcceptRefuse"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPartyAcceptRefuse::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyAcceptRefuse::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyAcceptRefuse::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyAcceptRefuse::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPartyInviteNPC::GameClientPartyInviteNPC(
    const std::vector<std::uint8_t> &data)
    : PacketReader(157) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyInviteNPC::get_packet_name() const {
  return "GameClientPartyInviteNPC";
}

std::string GameClientPartyInviteNPC::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyInviteNPC"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPartyInviteNPC::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyInviteNPC::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyInviteNPC::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyInviteNPC::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPartyInvitePlayer::GameClientPartyInvitePlayer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(158) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyInvitePlayer::get_packet_name() const {
  return "GameClientPartyInvitePlayer";
}

std::string GameClientPartyInvitePlayer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyInvitePlayer"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPartyInvitePlayer::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyInvitePlayer::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyInvitePlayer::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyInvitePlayer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPartyInvitePlayerName::GameClientPartyInvitePlayerName(
    const std::vector<std::uint8_t> &data)
    : PacketReader(159) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyInvitePlayerName::get_packet_name() const {
  return "GameClientPartyInvitePlayerName";
}

std::string GameClientPartyInvitePlayerName::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyInvitePlayerName"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientPartyInvitePlayerName::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyInvitePlayerName::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyInvitePlayerName::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyInvitePlayerName::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  return data;
}
GameClientPartyLeaveGroup::GameClientPartyLeaveGroup(
    const std::vector<std::uint8_t> &data)
    : PacketReader(160) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyLeaveGroup::get_packet_name() const {
  return "GameClientPartyLeaveGroup";
}

std::string GameClientPartyLeaveGroup::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyLeaveGroup"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPartyLeaveGroup::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyLeaveGroup::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyLeaveGroup::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyLeaveGroup::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPartyCancelEnterChallenge::GameClientPartyCancelEnterChallenge(
    const std::vector<std::uint8_t> &data)
    : PacketReader(161) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyCancelEnterChallenge::get_packet_name() const {
  return "GameClientPartyCancelEnterChallenge";
}

std::string
GameClientPartyCancelEnterChallenge::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyCancelEnterChallenge"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientPartyCancelEnterChallenge::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyCancelEnterChallenge::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyCancelEnterChallenge::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyCancelEnterChallenge::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPacket162::GameClientPacket162(const std::vector<std::uint8_t> &data)
    : PacketReader(162) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket162::get_packet_name() const {
  return "GameClientPacket162";
}

std::string GameClientPacket162::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket162"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket162::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket162::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket162::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 64, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket162::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameClientPartyEnterChallenge::GameClientPartyEnterChallenge(
    const std::vector<std::uint8_t> &data)
    : PacketReader(163) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyEnterChallenge::get_packet_name() const {
  return "GameClientPartyEnterChallenge";
}

std::string GameClientPartyEnterChallenge::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyEnterChallenge"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientPartyEnterChallenge::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyEnterChallenge::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyEnterChallenge::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyEnterChallenge::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket164::GameClientPacket164(const std::vector<std::uint8_t> &data)
    : PacketReader(164) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket164::get_packet_name() const {
  return "GameClientPacket164";
}

std::string GameClientPacket164::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket164"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket164::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket164::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket164::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket164::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientPartyReturnToOutpost::GameClientPartyReturnToOutpost(
    const std::vector<std::uint8_t> &data)
    : PacketReader(165) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyReturnToOutpost::get_packet_name() const {
  return "GameClientPartyReturnToOutpost";
}

std::string GameClientPartyReturnToOutpost::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyReturnToOutpost"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientPartyReturnToOutpost::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyReturnToOutpost::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyReturnToOutpost::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyReturnToOutpost::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPartyKickNPC::GameClientPartyKickNPC(
    const std::vector<std::uint8_t> &data)
    : PacketReader(166) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyKickNPC::get_packet_name() const {
  return "GameClientPartyKickNPC";
}

std::string GameClientPartyKickNPC::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyKickNPC"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPartyKickNPC::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyKickNPC::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyKickNPC::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyKickNPC::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPartyKickPlayer::GameClientPartyKickPlayer(
    const std::vector<std::uint8_t> &data)
    : PacketReader(167) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyKickPlayer::get_packet_name() const {
  return "GameClientPartyKickPlayer";
}

std::string GameClientPartyKickPlayer::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyKickPlayer"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPartyKickPlayer::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyKickPlayer::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyKickPlayer::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyKickPlayer::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPartySearchSeek::GameClientPartySearchSeek(
    const std::vector<std::uint8_t> &data)
    : PacketReader(168) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartySearchSeek::get_packet_name() const {
  return "GameClientPartySearchSeek";
}

std::string GameClientPartySearchSeek::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartySearchSeek"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPartySearchSeek::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartySearchSeek::get_packet_size() const {
  return packet_size;
}
bool GameClientPartySearchSeek::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 32, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartySearchSeek::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientPartySearchCancel::GameClientPartySearchCancel(
    const std::vector<std::uint8_t> &data)
    : PacketReader(169) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartySearchCancel::get_packet_name() const {
  return "GameClientPartySearchCancel";
}

std::string GameClientPartySearchCancel::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartySearchCancel"
     << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPartySearchCancel::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartySearchCancel::get_packet_size() const {
  return packet_size;
}
bool GameClientPartySearchCancel::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartySearchCancel::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  return data;
}
GameClientPartySearchRequestJoin::GameClientPartySearchRequestJoin(
    const std::vector<std::uint8_t> &data)
    : PacketReader(170) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartySearchRequestJoin::get_packet_name() const {
  return "GameClientPartySearchRequestJoin";
}

std::string GameClientPartySearchRequestJoin::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartySearchRequestJoin"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientPartySearchRequestJoin::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartySearchRequestJoin::get_packet_size() const {
  return packet_size;
}
bool GameClientPartySearchRequestJoin::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartySearchRequestJoin::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPartySearchRequestReply::GameClientPartySearchRequestReply(
    const std::vector<std::uint8_t> &data)
    : PacketReader(171) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartySearchRequestReply::get_packet_name() const {
  return "GameClientPartySearchRequestReply";
}

std::string GameClientPartySearchRequestReply::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartySearchRequestReply"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientPartySearchRequestReply::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartySearchRequestReply::get_packet_size() const {
  return packet_size;
}
bool GameClientPartySearchRequestReply::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartySearchRequestReply::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPartySearchType::GameClientPartySearchType(
    const std::vector<std::uint8_t> &data)
    : PacketReader(172) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartySearchType::get_packet_name() const {
  return "GameClientPartySearchType";
}

std::string GameClientPartySearchType::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartySearchType"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPartySearchType::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartySearchType::get_packet_size() const {
  return packet_size;
}
bool GameClientPartySearchType::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartySearchType::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPartyReadyStatus::GameClientPartyReadyStatus(
    const std::vector<std::uint8_t> &data)
    : PacketReader(173) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyReadyStatus::get_packet_name() const {
  return "GameClientPartyReadyStatus";
}

std::string GameClientPartyReadyStatus::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyReadyStatus"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPartyReadyStatus::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyReadyStatus::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyReadyStatus::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyReadyStatus::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPartyEnterGuildHall::GameClientPartyEnterGuildHall(
    const std::vector<std::uint8_t> &data)
    : PacketReader(174) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyEnterGuildHall::get_packet_name() const {
  return "GameClientPartyEnterGuildHall";
}

std::string GameClientPartyEnterGuildHall::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyEnterGuildHall"
     << "\n";
  ss << "  field_0: ";
  for (const auto &item : field_0) {
    ss << static_cast<int>(item) << " ";
  }
  ss << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientPartyEnterGuildHall::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyEnterGuildHall::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyEnterGuildHall::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_blob(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyEnterGuildHall::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_blob(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPartyTravel::GameClientPartyTravel(
    const std::vector<std::uint8_t> &data)
    : PacketReader(175) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyTravel::get_packet_name() const {
  return "GameClientPartyTravel";
}

std::string GameClientPartyTravel::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyTravel"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << field_2 << "\n";
  ss << "  field_3: " << field_3 << "\n";
  ss << "  field_4: " << field_4 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPartyTravel::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyTravel::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyTravel::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPartyTravel::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_field(field_2, data);
  pack_field(field_3, data);
  pack_field(field_4, data);
  return data;
}
GameClientPartyLeaveGuildHall::GameClientPartyLeaveGuildHall(
    const std::vector<std::uint8_t> &data)
    : PacketReader(176) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPartyLeaveGuildHall::get_packet_name() const {
  return "GameClientPartyLeaveGuildHall";
}

std::string GameClientPartyLeaveGuildHall::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPartyLeaveGuildHall"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t>
GameClientPartyLeaveGuildHall::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPartyLeaveGuildHall::get_packet_size() const {
  return packet_size;
}
bool GameClientPartyLeaveGuildHall::parse(
    const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPartyLeaveGuildHall::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket177::GameClientPacket177(const std::vector<std::uint8_t> &data)
    : PacketReader(177) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket177::get_packet_name() const {
  return "GameClientPacket177";
}

std::string GameClientPacket177::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket177"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket177::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket177::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket177::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket177::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameClientPacket178::GameClientPacket178(const std::vector<std::uint8_t> &data)
    : PacketReader(178) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket178::get_packet_name() const {
  return "GameClientPacket178";
}

std::string GameClientPacket178::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket178"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket178::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket178::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket178::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket178::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameClientPacket179::GameClientPacket179(const std::vector<std::uint8_t> &data)
    : PacketReader(179) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket179::get_packet_name() const {
  return "GameClientPacket179";
}

std::string GameClientPacket179::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket179"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  ss << "  field_2: " << field_2 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket179::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket179::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket179::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 32, it, data, packet_size))
    return false;
  if (!read_field(field_2, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket179::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientPacket180::GameClientPacket180(const std::vector<std::uint8_t> &data)
    : PacketReader(180) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket180::get_packet_name() const {
  return "GameClientPacket180";
}

std::string GameClientPacket180::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket180"
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
std::vector<std::uint8_t> GameClientPacket180::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket180::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket180::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket180::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_blob(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientPacket181::GameClientPacket181(const std::vector<std::uint8_t> &data)
    : PacketReader(181) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket181::get_packet_name() const {
  return "GameClientPacket181";
}

std::string GameClientPacket181::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket181"
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
std::vector<std::uint8_t> GameClientPacket181::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket181::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket181::parse(const std::vector<std::uint8_t> &data) {
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
std::vector<std::uint8_t> GameClientPacket181::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_blob(field_1, data);
  pack_field(field_2, data);
  return data;
}
GameClientPacket182::GameClientPacket182(const std::vector<std::uint8_t> &data)
    : PacketReader(182) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket182::get_packet_name() const {
  return "GameClientPacket182";
}

std::string GameClientPacket182::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket182"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket182::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket182::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket182::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket182::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameClientPacket183::GameClientPacket183(const std::vector<std::uint8_t> &data)
    : PacketReader(183) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket183::get_packet_name() const {
  return "GameClientPacket183";
}

std::string GameClientPacket183::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket183"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket183::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket183::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket183::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket183::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket184::GameClientPacket184(const std::vector<std::uint8_t> &data)
    : PacketReader(184) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket184::get_packet_name() const {
  return "GameClientPacket184";
}

std::string GameClientPacket184::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket184"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket184::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket184::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket184::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket184::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameClientPacket185::GameClientPacket185(const std::vector<std::uint8_t> &data)
    : PacketReader(185) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket185::get_packet_name() const {
  return "GameClientPacket185";
}

std::string GameClientPacket185::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket185"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket185::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket185::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket185::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket185::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket186::GameClientPacket186(const std::vector<std::uint8_t> &data)
    : PacketReader(186) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket186::get_packet_name() const {
  return "GameClientPacket186";
}

std::string GameClientPacket186::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket186"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket186::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket186::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket186::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket186::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  return data;
}
GameClientPacket187::GameClientPacket187(const std::vector<std::uint8_t> &data)
    : PacketReader(187) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket187::get_packet_name() const {
  return "GameClientPacket187";
}

std::string GameClientPacket187::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket187"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket187::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket187::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket187::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 20, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket187::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameClientPacket188::GameClientPacket188(const std::vector<std::uint8_t> &data)
    : PacketReader(188) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket188::get_packet_name() const {
  return "GameClientPacket188";
}

std::string GameClientPacket188::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket188"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << common::u16string_to_string(field_1) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket188::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket188::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket188::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_string(field_1, 256, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket188::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_string(field_1, data);
  return data;
}
GameClientPacket189::GameClientPacket189(const std::vector<std::uint8_t> &data)
    : PacketReader(189) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket189::get_packet_name() const {
  return "GameClientPacket189";
}

std::string GameClientPacket189::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket189"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  ss << "  field_2: " << common::u16string_to_string(field_2) << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket189::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket189::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket189::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;
  if (!read_string(field_2, 32, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket189::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  pack_string(field_2, data);
  return data;
}
GameClientPacket190::GameClientPacket190(const std::vector<std::uint8_t> &data)
    : PacketReader(190) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket190::get_packet_name() const {
  return "GameClientPacket190";
}

std::string GameClientPacket190::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket190"
     << "\n";
  ss << "  field_0: " << common::u16string_to_string(field_0) << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket190::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket190::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket190::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_string(field_0, 32, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket190::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_string(field_0, data);
  pack_field(field_1, data);
  return data;
}
GameClientPacket191::GameClientPacket191(const std::vector<std::uint8_t> &data)
    : PacketReader(191) {
  if (parse(data)) {
    packet_valid = true;
  } else {
    packet_valid = false;
  }
}
std::string GameClientPacket191::get_packet_name() const {
  return "GameClientPacket191";
}

std::string GameClientPacket191::get_packet_as_printable() const {
  std::stringstream ss;
  ss << "GameClientPacket191"
     << "\n";
  ss << "  field_0: " << field_0 << "\n";
  ss << "  field_1: " << field_1 << "\n";
  return ss.str();
}
std::vector<std::uint8_t> GameClientPacket191::get_packed_data() const {
  return pack();
}
std::uint16_t GameClientPacket191::get_packet_size() const {
  return packet_size;
}
bool GameClientPacket191::parse(const std::vector<std::uint8_t> &data) {
  auto it = data.begin();
  if (!read_header_id(header_id, it, data, packet_size))
    return false;
  if (!read_field(field_0, it, data, packet_size))
    return false;
  if (!read_field(field_1, it, data, packet_size))
    return false;

  return true;
}
std::vector<std::uint8_t> GameClientPacket191::pack() const {
  std::vector<std::uint8_t> data;
  pack_header_id(header_id, data);
  pack_field(field_0, data);
  pack_field(field_1, data);
  return data;
}
} // namespace core
} // namespace utopia
