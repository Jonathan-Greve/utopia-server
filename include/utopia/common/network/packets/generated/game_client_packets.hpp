#ifndef GAME_CLIENT_PACKETS_HPP
#define GAME_CLIENT_PACKETS_HPP

#include "utopia/common/network/packets/packet_reader.hpp"

#include <glm/glm.hpp>

#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace utopia {
namespace common {

class GameClientTradeAcknowledge : public PacketReader {
public:
  GameClientTradeAcknowledge() : PacketReader(32768) {};
  GameClientTradeAcknowledge(const std::vector<std::uint8_t> &data);
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

class GameClientTradeCancel : public PacketReader {
public:
  GameClientTradeCancel() : PacketReader(32769) {};
  GameClientTradeCancel(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientTradeAddItem : public PacketReader {
public:
  GameClientTradeAddItem() : PacketReader(32770) {};
  GameClientTradeAddItem(const std::vector<std::uint8_t> &data);
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

class GameClientTradeSendOffer : public PacketReader {
public:
  GameClientTradeSendOffer() : PacketReader(32771) {};
  GameClientTradeSendOffer(const std::vector<std::uint8_t> &data);
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

class GameClientPacket004 : public PacketReader {
public:
  GameClientPacket004() : PacketReader(32772) {};
  GameClientPacket004(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientTradeRemoveItem : public PacketReader {
public:
  GameClientTradeRemoveItem() : PacketReader(32773) {};
  GameClientTradeRemoveItem(const std::vector<std::uint8_t> &data);
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

class GameClientTradeCancelOffer : public PacketReader {
public:
  GameClientTradeCancelOffer() : PacketReader(32774) {};
  GameClientTradeCancelOffer(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientTradeAccept : public PacketReader {
public:
  GameClientTradeAccept() : PacketReader(32775) {};
  GameClientTradeAccept(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientDisconnect : public PacketReader {
public:
  GameClientDisconnect() : PacketReader(32776) {};
  GameClientDisconnect(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPingReply : public PacketReader {
public:
  GameClientPingReply() : PacketReader(32777) {};
  GameClientPingReply(const std::vector<std::uint8_t> &data);
  std::uint32_t value;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientHeartbeat : public PacketReader {
public:
  GameClientHeartbeat() : PacketReader(32778) {};
  GameClientHeartbeat(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPingRequest : public PacketReader {
public:
  GameClientPingRequest() : PacketReader(32779) {};
  GameClientPingRequest(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientAttributeDecrease : public PacketReader {
public:
  GameClientAttributeDecrease() : PacketReader(32780) {};
  GameClientAttributeDecrease(const std::vector<std::uint8_t> &data);
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

class GameClientAttributeIncrease : public PacketReader {
public:
  GameClientAttributeIncrease() : PacketReader(32781) {};
  GameClientAttributeIncrease(const std::vector<std::uint8_t> &data);
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

class GameClientAttributeLoad : public PacketReader {
public:
  GameClientAttributeLoad() : PacketReader(32782) {};
  GameClientAttributeLoad(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::vector<std::uint32_t> field_1;
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

class GameClientQuestAbandon : public PacketReader {
public:
  GameClientQuestAbandon() : PacketReader(32783) {};
  GameClientQuestAbandon(const std::vector<std::uint8_t> &data);
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

class GameClientQuestRequestInfos : public PacketReader {
public:
  GameClientQuestRequestInfos() : PacketReader(32784) {};
  GameClientQuestRequestInfos(const std::vector<std::uint8_t> &data);
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

class GameClientPacket017 : public PacketReader {
public:
  GameClientPacket017() : PacketReader(32785) {};
  GameClientPacket017(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket018 : public PacketReader {
public:
  GameClientPacket018() : PacketReader(32786) {};
  GameClientPacket018(const std::vector<std::uint8_t> &data);
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

class GameClientHeroBehavior : public PacketReader {
public:
  GameClientHeroBehavior() : PacketReader(32787) {};
  GameClientHeroBehavior(const std::vector<std::uint8_t> &data);
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

class GameClientHeroLockTarget : public PacketReader {
public:
  GameClientHeroLockTarget() : PacketReader(32788) {};
  GameClientHeroLockTarget(const std::vector<std::uint8_t> &data);
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

class GameClientPacket021 : public PacketReader {
public:
  GameClientPacket021() : PacketReader(32789) {};
  GameClientPacket021(const std::vector<std::uint8_t> &data);
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

class GameClientPacket022 : public PacketReader {
public:
  GameClientPacket022() : PacketReader(32790) {};
  GameClientPacket022(const std::vector<std::uint8_t> &data);
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

class GameClientHeroSkillToggle : public PacketReader {
public:
  GameClientHeroSkillToggle() : PacketReader(32791) {};
  GameClientHeroSkillToggle(const std::vector<std::uint8_t> &data);
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

class GameClientHeroFlagSingle : public PacketReader {
public:
  GameClientHeroFlagSingle() : PacketReader(32792) {};
  GameClientHeroFlagSingle(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  glm::vec2 field_1;
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

class GameClientHeroFlagAll : public PacketReader {
public:
  GameClientHeroFlagAll() : PacketReader(32793) {};
  GameClientHeroFlagAll(const std::vector<std::uint8_t> &data);
  glm::vec2 field_0;
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

class GameClientHeroUseSkill : public PacketReader {
public:
  GameClientHeroUseSkill() : PacketReader(32794) {};
  GameClientHeroUseSkill(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  agent_id field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket027 : public PacketReader {
public:
  GameClientPacket027() : PacketReader(32795) {};
  GameClientPacket027(const std::vector<std::uint8_t> &data);
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

class GameClientHeroAdd : public PacketReader {
public:
  GameClientHeroAdd() : PacketReader(32796) {};
  GameClientHeroAdd(const std::vector<std::uint8_t> &data);
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

class GameClientHeroKick : public PacketReader {
public:
  GameClientHeroKick() : PacketReader(32797) {};
  GameClientHeroKick(const std::vector<std::uint8_t> &data);
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

class GameClientPacket030 : public PacketReader {
public:
  GameClientPacket030() : PacketReader(32798) {};
  GameClientPacket030(const std::vector<std::uint8_t> &data);
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

class GameClientPacket031 : public PacketReader {
public:
  GameClientPacket031() : PacketReader(32799) {};
  GameClientPacket031(const std::vector<std::uint8_t> &data);
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

class GameClientPacket032 : public PacketReader {
public:
  GameClientPacket032() : PacketReader(32800) {};
  GameClientPacket032(const std::vector<std::uint8_t> &data);
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

class GameClientTargetCall : public PacketReader {
public:
  GameClientTargetCall() : PacketReader(32801) {};
  GameClientTargetCall(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
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

class GameClientPacket034 : public PacketReader {
public:
  GameClientPacket034() : PacketReader(32802) {};
  GameClientPacket034(const std::vector<std::uint8_t> &data);
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

class GameClientPingWeaponSet : public PacketReader {
public:
  GameClientPingWeaponSet() : PacketReader(32803) {};
  GameClientPingWeaponSet(const std::vector<std::uint8_t> &data);
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

class GameClientAttackAgent : public PacketReader {
public:
  GameClientAttackAgent() : PacketReader(32804) {};
  GameClientAttackAgent(const std::vector<std::uint8_t> &data);
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

class GameClientPacket037 : public PacketReader {
public:
  GameClientPacket037() : PacketReader(32805) {};
  GameClientPacket037(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
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

class GameClientCancelMovement : public PacketReader {
public:
  GameClientCancelMovement() : PacketReader(32806) {};
  GameClientCancelMovement(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientDropBuff : public PacketReader {
public:
  GameClientDropBuff() : PacketReader(32807) {};
  GameClientDropBuff(const std::vector<std::uint8_t> &data);
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

class GameClientPacket040 : public PacketReader {
public:
  GameClientPacket040() : PacketReader(32808) {};
  GameClientPacket040(const std::vector<std::uint8_t> &data);
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

class GameClientDrawMap : public PacketReader {
public:
  GameClientDrawMap() : PacketReader(32809) {};
  GameClientDrawMap(const std::vector<std::uint8_t> &data);
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

class GameClientDropItem : public PacketReader {
public:
  GameClientDropItem() : PacketReader(32810) {};
  GameClientDropItem(const std::vector<std::uint8_t> &data);
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

class GameClientPacket043 : public PacketReader {
public:
  GameClientPacket043() : PacketReader(32811) {};
  GameClientPacket043(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket044 : public PacketReader {
public:
  GameClientPacket044() : PacketReader(32812) {};
  GameClientPacket044(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientDropGold : public PacketReader {
public:
  GameClientDropGold() : PacketReader(32813) {};
  GameClientDropGold(const std::vector<std::uint8_t> &data);
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

class GameClientEquipItem : public PacketReader {
public:
  GameClientEquipItem() : PacketReader(32814) {};
  GameClientEquipItem(const std::vector<std::uint8_t> &data);
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

class GameClientPacket047 : public PacketReader {
public:
  GameClientPacket047() : PacketReader(32815) {};
  GameClientPacket047(const std::vector<std::uint8_t> &data);
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

class GameClientPacket048 : public PacketReader {
public:
  GameClientPacket048() : PacketReader(32816) {};
  GameClientPacket048(const std::vector<std::uint8_t> &data);
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

class GameClientInteractPlayer : public PacketReader {
public:
  GameClientInteractPlayer() : PacketReader(32817) {};
  GameClientInteractPlayer(const std::vector<std::uint8_t> &data);
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

class GameClientPacket050 : public PacketReader {
public:
  GameClientPacket050() : PacketReader(32818) {};
  GameClientPacket050(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;
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

class GameClientDepositFaction : public PacketReader {
public:
  GameClientDepositFaction() : PacketReader(32819) {};
  GameClientDepositFaction(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
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

class GameClientPacket052 : public PacketReader {
public:
  GameClientPacket052() : PacketReader(32820) {};
  GameClientPacket052(const std::vector<std::uint8_t> &data);
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

class GameClientPacket053 : public PacketReader {
public:
  GameClientPacket053() : PacketReader(32821) {};
  GameClientPacket053(const std::vector<std::uint8_t> &data);
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

class GameClientPacket054 : public PacketReader {
public:
  GameClientPacket054() : PacketReader(32822) {};
  GameClientPacket054(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;
  std::uint8_t field_4;
  std::uint8_t field_5;
  std::uint16_t field_6;
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

class GameClientInteractLiving : public PacketReader {
public:
  GameClientInteractLiving() : PacketReader(32823) {};
  GameClientInteractLiving(const std::vector<std::uint8_t> &data);
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

class GameClientPacket056 : public PacketReader {
public:
  GameClientPacket056() : PacketReader(32824) {};
  GameClientPacket056(const std::vector<std::uint8_t> &data);
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

class GameClientSendDialog : public PacketReader {
public:
  GameClientSendDialog() : PacketReader(32825) {};
  GameClientSendDialog(const std::vector<std::uint8_t> &data);
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

class GameClientPacket058 : public PacketReader {
public:
  GameClientPacket058() : PacketReader(32826) {};
  GameClientPacket058(const std::vector<std::uint8_t> &data);
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

class GameClientPacket059 : public PacketReader {
public:
  GameClientPacket059() : PacketReader(32827) {};
  GameClientPacket059(const std::vector<std::uint8_t> &data);
  glm::vec2 field_0;
  std::uint32_t field_1;
  glm::vec2 field_2;
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

class GameClientMoveToCoord : public PacketReader {
public:
  GameClientMoveToCoord() : PacketReader(32828) {};
  GameClientMoveToCoord(const std::vector<std::uint8_t> &data);
  glm::vec2 field_0;
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

class GameClientInteractItem : public PacketReader {
public:
  GameClientInteractItem() : PacketReader(32829) {};
  GameClientInteractItem(const std::vector<std::uint8_t> &data);
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

class GameClientRotatePlayer : public PacketReader {
public:
  GameClientRotatePlayer() : PacketReader(32830) {};
  GameClientRotatePlayer(const std::vector<std::uint8_t> &data);
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

class GameClientChangeSecondProfession : public PacketReader {
public:
  GameClientChangeSecondProfession() : PacketReader(32831) {};
  GameClientChangeSecondProfession(const std::vector<std::uint8_t> &data);
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

class GameClientPacket064 : public PacketReader {
public:
  GameClientPacket064() : PacketReader(32832) {};
  GameClientPacket064(const std::vector<std::uint8_t> &data);
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

class GameClientPacket065 : public PacketReader {
public:
  GameClientPacket065() : PacketReader(32833) {};
  GameClientPacket065(const std::vector<std::uint8_t> &data);
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

class GameClientPacket066 : public PacketReader {
public:
  GameClientPacket066() : PacketReader(32834) {};
  GameClientPacket066(const std::vector<std::uint8_t> &data);
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

class GameClientPacket067 : public PacketReader {
public:
  GameClientPacket067() : PacketReader(32835) {};
  GameClientPacket067(const std::vector<std::uint8_t> &data);
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

class GameClientUseSkill : public PacketReader {
public:
  GameClientUseSkill() : PacketReader(32836) {};
  GameClientUseSkill(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  agent_id field_2;
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

class GameClientPacket069 : public PacketReader {
public:
  GameClientPacket069() : PacketReader(32837) {};
  GameClientPacket069(const std::vector<std::uint8_t> &data);
  glm::vec2 field_0;
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

class GameClientPacket070 : public PacketReader {
public:
  GameClientPacket070() : PacketReader(32838) {};
  GameClientPacket070(const std::vector<std::uint8_t> &data);
  glm::vec2 field_0;
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

class GameClientTradeInitiate : public PacketReader {
public:
  GameClientTradeInitiate() : PacketReader(32839) {};
  GameClientTradeInitiate(const std::vector<std::uint8_t> &data);
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

class GameClientBuyMaterials : public PacketReader {
public:
  GameClientBuyMaterials() : PacketReader(32840) {};
  GameClientBuyMaterials(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;
  std::vector<std::uint32_t> field_2;
  std::uint32_t field_3;
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

class GameClientPacket073 : public PacketReader {
public:
  GameClientPacket073() : PacketReader(32841) {};
  GameClientPacket073(const std::vector<std::uint8_t> &data);
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

class GameClientRequestQuote : public PacketReader {
public:
  GameClientRequestQuote() : PacketReader(32842) {};
  GameClientRequestQuote(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint8_t field_1;
  std::uint32_t field_2;
  std::vector<std::uint32_t> field_3;
  std::uint32_t field_4;
  std::vector<std::uint32_t> field_5;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientTransactItems : public PacketReader {
public:
  GameClientTransactItems() : PacketReader(32843) {};
  GameClientTransactItems(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::uint32_t field_1;
  std::vector<std::uint32_t> field_2;
  std::vector<std::uint8_t> field_3;
  std::uint32_t field_4;
  std::vector<std::uint32_t> field_5;
  std::vector<std::uint8_t> field_6;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket076 : public PacketReader {
public:
  GameClientPacket076() : PacketReader(32844) {};
  GameClientPacket076(const std::vector<std::uint8_t> &data);
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

class GameClientUnequipItem : public PacketReader {
public:
  GameClientUnequipItem() : PacketReader(32845) {};
  GameClientUnequipItem(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
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

class GameClientPacket078 : public PacketReader {
public:
  GameClientPacket078() : PacketReader(32846) {};
  GameClientPacket078(const std::vector<std::uint8_t> &data);
  agent_id field_0;
  std::uint8_t field_1;
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

class GameClientInteractGadget : public PacketReader {
public:
  GameClientInteractGadget() : PacketReader(32847) {};
  GameClientInteractGadget(const std::vector<std::uint8_t> &data);
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

class GameClientPacket080 : public PacketReader {
public:
  GameClientPacket080() : PacketReader(32848) {};
  GameClientPacket080(const std::vector<std::uint8_t> &data);
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

class GameClientOpenChest : public PacketReader {
public:
  GameClientOpenChest() : PacketReader(32849) {};
  GameClientOpenChest(const std::vector<std::uint8_t> &data);
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

class GameClientPacket082 : public PacketReader {
public:
  GameClientPacket082() : PacketReader(32850) {};
  GameClientPacket082(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint8_t field_2;
  std::uint8_t field_3;
  std::uint8_t field_4;
  std::uint8_t field_5;
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

class GameClientPacket083 : public PacketReader {
public:
  GameClientPacket083() : PacketReader(32851) {};
  GameClientPacket083(const std::vector<std::uint8_t> &data);
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

class GameClientPacket084 : public PacketReader {
public:
  GameClientPacket084() : PacketReader(32852) {};
  GameClientPacket084(const std::vector<std::uint8_t> &data);
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

class GameClientEquipVisibility : public PacketReader {
public:
  GameClientEquipVisibility() : PacketReader(32853) {};
  GameClientEquipVisibility(const std::vector<std::uint8_t> &data);
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

class GameClientTitleDisplay : public PacketReader {
public:
  GameClientTitleDisplay() : PacketReader(32854) {};
  GameClientTitleDisplay(const std::vector<std::uint8_t> &data);
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

class GameClientTitleHide : public PacketReader {
public:
  GameClientTitleHide() : PacketReader(32855) {};
  GameClientTitleHide(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket088 : public PacketReader {
public:
  GameClientPacket088() : PacketReader(32856) {};
  GameClientPacket088(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket089 : public PacketReader {
public:
  GameClientPacket089() : PacketReader(32857) {};
  GameClientPacket089(const std::vector<std::uint8_t> &data);
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

class GameClientSkillbarSkillSet : public PacketReader {
public:
  GameClientSkillbarSkillSet() : PacketReader(32858) {};
  GameClientSkillbarSkillSet(const std::vector<std::uint8_t> &data);
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

class GameClientSkillbarLoad : public PacketReader {
public:
  GameClientSkillbarLoad() : PacketReader(32859) {};
  GameClientSkillbarLoad(const std::vector<std::uint8_t> &data);
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

class GameClientSkillbarSkillReplace : public PacketReader {
public:
  GameClientSkillbarSkillReplace() : PacketReader(32860) {};
  GameClientSkillbarSkillReplace(const std::vector<std::uint8_t> &data);
  agent_id field_0;
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

class GameClientPacket093 : public PacketReader {
public:
  GameClientPacket093() : PacketReader(32861) {};
  GameClientPacket093(const std::vector<std::uint8_t> &data);
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

class GameClientPacket094 : public PacketReader {
public:
  GameClientPacket094() : PacketReader(32862) {};
  GameClientPacket094(const std::vector<std::uint8_t> &data);
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

class GameClientPacket095 : public PacketReader {
public:
  GameClientPacket095() : PacketReader(32863) {};
  GameClientPacket095(const std::vector<std::uint8_t> &data);
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

class GameClientPacket096 : public PacketReader {
public:
  GameClientPacket096() : PacketReader(32864) {};
  GameClientPacket096(const std::vector<std::uint8_t> &data);
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

class GameClientSkipCinematic : public PacketReader {
public:
  GameClientSkipCinematic() : PacketReader(32865) {};
  GameClientSkipCinematic(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientSendChatMessage : public PacketReader {
public:
  GameClientSendChatMessage() : PacketReader(32866) {};
  GameClientSendChatMessage(const std::vector<std::uint8_t> &data);
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

class GameClientPacket099 : public PacketReader {
public:
  GameClientPacket099() : PacketReader(32867) {};
  GameClientPacket099(const std::vector<std::uint8_t> &data);
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

class GameClientPacket100 : public PacketReader {
public:
  GameClientPacket100() : PacketReader(32868) {};
  GameClientPacket100(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
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

class GameClientPacket101 : public PacketReader {
public:
  GameClientPacket101() : PacketReader(32869) {};
  GameClientPacket101(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint8_t field_1;
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

class GameClientPacket102 : public PacketReader {
public:
  GameClientPacket102() : PacketReader(32870) {};
  GameClientPacket102(const std::vector<std::uint8_t> &data);
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

class GameClientItemDestroy : public PacketReader {
public:
  GameClientItemDestroy() : PacketReader(32871) {};
  GameClientItemDestroy(const std::vector<std::uint8_t> &data);
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

class GameClientPacket104 : public PacketReader {
public:
  GameClientPacket104() : PacketReader(32872) {};
  GameClientPacket104(const std::vector<std::uint8_t> &data);
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

class GameClientPacket105 : public PacketReader {
public:
  GameClientPacket105() : PacketReader(32873) {};
  GameClientPacket105(const std::vector<std::uint8_t> &data);
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

class GameClientItemIdentify : public PacketReader {
public:
  GameClientItemIdentify() : PacketReader(32874) {};
  GameClientItemIdentify(const std::vector<std::uint8_t> &data);
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

class GameClientTomeUnlockSkill : public PacketReader {
public:
  GameClientTomeUnlockSkill() : PacketReader(32875) {};
  GameClientTomeUnlockSkill(const std::vector<std::uint8_t> &data);
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

class GameClientPacket108 : public PacketReader {
public:
  GameClientPacket108() : PacketReader(32876) {};
  GameClientPacket108(const std::vector<std::uint8_t> &data);
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

class GameClientPacket109 : public PacketReader {
public:
  GameClientPacket109() : PacketReader(32877) {};
  GameClientPacket109(const std::vector<std::uint8_t> &data);
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

class GameClientPacket110 : public PacketReader {
public:
  GameClientPacket110() : PacketReader(32878) {};
  GameClientPacket110(const std::vector<std::uint8_t> &data);
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

class GameClientPacket111 : public PacketReader {
public:
  GameClientPacket111() : PacketReader(32879) {};
  GameClientPacket111(const std::vector<std::uint8_t> &data);
  struct some_struct {
    std::uint8_t field_0;
    std::uint32_t field_1;
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

class GameClientItemMove : public PacketReader {
public:
  GameClientItemMove() : PacketReader(32880) {};
  GameClientItemMove(const std::vector<std::uint8_t> &data);
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

class GameClientItemAcceptAll : public PacketReader {
public:
  GameClientItemAcceptAll() : PacketReader(32881) {};
  GameClientItemAcceptAll(const std::vector<std::uint8_t> &data);
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

class GameClientPacket114 : public PacketReader {
public:
  GameClientPacket114() : PacketReader(32882) {};
  GameClientPacket114(const std::vector<std::uint8_t> &data);
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

class GameClientItemSplitStack : public PacketReader {
public:
  GameClientItemSplitStack() : PacketReader(32883) {};
  GameClientItemSplitStack(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
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

class GameClientPacket116 : public PacketReader {
public:
  GameClientPacket116() : PacketReader(32884) {};
  GameClientPacket116(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientItemSalvageSessionOpen : public PacketReader {
public:
  GameClientItemSalvageSessionOpen() : PacketReader(32885) {};
  GameClientItemSalvageSessionOpen(const std::vector<std::uint8_t> &data);
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

class GameClientItemSalvageSessionCancel : public PacketReader {
public:
  GameClientItemSalvageSessionCancel() : PacketReader(32886) {};
  GameClientItemSalvageSessionCancel(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientItemSalvageSessionDone : public PacketReader {
public:
  GameClientItemSalvageSessionDone() : PacketReader(32887) {};
  GameClientItemSalvageSessionDone(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientItemSalvageMaterials : public PacketReader {
public:
  GameClientItemSalvageMaterials() : PacketReader(32888) {};
  GameClientItemSalvageMaterials(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientItemSalvageUpgrade : public PacketReader {
public:
  GameClientItemSalvageUpgrade() : PacketReader(32889) {};
  GameClientItemSalvageUpgrade(const std::vector<std::uint8_t> &data);
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

class GameClientItemChangeGold : public PacketReader {
public:
  GameClientItemChangeGold() : PacketReader(32890) {};
  GameClientItemChangeGold(const std::vector<std::uint8_t> &data);
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

class GameClientPacket123 : public PacketReader {
public:
  GameClientPacket123() : PacketReader(32891) {};
  GameClientPacket123(const std::vector<std::uint8_t> &data);
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

class GameClientItemUse : public PacketReader {
public:
  GameClientItemUse() : PacketReader(32892) {};
  GameClientItemUse(const std::vector<std::uint8_t> &data);
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

class GameClientPacket125 : public PacketReader {
public:
  GameClientPacket125() : PacketReader(32893) {};
  GameClientPacket125(const std::vector<std::uint8_t> &data);
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

class GameClientPacket126 : public PacketReader {
public:
  GameClientPacket126() : PacketReader(32894) {};
  GameClientPacket126(const std::vector<std::uint8_t> &data);
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

class GameClientPacket127 : public PacketReader {
public:
  GameClientPacket127() : PacketReader(32895) {};
  GameClientPacket127(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket128 : public PacketReader {
public:
  GameClientPacket128() : PacketReader(32896) {};
  GameClientPacket128(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket129 : public PacketReader {
public:
  GameClientPacket129() : PacketReader(32897) {};
  GameClientPacket129(const std::vector<std::uint8_t> &data);
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

class GameClientPacket130 : public PacketReader {
public:
  GameClientPacket130() : PacketReader(32898) {};
  GameClientPacket130(const std::vector<std::uint8_t> &data);
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

class GameClientPacket131 : public PacketReader {
public:
  GameClientPacket131() : PacketReader(32899) {};
  GameClientPacket131(const std::vector<std::uint8_t> &data);
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

class GameClientPacket132 : public PacketReader {
public:
  GameClientPacket132() : PacketReader(32900) {};
  GameClientPacket132(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint16_t field_1;
  std::vector<std::uint16_t> field_2;
  std::uint8_t field_3;
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

class GameClientPacket133 : public PacketReader {
public:
  GameClientPacket133() : PacketReader(32901) {};
  GameClientPacket133(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
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

class GameClientInstanceLoadRequestSpawn : public PacketReader {
public:
  GameClientInstanceLoadRequestSpawn() : PacketReader(32902) {};
  GameClientInstanceLoadRequestSpawn(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket135 : public PacketReader {
public:
  GameClientPacket135() : PacketReader(32903) {};
  GameClientPacket135(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket136 : public PacketReader {
public:
  GameClientPacket136() : PacketReader(32904) {};
  GameClientPacket136(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket137 : public PacketReader {
public:
  GameClientPacket137() : PacketReader(32905) {};
  GameClientPacket137(const std::vector<std::uint8_t> &data);
  std::u16string field_0;
  std::array<std::uint8_t, 8> field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket138 : public PacketReader {
public:
  GameClientPacket138() : PacketReader(32906) {};
  GameClientPacket138(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket139 : public PacketReader {
public:
  GameClientPacket139() : PacketReader(32907) {};
  GameClientPacket139(const std::vector<std::uint8_t> &data);
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

class GameClientPacket140 : public PacketReader {
public:
  GameClientPacket140() : PacketReader(32908) {};
  GameClientPacket140(const std::vector<std::uint8_t> &data);
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

class GameClientPacket141 : public PacketReader {
public:
  GameClientPacket141() : PacketReader(32909) {};
  GameClientPacket141(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientInstanceLoadRequestPlayers : public PacketReader {
public:
  GameClientInstanceLoadRequestPlayers() : PacketReader(32910) {};
  GameClientInstanceLoadRequestPlayers(const std::vector<std::uint8_t> &data);
  std::array<std::uint8_t, 16> request_data;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientRequestItems : public PacketReader {
public:
  GameClientRequestItems() : PacketReader(32911) {};
  GameClientRequestItems(const std::vector<std::uint8_t> &data);
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

class GameClientPacket144 : public PacketReader {
public:
  GameClientPacket144() : PacketReader(32912) {};
  GameClientPacket144(const std::vector<std::uint8_t> &data);
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

class GameClientPacket145 : public PacketReader {
public:
  GameClientPacket145() : PacketReader(32913) {};
  GameClientPacket145(const std::vector<std::uint8_t> &data);
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

class GameClientPacket146 : public PacketReader {
public:
  GameClientPacket146() : PacketReader(32914) {};
  GameClientPacket146(const std::vector<std::uint8_t> &data);
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

class GameClientPacket147 : public PacketReader {
public:
  GameClientPacket147() : PacketReader(32915) {};
  GameClientPacket147(const std::vector<std::uint8_t> &data);
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

class GameClientPacket148 : public PacketReader {
public:
  GameClientPacket148() : PacketReader(32916) {};
  GameClientPacket148(const std::vector<std::uint8_t> &data);
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

class GameClientPacket149 : public PacketReader {
public:
  GameClientPacket149() : PacketReader(32917) {};
  GameClientPacket149(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket150 : public PacketReader {
public:
  GameClientPacket150() : PacketReader(32918) {};
  GameClientPacket150(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket151 : public PacketReader {
public:
  GameClientPacket151() : PacketReader(32919) {};
  GameClientPacket151(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket152 : public PacketReader {
public:
  GameClientPacket152() : PacketReader(32920) {};
  GameClientPacket152(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPartySetDifficulty : public PacketReader {
public:
  GameClientPartySetDifficulty() : PacketReader(32921) {};
  GameClientPartySetDifficulty(const std::vector<std::uint8_t> &data);
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

class GameClientPartyAcceptInvite : public PacketReader {
public:
  GameClientPartyAcceptInvite() : PacketReader(32922) {};
  GameClientPartyAcceptInvite(const std::vector<std::uint8_t> &data);
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

class GameClientPartyAcceptCancel : public PacketReader {
public:
  GameClientPartyAcceptCancel() : PacketReader(32923) {};
  GameClientPartyAcceptCancel(const std::vector<std::uint8_t> &data);
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

class GameClientPartyAcceptRefuse : public PacketReader {
public:
  GameClientPartyAcceptRefuse() : PacketReader(32924) {};
  GameClientPartyAcceptRefuse(const std::vector<std::uint8_t> &data);
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

class GameClientPartyInviteNPC : public PacketReader {
public:
  GameClientPartyInviteNPC() : PacketReader(32925) {};
  GameClientPartyInviteNPC(const std::vector<std::uint8_t> &data);
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

class GameClientPartyInvitePlayer : public PacketReader {
public:
  GameClientPartyInvitePlayer() : PacketReader(32926) {};
  GameClientPartyInvitePlayer(const std::vector<std::uint8_t> &data);
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

class GameClientPartyInvitePlayerName : public PacketReader {
public:
  GameClientPartyInvitePlayerName() : PacketReader(32927) {};
  GameClientPartyInvitePlayerName(const std::vector<std::uint8_t> &data);
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

class GameClientPartyLeaveGroup : public PacketReader {
public:
  GameClientPartyLeaveGroup() : PacketReader(32928) {};
  GameClientPartyLeaveGroup(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPartyCancelEnterChallenge : public PacketReader {
public:
  GameClientPartyCancelEnterChallenge() : PacketReader(32929) {};
  GameClientPartyCancelEnterChallenge(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPacket162 : public PacketReader {
public:
  GameClientPacket162() : PacketReader(32930) {};
  GameClientPacket162(const std::vector<std::uint8_t> &data);
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

class GameClientPartyEnterChallenge : public PacketReader {
public:
  GameClientPartyEnterChallenge() : PacketReader(32931) {};
  GameClientPartyEnterChallenge(const std::vector<std::uint8_t> &data);
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

class GameClientPacket164 : public PacketReader {
public:
  GameClientPacket164() : PacketReader(32932) {};
  GameClientPacket164(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint32_t field_1;
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

class GameClientPartyReturnToOutpost : public PacketReader {
public:
  GameClientPartyReturnToOutpost() : PacketReader(32933) {};
  GameClientPartyReturnToOutpost(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPartyKickNPC : public PacketReader {
public:
  GameClientPartyKickNPC() : PacketReader(32934) {};
  GameClientPartyKickNPC(const std::vector<std::uint8_t> &data);
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

class GameClientPartyKickPlayer : public PacketReader {
public:
  GameClientPartyKickPlayer() : PacketReader(32935) {};
  GameClientPartyKickPlayer(const std::vector<std::uint8_t> &data);
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

class GameClientPartySearchSeek : public PacketReader {
public:
  GameClientPartySearchSeek() : PacketReader(32936) {};
  GameClientPartySearchSeek(const std::vector<std::uint8_t> &data);
  std::uint8_t field_0;
  std::u16string field_1;
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

class GameClientPartySearchCancel : public PacketReader {
public:
  GameClientPartySearchCancel() : PacketReader(32937) {};
  GameClientPartySearchCancel(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class GameClientPartySearchRequestJoin : public PacketReader {
public:
  GameClientPartySearchRequestJoin() : PacketReader(32938) {};
  GameClientPartySearchRequestJoin(const std::vector<std::uint8_t> &data);
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

class GameClientPartySearchRequestReply : public PacketReader {
public:
  GameClientPartySearchRequestReply() : PacketReader(32939) {};
  GameClientPartySearchRequestReply(const std::vector<std::uint8_t> &data);
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

class GameClientPartySearchType : public PacketReader {
public:
  GameClientPartySearchType() : PacketReader(32940) {};
  GameClientPartySearchType(const std::vector<std::uint8_t> &data);
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

class GameClientPartyReadyStatus : public PacketReader {
public:
  GameClientPartyReadyStatus() : PacketReader(32941) {};
  GameClientPartyReadyStatus(const std::vector<std::uint8_t> &data);
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

class GameClientPartyEnterGuildHall : public PacketReader {
public:
  GameClientPartyEnterGuildHall() : PacketReader(32942) {};
  GameClientPartyEnterGuildHall(const std::vector<std::uint8_t> &data);
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

class GameClientPartyTravel : public PacketReader {
public:
  GameClientPartyTravel() : PacketReader(32943) {};
  GameClientPartyTravel(const std::vector<std::uint8_t> &data);
  std::uint16_t field_0;
  std::uint8_t field_1;
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

class GameClientPartyLeaveGuildHall : public PacketReader {
public:
  GameClientPartyLeaveGuildHall() : PacketReader(32944) {};
  GameClientPartyLeaveGuildHall(const std::vector<std::uint8_t> &data);
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

class GameClientPacket177 : public PacketReader {
public:
  GameClientPacket177() : PacketReader(32945) {};
  GameClientPacket177(const std::vector<std::uint8_t> &data);
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

class GameClientPacket178 : public PacketReader {
public:
  GameClientPacket178() : PacketReader(32946) {};
  GameClientPacket178(const std::vector<std::uint8_t> &data);
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

class GameClientPacket179 : public PacketReader {
public:
  GameClientPacket179() : PacketReader(32947) {};
  GameClientPacket179(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;
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

class GameClientPacket180 : public PacketReader {
public:
  GameClientPacket180() : PacketReader(32948) {};
  GameClientPacket180(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
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

class GameClientPacket181 : public PacketReader {
public:
  GameClientPacket181() : PacketReader(32949) {};
  GameClientPacket181(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
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

class GameClientPacket182 : public PacketReader {
public:
  GameClientPacket182() : PacketReader(32950) {};
  GameClientPacket182(const std::vector<std::uint8_t> &data);
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

class GameClientPacket183 : public PacketReader {
public:
  GameClientPacket183() : PacketReader(32951) {};
  GameClientPacket183(const std::vector<std::uint8_t> &data);
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

class GameClientPacket184 : public PacketReader {
public:
  GameClientPacket184() : PacketReader(32952) {};
  GameClientPacket184(const std::vector<std::uint8_t> &data);
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

class GameClientPacket185 : public PacketReader {
public:
  GameClientPacket185() : PacketReader(32953) {};
  GameClientPacket185(const std::vector<std::uint8_t> &data);
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

class GameClientPacket186 : public PacketReader {
public:
  GameClientPacket186() : PacketReader(32954) {};
  GameClientPacket186(const std::vector<std::uint8_t> &data);
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

class GameClientPacket187 : public PacketReader {
public:
  GameClientPacket187() : PacketReader(32955) {};
  GameClientPacket187(const std::vector<std::uint8_t> &data);
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

class GameClientPacket188 : public PacketReader {
public:
  GameClientPacket188() : PacketReader(32956) {};
  GameClientPacket188(const std::vector<std::uint8_t> &data);
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

class GameClientPacket189 : public PacketReader {
public:
  GameClientPacket189() : PacketReader(32957) {};
  GameClientPacket189(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
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

class GameClientPacket190 : public PacketReader {
public:
  GameClientPacket190() : PacketReader(32958) {};
  GameClientPacket190(const std::vector<std::uint8_t> &data);
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

class GameClientPacket191 : public PacketReader {
public:
  GameClientPacket191() : PacketReader(32959) {};
  GameClientPacket191(const std::vector<std::uint8_t> &data);
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

} // namespace common
} // namespace utopia

#endif // GAME_CLIENT_PACKETS_HPP
