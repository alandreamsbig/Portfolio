/************************************************************************
//Alan Tsai
//CS260 Problem 7
//Floyd's algorithm
//Reference: https://blog.cedric.ws/c-floyd-warshall-shortest-distance-explanation-code
*************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

#define INF 99999

int main()
{
	/*Initialize the vector*/
	int vertices = 7;
	vector< vector<int> > A(vertices, vector<int> (vertices, INF));

	for (int i = 0; i < vertices; i++)
	{
		A[i][i] = 0;
		
		/*Test cases from review 2 question 6*/
		A[1][2] = 4;
		A[1][3] = 1;
		A[1][4] = 5;
		A[1][5] = 8;
		A[1][6] = 10;
		A[3][2] = 2;
		A[4][5] = 2;
		A[5][6] = 1;
		
		/*solves the all-pairs shortest path using Floy's algorithm*/
		for (int k = 0; k < vertices; k++)
			for (int i =0; i < vertices; i++)
				for(int j = 0; j < vertices; j++)
					if(A[i][j] > A[i][k] + A[k][j])
						A[i][j] = A[i][k] + A[k][j];
      
		/*Print out the matrix solution*/
		for (int i = 0; i < vertices; i++)
		{
			for(int j = 0; j < vertices; j++)
				cout << A[i][j] << "        ";
			cout << endl;
		}

		return 0;
	}
}
