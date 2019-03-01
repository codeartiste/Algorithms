//
//  SortingAlgorithms.hpp
//  Algorithms
//
//  Created by Sandip Pal on 9/3/18.
//  Copyright © 2018 Sandip Pal. All rights reserved.
//

#ifndef SortingAlgorithms_hpp
#define SortingAlgorithms_hpp

#include <stdio.h>

class SortAlgorithms{
  
    void domyQsort(int arr[], int left, int right);
    int partition(int arr[], int left, int right);
    int partition2(int arr[], int left, int right);
    void domyMergeSort(int arr[],int temp[], int leftStart, int rightEnd);
    void doMergeHalves(int arr[], int temp[], int leftStart, int rightEnd);
public:
    void myQsort(int arr[], int len);
    void myMergeSort(int arr[], int len);
    void SWAP(int arr[], int i , int j);
    
    
};


#endif /* SortingAlgorithms_hpp */
