CC = g++
CFLAGS = -g -Wall

all: start

#start: clean problem3
#problem3: clean
	#gcc -o problem3.o problem3.c
	#./problem3.o

start: clean preorder
preorder: clean
	g++ -o preorder.o preorder.cpp
	./preorder.o

start: clean postorder
postorder: clean
	g++ -o postorder.o postorder.cpp
	./postorder.o

clean:
	rm -rf *.o *.out
