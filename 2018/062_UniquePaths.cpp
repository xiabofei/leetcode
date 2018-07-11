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
    int uniquePaths(int m, int n) {
    	// 用O(m*n) extra space的标准解法
    	int dp[m][n];
    	fill_n(&dp[0][0], m*n, 1);
    	for(int i=1; i<m; i++){
    		for(int j=1; j<n; j++){
    			dp[i][j] = dp[i-1][j] + dp[i][j-1];
    		}
    	}
    	return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
    	// 只用O(n) extra space的trick解法
    	int dp[m];
    	fill_n(&dp[0], m, 1);
    	for(int i=1; i<n; i++){
    		for(int j=1; j<m; j++){
    			dp[j] = dp[j] + dp[j-1];
    		}
    	}
    	return dp[m-1];
    }
};