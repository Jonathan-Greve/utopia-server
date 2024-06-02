#pragma once

#include <glm/glm.hpp>

#include <cassert>
#include <cstdint>
#include <cstring>
#include <span>
#include <string>
#include <vector>

#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

namespace utopia::common {
class PacketReader {
public:
  virtual ~PacketReader();

  using agent_id = std::uint32_t;

  // Converts a big endian 2 byte integer to a little endian 2 byte integer.
  static std::uint16_t be16_to_le16(const void *pp) {
    auto p = std::span<const std::uint8_t, 2>(
        static_cast<const std::uint8_t *>(pp), 2);
    return static_cast<std::uint16_t>(p[1] << 8 | p[0]);
  }

  /**
   * @brief Get the number of bytes it took to construct the packet (not the
   * actual size of the packet).
   *
   * This virtual method returns the size, in bytes, of the constructed packet.
   * Derived classes should override this method to provide the actual packet
   * size.
   *
   * @return A std::uint16_t representing the packet size in bytes. Default
   * implementation returns 0.
   *
   * @note This function is used when creating the packet in a derived class to
   * know how many of the received bytes to delete from the receive buffer.
   */
  virtual std::uint16_t get_packet_size() const { return 0; }

  // The packet header_id. All packets have a unique header id.
  // The same header can be shared by packet different from different sources
  // (Game or Auth server, StoC and CtoS). e.g. game client and game server
  // packets can both have header_id 0.
  std::uint16_t header_id;

  bool packet_valid = false;

  PacketReader();
  PacketReader(std::uint16_t header_id) : header_id(header_id) {};
  PacketReader(const PacketReader &) = default;
  PacketReader &operator=(const PacketReader &) = default;

  PacketReader(PacketReader &&) = default;
  PacketReader &operator=(PacketReader &&) = default;

protected:
  static bool read_header_id(std::uint16_t &header_id,
                             std::vector<std::uint8_t>::const_iterator &it,
                             const std::vector<std::uint8_t> &data,
                             std::uint16_t &packet_size) {
    std::uint16_t remaining_range =
        static_cast<std::uint16_t>(std::ranges::distance(it, data.end()));
    if (remaining_range < sizeof(header_id))
      return false;

    std::memcpy(&header_id, &(*it), sizeof(header_id));
    header_id = be16_to_le16(&header_id);
    it += sizeof(header_id);

    packet_size += sizeof(header_id);

    return true;
  }

  template <typename T>
  static bool read_field(T &field,
                         std::vector<std::uint8_t>::const_iterator &it,
                         const std::vector<std::uint8_t> &data,
                         std::uint16_t &packet_size) {
    std::size_t remaining_range =
        static_cast<std::size_t>(std::ranges::distance(it, data.end()));
    if (remaining_range < sizeof(T)) {
      return false;
    }

    std::memcpy(&field, &(*it), sizeof(T));
    it += sizeof(T);

    packet_size += sizeof(T);

    return true;
  }

  static bool read_vec2(glm::vec2 &vec2_field,
                        std::vector<std::uint8_t>::const_iterator &it,
                        const std::vector<std::uint8_t> &data,
                        std::uint16_t &packet_size) {
    return read_field(vec2_field.x, it, data, packet_size) &&
           read_field(vec2_field.y, it, data, packet_size);
  }

  static bool read_vec3(glm::vec3 &vec3_field,
                        std::vector<std::uint8_t>::const_iterator &it,
                        const std::vector<std::uint8_t> &data,
                        std::uint16_t &packet_size) {
    return read_field(vec3_field.x, it, data, packet_size) &&
           read_field(vec3_field.y, it, data, packet_size) &&
           read_field(vec3_field.z, it, data, packet_size);
  }

  template <std::size_t N>
  static bool read_blob(std::array<std::uint8_t, N> &blob,
                        std::vector<std::uint8_t>::const_iterator &it,
                        const std::vector<std::uint8_t> &data,
                        std::uint16_t &packet_size) {
    std::size_t remaining_range =
        static_cast<std::size_t>(std::ranges::distance(it, data.end()));
    if (remaining_range < N) {
      return false;
    }

    std::copy(it, it + N, blob.begin());
    it += N;

    packet_size += N;

    return true;
  }

  static bool read_string(std::u16string &str, const std::uint16_t size,
                          std::vector<std::uint8_t>::const_iterator &it,
                          const std::vector<std::uint8_t> &data,
                          std::uint16_t &packet_size) {
    std::size_t remaining_range =
        static_cast<std::size_t>(std::ranges::distance(it, data.end()));
    if (remaining_range < sizeof(std::uint16_t)) {
      return false;
    }

    std::uint16_t length = 0;
    std::memcpy(&length, &(*it), sizeof(std::uint16_t));
    length = be16_to_le16(&length);

    if (length > size) {
      return false;
    }

    it += sizeof(length);

    packet_size += sizeof(length);

    remaining_range =
        static_cast<std::size_t>(std::ranges::distance(it, data.end()));
    if (remaining_range < static_cast<std::size_t>(length * sizeof(char16_t))) {
      return false;
    }

    str.clear();
    for (std::uint16_t i = 0; i < length; ++i) {
      char16_t ch;
      if (!read_field(ch, it, data, packet_size)) {
        return false;
      }
      str.push_back(ch);
    }

    return true;
  }

  template <std::copyable T>
  static bool read_array(std::vector<T> &array, const std::uint16_t size,
                         std::vector<std::uint8_t>::const_iterator &it,
                         const std::vector<std::uint8_t> &data,
                         std::uint16_t &packet_size) {
    std::size_t remaining_range =
        static_cast<std::size_t>(std::ranges::distance(it, data.end()));
    if (remaining_range < sizeof(std::uint16_t)) {
      return false;
    }

    const std::uint16_t length = be16_to_le16(&(*it));
    assert(length <= size);
    (void)size;
    it += sizeof(std::uint16_t);

    remaining_range =
        static_cast<std::size_t>(std::ranges::distance(it, data.end()));
    if (remaining_range < static_cast<std::size_t>(length * sizeof(T))) {
      return false;
    }

    array.insert(array.end(), reinterpret_cast<const T *>(&(*it)),
                 reinterpret_cast<const T *>(&(*it) + length * sizeof(T)));
    it += length * sizeof(T);

    packet_size += sizeof(length) + length * sizeof(T);

    return true;
  }

  template <std::copyable T>
  static bool read_extra_struct(T *p_extra_struct,
                                std::uint16_t &extra_struct_data_size,
                                const std::uint16_t size,
                                std::vector<std::uint8_t>::const_iterator &it,
                                const std::vector<std::uint8_t> &data,
                                std::uint16_t &packet_size) {
    std::size_t remaining_range =
        static_cast<std::size_t>(std::ranges::distance(it, data.end()));
    if (remaining_range < sizeof(std::uint16_t)) {
      return false;
    }

    const std::uint16_t length = be16_to_le16(&(*it));
    assert(length <= size);
    (void)size;

    extra_struct_data_size = length;
    it += sizeof(std::uint16_t);

    remaining_range =
        static_cast<std::size_t>(std::ranges::distance(it, data.end()));
    if (remaining_range < static_cast<std::size_t>(length * sizeof(T))) {
      return false;
    }

    memcpy(p_extra_struct, &(*it), length * sizeof(T));
    it += length * sizeof(T);

    packet_size += sizeof(length) + length * sizeof(T);

    return true;
  }

  template <typename T>
  static void pack_field(const T &field, std::vector<std::uint8_t> &data) {
    std::span<const std::uint8_t> bytes(
        reinterpret_cast<const std::uint8_t *>(&field), sizeof(T));
    data.insert(data.end(), bytes.begin(), bytes.end());
  }

  static void pack_header_id(const std::uint16_t header_id,
                             std::vector<std::uint8_t> &data) {
    // const std::uint16_t be_header_id = (header_id >> 8) | (header_id << 8);
    // // Convert to big-endian
    pack_field(header_id, data);
  }

  static void pack_string(const std::u16string &str,
                          std::vector<std::uint8_t> &data) {
    auto size = static_cast<std::uint16_t>(str.size());
    // size = (size >> 8) | (size << 8); // Convert to big-endian
    pack_field(size, data);
    for (const char16_t ch : str) {
      pack_field(ch, data);
    }
  }

  template <typename T>
  static void pack_array(const std::vector<T> &array,
                         std::vector<std::uint8_t> &data) {
    auto size = static_cast<std::uint16_t>(array.size());
    // size = (size >> 8) | (size << 8); // Convert to big-endian
    pack_field(size, data);
    for (const T &element : array) {
      pack_field(element, data);
    }
  }

  template <std::size_t N>
  static void pack_blob(const std::array<std::uint8_t, N> &blob,
                        std::vector<std::uint8_t> &data) {
    data.insert(data.end(), blob.begin(), blob.end());
  }

  static void pack_vec2(const glm::vec2 &field,
                        std::vector<std::uint8_t> &data) {
    pack_field(field.x, data);
    pack_field(field.y, data);
  }

  static void pack_vec3(const glm::vec3 &vec3_field,
                        std::vector<std::uint8_t> &data) {
    pack_field(vec3_field.x, data);
    pack_field(vec3_field.y, data);
    pack_field(vec3_field.z, data);
  }

  template <typename T>
  static void pack_extra_struct(T *extra_struct,
                                const std::uint16_t extra_struct_data_size,
                                std::vector<std::uint8_t> &data) {
    std::uint16_t struct_size = sizeof(T);
    assert(extra_struct_data_size <= struct_size);
    (void)struct_size;

    data.resize(data.size() + extra_struct_data_size + 2);
    std::uint8_t *insert_ptr = &data[data.size() - extra_struct_data_size - 2];
    // size = (size >> 8) | (size << 8); // Convert to big-endian
    memcpy(insert_ptr, &extra_struct_data_size, sizeof(std::uint16_t));
    memcpy(insert_ptr + 2, extra_struct, extra_struct_data_size);
  }
};
} // namespace utopia::common
