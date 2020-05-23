/* Main.c
Author: BSS9395
Update: 2020-05-23T23:53:00+08@China-Guangdong-Zhanjiang+08
Design: Polymorphism
*/

/* Class Inheritance
ReadMe --   Super   -- Virtual_SetID
			  |     \
ShowMe --  Derived   - Virtual_GetID
			 / \
LeadMe -- Boy  Girl -- SeeYou
*/

/* Struct Boy
+---------------------------------------------+ Super
| _offset_ = offsetof(Derived, _offset_) = 28 |
| Virtual_Destruct                            |
| ...                                         |
| _id   = "ID"                                |
| _desc = "Read Me and My Life."              |
+---------------------------------------------+ Derived
| _offset_ = offsetof(Boy, _offset_) = 52     |
| Virtual_Destruct                            |
| ...                                         |
| _desc = "Show Me Your Passionate Love."     |
+---------------------------------------------+ Boy
| _offset_ = 0                                |
| Virtual_Destruct                            |
| ...                                         |
| _desc = "Lead Me to Your World."            |
+---------------------------------------------+
*/

#define Super_c
#include "Super.c"

#define Derived_c
#include "Derived.c"

#define Boy_c
#include "Boy.c"

#define Girl_c
#include "Girl.c"


int main(int argc, char *argv[]) {
	fprintf(stderr, "sizeof(Super)   = %ld\n", sizeof(Super));
	fprintf(stderr, "sizeof(Derived) = %ld\n", sizeof(Derived));
	fprintf(stderr, "sizeof(Boy)     = %ld\n", sizeof(Boy));
	fprintf(stderr, "sizeof(Girl)    = %ld\n", sizeof(Girl));

	fprintf(stderr, "\n""----------------------------------------""\n");

	Boy boy = MakeBoy();
	fprintf(stderr, "_super_   _offset_ = %ld""\n", boy._derived_._super_._offset_);
	fprintf(stderr, "_derived_ _offset_ = %ld""\n", boy._derived_._offset_);
	fprintf(stderr, "_boy_     _offset_ = %ld""\n", boy._offset_);

	fprintf(stderr, "\n""----------------------------------------""\n");

	Super *super = (Super *)NewBoy();
	super->Virtual_SetID(super, "ID");

	char *id = super->Virtual_GetID(super);
	fprintf(stderr, "%s""\n", id);

	Destruct(super);

	return 0;
}