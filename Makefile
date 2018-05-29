CHESSVIZ: mkdir_bin board_print_plain.o board_read.o board.o main.o 
	gcc -std=c99 -Wall -Werror build/board_print_plain.o build/board_read.o build/board.o build/main.o -o bin/CHESSVIZ

test: CHESSVIZ_TEST
	bin/CHESSVIZ_TEST
CHESSVIZ_TEST: mkdir_bin board_print_plain.o board_read.o board.o main.o board_test.o main_test.o
	gcc -std=c99 -Wall -Werror build/board.o build/test/board_test.o build/test/main.o -o bin/CHESSVIZ_TEST

board_test.o: board_print_plain.o board_read.o board.o test/board_test.c
	gcc -std=c99 -Wall -Werror -I thirdparty -I src -c test/board_test.c -o build/test/board_test.o

main_test.o: board_test.o test/main.c
	gcc -std=c99 -Wall -Werror -I thirdparty -I src -c test/main.c -o build/test/main.o

board_print_plain.o: mkdir_build src/board_print_plain.c
	gcc -std=c99 -Wall -Werror -c src/board_print_plain.c -o build/board_print_plain.o

board_read.o: mkdir_build src/board_read.c
	gcc -std=c99 -Wall -Werror -c src/board_read.c -o build/board_read.o

board.o: mkdir_build src/board.c
	gcc -std=c99 -Wall -Werror -c src/board.c -o build/board.o

main.o: mkdir_build src/main.c
	gcc -std=c99 -Wall -Werror -c src/main.c -o build/main.o

mkdir_bin:
	if [ ! -d "bin" ]; then mkdir bin; fi
	
mkdir_build:
	if [ ! -d "build" ]; then mkdir build; fi
	if [ ! -d "build/test" ]; then mkdir build/test; fi


.PHONY:clean test
clean: 
	rm -rf bin build
