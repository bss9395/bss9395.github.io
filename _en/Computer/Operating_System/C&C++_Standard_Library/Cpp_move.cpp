/* Cpp_move.cpp
Author: BSS9395
Update: 2023-10-01T10:17:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: move
*/

#include <utility>     
#include <iostream>  
#include <vector>       
#include <string>       

int main() {
	std::string C   = "C";
	std::string Cpp = "C++";
	std::vector<std::string> vector;

	vector.push_back(std::move(C));
	vector.push_back(Cpp);         

	for (std::string& str : vector) {
		std::cout << str << std::endl;
	}	
	
	std::cout << "C   = " << C   << std::endl;
 	std::cout << "Cpp = " << Cpp << std::endl;

	return 0;
}
