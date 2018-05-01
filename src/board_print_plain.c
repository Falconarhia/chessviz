#include "board_print_plain.h"

void show_board (char board[8][8])
{
	for(int i=0; i< 8; ++i )
	{
		printf("%d ", (8-i));
		for(int j=0; j<8; ++j)
		{
			printf("%c ", board[i][j]);
		} 
		printf("\n");
	}

printf("  a b c d e f g h\n");
}