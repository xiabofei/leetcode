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
    int minDistance(string word1, string word2) 
    {
    	const int n1 = word1.size();
    	const int n2 = word2.size();
    	vector<vector<int> > dp(n1+1, vector<int>(n2+1, 0));
    	// initilize
    	dp[0][0] = 0;
    	for ( int i=1; i<=n1; ++i ) dp[i][0] = dp[i-1][0] + 1;
    	for ( int i=1; i<=n2; ++i ) dp[0][i] = dp[0][i-1] + 1;
    	// dp process
    	for ( int i=1; i<=n1; ++i )
    	{
    		for ( int j=1; j<=n2; ++j )
    		{
    			if ( word1[i-1]==word2[j-1] )
    			{
    				dp[i][j] = dp[i-1][j-1];
    			}
    			else
    			{
    				int insert = dp[i-1][j]+1;
    				int dele = dp[i][j-1]+1;
    				int repl = dp[i-1][j-1]+1;
    				dp[i][j] = min(min(insert,dele),repl);
    			}
    		}
    	}
    	return dp[n1][n2];
    }
};