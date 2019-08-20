/* Main.c
Design: Polymorphism
Authro: BSS9395
Update: 2019-08-20T19:13 +08
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

	pSuper->virtual->setID(pSuper, "SuperID");
	fprintf(stdout, "%s\n", pSuper->virtual->getID(pSuper));

	Derived *pDerived = (Derived *)pSuper;

	setInfo(pDerived, "SuperInfo");
	fprintf(stdout, "%s\n", getInfo(pDerived));

	destroy(pDerived);

	fprintf(stdout, "----------------------------------------\n");

	return 0;
}