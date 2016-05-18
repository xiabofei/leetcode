#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle)
    {
    	const int n = triangle.size();
    	vector<int> dp(n, INT_MAX);
    	dp[0] = triangle[0][0];
    	for ( int i=1; i<n; ++i )
    	{
    		for ( int j=triangle[i].size()-1; j>0; --j )
    		{
    			dp[j] = triangle[i][j] + min(dp[j], dp[j-1]);
    		}
    		dp[0] += triangle[i][0];
    	}
    	int ret = dp[0];
    	for ( int i=1; i<n; ++i ) ret = min(ret, dp[i]);
   		return ret;
    }
};