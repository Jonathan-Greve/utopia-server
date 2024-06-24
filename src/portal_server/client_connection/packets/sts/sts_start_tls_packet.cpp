#include "utopia/utopia_pch.hpp"

#include "utopia/portal_server/client_connection/packets/sts/sts_start_tls_packet.hpp"

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
    "P /Auth/StartTls STS/{}.{}\r\ns:{};timeout={}\r\nl:{}";
constexpr std::string_view scan_alternative_str =
    "P /Auth/StartTls STS/{}.{}\r\nl:{}\r\ns:{};timeout={}";

// before xml_content_ we have "\r\n\r\n" that we wish to skip
constexpr std::uint32_t header_end_size = 4;

StsStartTlsPacket::StsStartTlsPacket(
    const std::vector<std::uint8_t> &data) noexcept {
  std::string data_str(data.begin(), data.end());

  auto scan_result =
      scn::scan<std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t,
                std::uint32_t>(data_str, scan_str);

  auto scan_alternative_result =
      scn::scan<std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t,
                std::uint32_t>(data_str, scan_alternative_str);

  if (scan_result) {
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
  } else if (scan_alternative_result) {
    auto &[scan_major, scan_minor, scan_xml_size, scan_sequence_number,
           scan_timeout] = scan_alternative_result->values();
    protocol_version_major = scan_major;
    protocol_version_minor = scan_minor;
    sequence_number = scan_sequence_number;
    timeout_ms = scan_timeout;
    xml_content_size = scan_xml_size;

    xml_content_ =
        std::string(scan_alternative_result->range().begin() + header_end_size,
                    scan_alternative_result->range().begin() + header_end_size +
                        xml_content_size);

    alternative_scan_str_used = true;
  } else {
    is_valid_ = false;
    return;
  }

  if (xml_content_size != xml_content_.size()) {
    spdlog::error("XML content size does not match the expected size.");
    is_valid_ = false;
    return;
  }

  is_valid_ = true;
}

std::uint32_t StsStartTlsPacket::get_packet_size() const noexcept {
  using namespace common;
  return get_format_string_length_ignoring_curly_brackets(scan_str) +
         count_digits(protocol_version_major) +
         count_digits(protocol_version_minor) + count_digits(sequence_number) +
         count_digits(timeout_ms) + count_digits(xml_content_size) +
         xml_content_size + header_end_size;
}

std::vector<std::uint8_t> StsStartTlsPacket::serialize() noexcept {
  xml_content_ = "";
  xml_content_size = 0;
  std::string packet_str;
  if (alternative_scan_str_used) {
    packet_str = fmt::format(scan_alternative_str, protocol_version_major,
                             protocol_version_minor, xml_content_size,
                             sequence_number, timeout_ms) +
                 "\r\n\r\n";
  } else {
    packet_str =
        fmt::format(scan_str, protocol_version_major, protocol_version_minor,
                    sequence_number, timeout_ms, xml_content_size) +
        "\r\n\r\n";
  }

  std::vector<std::uint8_t> packet(packet_str.begin(), packet_str.end());

  return packet;
}

} // namespace utopia::portal::client_connection
