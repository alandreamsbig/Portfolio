#Alan Tsai
#CS360 HW2 Problem 3 Resursive Descent Parser of Lecture Grammar
#Reference:http://pclib.github.io/safari/program/python-cookbook/Text/ch02s19.html
import sys
next = None
    
def P():
    sys.stdout.write("\nGrammer Input: ")
    scan()
    if next == '$':
        sys.exit(1)
    E()
    if next == '$':
        sys.stdout.write(", accept.")
    else:
        error(1)

def E():
    T()
    while next == '+':
        scan()
        T()

def T():
    F()
    while next == '*':
        scan()
        F()

def F():
    if next.isalnum(): # alphanum
        scan()
    elif next == '(':
        scan()
        E()
        if next == ')':
            scan()
        else:
            error(3)
    else:
        error(4)

def error(n):
    sys.stdout.write("\nError:" +
      str(n) + "\n")
    sys.exit(1)

def getch():
    c = sys.stdin.read(1)
    if len(c) > 0:
        sys.stdout.write(c) # echo input
        return c
    else:
        return None

def scan():
    global next
    next = getch()
    if next == None:
        sys.exit(1)
    while next.isspace(): # skip whitesp
        next = getch()

while True:
    P()
