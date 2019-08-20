/* Super.c
Design: Polymorphism
Authro: BSS9395
Update: 2019-08-20T21:26 +08 @ ShenZhen +08
*/

#include "Super.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Super mkSuper(void);
Super *newSuper(void);

inline void deSuper(Super *self);
inline void Super_setID(Super *self, const char *ID);
inline const char *Super_getID(Super *self);
inline Super *newSuper(void);


Super mkSuper(void) {
	static SuperFunction superVirtual = {
		.size = sizeof(SuperType),
		.destruct = deSuper,
		.virtual_setID = Super_setID,
		.virtual_getID = Super_getID
	};
	static SuperType superType = { &superVirtual };

	superType._ID = NULL;

	fprintf(stderr, "void mkSuper(Super *);\n");
	return superType;
}

Super *newSuper(void) {
	fprintf(stderr, "Super *newSuper();\n");

	Super *super = (Super *)malloc(sizeof(Super));
	*super = mkSuper();
	return super;
}

inline void deSuper(Super *self) {
	fprintf(stderr, "void deSuper(Super *);\n");

	if (NULL != self->_ID) {
		free(self->_ID);
		self->_ID = NULL;
	}
}

inline void Super_setID(Super *self, const char *ID) {
	fprintf(stderr, "void Super_setID(Super *, const char *);\n");

	if (NULL != self->_ID) {
		free(self->_ID);
	}

	self->_ID = (char *)malloc((strlen(ID) + 1) * sizeof(char));
	strcpy(self->_ID, ID);
}

inline const char *Super_getID(Super *self) {
	fprintf(stderr, "const char *Super_getID(Super *);\n");

	return self->_ID;
}
