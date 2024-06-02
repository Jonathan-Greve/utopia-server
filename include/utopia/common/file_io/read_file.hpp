#pragma once
#include <spdlog/spdlog.h>

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <vector>

namespace utopia::core {
inline std::optional<std::vector<std::uint8_t>>
read_file(const std::filesystem::path &filepath) {
  std::ifstream file(filepath, std::ios::binary);
  if (!file) {
    spdlog::error("Failed to open file:{}", filepath.string());
    return std::nullopt;
  }

  const auto file_size = std::filesystem::file_size(filepath);
  if (file_size <= 0) {
    spdlog::error("File is empty or an error occurred while determining the "
                  "file size: {}",
                  filepath.string());
    return std::nullopt;
  }

  std::vector<std::uint8_t> data(file_size);
  if (!file.read(reinterpret_cast<char *>(data.data()),
                 static_cast<std::streamsize>(file_size))) {
    spdlog::error("Failed to read from file: {}", filepath.string());
    return std::nullopt;
  }

  return data;
}
} // namespace utopia::core
