/* Cpp_finally.cpp
Author: bss9395
Update: 2025-07-29T22:43:00+08@China-GuangDong-ZhanJiang+08
*/

#include <iostream>
#include <functional>

class Finally {
public:
	explicit Finally(const std::function<void()>& cleanup)
		: _cleanup(cleanup) {}

	virtual ~Finally() {
		_Execute();
	}

public:
	void _Execute() {
		if (_flag == false) {
			_flag = true;
			_cleanup();
		}
	}

private:
	bool _flag = false;
	std::function<void()> _cleanup;
};

void _Function() {
	std::cout << "begin function" << std::endl;
	if (true) {
		throw std::runtime_error("error occurred.");
	}
	std::cout << "endup function" << std::endl;
}

int main() {
	try {
		Finally finally([]() {
			std::cout << "finally executed." << std::endl;
		});
		try {
			_Function();
		} catch (const std::exception& except) {
			std::cout << "exception caught: " << except.what() << std::endl;
			throw except;
		} catch (...) {
			std::cout << "any exception caught: " << std::endl;
		} 
		finally._Execute();
		std::cout << "after try" << std::endl;
	} catch (const std::exception& except) {
		std::cout << "outer try: " << except.what() << std::endl;
	}
	return 0;
}
