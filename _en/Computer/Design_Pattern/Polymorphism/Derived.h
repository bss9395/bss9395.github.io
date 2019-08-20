/* Derived.h
Design: Polymorphism
Authro: BSS9395
Update: 2019-08-20T19:13 +08
*/

#ifndef Derived_h
#define Derived_h

#include "Helper.h"
#include "Super.h"

typedef struct _DerivedType Derived;
typedef struct _DerivedType DerivedType;
typedef struct _DerivedFunction DerivedFunction;

struct _DerivedFunction {
	long size;
	void(*destruct)(Derived *);
	void(*virtual_setID)(Derived *, const char *);
	const char *(*virtual_getID)(Derived *);

	void(*setInfo)(Derived *, const char *);
	const char *(*getInfo)(Derived *self);
};

struct _DerivedType {
	DerivedFunction *function;

	SuperType super;
	char *_Info;
};

Derived mkDerived(void);
Derived *newDerived(void);

#endif // Derived_h
