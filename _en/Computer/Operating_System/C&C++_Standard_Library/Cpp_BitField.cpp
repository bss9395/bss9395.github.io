/* Cpp_BitField.cpp
Author: bss9395
Update: 2024-09-05T22:06:45:00+08@China-Beijing+08
*/

#include <iostream>
#include <bitset>

typedef uint8_t  ui01;      //   8=2**3=8*1
typedef uint16_t ui02;      //  16=2**4=8*2
typedef uint32_t ui04;      //  32=2**5=8*4
typedef uint64_t ui08;      //  64=2**6=8*8
// typedef uint128_t ui16;  // 128=2**7=8*16

typedef uint8_t  uin3;      //   8=2**3=8*1
typedef uint16_t uin4;      //  16=2**4=8*2
typedef uint32_t uin5;      //  32=2**5=8*4
typedef uint64_t uin6;      //  64=2**6=8*8
// typedef uint128_t uin7;  // 128=2**7=8*16


#pragma pack(1)  // 内存连续不断分布
void _BitField_LittleEndian() {
	union Struct {
		struct Pack {
			uin3 _u0 = 0;
			uin3 _u1 = 0;
			uin3 _u2 = 0;
			uin3 _u3 = 0;
		};
		struct Field {
			uin5 _b04_b00 : 5;
			uin5 _b08_b05 : 4;
			uin5 _b31_b09 : 23;
		};

		Pack _pack;
		Field _field;
		uin3 _array[4];

		explicit Struct() {
			memset(this, '\0', sizeof(Struct));
		}
	};

	///////////////////////////////////////
	// ASCII         '4'       '3'       '2'       '1'       '0'
	// #b      00110100, 00110011, 00110010, 00110001, 00110000 
	// #d            52,       51,       50,       49,       48
	// #x            34,       33,       32,       31,       30
	// _pack        _u4,      _u3,      _u2,      _u1,      _u0
	// _field      _b32,     _b24,     _b16,     _b08,     _b00
	// _array      

	Struct endian;
	Struct cells[8];
	std::memcpy(&endian, "0123456789abcdefghijklmnopqrstuvwxyz", sizeof(Struct)   );
	std::memcpy(&cells , "0123456789abcdefghijklmnopqrstuvwxyz", sizeof(Struct[8]));

	std::fprintf(stdout, R"!([%8p] endian._pack._u0               =    '%c')!""\n", &(endian._pack._u0)      , endian._pack._u0          );  //    '0'
	std::fprintf(stdout, R"!([%8p] endian._pack._u3               =    '%c')!""\n", &(endian._pack._u3)      , endian._pack._u3          );  //    '3'
	std::fprintf(stdout, R"!([%8u] endian._field._b04_b00         =    %u  )!""\n", 0                        , endian._field._b04_b00    );  //    16
	std::fprintf(stdout, R"!([%8u] endian._field._b08_b05         =     %u )!""\n", 5                        , endian._field._b08_b05    );  //     9
	std::fprintf(stdout, R"!([%8p] endian._array[0]               =    '%c')!""\n", &(endian._array[0])      , endian._array[0]          );  //    '0'
	std::fprintf(stdout, R"!([%8p] endian._array[3]               =    '%c')!""\n", &(endian._array[3])      , endian._array[3]          );  //    '3'
	std::fprintf(stdout, R"!([%8p] *(uin4 *)&(cells[0]._pack._u3) = %u     )!""\n", &(cells[0]._pack._u3), *(uin4 *)&(cells[0]._pack._u3));  // 13363
	std::fprintf(stdout, R"!([%8p] *(uin4 *)&(cells[0]._pack._u3) =  %x    )!""\n", &(cells[0]._pack._u3), *(uin4 *)&(cells[0]._pack._u3));  //  3433
	std::fprintf(stdout, R"!([%8p] *(uin4 *)&(cells[3]._pack._u3) = %u     )!""\n", &(cells[3]._pack._u3), *(uin4 *)&(cells[3]._pack._u3));  // 26470
	std::fprintf(stdout, R"!([%8p] *(uin4 *)&(cells[3]._pack._u3) =  %x    )!""\n", &(cells[3]._pack._u3), *(uin4 *)&(cells[3]._pack._u3));  //  6766
}

// Notice that modifying a single bit may have effects on an undetermined number of other bits in the bitset, thus rendering concurrent access/modification of different bits not thread-safe.
void _bitset_LittleEndian() {
	std::bitset<16> field;
	field[1] = 1;
	field[2] = 1;
	fprintf(stdout, "field = 0b%s\n", field.to_string().data());
	fprintf(stdout, "field = 0d%u\n", field.to_ulong());

	std::bitset<16> number(0xbeef);
	std::bitset<16> binary("1100");
	fprintf(stdout, "number = 0b%s\n", number.to_string().data());
	fprintf(stdout, "binary = 0b%s\n", binary.to_string().data());
}

int main(int argc, char *argv[]) {
	_BitField_LittleEndian();
	// _bitset_LittleEndian();

	return 0;
}
#pragma pack()  // 恢复内存默认对齐，x86内存默认以32bits对齐，x64内存默认以64bits对齐。