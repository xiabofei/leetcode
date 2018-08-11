#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 直接用dfs会超时 因为很多break重复了
// 可以用memory的方法记录出现过的string和切分组合

class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		vector<string> ret;
		unordered_set<string> dict;
		for(int i=0; i<wordDict.size(); i++){
			dict.insert(wordDict[i]);
		}
		string tmp = "";
		dfs(ret, tmp, s, dict, 0);
		return ret;
	}
	void dfs(
		vector<string>& ret, string tmp, 
		string s, unordered_set<string>& dict, const int b){
		if(b==s.size()){
			ret.push_back(tmp);
			return;
		}
		for(int i=b; i<s.size(); i++){
			string cur = s.substr(b, i-b+1);
			if(dict.find(cur)==dict.end()){
				continue;
			}
			if(tmp.size()>0){
				dfs(ret, tmp+" "+cur, s, dict, i+1);
			}
			else{
				dfs(ret, cur, s, dict, i+1);
			}
		}
	}
};