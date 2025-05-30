
#ifndef Boy_h
#define Boy_h

#define Derived_c
#include "Derived.c"

typedef struct _Boy_ Boy;

struct _Boy_ {
	Derived _derived_;
	iptr _offset_;

	void(*Virtual_Destruct)(Boy *self);
	iptr(*Virtual_SetID)(Boy *self, char *id);
	char *(*Virtual_GetID)(Boy *self);
	iptr(*LeadMe)(Boy *self);

	char *_desc;
};

Boy MakeBoy();
Boy *NewBoy();


#endif // Boy_h

#ifndef Boy_c
#define Boy_c

static void Virtual_Destruct(Boy *self);
static iptr Virtual_SetID(Boy *self, char *id);
static char *Virtual_GetID(Boy *self);
static iptr LeadMe(Boy *self);

Boy MakeBoy() {
	static Boy boy = {
		._offset_ = 0,
		.Virtual_Destruct = Virtual_Destruct,
		.Virtual_SetID = Virtual_SetID,
		.Virtual_GetID = Virtual_GetID,
		.LeadMe = LeadMe
	};

	boy._derived_ = MakeDerived();
	boy._derived_._offset_ = offsetof(Boy, _offset_);

	const char *desc = "Lead Me to Your World.";
	boy._desc = (char *)malloc(strlen(desc) + 1);
	memcpy(boy._desc, desc, strlen(desc) + 1);

	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	return boy;
}

Boy *NewBoy() {
	Boy *boy = (Boy *)malloc(sizeof(Boy));
	*boy = MakeBoy();

	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	return boy;
}

static void Virtual_Destruct(Boy *self) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	free(self->_desc);
}

static iptr Virtual_SetID(Boy *self, char *id) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	iptr ret = 0;

	Super *jump = (Super *)self;
	if (0 != self->_offset_) {
		jump = Jump((void *)self, self->_offset_);
		jump->Virtual_SetID((void *)self, id);
	}
	else {
		free(jump->_id);
		const char *addID = "#Boy";
		jump->_id = (char *)malloc(strlen(id) + strlen(addID) + 1);
		strcpy(jump->_id, id);
		strcat(jump->_id, addID);
		ret += 1;
	}
	return ret;
}

static char *Virtual_GetID(Boy *self) {
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

static iptr LeadMe(Boy *self) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	iptr ret = 0;

	fprintf(stdout, "%s""\n", self->_desc);
	ret += 1;

	return ret;
}


#endif // Boy_c

