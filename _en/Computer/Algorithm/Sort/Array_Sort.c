/* Array_Sort.c
Author: BSS9395
Update: 2020-12-04T07:55:00+08@China-Guangdong-Zhanjiang+08
Design: Array Sort
*/

/*
				   Y┌            Case1: H1 < H2 < H3
		Y┌ H2 < H3 ─┤         Y┌ Case2: H1 < H3 ≤ H2
		 │         N└ H1 < H3 ─┤
H1 < H2 ─┤                    N└ Case3: H3 ≤ H1 < H2
		 │         Y┌            Case4: H2 ≤ H1 < H3    # 3! = 6
		N└ H1 < H3 ─┤         Y┌ Case5: H2 < H3 ≤ H1
				   N└ H2 < H3 ─┤
							  N└ Case6: H3 ≤ H2 ≤ H1

Stirling's Formula
n! ≈ (2·π·n)^(1/2)·(n/ә)^n

  Log2[n!]
= Log2[(2·π·n)^(1/2)·(n/ә)^n]
= (1/2)·Log2[2·π·n] + n·Log2[n/ә]
= (1/2)·(Log2[2·π] + Log2[n]) + n·(Log2[n] - Log2[ә])
= (1/2 + n)·Log2[n] - n·Log2[ә] + 1/2·(1 + Log2[π]）

 ⌈Log2(n!)⌉ = O(n·Log2(n))
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
	long _hash;
	void *_index;
} Index;

Datum _Datum[] = { {1, "!"}, {3, "#"}, {4, "$"}, {5, "%"}, {7, "&"}, {9, "("}, {0, ")"}, {8, "*"}, {2, "@"}, {6, "^"} };
Datum _Extra[] = { {1, "1"}, {3, "3"}, {4, "4"}, {5, "5"}, {7, "7"}, {9, "9"}, {0, "0"}, {8, "8"}, {2, "2"}, {6, "6"} };
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
 1st: [0] 1  3  4  5  7  9  2  8  6
 2nd: [0  1] 2  3  4  5  7  9  6  8
 3rd: [0  1  2] 3  4  5  6  7  9  8
 4th: [0  1  2  3] 4  5  6  7  8  9
 5th: [0  1  2  3  4  5  6  7  8  9]
*/
Index *Bubble_Sort_LH(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	bool flip = false;
	Index swap;
	for (long i = 0; i < leng; i += 1) {
		// Print(index, leng);
		flip = false;
		for (long j = leng - 1; i < j; j -= 1) {
			if (comp(index[j]._hash, index[j - 1]._hash)) {
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
data:  1  3  4  5  7  9  0  8  2  6
 1st:  1  3  4  5  7  0  8  2  6 [9]
 2nd:  1  3  4  5  0  7  2  6 [8  9]
 3rd:  1  3  4  0  5  2  6 [7  8  9]
 4th:  1  3  0  4  2  5 [6  7  8  9]
 5th:  1  0  3  2  4 [5  6  7  8  9]
 6th:  0  1  2  3 [4  5  6  7  8  9]
 7th: [0  1  2  3  4  5  6  7  8  9]
*/
Index *Bubble_Sort_HL(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	bool flip = false;
	Index swap;
	for (long i = leng - 1; 0 <= i; i -= 1) {
		// Print(index, leng);
		flip = false;
		for (long j = 0; j < i; j += 1) {
			if (comp(index[j + 1]._hash, index[j]._hash)) {
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

/* Unstable
data:  1  3  4  5  7  9  0  8  2  6
 1st:  1  2 [4] 5  7  9  0  8  3 [6]    # step = 7
 2nd:  1  0  4  3 [6] 9  2  8  5 [7]    # step = 5
 3rd: [1] 0  4 [2] 6  5 [3] 8  9 [7]    # step = 3
 4th:  1 [0] 3 [2] 4 [5] 6 [7] 9 [8]    # step = 2
 5th: [0][1][2][3][4][5][6][7][8][9]    # step = 1
 6th: [0][1][2][3][4][5][6][7][8][9]    # step = 1
*/
Index *Comb_Sort(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	double fact = 4.0 / 3.0;
	long step = (long)(leng / fact);
	bool flip = true;
	Index swap;
	while (flip) {
		flip = false;
		for (long i = leng - 1; step <= i; i -= 1) {
			if (comp(index[i]._hash, index[i - step]._hash)) {
				swap = index[i];
				index[i] = index[i - step];
				index[i - step] = swap;
				flip = true;
			}
		}
		// fprintf(stdout, "step = %ld""\n", step);
		// Print_Index(index, leng);
		if (1 < step) {
			step = (long)(step / fact);
			flip = true;
		}


	}
	return index;
}

////////////////////////////////////////////////////////////////////////////////

/* Stable
data:  1  3  4  5  7  9  0  8  2  6
 1st: [0] 3  4  5  7  9  1  8  2  6
 2nd: [0  1] 4  5  7  9  3  8  2  6
 3rd: [0  1  2] 5  7  9  3  8  4  6
 4th: [0  1  2  3] 7  9  5  8  4  6
 5th: [0  1  2  3  4] 9  5  8  7  6
 6th: [0  1  2  3  4  5] 9  8  7  6
 7th: [0  1  2  3  4  5  6] 8  7  9
 8th: [0  1  2  3  4  5  6  7] 8  9
 9th: [0  1  2  3  4  5  6  7  8] 9
10th: [0  1  2  3  4  5  6  7  8  9]
*/
Index *Selection_Sort_LH(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	long most = 0;
	Index swap;
	for (long i = 0; i < leng; i += 1) {
		// Print(index, leng);
		most = i;
		for (long j = i; j < leng; j += 1) {
			if (comp(index[j]._hash, index[most]._hash)) {
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
data:  1  3  4  5  7  9  0  8  2  6
 1st:  1  3  4  5  7  6  0  8  2 [9]
 2nd:  1  3  4  5  7  6  0  2 [8  9]
 3rd:  1  3  4  5  2  6  0 [7  8  9]
 4th:  1  3  4  5  2  0 [6  7  8  9]
 5th:  1  3  4  0  2 [5  6  7  8  9]
 6th:  1  3  2  0 [4  5  6  7  8  9]
 7th:  1  0  2 [3  4  5  6  7  8  9]
 8th:  1  0 [2  3  4  5  6  7  8  9]
 9th:  0 [1  2  3  4  5  6  7  8  9]
10th: [0  1  2  3  4  5  6  7  8  9]
*/
Index *Selection_Sort_HL(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	long most = 0;
	Index swap;
	for (long i = leng - 1; 0 <= i; i -= 1) {
		// Print_Index(index, leng);
		most = i;
		for (long j = i; 0 <= j; j -= 1) {
			if (comp(index[most]._hash, index[j]._hash)) {
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
data:  1  3  4  5  7  9  0  8  2  6
 1st: [1] 3  4  5  7  9  0  8  2  6
 2nd: [1  3] 4  5  7  9  0  8  2  6
 3rd: [1  3  4] 5  7  9  0  8  2  6
 4th: [1  3  4  5] 7  9  0  8  2  6
 5th: [1  3  4  5  7] 9  0  8  2  6
 6th: [1  3  4  5  7  9] 0  8  2  6
 7th: [0  1  3  4  5  7  9] 8  2  6
 8th: [0  1  3  4  5  7  8  9] 2  6
 9th: [0  1  2  3  4  5  7  8  9] 6
10th: [0  1  2  3  4  5  6  7  8  9]
*/
Index *Insertion_Sort_LH(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	Index pick;
	for (long i = 0; i < leng; i += 1) {
		// Print(index, leng);
		pick = index[i];
		long j = i;
		while (0 < j && comp(pick._hash, index[j - 1]._hash)) {
			index[j] = index[j - 1];
			j -= 1;
		}
		index[j] = pick;
	}
	return index;
}

/* Stable
data:  1  3  4  5  7  9  0  8  2  6
 1st:  1  3  4  5  7  9  0  8  2 [6]
 2nd:  1  3  4  5  7  9  0  8 [2  6]
 3rd:  1  3  4  5  7  9  0 [2  6  8]
 4th:  1  3  4  5  7  9 [0  2  6  8]
 5th:  1  3  4  5  7 [0  2  6  8  9]
 6th:  1  3  4  5 [0  2  6  7  8  9]
 7th:  1  3  4 [0  2  5  6  7  8  9]
 8th:  1  3 [0  2  4  5  6  7  8  9]
 9th:  1 [0  2  3  4  5  6  7  8  9]
10th: [0  1  2  3  4  5  6  7  8  9]
*/
Index *Insertion_Sort_HL(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	Index pick;
	for (long i = leng - 1; 0 <= i; i -= 1) {
		// Print(index, leng);
		pick = index[i];
		long j = i;
		while (j < leng - 1 && comp(index[j + 1]._hash, pick._hash)) {
			index[j] = index[j + 1];
			j += 1;
		}
		index[j] = pick;
	}
	return index;
}

/* UnStable
data:  1 3  4  5  7  9  0  8  2  6
 1st: [1] 3  4  5  7  9  0  8  2  6
 2nd: [1  3] 4  5  7  9  0  8  2  6
 3rd: [1  3  4] 5  7  9  0  8  2  6
 4th: [1  3  4  5] 7  9  0  8  2  6
 5th: [1  3  4  5  7] 9  0  8  2  6
 6th: [1  3  4  5  7  9] 0  8  2  6
 7th: [0  1  3  4  5  7  9] 8  2  6
 8th: [0  1  3  4  5  7  8  9] 2  6
 9th: [0  1  2  3  4  5  7  8  9] 6
10th: [0  1  2  3  4  5  6  7  8  9]
*/
Index *Binary_Insertion_Sort_LH(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
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
			comp(pick._hash, index[mid]._hash) ? (end = mid) : (beg = mid + 1);
		}
		for (long j = i; end < j; j -= 1) {
			index[j] = index[j - 1];
		}
		index[end] = pick;
	}
	return index;
}

/* Unstable
data:  1  3  4  5  7  9  0  8  2  6
 1st:  1  3  4  5  7  9  0  8  2 [6]
 2nd:  1  3  4  5  7  9  0  8 [2  6]
 3rd:  1  3  4  5  7  9  0 [2  6  8]
 4th:  1  3  4  5  7  9 [0  2  6  8]
 5th:  1  3  4  5  7 [0  2  6  8  9]
 6th:  1  3  4  5 [0  2  6  7  8  9]
 7th:  1  3  4 [0  2  5  6  7  8  9]
 8th:  1  3 [0  2  4  5  6  7  8  9]
 9th:  1 [0  2  3  4  5  6  7  8  9]
10th: [0  1  2  3  4  5  6  7  8  9]
*/
Index *Binary_Insertion_Sort_HL(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
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
			comp(index[mid]._hash, pick._hash) ? (end = mid) : (beg = mid - 1);
		}
		for (long j = i; j < end; j += 1) {
			index[j] = index[j + 1];
		}
		index[end] = pick;
	}
	return index;
}

/* Unstable
data:  1  3  4  5  7  9  0  8  2  6
 1st: [1] ?  ?  ?  ?  ?  ?  ?  ?  ?
 2nd: [1  3] ?  ?  ?  ?  ?  ?  ?  ?
 3rd: [1  3  4] ?  ?  ?  ?  ?  ?  ?
 4th: [1  3  4  5] ?  ?  ?  ?  ?  ?
 5th: [1  3  4  5  7] ?  ?  ?  ?  ?
 6th: [1  3  4  5  7  9] ?  ?  ?  ?
 7th: [1  3  4  5  7  9] ?  ?  ? [0]
 8th: [1  3  4  5  7  8  9] ?  ? [0]
 9th: [1  2  3  4  5  7  8  9] ? [0]
10th: [1  2  3  4  5  6  7  8  9][0]
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
		if (comp(polar[tail]._hash, index[i]._hash)) {
			tail = tail + 1;
			polar[tail] = index[i];
		}
		else if (comp(index[i]._hash, polar[head]._hash)) {
			head = (head == 0) ? (leng - 1) : (head - 1);
			polar[head] = index[i];
		}
		else {
			long idx = head;
			while (comp(polar[idx]._hash, index[i]._hash)) {
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
data:  1  3  4  5  7  9  0  8  2  6
 1st: [1] 0  4  2 {6}[9] 3  8  5 {7}    # step = 5
 2nd: [1]{0}[3]{2}[4]{7}[5]{8}[6]{9}    # step = 2
 3rd: [0  1  2  3  4  5  6  7  8  9]    # step = 1
*/
Index *Diminishing_Step_Sort(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	Index pick;
	for (long step = leng / 2; 1 <= step; step = step / 2) {
		// Print(index, leng);
		for (long i = step; i < leng; i += 1) {
			pick = index[i];
			long j = i;
			while (step <= j && comp(pick._hash, index[j - step]._hash)) {
				index[j] = index[j - step];
				j -= step;
			}
			index[j] = pick;
		}
	}
	return index;
}

////////////////////////////////////////////////////////////////////////////////

/* Unstable
data:  1   3   4   5   7   9   0   8   2   6
 1st: [0] {1}  4   5   7   9  [3]  8   2   6
 2nd:  0 | 1 |[2] [3] {4}  9  [7]  8  [5]  6
 3rd:  0 | 1 |{2}  3 | 4 | 9   7   8   5   6
 4th:  0 | 1 | 2 | 3 | 4 |[6]  7   8   5  {9}
 5th:  0 | 1 | 2 | 3 | 4 |[5] {6}  8  [7]| 9
 6th:  0 | 1 | 2 | 3 | 4 | 5 | 6 |{7}  8 | 9
*/
Index *Partition_Sort_Recursive_Entrance(Index *head, Index *tail, Compare comp) {
	if (head < tail) {
		// Print_Index(_Index, _Length);
		Index pivot = head[0];
		Index *lower = head;
		Index *upper = tail;
		while (true) {
			while (lower < upper && comp(pivot._hash, upper->_hash)) {
				upper -= 1;
			}
			if (lower < upper) {
				lower[0] = upper[0];
				lower += 1;

				while (lower < upper && comp(lower->_hash, pivot._hash)) {
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

/* Unstable
data:  1   3   4   5   7   9   0   8   2   6
 1st: [0] {1}  4   5   7   9  [3]  8   2   6
 2nd:  0 | 1 |[2] [3] {4}  9  [7]  8  [5]  6
 3rd:  0 | 1 |{2}  3 | 4 | 9   7   8   5   6
 4th:  0 | 1 | 2 | 3 | 4 |[6]  7   8   5  {9}
 5th:  0 | 1 | 2 | 3 | 4 |[5] {6}  8  [7]| 9
 6th:  0 | 1 | 2 | 3 | 4 | 5 | 6 |{7}  8 | 9
*/
Index *Partition_Sort(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	typedef struct Queue {
		Index *_head;
		Index *_tail;
	} Queue;
	Queue *range = (Queue *)calloc(leng, sizeof(Queue));
	long get = 0;
	long put = 0;
	range[put]._head = &index[0];
	range[put]._tail = &index[leng - 1];
	put += 1;

	Index *head = NULL;
	Index *tail = NULL;
	Index pivot;
	Index *lower = NULL;
	Index *upper = NULL;
	while (get < put) {
		head = range[get]._head;
		tail = range[get]._tail;
		get += 1;

		pivot = head[0];
		lower = head;
		upper = tail;
		while (true) {
			while (lower < upper && comp(pivot._hash, upper->_hash)) {
				upper -= 1;
			}
			if (lower < upper) {
				lower[0] = upper[0];
				lower += 1;

				while (lower < upper && comp(lower->_hash, pivot._hash)) {
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
		if (head < lower - 1) {
			range[put]._head = head;
			range[put]._tail = lower - 1;
			put += 1;
		}
		if (lower + 1 < tail) {
			range[put]._head = lower + 1;
			range[put]._tail = tail;
			put += 1;
		}
	}
	free(range);
	return index;
}

////////////////////////////////////////////////////////////////////////////////

/* Stable
data:  1  3  4  5  7  9  0  8  2  6
 1st: [1  3] 4  5  7  9  0  8  2  6
 2nd: [1  3  4] 5  7  9  0  8  2  6
 3rd: [1  3  4][5  7] 9  0  8  2  6
 4th: [1  3  4  5  7] 9  0  8  2  6
 5th: [1  3  4  5  7][0  9] 8  2  6
 6th: [1  3  4  5  7][0  8  9] 2  6
 7th: [1  3  4  5  7][0  8  9][2  6]
 8th: [1  3  4  5  7][0  2  6  8  9]
 9th: [0  1  2  3  4  5  6  7  8  9]
*/
Index *Merge_Sort_Recursive_Entrance(Index merge[], Index *head, Index *tail, Compare comp) {
	if (head < tail) {
		Index *half = head + (tail - head) / 2;
		Merge_Sort_Recursive_Entrance(merge, head, half, comp);
		Merge_Sort_Recursive_Entrance(merge, half + 1, tail, comp);

		Index *fore = head;
		Index *back = half + 1;
		for (; fore <= half && back <= tail; merge += 1) {
			comp(fore->_hash, back->_hash)
				? (merge[0] = fore[0], fore += 1)
				: (merge[0] = back[0], back += 1);
		}
		for (; fore <= half; merge[0] = fore[0], merge += 1, fore += 1);
		for (; back <= tail; merge[0] = back[0], merge += 1, back += 1);

		for (merge -= 1; head <= tail; tail[0] = merge[0], tail -= 1, merge -= 1);
		// Print_Index(_Index, _Length);
	}
	return head;
}

Index *Merge_Sort_Recursive(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	Index *merge = (Index *)calloc(leng, sizeof(Index));
	Merge_Sort_Recursive_Entrance(merge, &index[0], &index[leng - 1], comp);
	free(merge);
	return index;
}

/* Stable
data:  1  3  4  5  7  9  0  8  2  6
 1st: [1  3][4  5][7  9][0  8][2  6]
 2nd: [1  3  4  5][0  7  8  9][2  6]
 3rd: [0  1  3  4  5  7  8  9][2  6]
 4th: [0  1  2  3  4  5  6  7  8  9]
 */
Index *Merge_Sort(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	Index *merge = (Index *)calloc(leng, sizeof(Index));
	Index *swap = NULL;
	long iter = 0;
	long beg1 = 0;
	long end1 = 0;
	long beg2 = 0;
	long end2 = 0;
	for (long span = 1; span < leng; span += span) {
		iter = 0;
		beg1 = iter, end1 = beg1 + span;
		beg2 = end1, end2 = beg2 + span;
		while (end2 < leng) {
			for (; beg1 < end1 && beg2 < end2; iter += 1) {
				comp(index[beg1]._hash, index[beg2]._hash)
					? (merge[iter] = index[beg1], beg1 += 1)
					: (merge[iter] = index[beg2], beg2 += 1);
			}
			for (; beg1 < end1; merge[iter] = index[beg1], iter += 1, beg1 += 1);
			for (; beg2 < end2; merge[iter] = index[beg2], iter += 1, beg2 += 1);

			beg1 = end2, end1 = beg1 + span;
			beg2 = end1, end2 = beg2 + span;
		}
		if (end1 < leng) {
			end2 = leng;
			for (; beg1 < end1 && beg2 < end2; iter += 1) {
				comp(index[beg1]._hash, index[beg2]._hash)
					? (merge[iter] = index[beg1], beg1 += 1)
					: (merge[iter] = index[beg2], beg2 += 1);
			}
			for (; beg1 < end1; merge[iter] = index[beg1], iter += 1, beg1 += 1);
			for (; beg2 < end2; merge[iter] = index[beg2], iter += 1, beg2 += 1);
		}
		swap = index, index = merge, merge = swap;
		// Print_Index(index, leng);
	}
	free(merge);
	return index;
}

////////////////////////////////////////////////////////////////////////////////

/* Heap
				   │  0:	0
				   │   	     \
0:	    0          │  1:      1
	   / \         │         / \
1:    1   2        │  2:    2   3
	 / \ / \       │       / \ / \
2:  3  4 5  6      │  3:  4  5 6  7
H[i] ≤ H[2·i+1]    │  H[i] ≤ H[2·i+0]
H[i] ≤ H[2·i+2]    │  H[i] ≤ H[2·i+1]
H[(i-1)/2] ≤ H[i]  │  H[i/2] ≤ H[i]
*/
Index *Heap_Sort_Heapify(Index peak[], long tail, Compare comp) {
	Index swap;
	long head = 0;
	long left = head * 2 + 1;
	while (left < tail) {
		if (!comp(peak[left + 1]._hash, peak[left]._hash)) {
			left += 1;
		}
		if (!comp(peak[left]._hash, peak[head]._hash)) {
			swap = peak[left], peak[left] = peak[head], peak[head] = swap;
			head = left;
			left = head * 2 + 1;
			continue;
		}
		break;
	}
	if (left == tail && !comp(peak[left]._hash, peak[head]._hash)) {
		swap = peak[left], peak[left] = peak[head], peak[head] = swap;
	}
	return peak;
}

/* Unstable
index: 0  1  2  3  4  5  6  7  8  9
data:  1  3  4  5  7  9  0  8  2  6
 1st:  8  7  4  5  6  1  0  3  2 [9]
 2nd:  7  6  4  5  2  1  0  3 [8  9]
 3rd:  6  5  4  3  2  1  0 [7  8  9]
 4th:  5  3  4  0  2  1 [6  7  8  9]
 5th:  4  3  1  0  2 [5  6  7  8  9]
 6th:  3  2  1  0 [4  5  6  7  8  9]
 7th:  2  0  1 [3  4  5  6  7  8  9]
 8th:  1  0 [2  3  4  5  6  7  8  9]
 9th:  0 [1  2  3  4  5  6  7  8  9]
*/
Index *Heap_Sort_TB(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	Index swap;
	long head = 0;
	long left = 0;
	long tail = leng - 1;
	for (long idx = (tail - 1) / 2; 0 <= idx; idx -= 1) {
		head = idx;
		left = (head << 1U) + 1;
		while (left < tail) {
			if (!comp(index[left + 1]._hash, index[left]._hash)) {
				left += 1;
			}
			if (!comp(index[left]._hash, index[head]._hash)) {
				swap = index[left], index[left] = index[head], index[head] = swap;
				head = left;
				left = (head << 1U) + 1;
				continue;
			}
			break;
		}
		if (left == tail && !comp(index[left]._hash, index[head]._hash)) {
			swap = index[left], index[left] = index[head], index[head] = swap;
		}
		// Heap_Sort_TB_Heapify(&index[i], leng - i, comp);
		// Print_Index(index, leng);
	}

	for (long i = leng - 1; 0 < i; i -= 1) {
		swap = index[0], index[0] = index[i], index[i] = swap;
		Heap_Sort_Heapify(&index[0], i - 1, comp);
		Print_Index(index, leng);
	}
	return index;
}

/* Unstable
index: 0  1  2  3  4  5  6  7  8  9
data:  1  3  4  5  7  9  0  8  2  6
 1st:  8  6  7  5  4  3  0  1  2 [9]
 2nd:  7  6  3  5  4  2  0  1 [8  9]
 3rd:  6  5  3  1  4  2  0 [7  8  9]
 4th:  5  4  3  1  0  2 [6  7  8  9]
 5th:  4  2  3  1  0 [5  6  7  8  9]
 6th:  3  2  0  1 [4  5  6  7  8  9]
 7th:  2  1  0 [3  4  5  6  7  8  9]
 8th:  1  0 [2  3  4  5  6  7  8  9]
 9th:  0 [1  2  3  4  5  6  7  8  9]
*/
Index *Heap_Sort_BT(Index index[], long leng, Compare comp) {
	if (Check(index == NULL || leng < 0 || comp == NULL, ELevel._Error, __FUNCTION__, "index == NULL || leng < 0 || comp == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (leng <= 1) {
		return index;
	}

	Index swap;
	for (long join = 1, head = 0; join < leng; join += 1) {
		head = ((join - 1) >> 1U);
		while (0 < join && !comp(index[join]._hash, index[head]._hash)) {
			swap = index[join], index[join] = index[head], index[head] = swap;
			join = head;
			head = ((join - 1) >> 1U);
		}
		// Print_Index(index, leng);
	}

	for (long i = leng - 1; 0 < i; i -= 1) {
		swap = index[0], index[0] = index[i], index[i] = swap;
		Heap_Sort_Heapify(&index[0], i - 1, comp);
		Print_Index(index, leng);
	}
	return index;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Bubble_Sort() {
	_Index = Bubble_Sort_LH(_Index, _Length, Less);
	// _Index = Bubble_Sort_HL(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Comb_Sort() {
	_Index = Comb_Sort(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Selection_Sort() {
	// _Index = Selection_Sort_LH(_Index, _Length, Less);
	_Index = Selection_Sort_HL(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Insertion_Sort() {
	// _Index = Insertion_Sort_LH(_Index, _Length, Less);
	_Index = Insertion_Sort_HL(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Binary_Insertion_Sort() {
	// _Index = Binary_Insertion_Sort_LH(_Index, _Length, Less);
	_Index = Binary_Insertion_Sort_HL(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Bipolar_Insertion_Sort() {
	_Index = Bipolar_Insertion_Sort(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Diminishing_Step_Sort() {
	_Index = Diminishing_Step_Sort(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Partition_Sort() {
	// _Index = Partition_Sort_Recursive(_Index, _Length, LessEqual);
	_Index = Partition_Sort(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Merge_Sort() {
	// _Index = Merge_Sort_Recursive(_Index, _Length, Less);
	_Index = Merge_Sort(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

void Test_Heap_Sort() {
	// _Index = Heap_Sort_TB(_Index, _Length, Less);
	_Index = Heap_Sort_BT(_Index, _Length, Less);
	Print_Datum(_Index, _Length);
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	Mapping(true);

	// Test_Bubble_Sort();
	// Test_Comb_Sort();
	// Test_Selection_Sort();
	// Test_Insertion_Sort();
	// Test_Binary_Insertion_Sort();
	// Test_Bipolar_Insertion_Sort();
	// Test_Diminishing_Increment_Sort();
	// Test_Partition_Sort();
	// Test_Merge_Sort();
	Test_Heap_Sort();
	return 0;
}
