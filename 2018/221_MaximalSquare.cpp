#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


// 记住这种解法
// https://www.cnblogs.com/grandyang/p/4550604.html
// dp[i][j]表示以matrix[i][j]为右下角的最大matrix的边长

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	const int rows = matrix.size();
    	if(rows==0){return 0;}
    	const int cols = matrix[0].size();
    	vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
    	// 第一列
    	for(int r=1; r<=rows; r++){
    		dp[r][1] = (matrix[r-1][0]=='1' ? 1 : 0);
    	}
    	// 第一行
    	for(int c=1; c<=cols; c++){
    		dp[1][c] = (matrix[0][c-1]=='1' ? 1 : 0);
    	}
    	// 开始dp过程 看 左/左上/上 三个方向
    	// 并在遍历的过程中更新最大值
    	int ret = 0;
    	for(int r=1; r<=rows; r++){
    		for(int c=1; c<=cols; c++){
    			if(matrix[r-1][c-1]=='1'){
    				dp[r][c] = min(dp[r][c-1], min(dp[r-1][c-1], dp[r-1][c]))+1;
    				ret = max(ret, dp[r][c]);
    			}
    		}
    	}
    	return ret*ret;
    }
};