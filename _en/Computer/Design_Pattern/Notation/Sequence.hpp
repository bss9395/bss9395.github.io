/*Sequence.hpp
* Author: BSS9395
* Update: 2020-01-23T20:36:00+08@ShenZhen+08
* Design: Notation
*/

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
	static int ParseNumber(char *data, Value *number, double base = 10.0) {
		char *ret = data;
		int sign = +1;
		double value = 0;

		if (data[0] == '+') {
			data += 1;
			sign = +1;
		}
		else if (data[0] == '-') {
			data += 1;
			sign = -1;
		}
		else if (data[0] == '0') {
			data += 1;
			if (data[0] == 'b' || data[0] == 'B') {
				data += 1;
				base = 2;
			}
			else if (data[0] == 'o' || data[0] == 'O') {
				data += 1;
				base = 8;
			}
			else if (data[0] == 'x' || data[0] == 'X') {
				data += 1;
				base = 16;
			}
		}
		else if (!('0' <= data[0] && data[0] <= '9' || 'a' <= data[0] && data[0] <= 'z' || 'A' <= data[0] && data[0] <= 'Z')) {
			return 0;
		}

		if (2.0 <= base && base <= 10.0) {
			char range = (char)('0' + base);
			while ('0' <= data[0] && data[0] < range) {
				value = value * base + (data[0] - '0');
				data += 1;
			}
		}
		else if (10.0 < base && base <= 36.0) {
			while (true) {
				if ('0' <= data[0] && data[0] <= '9') {
					value = value * base + (data[0] - '0' + 0);
				}
				else if ('a' <= data[0] && data[0] <= 'z') {
					value = value * base + (data[0] - 'a' + 10);
				}
				else if ('A' <= data[0] && data[0] <= 'Z') {
					value = value * base + (data[0] - 'A' + 10);
				}
				else {
					break;
				}
				data += 1;
			}
		}
		if (data[0] == '.') {
			data += 1;
			if (2.0 <= base && base <= +10.0) {
				char range = (char)('0' + base);
				double factor = 1 / base;
				while ('0' <= data[0] && data[0] < range) {
					value = value + (data[0] - '0') * factor;
					data += 1;
					factor *= factor;
				}
			}
			else if (10.0 < base && base <= 36.0) {
				double factor = 1 / base;
				while (true) {
					if ('0' <= data[0] && data[0] <= '9') {
						value = value + (data[0] - '0' + 0) * factor;
					}
					else if ('a' <= data[0] && data[0] <= 'z') {
						value = value + (data[0] - 'a' + 10) * factor;
					}
					else if ('A' <= data[0] && data[0] <= 'Z') {
						value = value + (data[0] - 'A' + 10) * factor;
					}
					else {
						break;
					}
					factor *= factor;
				}
			}
		}

		if ((data[0] == 'e' || data[0] == 'E') && base == 10.0) {
			data += 1;
			double expo = 0;
			data += ParseNumber(data, &expo, 10.0);
			value = value * pow(10, expo);
		}
		else if (data[0] == '^' && base == 10.0) {
			data += 1;
			double expo = 0;
			data += ParseNumber(data, &expo, 10.0);
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

int main(int argc, char *argv[]) {
	// testStreanline();
	// testSkips();
	// testUntil();
	testReadLine();

	return 0;
}

#endif // Main
