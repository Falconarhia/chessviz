#ifndef BOARD_READ_H
#define BOARD_READ_H

#include <stdio.h>
#include <string.h>
#include "board.h"
#include "board_print_plain.h"

char* read_next(FILE* in, char* str, size_t len);
int read_file(const char* filename, char board[8][8]);

#endif 