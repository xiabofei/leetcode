#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
    	if(bits.size()==0){return false;}
    	if(bits.size()==1){return true;}
    	if(bits.size()==2){return bits[0]==0;}
    	vector<bool> dp(bits.size(), false);
    	dp[0] = bits[0]==0;
    	for(int i=1; i<bits.size(); i++){
    		if(i<2){
    			dp[i] = (dp[i-1] && bits[i]==0) 
    			|| (bits[i]==1 && bits[i-1]==1) 
    			|| (bits[i]==0 && bits[i-1]==1);
    		}
    		else{
    			dp[i] = 
    			(dp[i-1] && bits[i]==0) 
    			|| (((bits[i]==1 && bits[i-1]==1) || (bits[i]==0 && bits[i-1]==1)) && dp[i-2]);
    		}
    	}
    	if(!dp[bits.size()-1]){return false;}
    	return (dp[bits.size()-3] && bits[bits.size()-2]==0) || dp[bits.size()-2];
    }
};