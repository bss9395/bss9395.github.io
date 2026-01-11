/// Record: Cpp_Reference_Virtual.cpp
/// Author: bss9395
/// Update: 2025/12/21T15:06:00&+08$+08@China-BeiJing
/// Keepin: bss9395@yeah.net

#include<iostream>
#include<string>

struct Type {
	virtual void _Func() {
		std::cout << __FUNCTION__ << std::endl;
	}
};

struct Derived : public Type {
	virtual void _Func() {
		std::cout << __FUNCTION__ << std::endl;
	}
};

int main(int argc, char *argv[]) {
	Derived derived;
	Type& type = derived;
	type._Func();

	return 0;
}
