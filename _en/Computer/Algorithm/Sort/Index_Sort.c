/* Index_Sort.c
Author: BSS9395
Update: 2020-12-04T23:26:00+08@China-Guangdong-Zhanjiang+08
Design: Index Sort
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int8_t    in08;
typedef int16_t   in16;
typedef int32_t   in32;
typedef int64_t   in64;
typedef intptr_t  iptr;
typedef uint8_t   ui08;
typedef uint16_t  ui16;
typedef uint32_t  ui32;
typedef uint64_t  ui64;
typedef uintptr_t uptr;

typedef const ui08 *Level;
struct {
	const Level _Info;
	const Level _ToDo;
	const Level _Warn;
	const Level _Error;
	const Level _Fatal;
} ELevel = {
	._Info = "Info",
	._ToDo = "ToDo",
	._Warn = "Warn",
	._Error = "Error",
	._Fatal = "Fatal"
};

bool Check(bool failed, Level level, const ui08 *function, const ui08 *record, const ui08 *extra) {
	if (failed) {
		(extra == NULL) ? extra = (const ui08 *)"" : extra;
		fprintf(stderr, "[%s] %s: %s%s; ""\n", level, function, record, extra);
	}

	errno = 0;
	return failed;
}

////////////////////////////////////////////////////////////////////////////////

typedef bool(Compare)(long, long);

bool Less(long lhs, long rhs) {
	return (lhs < rhs);
}

bool LessEqual(long lhs, long rhs) {
	return (lhs <= rhs);
}

bool Equal(long lhs, long rhs) {
	return (lhs == rhs);
}

bool More(long lhs, long rhs) {
	return (lhs > rhs);
}

bool MoreEqual(long lhs, long rhs) {
	return (lhs >= rhs);
}

////////////////////////////////////////////////////////////////////////////////

typedef struct Datum {
	long _hash;
	char *_datum;
} Datum;

typedef struct Index {
	struct Index *_link;
	long _hash;
	void *_index;
} Index;

Datum _Datum[] = { {1, "!"}, {3, "#"}, {4, "$"}, {5, "%"}, {7, "&"}, {9, "("}, {0, ")"}, {8, "*"}, {2, "@"}, {6, "^"} };
Datum _Extra[] = { {-1, "1"}, {-3, "3"}, {4, "4"}, {5, "5"}, {7, "7"}, {9, "9"}, {0, "0"}, {8, "8"}, {2, "2"}, {6, "6"} };
Index *_Index = NULL;
long _Length = 0;

void Mapping(bool normal) {
	if (normal) {
		long length = sizeof(_Datum) / sizeof(_Datum[0]);
		Index *index = (Index *)calloc(length, sizeof(Index));
		for (long i = 0; i < length; i += 1) {
			index[i]._hash = _Datum[i]._hash;
			index[i]._index = &_Datum[i];
		}
		_Index = index;
		_Length = length;
	}
	else {
		long length = sizeof(_Datum) / sizeof(_Datum[0]);
		long length_extra = sizeof(_Extra) / sizeof(_Extra[0]);
		Index *index = (Index *)calloc(length + length_extra, sizeof(Index));
		for (long i = 0; i < length; i += 1) {
			index[i]._hash = _Datum[i]._hash;
			index[i]._index = &_Datum[i];
		}
		for (long i = 0; i < length_extra; i += 1) {
			index[length + i]._hash = _Extra[i]._hash;
			index[length + i]._index = &_Extra[i];
		}
		_Index = index;
		_Length = length + length_extra;
	}
}

void Print_Index(Index index[], long leng) {
	for (long i = 0; i < leng; i += 1) {
		fprintf(stdout, " %ld ", index[i]._hash);
	}
	fprintf(stdout, "\n");
}

void Print_Datum(Index index[], long leng) {
	Datum *idx = NULL;
	for (long i = 0; i < leng; i += 1) {
		idx = index[i]._index;
		fprintf(stdout, "[%ld: %s] ", idx->_hash, idx->_datum);
	}
	fprintf(stdout, "\n");
}

////////////////////////////////////////////////////////////////////////////////

/* Stable
data:  1  3  4  5  7  9  0  8  2  6
*/
Index *Insertion_Sort_List(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	for (long i = 0; i < leng; i += 1) {
		index[i]._link = NULL;
	}

	Index *head = &index[0];
	Index **iter = NULL;
	for (long i = 1; i < leng; i += 1) {
		iter = &head;
		// while ((*iter) != NULL && comp((*iter)->_hash, index[i]._hash)) {    // Unstable
		while ((*iter) != NULL && !comp(index[i]._hash, (*iter)->_hash)) {    // Stable
			iter = &((*iter)->_link);
		}
		index[i]._link = (*iter);
		(*iter) = &index[i];
	}

	Index swap;
	Index *link = NULL;
	for (Index *beg = index, *end = index + leng; beg < end; beg += 1) {
		while (head < beg) {
			head = head->_link;
		}
		link = head->_link;
		if (head != beg) {
			swap = (*beg), (*beg) = (*head), (*head) = swap;
			beg->_link = head;
		}
		head = link;
	}
	return index;
}



////////////////////////////////////////////////////////////////////////////////

void Test_Insertion_Sort_List() {
	Insertion_Sort_List(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	Mapping(false);

	Test_Insertion_Sort_List();
	return 0;
}
