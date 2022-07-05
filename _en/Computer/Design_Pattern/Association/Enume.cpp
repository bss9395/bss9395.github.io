/* Enum.cpp
Author: BSS9395
Update: 2022-07-03T13:23:00+08@China-Shanghai+08
Design: Enum
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
typedef intptr_t iptr;

struct Enume {
public:
    iptr _index = 0;
    iptr _enume = 0;
    const char* _field = "";
    const char* _alias = "";

public:
    Enume() {
        fprintf(stderr, "%s\n", "Enum() {");
    }

    Enume(Enume* base, iptr enume, const char* alias) {
        fprintf(stderr, "%s\n", "Enume(Enume *base, iptr index, iptr enume, const char* alias) {");

        _index = base->_index;
        _enume = enume;
        _alias = alias;
        base->_index += 1;
    }

    Enume(Enume* base, const char* field, const char* alias) {
        fprintf(stderr, "%s\n", "Enume(Enume *base, iptr index, const char* field, const char* alias) {");

        _index = base->_index;
        _field = field;
        _alias = alias;
        base->_index += 1;
    }

public:
    Enume& operator[](iptr idx) {
        fprintf(stderr, "%s\n", "Enum& operator[](iptr idx) {");

        return ((Enume*)this)[idx + 1];
    }
};

struct Datum : public Enume {
    Enume _name    = Enume{ this, "_name"   , "姓名" };
    Enume _math    = Enume{ this, "_math"   , "数学" };
    Enume _chinese = Enume{ this, "_chinese", "语文" };
    Enume _english = Enume{ this, "_english", "英语" };
    Enume _average = Enume{ this, "_average", "平均分" };
} _datum;

////////////////////////////////////////////////////////////////////////////////

template<typename Field>
struct Enumeration {
public:
    Field& operator[](iptr idx) {
        fprintf(stderr, "%s\n", "Field& operator[](iptr idx) {");

        return ((Field*)this)[idx];
    }
};

struct Field {
    iptr _index;
    const char* _field;
    const char* _alias;
};
struct Record : public Enumeration<Field> {
    Field _name    = Field{ 0, "_name"   , "姓名" };
    Field _math    = Field{ 1, "_math"   , "数学" };
    Field _chinese = Field{ 2, "_chinese", "语文" };
    Field _english = Field{ 3, "_english", "英语" };
    Field _average = Field{ 4, "_average", "平均分" };
} _record;

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
    fprintf(stderr, "%td, %s, %s""\n", (iptr)_datum[0]._index, _datum[0]._field, _datum[0]._alias);
    fprintf(stderr, "%td, %s, %s""\n", (iptr)_record[2]._index, _record[2]._field, _record[2]._alias);

    return 0;
}