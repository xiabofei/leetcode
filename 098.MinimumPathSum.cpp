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
    int minPathSum(vector<vector<int> >& grid)
    {
    	const int m = grid.size();
    	if ( m==0 ) return 0;
    	const int n = grid[0].size();
    	vector<int> dp(n, INT_MAX);
    	dp[0] = 0;
    	for ( int i=0; i<m; ++i )
    	{
    		dp[0] += grid[i][0];
    		for ( int j=1; j<n; ++j )
    			dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
    	}
    	return dp[n-1];
    }
};