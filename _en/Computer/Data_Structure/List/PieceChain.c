/* PieceChain.c
Author: BSS9395
Update: 2020-10-20T17:00:00+08@China-Guangdong-Zhanjiang+08
Design: Memory Control
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _Piece {
	struct _Piece *_prev;
	long _value;
} Piece;

#define PiecesInBlock 3
typedef struct _Block {
	struct _Block *_next;
	Piece _piece[PiecesInBlock];
} Block;

static Block *head_block = NULL;
static Piece *free_piece = NULL;

static Piece *Exploit() {
	Block *block = (Block *)calloc(1, sizeof(Block));
	block->_next = head_block;
	head_block = block;

	Piece *end = &block->_piece[PiecesInBlock];
	Piece *beg = &block->_piece[0];
	while (end -= 1, beg < end) {
		end->_prev = end - 1;
	}
	beg->_prev = NULL;

	return &block->_piece[PiecesInBlock - 1];
}

static Piece *Insert(long value) {
	if (free_piece == NULL) {
		free_piece = Exploit();
	}

	Piece *piece = free_piece;
	free_piece = piece->_prev;
	piece->_value = value;

	return piece;
}

static void Delete(Piece *piece) {
	piece->_value = 9395;

	piece->_prev = free_piece;
	free_piece = piece;
}


void Test() {
	Piece *piece12 = Insert(12);
	Piece *piece11 = Insert(11);
	Piece *piece10 = Insert(10);

	Piece *piece22 = Insert(22);
	Delete(piece11);
	Delete(piece10);
	piece10 = Insert(110);
	piece11 = Insert(111);
	Piece *piece21 = Insert(21);
	Piece *piece20 = Insert(20);

	while (head_block != NULL) {
		for (int i = 0; i < PiecesInBlock; i += 1) {
			fprintf(stdout, "%ld\t", head_block->_piece[i]._value);
		}
		fprintf(stdout, "\n");
		head_block = head_block->_next;
	}

	return;
}

int main(int argc, char *argv[]) {
	Test();

	return 0;
}

