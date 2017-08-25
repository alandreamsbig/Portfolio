//
//  timing.cpp
//  CS260 P1
//
//  Created by Alan Tsai on 7/28/16.
//  Copyright © 2016 All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <time.h>
#include "PointerList.h"
//#include "pointerstack.h"
//#include "arraylist.h"
using namespace std;

int main (void)
{
    LinkedList<int> *L;
//---------------+-------------+-------------------+----------
//@desc Timing the pointerlist Insert 
//@param
//---------------+-------------+-------------------+----------

    clock_t start = clock(); 
    
	 for(int i; i <= 1000; i++)
    {
        LinkedList<int>::Insert(i,L);
	 }
	 clock_t stop = clock();
	 cout << (1000*((int)stop - start)/CLOCKS_PER_SEC) << " milliseconds"<<endl;
/*	 
//---------------+-------------+-------------------+----------
//@desc Timing the pointerlist Delete
//@param
//---------------+-------------+-------------------+----------

	 clock_t start = clock();
	 for(int i; i <=1000; i++)
	 {
		LinkedList<int>::Delete(i,L);
	 }
	 clock_t stop = clock();

	 //std::time_t time = (double) (stop - start) / CLOCKS_PER_SEC * 1000.0
	 cout << (1000*((int)stop - start)/CLOCKS_PER_SEC) << "milliseconds"<< endl;

//---------------+-------------+-------------------+----------
//@desc Timing the pointerstack Push
//@param
//---------------+-------------+-------------------+----------

	 
	 clock_t start = clock(); 
    for(int i; i <= 1000; i++)
    {
        LinkedList<int>::Push(i,L);
	 }
	 clock_t stop = clock;
	 cout << (1000*((int)stop - start)/CLOCKS_PER_SEC) << "milliseconds"<<endl;
//---------------+-------------+-------------------+----------
//@desc Timing the pointerstack pop
//@param
//---------------+-------------+-------------------+----------

	 clock_t start = clock(); 
    for(int i; i <= 1000; i++)
    {
        LinkedList<int>::Pop(i,L);
	 }
	 clock_t stop = clock;
	 cout << (1000*((int)stop - start)/CLOCKS_PER_SEC) << "milliseconds"<<endl;

//---------------+-------------+-------------------+----------
//@desc Timing the arraylist Insert
//@param
//---------------+-------------+-------------------+----------

	 clock_t start = clock(); 
    for(int i; i <= 1000; i++)
    {
        LinkedList<int>::Insert(i,L);
	 }
	 clock_t stop = clock;
	 cout << (1000*((int)stop - start)/CLOCKS_PER_SEC) << "milliseconds"<<endl;

//---------------+-------------+-------------------+----------
//@desc Timing the arraylist Delete
//@param
//---------------+-------------+-------------------+----------

	 clock_t start = clock(); 
    for(int i; i <= 1000; i++)
    {
        LinkedList<int>::Delete(i,L);
	 }
	 clock_t stop = clock;
	 cout << (1000*((int)stop - start)/CLOCKS_PER_SEC) << "milliseconds"<<endl;
	
//---------------+-------------+-------------------+----------
//@desc Timing the arraystack Push
//@param
//---------------+-------------+-------------------+----------

	 
	 clock_t start = clock(); 
    for(int i; i <= 1000; i++)
    {
        LinkedList<int>::Push(i,L);
	 }
	 clock_t stop = clock;
	 cout << (1000*((int)stop - start)/CLOCKS_PER_SEC) << "milliseconds"<<endl;
//---------------+-------------+-------------------+----------
//@desc Timing the arraystack pop
//@param
//---------------+-------------+-------------------+----------

	 clock_t start = clock(); 
    for(int i; i <= 1000; i++)
    {
        LinkedList<int>::Pop(i,L);
	 }
	 clock_t stop = clock;
	 cout << (1000*((int)stop - start)/CLOCKS_PER_SEC) << "milliseconds"<<endl;
*/
	return 0;
}

