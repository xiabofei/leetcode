#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution{
    bool isValid(string s)
    {
    	stack<char> sta;
    	for ( int i=0; i<s.size(); ++i )
    	{
    		if ( s[i]=='{' || s[i]=='(' || s[i]=='[' )
    		{
    			sta.push(s[i]);
    		}
    		else
    		{
    			if ( sta.empty() )
    			{
    				return false;
    			}
    			else if ( s[i]=='}' )
    			{
    				if ( sta.top()!='{' ) return false;
    				sta.pop();
    			}
    			else if ( s[i]==']' )
    			{
    				if ( sta.top()!='[' ) return false;
    				sta.pop(); 
    			}
    			else if ( s[i]==')' )
    			{
    				if ( sta.top()!='(') return false;
    				sta.pop();
    			}
    			else
    			{
    				return false;
    			}
    		}
    	}
    	return sta.empty();
    }
};