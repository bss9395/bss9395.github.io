/* Gril.h
Design: Polymorphism with Single Inheritance
Author: BSS9395
Update: 2019-08-22T01:58 +08 @ ShenZhen +08
*/

#ifndef Girl_h
#define Girl_h

#include "Derived.h"

typedef struct _GirlType_     Girl;
typedef struct _GirlType_     GirlType;
typedef struct _GirlFunction_ GirlFunction;

struct _GirlFunction_ {
	size_t derived_offset;
	void(*virtual_destruct)(bool, Girl *);

	void(*virtual_setID)(bool, Girl *, const char *);
	const char *(*virtual_getID)(bool, Girl *);

	void(*seeYou)(Girl *);
};
struct _GirlType_ {
	DerivedType derived;

	GirlFunction *function;
	char *_info;
};

Girl makeGirl(void);
Girl *newGirl(void);


#endif // Girl_h
