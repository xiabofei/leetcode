#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 变相考察最长公共子串
// http://www.cnblogs.com/grandyang/p/7144045.html
// 记两种情况
// 1) 当前两个字符相等 则dp[i-1][j-1] + 1
// 2) 当前两个字符不等 则错位比较 max(dp[i][j-1], dp[i-1][j])

class Solution {
public:
    int minDistance(string word1, string word2) {
    	if(word1.size()==0){return word2.size();}
        if(word2.size()==0){return word1.size();}
        const int len1 = word1.size();
        const int len2 = word2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        for(int i = 1; i <= len1; i++){
        	for(int j = 1; j <= len2; j++){
        		if(word1[i-1]==word2[j-1]){
        			dp[i][j] = 1 + dp[i-1][j-1];
        		}
        		else{
        			dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        		}
        	}
        }
        return len1 + len2 - 2*dp[len1][len2];
    }
};