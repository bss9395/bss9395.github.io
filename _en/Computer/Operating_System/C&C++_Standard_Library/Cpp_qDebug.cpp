/* Cpp_qDebug.cpp
Author: bss9395
Update: 2024-09-26T10:31:00+08@China-Beijing+08
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Pair {
	friend std::ostream& operator<<(std::ostream& os, const Pair& pair) {
		os << "(" << pair._key << ":" << pair._value << ")";
		return os;
	}

public:
	std::string _key = "";
	double _value = 0;

public:
	explicit Pair(const std::string& key, const double value) {
		_key = key;
		_value = value;
	}
};

class Debug {
public:
	std::stringstream _stream;

public:
	virtual ~Debug() {
		std::cout << _stream.str() << std::endl;
	}

public:
	template<typename Type>
	Debug& operator<<(const Type& type) {		
		_stream << type;
		return (*this);
	}
};

int main(int argc, char *argv[]) {
	Debug() << "abcd" << ", " << "efgh";

	Pair pair("key", 1234.5678);
	Debug() << pair;

	return 0;
}
