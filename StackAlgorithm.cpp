/*
 * StackAlgorithm.cpp
 *
 *  Created on: Nov 26, 2018
 *      Author: sandip.pal
 */

#include "StackAlgorithm.h"

using namespace std;




StackAlgorithm::StackAlgorithm() {


}

StackAlgorithm::~StackAlgorithm() {

}

bool StackAlgorithm::CheckValidParenthesis(string str ){


	stack<char> pstack;

	char c;
	for(int i = 0 ; i < str.size(); i++){

		switch(str[i]){
		case '(':
		case '{':
		case '[':
			pstack.push(str[i]);
			break;
		case ')':
			c = pstack.top();
			if(c == '(') pstack.pop();
			else{
				return false;
			}
			break;
		case '}':
			c = pstack.top();
			if(c == '{') pstack.pop();
			else{
				return false;
			}
			break;
		case ']':
			c = pstack.top();
			if(c == '[') pstack.pop();
			else{
				return false;
			}
			break;

		default:
			//ignore other characters
			break;

		}


	}
	if(pstack.empty()) return true;


	return false;
}


string StackAlgorithm::MakeValidParenthesis(string str ){


	string cstr;
	stack<char> pstack;

	char c = 0;
	for(int i = 0 ; i < str.size(); i++){

		switch(str[i]){
		case '(':
		case '{':
		case '[':
			pstack.push(str[i]);
			cstr += str[i];
			break;
		case ')':
			if(!pstack.empty())
				c = pstack.top();
			if(c == '(' ) {
				//pop from stack as it is valid
				//append the char to the string
				pstack.pop();

			}
			else{
				//correct it
				//no need to push to stack
				//pstack.push('(');
				cstr += '(';

			}
			cstr += str[i];

			break;
		case '}':
			if(!pstack.empty())
				c = pstack.top();
			if(c == '{' ) {
				//pop from stack as it is valid
				//append the char to the string
				pstack.pop();
			}
			else{
				//correct it
				//no need to push to stack
				//pstack.push('{');
				cstr += '{';
			}
			cstr += str[i];
			break;
		case ']':
			if(!pstack.empty())
				c = pstack.top();
			if(c == '[' ) {
				//pop from stack as it is valid
				//append the char to the string
				pstack.pop();
			}
			else{
				//correct it
				//no need to push to stack
				//pstack.push('[');
				cstr += '[';
			}
			cstr += str[i];
			break;

		default:
			//ignore other characters
			break;

		}
		c=' ';

	}
	while(!pstack.empty())
	{
		char w = pstack.top();
		if(w == '(') cstr += ')';
		if(w == '{') cstr += '}';
		if(w == '[') cstr += ']';
		pstack.pop();
	}
	cout << cstr ;
	return cstr ;
}

