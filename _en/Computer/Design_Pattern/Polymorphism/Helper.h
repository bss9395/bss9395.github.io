/* Helper.h
Design: Polymorphism
Authro: BSS9395
Update: 2019-08-20T01:22 +08
*/

#ifndef Helper_h
#define Helper_h

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _BaseType Base;
typedef struct _BaseType BaseType;
typedef struct _BaseFunction BaseFunction;

struct _BaseFunction {
	Base(*construct)(void);
	void(*destruct)(void *);
	const char *(*represent)(void *);
};

struct _BaseType {
	BaseFunction *function;
};

inline void destruct(void *self);
inline void destroy(void *self);


inline void destruct(void *self) {
	Base *base = (Base *)self;
	base->function->destruct(base);
	// fprintf(stderr, "void destruct(void *);\n");
}

inline void destroy(void *self) {
	destruct(self);
	free(self);
	fprintf(stderr, "void destroy(void *);\n");
}

#endif // Helper_h
