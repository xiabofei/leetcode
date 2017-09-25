#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Tips:
1) dp思路先想起来
2) 重点是讨论'*' 而'.'作为辅助情况讨论
3) 分下一个元素是不是'*'讨论
4) '*' 在题干中有消除前一个元素的功能 且题目给的string都是合法的 所以 索引-2 这种用法会出现
5) 在判断dp[is][ip]的时候 敢这么用dp[is-1][ip]可以理解了
6) dp的几种cond刷下来
*/


class Solution {
public:
    bool isMatch(string s, string p) {
    	const size_t s_len = s.length();
    	const size_t p_len = p.length();
    	bool dp[s_len+1][p_len+1];
    	std::fill_n(&dp[0][0], (s_len+1)*(p_len+1), false);
    	dp[0][0] = true;
    	for(size_t i=1; i<=s_len; i++){dp[i][0]=false;}
    	for(size_t i=1; i<=p_len; i++){
    		if(p[i-1]!='*'){
    			dp[0][i] = false;
    		}
    		else{
    			dp[0][i] = dp[0][i-2];
    		}
    	}
    	for(size_t is = 1; is <= s_len; is++){
    		for(size_t ip = 1; ip <= p_len; ip++){
    			if(p[ip-1]!='*'){
    				bool cond = dp[is-1][ip-1] && (s[is-1]==p[ip-1]||p[ip-1]=='.');
    				dp[is][ip] = cond;
    			}
    			else{
    				if(dp[is][ip-1]){
    					dp[is][ip] = true;
    				}
    				else if(dp[is][ip-2]){
    					dp[is][ip] = true;
    				}
    				else if(dp[is-1][ip] && (s[is-1]==p[ip-2] || p[ip-2]=='.')){
    					dp[is][ip] = true;
    				}
    			}
    		}
    	}
    	return dp[s_len][p_len];
    }
};