/* Helper.h
Design: Polymorphism
Authro: BSS9395
Update: 2019-08-20T21:26 +08 @ ShenZhen +08
*/

#ifndef Helper_h
#define Helper_h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _BaseType Base;
typedef struct _BaseType BaseType;
typedef struct _BaseFunction BaseFunction;

struct _BaseFunction {
	long size;
	void(*destruct)(void *);
	const char *(*represent)(void *);
};

struct _BaseType {
	BaseFunction *virtual;
};

void destruct(void *self);
void destroy(void *self);
void *offset(void *self, size_t size);


inline void destruct(void *self) {
	Base *base = (Base *)self;
	base->virtual->destruct(base);
	// fprintf(stderr, "void destruct(void *);\n");
}

inline void destroy(void *self) {
	destruct(self);
	free(self);
	fprintf(stderr, "void destroy(void *);\n");
}

inline void *offset(void *self, size_t size) {
	Base *base = (Base *)self;
	ptrdiff_t diff = base->virtual->size - size;

	return (void *)((size_t)self + diff);
}

#endif // Helper_h
