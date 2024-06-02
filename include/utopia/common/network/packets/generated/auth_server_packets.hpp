#ifndef AUTH_SERVER_PACKETS_HPP
#define AUTH_SERVER_PACKETS_HPP

#include "utopia/common/network/packets/packet_reader.hpp"

#include <glm/glm.hpp>

#include <array>
#include <cstdint>
#include <string>
#include <vector>


namespace utopia {
namespace core {

class AuthServerHeartbeat : public PacketReader {
public:
  AuthServerHeartbeat() : PacketReader(0) {};
  AuthServerHeartbeat(const std::vector<std::uint8_t> &data);
  std::uint32_t unknown;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthServerSessionInfo : public PacketReader {
public:
  AuthServerSessionInfo() : PacketReader(1) {};
  AuthServerSessionInfo(const std::vector<std::uint8_t> &data);
  std::uint32_t salt;
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

class AuthServerPacket002 : public PacketReader {
public:
  AuthServerPacket002() : PacketReader(2) {};
  AuthServerPacket002(const std::vector<std::uint8_t> &data);
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

class AuthServerErrorMessage : public PacketReader {
public:
  AuthServerErrorMessage() : PacketReader(3) {};
  AuthServerErrorMessage(const std::vector<std::uint8_t> &data);
  std::uint32_t transaction_id;
  std::uint32_t error_code;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthServerPacket004 : public PacketReader {
public:
  AuthServerPacket004() : PacketReader(4) {};
  AuthServerPacket004(const std::vector<std::uint8_t> &data);
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

class AuthServerPacket005 : public PacketReader {
public:
  AuthServerPacket005() : PacketReader(5) {};
  AuthServerPacket005(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthServerPacket006 : public PacketReader {
public:
  AuthServerPacket006() : PacketReader(6) {};
  AuthServerPacket006(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::array<std::uint8_t, 8> field_1;
  std::array<std::uint8_t, 8> field_2;
  std::array<std::uint8_t, 8> field_3;
  std::array<std::uint8_t, 8> field_4;
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

class AuthServerCharacterInfo : public PacketReader {
public:
  AuthServerCharacterInfo() : PacketReader(7) {};
  AuthServerCharacterInfo(const std::vector<std::uint8_t> &data);
  struct extra_character_info {
    std::uint16_t es_field_0;
    std::uint16_t last_map_id;
    std::array<char, 4> es_field_2;
    std::array<std::uint16_t, 28> es_field_3;
  };

  std::uint16_t extra_struct_data_size;

  std::uint32_t transaction_id;
  std::array<std::uint8_t, 16> uuid;
  std::uint32_t field_2;
  std::u16string name;
  extra_character_info extra_info;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthServerPacket008 : public PacketReader {
public:
  AuthServerPacket008() : PacketReader(8) {};
  AuthServerPacket008(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::array<std::uint8_t, 24> field_2;
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

class AuthServerGameServerInfo : public PacketReader {
public:
  AuthServerGameServerInfo() : PacketReader(9) {};
  AuthServerGameServerInfo(const std::vector<std::uint8_t> &data);
  std::uint32_t request;
  std::uint32_t world_id;
  std::uint32_t map_id;
  std::array<std::uint8_t, 24> host;
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

class AuthServerPacket010 : public PacketReader {
public:
  AuthServerPacket010() : PacketReader(10) {};
  AuthServerPacket010(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::array<std::uint8_t, 16> field_2;
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

class AuthServerPacket011 : public PacketReader {
public:
  AuthServerPacket011() : PacketReader(11) {};
  AuthServerPacket011(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::array<std::uint8_t, 16> field_1;
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

class AuthServerPacket012 : public PacketReader {
public:
  AuthServerPacket012() : PacketReader(12) {};
  AuthServerPacket012(const std::vector<std::uint8_t> &data);
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

class AuthServerPacket013 : public PacketReader {
public:
  AuthServerPacket013() : PacketReader(13) {};
  AuthServerPacket013(const std::vector<std::uint8_t> &data);
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

class AuthServerPacket014 : public PacketReader {
public:
  AuthServerPacket014() : PacketReader(14) {};
  AuthServerPacket014(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
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

class AuthServerPacket015 : public PacketReader {
public:
  AuthServerPacket015() : PacketReader(15) {};
  AuthServerPacket015(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthServerPacket016 : public PacketReader {
public:
  AuthServerPacket016() : PacketReader(16) {};
  AuthServerPacket016(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::array<std::uint8_t, 16> field_2;
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

class AuthServerAccountInfo : public PacketReader {
public:
  AuthServerAccountInfo() : PacketReader(17) {};
  AuthServerAccountInfo(const std::vector<std::uint8_t> &data);
  std::uint32_t transaction_id;
  std::uint32_t territory_id;
  std::uint32_t field_2;
  std::array<std::uint8_t, 8> field_3;
  std::array<std::uint8_t, 8> field_4;
  std::array<std::uint8_t, 16> account_uuid;
  std::array<std::uint8_t, 16> char_select_character_uuid;
  std::uint32_t field_7;
  std::vector<std::uint8_t> field_8;
  std::uint8_t field_9;
  std::uint32_t eula_accepted;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthServerPacket018 : public PacketReader {
public:
  AuthServerPacket018() : PacketReader(18) {};
  AuthServerPacket018(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::array<std::uint8_t, 16> field_2;
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

class AuthServerPacket019 : public PacketReader {
public:
  AuthServerPacket019() : PacketReader(19) {};
  AuthServerPacket019(const std::vector<std::uint8_t> &data);
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

class AuthServerPacket020 : public PacketReader {
public:
  AuthServerPacket020() : PacketReader(20) {};
  AuthServerPacket020(const std::vector<std::uint8_t> &data);
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

class AuthServerPacket021 : public PacketReader {
public:
  AuthServerPacket021() : PacketReader(21) {};
  AuthServerPacket021(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::array<std::uint8_t, 8> field_1;
  std::array<std::uint8_t, 8> field_2;
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

class AuthServerAccountSettings : public PacketReader {
public:
  AuthServerAccountSettings() : PacketReader(22) {};
  AuthServerAccountSettings(const std::vector<std::uint8_t> &data);
  std::uint32_t transaction_id;
  std::vector<std::uint8_t> account_settings_data;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthServerPacket023 : public PacketReader {
public:
  AuthServerPacket023() : PacketReader(23) {};
  AuthServerPacket023(const std::vector<std::uint8_t> &data);
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

class AuthServerPacket024 : public PacketReader {
public:
  AuthServerPacket024() : PacketReader(24) {};
  AuthServerPacket024(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::array<std::uint8_t, 8> field_1;
  std::array<std::uint8_t, 8> field_2;
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

class AuthServerPacket025 : public PacketReader {
public:
  AuthServerPacket025() : PacketReader(25) {};
  AuthServerPacket025(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthServerPacket026 : public PacketReader {
public:
  AuthServerPacket026() : PacketReader(26) {};
  AuthServerPacket026(const std::vector<std::uint8_t> &data);
  struct some_struct {
    std::uint8_t field_0;
    std::uint8_t field_1;
  };

  std::uint32_t field_0;
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

class AuthServerPacket027 : public PacketReader {
public:
  AuthServerPacket027() : PacketReader(27) {};
  AuthServerPacket027(const std::vector<std::uint8_t> &data);
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

class AuthServerPacket028 : public PacketReader {
public:
  AuthServerPacket028() : PacketReader(28) {};
  AuthServerPacket028(const std::vector<std::uint8_t> &data);
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

class AuthServerPacket029 : public PacketReader {
public:
  AuthServerPacket029() : PacketReader(29) {};
  AuthServerPacket029(const std::vector<std::uint8_t> &data);
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

class AuthServerPacket030 : public PacketReader {
public:
  AuthServerPacket030() : PacketReader(30) {};
  AuthServerPacket030(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
  std::uint32_t field_3;
  std::uint32_t field_4;
  std::uint32_t field_5;
  std::uint32_t field_6;
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

class AuthServerPacket031 : public PacketReader {
public:
  AuthServerPacket031() : PacketReader(31) {};
  AuthServerPacket031(const std::vector<std::uint8_t> &data);
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

class AuthServerPacket032 : public PacketReader {
public:
  AuthServerPacket032() : PacketReader(32) {};
  AuthServerPacket032(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint16_t field_1;
  std::uint8_t field_2;
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

class AuthServerPacket033 : public PacketReader {
public:
  AuthServerPacket033() : PacketReader(33) {};
  AuthServerPacket033(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint16_t field_1;
  std::uint8_t field_2;
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

class AuthServerPacket034 : public PacketReader {
public:
  AuthServerPacket034() : PacketReader(34) {};
  AuthServerPacket034(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::array<std::uint8_t, 12> field_1;

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthServerPacket035 : public PacketReader {
public:
  AuthServerPacket035() : PacketReader(35) {};
  AuthServerPacket035(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::array<std::uint8_t, 16> field_2;
  std::array<std::uint8_t, 16> field_3;
  std::array<std::uint8_t, 16> field_4;
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

class AuthServerPacket036 : public PacketReader {
public:
  AuthServerPacket036() : PacketReader(36) {};
  AuthServerPacket036(const std::vector<std::uint8_t> &data);
  std::uint32_t field_0;
  std::uint32_t field_1;
  std::uint32_t field_2;
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

class AuthServerPacket037 : public PacketReader {
public:
  AuthServerPacket037() : PacketReader(37) {};
  AuthServerPacket037(const std::vector<std::uint8_t> &data);

  std::string get_packet_name() const;

  std::string get_packet_as_printable() const;

  std::vector<std::uint8_t> get_packed_data() const;
  std::uint16_t get_packet_size() const override;

private:
  std::uint16_t packet_size = 0;

  bool parse(const std::vector<std::uint8_t> &data);

  std::vector<std::uint8_t> pack() const;
};

class AuthServerPacket038 : public PacketReader {
public:
  AuthServerPacket038() : PacketReader(38) {};
  AuthServerPacket038(const std::vector<std::uint8_t> &data);
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

} // namespace core
} // namespace utopia

#endif // AUTH_SERVER_PACKETS_HPP
