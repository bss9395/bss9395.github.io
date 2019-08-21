/* Super.h
Design: Polymorphism with Single Inheritance
Author: BSS9395
Update: 2019-08-22T01:58 +08 @ ShenZhen +08
*/

#ifndef Super_h
#define Super_h

typedef struct _SuperType_     Super;
typedef struct _SuperType_     SuperType;
typedef struct _SuperFunction_ SuperFunction;

struct _SuperFunction_ {
	size_t derived_offset;
	void(*virtual_destruct)(Super *);

	void(*virtual_setID)(Super *, const char *);
	const char *(*virtual_getID)(Super *);

	void(*readMe)(Super *);
};

struct _SuperType_ {
	SuperFunction *function;
	char *_ID;
};

Super makeSuper(void);
Super *newSuper(void);

#endif // Super_h
