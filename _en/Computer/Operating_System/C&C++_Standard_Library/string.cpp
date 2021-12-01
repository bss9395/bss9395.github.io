/* string.cpp
Author: BSS9395
Update: 2021-12-01T23:02:00+08@China-Guangdong-Shenzhen+08
Design: C++ Standard Library: string
*/

/* C++ Standard Library: string
#include <string>
typedef basic_string<char> string;

#include <stirng>
string to_string(int val);
string to_string(long val);
string to_string(long long val);
string to_string(unsigned val);
string to_string(unsigned long val);
string to_string(unsigned long long val);
string to_string(float val);
string to_string(double val);
string to_string(long double val);

#include <string>
long double stold(const string&  str, size_t* idx = 0);
long double stold(const wstring& str, size_t* idx = 0);
*/

#include <cstdint>
#include <iostream>
#include <string>

typedef intptr_t iptr;

class String {
public:
    explicit String(const char *ptr) {
        std::cout << "explicit String(const char *ptr)" << std::endl;
    }

    explicit String(const std::string &str) {
        std::cout << "explicit String(const std::string &str) " << std::endl;
    }
};

void Test_String() {
    const char *buffer = "buffer";
    String{ buffer };
    String{ std::string{ buffer } };
}

void Test_To_String() {
    std::string to = std::to_string(-123.456789);
    double ld = std::stold("  -123.456789  ");
    std::cout << to << std::endl;
    std::cout << ld << std::endl;
}

void Test_Resize() {
    std::string buffer = "";
    buffer += "value: ";
    iptr leng = buffer.length();
    buffer.resize(1024);
    snprintf(buffer.data() + leng, buffer.size() - leng, "%0.3lf", -123.456789);
    fprintf(stdout, "%s""\n", buffer.data());
}

void Test_Less() {
    std::string ABC = "ABC";
    std::string abc = "abc";
    bool less = (ABC < abc);
    std::cout << std::boolalpha << less << std::endl;
}

int main(int argc, char *argv[]) {
    Test_String();
    Test_To_String();
    Test_Resize();
    Test_Less();

    return 0;
}
