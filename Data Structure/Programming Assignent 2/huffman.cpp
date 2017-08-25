/*************************
//Alan Tsai
//CS260
//Huffman code 
//Used as a referece http://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding/ 
***************************/

#include <queue>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

/*Huffman tree node*/
struct HeapNode
{
	char data;
	double freq;
	HeapNode *left, *right;

	HeapNode(char data, double freq)
	{
		left = NULL;
		right = NULL;
		this -> data = data;
		this -> freq = freq;
	}
};

/*Compares two heap nodes*/
struct compare
{
	bool operator()(HeapNode* l, HeapNode* r)
	{
		return ((*l).freq > (*r).freq);
	}
};

/*Display the codes from the root of the tree */
void Display(struct HeapNode* root, string str)
{
	if (!root)
	{
		return;
	}
	if (root -> data != '$')
		cout << root -> data << ": " << str << endl;

	string zero = "0";
	string one = "1";
	Display(root -> left, str + zero);
	Display(root -> right, str + one);
}
/*Creates a Huffman tree*/
void Huffman(char data[], double freq[])
{
	struct HeapNode *left;
	struct HeapNode *right;
	struct HeapNode *top;
	//Create a min heap and insert all characters of data[]
	priority_queue<HeapNode*, vector<HeapNode*>, compare> minHeap;
	for (int i = 0; i < 20; ++i)
	{
		minHeap.push(new HeapNode(data[i], freq[i]));

		while (minHeap.size() !=1)
		{
			//Get the two minimum freq items from min heap
			left = minHeap.top();
			minHeap.pop();

			right = minHeap.top();
			minHeap.pop();

			top = new HeapNode('$', left -> freq + right -> freq);
			top -> left = left;
			top -> right = right;
			minHeap.push(top);
		}
	}
	Display(minHeap.top(), "");
}
/*Main function for test cases*/
int main()
{
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	double freq[] = {0.07, 0.09, 0.12, 0.22, 0.23, 0.27};

	Huffman(arr, freq);
	return 0;
}


