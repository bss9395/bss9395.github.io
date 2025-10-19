/* Cpp_Generic_Array_Parameter.cpp
Author: bss9395
Update: 2025/10/18T09:23:00+08@China-BeiJing+08
Keepin: bss9395@yeah.net
*/

#include<iostream>
#include<string> 

template<typename Type_, long length_>
long _Array_Length(const Type_(&array)[length_]) {
	return length_;
}

int main(int argc, char *argv[]) {
	std::string array[] = {
		"Hello", "World"
	};
	long length = _Array_Length(array);
	std::cout << "length = " << length << std::endl;
	return 0;
}
