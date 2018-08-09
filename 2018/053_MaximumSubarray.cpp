#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// dp的解法
//      dp[i]表示子数组包含nums[i]的最大值
//      最终max subarray一定是dp[i]中的一个
// 简化实现
//      由于dp[i]只与dp[i-1]有关 所以只需要维护一个local变量记录dp[i-1]即可
// 具体实现在下面

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int local = INT_MIN;
    	int global = INT_MIN;
    	for(int i=0; i<nums.size(); i++){
    		local = local>0 ? local+nums[i] : nums[i];
    		global = max(global, local);
    	}
    	return global;
        /*
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        int ret = dp[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = (dp[i-1]>0 ? nums[i]+dp[i-1] : nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
        */
    }
};