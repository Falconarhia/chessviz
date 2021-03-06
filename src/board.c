#include "board.h"

int parce(struct Turn* t, const char* str) {
	char num[10];
	int state = 1;
	int i = 0;
	int j = 0;
	int k = 0;
	int fl = 0;

	while((str[i] != '\0') && (str[i] != '\n') && (str[i] != 13)){
		switch(state) {
			case 1:
			if((str[i] >= '1') && (str[i] <= '9')) {
				num[i] = str[i];
				state = 2;
			}
			else {
				return i + 1;
			}
			break;

			case 2:
			if((str[i] >= '0') && (str[i] <= '9')) {
				num[i] = str[i];
			}
			else if(str[i] == '.') {
				num[i] = '\0';
				sscanf(num, "%d", &(t->num));
				state = 13;
			}
			else {
				return i + 1;
			}
			break;

			case 3:
			if(fl > 1) {
				return i + 1;
			}
			if((str[i] == 'K') || (str[i] == 'Q') || (str[i] == 'R') || (str[i] == 'B') || (str[i] == 'N')) {
				t->turn[j].figure[k] = str[i];
				//++k;
				state = 4;
			}
			else if((str[i] >= 'a') && (str[i] <= 'h')) {
				t->turn[j].figure[k] = 'P';
				t->turn[j].x[k] = str[i];
				state = 5;
			}
			else {
				return i + 1;
			}
			break;

			case 4:
			if((str[i] >= 'a') && (str[i] <= 'h')) {
				//t->turn[j].figure[k] = 'P';
				t->turn[j].x[k] = str[i];
				state = 5;
			}
			else {
				return i + 1;
			}
			break;

			case 5:
			if((str[i] >= '1') && (str[i] <= '8')) {
				t->turn[j].y[k] = str[i];
				//printf("k = %d\n", k);
				++k;
				state = 6;
			}
			break;

			case 6:
			if((str[i] == '-') || (str[i] == 'x')) {
				t->turn[j].action = str[i];
				state = 3;
				++fl;
			}
			else if((str[i] == 'K') || (str[i] == 'Q') || (str[i] == 'R') || (str[i] == 'B') || (str[i] == 'N')) {
				t->turn[j].morph = str[i];
				state = 7;
			}
			else if((str[i] == '+') || (str[i] == '#')) {
				t->turn[j].end = str[i];
				state = 8;
			}
			else if(str[i] == 'e') {
				state = 9;
			}
			else if(str[i] == ' ') {
				++j;
				k = 0;
				state = 3;
				fl = 0;
				if(j > 1) {
					return i + 1;
				}
			}
			else {
				return i + 1;
			}
			break;

			case 7:
			if((str[i] == '+') || (str[i] == '#')) {

				t->turn[j].end = str[i];
				state = 8;
			}
			else if(str[i] == ' ') {
				++j;
				k = 0;
				state = 3;
				fl = 0;
				if(j > 1) {
					return i + 1;
				}
			}
			else {
				return i + 1;
			}
			break;

			case 8:
			if(str[i] == ' ') {
				++j;
				k = 0;
				state = 3;
				fl = 0;
				if(j > 1) {
					return i + 1;
				}
			}
			else {
				return i + 1;
			}
			break;

			case 9:
			if(str[i] == '.') {
				state = 10;
			}
			else {
				return i + 1;
			}
			break;

			case 10:
			if(str[i] == 'p') {
				state = 11;
			}
			else {
				return i + 1;
			}
			break;

			case 11:
			if(str[i] == '.') {
				t->turn[j].end = 'z';
				state = 12;
			}
			else {
				return i + 1;
			}
			break;

			case 13:
			if(str[i] == ' ') {
				state = 3;
			}
			else {
				return i + 1;
			}
			break;

			default:
			return i + 1;
		}
		++i;
	}

	if((j == 0) && (t->turn[j].end != '#')) {
		return i + 1;
	}

	if((state == 6) || (state == 7) || (state = 8) || (state == 12)) {
		return 0;
	}

	return -1;
	
}


int knight_check_move(struct Step* t) {
	if(abs(t->x[0] - t->x[1]) == 2) {
		if(abs(t->y[0] - t->y[1]) == 1) {
			return 0;
		}
	}
	else if(abs(t->x[0] - t->x[1]) == 1) {
		if(abs(t->y[0] - t->y[1]) == 2) {
			return 0;
		}	
	}
	else {
		return -1;
	}
	return -1;
}

int knight_move(struct Step* t, char board[8][8]){
	if(knight_check_move(t) == -1) {
		return -1;
	}

	int start_x = t->x[0] - 97;
	int start_y = 8 - (t->y[0] - 48);
	int stop_x = t->x[1] - 97;
	int stop_y = 8 - (t->y[1] - 48);
	char f = board[start_y][start_x];

	if(t->action == '-') {
		if(board[stop_y][stop_x] != ' ') {
			return -1;
		}
	}
	else if(t->action == 'x') {
		if(t->figure[0] == 'N') {
			if(board[stop_y][stop_x] != (t->figure[1] + 32)) {
				return -1;
			}
		}
		else if(t->figure[0] == 'n') {
			if(board[stop_y][stop_x] != t->figure[1]) {
				return -1;
			}
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}

	board[start_y][start_x] = ' ';
	board[stop_y][stop_x] = f;
	return 0;
}


int move(struct Step* t, char board[8][8]){
	int start_x = t->x[0] - 97;
	int start_y = 8 - (t->y[0] - 48);
	int stop_x = t->x[1] - 97;
	int stop_y = 8 - (t->y[1] - 48);
	char f = board[start_y][start_x];
	board[start_y][start_x] = ' ';
	board[stop_y][stop_x] = f;
	return 0;

}
