/****************
//Alan Tsai
//CS260
//Pointer Queue
*******************/

#ifndef POINTERQUEUE_H
#define POINTERQUEUE_H

#include<iostream>
using namespace std;

typedef int QueueType;

class Queue
{
	public:
		Queue(); //constructor
		~Queue(); //destructor

		bool isEmpty();
		void enqueue(QueueType newItem);
		bool dequeue();
		bool dequeue(QueueType& queueFirst);
		bool first(QueueType& queueFirst);
		void createQueue();
	
	private:
		struct queueNode
		{
			QueueType item;
			queueNode *next;
		};

		queueNode *front;
		queueNode *back;
};
/*Queue constructor*/
Queue::Queue(){
	back = front = NULL;
}

/*Queue destructor*/
Queue::~Queue(){
	while(!isEmpty())
		dequeue();
}
/* Check if the list is empty */
bool Queue::isEmpty(){
	return back == NULL;
}

/* Insert newItem to the queue */
void Queue::enqueue(QueueType newItem){
	queueNode *newPtr = new queueNode;
	newPtr ->item = newItem;
	newPtr ->next = NULL;
	
	if (isEmpty())
		front = newPtr;
	else
		back -> next = newPtr;

	back = newPtr;
}

/* Delete Item from the queue */
bool Queue::dequeue(){
	if(isEmpty()){
		return false;
	}
	queueNode *tempPtr = front;
	if (front == back){
	front = NULL;
	back = NULL;
	}
	else
	{
		front = front -> next;
		tempPtr -> next = NULL;
		delete tempPtr;
		return true;
	}

}
/* Delete Item from the queue*/
bool Queue::dequeue(QueueType& queueFirst){
	if (isEmpty())
	{
		return false;
	}
	queueFirst = front -> item;
	dequeue();
	return true;
}
/* Gets the first item of the queue */
bool Queue::first(QueueType& queueFirst){
	if(isEmpty())
	{
		return false;
	}

	queueFirst = front -> item;
	return true;
}

#endif
