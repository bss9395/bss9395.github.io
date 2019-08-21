/* Girl.c
Design: Polymorphism with Single Inheritance
Author: BSS9395
Update: 2019-08-22T01:58 +08 @ ShenZhen +08
*/

#include "Helper.h"
#include "Girl.h"

Girl makeGirl(void);
Girl *newGirl(void);
static void Girl_destruct(Girl *self);
static void Girl_setID(Girl *self, const char *Desc);
static const char *Girl_getID(Girl *self);
static void seeYou(Girl *self);

Girl makeGirl(void) {
	static GirlFunction girlFunction = {
		.derived_offset = 0,
		.virtual_destruct = Girl_destruct,
		.virtual_setID = Girl_setID,
		.virtual_getID = Girl_getID,
		.seeYou = seeYou
	};
	static GirlType girlType = {
		.function = &girlFunction
	};

	girlType.derived = makeDerived();
	girlType.derived.function->derived_offset = offsetof(GirlType, function);

	girlType._info = NULL;

	fprintf(stderr, "Girl makeGirl(void);\n");
	return girlType;
}

Girl *newGirl(void) {
	fprintf(stderr, "Girl *newGirl(void);\n");

	Girl *girl = (Girl *)malloc(sizeof(Girl));
	*girl = makeGirl();
	return girl;
}

static void Girl_destruct(Girl *self) {
	static bool virtual_ = true;
	if (virtual_) {
		if (0 != self->function->derived_offset) {
			virtual_ = false;
			Class *type = (Class *)((size_t)self + self->function->derived_offset);
			((ClassFunction *)type->function)->virtual_destruct(self);
			return;
		}
	}
	virtual_ = true;

	fprintf(stderr, "void Girl_destruct(Girl *);\n");

	free(self->_info);
	self->_info = NULL;
	return;
}

static void Girl_setID(Girl *self, const char *ID) {
	static bool virtual_ = true;
	if (virtual_) {
		if (0 != self->function->derived_offset) {
			virtual_ = false;
			Class *type = (Class *)((size_t)self + self->function->derived_offset);
			((GirlFunction *)type->function)->virtual_setID(self, ID);
			return;
		}
	}
	virtual_ = true;

	fprintf(stderr, "void Girl_setID(Girl *, const char *);\n");

	/* inherit virtual function for Derived */
	self->derived.function->virtual_setID((Derived *)self, ID);
	return;
}

static const char *Girl_getID(Girl *self) {
	static bool virtual_ = true;
	if (virtual_) {
		if (0 != self->function->derived_offset) {
			virtual_ = false;
			Class *type = (Class *)((size_t)self + self->function->derived_offset);
			const char *ret = ((GirlFunction *)type->function)->virtual_getID(self);
			return ret;
		}
	}
	virtual_ = true;

	fprintf(stderr, "const char *Girl_getID(Girl *);\n");

	/* inherit virtual function from Derived */
	const char *ret = self->derived.function->virtual_getID((Derived *)self);
	return ret;
}

static void seeYou(Girl *self) {
	fprintf(stdout,
		"See you in near future."
		"\n"
	);

	return;
}
