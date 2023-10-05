/* Cpp_uniform_int_distribution.cpp
Author: BSS9395
Update: 2023-09-30T18:00:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: uniform_int_distribution
*/

#include <iostream>
#include <random>

int main(int argc, char *argv[]) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 9);

    int p[10] = { 0 };
    const int nrolls = 10000;
    for (int i = 0; i < nrolls; ++i) {
        p[distribution(generator)] += 1;
    }

    std::cout << "uniform_int_distribution(0,9): " << std::endl;
    for (int i = 0; i < 10; i += 1) {
        std::cout << i << ": " << std::string(p[i] * 100 / nrolls, '*') << std::endl;
    }

    return 0;
}
