//
//  SortingAlgorithms.cpp
//  Algorithms
//
//  Created by Sandip Pal on 9/3/18.
//  Copyright © 2018 Sandip Pal. All rights reserved.
//

#include "SortingAlgorithms.hpp"


void SortAlgorithms::domyQsort(int arr[], int left, int right){
    int index;
    
    if((right- left)  > 0){
        index = partition(arr, left, right);
        domyQsort(arr, left, index -1 );
        domyQsort(arr, index+1, right );
    }
}


int SortAlgorithms::partition(int arr[], int left, int right){
    int pivot = (left + right)/2 ;
    
    int pivElement = arr[pivot];
    while(left < right){
        
        while(arr[left] < pivElement) {
            left++;
        }
        while(arr[right] > pivElement ){
            right --;
        }
        if(left < right)
            SWAP(arr, left, right);
    }
    arr[left] = arr[right];
    arr[right] = pivElement ;
    return right;
}
void SortAlgorithms::SWAP(int arr[], int i , int j){
    
    int temp = arr[i];
    arr[i]  = arr[j];
    arr[j]  = temp;
    
}


int SortAlgorithms::partition2(int arr[], int left, int right){
    
    int pivot  = (left + right)/2 ;
    int pivElement = arr[pivot];
    
    
    
    
    return left;
}

void SortAlgorithms::myQsort(int arr[], int len){
    
    domyQsort(arr, 0, len - 1 );
    
}

void SortAlgorithms::myMergeSort(int arr[], int len){
    
    int *temp = new int[len];
    domyMergeSort(arr, temp, 0, len -1);
    
    
}

void SortAlgorithms::domyMergeSort(int arr[], int temp[] ,int leftStart, int rightEnd){
    
    // terminating condition
    if(leftStart >= rightEnd)  return;
    int middle =  (leftStart + rightEnd)/2 ;
    
    
    domyMergeSort(arr, temp, leftStart, middle);
    domyMergeSort(arr, temp, middle + 1, rightEnd);
    doMergeHalves(arr, temp, leftStart, rightEnd);
    
    
    
}

void SortAlgorithms::doMergeHalves(int arr[], int temp[], int leftStart, int rightEnd){
    
    
    int left     = leftStart;
    int leftEnd  = (leftStart + rightEnd) /2;
    int rightStart = leftEnd + 1 ;
    int size = rightEnd - leftStart + 1 ;
    
    int right    = rightStart;
    int index    = 0;
    
    while(left <= leftEnd && right <= rightEnd){
        if(arr[left] < arr[right]){
            temp[index] = arr[left];
            left ++;
        }
        else{
            temp[index] = arr[right];
            right++;
        }
        index++;
        
    }
    // now copy the rest over
    for (int i = left ; i <= leftEnd ; i++){
        temp[index] = arr[i];
        index ++ ;
    }
    for (int j = right ; j <= rightEnd ; j++){
        temp[index] = arr[j];
        index ++ ;
    }
    // now copy the temp back to arr into the correct position
    for (int i = 0 ; i < index ; i++){
        arr[leftStart + i] = temp[i];
    }
    
}




