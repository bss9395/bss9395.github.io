/* String_Literal.cpp
Author: BSS9395
Update: 2021-11-10T01:04:00+08@China-Guangdong-Shenzhen+08
Design: C++ Standard String Literal
Encode: UTF-8; UNIX
Option: /utf-8; /source-charset:utf-8 /execution-charset:utf-8
Option: -finput-charset-UTF-8 -fexec-charset=UTF-8
*/

/*
// C++20 String Literal
"s-char-sequence"
L"s-char-sequence"
u8"s-char-sequence"
u"s-char-sequence"
U"s-char-sequence"
prefix(optional) R"delimiter(raw_characters)delimiter"
*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

void CString_Literal() {
    // system("chcp 65001");
    setlocale(LC_ALL, ".UTF-8");
    fprintf(stderr, "locale = %s""\n", setlocale(LC_ALL, NULL));

    char _char[] = "C:\\你好""\n";
    wchar_t _wchar[] = L"C:\\你好""\n";
    char _raw[] = R"(C:\你好
)";
    wchar_t _wraw[] = LR"(C:\你好
)";

    fprintf(stderr, "sizeof(_char) = %zd, %s", sizeof(_char), _char);
    fprintf(stderr, "sizeof(_wchar) = %zd, %ls", sizeof(_wchar), _wchar);
    fprintf(stderr, "sizeof(_raw) = %zd, %s", sizeof(_raw), _raw);
    fprintf(stderr, "sizeof(_wraw) = %zd, %ls", sizeof(_wraw), _wraw);

    ////////////////////////////////////
    fprintf(stderr, "%s""\n", "////////////////////////////////////////");

    //char8_t _char8[] = u8"C:\\你好""\n";  // C++20
    char16_t _char16[] = u"C:\\你好""\n";
    char32_t _char32[] = U"C:\\你好""\n";

    //fprintf(stderr, "sizeof(_char8) = %zd, %ls", sizeof(_char8), _char8);
    fprintf(stderr, "sizeof(_char16) = %zd""\n", sizeof(_char16));
    fprintf(stderr, "sizeof(_char32) = %zd""\n", sizeof(_char32));
}

void String_Literal() {
    // system("chcp 65001");
    setlocale(LC_ALL, ".UTF-8");
    fprintf(stderr, "locale = %s""\n", setlocale(LC_ALL, NULL));

    string _char = "C:\\你好""\n"s;
    wstring _wchar = L"C:\\你好""\n"s;
    string _raw = R"(C:\你好
)"s;
    wstring _wraw = LR"(C:\你好
)"s;

    cerr << "_char.length() = " << _char.length() << ", " << _char;
    wcerr << "_wchar.length() = " << _wchar.length() << ", " << _wchar;
    cerr << "_raw.length() = " << _raw.length() << ", " << _raw;
    wcerr << "_wraw.length() = " << _wraw.length() << ", " << _wraw;

    ////////////////////////////////////
    fprintf(stderr, "%s""\n", "////////////////////////////////////////");

    //u8string _char8 = u8"C:\\你好""\n"s;  // C++20
    u16string _char16 = u"C:\\你好""\n"s;
    u32string _char32 = U"C:\\你好""\n"s;

    //cerr << "_char8.length() = " << _char8.length() << endl;
    cerr << "_char16.length() = " << _char16.length() << endl;
    cerr << "_char32.length() = " << _char32.length() << endl;
}

int main(int argc, char *argv[]) {
    CString_Literal();
    // String_Literal();

    return 0;
}
