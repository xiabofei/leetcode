#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// dp[i][j] 表示s[0:i-1]与t[0:j-1]需要的最小的匹配次数
// dp[i][j] 的状态转移通过分类讨论'是否需要s[i-1]'匹配
// 如果不用s[i-1]上一轮dp[i-1][j]匹配上
// 如果想用s[i-1]则必须保证s[i-1]与t[j-1]相等

class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size()<t.size()){return 0;}
        const int len_s = s.size();
        const int len_t = t.size();
        vector<vector<int>> dp(len_s+1, vector<int>(len_t+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<=len_s; i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<=len_s; i++){
            for(int j=1; j<=min(i,len_t); j++){
                // 不用s[i-1]
                dp[i][j] += dp[i-1][j];
                // 用s[i-1]
                if(s[i-1]==t[j-1]){
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[len_s][len_t];
    }
};