all: main

main: eds.o exame.o
	gcc -o main main.c eds.o exame.o

exame.o:
	gcc -c exame.c

eds.o: 
	gcc -c eds.c

clr:
	rm exame.o
	rm eds.o
	rm main
