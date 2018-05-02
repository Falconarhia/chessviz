CHESSVIZ: board_print_plain.o main.o
	gcc -std=c99 -Wall -Werror build/board_print_plain.o build/main.o -o CHESSVIZ 

board_print_plain.o: src/board_print_plain.c
	gcc -std=c99 -Wall -Werror -c src/board_print_plain.c -o build/board_print_plain.o
main.o: src/main.c
	gcc -std=c99 -Wall -Werror -c src/main.c -o build/main.o
.PHONY:clean
clean: 
	rm CHESSVIZ build/*.o
