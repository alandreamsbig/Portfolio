#Makefile for lab 8
#Alan Tsai


cc = gcc
EXE = foo
JAVAC = javac
JRE = java
PAGER = less
TEST_OUT = test.out
EXP_OUT = expected.out

.PHONY : clean

foo.o : foo.c foo.h
	$(cc) -c foo.c

main.o : main.c foo.h
	$(cc) -c main.c

$(EXE) : foo.o main.o
	$(cc) -o$(EXE) main.o foo.o

run-c : $(EXE)
	./$(EXE)

run-py : foo.py
	python foo.py

read :
	@if [ -e README ]; then	$(PAGER) README; else echo File does not exist; fi;

foo.class : foo.java
	$(JAVAC) foo.java

run-java : foo.class
	$(JRE) foo

save-java :
	$(TEST_OUT)

test-java : $(TEST_OUT) $(EXP_OUT)
	-@if diff $(TEST_OUT) $(EXP_OUT) &> /dev/null ; then \
		echo "Passed!" ;\
	else \
		echo "Not the same!" ;\
	fi

clean:
	clean run-py run-c read run-java save-java test-java
