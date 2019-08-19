/* Main.c
Design: Polymorphism
Authro: BSS9395
Update: 2019-08-20T01:22 +08
*/

#include "Super.h"
#include "Derived.h"

#include <stdio.h>

int main() {

	fprintf(stdout, "sizeof(Super) = %ld\n", sizeof(Super));
	fprintf(stdout, "sizeof(Derived) = %ld\n", sizeof(Derived));

	fprintf(stdout, "----------------------------------------\n");

	Super super = mkSuper();
	destruct(&super);

	fprintf(stdout, "----------------------------------------\n");

	Derived derived = mkDerived();
	destruct(&derived);

	fprintf(stdout, "----------------------------------------\n");

	Super *pSuper = newSuper();
	destroy(pSuper);

	fprintf(stdout, "----------------------------------------\n");

	Derived *pDerived = newDerived();
	destroy(pDerived);

	fprintf(stdout, "----------------------------------------\n");

	Super *p = (Super *)newDerived();
	destroy(p);

	fprintf(stdout, "----------------------------------------\n");

	return 0;
}