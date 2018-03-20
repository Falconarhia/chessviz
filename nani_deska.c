#include "nani_deska.h"

void show_deska (char deska[8][8])
{
	for(int i=0; i< 8; ++i )
	{
		printf("%d ", (8-i));
		for(int j=0; j<8; ++j)
		{
			printf("%c ", deska[i][j]);
		} 
		printf("\n");
	}

printf("  a b c d e f g h\n");
}