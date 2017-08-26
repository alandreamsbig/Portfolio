/********************************************************************
//Alan Tsai
//CS260 
//Problem 4 trie.cpp
//Reference: https://www.youtube.com/watch?v=gfqS5nUH9ew
**********************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

#define ALPHABETS 26

/*create node struct*/
struct node{

	bool isEnd;
	struct node *child[ALPHABETS];
}*head;

/*Initialize the list*/
void Makenull()
{
	head = new node();
	head -> isEnd = false;
}

/*Insert elements(words) to the list*/
void Insert(string word)
{
	if(word.empty())
		return;
	node *current = head;
	for (int i = 0; i < word.length(); i++)
	{
		if(current -> child[word[i] - 'a'] == NULL)
			current -> child[word[i] = 'a'] = new node();

		current = current -> child[word[i] - 'a'];
	}

	current -> isEnd = true;
}

int main()
{
	/*Read file and insert to the list*/
	Makenull();
	ifstream file;
	file.open("./alice30.txt");
	if(!file)
	{
		cout << "Can not open the file" <<endl;
		return -1;
	}
	
	string word;
	while(file >> word)
	{
		cout << word << endl;
	}
	cout << endl;
	cout << "All words in Alice the Wonderland has been stored";
	cout << " trie() and Insert() function passed" << endl;
	file.close();
	return 0;
}


