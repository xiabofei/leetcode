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
    int rob(vector<int>& nums) {
    	if(nums.size()<1){return 0;}
    	int dp[nums.size()+1];
    	fill_n(&dp[0], nums.size()+1, 0);
    	dp[1] = nums[0];
    	for(int i=2; i<=nums.size(); i++){
    		dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
    	}
    	return dp[nums.size()];
    }
};