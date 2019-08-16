/* Helper.h
Design: decoupling
Author: BSS9395
Update: 2019-08-10T21:13
*/

#ifndef Helper_h
#define Helper_h

#include <stdio.h>
#include <stdarg.h>

typedef struct {
	void(*destruct)(void *cls);
	const char *(*represent)(void *cls);
} Class;


  void destruct(void *cls) {
	((Class *)cls)->destruct(cls);
}

  const char *represent(void *cls) {
	return ((Class *)cls)->represent(cls);
}

  void print(FILE *out, void *element, ...) {
	if (element) {
		fprintf(out, represent(element));
		return;
	}

	va_list args;
	va_start(args, element);
	vfprintf(out, va_arg(args, const char *), args);
	va_end(args);
}

typedef enum {
	LE = -2,
	LT = -1,
	EQ = 0,
	GT = +1,
	GE = +2,

	ASC = LT,
	DES = GT
} CP;

  CP compare(void *lhs, void *rhs) {
	if (lhs < rhs) {
		return LT;
	}
	else if (lhs == rhs) {
		return EQ;
	}
	return GT;
}

#endif // Helper_h
