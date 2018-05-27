CHESSVIZ: mkdir_bin board_print_plain.o board_read.o board.o main.o 
	gcc -std=c99 -Wall -Werror build/board_print_plain.o build/board_read.o build/board.o build/main.o -o bin/CHESSVIZ 

board_print_plain.o: mkdir_build src/board_print_plain.c
	gcc -std=c99 -Wall -Werror -c src/board_print_plain.c -o build/board_print_plain.o

board_read.o: mkdir_build src/board_read.c
	gcc -std=c99 -Wall -Werror -c src/board_read.c -o build/board_read.o

board.o: mkdir_build src/board.c
	gcc -std=c99 -Wall -Werror -c src/board.c -o build/board.o

main.o: mkdir_build src/main.c
	gcc -std=c99 -Wall -Werror -c src/main.c -o build/main.o

mkdir_bin:
	mkdir bin
	
mkdir_build:
	mkdir build

.PHONY:clean
clean: 
	rm -rf bin build
