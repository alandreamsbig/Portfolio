CC = g++
CFLAGS = -g -Wall

all: start

start: clean pointerqueue 
pointerqueue: clean
	g++ -o pointerqueue.o pointerqueue.cpp 
	./pointerqueue.o

start: clean mergelists
mergelists: clean
	g++ -o mergelists.o mergelists.cpp
	./mergelists.o

start: clean listconcat
listconcat: clean
	python listconcat.py

start: clean levelorder
levelorder: clean
	g++ -o levelorder.o levelorder.cpp
	./levelorder.o

start: clean traversalconvert
traversalconvert: clean
	g++ -o traversalconvert.o traversalconvert.cpp
	./traversalconvert.o

start: clean preorder
preorder: clean
	g++ -o preorder.o preorder.cpp
	./preorder.o

start: clean postorder
postorder: clean
	g++ -o postorder.o postorder.cpp
	./postorder.o

start: clean huffman
huffman: clean
	g++ -o huffman.o huffman.cpp
	./huffman.o



clean:
	rm -rf *.o *.out
