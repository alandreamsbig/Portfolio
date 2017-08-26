all: start

start: clean server 
server: clean
	gcc csapp.c server.c -lpthread -o server 
	./server 8080

client: clean
	gcc csapp.c client.c -lpthread -o client
	./client tux64-11.cs.drexel.edu 8080  

start:clean miniRSA
miniRSA: clean
	gcc miniRSA.c -o miniRSA
	./miniRSA ${input1} ${input2}

clean:
	rm -rf *.o *.out
