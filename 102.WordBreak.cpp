#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, set<string>& wordDict)
    {
    	bool dp[s.size()+1];
    	fill_n(&dp[0], s.size()+1, false);
    	dp[0] = true;
    	for ( int i=1; i<=s.size(); ++i )
    	{
    		if ( wordDict.find(s.substr(0,i))!=wordDict.end() )
    		{
    			dp[i] = true;
    		}
    		else
    		{
    			for ( int k=1; k<i; ++k )
    			{
    				if ( dp[k] && wordDict.find(s.substr(k, i-k))!=wordDict.end() )
    				{
    					dp[i] = true;
    					break;
    				}
    			}
    		}
    	}
    	return dp[s.size()];
    }
};