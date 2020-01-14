/*Notation.hpp
* Author: Bss9395
* Update: 2020-01-14T18:48:00+08@ShenZhen+08
* Design: Notation
*/

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
using ::printf;
using ::sprintf;
using ::snprintf;
using ::fprintf;

#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>
using std::type_info;
using std::cout;
using std::cerr;
using std::endl;
using std::flush;
using std::iostream;
using std::stringstream;
using std::fstream;
using std::string;
using std::vector;

#include "Pointer.hpp"

namespace Config {
	static const long _BUFFER_SIZE = 1024 * 8;
	static const long _NOTATION_COUNT = 512;
}

typedef int8_t  int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef float   rat32;
typedef double  rat64;

typedef unsigned short TypeID;
typedef unsigned short SizeID;
typedef unsigned int Define;
typedef unsigned int Operation;
namespace EType {
	static const TypeID _BIT = 1U << 15;
	static const TypeID _INT = _BIT | (1U << 14);
	static const TypeID _RAT = _BIT | (1U << 13);
	static const TypeID _INT8 = _INT | 8U;
	static const TypeID _INT16 = _INT | 16U;
	static const TypeID _INT32 = _INT | 32U;
	static const TypeID _INT64 = _INT | 64U;
	static const TypeID _RAT32 = _RAT | 32U;
	static const TypeID _RAT64 = _RAT | 64U;
	static const TypeID _RAWBUF = _BIT | 1U;
	static const TypeID _RAWSTR = _BIT | 2U;
	static const TypeID _STRING = _BIT | 3U;

	static const Operation _PUSHUP = (1U << 0);
	static const Operation _APPEND = (1U << 1);
	static const Operation _OCCUPY = (1U << 2);
	static const Operation _REMOVE = (1U << 3);
	static const Operation _PURIFY = (1U << 4);
	static const Operation _BACKPACK = (1U << 5);
	static const Operation _ASSEMBLE = (1U << 6);
	static const Operation _DESCRIPT = (1U << 7);
}

class Element {
public:
	Element()
		: _type(TypeID()), _value(nullptr), _next(nullptr) {
		// cerr << __FUNCTION__ << endl;
	}

	template<typename Value>
	Element(const Value *value, const TypeID &type = EType::_RAWSTR, const SizeID &size = sizeof(Value), const Pointer<Element> &next = nullptr)
		: _type(type), _value(new char[size], size), _next(next) {
		fprintf(stderr, "typeid(Value) = %s, value = %s, type = %04x, size = %d\n", typeid(Value).name(), (char *)value, type, size);
		memcpy((char *)_value, (char *)value, size);
		// cerr << __FUNCTION__ << endl;
	}

	virtual ~Element() {
		// cerr << __FUNCTION__ << endl;
	}

public:
	template<typename Value>
	int pushup(const Value *value, const TypeID &type, const SizeID &size = sizeof(Value)) {
		cerr << __FUNCTION__ << endl;
		int ret = 0;
		_next = new Element(value, type, size, _next);
		ret += 1;
		return ret;
	}

	template<typename Value>
	int append(const Value *value, const TypeID &type, const SizeID &size = sizeof(Value)) {
		cerr << __FUNCTION__ << endl;
		int ret = 0;
		Element *iter = this;
		while (iter->_next != nullptr) {
			iter = iter->_next;
		}
		iter->_next = new Element(value, type, size, nullptr);
		ret += 1;
		return ret;
	}

	template<typename Value>
	int occupy(const Value *value, const TypeID &type, const SizeID &size = sizeof(Value)) {
		cerr << __FUNCTION__ << endl;
		int ret = 0;
		_next = new Element(value, type, size, nullptr);
		return ret;
	}

	template<typename Value>
	int remove(const Value *value, const TypeID &type, const SizeID &size = sizeof(Value)) {
		cerr << __FUNCTION__ << endl;
		int ret = 0;
		Element *iter = this;
		while (iter->_next != nullptr) {
			Element &element = *(iter->_next);
			bool cond1 = (type == element._type && size == element._value.length());
			bool cond2 = (type == EType::_RAW && size >= element._value._length());
			if (cond1 || cond2) {
				if (0 == memcmp((char *)value, (char *)element._value, element._value.length())) {
					iter->_next = iter->_next->_next;
					ret += 1;
					continue;
				}
			}
			iter = iter->_next;
		}
		return ret;
	}

	template<typename Value>
	int obtain(Value *value, TypeID &type, SizeID &&size = sizeof(Value), const int &index = 0) {
		cerr << __FUNCTION__ << endl;
		int ret = 0;

		Element *iter = this;
		long idx = 0;
		while (iter->_next != nullptr && idx < index) {
			iter = iter->_next;
			idx += 1;
		}

		if (iter->_next != nullptr && idx == index) {
			Element &element = *(iter->_next);
			bool cond1 = (type == element._type && size == element._value.length());
			bool cond2 = (type == EType::_RAW && size >= element._value._length());
			if (cond1 || cond2) {
				memcpy((char *)value, (char *)element._value, element._value.length());
				type = element._type;
				size = element._value.length();
				ret += 1;
			}
		}
		return ret;
	}

	long format(Pointer<char> &buffer, const Operation &opera = EType::_DESCRIPT) {
		cerr << __FUNCTION__ << endl;
		Pointer<char> ret = buffer;
		bool desc = (0 != (opera & EType::_DESCRIPT));

		for (Element *iter = this; iter->_next != nullptr; iter = iter->_next) {
			Pointer<char> address = buffer;
			if (desc) {
				buffer += 8 + 1;
			}

			Element &element = *(iter->_next);
			if (element._type == EType::_INT8) {
				int8 *ptr = (int8 *)element._value;
				for (int i = 0, len = element._value.length() / 8U; i < len; i += 1) {
					buffer += sprintf(buffer, (i == 0 ? "%lld" : ", %lld"), (long long)ptr[i]);
				}
			}
			else if (element._type == EType::_INT16) {
				int16 *ptr = (int16 *)element._value;
				for (int i = 0, len = element._value.length() / 16U; i < len; i += 1) {
					buffer += sprintf(buffer, (i == 0 ? "%lld" : ", %lld"), (long long)ptr[i]);
				}
			}
			else if (element._type == EType::_INT32) {
				int32 *ptr = (int32 *)element._value;
				for (int i = 0, len = element._value.length() / 32U; i < len; i += 1) {
					buffer += sprintf(buffer, (i == 0 ? "%lld" : ", %lld"), (long long)ptr[i]);
				}
			}
			else if (element._type == EType::_INT64) {
				int64 *ptr = (int64 *)element._value;
				for (int i = 0, len = element._value.length() / 64U; i < len; i += 1) {
					buffer += sprintf(buffer, (i == 0 ? "%lld" : ", %lld"), (long long)ptr[i]);
				}
			}
			else if (element._type == EType::_RAT32) {
				rat32 *ptr = (rat32 *)element._value;
				for (int i = 0, len = element._value.length() / 32U; i < len; i += 1) {
					buffer += sprintf(buffer, (i == 0 ? "%lf" : ", %lf"), (double)ptr[i]);
				}
			}
			else if (element._type == EType::_RAT64) {
				rat64 *ptr = (rat64 *)element._value;
				for (int i = 0, len = element._value.length() / 64U; i < len; i += 1) {
					buffer += sprintf(buffer, (i == 0 ? "%lf" : ", %lf"), (double)ptr[i]);
				}
			}
			else if (element._type == EType::_RAWBUF) {
				unsigned char*ptr = (unsigned char*)element._value;
				for (int i = 0, len = element._value.length() / sizeof(unsigned char); i < len; i += 1) {
					buffer += sprintf(buffer, "%X", ptr[i]);
				}
			}
			else if (element._type == EType::_RAWSTR) {
				char *ptr = (char *)element._value;
				// buffer += sprintf(buffer, "%s", ptr);
				memcpy(buffer, ptr, element._value.length());
				buffer += element._value.length();
			}
			else {
				void *ptr = (void *)element._value;
				memcpy(buffer, ptr, sizeof(char) * element._value.length());
				buffer += element._value.length();
			}

			buffer += sprintf(buffer, "%s", "; ");
			if (desc) {
				Define define = (element._type << 16) | (SizeID)(buffer - address);
				sprintf(address, "%*.*x", 8, 8, define);
				address[8] = '#';
			}
		}
		return (long)(buffer - ret);
	}

public:
	TypeID _type;
	Pointer<char> _value;
	Pointer<Element> _next;
};

class Notation {
public:
	Notation(const string &key = string())
		: _key(key), _values(Element()), _next(nullptr) {
		cerr << __FUNCTION__ << endl;
	}

	virtual ~Notation() {
		cerr << __FUNCTION__ << endl;
	}

public:
	template<typename Value>
	int attach(const string &key, const Value *value, const TypeID &type, const SizeID &size = sizeof(Value), const Operation &opera = EType::_PUSHUP) {
		cerr << __FUNCTION__ << endl;
		int ret = 0;
		Notation *iter = this;
		while (iter->_next != nullptr && key != iter->_next->_key) {
			iter = iter->_next;
		}
		if (iter->_next == nullptr) {
			iter->_next = new Notation(key);
		}

		Element &element = iter->_next->_values;
		if (opera == EType::_PUSHUP) {
			ret += element.pushup(value, type, size);
		}
		else if (opera == EType::_APPEND) {
			ret += element.append(value, type, size);
		}
		else if (opera == EType::_OCCUPY) {
			ret += element.occupy(value, type, size);
		}
		return ret;
	}

	template<typename Value>
	int detach(const string &key, const Value *value, const TypeID &type, const SizeID &size = sizeof(Value), const Operation &opera = EType::_REMOVE) {
		cerr << __FUNCTION__ << endl;
		int ret = 0;

		Notation *iter = this;
		while (iter->_next != nullptr && key != iter->_next->_key) {
			iter = iter->_next;
		}

		if (iter->_next != nullptr) {
			Element &element = iter->_next->_values;
			if (opera == EType::_REMOVE) {
				ret += element.remove(value, type, size);
			}
			else if (opera == EType::_PURIFY) {
				iter->_next = iter->_next->_next;
				ret = 1;
			}
		}
		return ret;
	}

	template<typename Value>
	int recall(const string &key, Value *value, TypeID &type, SizeID &&size = sizeof(Value), long index = 0) {
		cerr << __FUNCTION__ << endl;
		int ret = 0;

		Notation *iter = this;
		while (iter->_next != nullptr && key != iter->_next->_key) {
			iter = iter->_next;
		}

		if (iter->_next != nullptr) {
			Element &element = iter->_next->_values;
			ret += element.obtain(value, type, size, index);
		}
		return ret;
	}

	long dumpFile(const string &filename, const Operation &opera = EType::_DESCRIPT) {
		cerr << __FUNCTION__ << endl;
		long chars = 0;
		long lines = 0;

		try {
			FILE *file = fopen(filename.c_str(), "wb+");
			Check(file == NULL, __FILE__, __LINE__, __FUNCTION__, errno, "fopen");
			auto cleanup = Cleanup(fclose, file);

			Pointer<char> buffer(new char[Config::_BUFFER_SIZE], Config::_BUFFER_SIZE);
			bool desc = (0 != (opera & EType::_DESCRIPT));
			if (desc) {
				int len = sprintf(buffer, "[%-*.*s#%-*x#%-*x]\n", 10, 10, "Arithmetic", 10, (unsigned long)chars, 10, (unsigned long)lines);
				fwrite(buffer, sizeof(char), len, file);
			}

			Pointer<char> address = buffer;
			for (Notation *iter = this; iter->_next != nullptr; iter = iter->_next) {
				Notation &notation = *(iter->_next);
				if (desc) {
					Define define = (EType::_STRING << 16) | (SizeID)(notation._key.size());
					buffer += sprintf(buffer, "%*.*x#", 8, 8, define);
				}
				buffer += sprintf(buffer, "%s; ", notation._key.c_str());
				notation._values.format(buffer, opera);
				long length = (long)(buffer - address);
				chars += fwrite(address, sizeof(char), length, file);
				lines += 1;
				fflush(file);
				buffer = address;
			}

			if (desc) {
				rewind(file);
				int len = sprintf(buffer, "[%-*.*s#%-*x#%-*x]\n", 10, 10, "Arithmetic", 10, (unsigned long)chars, 10, (unsigned long)lines);
				fwrite(buffer, sizeof(char), len, file);
			}
			fflush(file);
		}
		catch (...) {
			cerr << "catch(...)" << endl;
		}
		return lines;
	}

	long loadFile(const string &filename) {
		long chars = 0;
		long lines;



		return lines;
	}

public:
	string _key;
	Element _values;
	Pointer<Notation> _next;
};


// #define Main
int main(int argc, char *argv[]) {

	Notation note;
	const char *ptr = "abc";
	note.attach("a", "abcd", EType::_RAWSTR, 4);

	note.dumpFile("note.dat");

	return 0;
}