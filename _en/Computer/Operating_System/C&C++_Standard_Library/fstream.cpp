/* fstream.cpp
Author: BSS9395
Update: 2021-11-16T22:10:00+08@China-Guangdong-Shenzhen+08
Design: C++ Standard Library: fstream
*/

/* C++ Standard Library: fstream
#include <fstream>
typedef basic_fstream<char> fstream;
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef intptr_t iptr;

string Read_File(const string &filename) {
    string data = "";
    try {
        fstream file(filename, fstream::in | fstream::binary);
        file.exceptions(fstream::failbit | fstream::badbit);
        file.seekg(0, fstream::end);
        iptr leng = file.tellg();
        file.seekg(0, fstream::beg);

        data.resize(leng);
        if (leng != file.read(data.data(), leng).gcount()) {
            fprintf(stderr, "%s""\n", "leng != file.read(ret.data(), leng).gcount()");
        }
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
