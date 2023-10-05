/* Cpp_async.cpp
Author: BSS9395
Update: 2023-10-01T09:31:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: async
*/

#include <iostream>      
#include <future>         

bool is_prime(int prime) {
	for (int i = 2; i < prime; ++i) {
		if (prime % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	std::future<bool> fut = std::async(is_prime, 313222313);
	std::cout << "Checking whether 313222313 is prime.\n";
	bool retu = fut.get();      
	std::cout << "It is" << (retu ? " " : " not ") << "prime!\n";

	return 0;
}