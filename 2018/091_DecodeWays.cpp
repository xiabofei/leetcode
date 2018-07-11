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
    int numDecodings(string s) {
    	if(s[0]=='0'){return 0;}
    	int len = s.size();
    	if(len==1){return 1;}

    	vector<int> dp(len, 1);
    	// 给dp初始条件
    	if(s[1]-'0'==0){
    		if((s[0]-'0')*10+(s[1]-'0')>26){
    			return 0;
    		}
    		dp[1] = 1;
    	}
    	else{
    		if((s[0]-'0')*10+(s[1]-'0')<=26){
    			dp[1] = 2;
    		}
    		else{
    			dp[1] = 1;
    		}
    	}
    	// 开始往下走dp过程
    	for(int i=2; i<len; i++){
    		int pre = s[i-1]-'0';
    		int curr = s[i]-'0';
    		// 连续两个0 直接gg
    		if(pre==0 && curr==0){return 0;}
    		if(curr==0){ // curr是0 则必须跟i-1连上编码
    			if(pre*10+curr<=26){
    				dp[i]=dp[i-2];
    			}
    			else{
    				return 0;
    			}
    		}
    		else if(pre==0){ // pre是0 则curr必须独立编码
    			dp[i]=dp[i-1];
    		}
    		else{
    			if(pre*10+curr<=26){
    				dp[i] = dp[i-1] + dp[i-2];
    			}
    			else{
    				dp[i] = dp[i-1];
    			}
    		}
    	}
    	return dp[len-1];
    }
};