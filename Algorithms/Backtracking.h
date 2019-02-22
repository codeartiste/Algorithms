/*
 * Backtracking.h
 *
 *  Created on: Nov 20, 2018
 *      Author: sandip.pal
 */

#ifndef ALGORITHMS_ALGORITHMS_ALGORITHMS_BACKTRACKING_H_
#define ALGORITHMS_ALGORITHMS_ALGORITHMS_BACKTRACKING_H_

using namespace std;
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

class Backtracking {
public:
	Backtracking();
	virtual ~Backtracking();
	vector <vector <int>> solveCombinationSum(vector <int> arr, int target);
	void findNumbers(vector <int> arr, int target, vector<vector<int>> &res, vector<int> list, int i);

};

#endif /* ALGORITHMS_ALGORITHMS_ALGORITHMS_BACKTRACKING_H_ */
