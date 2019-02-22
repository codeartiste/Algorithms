/*
 * BinarySearch.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: sandip.pal
 */

#include "BinarySearch.h"

using namespace std;
#include <vector>
    
BinarySearch::BinarySearch() {
	// TODO Auto-generated constructor stub

}

BinarySearch::~BinarySearch() {
	// TODO Auto-generated destructor stub
}

int  BinarySearch::doBinaryRotatedSearch(vector<int> arr, int target){

	int low  = 0;
	int high = arr.size() - 1;
	int pivot = 0;

	int mid ;
	while(low <= high){
		mid = (low + high)/2;
		// is mid + 1 pivot?
		if ( arr[mid] > arr[mid + 1]){
			break;
		}

		//if arr[low] < = arr[mid] it means low to mid all elements are sorted
		// so look at mid + 1  and high
		if(arr[low] <= arr[mid]){
			low = mid + 1 ;
		}
		else{
			high = mid -1;
		}

	}

	pivot = mid + 1;
	cout << "Pivot element index = " << pivot << endl ;
	cout << "Pivot element = " << arr[pivot] << endl ;
	// mid + 1 is our Pivot
	// now do the binary search based on the proper half

	low = 0 ;
	high = arr.size() - 1 ;

	if(target >= arr[low]){
		high = mid;
		low = 0;
	}
	if(target >= arr[pivot]){
		low =  pivot;
		high = arr.size() -1 ;
	}

	while(low <= high){
		mid = (low + high)/2;
		if(target == arr[mid]) {
			cout << "Target found at index :" << mid << endl;
			return mid;
		}
		if(target > arr[mid]){
			low = mid + 1;
		}
		else{
			high = mid ;
		}
	}
	cout <<"target found at = " << mid << endl;
	return arr[mid + 1];


}

