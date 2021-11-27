/* align.cpp
Author: BSS9395
Update: 2021-11-27T18:11:00+08@China-Guangdong-Shenzhen+08
Design: C++ Standard Library: align
Credit: https://www.cplusplus.com/reference/memory/align/
*/

/*
#include <memory>
void* align (size_t alignment, size_t size, void*& ptr, size_t& space);
*/

#include <iostream>
#include <memory>

typedef intptr_t iptr;

int main(int argc, char *argv[]) {
    char buffer[] = "----------------------------------------";

    void* ptr = buffer;
    size_t space = sizeof(buffer) - 1;
    while (nullptr != std::align(alignof(int), sizeof(char), ptr, space)) {
        char *place = (char*)ptr;
        place[0] = '@';
        ptr = place + sizeof(char);
        space -= sizeof(char);
    }

    std::cout << buffer << std::endl;
    return 0;
}
