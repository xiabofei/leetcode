#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// word1 → word2 转化

class Solution {
public:
    int minDistance(string word1, string word2) {
    	int len1 = word1.size();
    	int len2 = word2.size();

    	int dp[len1+1][len2+1];
    	fill_n(&dp[0][0], (len1+1)*(len2+1), 0);

    	// dp初始化
    	dp[0][0] = 0;
    	// 只有delete操作
    	for(int w1=1; w1<=len1; w1++){dp[w1][0] = w1;}
    	// 只有insert操作
    	for(int w2=1; w2<=len2; w2++){dp[0][w2] = w2;}

    	// 走dp过程
    	for(int w1=1; w1<=len1; w1++){
    		for(int w2=1; w2<=len2; w2++){
    			int opt1 = dp[w1-1][w2-1]+1; // w1 w2都退一个
    			if(word1[w1-1]==word2[w2-1]){opt1--;}
    			int opt2 = dp[w1-1][w2]+1; // w1退一个 本轮执行delete操作
    			int opt3 = dp[w1][w2-1]+1; // w2退一个 本轮执行一个insert操作
    			dp[w1][w2] = min(opt1, min(opt2, opt3));
    		}
    	}
    	return dp[len1][len2];
    }
};