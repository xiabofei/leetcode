#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    	if(cost.size()==0){return 0;}
    	if(cost.size()==1){return cost[0];}
    	if(cost.size()==2){return min(cost[0], cost[1]);}
    	const int len = cost.size();
    	vector<int> dp(len, 0);
    	dp[0] = cost[0];
    	dp[1] = cost[1];
    	for(int i=2; i<len-1; i++){
    		// 标准dp公式
    		dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    	}
    	// 最后边界条件特殊处理一把
    	dp[len-1] = min(dp[len-2], dp[len-3]+cost[len-1]);
    	return dp[len-1];
    }
};