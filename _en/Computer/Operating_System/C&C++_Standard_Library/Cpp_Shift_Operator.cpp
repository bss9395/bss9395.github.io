/* Cpp_Shift_Operator.cpp
Author: bss9395
Update: 2025-07-16T19:02:00+08@China-ShangHai+08
*/

#include <iostream>
#include <string>
#include <algorithm>

std::string _IntoBinary(const void* const addr, int size) {
	typedef uint8_t  ui08;
	typedef uint32_t ui32;
	static const ui08 encodee[64] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
		'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
		'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '+', '*'
	};
	std::string binary = "";
	int bits = size * 8;
	int blocks = bits / 32;
	int remain = bits - blocks * 32;
	for (int block = 0; block < blocks; block += 1) {
		ui32 memo = ((ui32*)addr)[block];
		for (int bit = 0; bit < 32; bit += 1) {
			binary += encodee[(memo >> bit) & 0x01];
		}
	}
	for (int bit = 0; bit < remain; bit += 1) {
		ui32 memo = ((ui32*)addr)[blocks];
		binary += encodee[(memo >> bit) & 0x01];
	}
	std::reverse(binary.begin(), binary.end());
	return binary;
}

std::string _IntoHexadecimal(const void* const addr, int size) {
	typedef uint8_t  ui08;
	typedef uint32_t ui32;
	static const ui08 encodee[64] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
		'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
		'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '+', '*'
	};
	std::string hexadecimal = "";
	int bits = size * 8;
	int blocks = bits / 32;
	int remain = bits - blocks * 32;
	for (int block = 0; block < blocks; block += 1) {
		ui32 memo = ((ui32*)addr)[block];
		for (int nibble = 0; nibble < 8; nibble += 1) {
			hexadecimal += encodee[(memo >> (nibble * 4)) & 0x0F];
		}
	}
	for (int nibble = 0; nibble < (remain / 4); nibble += 1) {
		ui32 memo = ((ui32*)addr)[blocks];
		hexadecimal += encodee[(memo >> (nibble * 4)) & 0x0F];
	}
	std::reverse(hexadecimal.begin(), hexadecimal.end());
	return hexadecimal;
}

long _FromString(std::string binary, long base = 2) {
	typedef uint8_t ui08;
	static const ui08 hold = (ui08)-1;
	static const ui08 decodee[256] = {
		hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold,
		hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold,
		hold, hold, hold, hold, hold, hold, hold, hold, hold, hold,   63,   62, hold, hold, hold, hold,
		   0,    1,    2,    3,    4,    5,    6,    7,    8,    9, hold, hold, hold, hold, hold, hold,
		hold,   10,   11,   12,   13,   14,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
		  25,   26,   27,   28,   29,   30,   31,   32,   33,   34,   35, hold, hold, hold, hold, hold,
		hold,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,   48,   49,   50,
		  51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61, hold, hold, hold, hold, hold,
		hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold,
		hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold,
		hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold,
		hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold,
		hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold,
		hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold,
		hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold,
		hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold, hold
	};

	long integer = 0;
	long factor = 1;
	std::reverse(binary.begin(), binary.end());
	for (long i = 0; i < binary.size(); i += 1) {
		integer += decodee[binary[i]] * factor;
		factor *= base;
	}
	return integer;
}

#pragma pack(1)
struct Struct {
	short _a = 1;
	char _b = 1;
};


void _Test_ToBinary() {
	int shift = -1;
	fprintf(stdout, "%d, %s\n", shift, _IntoBinary(&shift, sizeof(shift)).data());
	int shiftL = shift << 2;        // shift * 4
	fprintf(stdout, "%d, %s\n", shiftL, _IntoBinary(&shiftL, sizeof(shiftL)).data());
	int shiftR = shift >> 2;        // wrong result
	fprintf(stdout, "%d, %s\n", shiftR, _IntoBinary(&shiftR, sizeof(shiftR)).data());
	//int shiftUR = shift >>> 2;    // wrong result
	//fprintf(stdout, "%d, %s\n", shiftUR, _ToBinary(&shiftUR, sizeof(shiftUR)).data());
}

void _Test_ToBinary_Struct() {
	Struct bulk = Struct();
	fprintf(stdout, "%s\n", _IntoBinary(&bulk, sizeof(bulk)).data());
}

void _Test_ToHexadecimal() {
	int shift = -1;
	fprintf(stdout, "%d, %s\n", shift, _IntoHexadecimal(&shift, sizeof(shift)).data());
	int shiftL = shift << 2;        // shift * 4
	fprintf(stdout, "%d, %s\n", shiftL, _IntoHexadecimal(&shiftL, sizeof(shiftL)).data());
	int shiftR = shift >> 2;        // wrong result
	fprintf(stdout, "%d, %s\n", shiftR, _IntoHexadecimal(&shiftR, sizeof(shiftR)).data());
	//int shiftUR = shift >>> 2;    // wrong result
	//fprintf(stdout, "%d, %s\n", shiftUR, _ToHexadecimal(&shiftUR, sizeof(shiftUR)).data());
}

void _Test_ToHexadecimal_Struct() {
	Struct bulk = Struct();
	fprintf(stdout, "%s\n", _IntoHexadecimal(&bulk, sizeof(bulk)).data());
}

void _Test_FromString() {
	short positive = (short)+253;
	char  truncate = (char)positive;
	short negative = (short)-253;
	char  cutoff   = (char)negative;

	std::cout << _IntoBinary(&positive, sizeof(positive)) << ", " << (int)positive << std::endl;
	std::cout << _IntoBinary(&truncate, sizeof(truncate)) << ", " << (int)truncate << std::endl;
	std::cout << _IntoBinary(&negative, sizeof(negative)) << ", " << (int)negative << std::endl;
	std::cout << _IntoBinary(&cutoff  , sizeof(cutoff))   << ", " << (int)cutoff   << std::endl;
	std::cout << _FromString("11111101", 2) << std::endl;
	std::cout << _FromString("00000011", 2) << std::endl;
}

int main() {
	// _Test_ToBinary();
	// _Test_ToBinary_Struct();
	// _Test_ToHexadecimal();
	// _Test_ToHexadecimal_Struct();
	_Test_FromString();

	return 0;
}
