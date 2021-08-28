/* Multi_Dimensional_Array.c
Author: BSS9395
Update: 2020-08-27T17:21:00+08@China-Guangdong-Zhanjiang+08
Design: Multi-Dimensional Array
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef const char *Level;
struct _ELevel {
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


typedef struct _Index {
    int _index[1024];
} Index;

typedef int Type;
typedef struct _Param {
    Type _param[1024];
} Param;

typedef struct _Array {
    int _dimen;
    int *_bound;
    int *_const;
    Type *_array;
} Array;

////////////////////////////////////////////////////////////////////////////////

bool Check(bool failed, Level level, char *function, char *record, char *extra) {
    if (failed) {
        fprintf(stderr, "[%s] %s# %s%s""\n", level, function, record, extra);
    }
    return failed;
}

////////////////////////////////////////////////////////////////////////////////

Array Create_Array(int dimen, Index bound) {
    Array array;
    array._dimen = dimen;
    array._bound = (int *)malloc(dimen * sizeof(int));
    array._const = (int *)malloc(dimen * sizeof(int));

    int numb = 1;
    for (int i = dimen - 1; 0 <= i; i -= 1) {
        array._bound[i] = bound._index[i];
        array._const[i] = numb;
        numb *= bound._index[i];
    }

    array._array = (Type *)malloc(numb * sizeof(Type));
    return array;
}

int Destruct_Array(Array *array) {
    int ret = 0;
    free(array->_bound);
    free(array->_const);
    free(array->_array);

    ret = 3;
    array->_dimen = 0;
    array->_bound = NULL;
    array->_const = NULL;
    array->_array = NULL;
    return ret;
}

int Assign(Array *array, int numb, Param value) {
    if (!(0 <= numb && numb <= array->_bound[0] * array->_const[0])) {
        Check(true, ELevel._Error, __FUNCTION__, "numb exceeds array bound.", "");
    }

    for (int i = 0; i < numb; i += 1) {
        array->_array[i] = value._param[i];
    }
    return numb;
}

int Order(Array *array, Index index) {
    int order = 0;
    for (int i = 0; i < array->_dimen; i += 1) {
        order += index._index[i] * array->_const[i];
    }
    return order;
}

Type *Value(Array *array, Index index) {
    int order = 0;
    for (int i = 0; i < array->_dimen; i += 1) {
        order += index._index[i] * array->_const[i];
    }
    return &(array->_array[order]);
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
    Array array = Create_Array(3, (Index) { 7, 5, 3 });
    fprintf(stdout, "_dimen    = %d""\n", array._dimen);
    fprintf(stdout, "_bound[0] = %d\t_bound[1] = %d\t_bound[2] = %d""\n", array._bound[0], array._bound[1], array._bound[2]);
    fprintf(stdout, "_const[0] = %d\t_const[1] = %d\t_const[2] = %d""\n", array._const[0], array._const[1], array._const[2]);

    Assign(&array, 10, (Param) {
        9, 0, 8,
            2, 6, 1,
            3, 4, 5,
            7
    });

    int order = Order(&array, (Index) { 0, 2, 2 });
    fprintf(stdout, "order = %d\t_array[order] = %d""\n", order, array._array[order]);

    *Value(&array, (Index) { 0, 2, 2 }) = 10;
    fprintf(stdout, "array[0,2,2] = %d""\n", *Value(&array, (Index) { 0, 2, 2 }));

    for (int i = 0; i < 7; i += 1) {
        for (int j = 0; j < 5; j += 1) {
            for (int k = 0; k < 3; k += 1) {
                *Value(&array, (Index) { i, j, k }) = i + j + k;
            }
        }
    }
    fprintf(stdout, "arra[1,2,2] = %d""\n", *Value(&array, (Index) { 1, 2, 2 }));

    Destruct_Array(&array);
    return 0;
}
