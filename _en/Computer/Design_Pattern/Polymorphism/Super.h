/* Super.h
Design: Polymorphism
Authro: BSS9395
Update: 2019-08-20T21:26 +08 @ ShenZhen +08
*/

#ifndef Super_h
#define Super_h

#include "Helper.h"

typedef struct _SuperType Super;
typedef struct _SuperType SuperType;
typedef struct _SuperFunction SuperFunction;

struct _SuperFunction {
	long size;
	void(*destruct)(Super *);
	void(*virtual_setID)(Super *, const char *);
	const char *(*virtual_getID)(Super *);


};

struct _SuperType {
	SuperFunction *function;

	char *_ID;
};

Super mkSuper(void);
Super *newSuper(void);

#endif // Super_h
