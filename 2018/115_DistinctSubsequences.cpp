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
    int numDistinct(string s, string t) {
    	int len_S = s.size();
    	int len_T = t.size();
    	if(len_S<len_T){return 0;}
    	int dp[len_S+1][len_T+1];
    	fill_n(&dp[0][0], (len_S+1)*(len_T+1), 0);
    	// dp初始化
    	dp[0][0] = 1;
    	for(int i=1; i<=len_S; i++){dp[i][0] = 1;}
    	// dp过程
    	for(int ls=1; ls<=len_S; ls++){
    		for(int lt=1; lt<=len_T; lt++){
    			if(ls<lt){continue;}
    			dp[ls][lt] = dp[ls-1][lt];
    			if(s[ls-1]==t[lt-1]){
    				dp[ls][lt] += dp[ls-1][lt-1];
    			}
    		}
    	}
    	return dp[len_S][len_T];
    }
};