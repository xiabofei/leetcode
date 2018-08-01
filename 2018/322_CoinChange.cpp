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


// 这类问题 dp过程迭代目标变量amount本身
// dp解法 dp[i]定义为凑齐amount==i需要最少的coins个数
// 外层对amount迭代 内层对coins迭代

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	vector<int> dp(amount+1, INT_MAX);
    	dp[0] = 0;
    	for(int i=1; i<=amount; i++){
    		for(int j=0; j<coins.size(); j++){
    			// 这里判断 coins[j]一定要小于i
    			// 因为每轮迭代amount的上限是i
    			if(coins[j]<=i && dp[i-coins[j]]!=INT_MAX){
    				dp[i] = min(dp[i], dp[i-coins[j]]+1);
    			}
    		}
    	}
    	if(dp[amount]==INT_MAX){
    		return -1;
    	}
    	return dp[amount];
    }
};