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
    bool isInterleave(string s1, string s2, string s3) {
    	int len1 = s1.size();
    	int len2 = s2.size();
    	int len3 = s3.size();
    	if((len1+len2)!=len3){return false;}
    	bool dp[len1+1][len2+1];
    	fill_n(&dp[0][0], (len1+1)*(len2+1), false);
    	// dp初始化
    	dp[0][0] = true;
    	for(int l=1; l<=len1; l++){dp[l][0] = dp[l-1][0] && s1[l-1] == s3[l-1];}
    	for(int l=1; l<=len2; l++){dp[0][l] = dp[0][l-1] && s2[l-1] == s3[l-1];}
    	// dp迭代
    	for(int l1=1; l1<=len1; l1++){
    		for(int l2=1; l2<=len2; l2++){
    			bool opt1 = dp[l1-1][l2] && s1[l1-1] == s3[l1+l2-1]; 
    			bool opt2 = dp[l1][l2-1] && s2[l2-1] == s3[l1+l2-1];
    			dp[l1][l2] = opt1 || opt2;
    		}
    	}
    	return dp[len1][len2];
    }
};