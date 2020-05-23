/* Boy.h
Design: Polymorphism with Single Inheritance
Author: BSS9395
Update: 2019-08-22T01:58 +08 @ ShenZhen +08
*/

#ifndef Boy_h
#define Boy_h

#include "Derived.h"

typedef struct _BoyType_     Boy;
typedef struct _BoyType_     BoyType;
typedef struct _BoyFunction_ BoyFunction;

struct _BoyFunction_ {
	size_t derived_offset;
	void(*virtual_destruct)(bool, Boy *);

	void(*virtual_setID)(bool, Boy *, const char *);
	const char *(*virtual_getID)(bool, Boy *);

	void(*leadMe)(Boy *);
};
struct _BoyType_ {
	DerivedType derived;

	BoyFunction *function;
	char *_info;
};

Boy makeBoy(void);
Boy *newBoy(void);


#endif // Boy_h
