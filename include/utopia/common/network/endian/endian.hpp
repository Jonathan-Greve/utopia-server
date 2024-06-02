#pragma once

#include <cstdint>

namespace utopia::core {

std::uint32_t be24_dec(const void *pp) noexcept;
std::uint16_t be16_dec(const void *pp) noexcept;
std::uint32_t be32_dec(const void *pp) noexcept;
std::uint64_t be64_dec(const void *pp) noexcept;

std::uint16_t le16_dec(const void *pp) noexcept;
std::uint32_t le32_dec(const void *pp) noexcept;
std::uint64_t le64_dec(const void *pp) noexcept;

void be16_enc(void *pp, const std::uint16_t u) noexcept;
void be32_enc(void *pp, const std::uint32_t u) noexcept;
void be64_enc(void *pp, const std::uint64_t u) noexcept;

void le16_enc(void *pp, const std::uint16_t u) noexcept;
void le32_enc(void *pp, const std::uint32_t u) noexcept;
void le64_enc(void *pp, const std::uint64_t u) noexcept;

} // namespace utopia::core
