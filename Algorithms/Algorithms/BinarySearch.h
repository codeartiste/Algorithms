/*
 * BinarySearch.h
 *
 *  Created on: Nov 28, 2018
 *      Author: sandip.pal
 */

#ifndef ALGORITHMS_ALGORITHMS_ALGORITHMS_BINARYSEARCH_H_
#define ALGORITHMS_ALGORITHMS_ALGORITHMS_BINARYSEARCH_H_

using namespace std;

#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
    
class BinarySearch {
public:
	BinarySearch();
	virtual ~BinarySearch();
	static int doBinaryRotatedSearch(vector<int> arr, int target);
};



#endif /* ALGORITHMS_ALGORITHMS_ALGORITHMS_BINARYSEARCH_H_ */
