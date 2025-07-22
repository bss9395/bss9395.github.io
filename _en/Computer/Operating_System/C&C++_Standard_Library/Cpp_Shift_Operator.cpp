/* Cpp_Shift_Operator.cpp
Author: bss9395
Update: 2025-07-16T19:02:00+08@China-ShangHai+08
*/

#include <iostream>
#include <string>
#include <algorithm>

std::string _ToBinary(const void* const addr, int size) {
	static const char* characters = "01";
	std::string binary = "";
	int bits = size * 8;
	int blocks = bits / 32;
	int remain = bits - blocks * 32;
	for (int block = 0; block < blocks; block += 1) {
		uint32_t memo = ((uint32_t*)addr)[block];
		for (int bit = 0; bit < 32; bit += 1) {			
			binary += characters[(memo >> bit) & 0x01];
		}
	}
	for (int bit = 0; bit < remain; bit += 1) {
		uint32_t memo = ((uint32_t*)addr)[blocks];
		binary += characters[(memo >> bit) & 0x01];
	}
	std::reverse(binary.begin(), binary.end());
	return binary;
}

std::string _ToHexadecimal(const void* const addr, int size) {
	static const char* characters = "0123456789ABCDEF";
	std::string hexadecimal = "";
	int bits = size * 8; 
	int blocks = bits / 32;       
	int remain = bits - blocks * 32;
	for (int block = 0; block < blocks; block += 1) {
		uint32_t memo = ((uint32_t*)addr)[block];
		for (int nibble = 0; nibble < 8; nibble += 1) {
			hexadecimal += characters[(memo >> (nibble * 4)) & 0x0F];
		}
	}
	for (int nibble = 0; nibble < (remain / 4); nibble += 1) {
		uint32_t memo = ((uint32_t*)addr)[blocks];
		hexadecimal += characters[(memo >> (nibble * 4)) & 0x0F];
	}
	std::reverse(hexadecimal.begin(), hexadecimal.end());
	return hexadecimal;
}

#pragma pack(1)
struct Struct {
	short _a = 1;
	char _b = 1;
};


void _Test_ToBinary() {
	int shift = -1;
	fprintf(stdout, "%d, %s\n", shift, _ToBinary(&shift, sizeof(shift)).data());
	int shiftL = shift << 2;        // shift * 4
	fprintf(stdout, "%d, %s\n", shiftL, _ToBinary(&shiftL, sizeof(shiftL)).data());
	int shiftR = shift >> 2;        // wrong result
	fprintf(stdout, "%d, %s\n", shiftR, _ToBinary(&shiftR, sizeof(shiftR)).data());
	//int shiftUR = shift >>> 2;    // wrong result
	//fprintf(stdout, "%d, %s\n", shiftUR, _ToBinary(&shiftUR, sizeof(shiftUR)).data());
}

void _Test_ToBinary_Struct() {
	Struct bulk = Struct();
	fprintf(stdout, "%s\n", _ToBinary(&bulk, sizeof(bulk)).data());
}

void _Test_ToHexadecimal() {
	int shift = -1;
	fprintf(stdout, "%d, %s\n", shift, _ToHexadecimal(&shift, sizeof(shift)).data());
	int shiftL = shift << 2;        // shift * 4
	fprintf(stdout, "%d, %s\n", shiftL, _ToHexadecimal(&shiftL, sizeof(shiftL)).data());
	int shiftR = shift >> 2;        // wrong result
	fprintf(stdout, "%d, %s\n", shiftR, _ToHexadecimal(&shiftR, sizeof(shiftR)).data());
	//int shiftUR = shift >>> 2;    // wrong result
	//fprintf(stdout, "%d, %s\n", shiftUR, _ToHexadecimal(&shiftUR, sizeof(shiftUR)).data());
}

void _Test_ToHexadecimal_Struct() {
	Struct bulk = Struct();
	fprintf(stdout, "%s\n", _ToHexadecimal(&bulk, sizeof(bulk)).data());
}

int main() {
	// _Test_ToBinary();
	_Test_ToBinary_Struct();
	// _Test_ToHexadecimal();
	// _Test_ToHexadecimal_Struct();

	return 0;
}
