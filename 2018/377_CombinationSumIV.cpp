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
    int combinationSum4(vector<int>& nums, int target) {
    	if(nums.size()==0){return 0;}
    	// 定义dp[i]为 '生成sum为i的组合个数'
    	vector<int> dp(target+1, 0);
    	dp[0] = 1;
    	for(int i=1; i<=target; i++){
    		for(int j=0; j<nums.size(); j++){
    			if(i>=nums[j]){
    				dp[i] += dp[i-nums[j]];
    			}
    		}
    	}
    	return dp[target];
    }
};