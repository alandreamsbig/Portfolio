//
//  listsofchildren.h
//  CS260 P2
//
//  Created by Alan Tsai on 8/1/16.
//
//

#ifndef listsofchildren_h
#define listsofchildren_h

#include <stdio.h>
#include <iostream>
using namespace std;


struct NodeSpace{
    int label = -9999;
    int child = 0;
};

struct cell
{
    int node = 0;
    int next = 0;
};

class Tree{
  
public:
    Tree();
    ~Tree();
    int leftmostChild(int n, Tree T);
    int root(Tree T);
    int parent(int n, Tree T);
    int rightSibling(int n, Tree T);
    int label(int n, Tree T);
    int create0(int v);
    int create1(int v, int T1);
    int create2(int v, int T1, int T2);
    int create3(int v, int T1, int T2, int T3);
    
private:
    
    int NodeSpace[1001];
    int cellSpace[1001];
};

#endif /* listsofchildren_h */
