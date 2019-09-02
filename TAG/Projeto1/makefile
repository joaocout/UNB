all: main
	./main

main: functions.o
	g++ -Wall -o main main.cpp functions.o

functions.o:
	g++ -Wall -c functions.cpp

rm:
	rm functions.o
	rm main
