#include <stdio.h>
#include <stdarg.h>

typedef int Ret;

typedef struct {
	int i;
	char *n;
} In;

typedef struct {
	char *o;
} InOut;

typedef struct {
	double u;
	char *t;
} Out;

Ret function(In in, InOut *io, Out *out) {
	Ret ret = 0;

	printf("In = { %d, %s }  Inout = { %s }  Out = { %lf, %s } \n", in.i, in.n, io->o, out->u, out->t);

	in.i = 11;
	in.n = "fn";
	io->o = "fo";
	out->u = 22;
	out->t = "ft";

	in = (In) { 111, "ffn" };
	*io = (InOut) { "ffo" };
	*out = (Out) { 222, "fft" };

	ret += 1;
	return ret;
}


int main(int argc, char *argv[]) {
	In in = { .i = 1,.n = "n" };
	InOut io = { .o = "o" };
	Out out = { .u = 2,.t = "t" };

	function(in, &io, &out);
	//function((In) { .i = 2 }, NULL, &out);

	printf("In = { %d, %s }  Inout = { %s }  Out = { %lf, %s } \n", in.i, in.n, io.o, out.u, out.t);

	return 0;
}