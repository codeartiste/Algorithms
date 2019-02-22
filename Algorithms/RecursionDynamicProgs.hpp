//
//  RecursionDynamicProgs.hpp
//  Algorithms
//
//  Created by Sandip Pal on 8/29/18.
//  Copyright © 2018 Sandip Pal. All rights reserved.
//

#ifndef RecursionDynamicProgs_hpp
#define RecursionDynamicProgs_hpp

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
class RecurDynamicProg{
    
	int getNumWaystoSplitNCents(int amount, int denom[], int index, int numDenoms);
	int **map;
public:
	RecurDynamicProg();
    int getChildNumWaysToClimb(int steps, int []);
    int getNumWaystoSplit(int amount);
    int CalcWaystoWriteBrackets(int left, int right, char *bracSt, int len, vector<string> str);
    int CalcWaystoWriteSumofPerfectSquares(int num);

};



#endif /* RecursionDynamicProgs_hpp */
