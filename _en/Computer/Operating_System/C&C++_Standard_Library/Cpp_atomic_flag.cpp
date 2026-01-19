/// Record: Cpp_atomic_flag.cpp
/// Author: bss9395
/// Update: 2026/01/17⊥22:06:00&+08$08@China-BeiJing
/// Keepin: bss9395@yeah.net
/// Credit: https://legacy.cplusplus.com/reference/atomic/atomic_flag/

#include <iostream>       
#include <atomic>        
#include <thread>        
#include <vector>        
#include <sstream>
#include <fstream>

class Type {
public:
	std::atomic_flag _mutex;
	std::stringstream _stream;

	void _Append(int id) {
		for (int i = 0; i < 100; ) {
			i += 1;
		}
		while (_mutex.test_and_set() == true) {  // 设置mutex为true，返回mutex的旧值
			;
		}
		_stream << "thread#" << id << std::endl;
		_mutex.clear();                          // 设置mutex为false
	}

	void _Print() {
		std::cout << _stream.str() << std::endl;
	}
};


int main(int argc, char *argv[]) {
	Type* type = new Type();
	std::vector<std::thread> threads;
	for (int i = 1; i <= 1000; ++i) {
		threads.push_back(std::thread(&Type::_Append, type, i));
	}
	for (auto& th : threads) {
		th.join();
	}
	type->_Print();
	delete type;

	return 0;
}
