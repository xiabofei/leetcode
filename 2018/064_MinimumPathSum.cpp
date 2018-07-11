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
    int minPathSum(vector<vector<int>>& grid) {
    	int rows = grid.size();
    	int cols = grid[0].size();
    	int dp[rows][cols];
    	fill_n(&dp[0][0], rows*cols, 0);
    	// dp初始化
    	dp[0][0] = grid[0][0];
    	for(int r=1; r<rows; r++){dp[r][0] = dp[r-1][0] + grid[r][0];}
    	for(int c=1; c<cols; c++){dp[0][c] = dp[0][c-1] + grid[0][c];}
    	// dp迭代 
    	int ret = dp[0][0];
    	for(int r=1; r<rows; r++){
    		for(int c=1; c<cols; c++){
    			dp[r][c] = grid[r][c] + min(dp[r-1][c], dp[r][c-1]);
    		}
    	}
    	return dp[rows-1][cols-1];
    }
};