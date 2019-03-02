/*
 * StackAlgorithm.cpp
 *
 *  Created on: Nov 26, 2018
 *      Author: sandip.pal
 */

#include "StackAlgorithm.h"
#include <set>
#include <queue>
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


/*
 Though this will not be a stack algorithm though
 It will be a BFS 
 */
void StackAlgorithm::RemoveInvalidParenthesis(string str){
    if(str.empty())
        return ;
    //Keep the visited list of strings
    set <string> visited;
    
    //queue for BFS
    queue <string> q;
    // to determine level of BFS
    bool level = false;
    string temp;
    
    //initiall push the entire string to q
    
    q.push(str);
    visited.insert(str);
    
    while(!q.empty()){
        str = q.front();
        q.pop();
        if(isValidString(str)){
            
            cout << "Valid string now " << str  << endl;
            
            level = true;
            
        }
        
        if (level) continue;  // continue the while
        
        for(int i = 0 ; i < str.length() ; i++ ){
            
            if( !isParenthesis(str[i])){
                continue;
            }
            
            
            temp = str.substr(0, i ) + str.substr(i+1) ;
            if(visited.find(temp) == visited.end()){
                q.push(temp);
                visited.insert(temp);
                
            }
            
            
        }
        
        
        
        
    }
    
    
    
}

bool StackAlgorithm::isValidString(string str){
    
    int cnt = 0;
    for( int i = 0 ; i < str.length(); i++){
        if(str[i] == '(')
            cnt++;
        if(str[i] == ')')
            cnt--;
        if (cnt < 0 )
            return false;
        
    }
    
    return (cnt ==0);
}


bool StackAlgorithm::isParenthesis(char c){
    
    if( c == '(' || c == ')')
        return true;
    
    return false;
}
