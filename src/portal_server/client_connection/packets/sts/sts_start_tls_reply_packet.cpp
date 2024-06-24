#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/client_connection/packets/sts/sts_start_tls_reply_packet.hpp"

#include "utopia/common/integers/count_digits.hpp"
#include "utopia/common/strings/get_format_string_length_ignoring_curly_brackets.hpp"

#include <pugixml.hpp>
#include <scn/scan.h>
#include <spdlog/spdlog.h>

#include <cstdint>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

constexpr std::string_view scan_str = "STS/{}.{} {} Success\r\ns:{}R\r\nl:{}";
constexpr std::uint32_t header_end_size =
    4; // before xml_content_ we have "\r\n\r\n" that we wish to skip

StsStartTlsReplyPacket::StsStartTlsReplyPacket(
    const std::vector<std::uint8_t> &data) noexcept {
  std::string data_str(data.begin(), data.end());

  auto scan_result =
      scn::scan<std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t,
                std::uint32_t>(data_str, scan_str);

  if (!scan_result) {
    is_valid_ = false;
    return;
  }

  auto &[scan_major, scan_minor, scan_conn_type, scan_sequence_number,
         scan_xml_size] = scan_result->values();

  protocol_version_major = scan_major;
  protocol_version_minor = scan_minor;
  conn_type = scan_conn_type;
  sequence_number = scan_sequence_number;
  xml_content_size = scan_xml_size;

  xml_content_ = std::string(scan_result->range().begin() + header_end_size,
                             scan_result->range().begin() + header_end_size +
                                 xml_content_size);

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
    is_valid_ = false;
    return;
  }

  auto connect_reply_node = doc.child("StartTlsReply");
  if (!connect_reply_node) {
    spdlog::error("Failed to find StartTlsReply node.");
    is_valid_ = false;
    return;
  }

  conn_type = connect_reply_node.child("ConnType").text().as_uint();
  sequence_number =
      connect_reply_node.child("ReplySequenceNumber").text().as_uint();
  xml_content_server = connect_reply_node.child("Server").text().as_uint();
  xml_content_module = connect_reply_node.child("Module").text().as_uint();
  xml_content_line = connect_reply_node.child("Line").text().as_uint();

  is_valid_ = true;
}

std::uint32_t StsStartTlsReplyPacket::get_packet_size() const noexcept {
  using namespace common;
  return get_format_string_length_ignoring_curly_brackets(scan_str) +
         count_digits(protocol_version_major) +
         count_digits(protocol_version_minor) + count_digits(conn_type) +
         count_digits(sequence_number) + count_digits(xml_content_size) +
         xml_content_size + header_end_size;
}

std::vector<std::uint8_t> StsStartTlsReplyPacket::serialize() noexcept {
  xml_content_ =
      std::format(R"(<Error server="{}" module="{}" line="{}"/>)",
                  xml_content_server, xml_content_module, xml_content_line) +
      '\n';
  xml_content_size = static_cast<uint32_t>(xml_content_.size());

  std::string packet_str =
      std::format(scan_str, protocol_version_major, protocol_version_minor,
                  conn_type, sequence_number, xml_content_size) +
      "\r\n\r\n" + xml_content_;

  std::vector<std::uint8_t> packet(packet_str.begin(), packet_str.end());

  return packet;
}

} // namespace utopia::portal::client_connection
