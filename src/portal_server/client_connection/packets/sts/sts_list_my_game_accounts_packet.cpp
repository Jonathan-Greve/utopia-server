#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/client_connection/packets/sts/sts_list_my_game_accounts_packet.hpp"

#include "utopia/common/integers/count_digits.hpp"
#include "utopia/common/strings/get_format_string_length_ignoring_curly_brackets.hpp"

#include <pugixml.hpp>
#include <scn/scan.h>
#include <spdlog/spdlog.h>

#include <cstdint>
#include <string>
#include <vector>

namespace utopia::portal::client_connection {

constexpr std::string_view scan_str =
    "P /Auth/ListMyGameAccounts STS/{}.{}\r\ns:{};timeout={}\r\nl:{}";

// before xml_content_ we have "\r\n\r\n" that we wish to skip
constexpr std::uint32_t header_end_size = 4;

StsListMyGameAccountsPacket::StsListMyGameAccountsPacket(
    const std::vector<std::uint8_t> &data) noexcept {
  std::string data_str(data.begin(), data.end());

  auto scan_result =
      scn::scan<std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t,
                std::uint32_t>(data_str, scan_str);

  if (!scan_result) {
    spdlog::error("Failed to parse STS ListMyGameAccounts packet.");
    is_valid_ = false;
    return;
  }

  auto &[scan_major, scan_minor, scan_sequence_number, scan_timeout,
         scan_xml_size] = scan_result->values();
  protocol_version_major = scan_major;
  protocol_version_minor = scan_minor;
  sequence_number = scan_sequence_number;
  timeout_ms = scan_timeout;
  xml_content_size = scan_xml_size;

  xml_content_ = std::string(scan_result->range().begin() + header_end_size,
                             scan_result->range().begin() + header_end_size +
                                 xml_content_size);

  if (xml_content_size != xml_content_.size()) {
    spdlog::error("XML content size does not match the expected size.");
    is_valid_ = false;
    return;
  }

  pugi::xml_document doc;
  pugi::xml_parse_result xml_parse_result =
      doc.load_string(xml_content_.c_str());

  if (!xml_parse_result) {
    spdlog::error("Failed to parse XML content.");
    is_valid_ = false;
    return;
  }

  auto request_node = doc.child("Request");
  if (!request_node) {
    spdlog::error("Failed to find Request node.");
    is_valid_ = false;
    return;
  }

  xml_content_game_code = request_node.child("GameCode").text().as_string();

  is_valid_ = true;
}

std::uint32_t StsListMyGameAccountsPacket::get_packet_size() const noexcept {
  using namespace common;
  return get_format_string_length_ignoring_curly_brackets(scan_str) +
         count_digits(protocol_version_major) +
         count_digits(protocol_version_minor) + count_digits(sequence_number) +
         count_digits(timeout_ms) + count_digits(xml_content_size) +
         xml_content_size + header_end_size;
}

std::vector<std::uint8_t> StsListMyGameAccountsPacket::serialize() noexcept {
  xml_content_ = std::format("<Request>\n"
                             "<GameCode>{}</GameCode>\n"
                             "</Request>\n",
                             xml_content_game_code);
  xml_content_size = static_cast<std::uint32_t>(xml_content_.size());

  std::string packet_str =
      fmt::format(scan_str, protocol_version_major, protocol_version_minor,
                  sequence_number, timeout_ms, xml_content_size) +
      "\r\n\r\n" + xml_content_;

  std::vector<std::uint8_t> packet(packet_str.begin(), packet_str.end());

  return packet;
}

} // namespace utopia::portal::client_connection
