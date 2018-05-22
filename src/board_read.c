#include "board_read.h"

int read_next(FILE* in, char* str) {
	if((in == NULL) || (str == NULL)) {
		return -1;
	}

	return fscanf(in, "%s", str);
}