#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/client_connection/packets/sts_connect_reply_packet.hpp"

#include <pugixml.hpp>
#include <scn/scan.h>
#include <spdlog/spdlog.h>

#include <cstdint>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

constexpr std::string_view scan_str =
    "STS/{}.{} {} Success\r\ns:{}\r\nl:{}\r\n\r\n";

StsConnectReplyPacket::StsConnectReplyPacket(
    const std::vector<std::uint8_t> &data) noexcept {
  std::string data_str(data.begin(), data.end());

  auto scan_result =
      scn::scan<std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t,
                std::uint32_t>(data_str, scan_str);

  if (!scan_result) {
    spdlog::error("Failed to parse STS Connect Reply packet.");
    is_valid_ = false;
    return;
  }

  auto &[major, minor, conn_type, sequence_number, size] =
      scan_result->values();

  protocol_version_major = major;
  protocol_version_minor = minor;
  conn_type = conn_type;
  reply_sequence_number = sequence_number;
  xml_content_size = size;
  xml_content_ =
      std::string(scan_result->range().begin(), scan_result->range().end());

  if (xml_content_size != xml_content_.size()) {
    spdlog::error("XML content size does not match the expected size.");
    is_valid_ = false;
    return;
  }

  // Parse xml into public data members
  pugi::xml_document doc;
  pugi::xml_parse_result xml_parse_result =
      doc.load_string(xml_content_.c_str());

  if (!xml_parse_result) {
    spdlog::error("Failed to parse XML content.");
    is_valid_ = false;
    return;
  }

  auto connect_reply_node = doc.child("ConnectReply");
  if (!connect_reply_node) {
    spdlog::error("Failed to find ConnectReply node.");
    is_valid_ = false;
    return;
  }

  conn_type = connect_reply_node.child("ConnType").text().as_uint();
  reply_sequence_number =
      connect_reply_node.child("ReplySequenceNumber").text().as_uint();
  xml_content_server = connect_reply_node.child("Server").text().as_uint();
  xml_content_module = connect_reply_node.child("Module").text().as_uint();
  xml_content_line = connect_reply_node.child("Line").text().as_uint();

  is_valid_ = true;
}

std::uint32_t StsConnectReplyPacket::get_packet_size() const noexcept {
  return sizeof(scan_str) - 5 + xml_content_size;
}

std::vector<std::uint8_t> StsConnectReplyPacket::serialize() noexcept {
  xml_content_ =
      std::format(R"(<Error server="{}" module="{}" line="{}"/>)",
                  xml_content_server, xml_content_module, xml_content_line);

  std::string packet_str = std::format("{}{}", scan_str, protocol_version_major,
                                       protocol_version_minor, conn_type,
                                       reply_sequence_number, xml_content_size);

  std::vector<std::uint8_t> packet(packet_str.begin(), packet_str.end());

  return packet;
}

} // namespace utopia::portal::client_connection
