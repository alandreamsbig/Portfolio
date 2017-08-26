Alan Tsai
CS360 HW2
ayt32@drexel.edu

The problems are named as problem number - section number
To load scheme files, enter mit-scheme. Documentation and work citation are in the code files. 

Problem 1-1: (load “p1-1.scm”)
Enter the following command to test the code
(lookup 'name list1)
(lookup 'height list1)
(lookup 'nonexistent list1)

Problem 1-2: (load “p1-2.scm”)
(lookup-env 'school env)
(lookup-env 'building env)
(lookup-env 'nonexistent env)

Problem 2

4.6 (load “p4_4.scm”)
(and #t #t #f)
(or #t #f #t)
or any other desired input

4.9 (load “p4_9.scm”)
'(begin (define (iter-name) (if (true) (begin (body) (iter-name)) done)) (iter-name))
should already be printing this out

4.11 (load “p4_11.scm”)
(make-binding '(a b c) '(1 2 3))
(make-frame '(a b c) '(11 33 11))

Problem 3:

python problem3.py
Input: a+b*c$
Input: (a + b)*c$
Input: ((a*b*(c+(d))+e)+i)$

Test errors:
Input: a+b*$
Input: (a+b)+c)*d)$

I don’t understand the grammar in the lecture so for this problem, I’m using the following grammar
Simple Language: REs
Parser below
P ---> E '$'
E ---> T  { '+' T }
T ---> F  { '*' F }
F ---> '(' E ')' | digit | letter

Problem 4:
To test the encoding and decoding, enter ghci and test the encoding and decoding
:load problem4.hs

then,enter the commands

encode “whatever”
makeHuffmanTree “whatever”
decode “whatever”

I’m not sure how to run the program in ghci but I found out that you can run the program with the following commands,
ghc -o problem4 problem4.hs
./problem4

