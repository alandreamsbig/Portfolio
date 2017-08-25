//
//  PointerList.h
//  CS260 P1
//
//  Created by Alan Tsai on 7/18/16
//  Copyright © 2016 All rights reserved.
//

#ifndef PointerList_h
#define PointerList_h

#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;

template <class TYPE>
class LinkedList
{
private:
	 //define a generic element
    TYPE element;
    LinkedList<TYPE>* next;
    
public:
    //---------------+-------------+-------------------+----------
	 //@desc Makenull function for the list
	 //@param L:TYPE
	 //---------------+-------------+-------------------+----------
    static void Makenull(LinkedList<TYPE>* &L)
    {
        L = new LinkedList<TYPE>;
        L->next = NULL;
    }
    
	 //---------------+-------------+-------------------+----------
	 //@desc End function return the end element of the list
	 //@param L:TYPE
	 //---------------+-------------+-------------------+----------
	 static LinkedList<TYPE>* End(LinkedList<TYPE>* L)
    {
        LinkedList<TYPE>* q = L;
        while (q->next != NULL)
            q = q->next;
        
        return q;
    }

    //---------------+-------------+-------------------+----------
	 //@desc Insert element to the list
	 //@param x:TYPE
	 //@oaran p: TYPE
	 //---------------+-------------+-------------------+----------
	 static void Insert(TYPE x, LinkedList<TYPE>* p)
    {
        LinkedList<TYPE>* temp;
        temp = p->next;
        p->next = new LinkedList<TYPE>;
        p->next->element = x;
        p->next->next = temp;
    }
   
    //---------------+-------------+-------------------+----------
	 //@desc Delete element in the list given position
	 //@param p:TYPE
	 //@param L:TYPE
	 //---------------+-------------+-------------------+----------
	 static void Delete(LinkedList<TYPE>* p, LinkedList<TYPE>* L)
    {
        assert(p != End(L));
        //assert(Locate(Retrieve(p, L), L) != End(L));
        
        p->next = p->next->next;
    }

    //---------------+-------------+-------------------+----------
	 //@desc Return the next element from the list
	 //@param p:TYPE
	 //---------------+-------------+-------------------+----------
	 static LinkedList<TYPE>* Next(LinkedList<TYPE>* p)
    {
        return p->next;
    }
    
	 //---------------+-------------+-------------------+----------
	 //@desc Return the first element from the list
	 //@param L:TYPE
	 //---------------+-------------+-------------------+----------
	 static LinkedList<TYPE>* First(LinkedList<TYPE>* L)
    {
        if (NULL == L)
            return End(L);
        
        return L;
    }

    //---------------+-------------+-------------------+----------
	 //@desc  Return the element given the position from the list 
	 //@param p:TYPE
	 //@param L:TYPE
	 //---------------+-------------+-------------------+----------
	 static TYPE Retrieve(LinkedList<TYPE>* p, LinkedList<TYPE>* L)
    {
        assert(p != End(L));
        assert(L != NULL);
        assert(Locate(p -> next -> element, L) != End(L));
        return p -> next ->element;
    }
    
	 //---------------+-------------+-------------------+----------
	 //@desc Return the postion of the list given the element 
	 //@param x:TYPE
	 //@param L:TYPE
	 //---------------+-------------+-------------------+----------
	 static LinkedList<TYPE>* Locate(TYPE x, LinkedList<TYPE>* L)
    {
        LinkedList<TYPE>* p = L;
        while (p -> next != NULL)
        {
            if (p-> next -> element == x)
                return p;
            else
                p = p -> next;
        }
        return End(L);
    }
    //---------------+-------------+-------------------+----------
	 //@desc Return the previous element from the list
	 //@param p:TYPE
	 //@param L:TYPE
	 //---------------+-------------+-------------------+----------

    static LinkedList<TYPE>* Previous(LinkedList<TYPE>* p, LinkedList<TYPE>* L)
    {
        assert(p != First(L));
        
        LinkedList<TYPE>* temp;
        temp = First(L);
        while(temp -> next != p)
        {
            temp = temp -> next;
        }
        return temp;
    }
};

#endif /* PointerList_h */
