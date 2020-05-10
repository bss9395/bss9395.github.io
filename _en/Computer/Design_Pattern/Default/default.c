#include <stdio.h>  
#include <stdarg.h>

#define DEFAULT(value, fallback)  (#value[0] ? value + 0 : fallback)

#define FUNC(d1, d2) \
    func(DEFAULT(d1, 12.0), DEFAULT(d2, 23.0))
void func(double d1, double d2) {
	printf("%lf, %lf\n", d1, d2);
}


void Default(double val, char *def) {
	char del = ':';
	if (def != NULL) {
		del = *def;
	}

	printf("%lf, %c\n", val, del);
}


int main(int argc, char* argv[]) {
	FUNC(, );
	FUNC(2.0, );
	FUNC(, 3.0);
	FUNC(2.0, 3.0);

	Default(12.23, NULL);

	return 0;
}
