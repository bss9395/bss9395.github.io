/* Reverse_Sentence.cpp
Author: BSS9395
Update: 2022-02-16T22:18:00+08@China-Guangdong-Zhanjiang+08
Design: Reverse Sentence with punctuations as words
Encode: UTF-8
*/

#include <iostream>
#include <string>

typedef intptr_t iptr;
std::string Reverse_Sentence(const std::string &lite) {
    std::string buffer = ""; buffer.resize(lite.size() * 2); // note: allocate enough memory.
    if (0 < lite.size()) {
        char *data = (char *)buffer.data();
        const char *head = lite.data();
        const char *fore = lite.data() + lite.size();
        const char *back = nullptr;
        while (head < fore && head[0] == ' ') {   // note: leave blank space.
            head += 1;
        }
        while (head < fore && fore[-1] == ' ') {  // note: leave blank space.
            fore -= 1;
        }
        while (head < fore) {
            back = fore;
            while (head < fore) {
                if (fore[-1] == ' ' || fore[-1] == ',' || fore[-1] == '!') {  // note: separator.
                    if (data != buffer.data()) {
                        data[0] = ' ';
                        data += 1;
                    }
                    for (const char *iter = fore; iter < back; iter += 1) {
                        data[0] = iter[0];
                        data += 1;
                    }
                    while (fore[-1] == ',' || fore[-1] == '!') {  // note: punctuations.
                        if (data != buffer.data()) {
                            data[0] = ' ';
                            data += 1;
                        }
                        data[0] = fore[-1];
                        data += 1;
                        fore -= 1;
                    }
                    break;
                }
                fore -= 1;
            }
            while (head < fore && fore[-1] == ' ') {  // note: leave blank space.
                fore -= 1;
            }
        }
        if (back != nullptr) {
            if (data != buffer.data()) {
                data[0] = ' ';
                data += 1;
            }
            for (const char *iter = fore; iter < back; iter += 1) {
                data[0] = iter[0];
                data += 1;
            }
        }
        data[0] = '\0';
        buffer.resize(data - buffer.data());                        // note: not a bug on Visual Studio 2017.
        // return std::string(buffer.data(), data - buffer.data()); // note: better way to do.
    }
    return buffer;
}


/*
input:  "Hello, world!"
output: "world! Hello,"
*/
int main(int argc, char *argv[]) {
    std::string test = "Hello,, world!";
    std::string buffer = Reverse_Sentence(test);
    std::cout << buffer << std::endl;

    return 0;
}
