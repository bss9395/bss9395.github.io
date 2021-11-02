/* final.cpp
Author: BSS9395
Update: 2021-11-02T21:08:00+08@China-Guangdong-Shenzheng+08
Design: C++ Standard Keyword: final
*/

#include <iostream>

class Config final {
public:
    // static const char Author[] = "BSS9395";  // Error: syntax not supported.
    static constexpr char Author[] = "BSS9395";

public:
    Config() {
        std::cerr << __FUNCTION__ << std::endl;
    }

    virtual ~Config() {
        std::cerr << __FUNCTION__ << std::endl;
    }

public:
    virtual void Final() final {
        std::cerr << __FUNCTION__ << std::endl;
    }
} _Config;

// // final class cannot be overrided.
// class Override : public Config {
// public:
//     // final function cannot be overrided.
//     virtual void Final() override {
//         std::cerr << __FUNCTION__ << std::endl;
//     }
// };

int main(int arg, char *argv[]) {
    std::cerr << __FUNCTION__ << std::endl;
}
