/* String_Matcher.c
Author: BSS9395
Update: 2020-11-20T07:01:00+08@China-Guangdong-Zhanjiang+08
Design: Pattern Matcher
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
} ELevel;

bool Check(bool failed, Level level, const ui08 *function, const ui08 *record, const ui08 *extra) {
	if (failed) {
		(extra == NULL) ? extra = (const ui08 *)"" : extra;
		fprintf(stderr, "[%s] %s: %s%s; ""\n", level, function, record, extra);
	}

	errno = 0;
	return failed;
}

long Length(char *stri) {
	long len = -1;
	if (stri != NULL) {
		while (len += 1, stri[len] != '\0');
	}
	return len;
}

////////////////////////////////////////////////////////////////////////////////

char *Match_SubString_Classic(char *str, long len_str, char *sub, long len_sub) {
	if (Check(str == NULL || len_str < 0 || sub == NULL || len_sub < 0, ELevel._Error, __FUNCTION__, "str == NULL || len_str < 0 || sub == NULL || len_sub < 0", NULL)) {
		exit(EXIT_FAILURE);
	}

	long idx = 0;
	char *end_str = str + len_str - len_sub + 1;
	while (idx < len_sub && str < end_str) {
		if (str[idx] == sub[idx]) {
			idx += 1;
		}
		else {
			str += 1;
			idx = 0;
		}
	}
	return (idx >= len_sub) ? str : NULL;
}

/* String moves forward all the way up, but Pattern will rollback once unmatch.
Si+0,Si+1,...,Si+n-1
P0  ,P1  ,...,Pn-1

Si+0,...,...,Si+j,Si+j+1
P0  ,...,...,Pj  ,Pj+1
	 P0 ,...,Pk  ,Pk+1


Case 1: Pattern Match
P0,P1,...,Pn-1 == Si+0,Si+1,...,Si+n-1

Case 2: Pattern UnMatch
P0,P1,...,Pj == Si+0,Si+1,...,Si+j  and  Pj+1 ¡Ù Si+j+1

Case 3: Pattern Rollback
P0,P1,...,Pk == Pj-k+0,Pj-k+1,...,Pj   # 0 < k < j < n
relation=> back[j+1] = k+1
optimaze=> if Pj+1 == Pk+1 then back[j+1] = back[k+1]
*/
/*
index: 0  1  2  3  4  5  6  7  8  9
sub:   b  i  g  b  i  g  g  i  r  l
back: -1  0  0  0  1  2  3  0  0  0
back: -1  0  0 -1  0  0  3  0  0  0
*/
long *Generate_Rollback_Index_Classical(char *sub, long len, long back[]) {
	if (Check(sub == NULL || len < 0 || back == NULL, ELevel._Error, __FUNCTION__, "str == NULL || len < 0 || back == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	long idx_str = 0;
	long idx_sub = -1;
	back[idx_str] = idx_sub;
	for (len -= 1; idx_str < len;) {
		if (idx_sub == -1 || sub[idx_str] == sub[idx_sub]) {
			idx_str += 1;
			idx_sub += 1;
			back[idx_str] = idx_sub;
		}
		else {
			idx_sub = back[idx_sub];
		}
	}
	return back;
}

/*
index: 0  1  2  3  4  5  6  7  8  9
sub:   b  i  g  b  i  g  g  i  r  l
back: -1  0  0  0  1  2  3  0  0  0
back: -1  0  0 -1  0  0  3  0  0  0
*/
long *Generate_Rollback_Index_Classic(char *sub, long len, long back[]) {
	if (Check(sub == NULL || len < 0 || back == NULL, ELevel._Error, __FUNCTION__, "str == NULL || len < 0 || back == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	long idx_str = 0;
	long idx_sub = -1;
	back[idx_str] = idx_sub;
	for (len -= 1; idx_str < len;) {
		while (0 <= idx_sub && sub[idx_str] != sub[idx_sub]) {
			idx_sub = back[idx_sub];
		}
		idx_str += 1;
		idx_sub += 1;
		back[idx_str] = idx_sub;
	}
	return back;
}

/*
index: 0  1  2  3  4  5  6  7  8  9
sub:   b  i  g  b  i  g  g  i  r  l
back: -1  0  0  0  1  2  3  0  0  0
back: -1  0  0 -1  0  0  3  0  0  0
*/
long *Generate_Rollback_Index(char *sub, long len, long back[]) {
	if (Check(sub == NULL || len < 0 || back == NULL, ELevel._Error, __FUNCTION__, "str == NULL || len < 0 || back == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	long idx_str = 0;
	long idx_sub = -1;
	back[idx_str] = idx_sub;
	for (len -= 1; idx_str < len;) {
		while (0 <= idx_sub && sub[idx_str] != sub[idx_sub]) {
			idx_sub = back[idx_sub];
		}
		idx_str += 1;
		idx_sub += 1;
		back[idx_str] = (sub[idx_str] == sub[idx_sub]) ? back[idx_sub] : idx_sub;
	}
	return back;
}

char *Match_SubString(char *str, long len_str, char *sub, long len_sub, long back[], bool bare) {
	bool heap = false;
	if (back == NULL) {
		heap = true;
		back = (long *)calloc(len_sub, sizeof(long));
		Generate_Rollback_Index(sub, len_sub, back);
	}
	else if (bare) {
		Generate_Rollback_Index(sub, len_sub, back);
	}

	char *end_str = str + len_str;
	long idx_sub = 0;
	while (str < end_str && idx_sub < len_sub) {
		while (0 <= idx_sub && str[0] != sub[idx_sub]) {
			idx_sub = back[idx_sub];
		}
		str += 1;
		idx_sub += 1;
	}

	if (heap) {
		free(back);
	}
	return (idx_sub >= len_sub) ? (str - len_sub) : NULL;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Match_SubString_Classic() {
	char str[] = "Thereisnoonelikeyou.";
	char sub[] = "noon";
	long len_str = Length(str);
	long len_sub = Length(sub);

	char *match = Match_SubString_Classic(str, len_str, sub, len_sub);
	fprintf(stdout, "%d, %s\n", match - str, match);
}

void Test_Rollback_Index() {
	char *sub = "bigbiggirl";
	long len = Length(sub);
	long back[100];

	Generate_Rollback_Index_Classical(sub, len, back);
	// Generate_Rollback_Index_Classic(sub, len, back);
	// Generate_Rollback_Index(sub, len, back);
	for (long i = 0; i < len; i += 1) {
		fprintf(stdout, "%ld, ", back[i]);
	}
	fprintf(stdout, "\n");
}

void Test_Match_SubString() {
	char *str = "Iamabigbiggirlinabigbigworld";
	char *sub = "bigbiggirl";
	long len_str = Length(str);
	long len_sub = Length(sub);

	char *match = Match_SubString(str, len_str, sub, len_sub, NULL, true);
	fprintf(stdout, "%ld, %s\n", match - str, match);
}

int main(int argc, char *argv[]) {
	// Test_Match_SubString_Classic();
	Test_Rollback_Index();
	Test_Match_SubString();

	return 0;
}
