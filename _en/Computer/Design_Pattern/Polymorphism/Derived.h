/* Derived.h
Design: Polymorphism with Single Inheritance
Author: BSS9395
Update: 2019-08-22T01:58 +08 @ ShenZhen +08
*/

#ifndef Derived_h
#define Derived_h

#include "Super.h"

typedef struct _DerivedType_     Derived;
typedef struct _DerivedType_     DerivedType;
typedef struct _DerivedFunction_ DerivedFunction;

struct _DerivedFunction_ {
	size_t derived_offset;
	void(*virtual_destruct)(Derived *);

	void(*virtual_setID)(Derived *, const char *);
	const char *(*virtual_getID)(Derived *);

	void(*showMe)(Derived *);
};

struct _DerivedType_ {
	SuperType super;

	DerivedFunction *function;
	char *_desc;
};

Derived makeDerived(void);
Derived *newDerived(void);

#endif // Derived_h
