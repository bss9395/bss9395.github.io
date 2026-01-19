/// Record: Cpp_atomic_exchange.cpp
/// Author: bss9395
/// Update: 2026/01/17⊥22:06:00&+08$08@China-BeiJing
/// Keepin: bss9395@yeah.net
/// Credit: https://legacy.cplusplus.com/reference/atomic/atomic/exchange/

#include <iostream>      
#include <atomic>       
#include <thread>       
#include <vector>        

class Type {
public:
	std::atomic<bool> _ready = false;
	std::atomic<bool> _winner = false;

	void _Race(int id) {
		while (_ready == false) {
			;
		}
		for (int i = 0; i < 100; ++i) {
			;
		}
		if (_winner.exchange(true) == false) {  // 替换_winner的值为true，返回_winner的旧值
			std::cout << "thread#" << id << " won!" << std::endl;
		}
	};
};

int main(int argc, char *argv[]) {
	Type* type = new Type();
	std::vector<std::thread> threads;
	for (int i = 1; i <= 10000; ++i) {
		threads.push_back(std::thread(&Type::_Race, type, i));
	}
	type->_ready = true;
	for (auto& th : threads) {
		th.join();
	}
	delete type;

	return 0;
}
