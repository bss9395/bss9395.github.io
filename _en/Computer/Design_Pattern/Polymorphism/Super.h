/* Super.h
Design: Polymorphism
Authro: BSS9395
Update: 2019-08-20T01:22 +08
*/

#ifndef Super_h
#define Super_h

#include "Helper.h"

typedef struct _SuperType Super;
typedef struct _SuperType SuperType;
typedef struct _SuperFunction SuperFunction;

struct _SuperFunction {
	Super(*mkSuper)(void);
	void(*destruct)(Super *);

	void(*setID)(Super *, const char *);
	const char *(*getID)(Super *);
};

struct _SuperType {
	SuperFunction *function;

	char *_ID;
};

inline Super mkSuper(void);
inline void deSuper(Super *self);
inline void setID(Super *self, const char *ID);
inline const char *getID(Super *self);
inline Super *newSuper(void);


inline Super mkSuper(void) {
	static SuperFunction superFunction = {
		mkSuper, deSuper, setID, getID
	};
	static SuperType superType = { &superFunction };

	superType._ID = NULL;

	fprintf(stderr, "void mkSuper(Super *);\n");
	return superType;
}

inline void deSuper(Super *self) {
	fprintf(stderr, "void deSuper(Super *);\n");

	if (NULL != self->_ID) {
		free(self->_ID);
		self->_ID = NULL;
	}
}

inline void setID(Super *self, const char *ID) {
	fprintf(stderr, "void setID(Super *, const char *);\n");

	if (NULL != self->_ID) {
		free(self->_ID);
	}

	self->_ID = (char *)malloc((strlen(ID) + 1) * sizeof(char));
	strcpy(self->_ID, ID);
}

inline const char *getID(Super *self) {
	fprintf(stderr, "const char *getID(Super *);\n");

	return self->_ID;
}

inline Super *newSuper(void) {
	fprintf(stderr, "Super *newSuper();\n");

	Super *super = (Super *)malloc(sizeof(Super));
	*super = mkSuper();
	return super;
}

#endif // Super_h
