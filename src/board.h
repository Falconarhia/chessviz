#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>

struct Step{
	char figure[2];
	char x[2]; // позиция в определенной строке по x
	char y[2];
	char action;
	char morph;
	char end;
};

struct Turn {
	int num;
	struct Step turn[2];
};

int parce(struct Turn* t, const char* str);
int knight_check_move(struct Step* t);
int knight_move(struct Step* t, char board[8][8]);
#endif