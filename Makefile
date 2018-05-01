clean: CHESSVIZ
	rm build/*.o
CHESSVIZ: board_print_plain.o main.o
	gcc -Wall -Werror build/board_print_plain.o build/main.o -o CHESSVIZ 

board_print_plain.o: src/board_print_plain.c
	gcc -Wall -Werror -c src/board_print_plain.c -o build/board_print_plain.o
main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o
