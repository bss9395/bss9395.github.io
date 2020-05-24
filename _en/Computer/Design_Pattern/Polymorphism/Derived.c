
#ifndef Derived_h
#define Derived_h

#define Super_c
#include "Super.c"

typedef struct _Derived_ Derived;

struct _Derived_ {
	Super _super_;
	iptr _offset_;

	void(*Virtual_Destruct)(Derived *self);
	iptr(*Virtual_SetID)(Derived *self, char *id);
	char *(*Virtual_GetID)(Derived *self);
	iptr(*ShowMe)(Derived *self);

	char *_desc;
};

Derived MakeDerived();
Derived *NewDerived();

#endif // Derived_h

#ifndef Derived_c
#define Derived_c

static void Virtual_Destruct(Derived *self);
static iptr Virtual_SetID(Derived *self, char *id);
static char *Virtual_GetID(Derived *self);
static iptr ShowMe(Derived *self);

Derived MakeDerived() {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	static Derived derived = {
		._offset_ = 0,
		.Virtual_Destruct = Virtual_Destruct,
		.Virtual_SetID = Virtual_SetID,
		.Virtual_GetID = Virtual_GetID,
		.ShowMe = ShowMe
	};
	derived._super_ = MakeSuper();
	derived._super_._offset_ = offsetof(Derived, _offset_);

	const char *desc = "Show Me Your Passionate Love.";
	derived._desc = (char *)malloc(strlen(desc) + 1);
	memcpy(derived._desc, desc, strlen(desc) + 1);

	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	return derived;
}

Derived *NewDerived() {
	Derived *derived = (Derived *)malloc(sizeof(Derived));
	*derived = MakeDerived();

	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	return derived;
}


static void Virtual_Destruct(Derived *self) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);

	free(self->_desc);
}

static iptr Virtual_SetID(Derived *self, char *id) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	iptr ret = 0;
	Super *jump = (Super *)self;
	if (0 != self->_offset_) {
		jump = Jump((void *)self, self->_offset_);
		jump->Virtual_SetID((void *)self, id);
	}
	else {
		free(jump->_id);
		const char *addID = "#Derived";
		jump->_id = (char *)malloc(strlen(id) + strlen(addID) + 1);
		strcpy(jump->_id, id);
		strcat(jump->_id, addID);
		ret += 1;
	}

	return ret;
}

static char *Virtual_GetID(Derived *self) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);

	char *ret = NULL;
	Super *jump = (Super *)self;
	if (0 != self->_offset_) {
		jump = Jump((void *)self, self->_offset_);
		ret = jump->Virtual_GetID((void *)self);
	}
	else {
		ret = jump->_id;
	}

	return ret;
}

static iptr ShowMe(Derived *self) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	iptr ret = 0;

	fprintf(stdout, "%s""\n", self->_desc);
	ret += 1;

	return ret;
}


#endif // Derived_c
