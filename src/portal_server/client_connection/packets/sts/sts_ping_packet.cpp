#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/client_connection/packets/sts/sts_ping_packet.hpp"

#include "utopia/common/integers/count_digits.hpp"
#include "utopia/common/strings/get_format_string_length_ignoring_curly_brackets.hpp"

#include <scn/scan.h>
#include <spdlog/spdlog.h>

#include <cstdint>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

constexpr std::string_view scan_str = "P /Sts/Ping STS/{}.{}\r\nl:{}";
constexpr std::uint32_t header_end_size =
    4; // before xml_content_ we have "\r\n\r\n" that we wish to skip

StsPingPacket::StsPingPacket(const std::vector<std::uint8_t> &data) noexcept {
  std::string data_str(data.begin(), data.end());

  auto scan_result = scn::scan<std::uint32_t, std::uint32_t, std::uint32_t>(
      data_str, scan_str);

  if (!scan_result) {
    spdlog::error("Failed to parse STS Ping packet.");
    is_valid_ = false;
    return;
  }

  auto &[scan_major, scan_minor, scan_xml_size] = scan_result->values();
  protocol_version_major = scan_major;
  protocol_version_minor = scan_minor;
  xml_content_size = scan_xml_size;

  xml_content_ = std::string(scan_result->range().begin() + header_end_size,
                             scan_result->range().end());

  if (xml_content_size != xml_content_.size()) {
    spdlog::error("XML content size does not match the expected size.");
    is_valid_ = false;
    return;
  }

  is_valid_ = true;
}

std::uint32_t StsPingPacket::get_packet_size() const noexcept {
  using namespace common;
  return get_format_string_length_ignoring_curly_brackets(scan_str) +
         count_digits(protocol_version_major) +
         count_digits(protocol_version_minor) + count_digits(xml_content_size) +
         xml_content_size + header_end_size;
}

std::vector<std::uint8_t> StsPingPacket::serialize() noexcept {
  xml_content_ = "";
  xml_content_size = 0;

  std::string packet_str =
      fmt::format(scan_str, protocol_version_major, protocol_version_minor,
                  xml_content_size) +
      "\r\n\r\n";

  std::vector<std::uint8_t> packet(packet_str.begin(), packet_str.end());

  return packet;
}

} // namespace utopia::portal::client_connection
