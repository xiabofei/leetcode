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
    string longestPalindrome(string s) {
    	bool dp[s.size()][s.size()];
    	fill_n(&dp[0][0], s.size()*s.size(), false);
    	for(int i=0; i<s.size(); i++){dp[i][i]=true;}
    	int begin = 0;
    	int end = 0;
    	for(int i=1; i<s.size(); i++){
    		for(int j=0; j<i; j++){
    			if(i-j==1){
    				dp[j][i]=(s[j]==s[i]);
    			}
    			else{
    				dp[j][i] = dp[j+1][i-1] && s[j]==s[i];
    			}
    			if(dp[j][i] && i-j > end-begin){
    				end = i;
    				begin = j;
    			}
    		}
    	}
    	return s.substr(begin, end-begin+1);
    }
};