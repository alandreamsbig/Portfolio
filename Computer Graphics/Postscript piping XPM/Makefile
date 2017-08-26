CC = g++
CFLAGS = -g -Wall

all: start

start: clean A1
A1: clean
	g++ -o A1 hw1.cpp
	./A1 ${arg} ${ps} > ${xpm}

clean:
	rm -rf *.o *.out
