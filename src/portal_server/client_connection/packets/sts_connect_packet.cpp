#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/client_connection/packets/sts_connect_packet.hpp"

#include <pugixml.hpp>
#include <scn/scan.h>
#include <spdlog/spdlog.h>

#include <cstdint>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

constexpr char scan_str[] = "P /Sts/Connect STS/{}.{}\r\nl:{}\r\n\r\n";

StsConnectPacket::StsConnectPacket(
    const std::vector<std::uint8_t> &data) noexcept {
  std::string data_str(data.begin(), data.end());

  auto scan_result = scn::scan<std::uint32_t, std::uint32_t, std::uint32_t>(
      data_str, scan_str);

  if (!scan_result) {
    spdlog::error("Failed to parse STS Connect packet.");
    is_valid_ = false;
    return;
  }

  auto &[major, minor, size] = scan_result->values();
  protocol_version_major = major;
  protocol_version_minor = minor;
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

  auto connect_node = doc.child("Connect");
  if (!connect_node) {
    spdlog::error("Failed to find Connect node.");
    is_valid_ = false;
    return;
  }

  conn_type = connect_node.child("ConnType").text().as_uint();
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
  // -4 (3 * {} + null terminator)
  return sizeof(scan_str) - 4 + xml_content_size;
}

} // namespace utopia::portal::client_connection
