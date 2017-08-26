//Alan Tsai
//CS260
//Post stack
/* Used as reference https://github.com/anurabashya/69d0818b9ef1f*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

/*Create a stack class*/
class Stack
{
	int top;
	char arr[20];

	public:
	Stack()
	{
		top = -1;
	}
	void push(char ch);
	char pop();
	char topstack();
};
/*Add ch to the stack */
	void Stack::push(char ch)
	{
		if(top == 19)
		{
			cout << "Stack is full" << endl;
		}
		else
		{
			arr[++top] = ch;
		}
	}
/*Delete the stack */
	char Stack::pop()
	{
		char ch;
		if (top < 0)
		{
			cout << "Stack is empty" << endl;
		}
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

/*check the operators*/
int isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch =='*' || ch== '/' || ch=='^' || ch =='$')
		return 1;
	else
		return 0;
}
/*Do the operations */
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
	cout << "Enter a Postfix Expression(Example Input: 98 3 *): ";
	cin >> exp;
	len = strlen(exp);
	j = 0;
	for(i = 0; i < len; i++)
	{
		if (exp[i] >= '0' && exp[i] <= '9')
		{
			s.push(exp[i] - '0');
		}
		else if (isOperator(exp[i]))
		{
			op1 = s.topstack();
			s.pop();
			op2 = s.topstack();
			s.pop();
			s.push(Operation(op1, op2, exp[i]));
		}
	}

	cout << "The Postfix evaluation is: " << (int)s.topstack() << endl;
	return 0;
}


	
