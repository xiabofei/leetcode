#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <math.h>

using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    string minWindow(string s, string t)
    {
    	if (s.size()<t.size()) return "";
    	string ret = s;
    	map<char, int> char_counts;
    	map<char, int> ref;
    	for ( int i=0; i<t.size(); ++i ) 
    	{
    		ref[t[i]]++;
    		char_counts[t[i]]=0;
    	}
    	int start = 0;
    	int match_counts = 0;
    	bool found = false;
    	for ( int i=0; i<s.size(); ++i )
    	{	
    		if ( ref.find(s[i])!=ref.end() )
    		{
    			char_counts[s[i]]++;
    			if (char_counts[s[i]]<=ref[s[i]]) match_counts++;
    		}
    		// find a window
    		if ( match_counts==t.size() )
    		{
    			found = true;
    			// minimum the window
    			int k=start;
    			for ( ; k<=i; ++k )
    			{
    				if( ref.find(s[k])!=ref.end() )
    				{
    					if ( char_counts[s[k]]-1<ref[s[k]] ) 
    					{
    						break;
    					}
    					char_counts[s[k]]--;
    				}
    			}
    			// update window
    			ret = (i-k+1)<ret.size() ? s.substr(k, i-k+1) : ret;
    			// break the window & go on
    			char_counts[s[k]]--;
    			match_counts--;
    			start = k+1; 
    		}
    	}
    	return found ? ret : "";
    }
};