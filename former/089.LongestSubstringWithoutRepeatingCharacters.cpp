#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
    	int global = 0;
    	int start = 0;
    	map<char, int> char_pos;
    	for ( int i=0; i<s.size(); ++i )
    	{
    		if ( char_pos.find(s[i])==char_pos.end() || char_pos[s[i]]<start )
    		{
    			char_pos[s[i]] = i;
    			global = max(global, i-start+1);
    		}
    		else
    		{
    			start = char_pos[s[i]]+1;
    			char_pos[s[i]] = i;
    		}
    	}
    	return global;
    }
};