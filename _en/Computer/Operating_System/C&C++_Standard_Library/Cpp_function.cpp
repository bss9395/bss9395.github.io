/* Cpp_function.cpp
Author: bss9395
Update: 2024-09-26T11:30:00+08@China-Beijing+08
*/

#include <iostream>     
#include <functional> 
#include <string>

std::string _Func(std::string text) {
	return text;
}

struct Type {
public:
	std::string _value = "value";

	std::string operator()(std::string text) {
		return (text + _value);
	}

	std::string _Func(std::string text) {
		return (text + _value);
	}
};

std::string _Function(int i, double d, std::string s) {
	std::cout << "i = " << i << ", " << "d = " << d << ", " << "s = " << s << std::endl;
	return s;
}

static void _Test_std_function() {
	std::function<std::string(std::string)> func1 = _Func;                                                 // function
	std::function<std::string(std::string)> func2 = &_Func;                                                // function pointer
	std::function<std::string(std::string)> func3 = Type();                                                // function object
	std::function<std::string(std::string)> func4 = [](std::string text) -> std::string { return text; };  // lambda expression
	std::function<std::string(Type&)> value = &Type::_value;                                               // pointer to data member
	std::function<std::string(Type&, std::string)> func5 = &Type::_Func;                                   // pointer to member function

	std::cout << "func1: " << func1("text") << std::endl;
	std::cout << "func2: " << func2("text") << std::endl;
	std::cout << "func3: " << func3("text") << std::endl;
	std::cout << "func4: " << func4("text") << std::endl;

	Type type = Type{ "text" };
	std::cout << "value: " << value(type) << std::endl;
	std::cout << "func5: " << func5(type, "text") << std::endl;
}

static void _Test_Function_Pointer() {
	std::cout << _Func("text") << std::endl;
	std::cout << (*_Func)("text") << std::endl;
	std::cout << (&_Func)("text") << std::endl;
}

// program runs normally
static void _Test_Cast_Regular() {
	typedef std::string(*Function)(int, double, std::string);
	Function function = (Function)_Function;
	std::string ret = function(12, 34.56, "78");
	std::cout << "ret = " << ret << std::endl;
}

// program runs anormally
static void _Test_Cast_Irregular() {
	typedef double(*Function)(int);
	Function function = (Function)_Function;
	double ret = function(12);
	std::cout << "ret = " << ret << std::endl;
}

int main(int argc, char *argv[]) {
	_Test_std_function();
	// _Test_Function_Pointer();
	// _Test_Cast_Regular();
	// _Test_Cast_Irregular();

	return 0;
}