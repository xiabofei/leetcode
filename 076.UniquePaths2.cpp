#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid)
    {
    	const int m = obstacleGrid.size();
    	if (m==0) return 0;
    	const int n = obstacleGrid[0].size();
    	vector<int> dp(n, 0);
    	dp[0] = 1;
    	for ( int i=0; i<m; ++i )
    	{
    		if (obstacleGrid[i][0]==1) dp[0]=0;
    		for ( int j=1; j<n; ++j )
    		{
    			dp[j] = obstacleGrid[i][j]==1 ? 0 : dp[j]+dp[j-1];
    		}
    	}
    	return dp[n-1];
    }
};