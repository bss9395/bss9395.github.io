/* Boy.c
Design: Polymorphism with Single Inheritance
Author: BSS9395
Update: 2019-08-22T01:58 +08 @ ShenZhen +08
*/

#include "Helper.h"
#include "Boy.h"

Boy makeBoy(void);
Boy *newBoy(void);
static void Boy_destruct(Boy *self);
static void Boy_setID(Boy *self, const char *ID);
static const char *Boy_getID(Boy *self);
static void leadMe(Boy *self);

Boy makeBoy(void) {
	static BoyFunction boyFunction = {
		.derived_offset = 0,
		.virtual_destruct = Boy_destruct,
		.virtual_setID = Boy_setID,
		.virtual_getID = Boy_getID,
		.leadMe = leadMe
	};
	static BoyType boyType = {
		.function = &boyFunction
	};

	boyType.derived = makeDerived();
	boyType.derived.function->derived_offset = offsetof(BoyType, function);

	boyType._info = NULL;

	fprintf(stderr, "Boy makeBoy(void);\n");
	return boyType;
}

Boy *newBoy(void) {
	fprintf(stderr, "Boy *newBoy(void);\n");

	Boy *boy = (Boy *)malloc(sizeof(Boy));
	*boy = makeBoy();
	return boy;
}

static void Boy_destruct(Boy *self) {
	static bool virtual_ = true;
	if (virtual_) {
		if (0 != self->function->derived_offset) {
			virtual_ = false;
			Class *type = (Class *)((size_t)self + self->function->derived_offset);
			((ClassFunction *)type->function)->virtual_destruct(self);
		}
	}
	virtual_ = true;

	fprintf(stderr, "void Boy_destruct(Boy *);\n");

	free(self->_info);
	self->_info = NULL;
	return;
}

static void Boy_setID(Boy *self, const char *ID) {
	static bool virtual_ = true;
	if (virtual_) {
		if (0 != self->function->derived_offset) {
			virtual_ = false;
			Class *type = (Class *)((size_t)self + self->function->derived_offset);
			((BoyFunction *)type->function)->virtual_setID(self, ID);
			return;
		}
	}
	virtual_ = true;

	fprintf(stderr, "void Boy_setID(Boy *, const char *);\n");

	/* override virtual function */
	free(self->derived.super._ID);

	const char *addID = " Boy ";
	self->derived.super._ID = (char *)malloc((strlen(ID) + strlen(addID) + 1) * sizeof(char));
	strcpy(self->derived.super._ID, ID);
	strcat(self->derived.super._ID, addID);
	return;
}

static const char *Boy_getID(Boy *self) {
	static bool virtual_ = true;
	if (virtual_) {
		if (0 != self->function->derived_offset) {
			virtual_ = false;
			Class *type = (Class *)((size_t)self + self->function->derived_offset);
			const char *ret = ((BoyFunction *)type->function)->virtual_getID(self);
			return ret;
		}
	}
	virtual_ = true;

	fprintf(stderr, "const char *Boy_getID(Boy *);\n");

	/* override virtual function */
	return self->derived.super._ID;
}

static void leadMe(Boy *self) {
	fprintf(stdout,
		"Lead me to your world."
		"\n"
	);
	return;
}
