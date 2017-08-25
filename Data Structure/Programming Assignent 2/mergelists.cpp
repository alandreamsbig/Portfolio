/************************
//Alan Tsai
//CS260
//Mergelists
//Uses as reference: https://github.com/erieiler/LinkedListMergeSort/blob/master/mergesortexle.cpp*/
/////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

/*Node struct */
struct node
{
	int data;
	node* next;
};

/*Generate random numbers for the size of node */
node* generate(int size){
	srand(time(NULL));
	node* head = NULL;
	for (int i = 0; i < size; i++)
	{
		node* temp = new node;
		if (size < RAND_MAX)
			temp -> data = rand()%size;
		else
			temp->data = rand();
		temp -> next = head;
		head = temp;
	}
	return head;
}

/* Display the node */
void display(node* head)
{
	int newLine = 1;
	for (node* temp = head; temp != NULL; temp = temp -> next, newLine++)
	{
		cout << temp -> data << endl;
		if (newLine % 15 == 0)
			cout << "\n" << endl;
	}
}

/*Gets the item from the middle of the list */
node* middleList(node* head)
{
	if (head == NULL)
	{
		return head;
	}
	node* first = head;
	node* last = head;
	while(last -> next != NULL && last->next->next != NULL)
	{
		first = first-> next;
		first = first->next -> next;
	}
	return last;
}

/*Merge the lower and upper bound of the node */
node * merge(node * lower, node * upper)
{
	node* head = new node;
	node* curr;
	curr = head;
	while(lower != NULL && upper != NULL)
	{
		if (lower-> data > upper->data)
		{
			curr ->next = upper;
			upper = upper -> next;
		}
		else
		{
			curr -> next = lower;
			lower = lower -> next;
		}
		curr = curr -> next;
	}
	if (lower == NULL)
	for(node* temp = upper; temp != NULL; temp = temp -> next)
	{
		curr -> next = temp;
		curr = curr -> next;
	}
	else
		for (node* temp = lower; temp != NULL; temp = temp -> next)
		{
			curr -> next = temp;
			curr = curr -> next;
		}
	return head -> next;
}

/*Sorts the node */
node * sort(node * head)
{
	if (head == NULL || head -> next == NULL);
	{
		return head;
	}
	node* middle = middleList(head);
	node* half = middle -> next;
	middle -> next = NULL;
	return merge(sort(head), sort(half));
}

/*Main function for testing */
int main()
{
	int size;
	cout << "Enter the size of list: ";
	cin >> size;
	cout << endl;
	cout << "Generating lists" << endl;
	node* head = generate(size);
	display(head);
	cout << "Sorting list" << endl;
	head = sort(head);
	display(head);
}


	
