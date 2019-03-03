//
//  PriorityQueue.hpp
//  Algorithms
//
//  Created by Sandip Pal on 3/2/19.
//  Copyright © 2019 Sandip Pal. All rights reserved.
//

#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp

#include <vector>
using namespace std ;

/*
 
 Thsi is a Priority Queue implementation from scratch
 
 it will use binary heap / sorted arraylist or binary search tree
 
 */


class PriorityQueue{
    void SwAp(int &x , int &y);
    vector<int> heap;
public:
    // type 0 = binary heap  : 1=sorted ArrayList  : 2 = binary search tree
    PriorityQueue(int type);
    bool insert(int x);
    int  findMinimum();
    bool deleteMinimum();
    void print();
    
    
    
};


#endif /* PriorityQueue_hpp */
