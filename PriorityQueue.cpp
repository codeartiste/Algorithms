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
        cout << x << "    ";
    cout << endl;
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
    int elem;
    if(heap.size() == 0) return true;
    // get the last element
    elem = heap.back();
    heap.pop_back();
    if(heap.size() == 0) return true;
    
    heap.front() = elem;
    minHeapify(0);
    

    return true;
}

void PriorityQueue::minHeapify(int index){
    if(index >= heap.size()) return;
    int lindex = 2*index + 1 ;
    int rindex = lindex + 1;
    int smallest = index;
    if(lindex < heap.size() && heap[index] > heap[lindex]){
        smallest = lindex;
    }
    if(rindex < heap.size() && heap[smallest] > heap[rindex]){
        smallest = rindex;
    }
    if( smallest != index){
        SwAp(heap[smallest], heap[index]);
        minHeapify(smallest);
    }
    return;
    
}
