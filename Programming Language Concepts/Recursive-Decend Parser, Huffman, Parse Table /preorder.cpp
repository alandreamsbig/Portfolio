//Alan Tsai
//CS260
//Preorder
/*Used as reference https://gist.github.com/anuraagbaishya/3ee69d0818b9ef1fdd79*/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int top;
char arr[20];
/* Create a stack class */
class Stack
{
	
	public:
	Stack()
	{
		top = -1;
	}
	void push(char ch);
	char pop();
	char topstack();
};
/*add ch to the stack */
void Stack::push(char ch)
{
	if(top > 19)
	{
		cout << "Stack is full" << endl;
	}
	else
	{
		arr[++top] = ch;
	}
}
/*Delete stack*/
char Stack::pop()
{
	char ch;
	if (top < 0)
		cout << "Stack is empty" << endl;
	else
	{
		ch = arr[top--];
	}
	return ch;
}

char Stack::topstack()
{
	return arr[top];
}
/*algorithm operations*/
int isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch =='*' || ch== '/' || ch=='^' || ch =='$')
		return 1;
	else
		return 0;
}
/*Input operations*/
int Operation(int op1, int op2, char op)
{
	int ans;
	if (op == '+')
	{
		ans = op2 + op1;
	}
	else if( op == '-')
	{
		ans = op2 - op1;
	}
	else if( op == '*')
	{
		ans = op2 * op1;
	}
	else if (op == '/')
	{
		ans = op2/op1;
	}
	else
	{
		ans = pow(op2, op1);
	}
	return ans;
}

int main()
{
	char exp[256];
	int i, op1, op2, len , j, x;
	Stack s;
	cout << "Enter a Prefix Expression(Example Input 83 5 *): ";
	cin >> exp;
	int k = 0;
	char str1[80];

	for(int i = strlen(exp)-1; i >= 0; i--)
	{
		str1[k++] = exp[i];
	}

	str1[k] = '\0';
	len = strlen(exp);
	j = 0;
	for(i = 0; i < len; i++)
	{
		if(str1[i] >= '0' && str1[i] <= '9')
		{
			s.push(str1[i] - '0');
		}
		else if (isOperator(str1[i]))
		{
			op1 = s.topstack();
			s.pop();
			op2 = s.topstack();
			s.pop();
			s.push(Operation(op2,op1,str1[i]));
		}

	}

	cout << "The Prefix expression is: " << (int)s.topstack() << endl;
	return 0;
}

