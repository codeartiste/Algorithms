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

class GraphAdjacency{
    int m_v; //vertices
    bool **m_alist; // 2 d array to hold adjacency values
public:
    //Constructor
    GraphAdjacency(int vertices);
    int AddEdge( int v, int w);
    
};


#endif /* GraphStructure_hpp */
