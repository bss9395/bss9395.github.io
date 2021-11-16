/* istreambuf_iterator.cpp
Author: BSS9395
Update: 2021-11-16T23:01:00+08@China-Guangdong-Shenzhen+08
Design: C++ Standard Library: istreambuf_iterator
*/

/* C++ Standard Library: istreambuf_iterator
#include <iterator>
template <class charT, class traits=char_traits<charT>>
class istreambuf_iterator;

#include <iterator>
template <class T, class charT=char, class traits=char_traits<charT>, class Distance = ptrdiff_t>
class istream_iterator;
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;

string Read_File(const string &filename) {
    string data = "";
    try {
        fstream file(filename, fstream::in | fstream::binary);
        file.exceptions(fstream::failbit | fstream::badbit);
        data.assign(istreambuf_iterator<char>{file}, istreambuf_iterator<char>{}); // read from streambuf like cin.read()

        //fstream file(filename, fstream::in | fstream::binary);
        //file.exceptions(fstream::badbit);
        //data.assign(istream_iterator<char>{file}, istream_iterator<char>{});     // read from stream like cin
    }
    catch (fstream::failure &except) {
        fprintf(stderr, "%s""\n", except.what());
    }
    return data;
}

int main(int argc, char** argv) {
    string data = Read_File(__FILE__);
    cout << data << endl;

    return 0;
}
