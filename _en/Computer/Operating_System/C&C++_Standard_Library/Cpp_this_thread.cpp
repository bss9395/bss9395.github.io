/* Cpp_this_thread.cpp
Author: bss9395
Update: 2025/11/25T23:40:00@China-BeiJing
Keepin: bss9395@yeah.net
*/

#include <iostream>
#include <chrono>
#include <thread>

void _Test_Sleep_For() {
	for (int i = 0; i < 10; i += 1) {
		std::cout << i << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

int main(int argc, char *argv[]) {
	_Test_Sleep_For();

	return 0;
}
