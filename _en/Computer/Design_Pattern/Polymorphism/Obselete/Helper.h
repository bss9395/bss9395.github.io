/* Helper.h
Design: Polymorphism with Single Inheritance
Author: BSS9395
Update: 2019-08-22T01:58 +08 @ ShenZhen +08
*/

#ifndef Helper_h
#define Helper_h

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _ClassType_     Class;
typedef struct _ClassType_     ClassType;
typedef struct _ClassFunction_ ClassFunction;

struct _ClassFunction_ {
	size_t derived_offset;
	void(*virtual_destruct)(bool, void *);
};

struct _ClassType_ {
	ClassFunction *function;
};

static void destruct(void *self);
static void destroy(void *self);


static void destruct(void *self) {
	Class *type = (Class *)self;
	type->function->virtual_destruct(true, self);

	// fprintf(stderr, "void destruct(void *);\n");
	return;
}

static void destroy(void *self) {
	destruct(self);
	free(self);

	fprintf(stderr, "void destroy(void *);\n");
	return;
}

#endif // Helper_h
