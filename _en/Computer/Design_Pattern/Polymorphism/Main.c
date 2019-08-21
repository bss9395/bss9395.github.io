/* Main.c
Design: Polymorphism with Single Inheritance
Author: BSS9395
Update: 2019-08-22T01:58 +08 @ ShenZhen +08
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Helper.h"
#include "Super.h"
#include "Derived.h"
#include "Boy.h"
#include "Girl.h"

/* Class Inheritance

readMe --   Super   (_ID)   -- virtual_setID
			  |             \
showMe --  Derived  (_Desc)  - virtual_getID
			 / \
leadMe -- Boy  Girl (_Info) -- seeYou

*/


int main(int argc, char *argv[]) {

	printf("sizeof(Super)   = %ld\n", sizeof(Super));
	printf("sizeof(Derived) = %ld\n", sizeof(Derived));
	printf("sizeof(Boy)     = %ld\n", sizeof(Boy));
	printf("sizeof(Girl)    = %ld\n", sizeof(Girl));

	printf("----------------------------------------\n");

	Boy boy = makeBoy();
	//boy.function->virtual_destruct(&boy);
	destruct(&boy);

	printf("----------------------------------------\n");

	Derived *pDerived = (Derived *)newBoy();

	printf("----------------------------------------\n");

	pDerived->function->virtual_setID(pDerived, "ID");
	printf("%s\n", pDerived->function->virtual_getID(pDerived));

	printf("----------------------------------------\n");

	Super *pSuper = (Super *)pDerived;
	pSuper->function->readMe(pSuper);

	pDerived->function->showMe(pDerived);

	Boy *pBoy = (Boy *)pDerived;
	pBoy->function->leadMe(pBoy);

	printf("----------------------------------------\n");

	destroy(pDerived);

	printf("----------------------------------------\n");

	Girl girl = makeGirl();

	printf("----------------------------------------\n");

	girl.function->seeYou(&girl);
	girl.derived.function->showMe((Derived *)&girl);
	girl.derived.super.function->readMe((Super *)&girl);

	printf("----------------------------------------\n");

	girl.function->virtual_setID(&girl, "ID");
	printf("%s\n", girl.function->virtual_getID(&girl));

	printf("----------------------------------------\n");

	destruct(&girl);

	printf("----------------------------------------\n");

	return 0;
}