#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// dp求所有回文子串 + dfs遍历所有切分可能
// 注意传参传引用 可以提升效率

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> ret;
		if(s.size()==0){return ret;}
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
		palindrome(s, dp);
		vector<string> tmp;
		dfs(dp, ret, tmp, s, 0);
		return ret;
	}
	void palindrome(string& s, vector<vector<bool>>& dp){
		for(int i=0; i<s.size(); i++){
			dp[i][i] = true;
		}
		for(int r=1; r<s.size(); r++){
			for(int l=r; l>=0; l--){
				if(r-l<2){
					dp[l][r] = s[l]==s[r];
				}
				else{
					dp[l][r] = s[l]==s[r] && dp[l+1][r-1];
				}
			}
		}
	}
	void dfs(
		vector<vector<bool>>& dp,
		vector<vector<string>>& ret, vector<string>& tmp, 
		string& s, const int b){
		if(b==s.size()){
			ret.push_back(tmp);
			return;
		}
		for(int i=b; i<s.size(); i++){
			if(dp[b][i]){
				tmp.push_back(s.substr(b, i-b+1));
				dfs(dp, ret, tmp, s, i+1);
				tmp.pop_back();
			}
		}
	}
};
