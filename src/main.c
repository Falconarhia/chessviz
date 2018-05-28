#include "board_print_plain.h"
#include "board_read.h"
#include "board.h"

int main(int argc, char* argv[])
{
	char board[8][8]= {{'r','n','b','q','k','b','n','r'},
	                   {'p','p','p','p','p','p','p','p'},
	                   {' ',' ',' ',' ',' ',' ',' ',' '},
	                   {' ',' ',' ',' ',' ',' ',' ',' '},
	                   {' ',' ',' ',' ',' ',' ',' ',' '},
	                   {' ',' ','p',' ',' ',' ',' ',' '},
	                   {'P','P','P','P','P','P','P','P'},
	                   {'R','N','B','Q','K','B','N','R'}};
	show_board(board);
	printf("\n");
	int a = read_file(argv[1], board);
	if(a != 0) {
		printf("Ошибка в строке %d\n", a);
		return -1;
	}
	return 0;
}