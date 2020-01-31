/*Sequence.hpp
* Author: BSS9395
* Update: 2020-02-01T01:58:00+08@ZhanJiang+08
* Design: Notation
*/

#include <stdlib.h>
#include <time.h>
#include "Pointer.hpp"

typedef const char *Endian;
namespace EType {
	static const Endian Arithmetic = "Arithmetic";
	static const Endian Cyberspace = "Cyberspace";
}

class Sequence {
public:
	static Endian Endianness() {
		Endian endian = EType::Arithmetic;
		unsigned data = 0x87654321;
		char *ptr = (char *)&data;
		if (ptr[0] == 0x21) {
			endian = EType::Arithmetic;
		}
		else if (ptr[sizeof(data) - 1] == 0x21) {
			endian = EType::Cyberspace;
		}
		return endian;
	}

	static char *Streamline(char *data, int size) {
		Endian endian = Sequence::Endianness();
		if (endian != EType::Cyberspace) {
			for (char *back = data + size - 1; data < back; data += 1, back -= 1) {
				data[0] = data[0] ^ back[0];
				back[0] = data[0] ^ back[0];
				data[0] = data[0] ^ back[0];
			}
		}
		return data;
	}

	static int Skip(char *data, int size, const char dels[] = " \t\v\f\r\n", int sz = 8) {
		int ret = 0;
		int i = 0;
		do {
			for (i = 0; ret < size && i < sz; i += 1) {
				if (data[ret] == dels[i]) {
					ret += 1;
					break;
				}
			}
		} while (i < sz);
		return ret;
	}

	static int Until(char *data, int size, const char dels[] = " \t\v\f\r\n", int sz = 8) {
		int ret = -1;
		int i = 0;

		do {
			ret += 1;
			for (i = 0; ret < size && i < sz; i += 1) {
				if (data[ret] == dels[i]) {
					break;
				}
			}
		} while (i >= sz);
		return ret;
	}



	template<typename Value>
	static int ParseNumber(const char *data, Value *number, double base = 10.0) {
		static const char PHD = '?';
		static const char SYM[128] = {
			'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			' ', PHD, PHD, PHD, PHD, PHD, PHD, PHD,	'(', ')', '*', '+', PHD, '-', '.', '/',
			  0,   1,	2,   3,   4,   5,   6,   7,   8,   9, PHD, PHD,	PHD, PHD, PHD, PHD,
			PHD,  10,  11,  12,  13,  14,  15, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, '^', PHD,
			PHD,  10,  11,  12,  13,  14,  15, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD
		};

		const char *ret = data;
		char sign = +1;
		double value = 0.0;

		while (data[0] == ' ') {
			data += 1;
		}

		if (data[0] == '(') {
			data += 1;
			data += ParseExpression(data, &value, base);
			if (data[0] != ')') {
				throw ')';
			}
			data += 1;
		}
		else if (data[0] == '+') {
			data += 1;
			sign = +1;
		}
		else if (data[0] == '-') {
			data += 1;
			sign = -1;
		}

		if (data[0] == '0') {
			data += 1;
			if (data[0] == 'b' || data[0] == 'B') {
				data += 1;
				base = 2.0;
			}
			else if (data[0] == 'o' || data[0] == 'O') {
				data += 1;
				base = 8.0;
			}
			else if (data[0] == 'x' || data[0] == 'X') {
				data += 1;
				base = 16.0;
			}
		}

		char num = 0;
		while (num = SYM[data[0]], 0 <= num && num <= base) {
			data += 1;
			value = value * base + num;
		}
		if (data[0] == '.') {
			data += 1;
			double fact = 1 / base;
			while (num = SYM[data[0]], 0 <= num && num <= base) {
				data += 1;
				value = value + num * fact;
				fact *= fact;
			}
		}

		if (data[0] == '^') {
			data += 1;
			double expo = 0.0;
			data += ParseNumber(data, &expo, base);
			value = pow(value, expo);
		}

		*number = (Value)(sign * value);
		return (int)(data - ret);
	}

	template<typename Value>
	static int ParseNumberArray(char *data, Value *numbers, double base = 10.0) {
		char *ret = data;
		int len = 0;
		while (len = ParseNumber(data, numbers, base), len != 0) {
			data += len;
			numbers += 1;

			while (data[0] == ',' || data[0] == ' ' || data[0] == '\t' || data[0] == '\v' || data[0] == '\f' || data[0] == '\r') {
				data += 1;
			}
			if (data[0] == ';') {
				break;
			}
		}

		return (int)(data - ret);
	}

	template<typename Value>
	int ParseTerm(const char *data, Value *number, double base = 10.0) {
		const char *ret = data;
		double lhs = 0.0;
		double rhs = 0.0;

		data += ParseNumber(data, &lhs);
		for (char op = data[0]; op == '*' || op == '/'; op = data[0]) {
			data += 1;
			data += ParseNumber(data, &rhs, base);
			if (op == '*') {
				lhs *= rhs;
			}
			else if (op == '/') {
				lhs /= rhs;
			}
		}

		*number = (Value)lhs;
		return (int)(data - ret);
	}

	template<typename Value>
	int ParseExpression(const char *data, Value *number, double base = 10.0) {
		const char *ret = data;
		double lhs = 0.0;
		double rhs = 0.0;

		data += ParseTerm(data, &lhs);
		for (char op = data[0]; op == '+' || op == '-'; op = data[0]) {
			data += 1;
			data += ParseTerm(data, &rhs);
			if (op == '+') {
				lhs += rhs;
			}
			else if (op == '-') {
				lhs -= rhs;
			}
		}

		*number = (Value)lhs;
		return (int)(data - ret);
	}




	template<typename Value>
	static int printNumber(char *buffer, Value *number, double base = 10.0, double precision = 8.0) {
		char *ret = buffer;

		double rational = *number;
		if (rational < 0) {
			buffer[0] = '-';
			buffer += 1;

			rational *= -1;
		}

		unsigned long long integer = (unsigned long long)rational;
		rational -= integer;

		if (base == 2.0) {
			buffer[0] = '0';
			buffer[1] = 'b';
			buffer += 2;
		}
		else if (base == 8.0) {
			buffer[0] = '0';
			buffer[1] = 'o';
			buffer += 2;
		}
		else if (base == 16.0) {
			buffer[0] = '0';
			buffer[1] = 'x';
			buffer += 2;
		}

		char *fore = buffer;
		int factor = (int)base;
		char ch = '\0';
		while (integer) {
			ch = (char)(integer % factor);
			buffer[0] = ch < 10 ? ch + '0' : ch + 'A' - 10;
			buffer += 1;
			integer = integer / factor;
		}

		for (char *back = buffer - 1; fore < back; fore += 1, back -= 1) {
			fore[0] = fore[0] ^ back[0];
			back[0] = fore[0] ^ back[0];
			fore[0] = fore[0] ^ back[0];
		}

		if (rational != 0.0) {
			buffer[0] = '.';
			buffer += 1;

			rational += 0.5 * pow(1 / base, precision);
			while (rational *= base, precision -= 1, rational >= 1 && precision >= 0) {
				ch = (char)rational;
				buffer[0] = ch < 10 ? ch + '0' : ch + 'A' - 10;
				buffer += 1;
				rational -= ch;
			}
		}

		return (int)(buffer - ret);
	}

	template<typename Value>
	static int printNumberArray(char *buffer, Value *numbers, int count, double base = 10.0, double precision = 8.0) {
		char *ret = buffer;
		while (count > 0) {
			if (ret != buffer) {
				buffer[0] = ',';
				buffer[1] = ' ';
				buffer += 2;
			}
			buffer += Sequence::printNumber(buffer, numbers, base, precision);
			numbers += 1;
			count -= 1;
		}
		return (int)(buffer - ret);
	}

	static int ParseRawBuf(char *data, char *buffer) {
		char *ret = data;
		while (data[0] != ';' && data[1] != ';') {
			if ('0' <= data[0] && data[0] <= '9') {
				buffer[0] = (data[0] - '0' + 0) << 4;
			}
			else if ('a' <= data[0] && data[0] <= 'z') {
				buffer[0] = (data[0] - 'a' + 10) << 4;
			}
			else if ('A' <= data[0] && data[0] <= 'Z') {
				buffer[0] = (data[0] - 'A' + 10) << 4;
			}
			else {
				break;
			}

			if ('0' <= data[1] && data[1] <= '9') {
				buffer[0] |= (data[1] - '0' + 0);
			}
			else if ('a' <= data[1] && data[1] <= 'z') {
				buffer[0] |= (data[1] - 'a' + 10);
			}
			else if ('A' <= data[1] && data[1] <= 'Z') {
				buffer[0] |= (data[1] - 'A' + 10);
			}
			else {
				break;
			}

			buffer += 1;
			data += 2;
		}
		return (int)(data - ret);
	}

	static int printRawBuf(char *buffer, int size, char *data) {
		char *ret = buffer;

		unsigned char ch = '\0';
		while (size > 0) {
			ch = (buffer[0] >> 4) & 0x0F;
			data[0] = ch < 10 ? ch + '0' : ch + 'A' - 10;

			ch = (buffer[0] >> 0) & 0x0F;
			data[1] = ch < 10 ? ch + '0' : ch + 'A' - 10;

			buffer += 1;
			data += 2;
			size -= 1;
		}

		return (int)(buffer - ret);
	}

	static Pointer<char> ReadFile(FILE *file) {
		fseek(file, 0, SEEK_END);
		int length = ftell(file);
		char *buffer = new char[length + 1];
		Pointer<char> ret(buffer, length + 1, buffer);

		rewind(file);
		length = fread(ret, sizeof(char), length, file);
		buffer[length] = '\0';
		return ret;
	}

	static int ReadLine(FILE *file, Pointer<char> &line, Pointer<char> &buffer, const char del = '\n') {
		int ret = 1;
		while (true) {
			if (buffer.offset() <= 0) {
				int cap = buffer.capacity();
				int len = fread(buffer, sizeof(char), cap, file);
				if (len <= 0) {
					// cerr << __FUNCTION__ << "#errno = " << errno << endl;
					line[0] = '\0';
					ret = -1;
					break;
				}
				else if (len < cap) {
					buffer.capacity(len);
					ret = 0;
				}
			}

			while (buffer.size() > 0 && buffer[0] != del) {
				line[0] = buffer[0];
				line += 1;
				buffer += 1;
			}

			if (buffer.size() <= 0) {
				buffer.reset();
				if (ret <= 0) {
					line[0] = '\0';
					ret = 0;
					break;
				}
			}
			else if (buffer[0] == del) {
				line[0] = del;
				line += 1;
				buffer += 1;

				line[0] = '\0';
				ret = +1;
				break;
			}
		}
		line.reset();
		return ret;
	}

	unsigned char *Base64_Encode(const unsigned char data[], int length) {
		static const unsigned char BASE64_MAP[64] = {
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
			'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
			'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
			'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
			'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
			'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
			'w', 'x', 'y', 'z', '0', '1', '2', '3',
			'4', '5', '6', '7', '8', '9', '+', '/',
		};

		typedef unsigned char Code[4];
		typedef unsigned char Data[3];

		int len = (length + 2) / 3 * 4;
		unsigned char *ret = (unsigned char *)malloc(sizeof(unsigned char) * len + 1);

		Code *cod = (Code *)ret;
		Data *dat = (Data *)data;
		Data *end = dat + length / 3;
		for (; dat < end; cod += 1, dat += 1) {
			(*cod)[0] = BASE64_MAP[0x3F & ((*dat)[0] >> 2)];
			(*cod)[1] = BASE64_MAP[0x3F & ((*dat)[0] << 4 | (*dat)[1] >> 4)];
			(*cod)[2] = BASE64_MAP[0x3F & ((*dat)[1] << 2 | (*dat)[2] >> 6)];
			(*cod)[3] = BASE64_MAP[0x3F & ((*dat)[2] << 0)];
		}

		if (length % 3 == 1) {
			(*cod)[0] = BASE64_MAP[0x3F & ((*dat)[0] >> 2)];
			(*cod)[1] = BASE64_MAP[0x3F & ((*dat)[0] << 4)];
			(*cod)[2] = '=';
			(*cod)[3] = '=';
		}
		else if (length % 3 == 2) {
			(*cod)[0] = BASE64_MAP[0x3F & ((*dat)[0] >> 2)];
			(*cod)[1] = BASE64_MAP[0x3F & ((*dat)[0] << 4 | (*dat)[1] >> 4)];
			(*cod)[2] = BASE64_MAP[0x3F & ((*dat)[1] << 2)];
			(*cod)[3] = '=';
		}

		ret[len] = '\0';
		return ret;
	}

	unsigned char *Base64_Decode(const unsigned char code[], int length) {
		static const unsigned char PHD = '?';
		static const unsigned char BASE64_INV[128] = {
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,  62, PHD, PHD, PHD,  63,
			 52,  53,  54,  55,  56,  57,  58,  59,	 60,  61, PHD, PHD, PHD, PHD, PHD, PHD,
			PHD,   0,	1,   2,   3,   4,   5,   6,	  7,   8,   9,  10,  11,  12,  13,  14,
			 15,  16,  17,  18,  19,  20,  21,  22,	 23,  24,  25, PHD, PHD, PHD, PHD, PHD,
			PHD,  26,  27,  28,  29,  30,  31,  32,	 33,  34,  35,  36,  37,  38,  39,  40,
			 41,  42,  43,  44,  45,  46,  47,  48,	 49,  50,  51, PHD, PHD, PHD, PHD, PHD
		};

		typedef unsigned char Data[3];
		typedef unsigned char Code[4];

		// Check(length % 4 != 0, __FILE__, __LINE__, __FUNCTION__, errno, "length % 4 != 0");
		int len = length / 4 * 3;
		len -= ((code[length - 2] == '=') ? 2 : ((code[length - 1] == '=') ? 1 : 0));
		unsigned char *ret = (unsigned char *)malloc(sizeof(unsigned char) * len + 1);

		Data *dat = (Data *)ret;
		Code *cod = (Code *)code;
		Code *end = cod + length / 4;
		for (; cod < end; dat += 1, cod += 1) {
			(*dat)[0] = BASE64_INV[(*cod)[0]] << 2 | BASE64_INV[(*cod)[1]] >> 4;
			(*dat)[1] = BASE64_INV[(*cod)[1]] << 4 | BASE64_INV[(*cod)[2]] >> 2;
			(*dat)[2] = BASE64_INV[(*cod)[2]] << 6 | BASE64_INV[(*cod)[3]] >> 0;
		}

		if (code[length - 2] == '=') {
			(*dat)[0] = BASE64_INV[(*cod)[0]] << 2 | BASE64_INV[(*cod)[1]] >> 4;
		}
		else if (code[length - 1] == '=') {
			(*dat)[0] = BASE64_INV[(*cod)[0]] << 2 | BASE64_INV[(*cod)[1]] >> 4;
			(*dat)[1] = BASE64_INV[(*cod)[1]] << 4 | BASE64_INV[(*cod)[2]] >> 2;
		}

		ret[len] = '\0';
		return ret;
	}

	char *RandomString(int length = 16) {
		static const unsigned char SYM[90] = {
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',	'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		'0', '1', '2', '3',	'4', '5', '6', '7', '8', '9',
		'!', '#', '$', '%', '&', '(', ')', '*', '+', ',', '-', '.', '/', ':',
		';', '<', '=', '>', '?', '@', '[', ']', '^', '_', '{', '|', '}', '~'
		};
		static auto Seed = [](unsigned hint) -> unsigned {
			static unsigned long long prep = 0;
			static unsigned long long post = 1;
			post = prep + post;
			prep = post - prep;
			return (unsigned)(time(NULL) * hint + post % 9395);
		};

		srand(Seed(length));

		char *ret = (char *)malloc(sizeof(char) * length + 1);
		for (int i = 0; i < length; i += 1) {
			ret[i] = SYM[rand() % sizeof(SYM)];
		}

		ret[length] = '\0';
		return ret;
	}
};


// #define Main
#ifdef Main

void testStreamline() {
	unsigned data = 0x87654321;
	Sequence::Streamline((char *)&data, sizeof(unsigned));
	fprintf(stderr, "%x\n", data);
}

void testSkips() {
	char data[] = "01234""\0""6789#";
	int len = Sequence::Skip(data, sizeof(data) / sizeof(data[0]), "\0""0123456789", 12);
	fprintf(stderr, "%d\n", len);
}

void testUntil() {
	char data[] = "01234""\0""6789#";
	int len = Sequence::Until(data, sizeof(data) / sizeof(data[0]), "\0""#,;\n", 6);
	fprintf(stderr, "%d\n", len);
}

void testReadLine() {
	FILE *file = fopen("tmp.txt", "rb+");
	Pointer<char> buffer(new char[128], 128);
	Pointer<char> line(new char[128], 128);

	int res = 0;
	while (res = Sequence::ReadLine(file, line, buffer, '\n'), 0 <= res) {
		cerr << (char *)line;
	}
}

void testParsePrintRawBuf() {
	char buffer[128] = { '\0' };
	unsigned int a = 0x87654321;
	printRawBuf((char *)&a, 4, buffer);
	fprintf(stderr, "%s\n", buffer);

	char data[128] = "21436587; ";
	unsigned int b = 0;
	ParseRawBuf(data, (char *)&b);
	fprintf(stderr, "a = %u, b = %u\n", a, b);
}

int main(int argc, char *argv[]) {
	// testStreanline();
	// testSkips();
	// testUntil();
	// testReadLine();
	testParsePrintRawBuf();

	return 0;
}

#endif // Main
