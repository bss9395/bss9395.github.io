
#ifndef Helper_h
#define Helper_h

#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long iptr;

typedef struct {
	iptr _offset_;
	void(*Virtual_Destruct)(void *self);
} Class;

inline void *Jump(Class *self, iptr start) {
	Class *jump = (Class *)((iptr)self + start);
	while (0 != jump->_offset_) {
		jump = (Class *)((iptr)self + jump->_offset_);
	}
	return jump;
}

inline void Destruct(void *self) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);

	Class *jump = (Class *)self;
	while (0 != jump->_offset_) {
		jump->Virtual_Destruct(self);
		jump = (Class *)((iptr)self + jump->_offset_);
	}
	jump->Virtual_Destruct(self);
}

inline void Destroy(void *self) {
	// fprintf(stderr, "[%s: %d: %s]""\n", __FILE__, __LINE__, __FUNCTION__);
	Destruct(self);
	free(self);
}


#endif // Helper_h
