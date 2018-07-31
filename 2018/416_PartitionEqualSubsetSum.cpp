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


// http://www.cnblogs.com/grandyang/p/5951422.html
// dfs过不了大集合 指数时间复杂度
// 用下面的dp方法去扫描
// 由于target = sum / 2 因此时间复杂度得到有效控制

class Solution {
public:
    bool canPartition(vector<int>& nums) {
    	if(nums.size()<=1){return false;}
    	int sum = 0;
    	for(int i=0; i<nums.size(); i++){sum += nums[i];}
    	if(sum&1){return false;}
    	int target = sum / 2;
    	// dp[i]表示 [数值i] 是否是原数组任意子集的和
    	vector<bool> dp(target+1, false);
    	dp[0] = true;
    	for(int i=0; i<nums.size(); i++){
    		// 由于nums中都是正数 所有nums一定要小于等于target才有可能产生满足条件的解
    		for(int j=target; j>=nums[i]; j--){
    			// 如果 j-nums[i] 已经可以由子数组形成
    			// 则再加上nums[i] 就可以满足条件了
    			dp[j] = dp[j] || dp[j-nums[i]];
    		}
    	}
    	return dp[target];
    }
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {1, 5, 11, 5};
	Solution().canPartition(dat);
	return 0;
}