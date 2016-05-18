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
    int numDistinct(string s, string t)
    {
    	int dp[s.size()+1][t.size()+1];
    	fill_n(&dp[0][0], (s.size()+1)*(t.size()+1), 0);
    	dp[0][0] = 1;
    	for ( int i=1; i<=s.size(); ++i ) dp[i][0] = 1;
    	// dp process
    	for ( int i=1; i<=s.size(); ++i )
    	{
    		for ( int j=1; j<=t.size(); ++j )
    		{
    			if (s[i-1]==t[j-1])
    			{
    				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    			}
    			else
    			{
    				dp[i][j] = dp[i-1][j];
    			}
    		}
    	}
    	return dp[s.size()][t.size()];
    }
};