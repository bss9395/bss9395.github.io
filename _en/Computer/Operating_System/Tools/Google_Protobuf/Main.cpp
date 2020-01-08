#if 0
g++ Main.cpp pb.pb.cc -lprotobuf
#endif

#include "pb.pb.h"
#include <iostream>
#include <string>

using namespace std;
using namespace pb_sample;

int main() {
    Student s;
    s.set_no(1);
    s.set_name("abc");

    string buf;
    s.SerializeToString(&buf);

    for(auto c : buf) {
        printf("%02x ",c);
    }
    printf("\n");

    char buf2[] = { 0x08, 0x01, 0x12, 0x03, 0x61, 0x62, 0x63 };
    Student s2;
    s2.ParseFromArray(buf2, sizeof(buf2));
    cout << s2.no() << ", " << s2.name() << endl;

    return 0;
}

