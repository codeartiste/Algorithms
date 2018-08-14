//
//  main.cpp
//  GraphAlgo
//
//  Created by Sandip Pal on 8/11/18.
//  Copyright © 2018 Sandip Pal. All rights reserved.
//

#include <iostream>
#include "GraphStructure.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Algorithms!\n";
    GraphAdjacency *pAdj = new GraphAdjacency(5);
    pAdj->AddEdge(0, 1);
    pAdj->AddEdge(1, 2);
    pAdj->AddEdge(1, 3);
    pAdj->AddEdge(2, 4);
    pAdj->AddEdge(0, 4);


    return 0;
}
