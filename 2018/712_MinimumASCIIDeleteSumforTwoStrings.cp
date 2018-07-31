#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 最长公共子串的变向考察
// http://www.cnblogs.com/grandyang/p/7752002.html

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
    	const int len1 = s1.size();
    	const int len2 = s2.size();
    	// dp[i][j]表示 让s1[0:i]与s2[0:j]相等 最少需要delete字母的sum
    	vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
    	// dp初始化
    	for(int i=1; i<=len1; i++){
    		dp[i][0] = dp[i-1][0] + s1[i-1];
    	}
    	for(int i=1; i<=len2; i++){
    		dp[0][i] = dp[0][i-1] + s2[i-1];
    	}
    	// 走dp过程
    	for(int i=1; i<=len1; i++){
    		for(int j=1; j<=len2; j++){
    			if(s1[i-1]==s2[j-1]){
    				dp[i][j] = dp[i-1][j-1];
    			}
    			else{
    				int way1 = dp[i][j-1] + s2[j-1];
    				int way2 = dp[i-1][j] + s1[i-1];
    				dp[i][j] = min(way1, way2);
    			}
    		}
    	}
    	return dp[len1][len2];
    }
};

int main(int argc, char const *argv[])
{
	string s1 = "sea";
	string s2 = "eat";
	Solution().minimumDeleteSum(s1, s2);
	return 0;
}