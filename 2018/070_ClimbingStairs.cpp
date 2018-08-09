#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 用第二种写法 可以节省空间 只保存最近的两个状态就可以了

class Solution {
public:
    int climbStairs(int n) {
        /*
    	vector<int> dp(n+1, 1);
    	dp[0] = 1;
    	dp[1] = 1;
    	dp[2] = 2;
    	for(int i=3; i<=n; i++){
    		dp[i] = dp[i-1] + dp[i-2];
    	}
    	return dp[n];
        */
        if(n<=1){return 1;}
        if(n==2){return 2;}
        int prepre_ways = 1;
        int pre_ways = 2;
        int ret = 0;
        for(int i=3; i<=n; i++){
            ret = prepre_ways + pre_ways;
            prepre_ways = pre_ways;
            pre_ways = ret;
        }
        return ret;
    }
};