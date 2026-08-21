all: main

main: main.c
	gcc *.c -o 2048.exe -lncurses