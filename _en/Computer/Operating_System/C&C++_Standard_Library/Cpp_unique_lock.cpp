/* Cpp_unique_lock.cpp
Author: BSS9395
Update: 2023-10-01:09:21:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: unique_lock
*/

#include <iostream>  
#include <thread>      
#include <mutex>        

std::mutex mtx;          

void print_block(int count, char c) {
	std::unique_lock<std::mutex> lock(mtx);
	for (int i = 0; i < count; ++i) {
		std::cout << c; 
	}
	std::cout << std::endl;
}

int main() {
	std::thread thread1(print_block, 50, '*');
	std::thread thread2(print_block, 50, '$');

	thread1.join();
	thread2.join();

	return 0;
}