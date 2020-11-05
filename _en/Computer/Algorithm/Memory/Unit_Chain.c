/* Unit_Chain.c
Author: BSS9395
Update: 2020-11-04T06:25:00+08@China-Guangdong-Zhanjiang+08
Design: Memory Control
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _Unit {
	union {
		struct _Unit *_;
		double _value;
	};
} Unit;

#define UnitsInBlock 3
typedef struct _Block {
	struct _Block *_next;
	struct _Unit _unit[UnitsInBlock];
} Block;


Block *_Head_Block = NULL;
Unit *_Free_Unit = NULL;

Unit *Exploit() {
	Block *block = (Block *)calloc(1, sizeof(Block));
	block->_next = _Head_Block;
	_Head_Block = block;

	Unit *beg = &(block->_unit[0]);
	Unit *end = &(block->_unit[UnitsInBlock - 1]);
	while (beg < end) {
		*(Unit **)beg = beg + 1;
		beg += 1;
	}
	*(Unit **)end = _Free_Unit;  // *(Unit **)end = NULL;

	return &(block->_unit[0]);
}

Unit *Insert(double value) {
	if (_Free_Unit == NULL) {
		_Free_Unit = Exploit();
	}

	Unit *unit = _Free_Unit;
	_Free_Unit = *(Unit **)unit;
	unit->_value = value;

	return unit;
}

void Delete(Unit *unit) {
	unit->_value = 9395;

	*(Unit **)unit = _Free_Unit;
	_Free_Unit = unit;
}

void Test_Unit_Chain() {
	Unit *unit10 = Insert(10);
	Unit *unit11 = Insert(11);
	Unit *unit12 = Insert(12);

	Delete(unit11);
	Delete(unit12);
	unit12 = Insert(120);
	unit11 = Insert(110);

	Unit *unit20 = Insert(20);
	Unit *unit21 = Insert(21);

	while (_Head_Block != NULL) {
		for (int i = 0; i < UnitsInBlock; i += 1) {
			fprintf(stdout, "%.2f""\t", _Head_Block->_unit[i]._value);
		}
		fprintf(stdout, "\n");
		_Head_Block = _Head_Block->_next;
	}
}

int main(int argc, char *argv[]) {
	Test_Unit_Chain();

	return 0;
}