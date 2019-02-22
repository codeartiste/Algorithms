//
//  Problems.cpp
//  Algorithms
//
//  Created by Sandip Pal on 9/10/18.
//  Copyright © 2018 Sandip Pal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "ProblemHeaders.hpp"
using namespace std;


    vector<vector<int>> Solution3Sum::threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() <= 2) return result;
        //qsort(nums.begin(), nums.end());
        
        
        for (int i = 0 ; i < nums.size() - 2 ; i++){
            int l = i+1 ;
            int r = nums.size() - 1;
            while( l < r){
                int sum = nums[i] + nums[l] + nums[r] ;
                if(sum == 0){
                    //found triplets
                    result.push_back(vector<int>({nums[i] , nums[l] , nums[r]}));
                    l++;
                    r--;
                }
                else if (sum > 0){
                    r--;
                }
                else{
                    l++ ;
                }
            }
            
        }
        
        
        return result;
        
    }

    double MathProbs::getSqrt(int n , double prec){

    	double guess = n;

    	/*while (abs(n/guess - guess) > prec ){

    		guess = (guess + n/guess)/2.0 ;

         
    	}*/

    	return guess;
    }

