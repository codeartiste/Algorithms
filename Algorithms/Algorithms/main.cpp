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
    GraphAdjacencyMatrix *pAdj = new GraphAdjacencyMatrix(13);
    pAdj->AddEdge(0, 1);
    pAdj->AddEdge(1, 2);
    pAdj->AddEdge(2, 3);
    pAdj->AddEdge(2, 5);
    pAdj->AddEdge(5, 6);
    pAdj->AddEdge(5, 7);
    pAdj->AddEdge(3, 4);
    pAdj->AddEdge(3, 7);
    pAdj->AddEdge(7, 12);
    pAdj->AddEdge(7, 11);
    pAdj->AddEdge(7, 8);
    pAdj->AddEdge(8, 9);
    pAdj->AddEdge(9, 10);
    pAdj->AddEdge(8, 11);
    pAdj->AddEdge(11, 12);

    pAdj->PrintDFS(0);
    return 0;
}
