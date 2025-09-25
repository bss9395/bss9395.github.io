/* Cpp_Base64.cpp
Author: bss9395
Update: 2025/09/22T10:45:00+08@China-GuangDong-ZhanJiang+08
*/

#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

class Base64 {
	typedef uint8_t ui08;

public:
	static string _Encode(const string &data) {
		static ui08 encodee[64] = {
			'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
			'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
			'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '+', '*'
		};
		// index:        [3]      [2]      [1]      [0]
		// data : |        |87654321|!!!!!!!!|87654321|
		// code : |  876543|  21!!!!|  !!!!87|  654321|
		// 0x3F :                            |00111111|
		// data.size / 3 * 4 ≤ code.size < (data.size + 2) / 3 * 4
		string code = string((data.size() + 2) / 3 * 4, '\0');	
		ui08 *pdata = (ui08*)&data[0], *edata = (ui08*)&data[data.size() / 3 * 3];
		ui08 *bcode = (ui08*)&code[0], *pcode = bcode;
		while (pdata < edata) {
			pcode[0] = encodee[0x3F & (pdata[0] >> 0)];
			pcode[1] = encodee[0x3F & (pdata[0] >> 6 | pdata[1] << 2)];
			pcode[2] = encodee[0x3F & (pdata[1] >> 4 | pdata[2] << 4)];
			pcode[3] = encodee[0x3F & (pdata[2] >> 2)];
			pdata += 3;
			pcode += 4;
		}
		int remain = data.size() % 3;
		if (remain == 1) {
			pcode[0] = encodee[0x3F & (pdata[0] >> 0)];
			pcode[1] = encodee[0x3F & (pdata[0] >> 6)];
			pcode += 2;
		} else if (remain == 2) {
			pcode[0] = encodee[0x3F & (pdata[0] >> 0)];
			pcode[1] = encodee[0x3F & (pdata[0] >> 6 | pdata[1] << 2)];
			pcode[2] = encodee[0x3F & (pdata[1] >> 4)];
			pcode += 3;
		}
		code.resize(pcode - bcode);
		return code;
	}

	static string _Decode(const string &code) {
		static ui08 PHD = (ui08)-1;
		static ui08 decodee[256] = {
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,  63,  62, PHD, PHD, PHD, PHD,
			  0,   1,   2,   3,   4,   5,   6,   7,   8,   9, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,
			 25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35, PHD, PHD, PHD, PHD, PHD,
			PHD,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,
			 51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD
		};
		// index:        [3]      [2]      [1]      [0]
		// data : |        |87654321|!!!!!!!!|87654321|
		// code : |  876543|  21!!!!|  !!!!87|  654321|
		// 0x3F :                            |00111111|
		// code.size / 4 * 3 ≤ data.size < (code.size + 3) / 4 * 3
		string data = string((code.size() + 3) / 4 * 3, '\0');
		ui08 *pcode = (ui08*)&code[0], *ecode = (ui08*)&code[code.size() / 4 * 4];
		ui08 *bdata = (ui08*)&data[0], *pdata = bdata;
		while (pcode < ecode) {
			if (decodee[pcode[0]] == PHD || decodee[pcode[1]] == PHD || decodee[pcode[2]] == PHD || decodee[pcode[3]] == PHD) {
				throw "exception decode";
			}
			pdata[0] = decodee[pcode[0]] >> 0 | decodee[pcode[1]] << 6;
			pdata[1] = decodee[pcode[1]] >> 2 | decodee[pcode[2]] << 4;
			pdata[2] = decodee[pcode[2]] >> 4 | decodee[pcode[3]] << 2;
			pcode += 4;
			pdata += 3;
		}
		int remain = code.size() % 4;
		if (remain == 1) {
			throw "exception decode";
		}
		else if (remain == 2) {
			if (decodee[pcode[0]] == PHD || decodee[pcode[1]] == PHD) {
				throw "exception decode";
			}
			pdata[0] = decodee[pcode[0]] >> 0 | decodee[pcode[1]] << 6;
			pdata += 1;
		} else if (remain == 3) {
			if (decodee[pcode[0]] == PHD || decodee[pcode[1]] == PHD || decodee[pcode[2]] == PHD) {
				throw "exception decode";
			}
			pdata[0] = decodee[pcode[0]] >> 0 | decodee[pcode[1]] << 6;
			pdata[1] = decodee[pcode[1]] >> 2 | decodee[pcode[2]] << 4;
			pdata += 2;
		}
		data.resize(pdata - bdata);
		return data;
	}
};

int main() {
	string code = Base64::_Encode("bss9395@GitHub");
	cout << "[code]" + code << endl;
	string data = Base64::_Decode(code);
	cout << "[data]" + data << endl;
	return 0;
}