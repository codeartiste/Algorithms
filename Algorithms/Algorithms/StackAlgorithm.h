/*
 * StackAlgorithm.h
 *
 *  Created on: Nov 26, 2018
 *      Author: sandip.pal
 */



#ifndef ALGORITHMS_ALGORITHMS_ALGORITHMS_STACKALGORITHM_H_
#define ALGORITHMS_ALGORITHMS_ALGORITHMS_STACKALGORITHM_H_

#include <string.h>
#include <iostream>
#include <stack>

using namespace std;


class StackAlgorithm {
public:
	StackAlgorithm();
	virtual ~StackAlgorithm();
	bool CheckValidParenthesis(string str );
	string MakeValidParenthesis(string str );

};



#endif /* ALGORITHMS_ALGORITHMS_ALGORITHMS_STACKALGORITHM_H_ */
