/* Sort.c
Author: BSS9395
Update: 2020-11-29T06:38:00+08@China-Guangdong-Zhanjiang+08
Design: Sort Indices
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

typedef struct Datum {
	long _hash;
	char *_datum;
} Datum;

typedef struct Index {
	long _hash;
	long _index;
} Index;

Datum _Datum[10] = { {1, "!"}, {3, "#"}, {4, "$"}, {5, "%"}, {7, "&"}, {9, "("}, {0, ")"}, {8, "*"}, {2, "@"}, {6, "^"} };
Index *_Index = NULL;
long _Length = 0;

Index *Mapping(Datum datum[], Index index[], long leng) {
	if (Check(datum == NULL || leng < 0, ELevel._Error, __FUNCTION__, "data == NULL || leng < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (index == NULL) {
		index = (Index *)calloc(leng, sizeof(Index));
	}

	for (long i = 0; i < leng; i += 1) {
		index[i]._hash = datum[i]._hash;
		index[i]._index = i;
	}

	////////////////////////////////////////

	//long idx = 0;
	//for (long i = 0; i < leng; i += 1) {
	//	idx = index[i]._index;
	//	fprintf(stdout, "[%ld: %s] ", datum[idx]._hash, datum[idx]._datum);
	//}
	return index;
}

////////////////////////////////////////////////////////////////////////////////

/*
data:   1, 3, 4, 5, 7, 9, 0, 8, 2, 6
1 st: [0], 1, 3, 4, 5, 7, 9, 8, 2, 6
2 nd: [0, 1], 3, 4, 5, 7, 9, 8, 2, 6
3 rd: [0, 1, 2], 3, 4, 5, 7, 9, 8, 6
4 th: [0, 1, 2, 3], 4, 5, 7, 9, 8, 6
5 th: [0, 1, 2, 3, 4], 5, 7, 9, 8, 6
*/
Index *Bubble_Sort_Ascending_LTR(Index index[], long leng) {
	bool flip = false;
	Index swap;
	for (long i = 0; i < leng - 1; i += 1) {
		flip = false;
		for (long j = leng - 1; i < j; j -= 1) {
			if (index[j]._hash < index[j - 1]._hash) {
				flip = true;
				swap = index[j];
				index[j] = index[j - 1];
				index[j - 1] = swap;
			}
		}
		if (!flip) {
			break;
		}
	}
	return index;
}



////////////////////////////////////////////////////////////////////////////////

void Test_Bubble_Sort_Ascending_LTR() {
	Bubble_Sort_Ascending_LTR(_Index, _Length);
	long idx = 0;
	for (long i = 0; i < _Length; i += 1) {
		idx = _Index[i]._index;
		fprintf(stdout, "[%ld: %s] ", _Datum[idx]._hash, _Datum[idx]._datum);
	}
	fprintf(stdout, "\n");
}

int main(int argc, char *argv[]) {
	_Length = sizeof(_Datum) / sizeof(_Datum[0]);
	_Index = Mapping(_Datum, _Index, _Length);

	Test_Bubble_Sort_Ascending_LTR();
	return 0;
}
