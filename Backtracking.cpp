/*
 * Backtracking.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: sandip.pal
 */

#include "Backtracking.h"

using namespace std;


Backtracking::Backtracking() {
	// TODO Auto-generated constructor stub

}

Backtracking::~Backtracking() {
	// TODO Auto-generated destructor stub
}

vector <vector <int>> Backtracking::solveCombinationSum(vector <int> arr, int target){

	//vector to hold the results
	vector <vector <int>> res;
	vector <int> vr;
	findNumbers(arr, target, res, vr, 0);

	return res;
}

void Backtracking::findNumbers(vector <int> arr, int target, vector<vector<int>>& res,
		          vector<int> list, int i){

	// if target < 0 return
	if(target < 0) return;
	if( target == 0){
		res.push_back(list);
		return;
	}

	//now run through the remainder of the list
	while(i < arr.size()  && target - arr[i] >= 0 ){
		list.push_back(arr[i]);
		findNumbers(arr, target - arr[i], res, list, i +1  );
		i++;
		list.pop_back();

	}






}
