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
    int minimumTotal(vector<vector<int>>& triangle) {
    	int len = triangle.size();
    	int dp[len+1];
    	fill_n(&dp[0], len+1, INT_MAX);
    	// dp初始化
    	dp[1] = triangle[0][0];
    	// dp迭代
    	for(int r=1; r<triangle.size(); r++){
    		// 一维滚动dp迭代 注意不要覆盖
    		// 本轮的c  依赖于  上轮的c和上轮的c-1
    		// 因此需要从后向前遍历 先更新本轮的c 再更新上轮的c-1
    		for(int c=triangle[r].size(); c>=1; c--){
    			dp[c] = triangle[r][c-1] + min(dp[c-1], dp[c]);
    		}
    	}
    	// 找到最小值
    	int ret = INT_MAX;
    	for(int i=1; i<=len; i++){ret = min(ret, dp[i]);}
    	return ret;
    }
};
