/* Sequential_Sort.c
Author: BSS9395
Update: 2020-12-02T02:08:00+08@China-Guangdong-Zhanjiang+08
Design: Sequential Sort
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

typedef bool(Compare)(long *, long *);

bool Less(long *lhs, long *rhs) {
	return ((*lhs) < (*rhs));
}

bool LessEqual(long *lhs, long *rhs) {
	return ((*lhs) <= (*rhs));
}

bool Equal(long *lhs, long *rhs) {
	return ((*lhs) == (*rhs));
}

bool More(long *lhs, long *rhs) {
	return ((*lhs) > (*rhs));
}

bool MoreEqual(long *lhs, long *rhs) {
	return ((*lhs) >= (*rhs));
}

////////////////////////////////////////////////////////////////////////////////

typedef struct Datum {
	long _hash;
	char *_datum;
} Datum;

typedef struct Index {
	long _hash;
	void *_index;
} Index;

Datum _Datum[10] = { {1, "!"}, {3, "#"}, {4, "$"}, {5, "%"}, {7, "&"}, {9, "("}, {0, ")"}, {8, "*"}, {2, "@"}, {6, "^"} };
Datum _Extra[10] = { {1, "1"}, {3, "3"}, {4, "4"}, {5, "5"}, {7, "7"}, {9, "9"}, {0, "0"}, {8, "8"}, {2, "2"}, {6, "6"} };
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
		fprintf(stdout, "%ld, ", index[i]._hash);
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
data:  1, 3, 4, 5, 7, 9, 0, 8, 2, 6
 1st: [0], 1, 3, 4, 5, 7, 9, 2, 8, 6
 2nd: [0, 1], 2, 3, 4, 5, 7, 9, 6, 8
 3rd: [0, 1, 2], 3, 4, 5, 6, 7, 9, 8
 4th: [0, 1, 2, 3], 4, 5, 6, 7, 8, 9
 5th: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
*/
Index *Bubble_Sort_LTH(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	bool flip = false;
	Index swap;
	for (long i = 0; i < leng; i += 1) {
		// Print(index, leng);
		flip = false;
		for (long j = leng - 1; i < j; j -= 1) {
			if (comp(&index[j]._hash, &index[j - 1]._hash)) {
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

/* Stable
data:  1, 3, 4, 5, 7, 9, 0, 8, 2, 6
 1st:  1, 3, 4, 5, 7, 0, 8, 2, 6,[9]
 2nd:  1, 3, 4, 5, 0, 7, 2, 6,[8, 9]
 3rd:  1, 3, 4, 0, 5, 2, 6,[7, 8, 9]
 4th:  1, 3, 0, 4, 2, 5,[6, 7, 8, 9]
 5th:  1, 0, 3, 2, 4,[5, 6, 7, 8, 9]
 6th:  0, 1, 2, 3,[4, 5, 6, 7, 8, 9]
 7th: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
*/
Index *Bubble_Sort_HTL(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	bool flip = false;
	Index swap;
	for (long i = leng - 1; 0 <= i; i -= 1) {
		// Print(index, leng);
		flip = false;
		for (long j = 0; j < i; j += 1) {
			if (comp(&index[j + 1]._hash, &index[j]._hash)) {
				flip = true;
				swap = index[j + 1];
				index[j + 1] = index[j];
				index[j] = swap;
			}
		}
		if (!flip) {
			break;
		}
	}
	return index;
}

////////////////////////////////////////////////////////////////////////////////

/* Stable
data:  1, 3, 4, 5, 7, 9, 0, 8, 2, 6
 1st: [0], 3, 4, 5, 7, 9, 1, 8, 2, 6
 2nd: [0, 1], 4, 5, 7, 9, 3, 8, 2, 6
 3rd: [0, 1, 2], 5, 7, 9, 3, 8, 4, 6
 4th: [0, 1, 2, 3], 7, 9, 5, 8, 4, 6
 5th: [0, 1, 2, 3, 4], 9, 5, 8, 7, 6
 6th: [0, 1, 2, 3, 4, 5], 9, 8, 7, 6
 7th: [0, 1, 2, 3, 4, 5, 6], 8, 7, 9
 8th: [0, 1, 2, 3, 4, 5, 6, 7], 8, 9
 9th: [0, 1, 2, 3, 4, 5, 6, 7, 8], 9
10th: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
*/
Index *Selection_Sort_LTH(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	long most = 0;
	Index swap;
	for (long i = 0; i < leng; i += 1) {
		// Print(index, leng);
		most = i;
		for (long j = i; j < leng; j += 1) {
			if (comp(&index[j]._hash, &index[most]._hash)) {
				most = j;
			}
		}
		if (most != i) {
			swap = index[most];
			index[most] = index[i];
			index[i] = swap;
		}
	}
	return index;
}

/* Stable
data:  1, 3, 4, 5, 7, 9, 0, 8, 2, 6
 1st:  1, 3, 4, 5, 7, 6, 0, 8, 2,[9]
 2nd:  1, 3, 4, 5, 7, 6, 0, 2,[8, 9]
 3rd:  1, 3, 4, 5, 2, 6, 0,[7, 8, 9]
 4th:  1, 3, 4, 5, 2, 0,[6, 7, 8, 9]
 5th:  1, 3, 4, 0, 2,[5, 6, 7, 8, 9]
 6th:  1, 3, 2, 0,[4, 5, 6, 7, 8, 9]
 7th:  1, 0, 2,[3, 4, 5, 6, 7, 8, 9]
 8th:  1, 0,[2, 3, 4, 5, 6, 7, 8, 9]
 9th:  0,[1, 2, 3, 4, 5, 6, 7, 8, 9]
10th: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
*/
Index *Selection_Sort_HTL(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	long most = 0;
	Index swap;
	for (long i = leng - 1; 0 <= i; i -= 1) {
		// Print_Index(index, leng);
		most = i;
		for (long j = i; 0 <= j; j -= 1) {
			if (comp(&index[most]._hash, &index[j]._hash)) {
				most = j;
			}
		}
		if (most != i) {
			swap = index[most];
			index[most] = index[i];
			index[i] = swap;
		}
	}
	return index;
}

////////////////////////////////////////////////////////////////////////////////

/* Stable
data:  1, 3, 4, 5, 7, 9, 0, 8, 2, 6
 1st: [1], 3, 4, 5, 7, 9, 0, 8, 2, 6
 2nd: [1, 3], 4, 5, 7, 9, 0, 8, 2, 6
 3rd: [1, 3, 4], 5, 7, 9, 0, 8, 2, 6
 4th: [1, 3, 4, 5], 7, 9, 0, 8, 2, 6
 5th: [1, 3, 4, 5, 7], 9, 0, 8, 2, 6
 6th: [1, 3, 4, 5, 7, 9], 0, 8, 2, 6
 7th: [0, 1, 3, 4, 5, 7, 9], 8, 2, 6
 8th: [0, 1, 3, 4, 5, 7, 8, 9], 2, 6
 9th: [0, 1, 2, 3, 4, 5, 7, 8, 9], 6
10th: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
*/
Index *Insertion_Sort_LTH(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	Index pick;
	for (long i = 0; i < leng; i += 1) {
		// Print(index, leng);
		pick = index[i];
		long j = i;
		while (0 < j && comp(&pick._hash, &index[j - 1]._hash)) {
			index[j] = index[j - 1];
			j -= 1;
		}
		index[j] = pick;
	}
	return index;
}

/* Stable
data:  1, 3, 4, 5, 7, 9, 0, 8, 2, 6
 1st:  1, 3, 4, 5, 7, 9, 0, 8, 2,[6]
 2nd:  1, 3, 4, 5, 7, 9, 0, 8,[2, 6]
 3rd:  1, 3, 4, 5, 7, 9, 0,[2, 6, 8]
 4th:  1, 3, 4, 5, 7, 9,[0, 2, 6, 8]
 5th:  1, 3, 4, 5, 7,[0, 2, 6, 8, 9]
 6th:  1, 3, 4, 5,[0, 2, 6, 7, 8, 9]
 7th:  1, 3, 4,[0, 2, 5, 6, 7, 8, 9]
 8th:  1, 3,[0, 2, 4, 5, 6, 7, 8, 9]
 9th:  1,[0, 2, 3, 4, 5, 6, 7, 8, 9]
10th: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
*/
Index *Insertion_Sort_HTL(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	Index pick;
	for (long i = leng - 1; 0 <= i; i -= 1) {
		// Print(index, leng);
		pick = index[i];
		long j = i;
		while (j < leng - 1 && comp(&index[j + 1]._hash, &pick._hash)) {
			index[j] = index[j + 1];
			j += 1;
		}
		index[j] = pick;
	}
	return index;
}

/* UnStable
data:  1, 3, 4, 5, 7, 9, 0, 8, 2, 6
 1st: [1], 3, 4, 5, 7, 9, 0, 8, 2, 6
 2nd: [1, 3], 4, 5, 7, 9, 0, 8, 2, 6
 3rd: [1, 3, 4], 5, 7, 9, 0, 8, 2, 6
 4th: [1, 3, 4, 5], 7, 9, 0, 8, 2, 6
 5th: [1, 3, 4, 5, 7], 9, 0, 8, 2, 6
 6th: [1, 3, 4, 5, 7, 9], 0, 8, 2, 6
 7th: [0, 1, 3, 4, 5, 7, 9], 8, 2, 6
 8th: [0, 1, 3, 4, 5, 7, 8, 9], 2, 6
 9th: [0, 1, 2, 3, 4, 5, 7, 8, 9], 6
10th: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
*/
Index *Binary_Insertion_Sort_LTH(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	Index pick;
	long beg = 0;
	long end = 0;
	long mid = 0;
	for (long i = 0; i < leng; i += 1) {
		// Print(index, leng);
		pick = index[i];
		beg = 0;
		end = i;
		while (beg < end) {
			mid = (beg + end) / 2;
			comp(&pick._hash, &index[mid]._hash) ? (end = mid) : (beg = mid + 1);
		}
		for (long j = i; end < j; j -= 1) {
			index[j] = index[j - 1];
		}
		index[end] = pick;
	}
	return index;
}

/* Unstable
data:  1, 3, 4, 5, 7, 9, 0, 8, 2, 6
 1st:  1, 3, 4, 5, 7, 9, 0, 8, 2,[6]
 2nd:  1, 3, 4, 5, 7, 9, 0, 8,[2, 6]
 3rd:  1, 3, 4, 5, 7, 9, 0,[2, 6, 8]
 4th:  1, 3, 4, 5, 7, 9,[0, 2, 6, 8]
 5th:  1, 3, 4, 5, 7,[0, 2, 6, 8, 9]
 6th:  1, 3, 4, 5,[0, 2, 6, 7, 8, 9]
 7th:  1, 3, 4,[0, 2, 5, 6, 7, 8, 9]
 8th:  1, 3,[0, 2, 4, 5, 6, 7, 8, 9]
 9th:  1,[0, 2, 3, 4, 5, 6, 7, 8, 9]
10th: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
*/
Index *Binary_Insertion_Sort_HTL(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	Index pick;
	long beg = 0;
	long end = 0;
	long mid = 0;
	for (long i = leng - 1; 0 <= i; i -= 1) {
		// Print(index, leng);
		pick = index[i];
		end = i;
		beg = leng - 1;
		while (end < beg) {
			mid = (end + beg + 1) / 2;
			comp(&index[mid]._hash, &pick._hash) ? (end = mid) : (beg = mid - 1);
		}
		for (long j = i; j < end; j += 1) {
			index[j] = index[j + 1];
		}
		index[end] = pick;
	}
	return index;
}

/* Unstable
data:  1, 3, 4, 5, 7, 9, 0, 8, 2, 6
 1st: [1], ?, ?, ?, ?, ?, ?, ?, ?, ?
 2nd: [1, 3], ?, ?, ?, ?, ?, ?, ?, ?
 3rd: [1, 3, 4], ?, ?, ?, ?, ?, ?, ?
 4th: [1, 3, 4, 5], ?, ?, ?, ?, ?, ?
 5th: [1, 3, 4, 5, 7], ?, ?, ?, ?, ?
 6th: [1, 3, 4, 5, 7, 9], ?, ?, ?, ?
 7th: [1, 3, 4, 5, 7, 9], ?, ?, ?,[0]
 8th: [1, 3, 4, 5, 7, 8, 9], ?, ?,[0]
 9th: [1, 2, 3, 4, 5, 7, 8, 9], ?,[0]
10th: [1, 2, 3, 4, 5, 6, 7, 8, 9],[0]
*/
Index *Bipolar_Insertion_Sort(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	Index *polar = (Index *)calloc(leng, sizeof(Index));
	long head = 0;
	long tail = 0;
	polar[0] = index[0];
	for (long i = 1; i < leng; i += 1) {
		// Print(polar, leng);
		if (comp(&polar[tail]._hash, &index[i]._hash)) {
			tail = tail + 1;
			polar[tail] = index[i];
		}
		else if (comp(&index[i]._hash, &polar[head]._hash)) {
			head = (head == 0) ? (leng - 1) : (head - 1);
			polar[head] = index[i];
		}
		else {
			long idx = head;
			while (comp(&polar[idx]._hash, &index[i]._hash)) {
				idx = (idx + 1) % leng;
			}
			if (idx <= tail) {
				for (long j = tail; idx <= j; polar[j + 1] = polar[j], j -= 1);
				polar[idx] = index[i];
				tail += 1;
			}
			else {
				for (long j = head; j <= idx; polar[j - 1] = polar[j], j += 1);
				polar[idx] = index[i];
				head -= 1;
			}
		}
	}

	for (long i = 0; i < leng; i += 1) {
		index[i] = polar[(head + i) % leng];
	}
	free(polar);
	return index;
}

/* Unstable
data:  1 , 3 , 4 , 5 , 7 , 9 , 0 , 8 , 2 , 6
 1st: [1], 0 , 4 , 2 ,{6},[9], 3 , 8 , 5 ,{7}    # gap = 5
 2nd: [1],{0},[3],{2},[4],{7},[5],{8},[6],{9}    # gap = 2
 3rd: [0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9]    # gap = 1
*/
Index *Diminishing_Gap_Sort(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	Index pick;
	for (long gap = leng / 2; 1 <= gap; gap = gap / 2) {
		// Print(index, leng);
		for (long i = gap; i < leng; i += 1) {
			pick = index[i];
			long j = i;
			while (gap <= j && comp(&pick._hash, &index[j - gap]._hash)) {
				index[j] = index[j - gap];
				j -= gap;
			}
			index[j] = pick;
		}
	}
	return index;
}

////////////////////////////////////////////////////////////////////////////////

/* Unstable
data:  1 , 3 , 4 , 5 , 7 , 9 , 0 , 8 , 2 , 6
 1st: [0],{1}, 4 , 5 , 7 , 9 ,[3], 8 , 2 , 6
 2nd:  0 | 1 |[2],[3],{4}, 9 ,[7], 8 ,[5], 6
 3rd:  0 | 1 |{2}, 3 | 4 | 9 , 7 , 8 , 5 , 6
 4th:  0 | 1 | 2 | 3 | 4 |[6], 7 , 8 , 5 ,{9}
 5th:  0 | 1 | 2 | 3 | 4 |[5],{6}, 8 ,[7]| 9
 6th:  0 | 1 | 2 | 3 | 4 | 5 | 6 |{7}, 8 | 9
*/
Index *Partition_Sort_Recursive_Entrance(Index *head, Index *tail, Compare comp) {
	if (head < tail) {
		Print_Index(_Index, _Length);
		Index pivot = head[0];
		Index *lower = head;
		Index *upper = tail;
		while (true) {
			while (lower < upper && comp(&pivot._hash, &upper->_hash)) {
				upper -= 1;
			}
			if (lower < upper) {
				lower[0] = upper[0];
				lower += 1;

				while (lower < upper && comp(&lower->_hash, &pivot._hash)) {
					lower += 1;
				}
				if (lower < upper) {
					upper[0] = lower[0];
					upper -= 1;
					continue;
				}
			}
			break;
		}
		lower[0] = pivot;
		Partition_Sort_Recursive_Entrance(head, lower - 1, comp);
		Partition_Sort_Recursive_Entrance(lower + 1, tail, comp);
	}
	return head;
}

Index *Partition_Sort_Recursive(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	Partition_Sort_Recursive_Entrance(&index[0], &index[leng - 1], comp);
	return index;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Bubble_Sort() {
	Bubble_Sort_LTH(_Index, _Length, Less);
	// Bubble_Sort_HTL(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Selection_Sort() {
	// Selection_Sort_LTH(_Index, _Length, Less);
	Selection_Sort_HTL(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}


void Test_Insertion_Sort() {
	// Insertion_Sort_LTH(_Index, _Length, Less);
	Insertion_Sort_HTL(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Binary_Insertion_Sort() {
	// Binary_Insertion_Sort_LTH(_Index, _Length, Less);
	Binary_Insertion_Sort_HTL(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Bipolar_Insertion_Sort() {
	Bipolar_Insertion_Sort(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Diminishing_Increment_Sort() {
	Diminishing_Gap_Sort(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Partition_Sort_Recursive() {
	Partition_Sort_Recursive(_Index, _Length, LessEqual);
	Print_Datum(_Index, _Length);
}

////////////////////////////////////////////////////////////////////////////////


int main(int argc, char *argv[]) {
	Mapping(true);

	// Test_Bubble_Sort();
	// Test_Selection_Sort();
	// Test_Insertion_Sort();
	// Test_Binary_Insertion_Sort();
	// Test_Bipolar_Insertion_Sort();
	// Test_Diminishing_Increment_Sort();
	Test_Partition_Sort_Recursive();
	return 0;
}
