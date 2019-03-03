//
//  PriorityQueue.cpp
//  Algorithms
//
//  Created by Sandip Pal on 3/2/19.
//  Copyright © 2019 Sandip Pal. All rights reserved.
//

#include "PriorityQueue.hpp"
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

PriorityQueue::PriorityQueue(int type){
    
    //empty for the time being
}

void PriorityQueue::print(){
    for (auto x : heap)
        cout << x << endl;
}

void PriorityQueue::SwAp(int &x , int &y){
    int temp = x;
    x = y;
    y = temp;
}


bool PriorityQueue::insert(int x){
    int parent = 0;
    int pos = 0;
    heap.push_back(x);
    pos = (int)(heap.size() -1 );
    
    
    while(pos!=0 && parent >= 0){
        if(pos %2 == 0) parent = (pos-2 )/2 ;
        else parent = (pos -1 )/2 ;
        if(heap[parent] > heap[pos]){
            SwAp(heap[parent], heap[pos]);
            pos = parent;
        }
        else {
            break;
        }
    }
    
    return true;
}



int  PriorityQueue::findMinimum(){
    
    return heap.front();
}


bool PriorityQueue::deleteMinimum(){
    
    if(heap.size() == 0) return true;
    // get the last element
    int elem;
    elem = heap.back();
    heap.erase(heap.end());
    if(heap.size() == 0) return true;
    int pos = 0;
    int child = 0;
    while( child < heap.size()){
        
    }
    
    
    
    
    return true;;
}
