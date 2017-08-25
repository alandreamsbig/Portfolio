//
//  arraystack.cpp
//  CS260 P1
//
//  Created by Alan Tsai  on 7/25/16.
//  Copyright © 2016 Anyapps. All rights reserved.
//

#ifndef arraystack_h
#define arraystack_h

#include <stdio.h>
#include <iostream>
using namespace std;


class Stack
{
public:
    bool Empty() const;
    void Makenull();
    bool isFullStack()const;
	 Stack(int size);
    int top() const;
    void push(int newItem);
    Stack(const Stack& otherStack);
    void pop();
    ~Stack();
private:
    int topstack;
    int maxsize;
    int* list;
    
};
//---------------+-------------+-------------------+----------
//@desc Set the stack size 
//@param size:int
//---------------+-------------+-------------------+----------

Stack::Stack(int size)
{
    maxsize = size;
    Makenull();
    list = new int[maxsize];
}
//---------------+-------------+-------------------+----------
//@desc Initialize the stack 
//@param
//---------------+-------------+-------------------+----------

void Stack::Makenull()
{
    topstack = 0;
}
//---------------+-------------+-------------------+----------
//@desc Check if the stack is Empty 
//@param const
//---------------+-------------+-------------------+----------

bool Stack::Empty() const
{
    return topstack == 0;
}
//---------------+-------------+-------------------+----------
//@desc Check if the stack is full 
//@param const
//---------------+-------------+-------------------+----------

bool Stack::isFullStack() const
{
	return topstack == maxsize;
}

//---------------+-------------+-------------------+----------
//@desc create another stack 
//@param otherStack:stack
//---------------+-------------+-------------------+----------

Stack::Stack(const Stack& otherStack)
{
    maxsize = otherStack.maxsize;
    topstack = otherStack.topstack;
    list = new int[maxsize];
    for (int i = 0; i < topstack; i++)
    {
        list[i] = otherStack.list[i];
    }
}
//---------------+-------------+-------------------+----------
//@desc return the top of the stack 
//@param const
//---------------+-------------+-------------------+----------

int Stack::top() const
{
    if(Empty())
    {
        cout <<"Is empty" << endl;
	 }
        return list[topstack -1];
    
}
//---------------+-------------+-------------------+----------
//@desc Insert newItem to the stack 
//@param newItem:int
//---------------+-------------+-------------------+----------

void Stack::push(int newItem)
{
	if(!isFullStack())
	{
		list[topstack] = newItem;
		topstack++;
	}
}
//---------------+-------------+-------------------+----------
//@desc Remove item from the stack 
//@param
//---------------+-------------+-------------------+----------

void Stack::pop()
{
	if(!Empty())
	{
		topstack--;
	}
}

Stack::~Stack(){
	delete[] list;
}

#endif
