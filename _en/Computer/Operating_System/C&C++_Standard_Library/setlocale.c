/* setlocale.c
Author: BSS9395
Update: 2021-11-15T23:39:00+08@China-Guangdong-Shenzhen+08
Design: C Standard Library: setlocale
Encode: UTF-8; UNIX
Option: /utf-8; /source-charset:utf-8 /execution-charset:utf-8
Option: -finput-charset-UTF-8 -fexec-charset=UTF-8
*/

/*
// C Standard Library: setlocale
#include <locale.h>
char *setlocale(int category, const char *locale);
*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CString_Literal() {
    // system("chcp 65001");
    setlocale(LC_ALL, ".UTF-8");
    fprintf(stderr, "locale = %s""\n", setlocale(LC_ALL, NULL));

    char _char[] = "C:\\你好""\n";
    wchar_t _wchar[] = L"C:\\你好\n";

    fprintf(stderr, "sizeof(_char) = %zd, %s", sizeof(_char), _char);
    fprintf(stderr, "sizeof(_wchar) = %zd, %ls", sizeof(_wchar), _wchar);
}

int main(int argc, char *argv[]) {
    CString_Literal();

    return 0;
}
