/* Cpp_thread_local.cpp
Author: bss9395
Update: 2025-08-06T22:17:00+08@China-GuangDong-ZhanJiang+08
*/

#include <iostream>
#include <thread>
#include <mutex>

class Type {
	std::mutex _mutex;

public:
	void _Counter() {
		static thread_local int _counter = 0;
		for (int i = 0; i < 100; i += 1) {
			_counter += 1;
			_mutex.lock();
			std::cout << "[" << std::this_thread::get_id() << "] " << _counter << std::endl;
			_mutex.unlock();
		}
	}
};

int main() {
	Type type;
	std::thread thread1(&Type::_Counter, &type);
	std::thread thread2(&Type::_Counter, &type);
	thread1.join();
	thread2.join();

	return 0;
}
