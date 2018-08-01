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

// 最长递增子序列
// LIS问题 记住一种DP解法
// http://www.cnblogs.com/grandyang/p/4938187.html

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	// dp[i]表示 '以nums[i]结尾的最长递增子序列长度'
    	vector<int> dp(nums.size(), 1);
    	for(int i=1; i<nums.size(); i++){
    		for(int j=i-1; j>=0; j--){
    			if(nums[i]>nums[j]){
    				dp[i] = max(dp[i], dp[j]+1);
    			}
    		}
    	}
    	// 扫一遍dp数组 获得最大值
    	int ret = 0;
    	for(int i=0; i<dp.size(); i++){
    		ret = max(ret, dp[i]);
    	}
    	return ret;
    }
};