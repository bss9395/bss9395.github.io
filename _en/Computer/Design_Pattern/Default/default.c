#include <stdio.h>  
#include <stdarg.h>

#define DEFAULT(value, fallback)  (#value[0] ? value + 0 : fallback)


#define FUNC(d) \
    func(DEFAULT(d, 123.0))
void func(double d) {
	printf("%lf\n", d);
}


#define FUNC2(d1, d2) \
    func2(DEFAULT(d1, 12.0), DEFAULT(d2, 23.0))
void func2(double d1, double d2) {
	printf("%lf, %lf\n", d1, d2);
}


int main(int argc, char* argv[]) {
	FUNC();
	FUNC(12.23);

	FUNC2();
	FUNC2(, );
	FUNC2(2.0, );
	FUNC2(, 3.0);
	FUNC2(2.0, 3.0);

	return 0;
}
