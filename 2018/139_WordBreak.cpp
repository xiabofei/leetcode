#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <set>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if(s.size()==0){return true;}
    	// s的各个子串是否能在dict中对应
		vector<vector<bool>> subWords(s.size(), vector<bool>(s.size(), false));
		getSubWords(subWords, s, wordDict);
    	// dp[i]表示s[0:i]能否用wordDict中的term表示
		bool dp[s.size()];
		fill_n(&dp[0], s.size(), false);
		dp[0] = subWords[0][0];
		for(int i=1; i<s.size(); i++){
			if(subWords[0][i]){
				dp[i] = true;
			}
			else{
				for(int j=i; j>0; j--){
    			if(subWords[j][i] && dp[j-1]){ // s[j:i]可以被wordDict中表示
    				dp[i] = true;
    				break;
    			}
    		}
    	}
    }
    return dp[s.size()-1];
}
void getSubWords(vector<vector<bool>>& subWords, string s, vector<string>& wordDict){
	set<string> dict(wordDict.begin(), wordDict.end());
	for(int i=0; i<s.size(); i++){
		for(int j=0; j<=i; j++){
			string sub_s = s.substr(j, i-j+1);
			subWords[j][i] = dict.find(sub_s) != dict.end();
		}
	}
}
};

int main(int argc, char const *argv[])
{
	vector<string> dict;
	dict.push_back("dog");
	dict.push_back("s");
	dict.push_back("gs");
	string s = "dogs";
	cout << Solution().wordBreak(s, dict) << endl;;
	return 0;
}