/* Piece_Chain.c
Author: BSS9395
Update: 2020-10-20T17:00:00+08@China-Guangdong-Zhanjiang+08
Design: Memory Control
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _Piece {
	struct _Piece *_link;
	double _value;
} Piece;

#define PiecesInBlock 3
typedef struct _Block {
	struct _Block *_next;
	struct _Piece _piece[PiecesInBlock];
} Block;


Block *_Head_Block = NULL;
Piece *_Free_Piece = NULL;

Piece *Exploit() {
	Block *block = (Block *)calloc(1, sizeof(Block));
	block->_next = _Head_Block;
	_Head_Block = block;

	Piece *beg = &(block->_piece[0]);
	Piece *end = &(block->_piece[PiecesInBlock - 1]);
	while (beg < end) {
		beg->_link = beg + 1;
		beg += 1;
	}
	end->_link = _Free_Piece;  // end->_link = NULL;

	return &(block->_piece[0]);
}

Piece *Insert(double value) {
	if (_Free_Piece == NULL) {
		_Free_Piece = Exploit();
	}

	Piece *piece = _Free_Piece;
	_Free_Piece = piece->_link;
	piece->_value = value;

	return piece;
}

void Delete(Piece *piece) {
	piece->_value = 9395;

	piece->_link = _Free_Piece;
	_Free_Piece = piece;
}

void Test_Piece_Chain() {
	Piece *piece10 = Insert(10);
	Piece *piece11 = Insert(11);
	Piece *piece12 = Insert(12);

	Delete(piece11);
	Delete(piece12);
	piece12 = Insert(120);
	piece11 = Insert(110);

	Piece *piece20 = Insert(20);
	Piece *piece21 = Insert(21);

	while (_Head_Block != NULL) {
		for (int i = 0; i < PiecesInBlock; i += 1) {
			fprintf(stdout, "%.2f""\t", _Head_Block->_piece[i]._value);
		}
		fprintf(stdout, "\n");
		_Head_Block = _Head_Block->_next;
	}
}

int main(int argc, char *argv[]) {
	Test_Piece_Chain();

	return 0;
}