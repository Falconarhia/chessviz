#include "board_read.h"

char* read_next(FILE* in, char* str, size_t len) {
	if((in == NULL) || (str == NULL)) {
		return NULL;
	}

	return fgets(str, len, in);
}

int read_file(const char* filename, char board[8][8]) {
	if(filename == NULL) {
		return -1;
	}

	FILE* in = fopen(filename, "r");
	if(in == NULL) {
		return -1;
	}

	struct Turn t;
	char str[100];
	int f;
	int l;
	while(read_next(in, str, 100) != NULL) {
		printf("\n%s\n", str);
		l = strlen(str);
		if(str[l - 1] == '\n') {
			str[l - 1] = '\0';
		}
		if((f = parce(&t, str)) != 0) {
			printf("%d\n", f);
			return f;
		}
		else {
			//printf("xf1 = %c xf2 = %c xst = %c xs= %c yst = %c ys= %c act = %c morph = %c end = %c\n", t.turn[0].figure[0], t.turn[0].figure[1], t.turn[0].x[0], t.turn[0].x[1], t.turn[0].y[0], t.turn[0].y[1], t.turn[0].action, t.turn[0].morph, t.turn[0].end);
			move(&(t.turn[0]), board);
			show_board(board);
			printf("\n");
			move(&(t.turn[1]), board);
			show_board(board);
		}
	}
	return 0;
}