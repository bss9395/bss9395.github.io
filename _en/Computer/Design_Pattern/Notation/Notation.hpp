/*Notation.hpp
* Author: BSS9395
* Update: 2020-01-23T20:36:00+08@ShenZhen+08
* Design: Notation
*/

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
using ::printf;
using ::sprintf;
using ::fprintf;

#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using std::cout;
using std::cerr;
using std::endl;
using std::flush;
using std::iostream;
using std::stringstream;
using std::fstream;
using std::string;


#include "Pointer.hpp"
#include "Sequence.hpp"

typedef int8_t  int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef float   rat32;
typedef double  rat64;

typedef unsigned short TypeID;
typedef unsigned short SizeID;
typedef unsigned int   Define;
typedef unsigned int   Operation;
namespace EType {
	// _BIT means a type defined by system;
	// otherwise means a type defined by user;
	static const TypeID _BIT = 1U << 15;
	static const TypeID _INT = _BIT | (1U << 14);
	static const TypeID _RAT = _BIT | (1U << 13);
	static const TypeID _INT8 = _INT | 1U;
	static const TypeID _INT16 = _INT | 2U;
	static const TypeID _INT32 = _INT | 4U;
	static const TypeID _INT64 = _INT | 8U;
	static const TypeID _RAT32 = _RAT | 4U;
	static const TypeID _RAT64 = _RAT | 8U;
	// static const TypeID _RAT64 = 64U;
	static const TypeID _RAWSTR = _BIT | 1U;
	static const TypeID _STRING = _BIT | 2U;

	static const Operation _PUSHUP = (1U << 0);
	static const Operation _APPEND = (1U << 1);
	static const Operation _OCCUPY = (1U << 2);
	static const Operation _REMOVE = (1U << 3);
	static const Operation _PURIFY = (1U << 4);
	static const Operation _DESCRIPT = (1U << 5);
	static const Operation _STRAIGHT = (1U << 6);
}


class Element {
public:
	Element(const TypeID &type = TypeID(), const SizeID &size = SizeID(), char *value = nullptr, const Pointer<Element> &next = nullptr)
		: _value(value), _type(type), _size(size), _next(next) {
		// cerr << __FUNCTION__ << endl;
	}

	template<typename Value>
	Element(const Value *value, const TypeID &type = EType::_RAWSTR, const SizeID &size = sizeof(Value), const Pointer<Element> &next = nullptr)
		: _value(new char[size]), _type(type), _size(size), _next(next) {

		// cerr << *(double *)value;

		memcpy(_value, value, size);
		// cerr << __FUNCTION__ << "#" << "Value" << endl;
	}

	virtual ~Element() {
		// cerr << __FUNCTION__ << endl;
		delete[] _value;
		// _value = nullptr;
	}

public:
	template<typename Value>
	int pushup(const Value *value, const TypeID &type, const SizeID &size) {
		// cerr << __FUNCTION__ << endl;
		int ret = 0;
		_next = new Element(value, type, size, _next);
		ret += 1;
		return ret;
	}

	template<typename Value>
	int append(const Value *value, const TypeID &type, const SizeID &size) {
		// cerr << __FUNCTION__ << endl;
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
	int occupy(const Value *value, const TypeID &type, const SizeID &size) {
		// cerr << __FUNCTION__ << endl;
		int ret = 0;
		_next = new Element(value, type, size, nullptr);
		ret += 1;
		return ret;
	}

	template<typename Value>
	int remove(const Value *value, const TypeID &type, const SizeID &size) {
		// cerr << __FUNCTION__ << endl;
		int ret = 0;
		Element *iter = this;
		while (iter->_next != nullptr) {
			Element &element = *(iter->_next);
			bool cond1 = (type == element._type && size == element._size);
			bool cond2 = (type == EType::_RAWSTR && size >= element._size);
			if (cond1 || cond2) {
				if (0 == memcmp(value, element._value, element._size)) {
					iter->_next = iter->_next->_next;
					_size -= element._size;
					ret += 1;
					continue;
				}
			}
			iter = iter->_next;
		}
		return ret;
	}

	template<typename Value>
	int obtain(Value *value, TypeID *type, SizeID *size, const int &index = 0) {
		// cerr << __FUNCTION__ << endl;
		int ret = 0;
		Element *iter = this;
		int idx = 0;
		while (iter->_next != nullptr && idx < index) {
			iter = iter->_next;
			idx += 1;
		}

		if (iter->_next != nullptr && idx == index) {
			Element &element = *(iter->_next);
			bool cond1 = (*type == element._type && *size == element._size);
			bool cond2 = (*type == EType::_RAWSTR && *size >= element._size);
			if (cond1 || cond2) {
				memcpy(value, element._value, element._size);
			}

			*type = element._type;
			*size = element._size;
			ret += 1;
		}

		return ret;
	}

	int format(char *buffer, const Operation &opera) {
		// cerr << __FUNCTION__ << endl;
		char *ret = buffer;
		for (Element *iter = this->_next; iter != nullptr; iter = iter->_next) {
			if (opera == EType::_DESCRIPT) {
				Define define = ((iter->_type << 16) | iter->_size);
				buffer += sprintf(buffer, "%*.*x#", 8, 8, define);
			}

			if (iter->_type == EType::_INT8) {
				int8 *numbers = (int8 *)iter->_value;
				for (int i = 0, len = iter->_size / sizeof(int8); i < len; i += 1) {
					buffer += sprintf(buffer, (i == 0 ? "%lld" : ", %lld"), (long long)numbers[i]);
				}
			}
			else if (iter->_type == EType::_INT16) {
				int16 *numbers = (int16 *)iter->_value;
				for (int i = 0, len = iter->_size / sizeof(int16); i < len; i += 1) {
					buffer += sprintf(buffer, (i == 0 ? "%lld" : ", %lld"), (long long)numbers[i]);
				}
			}
			else if (iter->_type == EType::_INT32) {
				int32 *numbers = (int32 *)iter->_value;
				for (int i = 0, len = iter->_size / sizeof(int32); i < len; i += 1) {
					buffer += sprintf(buffer, (i == 0 ? "%lld" : ", %lld"), (long long)numbers[i]);
				}
			}
			else if (iter->_type == EType::_INT64) {
				int64 *numbers = (int64 *)iter->_value;
				for (int i = 0, len = iter->_size / sizeof(int64); i < len; i += 1) {
					buffer += sprintf(buffer, (i == 0 ? "%lld" : ", %lld"), (long long)numbers[i]);
				}
			}
			else if (iter->_type == EType::_RAT32) {
				rat32 *numbers = (rat32 *)iter->_value;
				for (int i = 0, len = iter->_size / sizeof(rat32); i < len; i += 1) {
					buffer += sprintf(buffer, (i == 0 ? "%lf" : ", %lf"), (double)numbers[i]);
				}
			}
			else if (iter->_type == EType::_RAT64) {
				rat64 *numbers = (rat64 *)iter->_value;
				for (int i = 0, len = iter->_size / sizeof(rat64); i < len; i += 1) {
					buffer += sprintf(buffer, (i == 0 ? "%lf" : ", %lf"), (double)numbers[i]);
				}
			}
			else if (iter->_type == EType::_RAWSTR) {
				char *ptr = (char *)iter->_value;
				int len = iter->_size;
				memcpy(buffer, ptr, len);
				buffer += len;
			}
			else {
				char *ptr = (char *)iter->_value;
				int len = iter->_size;
				memcpy(buffer, ptr, len);
				buffer += len;
			}

			buffer += sprintf(buffer, "; ");
		}
		return (int)(buffer - ret);
	}

	int embark(char *data, const Operation &opera) {
		char *ret = data;

		Element *iter = this;
		while (true) {
			if (opera == EType::_DESCRIPT) {
				Define define;
				data += Sequence::ParseNumber(data, &define, 16.0);
				if (data[0] != '#') {
					throw '#';
				}
				data += 1;

				TypeID type = (TypeID)(define >> 16);
				SizeID size = (SizeID)define;
				char *value = new char[size];
				iter->_next = new Element(type, size, value, nullptr);
				iter = iter->_next;

				if (type == EType::_INT8) {
					int8 *numbers = (int8 *)value;
					data += Sequence::ParseNumberArray(data, numbers);
				}
				else if (type == EType::_INT16) {
					int16 *numbers = (int16 *)value;
					data += Sequence::ParseNumberArray(data, numbers);
				}
				else if (type == EType::_INT32) {
					int32 *numbers = (int32 *)value;
					data += Sequence::ParseNumberArray(data, numbers);
				}
				else if (type == EType::_INT64) {
					int64 *numbers = (int64 *)value;
					data += Sequence::ParseNumberArray(data, numbers);
				}
				else if (type == EType::_RAT32) {
					rat32 *numbers = (rat32 *)value;
					data += Sequence::ParseNumberArray(data, numbers);
				}
				else if (type == EType::_RAT64) {
					rat64 *numbers = (rat64 *)value;
					data += Sequence::ParseNumberArray(data, numbers);
				}
				else if (type == EType::_RAWSTR) {
					char *ptr = (char *)value;
					memcpy(ptr, data, (SizeID)define);
					data += (SizeID)define;
				}
				else {
					char *ptr = (char *)value;
					memcpy(ptr, data, (SizeID)define);
					data += (SizeID)define;
				}
			}
			else if (opera == EType::_STRAIGHT) {
				int cnt = 1;
				int len = 0;
				while (data[len] != ';') {
					if (data[len] == ',') {
						cnt += 1;
					}
					len += 1;
				}

				if ('0' <= data[0] && data[0] <= '9') {
					rat64 *numbers = new rat64[cnt];
					iter->_next = new Element(EType::_RAT64, (SizeID)(sizeof(rat64) * cnt), (char *)numbers, nullptr);
					iter = iter->_next;

					data += Sequence::ParseNumberArray(data, numbers, 10.0);
				}
				else {
					char *ptr = new char[len];
					iter->_next = new Element(EType::_RAWSTR, (SizeID)len, ptr, nullptr);
					iter = iter->_next;

					memcpy(ptr, data, len);
					data += len;
				}
			}

			if (data[0] != ';') {
				throw ';';
			}
			data += 1;

			while (data[0] == ' ' || data[0] == '\t' || data[0] == '\v' || data[0] == '\f' || data[0] == '\r') {
				data += 1;
			}

			if (data[0] == '\n' || data[0] == '\0') {
				break;
			}
		}

		return (int)(data - ret);
	}

public:
	char *_value;
	TypeID _type;
	SizeID _size;
	Pointer<Element> _next;
};

class Notation {
public:
	Notation(const string &key = string(), const Element &values = Element(), const Pointer<Notation> &next = nullptr)
		: _key(key), _values(values), _next(next) {
		// cerr << __FUNCTION__ << endl;
	}

	virtual ~Notation() {
		// cerr << __FUNCTION__ << endl;
	}

public:
	template<typename Value>
	int attach(const string &key, const Value *value, const TypeID &type, const SizeID &size = sizeof(Value), const Operation &opera = EType::_PUSHUP) {
		// cerr << __FUNCTION__ << endl;
		int ret = 0;

		Notation *iter = this;
		while (iter->_next != nullptr && key != iter->_next->_key) {
			iter = iter->_next;
		}
		if (iter->_next == nullptr) {
			iter->_next = new Notation(key, Element(), nullptr);
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
		// cerr << __FUNCTION__ << endl;
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
	int recall(const string &key, Value *value, TypeID *type, SizeID *size, int index = 0) {
		// cerr << __FUNCTION__ << endl;
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

	int backpack(char *buffer, const Operation &opera = EType::_DESCRIPT) {
		// cerr << __FUNCTION__ << endl;
		char *ret = buffer;
		for (Notation *iter = this->_next; iter != nullptr; iter = iter->_next) {
			if (opera == EType::_DESCRIPT) {
				Define define = ((EType::_STRING << 16) | (SizeID)iter->_key.size());
				buffer += sprintf(buffer, "%*.*x#", 8, 8, define);
			}

			buffer += sprintf(buffer, "%s; ", iter->_key.c_str());
			buffer += iter->_values.format(buffer, opera);
			buffer += sprintf(buffer, "\n");
		}
		buffer[0] = '\0';
		buffer += 1;

		return (int)(buffer - ret);
	}

	int assemble(char *data, const Operation &opera = EType::_DESCRIPT) {
		// cerr << __FUNCTION__ << endl;
		char *ret = data;
		Notation *iter = this;
		while (true) {
			while (data[0] == '\n' || data[0] == ' ' || data[0] == '\t' || data[0] == '\v' || data[0] == '\f' || data[0] == '\r') {
				data += 1;
			}

			if (opera == EType::_DESCRIPT) {
				Define define;
				data += Sequence::ParseNumber(data, &define, 16.0);
				if (data[0] != '#') {
					throw '#';
				}
				data += 1;

				iter->_next = new Notation();
				iter = iter->_next;
				iter->_key.assign(data, (SizeID)define);
				data += (SizeID)define;
			}
			else if (opera == EType::_STRAIGHT) {
				int len = 0;
				while (data[len] != ';') {
					len += 1;
				}

				iter->_next = new Notation();
				iter = iter->_next;
				iter->_key.assign(data, len);
				data += len;
			}

			if (data[0] != ';') {
				throw ';';
			}
			data += 1;

			while (data[0] == ' ' || data[0] == '\t' || data[0] == '\v' || data[0] == '\f' || data[0] == '\r') {
				data += 1;
			}

			data += iter->_values.embark(data, opera);

			if (data[0] == '\n' && data[1] == '\0' || data[0] == '\0') {
				break;
			}
			else if (data[0] != '\n') {
				throw '\n';
			}
			data += 1;
		}

		return (int)(data - ret);
	}

	int dumpFile(const string &filename, const Operation &opera = EType::_DESCRIPT) {
		// cerr << __FUNCTION__ << endl;
		int ret = 0;

		try {
			FILE *file = fopen(filename.c_str(), "wb+");
			Check(file == NULL, __FILE__, __LINE__, __FUNCTION__, errno, "fopen");
			auto cleanup = Cleanup(fclose, file);

			Pointer<char> buffer(new char[1024 * 8], 1024 * 8);
			int len = backpack(buffer, opera);

			fwrite(buffer, sizeof(char), len, file);
			ret += 1;
		}
		catch (char ch) {
			cerr << __FUNCTION__ << "#" << ch << endl;
		}
		return ret;
	}

	int loadFile(const string &filename, const Operation &opera = EType::_DESCRIPT) {
		// cerr << __FUNCTION__ << endl;
		int ret = 0;

		try {
			FILE *file = fopen(filename.c_str(), "rb+");
			Check(file == NULL, __FILE__, __LINE__, __FUNCTION__, errno, "fopen");
			auto cleanup = Cleanup(fclose, file);

			Pointer<char> data = Sequence::ReadFile(file);
			assemble(data, opera);
			ret += 1;
		}
		catch (char ch) {
			cerr << __FUNCTION__ << "#" << ch << endl;
		}
		return ret;
	}

public:
	string _key;
	Element _values;
	Pointer<Notation> _next;
};


#define Main
#ifdef Main

void testAssemble() {
	char data[] = "80030003#key; 80020005#value; ";
	Notation note;
	note.assemble(data, EType::_DESCRIPT);
	note.dumpFile("note.dat");
}

void testBackpack() {
	char buffer[1024] = "0123456789";
	Notation note;
	note.loadFile("note.dat");
	note.backpack(buffer, EType::_DESCRIPT);

	cerr << buffer;
}

void testAttach() {
	Notation note;

	note.attach("key1", "value1", EType::_RAWSTR, 6);

	int integer = 12345;
	note.attach("key2", &integer, EType::_INT32, sizeof(int));

	double rational[] = { 12.34, 56.78, 90.12 };
	note.attach("key3", &rational, EType::_RAT64, sizeof(rational));

	note.dumpFile("note.dat");
}

void testLoadDumpFile() {
	Notation note;
	note.loadFile("note.dat");
	note.dumpFile("note.txt");
}

void testNotationWithoutDescription() {
	Notation note;
	note.attach("key1", "value1", EType::_RAWSTR, 6);
	double numbers[] = { 12.34, 56.78, 90.12 };
	note.attach("key2", &numbers, (EType::_RAT | sizeof(double)), sizeof(numbers));
	note.dumpFile("straight.dat", EType::_STRAIGHT);

	Notation nota;
	nota.loadFile("straight.dat", EType::_STRAIGHT);
	nota.dumpFile("straight.tmp", EType::_STRAIGHT);
}

int main(int argc, char *argv[]) {
	// testAssemble();
	// testBackpack();
	// testAttach();
	// testLoadDumpFile();
	testNotationWithoutDescription();

	return 0;
}

#endif 
