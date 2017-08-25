//
//Alan Tsai
//CS260 P1 arraylist.h
/////////////////////////////

#include <iostream>
using namespace std;

class arrayList
{
	public:
		arrayList();
		void Makenull();
		bool isFull() const;
		void Insert(int item);
		int  First(int item);
		int  End(int item);
		void Retrieve(int item);
		void Locate(int item);
		void Next(int item);
		void Display();
		void Previous(int item);
		void Delete(int item);
	private:
		int length;
		int info[100];

};

//---------------+-------------+-------------------+----------
//@desc Set the array list size 
//@param
//---------------+-------------+-------------------+----------

arrayList:: arrayList()
{
	length = 0;
}
//---------------+-------------+-------------------+----------
//@desc Insert item to the list 
//@param item: int
//---------------+-------------+-------------------+----------

void arrayList::Insert(int item)
{
	info[length] = item;
	length++;
}
//---------------+-------------+-------------------+----------
//@desc Check if the list if full 
//@param const
//---------------+-------------+-------------------+----------

bool arrayList::isFull() const
{
	return (length == 100);
}
//---------------+-------------+-------------------+----------
//@desc Initialize the list 
//@param
//---------------+-------------+-------------------+----------

void arrayList::Makenull()
{
	length = 0;
}
//---------------+-------------+-------------------+----------
//@desc Delete item from the list 
//@param item:int
//---------------+-------------+-------------------+----------

void arrayList::Delete(int item)
{
	for (int i = 0; i < 100; i++)
	{
		if (info[i] == item)
		{
			info[i] = info[length -1];
			length--;
		}
	}
}
//---------------+-------------+-------------------+----------
//@desc Get the first item from the list 
//@param item:int
//---------------+-------------+-------------------+----------

int  arrayList::First(int item)
{
	return info[0];
}
//---------------+-------------+-------------------+----------
//@desc Get the last item from the list 
//@param item:int
//---------------+-------------+-------------------+----------

int arrayList::End(int item)
{
	return info[length -1];
}

//---------------+-------------+-------------------+----------
//@desc Display the list 
//@param
//---------------+-------------+-------------------+----------

void arrayList::Display()
{
	for (int i = 0; i < length; i++)
	{
		cout << info[i] << endl;
	}
}

