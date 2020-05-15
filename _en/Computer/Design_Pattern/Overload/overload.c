/* overload.c
Author: BSS9395
Update: 2020-05-15T13:42:00+08@China-Guangdong-Zhanjiang+08
Design: Function Overload
*/


#include <stdio.h>

typedef int Ret;

typedef const char *Type;
const struct {
	Type _Int;
	Type _Double;
	Type _String;
} EType = { "Int", "Double", "String" };

typedef struct {
	Type type;
	union {
		int i;
		double d;
		char *s;
	};
} Load;


Ret Overload(Load load, int i, double d, char *s) {
	Ret ret = 0;

	if (load.type == EType._Int) {
		fprintf(stderr, "%d""\n", load.i);
	}
	else if (load.type == EType._Double) {
		fprintf(stderr, "%lf""\n", load.d);
	}
	else if (load.type == EType._String) {
		fprintf(stderr, "%s""\n", load.s);
	}

	return ret;
}


typedef void *Para;

Ret Override(Type type, Para para, int i, double d, char *s) {
	Ret ret = 0;

	if (type == EType._Int) {
		int pi = *(int *)para;
		fprintf(stderr, "%d""\n", pi);
	}
	else if (type == EType._Double) {
		double pd = *(double *)para;
		fprintf(stderr, "%lf""\n", pd);
	}
	else if (type == EType._String) {
		char *ps = *(char **)para;
		fprintf(stderr, "%s""\n", ps);
	}

	return ret;
}

int main(int argc, char *argv[]) {
	Load load = {
		.type = EType._Double,
		.d = 12.23
	};

	Overload(load, 1, 2.0, "str");

	////////////////////////////////////////

	double d = 23.34;
	Override(EType._Double, &d, 1, 2.0, "str");

	char *s = "abc";
	Override(EType._String, &s, 1, 2.0, "str");

	return 0;
}
