#ifndef Super_h
#define Super_h

#include "Helper.h"


typedef struct _Super_ Super;

struct _Super_ {
	iptr _offset_;

	void(*Virtual_Destruct)(Super *self);
	iptr(*Virtual_SetID)(Super *self, char *id);
	char *(*Virtual_GetID)(Super *self);
	iptr(*ReadMe)(Super *self);

	char *_id;
	char *_desc;
};


Super MakeSuper();
Super *NewSuper();

#endif // Super_h

#ifndef Super_c
#define Super_c

static void Virtual_Destruct(Super *self);
static iptr Virtual_SetID(Super *self, char *id);
static char *Virtual_GetID(Super *self);
static iptr ReadMe(Super *self);


Super MakeSuper() {
	static Super super = {
		._offset_ = 0,
		.Virtual_Destruct = Virtual_Destruct,
		.Virtual_SetID = Virtual_SetID,
		.Virtual_GetID = Virtual_GetID,
		.ReadMe = ReadMe,
	};

	super._id = NULL;

	const char *desc = "Read Me and My Life.";
	super._desc = (char *)malloc(strlen(desc) + 1);
	memcpy(super._desc, desc, strlen(desc) + 1);

	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	return super;
}

Super *NewSuper() {
	Super *super = (Super *)malloc(sizeof(Super));
	*super = MakeSuper();

	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	return super;
}

static void Virtual_Destruct(Super *self) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);

	free(self->_id);
	free(self->_desc);
}

static iptr Virtual_SetID(Super *self, char *id) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	iptr ret = 0;
	Super *jump = (Super *)self;
	if (0 != self->_offset_) {
		jump = Jump((void *)self, self->_offset_);
		jump->Virtual_SetID((void *)self, id);
	}
	else {
		free(jump->_id);
		const char *addID = "#Super";
		jump->_id = (char *)malloc(strlen(id) + strlen(addID) + 1);
		strcpy(jump->_id, id);
		strcat(jump->_id, addID);
		ret += 1;
	}

	return ret;
}


static char *Virtual_GetID(Super *self) {
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

static iptr ReadMe(Super *self) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	iptr ret = 0;

	fprintf(stdout, "%s""\n", self->_desc);
	ret += 1;

	return ret;
}

#endif // Super_c
