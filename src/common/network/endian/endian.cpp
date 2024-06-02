#include "utopia/utopia_pch.hpp"

#include "utopia/common/network/endian/endian.hpp"

namespace utopia::core {

#include <cstdint>
#include <span>

std::uint32_t be24_dec(const void *pp) noexcept {
  auto p = std::span<const std::uint8_t, 3>(
      static_cast<const std::uint8_t *>(pp), 3);
  return ((static_cast<std::uint32_t>(p[0]) << 16) |
          (static_cast<std::uint32_t>(p[1]) << 8) | p[2]);
}

std::uint16_t be16_dec(const void *pp) noexcept {
  auto p = std::span<const std::uint8_t, 2>(
      static_cast<const std::uint8_t *>(pp), 2);
  return static_cast<uint16_t>((p[0] << 8) | p[1]);
}

std::uint32_t be32_dec(const void *pp) noexcept {
  auto p = std::span<const std::uint8_t, 4>(
      static_cast<const std::uint8_t *>(pp), 4);
  return ((static_cast<std::uint32_t>(p[0]) << 24) |
          (static_cast<std::uint32_t>(p[1]) << 16) |
          (static_cast<std::uint32_t>(p[2]) << 8) | p[3]);
}

std::uint64_t be64_dec(const void *pp) noexcept {
  auto p = std::span<const std::uint8_t, 8>(
      static_cast<const std::uint8_t *>(pp), 8);
  return ((static_cast<std::uint64_t>(be32_dec(p.subspan(0, 4).data())) << 32) |
          be32_dec(p.subspan(4, 4).data()));
}

std::uint16_t le16_dec(const void *pp) noexcept {
  auto p = std::span<const std::uint8_t, 2>(
      static_cast<const std::uint8_t *>(pp), 2);
  return static_cast<uint16_t>((p[1] << 8) | p[0]);
}

std::uint32_t le32_dec(const void *pp) noexcept {
  auto p = std::span<const std::uint8_t, 4>(
      static_cast<const std::uint8_t *>(pp), 4);
  return ((static_cast<std::uint32_t>(p[3]) << 24) |
          (static_cast<std::uint32_t>(p[2]) << 16) |
          (static_cast<std::uint32_t>(p[1]) << 8) |
          static_cast<std::uint32_t>(p[0]));
}

std::uint64_t le64_dec(const void *pp) noexcept {
  auto p = std::span<const std::uint8_t, 8>(
      static_cast<const std::uint8_t *>(pp), 8);
  return ((static_cast<std::uint64_t>(le32_dec(p.subspan(4, 4).data())) << 32) |
          le32_dec(p.subspan(0, 4).data()));
}

void be16_enc(void *pp, const std::uint16_t u) noexcept {
  auto p = std::span<std::uint8_t, 2>(static_cast<std::uint8_t *>(pp), 2);
  p[0] = static_cast<std::uint8_t>((u >> 8) & 0xff);
  p[1] = static_cast<std::uint8_t>(u & 0xff);
}

void be32_enc(void *pp, const std::uint32_t u) noexcept {
  auto p = std::span<std::uint8_t, 4>(static_cast<std::uint8_t *>(pp), 4);
  p[0] = (u >> 24) & 0xff;
  p[1] = (u >> 16) & 0xff;
  p[2] = (u >> 8) & 0xff;
  p[3] = u & 0xff;
}

void be64_enc(void *pp, const std::uint64_t u) noexcept {
  auto p = std::span<std::uint8_t, 8>(static_cast<std::uint8_t *>(pp), 8);
  be32_enc(p.subspan(0, 4).data(), static_cast<std::uint32_t>(u >> 32));
  be32_enc(p.subspan(4, 4).data(), static_cast<std::uint32_t>(u & 0xffffffff));
}

void le16_enc(void *pp, const std::uint16_t u) noexcept {
  auto p = std::span<std::uint8_t, 2>(static_cast<std::uint8_t *>(pp), 2);
  p[0] = static_cast<std::uint8_t>(u & 0xff);
  p[1] = static_cast<std::uint8_t>((u >> 8) & 0xff);
}

void le32_enc(void *pp, const std::uint32_t u) noexcept {
  auto p = std::span<std::uint8_t, 4>(static_cast<std::uint8_t *>(pp), 4);
  p[0] = u & 0xff;
  p[1] = (u >> 8) & 0xff;
  p[2] = (u >> 16) & 0xff;
  p[3] = (u >> 24) & 0xff;
}

void le64_enc(void *pp, const std::uint64_t u) noexcept {
  auto p = std::span<std::uint8_t, 8>(static_cast<std::uint8_t *>(pp), 8);
  le32_enc(p.subspan(0, 4).data(), static_cast<std::uint32_t>(u & 0xffffffff));
  le32_enc(p.subspan(4, 4).data(), static_cast<std::uint32_t>(u >> 32));
}

} // namespace utopia::core
