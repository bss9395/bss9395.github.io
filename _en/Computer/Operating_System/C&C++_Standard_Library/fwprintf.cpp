/* fwprintf.cpp
Author: BSS9395
Update: 2022-01-04T21:36:00+08@China-Guangdong-Shenzhen+08
Design: C standard library: fwprintf
*/

/*
#include <wchar.h>
int fwprintf (FILE* stream, const wchar_t* format, ...);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <clocale>
#include <cstdlib>
#include <iostream>
#include <string>

typedef unsigned char unch;
typedef wchar_t wide;       // note: typedef unsigned short wchar_t;
typedef intptr_t iptr;

#ifdef _WIN32 
#define Platform(windows, linux) windows
#elif __linux__
#define Platform(windows, linux) linux
#endif 

typedef const char *Locale;
struct {
    Locale _Local;
    Locale _UTF_8;
    Locale _ISO_8859_1;
    Locale _GBK;
} _ELocale = {
    Platform("", ""),
    Platform(".UTF-8", "en_GB.UTF-8"),
    Platform(".28591", "en_GB.ISO-8859-1"),
    Platform(".936", "zh_CN.GBK")
};

int main(int argc, char *argv[]) {
    char *locale = setlocale(LC_ALL, _ELocale._UTF_8);
    fprintf(stderr, "%s""\n", locale);

    std::wstring buffer_unicode = L"### 你好！";
    std::string buffer_utf8 = std::string(1024, 0);
    iptr numb = wcstombs(buffer_utf8.data(), buffer_unicode.data(), 100);

    Platform(
        fwprintf(stderr, L"%s", buffer_unicode.data()),
        fwprintf(stdout, L"%s", buffer_utf8.data())     // note: stderr, bug on g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
    );

    return 0;
}
