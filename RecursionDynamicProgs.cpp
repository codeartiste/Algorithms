//
//  RecursionDynamicProgs.cpp
//  Algorithms
//
//  Created by Sandip Pal on 8/29/18.
//  Copyright © 2018 Sandip Pal. All rights reserved.
//

#include "RecursionDynamicProgs.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

RecurDynamicProg::RecurDynamicProg(){

	map = new int *[201];
	for (int i = 0; i < 201; i++) {
		map[i] = new int[4];
		//now initialize the array to 0
		for (int j = 0; j < 4; j++) {

			map[i][j] = 0;

		}
	}


}


int RecurDynamicProg::getChildNumWaysToClimb(int steps, int memo[] ){

    if(steps <= 0){
        return 0;
    }
    if(memo[steps] == -1){
        memo[steps] = (1 + getChildNumWaysToClimb(steps - 1, memo) + getChildNumWaysToClimb(steps - 2, memo) + getChildNumWaysToClimb(steps - 3, memo));
    }
    return memo[steps] ;

}

int RecurDynamicProg::getNumWaystoSplitNCents(int amount, int denom[] ,int index, int numDenoms){


	if(map[amount][index] > 0) return map[amount][index];
	if(index >= numDenoms -1) return 1;
	int denomAmount = denom[index];
	int ways = 0;
	for(int i = 0 ; i * denomAmount <= amount ; i++){
		int amountRemaining = amount - i*denomAmount ;
		ways += getNumWaystoSplitNCents(amountRemaining, denom, index + 1, numDenoms);
	}

	map[amount][index]= ways;
	return ways;
}

int RecurDynamicProg::getNumWaystoSplit(int amount){

	int denom[]={25, 10, 5, 1};
	int ways = getNumWaystoSplitNCents(amount, denom , 0, 4);
	return ways;

}

int RecurDynamicProg::CalcWaystoWriteBrackets(int left, int right, char *bracSt, int len, vector<string> &str){
    //base cases
    if(left < 0 || right < left) return 0;
    if ((left == 0)  && (right == 0)) {
        
        bracSt[len] = 0;
        string st1 = bracSt;
        str.push_back(st1);
        //cout << st1 << endl;
        return 1;
        
    }
    int ways = 0;
    // recursion
    bracSt[len] = '(' ;
    ways += CalcWaystoWriteBrackets(left -1, right, bracSt, len +1, str);
    bracSt[len] = ')' ;
    ways += CalcWaystoWriteBrackets(left, right -1, bracSt, len +1, str);
    
    
    return ways;
}


int RecurDynamicProg::CalcWaystoWriteSumofPerfectSquares(int num){

	int numWays[128];

	for (int i = 0 ; i < 128; i++){
		numWays[i] = 99999;
	}
	numWays[0] = 0;

	for(int i = 1 ; i <= num ; i++){

		for(int j = 1 ; j*j <= i ; j++){

			numWays[i] = min(numWays[i], numWays[i-j*j] + 1);
		}

	}

	for (int i = 0 ; i <= num; i++){
			cout << "i = "  << i  << " Numways = "<< numWays[i] << endl ;
	}
	return numWays[num];

}


int RecurDynamicProg::CalculateCoinDenom(vector<int> & coins, int amount){
    
        if (amount == 0) return 0;
        vector <int> need ( amount + 1 , amount + 1);
        need[0] = 0;
        for(int c: coins){
            for(int i = c ; i <= amount; i ++){
                need[i] = min(need[i] , need[i - c] + 1 );
                
            }
            
        }
    
        return (need.back() > amount ) ? -1 : need.back() ; // thus all of them were initialized to amount + 1
    
}

int RecurDynamicProg::MyMax( vector<int> & seq, vector<int> & longNum, int j){
    
    int mx = 0;
    for(int i = 0 ; i <  j ; i++){
        if(seq[j] > seq[i] ){
            mx = (mx > longNum[i] )? mx : longNum[i];
        }
        
    }
    return mx;
}


int RecurDynamicProg::LenLISubSequence(vector<int> seq){
    int max = -1;
    vector <int> longNum(seq.size(), 0) ;
    for(int i = 0 ; i < seq.size() ; i++ ){
        
        longNum[i] = 1 + MyMax(seq, longNum, i);
        if( max < longNum[i]) max = longNum[i];
    }
    
    
    return max;
}
