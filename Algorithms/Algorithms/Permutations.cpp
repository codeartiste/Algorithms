/*
 * Permutations.cpp
 *
 *  Created on: Aug 27, 2018
 *      Author: sandip.pal
 */

#include "Permutations.hpp"

Permutations::Permutations(string s) {

	m_str = s;
}

int Permutations::setString(string s) {

	m_str = s;

	return 1; //no error
}

void Permutations::permuteHelper(string s, string chosen) {

	if (s.empty()) {

		cout << chosen << endl;

	} else {
		// choose /explore/ unchoose
		for (int i = 0; i < (int) s.length(); i++) {
			char c = s[i];
			chosen += c;
			s.erase(i, 1);
			permuteHelper(s, chosen);
			s.insert(i, 1, c);
			chosen.erase(chosen.length() - 1, 1);
		}

	}

}

void Permutations::doPermuteAndPrint() {

	permuteHelper(m_str, "");

}

void Permutations::swap(char*x, char*y) {

	char temp;
	temp = *y;
	*y = *x;
	*x = temp;

}
void Permutations::permute(char *a, int l, int r) {

	if (l == r) {
		cout << string(a) << endl;
	} else {
		for (int i = l; i <= r; i++) {
			swap((a + l), (a + i));  //choose
			permute(a, l + 1, r); //do
			swap((a + l), (a + i));  //unchoose or backtrack

		}
	}

}

