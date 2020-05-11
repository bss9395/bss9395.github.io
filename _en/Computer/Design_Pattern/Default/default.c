/* default.c
Author: BSS9395
Update: 2020-05-10T20:00:00@China-Guangdong-Zhanjiang
Design: C Function Default Parameters
*/

#include <stdio.h>  
#include <stdarg.h>

#define DEFAULT(value, fallback)  (#value[0] ? value + 0 : fallback)

#define FUNC(d1, d2) \
    func(DEFAULT(d1, 12.0), DEFAULT(d2, 23.0))
void func(double d1, double d2) {
	printf("%lf, %lf\n", d1, d2);
}


void Default(double val, char *def1, char *def2) {
	char del = ':';
	if (def1 != NULL) {
		del = *def1;
	}
	if (def2 == NULL) {
		def2 = &del;
	}

	printf("%lf, %c, %c\n", val, del, *def2);
}


int main(int argc, char* argv[]) {
	FUNC(, );
	FUNC(2.0, );
	FUNC(, 3.0);
	FUNC(2.0, 3.0);

	char ch = '#';
	Default(12.23, NULL, NULL);
	Default(23.34, &ch, &ch);

	return 0;
}
