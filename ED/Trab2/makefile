all: main

eds.o: sources/eds.c headers/eds.h
	gcc -c sources/eds.c

main: eds.o
	gcc -o main main.c eds.o

clr:
	rm eds.o
	rm main
