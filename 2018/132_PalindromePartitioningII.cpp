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
    int minCut(string s) {
    	if(s.size()<2){return 0;}
    	int len = s.size();
    	// step1. 获得所有子串是否是回文
    	vector<vector<bool>> P(len, vector<bool>(len, false)); 
    	getPalindromes(P, s);
    	// step2. 走dp并参考step1的结果
    	int dp[len];
    	fill_n(&dp[0], len, 0);
    	for(int i=0; i<len; i++){
    		if(P[0][i]){ // 子串已经是回文
    			dp[i] = 0;
    		}
    		else{ // 子串不是回文 找当前的最小cut
    			int min_cut = INT_MAX;
    			for(int j=i; j>0; j--){
    				// 从i-1开始切 保证至少能找到一次
    				if(P[j][i]){min_cut = min(min_cut, dp[j-1]+1);}
    			}
    			dp[i] = min_cut;
    		}
    	}
    	return dp[len-1];
    }
    void getPalindromes(vector<vector<bool>> &P, string s){
    	// P[j][i] 表示s[j:i]是否是回文
    	for(int i=0; i<s.size(); i++){
    		for(int j=0; j<=i; j++){
    			if(i-j<2){ // 判断回文的套路
    				P[j][i]= s[j]==s[i];
    			}
    			else{
    				P[j][i] = P[j+1][i-1] && s[j]==s[i];
    			}
    		}
    	}
    }
};