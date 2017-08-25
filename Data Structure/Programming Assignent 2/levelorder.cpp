/******************
//Alan Tsai
//CS260
//levelorder
//Used www.youtube.com/mycodeschool as a reference
************************/

#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

/*Function to print Nodes in a binary tree in Level order*/
void LevelOrder(Node *root) {
	if(root == NULL) return;
	queue<Node*> Q;
	Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty()) {
		Node* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}
/*Function to Insert Node in a Binary Search Tree*/
Node* Insert(Node *root,int data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) root->left = Insert(root->left,data);
	else root->right = Insert(root->right,data);
	return root;
}

int main() {
	Node* root = NULL;
	root = Insert(root,10); root = Insert(root,21); //Test cases for the tree
	root = Insert(root,3); root = Insert(root,33); 
	root = Insert(root,5); root = Insert(root,8);
	//Print Nodes in Level Order. 
 	cout << "The nodes of the tree listed in level-order is: " << endl;	
	LevelOrder(root);
	cout << endl;
}

