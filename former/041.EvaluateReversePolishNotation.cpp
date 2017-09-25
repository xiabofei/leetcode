#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution{
public:
    int evalRPN(vector<string>& tokens)
    {
    	stack<int> sta;
    	for ( int i=0; i<tokens.size(); ++i )
    	{
    		if ( tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/" )
    		{
    			int b = sta.top(); sta.pop();
    			int a = sta.top(); sta.pop();
    			if ( tokens[i]=="+" ) {sta.push(a+b);continue;}
    			if ( tokens[i]=="-" ) {sta.push(a-b);continue;}
    			if ( tokens[i]=="*" ) {sta.push(a*b);continue;}
    			if ( tokens[i]=="/" ) {sta.push(a/b);continue;} 
    		}
    		else
    		{
    			sta.push(atoi(tokens[i].c_str()));
    		}
    	}
    	return sta.top();
    }
};