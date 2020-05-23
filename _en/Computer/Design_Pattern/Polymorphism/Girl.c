
#ifndef Girl_h
#define Gril_h

#define Derived_c
#include "Derived.c"

typedef struct _Girl_ Girl;

struct _Girl_ {
	Derived _derived_;
	iptr _offset_;

	void(*Virtual_Destruct)(Girl *self);
	iptr(*Virtual_SetID)(Girl *self, char *id);
	char *(*Virtual_GetID)(Girl *self);
	iptr(*SeeYou)(Girl *self);

	char *_desc;
};

Girl MakeGirl();
Girl *NewGirl();

#endif // Girl_h

#ifndef Girl_c
#define Girl_c

static void Virtual_Destruct(Girl *self);
static iptr Virtual_SetID(Girl *self, char *id);
static char *Virtual_GetID(Girl *self);
static iptr SeeYou(Girl *self);

Girl MakeGirl() {
	static Girl girl = {
		._offset_ = 0,
		.Virtual_Destruct = Virtual_Destruct,
		.Virtual_SetID = Virtual_SetID,
		.Virtual_GetID = Virtual_GetID,
		.SeeYou = SeeYou
	};

	girl._derived_ = MakeDerived();
	girl._derived_._offset_ = offsetof(Girl, _offset_);

	const char *desc = "See You in Near Future.";
	girl._desc = (char *)malloc(strlen(desc) + 1);
	memcpy(girl._desc, desc, strlen(desc) + 1);

	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	return girl;
}

Girl *NewGirl() {
	Girl *girl = (Girl *)malloc(sizeof(Girl));
	*girl = MakeGirl();

	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	return girl;
}

static void Virtual_Destruct(Girl *self) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	free(self->_desc);
}

static iptr Virtual_SetID(Girl *self, char *id) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	iptr ret = 0;

	if (0 != self->_offset_) {
		Super *jump = (Super *)self;
		do {
			jump = (Super *)((iptr)self + jump->_offset_);
		} while (0 != jump->_offset_);

		ret += jump->Virtual_SetID(self, id);
	}
	else {
		Super *data = (Super *)self;
		free(data->_id);
		const char *addID = "#Girl";
		data->_id = (char *)malloc(strlen(addID) + 1);
		strcpy(data->_id, id);
		strcat(data->_id, addID);
		ret += 1;
	}
	return ret;
}

static char *Virtual_GetID(Girl *self) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	char *ret = NULL;
	if (0 != self->_offset_) {
		Super *jump = (Super *)self;
		do {
			jump = (Super *)((iptr)self + jump->_offset_);
		} while (0 != jump->_offset_);

		ret = jump->Virtual_GetID(self);
	}
	else {
		Super *data = (Super *)self;
		ret = data->_id;
	}
	return ret;
}

static iptr SeeYou(Girl *self) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	iptr ret = 0;

	fprintf(stdout, "%s""\n", self->_desc);
	ret += 1;

	return ret;
}


#endif // Girl_c
