//
//  pointerstack.cpp
//  CS260 P1
//
//  Created by Alan Tsai on 7/25/16.
//  Copyright © 2016 Anyapps. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "pointerstack.h"

int main (void)
{
    cout<<"Executing pointerstack.cpp" << endl << endl;

	 Stack<int>* S;
    Stack<int>::Makenull(S);
    cout << "Makenull() passed" << endl;
    
    Stack<int>::Push(1, S);
    assert(Stack<int>::Top(S) == 1);
    cout << "Push() passed" << endl;
    
    Stack<int>::Push(2, S);
    assert(Stack<int>::Top(S) == 2);
    cout << "Top() passed" << endl;
    
    Stack<int>::Pop(S);
    assert(Stack<int>::Top(S) == 1);
    cout << "Pop passed" << endl;
    
    Stack<int>::Pop(S);
    assert(Stack<int>::Empty(S));
    cout << "Empty() passed" <<endl;
}
