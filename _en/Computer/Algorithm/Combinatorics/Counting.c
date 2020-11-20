/* Counting.c
Author: BSS9395
Update: 2020-11-19T01:27:00+08@China-Guangdong-Zhanjiang+08
Design: Permutation and Combination
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/*
Factorial(n) = n! = n ¡Á (n - 1) ¡Á ... ¡Á 1   # 0 <= n
*/
long Factorial(long inte) {
	if (Check(inte < 0, ELevel._ToDo, __FUNCTION__, "inte < 0", NULL)) {
		return 0;
	}

	long fact = 1;
	for (long i = 1; i <= inte; i += 1) {
		fact *= i;
	}
	return fact;
}

/*
Permutation(m, n) = m! / (m - n)! = m ¡Á (m - 1) ¡Á ... ¡Á (m - n + 1)
*/
long Permutation(long samp, long pick) {
	if (samp < 0 || pick < 0 || samp < pick) {
		return 0;
	}

	long perm = 1;
	for (pick = samp - pick + 1; pick <= samp; pick += 1) {
		perm *= pick;
	}
	return perm;
}

/*
Combination(m, n) = m! / (m - n)! / n! = [m ¡Á (m - 1) ¡Á ... ¡Á (m - n + 1)] / [n ¡Á (n - 1) ¡Á ... ¡Á 1]
Combination(m, n) = Combination(m, m - n) = m! / n! / (m - n)!
*/
long Combination(long samp, long pick) {
	if (samp < 0 || pick < 0 || samp < pick) {
		return 0;
	}
	if (samp / 2 < pick) {
		pick = samp - pick;
	}

	long comb = Permutation(samp, pick) / Factorial(pick);
	return comb;
}

/*
once choice
M ¡Ô samp, N ¡Ô pick
Init = { 0, 1, 2, ..., N }
Pick = { ..., i, j, k, l }   # i < j < k < l
NULL = { M, M-1, ..., M-N+1 }

redo choice
Init = { 0, 0, 0, ..., 0 }
Pick = { ..., i, 0, 0, 0 }
NULL = { M, M, ..., M, M }
*/
long *Next_Permutation(long perm[], long samp, long pick, bool once) {
	if (Check(perm == NULL, ELevel._Error, __FUNCTION__, "perm == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (samp < 0 || pick < 0 || (samp < pick && samp != 0)) {
		return NULL;
	}
	if (pick == 0) {
		return perm;
	}

	if (once) {
		if (samp == 0) {
			for (long i = 0; i < pick; i += 1) {
				perm[i] = i;
			}
			return perm;
		}

		long idx = pick - 1;
		long min = perm[idx] + 1;
		long beg = 0;
		for (; beg < pick && perm[beg] == beg; beg += 1);

	Index:
		while (min >= samp) {
			idx -= 1;
			if (idx < 0) {
				return NULL;
			}
			min = perm[idx] + 1;
		}
		for (long i = beg; i < idx; i += 1) {
			if (perm[i] == min) {
				min += 1;
				goto Index;
			}
		}

		perm[idx] = min;
		(idx < beg) ? (beg = idx, min = idx) : (min = beg);
		while (idx += 1, idx < pick) {
			for (long i = beg; i < idx; ) {
				if (perm[i] == min) {
					min += 1;
					i = beg;
					continue;
				}
				i += 1;
			}
			perm[idx] = min;
			min += 1;
		}
	}
	else {
		if (samp == 0) {
			for (long i = 0; i < pick; i += 1) {
				perm[i] = 0;
			}
			return perm;
		}

		long idx = pick - 1;
		long min = perm[idx] + 1;

		while (min >= samp) {
			idx -= 1;
			if (idx < 0) {
				return NULL;
			}
			min = perm[idx] + 1;
		}

		perm[idx] = min;
		while (idx += 1, idx < pick) {
			perm[idx] = 0;
		}
	}
	return perm;
}

/*
once choice
M ¡Ô samp, N ¡Ô samp
Init = { 0, 1, 2, ..., N }
Samp = { ..., i, j, k, l }      # i > j > k > l
Pick = { ..., i, j, k, l }      # i < j < k < l
NULL = { M, M-1, ..., 1, 0 }
*/
long *Next_Permutation_Full(long perm[], long samp, bool once) {
	if (Check(perm == NULL, ELevel._Error, __FUNCTION__, "perm == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (samp == 0) {
		return perm;
	}

	if (samp < 0) {
		samp = -samp;
		for (long i = 0; i < samp; i += 1) {
			perm[i] = i;
		}
		return perm;
	}

	long idx = samp - 1;
	while (idx -= 1, 0 <= idx && perm[idx] >= perm[idx + 1]);
	if (idx < 0) {
		return NULL;
	}

	long min = samp;
	while (min -= 1, perm[idx] >= perm[min]);
	Swap(&perm[idx], &perm[min]);

	while (idx += 1, samp -= 1, idx < samp) {
		Swap(&perm[idx], &perm[samp]);
	}
	return perm;
}

/*
once choice
M ¡Ô samp, N ¡Ô pick
Init = { 0, 1, 2, ..., N }
Comb = { ..., i, i+1, i+2 }
NULL = { M-N+1, ..., M-1, M }

redo choice
M ¡Ô samp, N ¡Ô pick
Init = { 0, 0, 0, ..., 0 }
Comb = { ..., i, i, i, i }
NULL = { M, M, ..., M, M }
*/
long *Next_Combination(long comb[], long samp, long pick, bool once) {
	if (Check(comb == NULL, ELevel._Error, __FUNCTION__, "comb == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (samp < 0 || pick < 0 || (samp < pick && samp != 0)) {
		return NULL;
	}

	if (once) {
		if (samp == 0) {
			for (long i = 0; i < pick; i += 1) {
				comb[i] = i;
			}
			return comb;
		}

		long idx = pick;
		samp -= pick;
		while (idx -= 1, 0 <= idx && comb[idx] == samp + idx);
		if (idx < 0) {
			return NULL;
		}

		comb[idx] += 1;
		long incr = comb[idx];
		while (idx += 1, idx < pick) {
			incr += 1;
			comb[idx] = incr;
		}
	}
	else {
		if (samp == 0) {
			for (long i = 0; i < pick; i += 1) {
				comb[i] = 0;
			}
			return comb;
		}

		long idx = pick;
		samp -= 1;
		while (idx -= 1, 0 <= idx && comb[idx] == samp);
		if (idx < 0) {
			return NULL;
		}

		comb[idx] += 1;
		long same = comb[idx];
		while (idx += 1, idx < pick) {
			comb[idx] = same;
		}
	}
	return comb;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Factorial() {
	long fact = Factorial(3);
	fprintf(stdout, "%ld\n", fact);
}

void Test_Permutation() {
	long samp = 5;
	long pick = 3;
	long perm = Permutation(samp, pick);
	fprintf(stdout, "%ld\n", perm);
}

void Test_Combination() {
	long samp = 5;
	long pick = 3;
	long comb = Combination(samp, pick);
	fprintf(stdout, "%ld\n", comb);
}

void Test_Next_Permutation() {
	long perm[10];
	long samp = 3;
	long pick = 3;
	bool once = true;
	Next_Permutation(perm, 0, pick, once);
	long count = 0;
	do {
		for (long i = 0; i < pick; i += 1) {
			fprintf(stdout, "%ld, ", perm[i]);
		}
		fprintf(stdout, "\n");
		count += 1;
	} while (Next_Permutation(perm, samp, pick, once) != NULL);
	fprintf(stdout, "%ld\n", count);
}

void Test_Next_Combination() {
	long comb[10];
	long samp = 5;
	long pick = 3;
	bool once = false;
	Next_Combination(comb, 0, pick, once);
	long count = 0;
	do {
		for (long i = 0; i < pick; i += 1) {
			fprintf(stdout, "%ld, ", comb[i]);
		}
		fprintf(stdout, "\n");
		count += 1;
	} while (Next_Combination(comb, samp, pick, once) != NULL);
	fprintf(stdout, "%ld\n", count);
}


int main(int argc, char *argv[]) {
	// Test_Permutation();
	// Test_Combination();
	// Test_Next_Permutation();
	Test_Next_Combination();

	return 0;
}