/* Cpp_Enum.cpp
Author: bss9395
Update: 2025-08-06T19:37:00+08@China-GuangDong-ZhanJiang+08
*/

#include<iostream>
#include<string>

template<typename Type_, unsigned int>
struct Enum {
	Type_ _enum;
	Enum(const Type_& that) {
		_enum = that;
	}
	operator Type_() {
		return _enum;
	}
};

class Class {
public:
	typedef Enum<std::string, 0> Locale;
	static const Locale _zh_CN;
	static const Locale _en_US;

public:
	void _Func(const Locale& locale) {
		std::cout << (std::string)(Locale)locale << std::endl;
	}
};
const Class::Locale Class::_zh_CN = Class::Locale("zh-CN");
const Class::Locale Class::_en_US = Class::Locale("en-US");


int main() {
	Class cls;
	cls._Func(Class::_zh_CN);
	return 0;
}
