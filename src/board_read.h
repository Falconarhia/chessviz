#ifndef BOARD_READ_H
#define BOARD_READ_H

#include <stdio.h>

char* read_next(FILE* in, char* str, size_t len);
int read_file(const char* filename);

#endif 