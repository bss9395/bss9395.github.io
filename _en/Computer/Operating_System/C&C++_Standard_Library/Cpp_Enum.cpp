/* Cpp_Enum.cpp
Author: bss9395
Update: 2025-08-06T19:37:00+08@China-GuangDong-ZhanJiang+08
*/

#include<iostream>
#include<string>

template<typename Type_>
struct Enum {
	Type_ _enum = Type_();
	Enum(const Type_ &that) {
		_enum = that;
	}
	operator const Type_&() const {
		return _enum;
	}

	// 不需要定义bool operator!=(const Enum &lhs, const Enum &rhs);
	friend bool operator==(const Enum &lhs, const Enum &rhs) {
		return (lhs._enum == rhs._enum);
	}
};

class Class {
public:
	typedef Enum<const char *> Locale_Pointer;
	typedef Enum<std::string>  Locale_String;
	static inline const Locale_Pointer _zh_CN_Pointer = "zh-CN";
	static inline const Locale_Pointer _en_US_Pointer = "en-US";
	static inline const Locale_String  _zh_CN_String = std::string("zh-CN");
	static inline const Locale_String  _en_US_String = std::string("en-US");

public:
	void _Func_Pointer(const Locale_Pointer& locale) {
		std::cout << ((locale == _zh_CN_Pointer) ? "true" : "false") << std::endl;
		std::cout << (std::string)locale << std::endl;
	}

	void _Func_String(const Locale_String& locale) {
		std::cout << ((locale == _zh_CN_String) ? "true" : "false") << std::endl;
		std::cout << (std::string)locale << std::endl;
	}
};

void _Test_Enum() {
	Class cls;
	// cls._Func_Pointer(Class::_zh_CN_String);
	cls._Func_Pointer(Class::_zh_CN_Pointer);
	cls._Func_String(Class::_zh_CN_String);
}

int main() {
	_Test_Enum();

	return 0;
}
