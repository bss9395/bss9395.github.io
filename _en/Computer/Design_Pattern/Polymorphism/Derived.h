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
	Derived(*construct)(void);
	void(*destruct)(Derived *);

	void(*setInfo)(Derived *, const char *);
	const char *(*getInfo)(Derived *);
};

struct _DerivedType {
	DerivedFunction *function;

	SuperType super;
	char *_Info;
};

inline Derived mkDerived(void);
inline void deDerived(Derived *self);
inline void setInfo(Derived *self, const char *info);
inline const char *getInfo(Derived *self);
inline Derived *newDerived(void);


inline Derived mkDerived(void) {
	static DerivedFunction derivedFunction = {
		sizeof(DerivedType), mkDerived, deDerived, setInfo, getInfo
	};
	static DerivedType derivedType = { &derivedFunction };

	derivedType.super = mkSuper();

	derivedType._Info = NULL;

	fprintf(stderr, "void mkDerived(Derived *);\n");
	return derivedType;
}

inline void deDerived(Derived *self) {
	fprintf(stderr, "void deDerived(Derived *);\n");

	if (NULL != self->_Info) {
		free(self->_Info);
		self->_Info = NULL;
	}
	destruct(&self->super);
}

inline void setInfo(Derived *self, const char *info) {
	self = offset(self, sizeof(Derived));
	fprintf(stderr, "void setInfo(Derived *, const char *);\n");

	if (NULL != self->_Info) {
		free(self->_Info);
	}
	self->_Info = (char *)malloc((strlen(info) + 1) * sizeof(char));
	strcpy(self->_Info, info);
}

inline const char *getInfo(Derived *self) {
	self = offset(self, sizeof(Derived));
	fprintf(stderr, "const char *getInfo(Derived *);\n");

	return self->_Info;
}

inline Derived *newDerived(void) {
	fprintf(stderr, "Derived *newDerived();\n");

	Derived *derived = (Derived *)malloc(sizeof(Derived));
	*derived = mkDerived();
	return derived;
}

#endif // Derived_h
