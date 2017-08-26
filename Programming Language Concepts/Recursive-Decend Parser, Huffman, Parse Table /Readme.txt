Alan Tsai
CS360 HW1
ayt32@drexel.edu

Problem 1: 
To run problem 1, Run mit-scheme on tux and (load “problem1.scm”)
Paste the following code to test:
(decode sample-message sample-tree)
(encode '(A D A B B C A) sample-tree)

Work citation:
http://community.schemewiki.org/?sicp-ex-2.68

Problem 2:
Run mit-scheme on tux and (load “problem2.scm”)
Use the following code, however, it produce the output like the screenshot in problem 2 with racket but only output ‘() on tux…

(define next (iterator '(0 2 7)))
(begin (next) (next) (next) (next) (next))

Specifications:
The problem returns a function which when repeatedly called, it returns the numbers in the sequence (range (start step end)). when the sequence is exhausted, it returns (). The program first create an iterator and variables start, step end. If start is less than end, change the value of start inside the function. Subtract step from start. Else create empty list. iterate through the list.

Work citation:
http://www.javacms.tech/questions/4782749/scheme-function-returns-step-values-but-doesnt-append-an-empty-list-to-it

Problem 3:
The code is modified directly from FCS section 11.6. Run the make file. 
Paste the following code on tux to compile and run:

gcc -o problem3.o problem3.c
./problem3.o

Problem 4:
Run the make file. 
The files are preorder.cpp and postorder.cpp