#ifndef AUTH_CLIENT_PACKETS_HPP
#define AUTH_CLIENT_PACKETS_HPP

#include "utopia/common/network/packets/packet_reader.hpp"

#include <glm/glm.hpp>

#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace utopia {
namespace common {

class AuthClientHeartbeat : public PacketReader {
public:
  AuthClientHeartbeat() : PacketReader(0) {};
  AuthClientHeartbeat(const std::vector<std::uint8_t> &data);
  std::uint32_t uptime;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientComputerUserInfo : public PacketReader {
public:
  AuthClientComputerUserInfo() : PacketReader(1) {};
  AuthClientComputerUserInfo(const std::vector<std::uint8_t> &data);
  std::u16string pc_username;
  std::u16string pc_name;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientGameInfo : public PacketReader {
public:
  AuthClientGameInfo() : PacketReader(2) {};
  AuthClientGameInfo(const std::vector<std::uint8_t> &data);
  std::uint32_t game_version;
  std::array<std::uint8_t, 16> hash;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket003 : public PacketReader {
public:
  AuthClientPacket003() : PacketReader(3) {};
  AuthClientPacket003(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;
  std::array<std::uint8_t, 20> field_2;
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

class AuthClientPacket004 : public PacketReader {
public:
  AuthClientPacket004() : PacketReader(4) {};
  AuthClientPacket004(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket005 : public PacketReader {
public:
  AuthClientPacket005() : PacketReader(5) {};
  AuthClientPacket005(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::array<std::uint8_t, 20> field_2;
  std::array<std::uint8_t, 20> field_3;
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

class AuthClientPacket006 : public PacketReader {
public:
  AuthClientPacket006() : PacketReader(6) {};
  AuthClientPacket006(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket007 : public PacketReader {
public:
  AuthClientPacket007() : PacketReader(7) {};
  AuthClientPacket007(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket008 : public PacketReader {
public:
  AuthClientPacket008() : PacketReader(8) {};
  AuthClientPacket008(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket009 : public PacketReader {
public:
  AuthClientPacket009() : PacketReader(9) {};
  AuthClientPacket009(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;
  std::vector<std::uint8_t> field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientChangePlayCharacter : public PacketReader {
public:
  AuthClientChangePlayCharacter() : PacketReader(10) {};
  AuthClientChangePlayCharacter(const std::vector<std::uint8_t> &data);
  std::uint32_t transaction_id;
  std::u16string character_name;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket011 : public PacketReader {
public:
  AuthClientPacket011() : PacketReader(11) {};
  AuthClientPacket011(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket012 : public PacketReader {
public:
  AuthClientPacket012() : PacketReader(12) {};
  AuthClientPacket012(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::array<std::uint8_t, 16> field_2;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket013 : public PacketReader {
public:
  AuthClientPacket013() : PacketReader(13) {};
  AuthClientPacket013(const std::vector<std::uint8_t> &data);
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

class AuthClientSetPlayerStatus : public PacketReader {
public:
  AuthClientSetPlayerStatus() : PacketReader(14) {};
  AuthClientSetPlayerStatus(const std::vector<std::uint8_t> &data);
  std::uint32_t status;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientHardwareInfo : public PacketReader {
public:
  AuthClientHardwareInfo() : PacketReader(15) {};
  AuthClientHardwareInfo(const std::vector<std::uint8_t> &data);
  std::vector<std::uint8_t> info;
  std::array<std::uint8_t, 16> hash;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket016 : public PacketReader {
public:
  AuthClientPacket016() : PacketReader(16) {};
  AuthClientPacket016(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket017 : public PacketReader {
public:
  AuthClientPacket017() : PacketReader(17) {};
  AuthClientPacket017(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket018 : public PacketReader {
public:
  AuthClientPacket018() : PacketReader(18) {};
  AuthClientPacket018(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket019 : public PacketReader {
public:
  AuthClientPacket019() : PacketReader(19) {};
  AuthClientPacket019(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket020 : public PacketReader {
public:
  AuthClientPacket020() : PacketReader(20) {};
  AuthClientPacket020(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::u16string field_2;
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

class AuthClientPacket021 : public PacketReader {
public:
  AuthClientPacket021() : PacketReader(21) {};
  AuthClientPacket021(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket022 : public PacketReader {
public:
  AuthClientPacket022() : PacketReader(22) {};
  AuthClientPacket022(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket023 : public PacketReader {
public:
  AuthClientPacket023() : PacketReader(23) {};
  AuthClientPacket023(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket024 : public PacketReader {
public:
  AuthClientPacket024() : PacketReader(24) {};
  AuthClientPacket024(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket025 : public PacketReader {
public:
  AuthClientPacket025() : PacketReader(25) {};
  AuthClientPacket025(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::array<std::uint8_t, 20> field_2;
  std::array<std::uint8_t, 20> field_3;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket026 : public PacketReader {
public:
  AuthClientPacket026() : PacketReader(26) {};
  AuthClientPacket026(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket027 : public PacketReader {
public:
  AuthClientPacket027() : PacketReader(27) {};
  AuthClientPacket027(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::array<std::uint8_t, 16> field_1;
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

class AuthClientPacket028 : public PacketReader {
public:
  AuthClientPacket028() : PacketReader(28) {};
  AuthClientPacket028(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket029 : public PacketReader {
public:
  AuthClientPacket029() : PacketReader(29) {};
  AuthClientPacket029(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket030 : public PacketReader {
public:
  AuthClientPacket030() : PacketReader(30) {};
  AuthClientPacket030(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket031 : public PacketReader {
public:
  AuthClientPacket031() : PacketReader(31) {};
  AuthClientPacket031(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::u16string field_6;
  std::u16string field_7;
  std::u16string field_8;
  std::u16string field_9;
  std::u16string field_10;
  std::u16string field_11;
  std::u16string field_12;
  std::u16string field_13;
  std::u16string field_14;
  std::u16string field_15;
  std::u16string field_16;
  std::u16string field_17;
  std::u16string field_18;
  std::u16string field_19;
  std::u16string field_20;
  std::u16string field_21;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket032 : public PacketReader {
public:
  AuthClientPacket032() : PacketReader(32) {};
  AuthClientPacket032(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::vector<std::uint8_t> field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket033 : public PacketReader {
public:
  AuthClientPacket033() : PacketReader(33) {};
  AuthClientPacket033(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket034 : public PacketReader {
public:
  AuthClientPacket034() : PacketReader(34) {};
  AuthClientPacket034(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket035 : public PacketReader {
public:
  AuthClientPacket035() : PacketReader(35) {};
  AuthClientPacket035(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket036 : public PacketReader {
public:
  AuthClientPacket036() : PacketReader(36) {};
  AuthClientPacket036(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket037 : public PacketReader {
public:
  AuthClientPacket037() : PacketReader(37) {};
  AuthClientPacket037(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::array<std::uint8_t, 16> field_5;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket038 : public PacketReader {
public:
  AuthClientPacket038() : PacketReader(38) {};
  AuthClientPacket038(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket039 : public PacketReader {
public:
  AuthClientPacket039() : PacketReader(39) {};
  AuthClientPacket039(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket040 : public PacketReader {
public:
  AuthClientPacket040() : PacketReader(40) {};
  AuthClientPacket040(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::u16string field_1;
  std::u16string field_2;
  std::u16string field_3;
  std::u16string field_4;
  std::u16string field_5;
  std::u16string field_6;
  std::u16string field_7;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientRequestInstance : public PacketReader {
public:
  AuthClientRequestInstance() : PacketReader(41) {};
  AuthClientRequestInstance(const std::vector<std::uint8_t> &data);
  std::uint32_t transaction_id;
  std::uint32_t map_type;
  std::uint32_t map_id;
  std::uint32_t region;
  std::uint32_t district;
  std::uint32_t language;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket042 : public PacketReader {
public:
  AuthClientPacket042() : PacketReader(42) {};
  AuthClientPacket042(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket043 : public PacketReader {
public:
  AuthClientPacket043() : PacketReader(43) {};
  AuthClientPacket043(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
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

class AuthClientPacket044 : public PacketReader {
public:
  AuthClientPacket044() : PacketReader(44) {};
  AuthClientPacket044(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::u16string field_6;
  std::u16string field_7;
  std::u16string field_8;
  std::u16string field_9;
  std::u16string field_10;
  std::u16string field_11;
  std::u16string field_12;
  std::u16string field_13;
  std::u16string field_14;
  std::u16string field_15;
  std::u16string field_16;
  std::u16string field_17;
  std::u16string field_18;
  std::u16string field_19;
  std::vector<std::uint32_t> field_20;
  std::vector<std::uint32_t> field_21;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket045 : public PacketReader {
public:
  AuthClientPacket045() : PacketReader(45) {};
  AuthClientPacket045(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket046 : public PacketReader {
public:
  AuthClientPacket046() : PacketReader(46) {};
  AuthClientPacket046(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket047 : public PacketReader {
public:
  AuthClientPacket047() : PacketReader(47) {};
  AuthClientPacket047(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket048 : public PacketReader {
public:
  AuthClientPacket048() : PacketReader(48) {};
  AuthClientPacket048(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket049 : public PacketReader {
public:
  AuthClientPacket049() : PacketReader(49) {};
  AuthClientPacket049(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket050 : public PacketReader {
public:
  AuthClientPacket050() : PacketReader(50) {};
  AuthClientPacket050(const std::vector<std::uint8_t> &data);
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

class AuthClientPacket051 : public PacketReader {
public:
  AuthClientPacket051() : PacketReader(51) {};
  AuthClientPacket051(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
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

class AuthClientPacket052 : public PacketReader {
public:
  AuthClientPacket052() : PacketReader(52) {};
  AuthClientPacket052(const std::vector<std::uint8_t> &data);
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

class AuthClientAskServerResponse : public PacketReader {
public:
  AuthClientAskServerResponse() : PacketReader(53) {};
  AuthClientAskServerResponse(const std::vector<std::uint8_t> &data);
  std::uint32_t transaction_id;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket054 : public PacketReader {
public:
  AuthClientPacket054() : PacketReader(54) {};
  AuthClientPacket054(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::array<std::uint8_t, 256> field_6;
  std::u16string field_7;
  std::u16string field_8;
  std::u16string field_9;
  std::u16string field_10;
  std::u16string field_11;
  std::u16string field_12;
  std::u16string field_13;
  std::u16string field_14;
  std::u16string field_15;
  std::u16string field_16;
  std::u16string field_17;
  std::u16string field_18;
  std::u16string field_19;
  std::vector<std::uint32_t> field_20;
  std::vector<std::uint32_t> field_21;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthClientPacket055 : public PacketReader {
public:
  AuthClientPacket055() : PacketReader(55) {};
  AuthClientPacket055(const std::vector<std::uint8_t> &data);
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

class AuthClientPortalAccountLogin : public PacketReader {
public:
  AuthClientPortalAccountLogin() : PacketReader(56) {};
  AuthClientPortalAccountLogin(const std::vector<std::uint8_t> &data);
  std::uint32_t transaction_id;
  std::array<std::uint8_t, 16> user_id;
  std::array<std::uint8_t, 16> session_id;
  std::u16string character_name;

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

#endif // AUTH_CLIENT_PACKETS_HPP
