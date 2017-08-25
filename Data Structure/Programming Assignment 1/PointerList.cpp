//
//  PointerList.cpp
//  CS260 P1
//
//  Created by   on 7/18/16.
//  Copyright © Alan Tsai. All rights reserved.
//

#include "PointerList.h"
#include <assert.h>

int main() {
    
 	 cout << "Executing PointerList.cpp" << endl << endl;

    LinkedList<int>* L;
    LinkedList<int>::Makenull(L);
    cout << "Makenull function passed" << endl;
    assert(LinkedList<int>::Next(L) == NULL);
    
    cout << "Testing Insert function, Inserting int 5 to the list" << endl;
    LinkedList<int>::Insert(5, LinkedList<int>::End(L));
    LinkedList<int>::Insert(6, LinkedList<int>::End(L));
    LinkedList<int>::Insert(7, LinkedList<int>::End(L));
    assert(LinkedList<int>::Next(L) != NULL);
    cout << "Next() function passed" << endl;
    
    cout << "Testing Retrieve, First, End function" << endl;
    assert(LinkedList<int>::Retrieve(LinkedList<int>::First(L), L) == 5);
    cout << "Function passed, First and Endl element is 5" << endl;
    
    LinkedList<int>::Insert(6, LinkedList<int>::First(L));
    assert(LinkedList<int>::Retrieve(LinkedList<int>::First(L), L) == 6);
    
    cout << "Testing delete function" << endl;
    LinkedList<int>::Delete(LinkedList<int>::First(L), L);
    assert(LinkedList<int>::Retrieve(LinkedList<int>::First(L), L) == 5);
    
    cout << "Testing Previous function" << endl;
    LinkedList<int>* previous_end = LinkedList<int>::Previous(LinkedList<int>::End(L), L);
    assert(LinkedList<int>::Retrieve(previous_end, L) == 7);
    
    cout << "Previous function passed" << endl;
    cout << "Testing Locate function" << endl;
    
    assert(LinkedList<int>::Locate(5, L));
    cout << "Locate function passed" << endl;
    
    return 0;
}
