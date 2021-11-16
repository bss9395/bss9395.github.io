/* stringstream.cpp
Author: BSS9395
Update: 2021-11-16T22:32:00+08@China-Guangdong-Shenzhen+08
Design: C++ Standard Library: stringstream
*/

/* C++ Standard Library: stringstream
#include <sstream>
typedef basic_stringstream<char> stringstream;
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string Read_File(const string &filename) {
    string data = "";
    try {
        fstream file(filename, fstream::in | fstream::binary);
        file.exceptions(fstream::failbit | fstream::badbit);
        stringstream stream;
        stream << file.rdbuf();
        data = stream.str();
    }
    catch (fstream::failure &except) {
        fprintf(stderr, "%s""\n", except.what());
    }
    return data;
}

int main(int argc, char *argv[]) {
    string data = Read_File(__FILE__);
    cout << data << endl;

    return 0;
}
