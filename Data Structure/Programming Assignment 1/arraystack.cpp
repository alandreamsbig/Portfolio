#include <iostream>
#include "arraystack.h"

using namespace std;

int main()
{
	cout << "Executing arraystack.cpp" << endl << endl;

	Stack firstStack(5);
	cout << "Makenull() passed" << endl; 
	firstStack.push(8);
	firstStack.push(10);
	cout << firstStack.top() << endl;
	cout << "push() passed" << endl;
	cout << "top() passed" << endl;

	firstStack.pop();
	firstStack.pop();
	cout << firstStack.top() << endl;
	cout << "pop() passed" << endl;

	firstStack.Makenull();
	cout << firstStack.top() << endl;

}
	
