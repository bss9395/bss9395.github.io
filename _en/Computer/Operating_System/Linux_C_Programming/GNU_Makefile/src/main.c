
#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

int main(int argc, char *argv[]) {
    double ret = add(3.0, 4.0);
    fprintf(stdout, "ret = %lf", ret);
}