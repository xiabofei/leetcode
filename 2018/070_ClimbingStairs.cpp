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
    int climbStairs(int n) {
    	vector<int> dp(n+1, 1);
    	dp[0] = 1;
    	dp[1] = 1;
    	dp[2] = 2;
    	for(int i=3; i<=n; i++){
    		dp[i] = dp[i-1] + dp[i-2];
    	}
    	return dp[n];
    }
};