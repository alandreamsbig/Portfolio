/***************************
//Alan Tsai
//CS260
//Traversal Convert
//Used www.youtube.com/ mycodeshool as a reference
********************************/

#include<iostream>
using namespace std;
 
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

/*Function to visit nodes in Preorder*/
void Preorder(struct Node *root) {
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if(root == NULL) return;

	cout << root->data <<endl; // Print data
	Preorder(root->left);     // Visit left subtree
	Preorder(root->right);    // Visit right subtree
}

/*Function to visit nodes in Inorder*/
void Inorder(Node *root) {
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	cout << root->data << endl;  //Print data
	Inorder(root->right);      // Visit right subtree
}

/*Function to visit nodes in Postorder*/
void Postorder(Node *root) {
	if(root == NULL) return;

	Postorder(root->left);    // Visit left subtree
	Postorder(root->right);   // Visit right subtree
	cout << root->data << endl; // Print data
}

/*Function to Insert Node in a Binary Search Tree*/
Node* Insert(Node *root,int data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
 
int main() {
	Node* root = NULL;
	root = Insert(root,11); root = Insert(root,8);
	root = Insert(root,54); root = Insert(root,36); 
	root = Insert(root,7); root = Insert(root,95);
	//Print Nodes in Preorder. 
	cout<<"Preorder: " <<endl;
	Preorder(root);
	cout<<"\n";
	//Print Nodes in Inorder
	cout<<"Inorder: "<< endl;
	Inorder(root);
	cout<<"\n";
	//Print Nodes in Postorder
	cout<<"Postorder: "<< endl;
	Postorder(root);
	cout<<"\n";
}
