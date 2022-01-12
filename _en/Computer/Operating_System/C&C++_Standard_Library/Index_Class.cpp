/* Index_Class.cpp
Author: BSS9395
Update: 2022-01-12T22:05:00+08@China-Guangdong-Shenzhen+08
Design: C Macro Function: Index_Class, Index_Object, Offset_Class, Offset_Object
*/

#include <iostream>
#include <string>

typedef intptr_t iptr;
#define Index_Class(Object, _member)   (((iptr)&((Object *)0)->_member - (iptr)0) / (iptr)sizeof(((Object *)0)->_member))
#define Index_Object(object, _member)  (((iptr)&object._member - (iptr)&object)   / (iptr)sizeof(object._member))
#define Offset_Class(Object, _member)  ((iptr)&((Object *)0)->_member - (iptr)0)
#define Offset_Object(object, _member) ((iptr)&object._member - (iptr)&object)

struct Datum {
    static inline struct EMark {
        const char *_ID = "ID";
        const char *_Name = "Name";
        const char *_Gender = "Gender";
        const char *_Date = "Date";
        const char *_Nationality = "Nationality";
        const char *_Score = "Score";

        EMark() {

        }
    } _Mark;

    std::string _ID = "20220112173800";
    std::string _name = "璀璨星辰";
    std::string _gender = "男";
    std::string _date = "1993-09-05";
    std::string _nationality = "汉";
    double _score = 99.9;
};

int main(int argc, char *argv[]) {
    iptr index_class = Index_Class(Datum::EMark, _Gender);
    iptr index_object = Index_Object(Datum::_Mark, _Gender);
    iptr offset_class = Offset_Class(Datum::EMark, _Gender);
    iptr offset_object = Offset_Object(Datum::_Mark, _Gender);
    fprintf(stderr, "index_class = %td""\n", index_class);
    fprintf(stderr, "index_object = %td""\n", index_object);
    fprintf(stderr, "offset_class = %td""\n", offset_class);
    fprintf(stderr, "offset_object = %td""\n", offset_object);

    Datum datum;
    fprintf(stderr, "datum._ID = %s""\n", datum._ID.data());
    fprintf(stderr, "datum._Mark._ID = %s""\n", datum._Mark._ID);

    return 0;
}
