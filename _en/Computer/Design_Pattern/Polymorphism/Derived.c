/* Derived.c
Design: Polymorphism with Single Inheritance
Author: BSS9395
Update: 2019-08-22T01:58 +08 @ ShenZhen +08
*/

#include "Helper.h"
#include "Derived.h"

Derived makeDerived(void);
Derived *newDerived(void);
static void Derived_destruct(Derived *self);
static void Derived_setID(Derived *self, const char *ID);
static const char *Derived_getID(Derived *self);
static void showMe(Derived *self);

Derived makeDerived(void) {
	static DerivedFunction derivedFunction = {
		.derived_offset = 0,
		.virtual_destruct = Derived_destruct,
		.virtual_setID = Derived_setID,
		.virtual_getID = Derived_getID,
		.showMe = showMe
	};
	static DerivedType derivedType = {
		.function = &derivedFunction
	};

	derivedType.super = makeSuper();
	derivedType.super.function->derived_offset = offsetof(DerivedType, function);

	derivedType._desc = NULL;

	fprintf(stderr, "Derived makeDerived(void);\n");
	return derivedType;
}

Derived *newDerived(void) {
	fprintf(stderr, "Derived *newDerived(void);\n");

	DerivedType *derivedType = (DerivedType *)malloc(sizeof(DerivedType));
	*derivedType = makeDerived();
	return derivedType;
}

static void Derived_destruct(Derived *self) {
	static bool virtual_ = true;
	if (virtual_) {
		if (0 != self->function->derived_offset) {
			virtual_ = false;
			Class *type = (Class *)((size_t)self + self->function->derived_offset);
			((ClassFunction *)type->function)->virtual_destruct(self);
		}
	}
	virtual_ = true;

	fprintf(stderr, "void Derived_destruct(Derived *);\n");

	free(self->_desc);
	self->_desc = NULL;
	return;
}

static void Derived_setID(Derived *self, const char *ID) {
	static bool virtual_ = true;
	if (virtual_) {
		if (0 != self->function->derived_offset) {
			virtual_ = false;
			Class *type = (Class *)((size_t)self + self->function->derived_offset);
			((DerivedFunction *)type->function)->virtual_setID(self, ID);
			return;
		}
	}
	virtual_ = true;

	fprintf(stderr, "void Derived_setID(Derived *, const char *);\n");

	/* override virtual function */
	free(self->super._ID);

	const char *addID = " Derived ";
	self->super._ID = (char *)malloc((strlen(ID) + strlen(addID) + 1) * sizeof(char));
	strcpy(self->super._ID, ID);
	strcat(self->super._ID, addID);
	return;
}

static const char *Derived_getID(Derived *self) {
	static bool virtual_ = true;
	if (virtual_) {
		if (0 != self->function->derived_offset) {
			virtual_ = false;
			Class *type = (Class *)((size_t)self + self->function->derived_offset);
			const char *ret = ((DerivedFunction *)type->function)->virtual_getID(self);
			return ret;
		}
	}
	virtual_ = true;

	fprintf(stderr, "const char *Derived_getID(Derived *);\n");

	/* override virtual function */
	return self->super._ID;
}

static void showMe(Derived *self) {
	fprintf(stdout,
		"Show me your passionate love."
		"\n"
	);
	return;
}
