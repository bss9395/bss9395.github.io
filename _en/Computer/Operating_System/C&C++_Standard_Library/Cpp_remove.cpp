/* Cpp_remove.cpp
Author: BSS9395
Update: 2025-05-11T10:42:00+08@China-Guangdong-Zhanjiang+08
*/

#include <iostream>   
#include <algorithm> 

int main(int argc, char *argv[]) {
	int ints[] = { 10, 20, 30, 30, 20, 10, 10, 20 };
	int* beg = ints;                         
	int* end   = ints + sizeof(ints) / sizeof(int); 

	end = std::remove(beg, end, 20);         
												
	std::cout << "range contains:";
	for (auto iter = beg; iter != end; iter += 1) {
		std::cout << " " << (*iter);
	}
	std::cout << "\n";

	return 0;
}