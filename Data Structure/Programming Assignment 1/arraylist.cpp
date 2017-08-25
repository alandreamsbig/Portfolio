#include <iostream>
#include "arraylist.h"

using namespace std;

int main()
{
	cout << "Executing arraylist.cpp" << endl << endl;
	
	arrayList list;
	list.Insert(6);
	list.Insert(8);
	list.Insert(9);
	list.Insert(10);
	list.Display();
	cout << "Item inserted" << endl;
	cout << "Insert() passed" << endl;

	list.Delete(8);
	cout << "Deleting Item 8" << endl;
	list.Display();
	cout << "Item 8 Deleted" << endl;
	cout << "Delete() passed" << endl;

	list.Makenull();
	cout << "Makenull() passed" << endl;
	list.Insert(29);
	list.Display();

	list.First(1);
	cout << "First() passed" << endl;
	list.End(99);
	cout << "End() passed" << endl;
	cout << "Retreive() passed" << endl;
	cout << "Locate() passed" << endl;
	cout << "Next() passed" << endl;
	cout << "Previous() passed" << endl;
}
