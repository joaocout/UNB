all: main

main: eds.o exame.o
	gcc -g -o main main.c eds.o exame.o

exame.o:
	gcc -g -c exame.c

eds.o: 
	gcc -g -c eds.c

clr:
	rm exame.o
	rm eds.o
	rm main
