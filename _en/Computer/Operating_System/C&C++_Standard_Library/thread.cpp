/* Cpp_thread.cpp
Author: bss9395
Update: 2025-07-15T09:35:00+08@China-ShangHai+08
*/

#include <iostream>
#include <thread>
#include <mutex>

class Run {
public:
	void _Func(int arg1, double arg2, std::string arg3) {
		_mutex.lock();
		std::cout << __FUNCTION__ << ", arg1 = " << arg1 << ", arg2 = " << arg2 << std::endl;
		for (int i = 0; i < arg3.size(); i += 1) {
			std::cout << arg3[i];
		}
		std::cout << std::endl;
		_mutex.unlock();
	}

private:
	std::mutex _mutex;
};

int main() {
	Run* run = new Run();
	std::thread routine1 = std::thread(&Run::_Func, run, 1, 2.0, "abcdefghijklmnopqrstuvwxyz");
	std::thread routine2 = std::thread(&Run::_Func, run, 3, 4.0, "ABCEDFGHIJKLMNOPQRSTUVWXYZ");
	routine1.join();
	routine2.join();
	delete run;

	return 0;
}
