/// Record: Cpp_friend.cpp
/// Author: bss9395
/// Update: 2025/12/20T17:40:00&+08$+08@China-BeiJing
/// Keepin: bss9395@yeah.net

#include<iostream>
#include<string>

struct Type {
public:
	double _value = 1234.5678;

	friend std::ostream& operator<<(std::ostream& os, const Type& type) {
		os << type._value;
		return os;
	}
};

int main(int argc, char *argv[]) {
	Type type;
	std::cout << type << std::endl;

	return 0;
}
