///* Counting_Array.cpp
//Author: BSS9395
//Update: 2025-04-18T09:52:00@China-Guangdong-Zhan-Jiang
//Design: Permutation and Combination
//*/
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <vector>
//
///* 
//input = {3}
//output = {
//	A[0], A[1], A[2]
//}
//
//input = {2, 3}
//output = {
//	A[0][0], A[0][1], A[0][2],
//	A[1][0], A[1][1], A[1][2]
//}
//
//input = {3, 2, 3}
//output = {
//	A[0][0][0], A[0][0][1], A[0][0][2],
//	A[0][1][0], A[0][1][1], A[0][1][2],
//	A[1][0][0], A[1][0][1], A[1][0][2],
//	A[1][1][0], A[1][1][1], A[1][1][2],
//	A[2][0][0], A[2][0][1], A[2][0][2],
//	A[2][1][0], A[2][1][1], A[2][1][2]
//}
//*/
//
//void PrintArray(const std::string &name, const std::vector<int>& input) {
//	std::vector<int> numerator;
//	numerator.resize(input.size());
//	for (int i = 0; i < (int)input.size(); i += 1) {
//		int factor = 1;
//		for (int j = i + 1; j < (int)input.size(); j += 1) {
//			factor *= input[j];
//		}
//		numerator[i] = factor;
//	}
//
//	int end = 1;
//	for (int i = 0; i < (int)input.size(); i += 1) {
//		end *= input[i];
//	}
//
//	for (int beg = 0; beg < end; beg += 1) {
//		int i = beg;
//		std::cout << name;
//		for (int j = 0; j < (int)numerator.size(); j += 1) {
//			int idx = (i / numerator[j]);
//			std::cout << "[" << idx << "]";
//			i -= idx * numerator[j];
//		}
//		std::cout << std::endl;
//	}
//}
//
//void Test_PrintArray() {
//	std::vector<int> input;
//	input.push_back(3);
//	input.push_back(2);
//	input.push_back(3);
//	PrintArray("A", input);
//
//}
//
//int main(int argc, char *argv[]) {
//	Test_PrintArray();
//	return 0;
//}