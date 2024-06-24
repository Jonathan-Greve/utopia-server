#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/client_connection/packets/sts/sts_connect_packet.hpp"

#include "utopia/common/integers/count_digits.hpp"
#include "utopia/common/strings/get_format_string_length_ignoring_curly_brackets.hpp"

#include <pugixml.hpp>
#include <scn/scan.h>
#include <spdlog/spdlog.h>

#include <cstdint>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

constexpr std::string_view scan_str = "P /Sts/Connect STS/{}.{}\r\nl:{}";
constexpr std::uint32_t header_end_size =
    4; // before xml_content_ we have "\r\n\r\n" that we wish to skip

StsConnectPacket::StsConnectPacket(
    const std::vector<std::uint8_t> &data) noexcept {
  std::string data_str(data.begin(), data.end());

  auto scan_result = scn::scan<std::uint32_t, std::uint32_t, std::uint32_t>(
      data_str, scan_str);

  if (!scan_result) {
    is_valid_ = false;
    return;
  }

  auto &[scan_major, scan_minor, scan_xml_size] = scan_result->values();
  protocol_version_major = scan_major;
  protocol_version_minor = scan_minor;
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

  auto connect_node = doc.child("Connect");
  if (!connect_node) {
    spdlog::error("Failed to find Connect node.");
    is_valid_ = false;
    return;
  }

  conn_type = connect_node.child("ConnType").text().as_uint();
  client_address = connect_node.child("Address").text().as_string();
  product_type = connect_node.child("ProductType").text().as_uint();
  product_name = connect_node.child("ProductName").text().as_string();
  app_index = connect_node.child("AppIndex").text().as_uint();
  epoch = connect_node.child("Epoch").text().as_ullong();
  program = connect_node.child("Program").text().as_uint();
  build = connect_node.child("Build").text().as_uint();
  process_id = connect_node.child("Process").text().as_uint();

  is_valid_ = true;
}

std::uint32_t StsConnectPacket::get_packet_size() const noexcept {
  using namespace common;
  return get_format_string_length_ignoring_curly_brackets(scan_str) +
         count_digits(protocol_version_major) +
         count_digits(protocol_version_minor) + count_digits(xml_content_size) +
         xml_content_size + header_end_size;
}

std::vector<std::uint8_t> StsConnectPacket::serialize() noexcept {
  xml_content_ =
      fmt::format("<Connect>\n"
                  "<ConnType>{}</ConnType>\n"
                  "<Address>{}</Address>\n"
                  "<ProductType>{}</ProductType>\n"
                  "<ProductName>{}</ProductName>\n"
                  "<AppIndex>{}</AppIndex>\n"
                  "<Epoch>{}</Epoch>\n"
                  "<Program>{}</Program>\n"
                  "<Build>{}</Build>\n"
                  "<Process>{}</Process>\n"
                  "</Connect>\n",
                  conn_type, client_address, product_type, product_name,
                  app_index, epoch, program, build, process_id);
  xml_content_size = static_cast<uint32_t>(xml_content_.size());

  std::string packet_str =
      fmt::format(scan_str, protocol_version_major, protocol_version_minor,
                  xml_content_size) +
      "\r\n\r\n" + xml_content_;

  std::vector<std::uint8_t> packet(packet_str.begin(), packet_str.end());

  return packet;
}

} // namespace utopia::portal::client_connection
