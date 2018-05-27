#include "board_read.h"

char* read_next(FILE* in, char* str, size_t len) {
	if((in == NULL) || (str == NULL)) {
		return NULL;
	}

	return fgets(str, len, in);
}

int read_file(const char* filename) {
	if(filename == NULL) {
		return -1;
	}

	FILE* in = fopen(filename, "r");
	if(in == NULL) {
		return -1;
	}

	char str[100];
	while(read_next(in, str, 100) != NULL) {
		printf("%s", str);
	}
	return 0;
}