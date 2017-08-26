/***********************************
//Alan Tsai
//CS260
//Depth First Search
//Reference: http://www.geeksforgeeks.org/depth-first-traversal-for
***************************************************************************/
#include<iostream>
#include<stack>
#include<string>

using namespace std;

/*Graph class*/
class Graph
{
public:

	Graph(int size = 2);
	~Graph();
	bool isConnected(int x, int y);
	void addEdge(int x, int y);
	void DisplayMatrix();
	void DFS(int firstNode, int lastNode);

private:
	int count;
	int **array;
};

/*Constructor for graph, create the graphs of the search tree*/
Graph::Graph(int size)
{
	int i,j;
	if(size < 2)
		count = 2;
	else
		count = size;

	array = new int*[count];

	for (i = 0; i < count; ++i)
	{
		array[i] = new int[count];
	}
	for (i = 0; i < count; ++i)
	{
		for (j = 0; j < count; ++j)
		{
			array[i][j] = 0;
		}
	}
}
/*Destructor for graph*/
Graph::~Graph()
{
	for(int i = 0; i < count; ++i)
		delete [] array[i];
	delete [] array;
}

/*Check if the graph is connected */
bool Graph::isConnected(int x, int y)
{
	if (array[x-1][y-1] == 1)
		return true;
	else
		return false;
}

/*Add edge to the graph*/
void Graph::addEdge(int x, int y)
{
	array[x-1][y-1] = array[y-1][x-1] = 1;
}

/*Display the Maxtrix*/
void Graph::DisplayMatrix()
{
	cout << "Adjacency Matrix: " << endl;
	cout << "    ";
	for (int i = 0; i < count; ++i)
		cout << (i+1) << "  ";
	cout << endl;
	for (int i = 0; i < count; ++i)
	{
		cout << (i + 1) << "  ";
		for (int j = 0; j < count; ++j)
		{
			cout << array[i][j] << "  ";
		}
		cout << endl << endl;
	}
}

/*Depth First search function using stack*/
void Graph::DFS(int firstNode, int lastNode)
{
	stack<int> s;

	bool *visited = new bool[count+1];
	
	int i;
	for (i = 0; i <= count; i++)
		visited[i] = false;
	s.push(firstNode);
	visited[firstNode] = true;

	if(firstNode == lastNode)
		return;

	cout << "Depth First Search starting from vertex "; 
	cout << firstNode << " : " << endl;

	while(!s.empty())
	{
		int k = s.top();
		s.pop();
		if ( k == lastNode)
			break;
		cout << k << " ";

		for(i = count; i >= 0; i--)
		{
			if(isConnected(k,i) && !visited[i])
			{
				s.push(i);
				visited[i] = true;
			}
		}
	}
	cout << lastNode << endl;
	delete [] visited;
}


int main()
{
	Graph g(10);
	/*test cases*/
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,6);
	g.addEdge(2,7);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,6);
	g.addEdge(6,7);
	g.addEdge(7,8);
	g.addEdge(8,10);
	g.addEdge(9,10);
	g.DisplayMatrix();
	g.DFS(1,10);
	return 0;
}

