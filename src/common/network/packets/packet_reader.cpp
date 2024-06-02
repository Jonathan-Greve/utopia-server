#include "utopia/utopia_pch.hpp"

#include "utopia/common/network/packets/packet_reader.hpp"

namespace utopia::core {
PacketReader::PacketReader() : header_id(0xFFFF), packet_valid(false) {}
PacketReader::~PacketReader() {};
} // namespace utopia::core
