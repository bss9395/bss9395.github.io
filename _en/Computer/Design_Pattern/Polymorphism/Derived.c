/* Derived.c
Design: Polymorphism
Authro: BSS9395
Update: 2019-08-20T21:26 +08 @ ShenZhen +08
*/

#include "Derived.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Derived mkDerived(void);
Derived *newDerived(void);

inline void deDerived(Derived *self);
inline void Derived_setID(Derived *self, const char *id);
inline const char *Derived_getID(Derived *self);
inline void setInfo(Derived *self, const char *info);
inline const char *getInfo(Derived *self);


Derived mkDerived(void) {
	static DerivedFunction derivedFunction = {
		.size = sizeof(DerivedType),
		.destruct = deDerived,
		.virtual_setID = Derived_setID,
		.virtual_getID = Derived_getID,
		.setInfo = setInfo,
		.getInfo = getInfo
	};
	static DerivedType derivedType = { &derivedFunction };

	derivedType.super = mkSuper();
	derivedType._Info = NULL;

	fprintf(stderr, "void mkDerived(Derived *);\n");
	return derivedType;
}

Derived *newDerived(void) {
	fprintf(stderr, "Derived *newDerived();\n");

	Derived *derived = (Derived *)malloc(sizeof(Derived));
	*derived = mkDerived();
	return derived;
}

inline void deDerived(Derived *self) {
	fprintf(stderr, "void deDerived(Derived *);\n");

	if (NULL != self->_Info) {
		free(self->_Info);
		self->_Info = NULL;
	}
	destruct(&self->super);
}

inline void Derived_setID(Derived *self, const char *id) {
	fprintf(stderr, "void Derived_setID(Derived *, const char *);\n");

	if (NULL != self->super._ID) {
		free(self->super._ID);
	}
	self->super._ID = (char *)malloc((strlen(id) + 1) * sizeof(char));
	strcpy(self->super._ID, id);
}

inline const char *Derived_getID(Derived *self) {
	fprintf(stderr, "const char *Derived_getID(Derived *);\n");

	return self->super._ID;
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
