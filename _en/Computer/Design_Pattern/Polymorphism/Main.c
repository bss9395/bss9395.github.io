/* Main.c
Design: Polymorphism
Authro: BSS9395
Update: 2019-08-20T21:26 +08 @ ShenZhen +08
*/

#include "Super.h"
#include "Derived.h"

#include <stdio.h>

int main() {

	fprintf(stdout, "sizeof(Super) = %ld\n", sizeof(Super));
	fprintf(stdout, "sizeof(Derived) = %ld\n", sizeof(Derived));

	fprintf(stdout, "----------------------------------------\n");

	Derived derived = mkDerived();
	destruct(&derived);

	fprintf(stdout, "----------------------------------------\n");

	Super *pSuper = (Super *)newDerived();

	fprintf(stdout, "----------------------------------------\n");

	pSuper->function->virtual_setID(pSuper, "SuperID");
	fprintf(stdout, "%s\n", pSuper->function->virtual_getID(pSuper));

	fprintf(stdout, "----------------------------------------\n");

	Derived *pDerived = (Derived *)pSuper;

	pDerived->function->setInfo(pDerived, "SuperInfo");
	fprintf(stdout, "%s\n", pDerived->function->getInfo(pDerived));

	fprintf(stdout, "----------------------------------------\n");

	pDerived->function->setInfo(pDerived, "DerivedInfo");
	fprintf(stdout, "%s\n", pDerived->function->getInfo(pDerived));

	fprintf(stdout, "----------------------------------------\n");

	destroy(pDerived);

	fprintf(stdout, "----------------------------------------\n");

	return 0;
}