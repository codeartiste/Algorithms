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
GraphAdjacencyMatrix::GraphAdjacencyMatrix(int vertices){
    this->m_v = vertices;
    m_alist = new bool *[m_v] ;
    for(int i = 0 ; i < m_v ; i++){
        m_alist[i] = new bool[m_v];
        //now initialize the array to 0
        for(int j = 0 ; j < m_v ; j++){

            m_alist[i][j] = false;
          
        }
    }
    
}

int GraphAdjacencyMatrix::AddEdge( int v, int w){
    if( v > -1 && w > -1 && v < m_v && w < m_v){
        
        m_alist[v][w] = m_alist[w][v] = true;
        return 1;
    }
    return -1 ;
}


void GraphAdjacencyMatrix::PrintDFS(int v){

	// If adjacency is matrix then do this

	bool *visited = new bool [m_v];
	for(int i = 0 ; i < m_v ; i++){
		visited[i] = false;
	}
	DFSUtil(v, visited);

}

void GraphAdjacencyMatrix::DFSUtil(int v, bool visited[]){

	visited[v] = true;
	std::cout <<  v  << "  " ;
	for( int i = 0 ; i < m_v ; i++){
		if (m_alist[v][i] == true){
			if (visited[i] != true)
				DFSUtil(i, visited);
		}
	}
}
