#ifndef GAME_SERVER_PACKETS_HPP
#define GAME_SERVER_PACKETS_HPP

#include "utopia/common/network/packets/packet_reader.hpp"

#include <glm/glm.hpp>

#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace utopia {
namespace common {

class GameServerTradeRequest : public PacketReader {
public:
  GameServerTradeRequest() : PacketReader(0) {};
  GameServerTradeRequest(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTradeTerminate : public PacketReader {
public:
  GameServerTradeTerminate() : PacketReader(1) {};
  GameServerTradeTerminate(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTradeChangeOffer : public PacketReader {
public:
  GameServerTradeChangeOffer() : PacketReader(2) {};
  GameServerTradeChangeOffer(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTradeReceiveOffer : public PacketReader {
public:
  GameServerTradeReceiveOffer() : PacketReader(3) {};
  GameServerTradeReceiveOffer(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTradeAddItem : public PacketReader {
public:
  GameServerTradeAddItem() : PacketReader(4) {};
  GameServerTradeAddItem(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTradeAcknowledge : public PacketReader {
public:
  GameServerTradeAcknowledge() : PacketReader(5) {};
  GameServerTradeAcknowledge(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTradeAccept : public PacketReader {
public:
  GameServerTradeAccept() : PacketReader(6) {};
  GameServerTradeAccept(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket007 : public PacketReader {
public:
  GameServerPacket007() : PacketReader(7) {};
  GameServerPacket007(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTradeOfferedCount : public PacketReader {
public:
  GameServerTradeOfferedCount() : PacketReader(8) {};
  GameServerTradeOfferedCount(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket009 : public PacketReader {
public:
  GameServerPacket009() : PacketReader(9) {};
  GameServerPacket009(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket010 : public PacketReader {
public:
  GameServerPacket010() : PacketReader(10) {};
  GameServerPacket010(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket011 : public PacketReader {
public:
  GameServerPacket011() : PacketReader(11) {};
  GameServerPacket011(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPingRequest : public PacketReader {
public:
  GameServerPingRequest() : PacketReader(12) {};
  GameServerPingRequest(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPingReply : public PacketReader {
public:
  GameServerPingReply() : PacketReader(13) {};
  GameServerPingReply(const std::vector<std::uint8_t> &data);
  std::uint32_t ping_ms;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerFriendlistMessage : public PacketReader {
public:
  GameServerFriendlistMessage() : PacketReader(14) {};
  GameServerFriendlistMessage(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::u16string field_2;
  std::u16string field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAccountCurrency : public PacketReader {
public:
  GameServerAccountCurrency() : PacketReader(15) {};
  GameServerAccountCurrency(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;
  std::uint16_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket016 : public PacketReader {
public:
  GameServerPacket016() : PacketReader(16) {};
  GameServerPacket016(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket017 : public PacketReader {
public:
  GameServerPacket017() : PacketReader(17) {};
  GameServerPacket017(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket018 : public PacketReader {
public:
  GameServerPacket018() : PacketReader(18) {};
  GameServerPacket018(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket019 : public PacketReader {
public:
  GameServerPacket019() : PacketReader(19) {};
  GameServerPacket019(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket020 : public PacketReader {
public:
  GameServerPacket020() : PacketReader(20) {};
  GameServerPacket020(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket021 : public PacketReader {
public:
  GameServerPacket021() : PacketReader(21) {};
  GameServerPacket021(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket022 : public PacketReader {
public:
  GameServerPacket022() : PacketReader(22) {};
  GameServerPacket022(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket023 : public PacketReader {
public:
  GameServerPacket023() : PacketReader(23) {};
  GameServerPacket023(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint8_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint8_t field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket024 : public PacketReader {
public:
  GameServerPacket024() : PacketReader(24) {};
  GameServerPacket024(const std::vector<std::uint8_t> &data);
  std::vector<std::uint32_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket025 : public PacketReader {
public:
  GameServerPacket025() : PacketReader(25) {};
  GameServerPacket025(const std::vector<std::uint8_t> &data);
  struct some_struct {
    std::uint32_t field_0;
  };

  std::uint16_t field_0;
  std::uint8_t field_1;
  std::vector<some_struct> field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  bool read_struct(std::vector<std::uint8_t>::const_iterator &it,
                   const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket026 : public PacketReader {
public:
  GameServerPacket026() : PacketReader(26) {};
  GameServerPacket026(const std::vector<std::uint8_t> &data);
  struct some_struct {
    std::uint32_t field_0;
  };

  std::uint16_t field_0;
  std::vector<some_struct> field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  bool read_struct(std::vector<std::uint8_t>::const_iterator &it,
                   const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket027 : public PacketReader {
public:
  GameServerPacket027() : PacketReader(27) {};
  GameServerPacket027(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket028 : public PacketReader {
public:
  GameServerPacket028() : PacketReader(28) {};
  GameServerPacket028(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket029 : public PacketReader {
public:
  GameServerPacket029() : PacketReader(29) {};
  GameServerPacket029(const std::vector<std::uint8_t> &data);
  std::vector<std::uint32_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentMovementTick : public PacketReader {
public:
  GameServerAgentMovementTick() : PacketReader(30) {};
  GameServerAgentMovementTick(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentInstanceTimer : public PacketReader {
public:
  GameServerAgentInstanceTimer() : PacketReader(31) {};
  GameServerAgentInstanceTimer(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentSpawned : public PacketReader {
public:
  GameServerAgentSpawned() : PacketReader(32) {};
  GameServerAgentSpawned(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;
  glm::vec2 field_4;
  std::uint16_t field_5;
  glm::vec2 field_6;
  std::uint8_t field_7;
  float field_8;
  float field_9;
  std::uint32_t field_10;
  std::uint32_t field_11;
  std::uint32_t field_12;
  std::uint32_t field_13;
  std::uint32_t field_14;
  std::uint32_t field_15;
  std::uint32_t field_16;
  glm::vec2 field_17;
  glm::vec2 field_18;
  std::uint16_t field_19;
  std::uint32_t field_20;
  glm::vec2 field_21;
  std::uint16_t field_22;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentDespawned : public PacketReader {
public:
  GameServerAgentDespawned() : PacketReader(33) {};
  GameServerAgentDespawned(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentSetPlayer : public PacketReader {
public:
  GameServerAgentSetPlayer() : PacketReader(34) {};
  GameServerAgentSetPlayer(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket035 : public PacketReader {
public:
  GameServerPacket035() : PacketReader(35) {};
  GameServerPacket035(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket036 : public PacketReader {
public:
  GameServerPacket036() : PacketReader(36) {};
  GameServerPacket036(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentUpdateDirection : public PacketReader {
public:
  GameServerAgentUpdateDirection() : PacketReader(37) {};
  GameServerAgentUpdateDirection(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  glm::vec2 field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket038 : public PacketReader {
public:
  GameServerPacket038() : PacketReader(38) {};
  GameServerPacket038(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentUpdateSpeedBase : public PacketReader {
public:
  GameServerAgentUpdateSpeedBase() : PacketReader(39) {};
  GameServerAgentUpdateSpeedBase(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  float field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentStopMoving : public PacketReader {
public:
  GameServerAgentStopMoving() : PacketReader(40) {};
  GameServerAgentStopMoving(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentMoveToPoint : public PacketReader {
public:
  GameServerAgentMoveToPoint() : PacketReader(41) {};
  GameServerAgentMoveToPoint(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  glm::vec2 field_1;
  std::uint16_t field_2;
  std::uint16_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentUpdateDestination : public PacketReader {
public:
  GameServerAgentUpdateDestination() : PacketReader(42) {};
  GameServerAgentUpdateDestination(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  glm::vec2 field_1;
  std::uint16_t field_2;
  std::uint16_t field_3;
  std::uint32_t field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentUpdateSpeed : public PacketReader {
public:
  GameServerAgentUpdateSpeed() : PacketReader(43) {};
  GameServerAgentUpdateSpeed(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  float field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentUpdatePosition : public PacketReader {
public:
  GameServerAgentUpdatePosition() : PacketReader(44) {};
  GameServerAgentUpdatePosition(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  glm::vec2 field_1;
  std::uint16_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentPlayerDie : public PacketReader {
public:
  GameServerAgentPlayerDie() : PacketReader(45) {};
  GameServerAgentPlayerDie(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentUpdateRotation : public PacketReader {
public:
  GameServerAgentUpdateRotation() : PacketReader(46) {};
  GameServerAgentUpdateRotation(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentUpdateAllegiance : public PacketReader {
public:
  GameServerAgentUpdateAllegiance() : PacketReader(47) {};
  GameServerAgentUpdateAllegiance(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket048 : public PacketReader {
public:
  GameServerPacket048() : PacketReader(48) {};
  GameServerPacket048(const std::vector<std::uint8_t> &data);
  std::u16string field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint32_t field_6;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerHeroAccountName : public PacketReader {
public:
  GameServerHeroAccountName() : PacketReader(49) {};
  GameServerHeroAccountName(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket050 : public PacketReader {
public:
  GameServerPacket050() : PacketReader(50) {};
  GameServerPacket050(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerMessageOfTheDay : public PacketReader {
public:
  GameServerMessageOfTheDay() : PacketReader(51) {};
  GameServerMessageOfTheDay(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentPinged : public PacketReader {
public:
  GameServerAgentPinged() : PacketReader(52) {};
  GameServerAgentPinged(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  agent_id field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket053 : public PacketReader {
public:
  GameServerPacket053() : PacketReader(53) {};
  GameServerPacket053(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket054 : public PacketReader {
public:
  GameServerPacket054() : PacketReader(54) {};
  GameServerPacket054(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket055 : public PacketReader {
public:
  GameServerPacket055() : PacketReader(55) {};
  GameServerPacket055(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket056 : public PacketReader {
public:
  GameServerPacket056() : PacketReader(56) {};
  GameServerPacket056(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket057 : public PacketReader {
public:
  GameServerPacket057() : PacketReader(57) {};
  GameServerPacket057(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentUpdateAttribute : public PacketReader {
public:
  GameServerAgentUpdateAttribute() : PacketReader(58) {};
  GameServerAgentUpdateAttribute(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::vector<std::uint32_t> field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket059 : public PacketReader {
public:
  GameServerPacket059() : PacketReader(59) {};
  GameServerPacket059(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket060 : public PacketReader {
public:
  GameServerPacket060() : PacketReader(60) {};
  GameServerPacket060(const std::vector<std::uint8_t> &data);
  std::u16string field_0;
  std::u16string field_1;
  std::uint8_t field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentAllyDestroy : public PacketReader {
public:
  GameServerAgentAllyDestroy() : PacketReader(61) {};
  GameServerAgentAllyDestroy(const std::vector<std::uint8_t> &data);
  agent_id field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerEffectUpkeepAdded : public PacketReader {
public:
  GameServerEffectUpkeepAdded() : PacketReader(62) {};
  GameServerEffectUpkeepAdded(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  agent_id field_1;
  std::uint16_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerEffectUpkeepRemoved : public PacketReader {
public:
  GameServerEffectUpkeepRemoved() : PacketReader(63) {};
  GameServerEffectUpkeepRemoved(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerEffectUpkeepApplied : public PacketReader {
public:
  GameServerEffectUpkeepApplied() : PacketReader(64) {};
  GameServerEffectUpkeepApplied(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  agent_id field_1;
  std::uint16_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerEffectApplied : public PacketReader {
public:
  GameServerEffectApplied() : PacketReader(65) {};
  GameServerEffectApplied(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerEffectRenewed : public PacketReader {
public:
  GameServerEffectRenewed() : PacketReader(66) {};
  GameServerEffectRenewed(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerEffectRemoved : public PacketReader {
public:
  GameServerEffectRemoved() : PacketReader(67) {};
  GameServerEffectRemoved(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket068 : public PacketReader {
public:
  GameServerPacket068() : PacketReader(68) {};
  GameServerPacket068(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerScreenShake : public PacketReader {
public:
  GameServerScreenShake() : PacketReader(69) {};
  GameServerScreenShake(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  agent_id field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket070 : public PacketReader {
public:
  GameServerPacket070() : PacketReader(70) {};
  GameServerPacket070(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  glm::vec2 field_2;
  std::uint16_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentDisplayCape : public PacketReader {
public:
  GameServerAgentDisplayCape() : PacketReader(71) {};
  GameServerAgentDisplayCape(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerQuestGeneralInfo : public PacketReader {
public:
  GameServerQuestGeneralInfo() : PacketReader(72) {};
  GameServerQuestGeneralInfo(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  glm::vec2 field_1;
  std::uint16_t field_2;
  std::uint16_t field_3;
  std::uint32_t field_4;
  std::u16string field_5;
  std::u16string field_6;
  std::u16string field_7;
  std::uint16_t field_8;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket073 : public PacketReader {
public:
  GameServerPacket073() : PacketReader(73) {};
  GameServerPacket073(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket074 : public PacketReader {
public:
  GameServerPacket074() : PacketReader(74) {};
  GameServerPacket074(const std::vector<std::uint8_t> &data);
  std::vector<std::uint32_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerQuestDescription : public PacketReader {
public:
  GameServerQuestDescription() : PacketReader(75) {};
  GameServerQuestDescription(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;
  std::u16string field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket076 : public PacketReader {
public:
  GameServerPacket076() : PacketReader(76) {};
  GameServerPacket076(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  glm::vec2 field_1;
  std::uint16_t field_2;
  std::uint16_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket077 : public PacketReader {
public:
  GameServerPacket077() : PacketReader(77) {};
  GameServerPacket077(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket078 : public PacketReader {
public:
  GameServerPacket078() : PacketReader(78) {};
  GameServerPacket078(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerQuestAdd : public PacketReader {
public:
  GameServerQuestAdd() : PacketReader(79) {};
  GameServerQuestAdd(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::u16string field_2;
  std::u16string field_3;
  std::u16string field_4;
  std::uint16_t field_5;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerQuestUpdateMarker : public PacketReader {
public:
  GameServerQuestUpdateMarker() : PacketReader(80) {};
  GameServerQuestUpdateMarker(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  glm::vec2 field_1;
  std::uint16_t field_2;
  std::uint16_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerQuestRemove : public PacketReader {
public:
  GameServerQuestRemove() : PacketReader(81) {};
  GameServerQuestRemove(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerQuestAddMarker : public PacketReader {
public:
  GameServerQuestAddMarker() : PacketReader(82) {};
  GameServerQuestAddMarker(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  glm::vec2 field_1;
  std::uint16_t field_2;
  std::uint16_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket083 : public PacketReader {
public:
  GameServerPacket083() : PacketReader(83) {};
  GameServerPacket083(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket084 : public PacketReader {
public:
  GameServerPacket084() : PacketReader(84) {};
  GameServerPacket084(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerNPCUpdateProperties : public PacketReader {
public:
  GameServerNPCUpdateProperties() : PacketReader(85) {};
  GameServerNPCUpdateProperties(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint8_t field_6;
  std::uint8_t field_7;
  std::u16string field_8;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerNPCUpdateModel : public PacketReader {
public:
  GameServerNPCUpdateModel() : PacketReader(86) {};
  GameServerNPCUpdateModel(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::vector<std::uint32_t> field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket087 : public PacketReader {
public:
  GameServerPacket087() : PacketReader(87) {};
  GameServerPacket087(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentCreatePlayer : public PacketReader {
public:
  GameServerAgentCreatePlayer() : PacketReader(88) {};
  GameServerAgentCreatePlayer(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  agent_id field_1;
  std::uint32_t field_2;
  std::uint8_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::u16string field_6;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentDestroyPlayer : public PacketReader {
public:
  GameServerAgentDestroyPlayer() : PacketReader(89) {};
  GameServerAgentDestroyPlayer(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket090 : public PacketReader {
public:
  GameServerPacket090() : PacketReader(90) {};
  GameServerPacket090(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket091 : public PacketReader {
public:
  GameServerPacket091() : PacketReader(91) {};
  GameServerPacket091(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  agent_id field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerChatMessageCore : public PacketReader {
public:
  GameServerChatMessageCore() : PacketReader(92) {};
  GameServerChatMessageCore(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerChatMessageServer : public PacketReader {
public:
  GameServerChatMessageServer() : PacketReader(93) {};
  GameServerChatMessageServer(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerChatMessageNPC : public PacketReader {
public:
  GameServerChatMessageNPC() : PacketReader(94) {};
  GameServerChatMessageNPC(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;
  std::u16string field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerChatMessageGlobal : public PacketReader {
public:
  GameServerChatMessageGlobal() : PacketReader(95) {};
  GameServerChatMessageGlobal(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::u16string field_1;
  std::u16string field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerChatMessageLocal : public PacketReader {
public:
  GameServerChatMessageLocal() : PacketReader(96) {};
  GameServerChatMessageLocal(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerHeroBehavior : public PacketReader {
public:
  GameServerHeroBehavior() : PacketReader(97) {};
  GameServerHeroBehavior(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket098 : public PacketReader {
public:
  GameServerPacket098() : PacketReader(98) {};
  GameServerPacket098(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  agent_id field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerHeroSkillStatus : public PacketReader {
public:
  GameServerHeroSkillStatus() : PacketReader(99) {};
  GameServerHeroSkillStatus(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerHeroSkillStatusBitmap : public PacketReader {
public:
  GameServerHeroSkillStatusBitmap() : PacketReader(100) {};
  GameServerHeroSkillStatusBitmap(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket101 : public PacketReader {
public:
  GameServerPacket101() : PacketReader(101) {};
  GameServerPacket101(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  glm::vec2 field_1;
  std::uint16_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket102 : public PacketReader {
public:
  GameServerPacket102() : PacketReader(102) {};
  GameServerPacket102(const std::vector<std::uint8_t> &data);
  glm::vec2 field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket103 : public PacketReader {
public:
  GameServerPacket103() : PacketReader(103) {};
  GameServerPacket103(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket104 : public PacketReader {
public:
  GameServerPacket104() : PacketReader(104) {};
  GameServerPacket104(const std::vector<std::uint8_t> &data);
  agent_id field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket105 : public PacketReader {
public:
  GameServerPacket105() : PacketReader(105) {};
  GameServerPacket105(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPostProcess : public PacketReader {
public:
  GameServerPostProcess() : PacketReader(106) {};
  GameServerPostProcess(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerDungeonReward : public PacketReader {
public:
  GameServerDungeonReward() : PacketReader(107) {};
  GameServerDungeonReward(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerNPCUpdateWeapons : public PacketReader {
public:
  GameServerNPCUpdateWeapons() : PacketReader(108) {};
  GameServerNPCUpdateWeapons(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket109 : public PacketReader {
public:
  GameServerPacket109() : PacketReader(109) {};
  GameServerPacket109(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint32_t field_6;
  std::uint32_t field_7;
  std::uint32_t field_8;
  std::uint32_t field_9;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket110 : public PacketReader {
public:
  GameServerPacket110() : PacketReader(110) {};
  GameServerPacket110(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket111 : public PacketReader {
public:
  GameServerPacket111() : PacketReader(111) {};
  GameServerPacket111(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket112 : public PacketReader {
public:
  GameServerPacket112() : PacketReader(112) {};
  GameServerPacket112(const std::vector<std::uint8_t> &data);
  agent_id field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket113 : public PacketReader {
public:
  GameServerPacket113() : PacketReader(113) {};
  GameServerPacket113(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  agent_id field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket114 : public PacketReader {
public:
  GameServerPacket114() : PacketReader(114) {};
  GameServerPacket114(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint8_t field_6;
  std::uint8_t field_7;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerMercenaryInfo : public PacketReader {
public:
  GameServerMercenaryInfo() : PacketReader(115) {};
  GameServerMercenaryInfo(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint8_t field_6;
  std::uint8_t field_7;
  std::uint32_t field_8;
  std::uint32_t field_9;
  std::uint32_t field_10;
  std::uint32_t field_11;
  std::uint32_t field_12;
  std::uint32_t field_13;
  std::uint32_t field_14;
  std::uint32_t field_15;
  std::uint32_t field_16;
  std::uint32_t field_17;
  std::uint32_t field_18;
  std::u16string field_19;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket116 : public PacketReader {
public:
  GameServerPacket116() : PacketReader(116) {};
  GameServerPacket116(const std::vector<std::uint8_t> &data);
  agent_id field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket117 : public PacketReader {
public:
  GameServerPacket117() : PacketReader(117) {};
  GameServerPacket117(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket118 : public PacketReader {
public:
  GameServerPacket118() : PacketReader(118) {};
  GameServerPacket118(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket119 : public PacketReader {
public:
  GameServerPacket119() : PacketReader(119) {};
  GameServerPacket119(const std::vector<std::uint8_t> &data);
  struct some_struct {
    std::uint16_t field_0;
    std::uint8_t field_1;
    std::uint32_t field_2;
    std::uint32_t field_3;
    std::uint8_t field_4;
  };

  std::uint8_t field_0;
  std::vector<some_struct> field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  bool read_struct(std::vector<std::uint8_t>::const_iterator &it,
                   const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket120 : public PacketReader {
public:
  GameServerPacket120() : PacketReader(120) {};
  GameServerPacket120(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket121 : public PacketReader {
public:
  GameServerPacket121() : PacketReader(121) {};
  GameServerPacket121(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket122 : public PacketReader {
public:
  GameServerPacket122() : PacketReader(122) {};
  GameServerPacket122(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket123 : public PacketReader {
public:
  GameServerPacket123() : PacketReader(123) {};
  GameServerPacket123(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket124 : public PacketReader {
public:
  GameServerPacket124() : PacketReader(124) {};
  GameServerPacket124(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerDialogButton : public PacketReader {
public:
  GameServerDialogButton() : PacketReader(125) {};
  GameServerDialogButton(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::u16string field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket126 : public PacketReader {
public:
  GameServerPacket126() : PacketReader(126) {};
  GameServerPacket126(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerDialogBody : public PacketReader {
public:
  GameServerDialogBody() : PacketReader(127) {};
  GameServerDialogBody(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerDialogSender : public PacketReader {
public:
  GameServerDialogSender() : PacketReader(128) {};
  GameServerDialogSender(const std::vector<std::uint8_t> &data);
  agent_id field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket129 : public PacketReader {
public:
  GameServerPacket129() : PacketReader(129) {};
  GameServerPacket129(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerWindowOpen : public PacketReader {
public:
  GameServerWindowOpen() : PacketReader(130) {};
  GameServerWindowOpen(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerWindowAddItems : public PacketReader {
public:
  GameServerWindowAddItems() : PacketReader(131) {};
  GameServerWindowAddItems(const std::vector<std::uint8_t> &data);
  std::vector<std::uint32_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerWindowItemsEnd : public PacketReader {
public:
  GameServerWindowItemsEnd() : PacketReader(132) {};
  GameServerWindowItemsEnd(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerWindowItemStreamEnd : public PacketReader {
public:
  GameServerWindowItemStreamEnd() : PacketReader(133) {};
  GameServerWindowItemStreamEnd(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket134 : public PacketReader {
public:
  GameServerPacket134() : PacketReader(134) {};
  GameServerPacket134(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint32_t field_6;
  std::uint32_t field_7;
  std::uint16_t field_8;
  std::uint16_t field_9;
  std::uint16_t field_10;
  std::uint16_t field_11;
  std::uint16_t field_12;
  std::uint8_t field_13;
  std::uint8_t field_14;
  std::uint8_t field_15;
  std::uint8_t field_16;
  std::uint8_t field_17;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket135 : public PacketReader {
public:
  GameServerPacket135() : PacketReader(135) {};
  GameServerPacket135(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket136 : public PacketReader {
public:
  GameServerPacket136() : PacketReader(136) {};
  GameServerPacket136(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  glm::vec3 field_1;
  glm::vec2 field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerCartographyData : public PacketReader {
public:
  GameServerCartographyData() : PacketReader(137) {};
  GameServerCartographyData(const std::vector<std::uint8_t> &data);
  std::vector<std::uint32_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket138 : public PacketReader {
public:
  GameServerPacket138() : PacketReader(138) {};
  GameServerPacket138(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket139 : public PacketReader {
public:
  GameServerPacket139() : PacketReader(139) {};
  GameServerPacket139(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket140 : public PacketReader {
public:
  GameServerPacket140() : PacketReader(140) {};
  GameServerPacket140(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  glm::vec2 field_1;
  std::uint16_t field_2;
  std::uint8_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::u16string field_6;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket141 : public PacketReader {
public:
  GameServerPacket141() : PacketReader(141) {};
  GameServerPacket141(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket142 : public PacketReader {
public:
  GameServerPacket142() : PacketReader(142) {};
  GameServerPacket142(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket143 : public PacketReader {
public:
  GameServerPacket143() : PacketReader(143) {};
  GameServerPacket143(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerCompassDrawing : public PacketReader {
public:
  GameServerCompassDrawing() : PacketReader(144) {};
  GameServerCompassDrawing(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;
  std::vector<std::uint32_t> field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket145 : public PacketReader {
public:
  GameServerPacket145() : PacketReader(145) {};
  GameServerPacket145(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket146 : public PacketReader {
public:
  GameServerPacket146() : PacketReader(146) {};
  GameServerPacket146(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerMapsUnlocked : public PacketReader {
public:
  GameServerMapsUnlocked() : PacketReader(147) {};
  GameServerMapsUnlocked(const std::vector<std::uint8_t> &data);
  std::vector<std::uint32_t> field_0;
  std::vector<std::uint32_t> field_1;
  std::vector<std::uint32_t> field_2;
  std::vector<std::uint32_t> field_3;
  std::vector<std::uint32_t> field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket148 : public PacketReader {
public:
  GameServerPacket148() : PacketReader(148) {};
  GameServerPacket148(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket149 : public PacketReader {
public:
  GameServerPacket149() : PacketReader(149) {};
  GameServerPacket149(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket150 : public PacketReader {
public:
  GameServerPacket150() : PacketReader(150) {};
  GameServerPacket150(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket151 : public PacketReader {
public:
  GameServerPacket151() : PacketReader(151) {};
  GameServerPacket151(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket152 : public PacketReader {
public:
  GameServerPacket152() : PacketReader(152) {};
  GameServerPacket152(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentUpdateScale : public PacketReader {
public:
  GameServerAgentUpdateScale() : PacketReader(153) {};
  GameServerAgentUpdateScale(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentUpdateNPCName : public PacketReader {
public:
  GameServerAgentUpdateNPCName() : PacketReader(154) {};
  GameServerAgentUpdateNPCName(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket155 : public PacketReader {
public:
  GameServerPacket155() : PacketReader(155) {};
  GameServerPacket155(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket156 : public PacketReader {
public:
  GameServerPacket156() : PacketReader(156) {};
  GameServerPacket156(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentDisplayDialog : public PacketReader {
public:
  GameServerAgentDisplayDialog() : PacketReader(157) {};
  GameServerAgentDisplayDialog(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::u16string field_1;
  std::uint8_t field_2;
  std::u16string field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentAttrUpdateInt : public PacketReader {
public:
  GameServerAgentAttrUpdateInt() : PacketReader(158) {};
  GameServerAgentAttrUpdateInt(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  agent_id field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentAttrUpdateIntTarget : public PacketReader {
public:
  GameServerAgentAttrUpdateIntTarget() : PacketReader(159) {};
  GameServerAgentAttrUpdateIntTarget(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  agent_id field_1;
  agent_id field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentAttrPlayEffect : public PacketReader {
public:
  GameServerAgentAttrPlayEffect() : PacketReader(160) {};
  GameServerAgentAttrPlayEffect(const std::vector<std::uint8_t> &data);
  glm::vec2 field_0;
  std::uint16_t field_1;
  agent_id field_2;
  std::uint16_t field_3;
  std::uint8_t field_4;
  std::uint8_t field_5;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentAttrUpdateFloat : public PacketReader {
public:
  GameServerAgentAttrUpdateFloat() : PacketReader(161) {};
  GameServerAgentAttrUpdateFloat(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  agent_id field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentAttrUpdateFloatTarget : public PacketReader {
public:
  GameServerAgentAttrUpdateFloatTarget() : PacketReader(162) {};
  GameServerAgentAttrUpdateFloatTarget(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  agent_id field_1;
  agent_id field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentProjectileLaunched : public PacketReader {
public:
  GameServerAgentProjectileLaunched() : PacketReader(163) {};
  GameServerAgentProjectileLaunched(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  glm::vec2 field_1;
  std::uint16_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint8_t field_6;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSpeechBubble : public PacketReader {
public:
  GameServerSpeechBubble() : PacketReader(164) {};
  GameServerSpeechBubble(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentUpdateProfession : public PacketReader {
public:
  GameServerAgentUpdateProfession() : PacketReader(165) {};
  GameServerAgentUpdateProfession(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket166 : public PacketReader {
public:
  GameServerPacket166() : PacketReader(166) {};
  GameServerPacket166(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket167 : public PacketReader {
public:
  GameServerPacket167() : PacketReader(167) {};
  GameServerPacket167(const std::vector<std::uint8_t> &data);
  glm::vec2 field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket168 : public PacketReader {
public:
  GameServerPacket168() : PacketReader(168) {};
  GameServerPacket168(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentCreateNPC : public PacketReader {
public:
  GameServerAgentCreateNPC() : PacketReader(169) {};
  GameServerAgentCreateNPC(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket170 : public PacketReader {
public:
  GameServerPacket170() : PacketReader(170) {};
  GameServerPacket170(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket171 : public PacketReader {
public:
  GameServerPacket171() : PacketReader(171) {};
  GameServerPacket171(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket172 : public PacketReader {
public:
  GameServerPacket172() : PacketReader(172) {};
  GameServerPacket172(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerUpdateAgentModel : public PacketReader {
public:
  GameServerUpdateAgentModel() : PacketReader(173) {};
  GameServerUpdateAgentModel(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket174 : public PacketReader {
public:
  GameServerPacket174() : PacketReader(174) {};
  GameServerPacket174(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerUpdateAgentPartysize : public PacketReader {
public:
  GameServerUpdateAgentPartysize() : PacketReader(175) {};
  GameServerUpdateAgentPartysize(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket176 : public PacketReader {
public:
  GameServerPacket176() : PacketReader(176) {};
  GameServerPacket176(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket177 : public PacketReader {
public:
  GameServerPacket177() : PacketReader(177) {};
  GameServerPacket177(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  agent_id field_1;
  std::u16string field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket178 : public PacketReader {
public:
  GameServerPacket178() : PacketReader(178) {};
  GameServerPacket178(const std::vector<std::uint8_t> &data);
  agent_id field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket179 : public PacketReader {
public:
  GameServerPacket179() : PacketReader(179) {};
  GameServerPacket179(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket180 : public PacketReader {
public:
  GameServerPacket180() : PacketReader(180) {};
  GameServerPacket180(const std::vector<std::uint8_t> &data);
  std::vector<std::uint8_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPlayerUnlockedProfession : public PacketReader {
public:
  GameServerPlayerUnlockedProfession() : PacketReader(181) {};
  GameServerPlayerUnlockedProfession(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPlayerUpdateProfession : public PacketReader {
public:
  GameServerPlayerUpdateProfession() : PacketReader(182) {};
  GameServerPlayerUpdateProfession(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket183 : public PacketReader {
public:
  GameServerPacket183() : PacketReader(183) {};
  GameServerPacket183(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerMissionInfoboxAdd : public PacketReader {
public:
  GameServerMissionInfoboxAdd() : PacketReader(184) {};
  GameServerMissionInfoboxAdd(const std::vector<std::uint8_t> &data);
  std::u16string field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerMissionStreamStart : public PacketReader {
public:
  GameServerMissionStreamStart() : PacketReader(185) {};
  GameServerMissionStreamStart(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerMissionObjectiveAdd : public PacketReader {
public:
  GameServerMissionObjectiveAdd() : PacketReader(186) {};
  GameServerMissionObjectiveAdd(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::u16string field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerMissionObjectiveComplete : public PacketReader {
public:
  GameServerMissionObjectiveComplete() : PacketReader(187) {};
  GameServerMissionObjectiveComplete(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerMissionObjectiveUpdateString : public PacketReader {
public:
  GameServerMissionObjectiveUpdateString() : PacketReader(188) {};
  GameServerMissionObjectiveUpdateString(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket189 : public PacketReader {
public:
  GameServerPacket189() : PacketReader(189) {};
  GameServerPacket189(const std::vector<std::uint8_t> &data);
  agent_id field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket190 : public PacketReader {
public:
  GameServerPacket190() : PacketReader(190) {};
  GameServerPacket190(const std::vector<std::uint8_t> &data);
  std::vector<std::uint32_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket191 : public PacketReader {
public:
  GameServerPacket191() : PacketReader(191) {};
  GameServerPacket191(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::u16string field_3;
  std::u16string field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket192 : public PacketReader {
public:
  GameServerPacket192() : PacketReader(192) {};
  GameServerPacket192(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket193 : public PacketReader {
public:
  GameServerPacket193() : PacketReader(193) {};
  GameServerPacket193(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerWindowMerchant : public PacketReader {
public:
  GameServerWindowMerchant() : PacketReader(194) {};
  GameServerWindowMerchant(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerWindowOwner : public PacketReader {
public:
  GameServerWindowOwner() : PacketReader(195) {};
  GameServerWindowOwner(const std::vector<std::uint8_t> &data);
  agent_id field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket196 : public PacketReader {
public:
  GameServerPacket196() : PacketReader(196) {};
  GameServerPacket196(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTransactionReject : public PacketReader {
public:
  GameServerTransactionReject() : PacketReader(197) {};
  GameServerTransactionReject(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket198 : public PacketReader {
public:
  GameServerPacket198() : PacketReader(198) {};
  GameServerPacket198(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;
  std::vector<std::uint32_t> field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket199 : public PacketReader {
public:
  GameServerPacket199() : PacketReader(199) {};
  GameServerPacket199(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket200 : public PacketReader {
public:
  GameServerPacket200() : PacketReader(200) {};
  GameServerPacket200(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket201 : public PacketReader {
public:
  GameServerPacket201() : PacketReader(201) {};
  GameServerPacket201(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket202 : public PacketReader {
public:
  GameServerPacket202() : PacketReader(202) {};
  GameServerPacket202(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTransactionDone : public PacketReader {
public:
  GameServerTransactionDone() : PacketReader(203) {};
  GameServerTransactionDone(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket204 : public PacketReader {
public:
  GameServerPacket204() : PacketReader(204) {};
  GameServerPacket204(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket205 : public PacketReader {
public:
  GameServerPacket205() : PacketReader(205) {};
  GameServerPacket205(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket206 : public PacketReader {
public:
  GameServerPacket206() : PacketReader(206) {};
  GameServerPacket206(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket207 : public PacketReader {
public:
  GameServerPacket207() : PacketReader(207) {};
  GameServerPacket207(const std::vector<std::uint8_t> &data);
  agent_id field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket208 : public PacketReader {
public:
  GameServerPacket208() : PacketReader(208) {};
  GameServerPacket208(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket209 : public PacketReader {
public:
  GameServerPacket209() : PacketReader(209) {};
  GameServerPacket209(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket210 : public PacketReader {
public:
  GameServerPacket210() : PacketReader(210) {};
  GameServerPacket210(const std::vector<std::uint8_t> &data);
  std::vector<std::uint32_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket211 : public PacketReader {
public:
  GameServerPacket211() : PacketReader(211) {};
  GameServerPacket211(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket212 : public PacketReader {
public:
  GameServerPacket212() : PacketReader(212) {};
  GameServerPacket212(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket213 : public PacketReader {
public:
  GameServerPacket213() : PacketReader(213) {};
  GameServerPacket213(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket214 : public PacketReader {
public:
  GameServerPacket214() : PacketReader(214) {};
  GameServerPacket214(const std::vector<std::uint8_t> &data);
  std::vector<std::uint32_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket215 : public PacketReader {
public:
  GameServerPacket215() : PacketReader(215) {};
  GameServerPacket215(const std::vector<std::uint8_t> &data);
  std::vector<std::uint32_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSkillbarUpdateSkill : public PacketReader {
public:
  GameServerSkillbarUpdateSkill() : PacketReader(216) {};
  GameServerSkillbarUpdateSkill(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;
  std::uint16_t field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSkillbarUpdate : public PacketReader {
public:
  GameServerSkillbarUpdate() : PacketReader(217) {};
  GameServerSkillbarUpdate(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::vector<std::uint32_t> field_1;
  std::vector<std::uint32_t> field_2;
  std::uint8_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSkillsUnlocked : public PacketReader {
public:
  GameServerSkillsUnlocked() : PacketReader(218) {};
  GameServerSkillsUnlocked(const std::vector<std::uint8_t> &data);
  std::vector<std::uint32_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSkillAddToWindowCount : public PacketReader {
public:
  GameServerSkillAddToWindowCount() : PacketReader(219) {};
  GameServerSkillAddToWindowCount(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket220 : public PacketReader {
public:
  GameServerPacket220() : PacketReader(220) {};
  GameServerPacket220(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket221 : public PacketReader {
public:
  GameServerPacket221() : PacketReader(221) {};
  GameServerPacket221(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket222 : public PacketReader {
public:
  GameServerPacket222() : PacketReader(222) {};
  GameServerPacket222(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSkillAddToWindowsData : public PacketReader {
public:
  GameServerSkillAddToWindowsData() : PacketReader(223) {};
  GameServerSkillAddToWindowsData(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::vector<std::uint32_t> field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSkillAddToWindowsEnd : public PacketReader {
public:
  GameServerSkillAddToWindowsEnd() : PacketReader(224) {};
  GameServerSkillAddToWindowsEnd(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSkillInterupted : public PacketReader {
public:
  GameServerSkillInterupted() : PacketReader(225) {};
  GameServerSkillInterupted(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSkillActivatedOrCanceled : public PacketReader {
public:
  GameServerSkillActivatedOrCanceled() : PacketReader(226) {};
  GameServerSkillActivatedOrCanceled(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSkillActivate : public PacketReader {
public:
  GameServerSkillActivate() : PacketReader(227) {};
  GameServerSkillActivate(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSkillRecharge : public PacketReader {
public:
  GameServerSkillRecharge() : PacketReader(228) {};
  GameServerSkillRecharge(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSkillRecharged : public PacketReader {
public:
  GameServerSkillRecharged() : PacketReader(229) {};
  GameServerSkillRecharged(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket230 : public PacketReader {
public:
  GameServerPacket230() : PacketReader(230) {};
  GameServerPacket230(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket231 : public PacketReader {
public:
  GameServerPacket231() : PacketReader(231) {};
  GameServerPacket231(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPlayerAttrSet : public PacketReader {
public:
  GameServerPlayerAttrSet() : PacketReader(232) {};
  GameServerPlayerAttrSet(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint32_t field_6;
  std::uint32_t field_7;
  std::uint32_t field_8;
  std::uint32_t field_9;
  std::uint32_t field_10;
  std::uint32_t field_11;
  std::uint32_t field_12;
  std::uint32_t field_13;
  std::uint32_t field_14;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPlayerAttrMaxKurzick : public PacketReader {
public:
  GameServerPlayerAttrMaxKurzick() : PacketReader(233) {};
  GameServerPlayerAttrMaxKurzick(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPlayerAttrMaxLuxon : public PacketReader {
public:
  GameServerPlayerAttrMaxLuxon() : PacketReader(234) {};
  GameServerPlayerAttrMaxLuxon(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPlayerAttrMaxBalthazar : public PacketReader {
public:
  GameServerPlayerAttrMaxBalthazar() : PacketReader(235) {};
  GameServerPlayerAttrMaxBalthazar(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPlayerAttrMaxImperial : public PacketReader {
public:
  GameServerPlayerAttrMaxImperial() : PacketReader(236) {};
  GameServerPlayerAttrMaxImperial(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPlayerAttrUpdate : public PacketReader {
public:
  GameServerPlayerAttrUpdate() : PacketReader(237) {};
  GameServerPlayerAttrUpdate(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket238 : public PacketReader {
public:
  GameServerPacket238() : PacketReader(238) {};
  GameServerPacket238(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentInitialEffects : public PacketReader {
public:
  GameServerAgentInitialEffects() : PacketReader(239) {};
  GameServerAgentInitialEffects(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerAgentUpdateEffects : public PacketReader {
public:
  GameServerAgentUpdateEffects() : PacketReader(240) {};
  GameServerAgentUpdateEffects(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInstanceLoaded : public PacketReader {
public:
  GameServerInstanceLoaded() : PacketReader(241) {};
  GameServerInstanceLoaded(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTitleRankData : public PacketReader {
public:
  GameServerTitleRankData() : PacketReader(242) {};
  GameServerTitleRankData(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::u16string field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTitleRankDisplay : public PacketReader {
public:
  GameServerTitleRankDisplay() : PacketReader(243) {};
  GameServerTitleRankDisplay(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket244 : public PacketReader {
public:
  GameServerPacket244() : PacketReader(244) {};
  GameServerPacket244(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTitleTrackInfo : public PacketReader {
public:
  GameServerTitleTrackInfo() : PacketReader(245) {};
  GameServerTitleTrackInfo(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint32_t field_6;
  std::uint32_t field_7;
  std::uint32_t field_8;
  std::u16string field_9;
  std::u16string field_10;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemPriceQuote : public PacketReader {
public:
  GameServerItemPriceQuote() : PacketReader(246) {};
  GameServerItemPriceQuote(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket247 : public PacketReader {
public:
  GameServerPacket247() : PacketReader(247) {};
  GameServerPacket247(const std::vector<std::uint8_t> &data);
  agent_id field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemPrices : public PacketReader {
public:
  GameServerItemPrices() : PacketReader(248) {};
  GameServerItemPrices(const std::vector<std::uint8_t> &data);
  std::vector<std::uint32_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerVanquishProgress : public PacketReader {
public:
  GameServerVanquishProgress() : PacketReader(249) {};
  GameServerVanquishProgress(const std::vector<std::uint8_t> &data);
  std::vector<std::uint32_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerVanquishComplete : public PacketReader {
public:
  GameServerVanquishComplete() : PacketReader(250) {};
  GameServerVanquishComplete(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket251 : public PacketReader {
public:
  GameServerPacket251() : PacketReader(251) {};
  GameServerPacket251(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket252 : public PacketReader {
public:
  GameServerPacket252() : PacketReader(252) {};
  GameServerPacket252(const std::vector<std::uint8_t> &data);
  std::u16string field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerCinematicSkipEveryone : public PacketReader {
public:
  GameServerCinematicSkipEveryone() : PacketReader(253) {};
  GameServerCinematicSkipEveryone(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerCinematicSkipCount : public PacketReader {
public:
  GameServerCinematicSkipCount() : PacketReader(254) {};
  GameServerCinematicSkipCount(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerCinematicStart : public PacketReader {
public:
  GameServerCinematicStart() : PacketReader(255) {};
  GameServerCinematicStart(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket256 : public PacketReader {
public:
  GameServerPacket256() : PacketReader(256) {};
  GameServerPacket256(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerCinematicText : public PacketReader {
public:
  GameServerCinematicText() : PacketReader(257) {};
  GameServerCinematicText(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint16_t field_1;
  std::u16string field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerCinematicDataEnd : public PacketReader {
public:
  GameServerCinematicDataEnd() : PacketReader(258) {};
  GameServerCinematicDataEnd(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerCinematicData : public PacketReader {
public:
  GameServerCinematicData() : PacketReader(259) {};
  GameServerCinematicData(const std::vector<std::uint8_t> &data);
  std::vector<std::uint8_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerCinematicEnd : public PacketReader {
public:
  GameServerCinematicEnd() : PacketReader(260) {};
  GameServerCinematicEnd(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket261 : public PacketReader {
public:
  GameServerPacket261() : PacketReader(261) {};
  GameServerPacket261(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket262 : public PacketReader {
public:
  GameServerPacket262() : PacketReader(262) {};
  GameServerPacket262(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint8_t field_3;
  std::u16string field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket263 : public PacketReader {
public:
  GameServerPacket263() : PacketReader(263) {};
  GameServerPacket263(const std::vector<std::uint8_t> &data);
  agent_id field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket264 : public PacketReader {
public:
  GameServerPacket264() : PacketReader(264) {};
  GameServerPacket264(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSignpostButton : public PacketReader {
public:
  GameServerSignpostButton() : PacketReader(265) {};
  GameServerSignpostButton(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::u16string field_1;
  std::uint32_t field_2;
  std::uint16_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSignpostBody : public PacketReader {
public:
  GameServerSignpostBody() : PacketReader(266) {};
  GameServerSignpostBody(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSignpostSender : public PacketReader {
public:
  GameServerSignpostSender() : PacketReader(267) {};
  GameServerSignpostSender(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket268 : public PacketReader {
public:
  GameServerPacket268() : PacketReader(268) {};
  GameServerPacket268(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerManipulateMapObject : public PacketReader {
public:
  GameServerManipulateMapObject() : PacketReader(269) {};
  GameServerManipulateMapObject(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket270 : public PacketReader {
public:
  GameServerPacket270() : PacketReader(270) {};
  GameServerPacket270(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket271 : public PacketReader {
public:
  GameServerPacket271() : PacketReader(271) {};
  GameServerPacket271(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerManipulateMapObject2 : public PacketReader {
public:
  GameServerManipulateMapObject2() : PacketReader(272) {};
  GameServerManipulateMapObject2(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket273 : public PacketReader {
public:
  GameServerPacket273() : PacketReader(273) {};
  GameServerPacket273(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket274 : public PacketReader {
public:
  GameServerPacket274() : PacketReader(274) {};
  GameServerPacket274(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket275 : public PacketReader {
public:
  GameServerPacket275() : PacketReader(275) {};
  GameServerPacket275(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket276 : public PacketReader {
public:
  GameServerPacket276() : PacketReader(276) {};
  GameServerPacket276(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket277 : public PacketReader {
public:
  GameServerPacket277() : PacketReader(277) {};
  GameServerPacket277(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::array<std::uint8_t, 16> field_1;
  std::uint8_t field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket278 : public PacketReader {
public:
  GameServerPacket278() : PacketReader(278) {};
  GameServerPacket278(const std::vector<std::uint8_t> &data);
  std::array<std::uint8_t, 16> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGuildPlayerRole : public PacketReader {
public:
  GameServerGuildPlayerRole() : PacketReader(279) {};
  GameServerGuildPlayerRole(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::array<std::uint8_t, 16> field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket280 : public PacketReader {
public:
  GameServerPacket280() : PacketReader(280) {};
  GameServerPacket280(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTownAllianceObject : public PacketReader {
public:
  GameServerTownAllianceObject() : PacketReader(281) {};
  GameServerTownAllianceObject(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;
  std::uint32_t field_3;
  std::u16string field_4;
  std::u16string field_5;
  std::uint8_t field_6;
  std::uint8_t field_7;
  std::uint8_t field_8;
  std::uint8_t field_9;
  std::uint8_t field_10;
  std::uint16_t field_11;
  std::uint8_t field_12;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket282 : public PacketReader {
public:
  GameServerPacket282() : PacketReader(282) {};
  GameServerPacket282(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket283 : public PacketReader {
public:
  GameServerPacket283() : PacketReader(283) {};
  GameServerPacket283(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket284 : public PacketReader {
public:
  GameServerPacket284() : PacketReader(284) {};
  GameServerPacket284(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket285 : public PacketReader {
public:
  GameServerPacket285() : PacketReader(285) {};
  GameServerPacket285(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket286 : public PacketReader {
public:
  GameServerPacket286() : PacketReader(286) {};
  GameServerPacket286(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGuildAllianceInfo : public PacketReader {
public:
  GameServerGuildAllianceInfo() : PacketReader(287) {};
  GameServerGuildAllianceInfo(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::array<std::uint8_t, 16> field_1;
  std::u16string field_2;
  std::u16string field_3;
  std::uint8_t field_4;
  std::uint8_t field_5;
  std::uint8_t field_6;
  std::uint8_t field_7;
  std::uint8_t field_8;
  std::uint8_t field_9;
  std::uint16_t field_10;
  std::uint8_t field_11;
  std::uint8_t field_12;
  std::uint32_t field_13;
  std::uint8_t field_14;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGuildGeneralInfo : public PacketReader {
public:
  GameServerGuildGeneralInfo() : PacketReader(288) {};
  GameServerGuildGeneralInfo(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::array<std::uint8_t, 16> field_1;
  std::u16string field_2;
  std::u16string field_3;
  std::uint8_t field_4;
  std::uint8_t field_5;
  std::uint8_t field_6;
  std::uint8_t field_7;
  std::uint8_t field_8;
  std::uint8_t field_9;
  std::uint8_t field_10;
  std::uint16_t field_11;
  std::uint8_t field_12;
  std::uint8_t field_13;
  std::uint32_t field_14;
  std::uint32_t field_15;
  std::uint32_t field_16;
  std::uint32_t field_17;
  std::uint8_t field_18;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGuildChangeFaction : public PacketReader {
public:
  GameServerGuildChangeFaction() : PacketReader(289) {};
  GameServerGuildChangeFaction(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGuildInviteReceived : public PacketReader {
public:
  GameServerGuildInviteReceived() : PacketReader(290) {};
  GameServerGuildInviteReceived(const std::vector<std::uint8_t> &data);
  std::array<std::uint8_t, 16> field_0;
  std::u16string field_1;
  std::u16string field_2;
  std::u16string field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint8_t field_6;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket291 : public PacketReader {
public:
  GameServerPacket291() : PacketReader(291) {};
  GameServerPacket291(const std::vector<std::uint8_t> &data);
  std::array<std::uint8_t, 16> field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket292 : public PacketReader {
public:
  GameServerPacket292() : PacketReader(292) {};
  GameServerPacket292(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket293 : public PacketReader {
public:
  GameServerPacket293() : PacketReader(293) {};
  GameServerPacket293(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGuildPlayerInfo : public PacketReader {
public:
  GameServerGuildPlayerInfo() : PacketReader(294) {};
  GameServerGuildPlayerInfo(const std::vector<std::uint8_t> &data);
  std::u16string field_0;
  std::u16string field_1;
  std::u16string field_2;
  std::u16string field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint32_t field_6;
  std::uint32_t field_7;
  std::uint8_t field_8;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGuildPlayerRemove : public PacketReader {
public:
  GameServerGuildPlayerRemove() : PacketReader(295) {};
  GameServerGuildPlayerRemove(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket296 : public PacketReader {
public:
  GameServerPacket296() : PacketReader(296) {};
  GameServerPacket296(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGuildPlayerChangeComplete : public PacketReader {
public:
  GameServerGuildPlayerChangeComplete() : PacketReader(297) {};
  GameServerGuildPlayerChangeComplete(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGuildChangePlayerContext : public PacketReader {
public:
  GameServerGuildChangePlayerContext() : PacketReader(298) {};
  GameServerGuildChangePlayerContext(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGuildChangePlayerStatus : public PacketReader {
public:
  GameServerGuildChangePlayerStatus() : PacketReader(299) {};
  GameServerGuildChangePlayerStatus(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGuildChangePlayerType : public PacketReader {
public:
  GameServerGuildChangePlayerType() : PacketReader(300) {};
  GameServerGuildChangePlayerType(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket301 : public PacketReader {
public:
  GameServerPacket301() : PacketReader(301) {};
  GameServerPacket301(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket302 : public PacketReader {
public:
  GameServerPacket302() : PacketReader(302) {};
  GameServerPacket302(const std::vector<std::uint8_t> &data);
  std::u16string field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket303 : public PacketReader {
public:
  GameServerPacket303() : PacketReader(303) {};
  GameServerPacket303(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket304 : public PacketReader {
public:
  GameServerPacket304() : PacketReader(304) {};
  GameServerPacket304(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket305 : public PacketReader {
public:
  GameServerPacket305() : PacketReader(305) {};
  GameServerPacket305(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket306 : public PacketReader {
public:
  GameServerPacket306() : PacketReader(306) {};
  GameServerPacket306(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket307 : public PacketReader {
public:
  GameServerPacket307() : PacketReader(307) {};
  GameServerPacket307(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket308 : public PacketReader {
public:
  GameServerPacket308() : PacketReader(308) {};
  GameServerPacket308(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket309 : public PacketReader {
public:
  GameServerPacket309() : PacketReader(309) {};
  GameServerPacket309(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket310 : public PacketReader {
public:
  GameServerPacket310() : PacketReader(310) {};
  GameServerPacket310(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket311 : public PacketReader {
public:
  GameServerPacket311() : PacketReader(311) {};
  GameServerPacket311(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;
  std::u16string field_2;
  std::u16string field_3;
  std::u16string field_4;
  std::u16string field_5;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInventoryItemQuantity : public PacketReader {
public:
  GameServerInventoryItemQuantity() : PacketReader(312) {};
  GameServerInventoryItemQuantity(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemUpdateName : public PacketReader {
public:
  GameServerItemUpdateName() : PacketReader(313) {};
  GameServerItemUpdateName(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket314 : public PacketReader {
public:
  GameServerPacket314() : PacketReader(314) {};
  GameServerPacket314(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket315 : public PacketReader {
public:
  GameServerPacket315() : PacketReader(315) {};
  GameServerPacket315(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket316 : public PacketReader {
public:
  GameServerPacket316() : PacketReader(316) {};
  GameServerPacket316(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint16_t field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInventoryItemLocation : public PacketReader {
public:
  GameServerInventoryItemLocation() : PacketReader(317) {};
  GameServerInventoryItemLocation(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;
  std::uint16_t field_2;
  std::uint8_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInventoryCreateBag : public PacketReader {
public:
  GameServerInventoryCreateBag() : PacketReader(318) {};
  GameServerInventoryCreateBag(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;
  std::uint16_t field_3;
  std::uint8_t field_4;
  std::uint32_t field_5;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGoldCharacterAdd : public PacketReader {
public:
  GameServerGoldCharacterAdd() : PacketReader(319) {};
  GameServerGoldCharacterAdd(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGoldStorageAdd : public PacketReader {
public:
  GameServerGoldStorageAdd() : PacketReader(320) {};
  GameServerGoldStorageAdd(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket321 : public PacketReader {
public:
  GameServerPacket321() : PacketReader(321) {};
  GameServerPacket321(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket322 : public PacketReader {
public:
  GameServerPacket322() : PacketReader(322) {};
  GameServerPacket322(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemStreamCreate : public PacketReader {
public:
  GameServerItemStreamCreate() : PacketReader(323) {};
  GameServerItemStreamCreate(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemStreamDestroy : public PacketReader {
public:
  GameServerItemStreamDestroy() : PacketReader(324) {};
  GameServerItemStreamDestroy(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket325 : public PacketReader {
public:
  GameServerPacket325() : PacketReader(325) {};
  GameServerPacket325(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint16_t field_2;
  std::uint8_t field_3;
  std::uint32_t field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemWeaponSet : public PacketReader {
public:
  GameServerItemWeaponSet() : PacketReader(326) {};
  GameServerItemWeaponSet(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemSetActiveWeaponSet : public PacketReader {
public:
  GameServerItemSetActiveWeaponSet() : PacketReader(327) {};
  GameServerItemSetActiveWeaponSet(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket328 : public PacketReader {
public:
  GameServerPacket328() : PacketReader(328) {};
  GameServerPacket328(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket329 : public PacketReader {
public:
  GameServerPacket329() : PacketReader(329) {};
  GameServerPacket329(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemChangeLocation : public PacketReader {
public:
  GameServerItemChangeLocation() : PacketReader(330) {};
  GameServerItemChangeLocation(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;
  std::uint16_t field_2;
  std::uint8_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket331 : public PacketReader {
public:
  GameServerPacket331() : PacketReader(331) {};
  GameServerPacket331(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemRemove : public PacketReader {
public:
  GameServerItemRemove() : PacketReader(332) {};
  GameServerItemRemove(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket333 : public PacketReader {
public:
  GameServerPacket333() : PacketReader(333) {};
  GameServerPacket333(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGoldCharacterRemove : public PacketReader {
public:
  GameServerGoldCharacterRemove() : PacketReader(334) {};
  GameServerGoldCharacterRemove(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerGoldStorageRemove : public PacketReader {
public:
  GameServerGoldStorageRemove() : PacketReader(335) {};
  GameServerGoldStorageRemove(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket336 : public PacketReader {
public:
  GameServerPacket336() : PacketReader(336) {};
  GameServerPacket336(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket337 : public PacketReader {
public:
  GameServerPacket337() : PacketReader(337) {};
  GameServerPacket337(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket338 : public PacketReader {
public:
  GameServerPacket338() : PacketReader(338) {};
  GameServerPacket338(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;
  std::uint16_t field_2;
  std::uint8_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTomeShowSkills : public PacketReader {
public:
  GameServerTomeShowSkills() : PacketReader(339) {};
  GameServerTomeShowSkills(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket340 : public PacketReader {
public:
  GameServerPacket340() : PacketReader(340) {};
  GameServerPacket340(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket341 : public PacketReader {
public:
  GameServerPacket341() : PacketReader(341) {};
  GameServerPacket341(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket342 : public PacketReader {
public:
  GameServerPacket342() : PacketReader(342) {};
  GameServerPacket342(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket343 : public PacketReader {
public:
  GameServerPacket343() : PacketReader(343) {};
  GameServerPacket343(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket344 : public PacketReader {
public:
  GameServerPacket344() : PacketReader(344) {};
  GameServerPacket344(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket345 : public PacketReader {
public:
  GameServerPacket345() : PacketReader(345) {};
  GameServerPacket345(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket346 : public PacketReader {
public:
  GameServerPacket346() : PacketReader(346) {};
  GameServerPacket346(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket347 : public PacketReader {
public:
  GameServerPacket347() : PacketReader(347) {};
  GameServerPacket347(const std::vector<std::uint8_t> &data);
  struct some_struct {
    std::uint8_t field_0;
    std::uint16_t field_1;
    std::uint8_t field_2;
    std::uint16_t field_3;
    std::uint16_t field_4;
    std::uint16_t field_5;
    std::uint16_t field_6;
  };

  std::uint16_t field_0;
  std::vector<some_struct> field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  bool read_struct(std::vector<std::uint8_t>::const_iterator &it,
                   const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket348 : public PacketReader {
public:
  GameServerPacket348() : PacketReader(348) {};
  GameServerPacket348(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket349 : public PacketReader {
public:
  GameServerPacket349() : PacketReader(349) {};
  GameServerPacket349(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;
  std::uint16_t field_4;
  std::uint16_t field_5;
  std::uint8_t field_6;
  std::uint32_t field_7;
  std::uint32_t field_8;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket350 : public PacketReader {
public:
  GameServerPacket350() : PacketReader(350) {};
  GameServerPacket350(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;
  std::uint16_t field_4;
  std::uint16_t field_5;
  std::uint8_t field_6;
  std::uint32_t field_7;
  std::uint32_t field_8;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket351 : public PacketReader {
public:
  GameServerPacket351() : PacketReader(351) {};
  GameServerPacket351(const std::vector<std::uint8_t> &data);
  struct some_struct {
    std::uint32_t field_0;
  };

  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::u16string field_3;
  std::vector<some_struct> field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  bool read_struct(std::vector<std::uint8_t>::const_iterator &it,
                   const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemGeneralInfo : public PacketReader {
public:
  GameServerItemGeneralInfo() : PacketReader(352) {};
  GameServerItemGeneralInfo(const std::vector<std::uint8_t> &data);
  struct some_struct {
    std::uint32_t field_0;
  };

  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;
  std::uint16_t field_4;
  std::uint16_t field_5;
  std::uint8_t field_6;
  std::uint32_t field_7;
  std::uint32_t field_8;
  std::uint32_t field_9;
  std::uint32_t field_10;
  std::u16string field_11;
  std::vector<some_struct> field_12;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  bool read_struct(std::vector<std::uint8_t>::const_iterator &it,
                   const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket353 : public PacketReader {
public:
  GameServerPacket353() : PacketReader(353) {};
  GameServerPacket353(const std::vector<std::uint8_t> &data);
  struct some_struct {
    std::uint32_t field_0;
  };

  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;
  std::uint16_t field_4;
  std::uint16_t field_5;
  std::uint8_t field_6;
  std::uint32_t field_7;
  std::uint32_t field_8;
  std::uint32_t field_9;
  std::uint32_t field_10;
  std::u16string field_11;
  std::vector<some_struct> field_12;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  bool read_struct(std::vector<std::uint8_t>::const_iterator &it,
                   const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemSalvageSessionStart : public PacketReader {
public:
  GameServerItemSalvageSessionStart() : PacketReader(354) {};
  GameServerItemSalvageSessionStart(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;
  std::vector<std::uint32_t> field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemSalvageSessionCancel : public PacketReader {
public:
  GameServerItemSalvageSessionCancel() : PacketReader(355) {};
  GameServerItemSalvageSessionCancel(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemSalvageSessionDone : public PacketReader {
public:
  GameServerItemSalvageSessionDone() : PacketReader(356) {};
  GameServerItemSalvageSessionDone(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemSalvageSessionSuccess : public PacketReader {
public:
  GameServerItemSalvageSessionSuccess() : PacketReader(357) {};
  GameServerItemSalvageSessionSuccess(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerItemSalvageSessionItemKept : public PacketReader {
public:
  GameServerItemSalvageSessionItemKept() : PacketReader(358) {};
  GameServerItemSalvageSessionItemKept(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket359 : public PacketReader {
public:
  GameServerPacket359() : PacketReader(359) {};
  GameServerPacket359(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket360 : public PacketReader {
public:
  GameServerPacket360() : PacketReader(360) {};
  GameServerPacket360(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket361 : public PacketReader {
public:
  GameServerPacket361() : PacketReader(361) {};
  GameServerPacket361(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;
  std::vector<std::uint32_t> field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket362 : public PacketReader {
public:
  GameServerPacket362() : PacketReader(362) {};
  GameServerPacket362(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket363 : public PacketReader {
public:
  GameServerPacket363() : PacketReader(363) {};
  GameServerPacket363(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket364 : public PacketReader {
public:
  GameServerPacket364() : PacketReader(364) {};
  GameServerPacket364(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket365 : public PacketReader {
public:
  GameServerPacket365() : PacketReader(365) {};
  GameServerPacket365(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket366 : public PacketReader {
public:
  GameServerPacket366() : PacketReader(366) {};
  GameServerPacket366(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket367 : public PacketReader {
public:
  GameServerPacket367() : PacketReader(367) {};
  GameServerPacket367(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket368 : public PacketReader {
public:
  GameServerPacket368() : PacketReader(368) {};
  GameServerPacket368(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint32_t field_6;
  std::uint32_t field_7;
  std::uint8_t field_8;
  std::uint8_t field_9;
  std::uint8_t field_10;
  std::uint8_t field_11;
  std::uint8_t field_12;
  std::uint16_t field_13;
  std::uint16_t field_14;
  std::uint16_t field_15;
  std::uint16_t field_16;
  std::uint16_t field_17;
  std::uint32_t field_18;
  std::uint8_t field_19;
  std::uint8_t field_20;
  std::uint32_t field_21;
  std::uint8_t field_22;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket369 : public PacketReader {
public:
  GameServerPacket369() : PacketReader(369) {};
  GameServerPacket369(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket370 : public PacketReader {
public:
  GameServerPacket370() : PacketReader(370) {};
  GameServerPacket370(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket371 : public PacketReader {
public:
  GameServerPacket371() : PacketReader(371) {};
  GameServerPacket371(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint32_t field_6;
  std::uint32_t field_7;
  std::uint8_t field_8;
  std::uint8_t field_9;
  std::uint8_t field_10;
  std::uint8_t field_11;
  std::uint8_t field_12;
  std::uint16_t field_13;
  std::uint16_t field_14;
  std::uint16_t field_15;
  std::uint16_t field_16;
  std::uint16_t field_17;
  std::uint32_t field_18;
  std::uint8_t field_19;
  std::uint8_t field_20;
  std::uint32_t field_21;
  std::uint8_t field_22;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket372 : public PacketReader {
public:
  GameServerPacket372() : PacketReader(372) {};
  GameServerPacket372(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint16_t field_1;
  std::uint8_t field_2;
  std::u16string field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket373 : public PacketReader {
public:
  GameServerPacket373() : PacketReader(373) {};
  GameServerPacket373(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket374 : public PacketReader {
public:
  GameServerPacket374() : PacketReader(374) {};
  GameServerPacket374(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint16_t field_1;
  std::uint8_t field_2;
  std::u16string field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket375 : public PacketReader {
public:
  GameServerPacket375() : PacketReader(375) {};
  GameServerPacket375(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::u16string field_1;
  std::u16string field_2;
  std::uint16_t field_3;
  std::uint8_t field_4;
  std::uint8_t field_5;
  std::uint8_t field_6;
  std::uint8_t field_7;
  std::uint16_t field_8;
  std::uint16_t field_9;
  std::uint8_t field_10;
  std::uint8_t field_11;
  std::uint8_t field_12;
  std::uint8_t field_13;
  std::uint16_t field_14;
  std::uint16_t field_15;
  std::uint32_t field_16;
  std::uint32_t field_17;
  std::uint32_t field_18;
  std::uint8_t field_19;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket376 : public PacketReader {
public:
  GameServerPacket376() : PacketReader(376) {};
  GameServerPacket376(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint16_t field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket377 : public PacketReader {
public:
  GameServerPacket377() : PacketReader(377) {};
  GameServerPacket377(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInstanceShowWin : public PacketReader {
public:
  GameServerInstanceShowWin() : PacketReader(378) {};
  GameServerInstanceShowWin(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInstanceLoadHead : public PacketReader {
public:
  GameServerInstanceLoadHead() : PacketReader(379) {};
  GameServerInstanceLoadHead(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInstanceLoadPlayerName : public PacketReader {
public:
  GameServerInstanceLoadPlayerName() : PacketReader(380) {};
  GameServerInstanceLoadPlayerName(const std::vector<std::uint8_t> &data);
  std::u16string player_name;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInstanceCountdownStop : public PacketReader {
public:
  GameServerInstanceCountdownStop() : PacketReader(381) {};
  GameServerInstanceCountdownStop(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket382 : public PacketReader {
public:
  GameServerPacket382() : PacketReader(382) {};
  GameServerPacket382(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInstanceCountdown : public PacketReader {
public:
  GameServerInstanceCountdown() : PacketReader(383) {};
  GameServerInstanceCountdown(const std::vector<std::uint8_t> &data);
  std::u16string field_0;
  std::uint8_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket384 : public PacketReader {
public:
  GameServerPacket384() : PacketReader(384) {};
  GameServerPacket384(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket385 : public PacketReader {
public:
  GameServerPacket385() : PacketReader(385) {};
  GameServerPacket385(const std::vector<std::uint8_t> &data);
  std::u16string field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket386 : public PacketReader {
public:
  GameServerPacket386() : PacketReader(386) {};
  GameServerPacket386(const std::vector<std::uint8_t> &data);
  std::u16string field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket387 : public PacketReader {
public:
  GameServerPacket387() : PacketReader(387) {};
  GameServerPacket387(const std::vector<std::uint8_t> &data);
  std::u16string field_0;
  std::u16string field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket388 : public PacketReader {
public:
  GameServerPacket388() : PacketReader(388) {};
  GameServerPacket388(const std::vector<std::uint8_t> &data);
  std::u16string field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerSentAfterInstanceLoadHead : public PacketReader {
public:
  GameServerSentAfterInstanceLoadHead() : PacketReader(389) {};
  GameServerSentAfterInstanceLoadHead(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket390 : public PacketReader {
public:
  GameServerPacket390() : PacketReader(390) {};
  GameServerPacket390(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket391 : public PacketReader {
public:
  GameServerPacket391() : PacketReader(391) {};
  GameServerPacket391(const std::vector<std::uint8_t> &data);
  std::array<std::uint8_t, 16> field_0;
  std::u16string field_1;
  std::uint16_t field_2;
  std::vector<std::uint8_t> field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket392 : public PacketReader {
public:
  GameServerPacket392() : PacketReader(392) {};
  GameServerPacket392(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket393 : public PacketReader {
public:
  GameServerPacket393() : PacketReader(393) {};
  GameServerPacket393(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket394 : public PacketReader {
public:
  GameServerPacket394() : PacketReader(394) {};
  GameServerPacket394(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket395 : public PacketReader {
public:
  GameServerPacket395() : PacketReader(395) {};
  GameServerPacket395(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket396 : public PacketReader {
public:
  GameServerPacket396() : PacketReader(396) {};
  GameServerPacket396(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInstanceLoadFinish : public PacketReader {
public:
  GameServerInstanceLoadFinish() : PacketReader(397) {};
  GameServerInstanceLoadFinish(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket398 : public PacketReader {
public:
  GameServerPacket398() : PacketReader(398) {};
  GameServerPacket398(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerJumboMessage : public PacketReader {
public:
  GameServerJumboMessage() : PacketReader(399) {};
  GameServerJumboMessage(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket400 : public PacketReader {
public:
  GameServerPacket400() : PacketReader(400) {};
  GameServerPacket400(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket401 : public PacketReader {
public:
  GameServerPacket401() : PacketReader(401) {};
  GameServerPacket401(const std::vector<std::uint8_t> &data);
  struct some_struct {
    std::u16string field_0;
  };

  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;
  std::uint32_t field_4;
  std::u16string field_5;
  std::vector<some_struct> field_6;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  bool read_struct(std::vector<std::uint8_t>::const_iterator &it,
                   const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket402 : public PacketReader {
public:
  GameServerPacket402() : PacketReader(402) {};
  GameServerPacket402(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket403 : public PacketReader {
public:
  GameServerPacket403() : PacketReader(403) {};
  GameServerPacket403(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInstanceLoadSpawnPoint : public PacketReader {
public:
  GameServerInstanceLoadSpawnPoint() : PacketReader(404) {};
  GameServerInstanceLoadSpawnPoint(const std::vector<std::uint8_t> &data);
  std::uint32_t map_file_id;
  glm::vec2 spawn_position;
  std::uint16_t plane_id;
  std::uint8_t unk0;
  std::uint8_t is_cinematic;
  std::array<std::uint8_t, 8> unk1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket405 : public PacketReader {
public:
  GameServerPacket405() : PacketReader(405) {};
  GameServerPacket405(const std::vector<std::uint8_t> &data);
  std::vector<std::uint8_t> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket406 : public PacketReader {
public:
  GameServerPacket406() : PacketReader(406) {};
  GameServerPacket406(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint16_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket407 : public PacketReader {
public:
  GameServerPacket407() : PacketReader(407) {};
  GameServerPacket407(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInstanceLoadInfo : public PacketReader {
public:
  GameServerInstanceLoadInfo() : PacketReader(408) {};
  GameServerInstanceLoadInfo(const std::vector<std::uint8_t> &data);
  agent_id agent_id;
  std::uint16_t map_id;
  std::uint8_t is_explorable;
  std::uint32_t district;
  std::uint8_t language;
  std::uint8_t is_observer;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket409 : public PacketReader {
public:
  GameServerPacket409() : PacketReader(409) {};
  GameServerPacket409(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket410 : public PacketReader {
public:
  GameServerPacket410() : PacketReader(410) {};
  GameServerPacket410(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket411 : public PacketReader {
public:
  GameServerPacket411() : PacketReader(411) {};
  GameServerPacket411(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket412 : public PacketReader {
public:
  GameServerPacket412() : PacketReader(412) {};
  GameServerPacket412(const std::vector<std::uint8_t> &data);
  struct some_struct {
    std::uint8_t field_0;
    std::uint8_t field_1;
    std::uint8_t field_2;
    std::uint8_t field_3;
    std::uint8_t field_4;
    std::uint8_t field_5;
    std::uint8_t field_6;
    std::uint16_t field_7;
    std::uint8_t field_8;
    std::u16string field_9;
  };

  std::uint32_t field_0;
  std::uint16_t field_1;
  std::uint16_t field_2;
  std::uint8_t field_3;
  std::uint8_t field_4;
  std::uint8_t field_5;
  std::vector<some_struct> field_6;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  bool read_struct(std::vector<std::uint8_t>::const_iterator &it,
                   const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket413 : public PacketReader {
public:
  GameServerPacket413() : PacketReader(413) {};
  GameServerPacket413(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket414 : public PacketReader {
public:
  GameServerPacket414() : PacketReader(414) {};
  GameServerPacket414(const std::vector<std::uint8_t> &data);
  struct some_struct {
    std::uint16_t field_0;
    std::uint32_t field_1;
  };

  std::vector<some_struct> field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  bool read_struct(std::vector<std::uint8_t>::const_iterator &it,
                   const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerCreateMissionProgress : public PacketReader {
public:
  GameServerCreateMissionProgress() : PacketReader(415) {};
  GameServerCreateMissionProgress(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::u16string field_1;
  std::u16string field_2;
  std::uint8_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint32_t field_6;
  std::uint32_t field_7;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket416 : public PacketReader {
public:
  GameServerPacket416() : PacketReader(416) {};
  GameServerPacket416(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerUpdateMissionProgress : public PacketReader {
public:
  GameServerUpdateMissionProgress() : PacketReader(417) {};
  GameServerUpdateMissionProgress(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint8_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket418 : public PacketReader {
public:
  GameServerPacket418() : PacketReader(418) {};
  GameServerPacket418(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::u16string field_1;
  std::u16string field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket419 : public PacketReader {
public:
  GameServerPacket419() : PacketReader(419) {};
  GameServerPacket419(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint16_t field_1;
  std::uint8_t field_2;
  std::uint32_t field_3;
  std::uint8_t field_4;
  std::uint8_t field_5;
  std::uint32_t field_6;
  glm::vec2 field_7;
  std::uint16_t field_8;
  std::uint8_t field_9;
  std::uint8_t field_10;
  std::u16string field_11;
  std::array<std::uint8_t, 8> field_12;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerTransferGameServerInfo : public PacketReader {
public:
  GameServerTransferGameServerInfo() : PacketReader(420) {};
  GameServerTransferGameServerInfo(const std::vector<std::uint8_t> &data);
  std::array<std::uint8_t, 24> host;
  std::uint32_t world_id;
  std::uint8_t region;
  std::uint16_t map_id;
  std::uint8_t is_explorable;
  std::uint32_t player_id;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket421 : public PacketReader {
public:
  GameServerPacket421() : PacketReader(421) {};
  GameServerPacket421(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint8_t field_1;
  std::uint32_t field_2;
  std::u16string field_3;
  std::uint32_t field_4;
  std::u16string field_5;
  std::uint32_t field_6;
  std::uint8_t field_7;
  std::uint8_t field_8;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket422 : public PacketReader {
public:
  GameServerPacket422() : PacketReader(422) {};
  GameServerPacket422(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket423 : public PacketReader {
public:
  GameServerPacket423() : PacketReader(423) {};
  GameServerPacket423(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket424 : public PacketReader {
public:
  GameServerPacket424() : PacketReader(424) {};
  GameServerPacket424(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket425 : public PacketReader {
public:
  GameServerPacket425() : PacketReader(425) {};
  GameServerPacket425(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerReadyForMapSpawn : public PacketReader {
public:
  GameServerReadyForMapSpawn() : PacketReader(426) {};
  GameServerReadyForMapSpawn(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket427 : public PacketReader {
public:
  GameServerPacket427() : PacketReader(427) {};
  GameServerPacket427(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::u16string field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket428 : public PacketReader {
public:
  GameServerPacket428() : PacketReader(428) {};
  GameServerPacket428(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;
  std::uint8_t field_4;
  std::u16string field_5;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket429 : public PacketReader {
public:
  GameServerPacket429() : PacketReader(429) {};
  GameServerPacket429(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;
  std::uint8_t field_4;
  std::uint8_t field_5;
  std::uint16_t field_6;
  std::uint8_t field_7;
  std::uint32_t field_8;
  std::uint32_t field_9;
  std::u16string field_10;
  std::u16string field_11;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerDOACompleteZone : public PacketReader {
public:
  GameServerDOACompleteZone() : PacketReader(430) {};
  GameServerDOACompleteZone(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket431 : public PacketReader {
public:
  GameServerPacket431() : PacketReader(431) {};
  GameServerPacket431(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket432 : public PacketReader {
public:
  GameServerPacket432() : PacketReader(432) {};
  GameServerPacket432(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint32_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket433 : public PacketReader {
public:
  GameServerPacket433() : PacketReader(433) {};
  GameServerPacket433(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket434 : public PacketReader {
public:
  GameServerPacket434() : PacketReader(434) {};
  GameServerPacket434(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint8_t field_1;
  std::u16string field_2;
  std::uint32_t field_3;
  std::uint8_t field_4;
  std::uint32_t field_5;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket435 : public PacketReader {
public:
  GameServerPacket435() : PacketReader(435) {};
  GameServerPacket435(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket436 : public PacketReader {
public:
  GameServerPacket436() : PacketReader(436) {};
  GameServerPacket436(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint8_t field_1;
  std::u16string field_2;
  std::uint32_t field_3;
  std::uint8_t field_4;
  std::uint32_t field_5;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket437 : public PacketReader {
public:
  GameServerPacket437() : PacketReader(437) {};
  GameServerPacket437(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket438 : public PacketReader {
public:
  GameServerPacket438() : PacketReader(438) {};
  GameServerPacket438(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket439 : public PacketReader {
public:
  GameServerPacket439() : PacketReader(439) {};
  GameServerPacket439(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket440 : public PacketReader {
public:
  GameServerPacket440() : PacketReader(440) {};
  GameServerPacket440(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket441 : public PacketReader {
public:
  GameServerPacket441() : PacketReader(441) {};
  GameServerPacket441(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInstanceTravelTimer : public PacketReader {
public:
  GameServerInstanceTravelTimer() : PacketReader(442) {};
  GameServerInstanceTravelTimer(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::u16string field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerInstanceCantEnter : public PacketReader {
public:
  GameServerInstanceCantEnter() : PacketReader(443) {};
  GameServerInstanceCantEnter(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket444 : public PacketReader {
public:
  GameServerPacket444() : PacketReader(444) {};
  GameServerPacket444(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartySetDifficulty : public PacketReader {
public:
  GameServerPartySetDifficulty() : PacketReader(445) {};
  GameServerPartySetDifficulty(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyHenchmanAdd : public PacketReader {
public:
  GameServerPartyHenchmanAdd() : PacketReader(446) {};
  GameServerPartyHenchmanAdd(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;
  std::u16string field_2;
  std::uint8_t field_3;
  std::uint8_t field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyHenchmanRemove : public PacketReader {
public:
  GameServerPartyHenchmanRemove() : PacketReader(447) {};
  GameServerPartyHenchmanRemove(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket448 : public PacketReader {
public:
  GameServerPacket448() : PacketReader(448) {};
  GameServerPacket448(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyHeroAdd : public PacketReader {
public:
  GameServerPartyHeroAdd() : PacketReader(449) {};
  GameServerPartyHeroAdd(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;
  std::uint16_t field_2;
  std::uint8_t field_3;
  std::uint8_t field_4;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyHeroRemove : public PacketReader {
public:
  GameServerPartyHeroRemove() : PacketReader(450) {};
  GameServerPartyHeroRemove(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;
  std::uint16_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyInviteAdd : public PacketReader {
public:
  GameServerPartyInviteAdd() : PacketReader(451) {};
  GameServerPartyInviteAdd(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyJoinRequest : public PacketReader {
public:
  GameServerPartyJoinRequest() : PacketReader(452) {};
  GameServerPartyJoinRequest(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyInviteCancel : public PacketReader {
public:
  GameServerPartyInviteCancel() : PacketReader(453) {};
  GameServerPartyInviteCancel(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyRequestCancel : public PacketReader {
public:
  GameServerPartyRequestCancel() : PacketReader(454) {};
  GameServerPartyRequestCancel(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyRequestResponse : public PacketReader {
public:
  GameServerPartyRequestResponse() : PacketReader(455) {};
  GameServerPartyRequestResponse(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyInviteResponse : public PacketReader {
public:
  GameServerPartyInviteResponse() : PacketReader(456) {};
  GameServerPartyInviteResponse(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyYouAreLeader : public PacketReader {
public:
  GameServerPartyYouAreLeader() : PacketReader(457) {};
  GameServerPartyYouAreLeader(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyPlayerAdd : public PacketReader {
public:
  GameServerPartyPlayerAdd() : PacketReader(458) {};
  GameServerPartyPlayerAdd(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket459 : public PacketReader {
public:
  GameServerPacket459() : PacketReader(459) {};
  GameServerPacket459(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket460 : public PacketReader {
public:
  GameServerPacket460() : PacketReader(460) {};
  GameServerPacket460(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket461 : public PacketReader {
public:
  GameServerPacket461() : PacketReader(461) {};
  GameServerPacket461(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket462 : public PacketReader {
public:
  GameServerPacket462() : PacketReader(462) {};
  GameServerPacket462(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyPlayerRemove : public PacketReader {
public:
  GameServerPartyPlayerRemove() : PacketReader(463) {};
  GameServerPartyPlayerRemove(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyPlayerReady : public PacketReader {
public:
  GameServerPartyPlayerReady() : PacketReader(464) {};
  GameServerPartyPlayerReady(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyCreate : public PacketReader {
public:
  GameServerPartyCreate() : PacketReader(465) {};
  GameServerPartyCreate(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyMemberStreamEnd : public PacketReader {
public:
  GameServerPartyMemberStreamEnd() : PacketReader(466) {};
  GameServerPartyMemberStreamEnd(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket467 : public PacketReader {
public:
  GameServerPacket467() : PacketReader(467) {};
  GameServerPacket467(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket468 : public PacketReader {
public:
  GameServerPacket468() : PacketReader(468) {};
  GameServerPacket468(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket469 : public PacketReader {
public:
  GameServerPacket469() : PacketReader(469) {};
  GameServerPacket469(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket470 : public PacketReader {
public:
  GameServerPacket470() : PacketReader(470) {};
  GameServerPacket470(const std::vector<std::uint8_t> &data);
  struct some_struct {
    std::uint32_t field_0;
    std::uint32_t field_1;
    std::uint32_t field_2;
  };

  std::vector<std::uint16_t> field_0;
  std::vector<some_struct> field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  bool read_struct(std::vector<std::uint8_t>::const_iterator &it,
                   const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyDefeated : public PacketReader {
public:
  GameServerPartyDefeated() : PacketReader(471) {};
  GameServerPartyDefeated(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartyLock : public PacketReader {
public:
  GameServerPartyLock() : PacketReader(472) {};
  GameServerPartyLock(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint8_t field_1;
  std::u16string field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket473 : public PacketReader {
public:
  GameServerPacket473() : PacketReader(473) {};
  GameServerPacket473(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartySearchRequestJoin : public PacketReader {
public:
  GameServerPartySearchRequestJoin() : PacketReader(474) {};
  GameServerPartySearchRequestJoin(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartySearchRequestDone : public PacketReader {
public:
  GameServerPartySearchRequestDone() : PacketReader(475) {};
  GameServerPartySearchRequestDone(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartySearchAdvertisement : public PacketReader {
public:
  GameServerPartySearchAdvertisement() : PacketReader(476) {};
  GameServerPartySearchAdvertisement(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;
  std::uint8_t field_4;
  std::uint8_t field_5;
  std::uint8_t field_6;
  std::u16string field_7;
  std::u16string field_8;
  std::uint8_t field_9;
  std::uint8_t field_10;
  std::uint8_t field_11;
  std::uint32_t field_12;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartySearchSeek : public PacketReader {
public:
  GameServerPartySearchSeek() : PacketReader(477) {};
  GameServerPartySearchSeek(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartySearchRemove : public PacketReader {
public:
  GameServerPartySearchRemove() : PacketReader(478) {};
  GameServerPartySearchRemove(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartySearchSize : public PacketReader {
public:
  GameServerPartySearchSize() : PacketReader(479) {};
  GameServerPartySearchSize(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPartySearchType : public PacketReader {
public:
  GameServerPartySearchType() : PacketReader(480) {};
  GameServerPartySearchType(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket481 : public PacketReader {
public:
  GameServerPacket481() : PacketReader(481) {};
  GameServerPacket481(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket482 : public PacketReader {
public:
  GameServerPacket482() : PacketReader(482) {};
  GameServerPacket482(const std::vector<std::uint8_t> &data);
  std::u16string field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket483 : public PacketReader {
public:
  GameServerPacket483() : PacketReader(483) {};
  GameServerPacket483(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameServerPacket484 : public PacketReader {
public:
  GameServerPacket484() : PacketReader(484) {};
  GameServerPacket484(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

} // namespace common
} // namespace utopia

#endif // GAME_SERVER_PACKETS_HPP
