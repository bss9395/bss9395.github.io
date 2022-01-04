/* mbstowcs.cpp
Author: BSS9395
Update: 2022-01-04T21:19:00+08@China-Guangdong-Shenzhen+08
Design: C Standard Library: mbstowcs
Encode: UTF-8
*/

/*
#include <stdlib.h>
size_t mbstowcs (wchar_t* dest, const char* src, size_t max);
size_t wcstombs (char* dest, const wchar_t* src, size_t max);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <clocale>
#include <cstdlib>
#include <fstream>
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

iptr Dump_File(std::string &filename_local, const std::string &filename_utf8) {
    std::wstring unicode = std::wstring(1024, 0);
    char *locale = NULL;
    iptr numb = 0;

    locale = setlocale(LC_ALL, _ELocale._UTF_8);  // note: terminal unaffected, bug on Linux terminal.
    if (locale == NULL) {
        fprintf(stderr, "\n""[%td] %s", (iptr)__LINE__, "invalid locale");
        exit(EXIT_FAILURE);
    }
    numb = mbstowcs(unicode.data(), filename_utf8.data(), unicode.size());
    locale = setlocale(LC_ALL, _ELocale._Local);
    if (locale == NULL) {
        fprintf(stderr, "\n""[%td] %s", (iptr)__LINE__, "invalid locale");
        exit(EXIT_FAILURE);
    }
    numb = wcstombs(filename_local.data(), unicode.data(), filename_local.size());

    FILE *file = fopen(filename_local.data(), "wb");
    if (file == NULL) {
        fprintf(stderr, "\n""[%td] %s", (iptr)__LINE__, "file == NULL");
        exit(EXIT_FAILURE);
    }
    char test[11] = { // encoded in zh_CN.936(GBK)
        (char)0x23, (char)0x23, (char)0x23, (char)0x20, (char)0xC4, (char)0xE3, (char)0xBA, (char)0xC3, (char)0xA3, (char)0xA1,
        (char)0x0A // note: \n
    };
    fwrite(test, sizeof(char), sizeof(test), file);
    fclose(file);
    return 0;
}


iptr Transcode(const std::string &filename_local) {
    std::string buffer = "";
    std::wstring text = L"";
    char *locale = NULL;
    iptr numb = 0;

    FILE *file = fopen(filename_local.data(), "rt");     // note: \r\n => \n
    if (file == NULL) {
        fprintf(stderr, "\n""[%td] %s", (iptr)__LINE__, "file == NULL");
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    iptr leng = ftell(file);
    rewind(file);
    buffer.resize(leng);
    fread(buffer.data(), sizeof(char), leng, file);      // note: locale doesn't matter.
    fclose(file);
    fprintf(stderr, "\n========================================");

    ////////////////////////////////////

    locale = (char *)setlocale(LC_ALL, _ELocale._UTF_8);      // unnormal output
    if (locale == NULL) {
        fprintf(stderr, "\n""[%td] %s", (iptr)__LINE__, "invalid locale");
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "\n""locale = %s", locale);
    fprintf(stderr, "\n""leng = %td", leng);
    fprintf(stderr, "\n""%s", buffer.data());            // note: no output if locale dismatches.
    fprintf(stderr, "\n");
    for (iptr i = 0; i < leng; i += 1) {
        fprintf(stderr, "%x,", (unch)buffer.data()[i]);
    }
    fprintf(stderr, "\n========================================");

    ////////////////////////////////////

    locale = (char *)setlocale(LC_ALL, _ELocale._ISO_8859_1); // unnormal output
    if (locale == NULL) {
        fprintf(stderr, "\n""[%td] %s", (iptr)__LINE__, "invalid locale");
        exit(EXIT_FAILURE);
    }
    text.resize(leng);
    numb = mbstowcs(text.data(), buffer.data(), leng);
    if (numb < 0) {
        fprintf(stderr, "\n""[%td] %s", (iptr)__LINE__, "invalid multibyte character is encountered.");
        exit(EXIT_FAILURE);
    }
    text.resize(numb);

    fprintf(stderr, "\n""locale = %s", locale);
    fprintf(stderr, "\n""numb = %td", numb);
    // fwprintf(stdout, L"\n""%s", text.data());          // note: stderr, mess. two bugs on g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
    fprintf(stderr, "\n""%ls", text.data());
    fprintf(stderr, "\n");
    for (iptr i = 0; i < leng; i += 1) {
        fprintf(stderr, "%x,", (wide)text.data()[i]);
    }
    fprintf(stderr, "\n========================================");

    ////////////////////////////////////

    locale = (char *)setlocale(LC_ALL, _ELocale._GBK);        // normal output
    if (locale == NULL) {
        fprintf(stderr, "\n""[%td] %s", (iptr)__LINE__, "invalid locale");
        exit(EXIT_FAILURE);
    }
    text.resize(leng);
    numb = mbstowcs(text.data(), buffer.data(), leng);
    if (numb < 0) {
        fprintf(stderr, "\n""[%td] %s", (iptr)__LINE__, "invalid multibyte character is encountered.");
        exit(EXIT_FAILURE);
    }
    text.resize(numb);

    fprintf(stderr, "\n""locale = %s", locale);
    fprintf(stderr, "\n""numb = %td", numb);
    // fwprintf(stdout, L"\n""%s", text.data());         // note: stderr, mess. two bugs on g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
    fprintf(stderr, "\n""%ls", text.data());
    fprintf(stderr, "\n");
    for (iptr i = 0; i < leng; i += 1) {
        fprintf(stderr, "%x,", (wide)text.data()[i]);
    }
    fprintf(stderr, "\n========================================");

    return 0;
}

int main(int argc, char *argv[]) {
    std::string filename_utf8 = std::string("你好！.md");
    std::string filename_local = std::string(1024, 0);

    Dump_File(filename_local, filename_utf8);
    Transcode(filename_local);

    return 0;
}
