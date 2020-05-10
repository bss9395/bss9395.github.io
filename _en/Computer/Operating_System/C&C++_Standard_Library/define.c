#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR(str1, str2, str3) \
    printf("str1 is " #str1 ", str2 is " #str2 ", str3 is " #str3 ".\n");

#define GLUE(str) \
    printf("xstr is %s, glue xstr is %s.\n", "x"#str, "x"##str);

#define PRINT(...) \
    printf(__VA_ARGS__);


int main(int argc, char* argv[]) {
	STR(5.0, 'a', "abc");
	GLUE("abc");
	PRINT("str1 is %s, str2 is %s, str3 is %s.\n", "abc", "cde", "fgh");

	return 0;
}
