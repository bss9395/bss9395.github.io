/* Bucket_Sort.c
Author: BSS9395
Update: 2020-12-03T05:36:00+08@China-Guangdong-Zhanjiang+08
Design: Bucket Sort
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

index: 0  1  2  3  4  5  6  7  8  9
count: 1  2  3  4  5  6  7  8  9 10
*/
Index *Counting_Sort_Natural(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	long max = index[0]._hash;
	for (long i = 1; i < leng; i += 1) {
		if (max < index[i]._hash) {
			max = index[i]._hash;
		}
	}

	long *count = (long *)calloc(max + 1, sizeof(long));
	for (long i = 0; i < leng; i += 1) {
		count[index[i]._hash] += 1;
	}

	Index *sorted = (Index *)calloc(leng, sizeof(Index));
	long idx = 0;
	if (comp(0, 1)) {
		for (long i = 1; i <= max; i += 1) {
			count[i] += count[i - 1];
		}
		for (long i = leng - 1; 0 <= i; i -= 1) {
			idx = index[i]._hash;
			count[idx] -= 1;
			sorted[count[idx]] = index[i];
		}
	}
	else if (comp(1, 0)) {
		for (long i = max - 1; 0 <= i; i -= 1) {
			count[i] += count[i + 1];
		}
		for (long i = 0; i < leng; i += 1) {
			idx = index[i]._hash;
			count[idx] -= 1;
			sorted[count[idx]] = index[i];
		}
	}

	free(count);
	free(index);
	return sorted;
}

/* Stable
data:  1  3  4  5  7  9  0  8  2  6

index: 0  1  2  3  4  5  6  7  8  9
count: 1  2  3  4  5  6  7  8  9 10
*/
Index *Counting_Sort_Integer(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	long min = index[0]._hash;
	long max = index[0]._hash;
	for (long i = 1; i < leng; i += 1) {
		if (index[i]._hash < min) {
			min = index[i]._hash;
		}
		else if (max < index[i]._hash) {
			max = index[i]._hash;
		}
	}

	long diff = max - min;
	long *count = (long *)calloc(diff + 1, sizeof(long));
	for (long i = 0; i < leng; i += 1) {
		count[index[i]._hash - min] += 1;
	}

	Index *sorted = (Index *)calloc(leng, sizeof(Index));
	long idx = 0;
	if (comp(0, 1)) {
		for (long i = 1; i <= diff; i += 1) {
			count[i] += count[i - 1];
		}
		for (long i = leng - 1; 0 <= i; i -= 1) {
			idx = index[i]._hash - min;
			count[idx] -= 1;
			sorted[count[idx]] = index[i];
		}
	}
	else if (comp(1, 0)) {
		for (long i = diff - 1; 0 <= i; i -= 1) {
			count[i] += count[i + 1];
		}
		for (long i = 0; i < leng; i += 1) {
			idx = index[i]._hash - min;
			count[idx] -= 1;
			sorted[count[idx]] = index[i];
		}
	}

	free(count);
	free(index);
	return sorted;
}

////////////////////////////////////////////////////////////////////////////////

Index *Bucket_Sort(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	Index *bucket = (Index *)calloc(leng, sizeof(Index));
	for (long i = 0; i < leng; i += 1) {
		index[i]._link = NULL;
	}

	long idx = 0;
	Index **iter = NULL;
	for (long i = 0; i < leng; i += 1) {
		idx = (index[i]._hash + leng) % leng;
		iter = &bucket[idx]._link;
		while ((*iter) != NULL && comp((*iter)->_hash, index[i]._hash)) {
			iter = &((*iter)->_link);
		}
		index[i]._link = (*iter);
		(*iter) = &index[i];
	}

	Index *join = NULL;
	Index *swap = NULL;
	Index *head = bucket[0]._link;
	for (long i = 1; i < leng; i += 1) {
		if (bucket[i]._link != NULL) {
			iter = &head;
			join = bucket[i]._link;
			while ((*iter) != NULL && join != NULL) {
				if (comp(join->_hash, (*iter)->_hash)) {
					swap = join;
					join = (*iter);
					(*iter) = swap;
				}
				iter = &((*iter)->_link);
			}
			if (join != NULL) {
				(*iter) = join;
			}
		}
	}

	for (long i = 0; i < leng; i += 1) {
		bucket[i]._hash = head->_hash;
		bucket[i]._index = head->_index;
		head = head->_link;
	}
	free(index);
	return bucket;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Counting_Sort() {
	// _Index = Counting_Sort_Natural(_Index, _Length, More);
	_Index = Counting_Sort_Integer(_Index, _Length, More);
	Print_Datum(_Index, _Length);
}

void Test_Bucket_Sort() {
	_Index = Bucket_Sort(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	Mapping(true);

	// Test_Counting_Sort();
	Test_Bucket_Sort();

	return 0;
}
