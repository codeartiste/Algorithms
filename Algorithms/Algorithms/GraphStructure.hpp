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
using namespace std;


class GraphAdjacencyMatrix{
    int m_v; //vertices
    bool **m_alist; // 2 d array to hold adjacency values
    void DFSUtil(int , bool []);
public:
    //Constructor
    GraphAdjacencyMatrix(int vertices);
    int AddEdge( int v, int w);
    void PrintDFS(int v);
    
};

class GraphAdjacencyList{
    int m_v; //vertices
    list <int> m_list ; // array list
    void DFSUtil(int , bool []);
public:
    //Constructor
    GraphAdjacencyList(int vertices);
    int AddEdge( int v, int w);
    void PrintDFS(int v);
    
};

#endif /* GraphStructure_hpp */
