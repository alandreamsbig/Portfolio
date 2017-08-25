CC = g++
CFLAGS = -g -Wall

all: start

start: clean PL 
PL: clean
	g++ -o PL.o PointerList.cpp 
	./PL.o

start: clean PS
PS: clean
	g++ -o PS.o pointerstack.cpp
	./PS.o

start: clean AL
AL: clean
	g++ -o AL.o arraylist.cpp
	./AL.o

start: clean AS
AS: clean
	g++ -o AS.o arraystack.cpp
	./AS.o

start: clean timing
timing: clean
	g++ -o timing.o timing.cpp
	./timing.o

clean:
	rm -rf *.o *.out
