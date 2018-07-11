#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	int rows = obstacleGrid.size();
    	int cols = obstacleGrid[0].size();
    	int dp[rows][cols];
    	fill_n(&dp[0][0], rows*cols, 0);
    	// most-left-col and most-top-row 初始化
    	dp[0][0] = obstacleGrid[0][0]==0 ? 1: 0;
    	for(int r=1; r<rows; r++){
    		dp[r][0]= (obstacleGrid[r][0]==0 && dp[r-1][0]==1) ? 1 : 0;
    	}
    	for(int c=1; c<cols; c++){
    		dp[0][c]= (obstacleGrid[0][c]==0 && dp[0][c-1]==1) ? 1 : 0;
    	}
    	// dp过程
    	for(int r=1; r<rows; r++){
    		for(int c=1; c<cols; c++){
    			dp[r][c] = obstacleGrid[r][c]==0 ? dp[r-1][c] + dp[r][c-1] : 0;
    		}
    	}
    	return dp[rows-1][cols-1];
    }
};