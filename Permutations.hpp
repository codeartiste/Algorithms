/*
 * Permutations.hpp
 *
 *  Created on: Aug 27, 2018
 *      Author: sandip.pal
 */

#ifndef ALGORITHMS_ALGORITHMS_ALGORITHMS_PERMUTATIONS_HPP_
#define ALGORITHMS_ALGORITHMS_ALGORITHMS_PERMUTATIONS_HPP_

#include <string>
#include <iostream>
using namespace std;

class Permutations {

	string m_str;
	void permuteHelper(string s, string choose);
	void swap(char*x, char*y);

public:
	Permutations(string s);
	void doPermuteAndPrint();
	int setString(string s);
	void permute(char *a, int l, int r);

};

#endif /* ALGORITHMS_ALGORITHMS_ALGORITHMS_PERMUTATIONS_HPP_ */
