/* Super.c
Design: Polymorphism with Single Inheritance
Author: BSS9395
Update: 2019-08-22T01:58 +08 @ ShenZhen +08
*/

#include "Helper.h"
#include "Super.h"

Super makeSuper(void);
Super *newSuper(void);
static void Super_destruct(bool virtual_, Super *self);
static void Super_setID(bool virtual_, Super *self, const char *ID);
static const char *Super_getID(bool virtual_, Super *self);
static void readMe(Super *self);

Super makeSuper(void) {
	static SuperFunction superFunction = {
		.derived_offset = 0,
		.virtual_destruct = Super_destruct,
		.virtual_setID = Super_setID,
		.virtual_getID = Super_getID,
		.readMe = readMe
	};
	static SuperType superType = {
		.function = &superFunction
	};

	superType._ID = NULL;

	fprintf(stderr, "Super makeSuper(void);\n");
	return superType;
}

Super *newSuper(void) {
	fprintf(stderr, "Super *newSuper(void);\n");

	Super *super = (Super *)malloc(sizeof(Super));
	*super = makeSuper();
	return super;
}

/* virtual function */
static void Super_destruct(bool virtual_, Super *self) {
	if (virtual_) {
		if (0 != self->function->derived_offset) {
			Class *type = (Class *)((size_t)self + self->function->derived_offset);
			((ClassFunction *)type->function)->virtual_destruct(true, self);
		}
	}

	fprintf(stderr, "void Super_destruct(bool, Super *);\n");

	free(self->_ID);
	self->_ID = NULL;
	return;
}

/* virtual function */
static void Super_setID(bool virtual_, Super *self, const char *ID) {
	if (virtual_) {
		if (0 != self->function->derived_offset) {
			Class *type = (Class *)((size_t)self + self->function->derived_offset);
			((SuperFunction *)type->function)->virtual_setID(true, self, ID);
			return;
		}
	}

	fprintf(stderr, "void Super_setID(bool, Super *, const char *);\n");

	free(self->_ID);

	const char *addID = " Super ";
	self->_ID = (char *)malloc((strlen(ID) + strlen(addID) + 1) * sizeof(char));
	strcpy(self->_ID, ID);
	strcat(self->_ID, addID);
	return;
}

/* virtual function */
static const char *Super_getID(bool virtual_, Super *self) {
	if (virtual_) {
		if (0 != self->function->derived_offset) {
			Class *type = (Class *)((size_t)self + self->function->derived_offset);
			const char *ret = ((SuperFunction *)type->function)->virtual_getID(true, self);
			return ret;
		}
	}

	fprintf(stderr, "void Super_getID(bool, Super *);\n");

	return self->_ID;
}

static void readMe(Super *self) {
	fprintf(stdout,
		"Read me and my life."
		"\n"
	);
	return;
}
