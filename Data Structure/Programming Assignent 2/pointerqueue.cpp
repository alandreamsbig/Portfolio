/****************
//Alan Tsai
//CS260 
//Queue Pointer
*******************/

#include <iostream>
#include "pointerqueue.h"

using namespace std;

int main(){
	Queue queue;
	int num;

	cout << "Inserting numbers to the Queue" << endl;
	/*Test cases for enqueue*/
	queue.enqueue(8);
	queue.enqueue(10);
	queue.enqueue(14);
	queue.enqueue(18);
	cout << "enqueue() passed" <<endl;
	/*Testing first*/
	queue.first(num);
	cout << "Front item in queue: " << num << endl;
	cout << "first() passed" << endl;
	/*Testing dequeue*/
	cout << "Remove all items in the queue" << endl;
	while (!queue.isEmpty())
	{
		queue.dequeue(num);
		cout << num << endl;
	}

	cout << "dequeue(), isEmpty() passed" << endl;

	return 0;
}

