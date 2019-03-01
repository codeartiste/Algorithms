//
//  GraphStructure.hpp
//  GraphAlgo
//
//  Created by Sandip Pal on 8/12/18.
//  Copyright © 2018 Sandip Pal. All rights reserved.
//

#ifndef GraphStructure_hpp
#define GraphStructure_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class GraphAdjacencyMatrix {
	int m_v; //vertices
	bool **m_alist; // 2 d array to hold adjacency values

	void DFSUtil(int, bool[]);
public:
	//Constructor
	GraphAdjacencyMatrix(int vertices);
	int AddEdge(int v, int w);
	void PrintDFS(int v);

};

class Node_G{
public:
	int endVertex;
	int weight;
	Node_G(int ver, int w){
		endVertex = ver;
		weight  = w;
	}

};

class edge{
public:
    int src;
    int dest;
    edge(int s , int d){
        src = s;
        dest = d;
    }
    
};


class GraphAdjacencyList {
	int m_v; //vertices
	list<Node_G> *adjList; // array of lists
    list<edge> edgeList;
	queue<int> m_openque;
	stack<int> m_pathStack;
	bool m_found;
	void DFSUtil(int, bool[]);
public:
	//Constructor
	GraphAdjacencyList(int vertices);
	int  AddEdge(int v, int w, int weight=0);
	void PrintDFS(int v);
	void PrintBFS(int v);
	void SearchPath(int start, int end);
	void DFSSearchPath(int start, int end, bool visited[]);
	void getDijstrasPath(int start, int end);
    int  findV(int parent[], int i);
    void Union(int parent[], int x, int y);
    bool isCyclicUnionFind();


	bool isCyclic();
	bool findDFSCycleUtil(int v, bool visited[], bool recurrStack[]);
	bool isUCyclic();
	bool findUDFSCycleUtil(int v, bool visited[], int parent);

};

class Solution {
public:
    int numIslands(char** grid, int gridRowSize, int gridColSize);
private:
    void DFSMarking(char** grid, int gridRowSize, int gridColSize, int i, int j);
};

#endif /* GraphStructure_hpp */
