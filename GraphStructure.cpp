//
//  GraphStructure.cpp
//  GraphAlgo
//
//  Created by Sandip Pal on 8/12/18.
//  Copyright © 2018 Sandip Pal. All rights reserved.
//

#include "GraphStructure.hpp"

using namespace std;
//constructor
GraphAdjacencyMatrix::GraphAdjacencyMatrix(int vertices) {
	this->m_v = vertices;
	m_alist = new bool *[m_v];
	for (int i = 0; i < m_v; i++) {
		m_alist[i] = new bool[m_v];
		//now initialize the array to 0
		for (int j = 0; j < m_v; j++) {
			m_alist[i][j] = false;

		}
	}

}

int GraphAdjacencyMatrix::AddEdge(int v, int w) {
	if (v > -1 && w > -1 && v < m_v && w < m_v) {

		m_alist[v][w] = m_alist[w][v] = true;
		return 1;
	}
	return -1;
}

void GraphAdjacencyMatrix::PrintDFS(int v) {

	// If adjacency is matrix then do this

	bool *visited = new bool[m_v];
	for (int i = 0; i < m_v; i++) {
		visited[i] = false;
	}
	DFSUtil(v, visited);

}

void GraphAdjacencyMatrix::DFSUtil(int v, bool visited[]) {

	visited[v] = true;
	std::cout << v << "  ";
	for (int i = 0; i < m_v; i++) {
		if (m_alist[v][i] == true) {
			if (visited[i] != true)
				DFSUtil(i, visited);
		}
	}
}

GraphAdjacencyList::GraphAdjacencyList(int vertices) {

	this->m_v = vertices;
	adjList = new list<Node_G > [m_v];
	m_found = false;

}

int GraphAdjacencyList::AddEdge(int v, int w, int weight) {

	//simply push w into v's list
	//simply push v into w's list
	adjList[v].push_back(Node_G(w, weight));
	adjList[w].push_back(Node_G(v, weight));
    edgeList.push_back(edge(v, w));

	return 1;
}

void GraphAdjacencyList::PrintDFS(int v) {

	// If adjacency is matrix then do this
	bool *visited = new bool[m_v];
	for (int i = 0; i < m_v; i++) {
		visited[i] = false;
	}
	DFSUtil(v, visited);
	delete[] visited;
	cout << "\n";

}

void GraphAdjacencyList::DFSUtil(int v, bool visited[]) {

	if(visited[v] == false){
		visited[v] = true;
		std::cout << v << "  ";
		list<Node_G>::iterator i;
		for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
			if (!visited[(*i).endVertex])
				DFSUtil((*i).endVertex,  visited);
	}

}

void GraphAdjacencyList::DFSSearchPath(int start, int end, bool visited[]) {

	if (m_found)
		return;
	visited[start] = true;
	list<Node_G>::iterator i;
	for (i = adjList[start].begin(); i != adjList[start].end(); ++i)
		if (!visited[(*i).endVertex]) {
			//put this in path stack
			m_pathStack.push((*i).endVertex);
			if ((*i).endVertex == end) {
				cout << "Found  destination";
				m_found = true;
				std::cout << '\n';
				std::cout << (*i).endVertex;

			} else {
				DFSSearchPath((*i).endVertex, end, visited);
				if (m_found)
					std::cout << "<--" << (*i).endVertex;
				m_pathStack.pop();
			}
		}
    
}

void GraphAdjacencyList::SearchPath(int start, int end) {

	bool *visited = new bool[m_v];
	for (int i = 0; i < m_v; i++) {
		visited[i] = false;
	}
	m_found = false;
	m_pathStack.push(start);
	DFSSearchPath(start, end, visited);
	if (m_found)
		std::cout << "<--" << start;
	m_pathStack.pop();
	delete[] visited;

}

void GraphAdjacencyList::PrintBFS(int v) {

	bool *visited = new bool[m_v];
	for (int i = 0; i < m_v; i++) {
		visited[i] = false;
	}
	visited[v] = true;
	m_openque.push(v);
	while (!m_openque.empty()) {
		int elem = m_openque.front();
		m_openque.pop();

		std::cout << elem << "  ";

		list<Node_G>::iterator i;
		for (i = adjList[elem].begin(); i != adjList[elem].end(); ++i) {
			if (!visited[(*i).endVertex]) {
				//push an element and mark it visited
				visited[(*i).endVertex] = true;
				m_openque.push((*i).endVertex);
			}
		}

	}
    delete [] visited;

}


int Solution::numIslands(char** grid, int gridRowSize, int gridColSize) {
        int count = 0;
      
        for (int i = 0; i < gridRowSize; i++){
            for (int j = 0; j < gridColSize; j++)
                if (grid[i][j] == '1') {
                    DFSMarking(grid, gridRowSize, gridColSize, i, j);
                    ++count;
                }
        }
        return count;
    
    }
    

void Solution::DFSMarking(char** grid, int gridRowSize, int gridColSize, int i, int j) {
        if (i < 0 || j < 0 || i >= gridRowSize || j >= gridColSize || grid[i][j] != '1') return;
        grid[i][j] = '0';
        DFSMarking(grid, gridRowSize, gridColSize, i + 1, j);
        DFSMarking(grid, gridRowSize, gridColSize,i - 1, j);
        DFSMarking(grid, gridRowSize, gridColSize,i, j + 1);
        DFSMarking(grid, gridRowSize, gridColSize,i, j - 1);
}
    


bool GraphAdjacencyList::isCyclic() {

	// If adjacency is list then do this

	bool *visited = new bool[m_v];
	bool *recurrStack = new bool[m_v];
	for (int i = 0; i < m_v; i++) {
		visited[i] = false;
		recurrStack[i] = false;
	}
	for (int i = 0; i < m_v; i++) {
		if(findDFSCycleUtil(i, visited, recurrStack))
			return true;
	}

	cout << "\n";

	return false;
}

int GraphAdjacencyList::findV(int parent[], int i){
    if(parent[i] == -1)
        return i;
    else
        return parent[i];
    
}

void GraphAdjacencyList::Union(int parent[], int x, int y){
    
    int xset = findV(parent, x);
    int yset = findV(parent, y);
    if(xset != yset){
        if(parent[xset]== -1)
            parent[xset] = yset;
        else
            parent[yset] = xset;
        
    }
    
}

bool GraphAdjacencyList::isCyclicUnionFind() {
    
    int *vertices = new int[m_v];
    int *parent   = new int[m_v];
    for(int i = 0 ; i < m_v ; i++){
        vertices[i] = i;
        parent[i]   = -1;
    }
    
    list<edge>::iterator ed;
    for (ed = edgeList.begin(); ed != edgeList.end(); ++ed) {
    
        int a ,b;
        a = (*ed).src ;
        b = (*ed).dest ;
        if(findV(parent, a) == findV(parent, b)){
            
            cout<< "Cycle Detected" << endl;
            return true;
        }
        else{
            //Union sets X and Y  where src is in X and dest is in Y
            Union(parent, a, b);
        }
    
    
    }
    
    return false;
}

bool GraphAdjacencyList::findDFSCycleUtil(int v, bool visited[], bool recurrStack[]) {

	if(visited[v] == false){
		visited[v] = true;
		recurrStack[v] = true;
		std::cout << v << "  ";
		list<Node_G>::iterator i;
		for (i = adjList[v].begin(); i != adjList[v].end(); ++i){
			if(!visited[(*i).endVertex] && findDFSCycleUtil((*i).endVertex , visited, recurrStack) ){ // not visited and
				return true;
			}
			else if(recurrStack[(*i).endVertex])
				return true;
		}
	}
	recurrStack[v] = false;
	return false;
}

bool GraphAdjacencyList::isUCyclic() {

	// If adjacency is list then do this

	bool *visited = new bool[m_v];
	for (int i = 0; i < m_v; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < m_v; i++) {
		if(!visited[i]){
		   if(findUDFSCycleUtil(i, visited, -1))
			   return true;
		}
	}

	return false;
}

bool GraphAdjacencyList::findUDFSCycleUtil(int v, bool visited[], int parent) {

	if(visited[v] == false){
		visited[v] = true;
		std::cout << v << "\n ";
		list<Node_G>::iterator i;
		for (i = adjList[v].begin(); i != adjList[v].end(); ++i){
			if(!visited[(*i).endVertex]){
				if(findUDFSCycleUtil((*i).endVertex , visited, v) ){ // not visited and
					return true;
				}
			}
			else if ((*i).endVertex != parent){
				cout << "parent = " <<parent<<endl;
				cout << "node = " << v <<endl;
				return true;
			}
		}

	}
	return false;
}


void GraphAdjacencyList::getDijstrasPath(int start, int end){
    
    
    
}




