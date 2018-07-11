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
    int countSubstrings(string s) {
    	if(s.size()==0){return 0;}
    	if(s.size()==1){return 1;}
    	int ret = 0;
    	bool dp[s.size()][s.size()];
    	fill_n(&dp[0][0], s.size()*s.size(), false);
    	for(int i=0; i<s.size(); i++){
    		for(int j=i; j>=0; j--){
    			if(i-j<2){
    				dp[j][i] = s[j]==s[i];
    			}
    			else{
    				dp[j][i] = dp[j+1][i-1] && s[j]==s[i];
    			}
    			ret += dp[j][i] ? 1 : 0;
    		}
    	}
    	return ret;
    }
};