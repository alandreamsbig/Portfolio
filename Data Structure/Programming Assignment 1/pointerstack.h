//
//  ppointerstack.h
//  CS260 P1
//
//  Created by Alan Tsai on 7/25/16.
//  Copyright All rights reserved.
//

#ifndef pointerstack_h
#define pointerstack_h

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <assert.h>

using namespace std;

template <class TYPE>
class Stack
{
private:
    TYPE element;
    Stack<TYPE>* next;
    
public:
    
	 //---------------+-------------+-------------------+----------
	 //@desc Makenull function for the stack
	 //@param S:TYPE
	 //---------------+-------------+-------------------+----------

    static void Makenull(Stack<TYPE>* &S)
    {
        S = new Stack<TYPE>;
        S->next = NULL;
    }
    
	 //---------------+-------------+-------------------+----------
	 //@desc Return the top element of the stack
	 //@param S:TYPE
	 //---------------+-------------+-------------------+----------

    static TYPE Top(Stack<TYPE>* S)
    {
        assert(S != NULL && S->next != NULL);
        return S->next->element;
    }
    
	 //---------------+-------------+-------------------+----------
	 //@desc Check if the stack is empty
	 //@param S:TYPE
	 //---------------+-------------+-------------------+----------

    static bool Empty(Stack<TYPE>* S)
    {
        return (S == NULL || S->next == NULL);
    }
    
	 //---------------+-------------+-------------------+----------
	 //@desc Add element to the stack
	 //@param x:TYPE
	 //@param S:TYPE
	 //---------------+-------------+-------------------+----------

    static void Push(TYPE x, Stack<TYPE>* &S)
    {
        Stack<TYPE>* temp = new Stack<TYPE>;
        temp -> element = x;
        temp -> next = S -> next;
        S -> next = temp;
    }
    
	 //---------------+-------------+-------------------+----------
	 //@desc Delete element from the stack
	 //@param S:TYPE
	 //---------------+-------------+-------------------+----------

    static void Pop(Stack<int>* &S)
    {
        assert(!Empty(S));
        S -> next = S -> next -> next;
    }
    
};

#endif /* ppointerstack_h */
