#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// https://leetcode.com/problems/restore-ip-addresses/discuss/31151/Share-0ms-neat-and-clear-c++-solution-using-DFS
// dfs解法 + 各种剪枝条件

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		string tmp = "";
		dfs(ret, tmp, s, 0, 0);
		return ret;
	}
	void dfs(vector<string>& ret, string tmp, string s, int step, const int b){
		if(b==s.size() && step==4){
			tmp.pop_back();
			ret.push_back(tmp);
			return;
		}
    	// 剪枝
		if(s.size() - b > (4-step)*3){return;}
		if(s.size() - b < 4-step){return;}
    	// 当前部分取1/2/3个数字
    	// 如果s[b]是0 则只能单独列出来 否则会有重复解
    	if(s[b]=='0'){
    		dfs(ret, tmp+"0.", s, step+1, b+1);
    		return;
    	}
		int curr = 0;
		for(int i=b; i<min(b+3, (int)s.size()); i++){
			curr = 10*curr + s[i]-'0';
			if(curr>=0 && curr<=255){
				dfs(ret, tmp + to_string(curr) + ".", s, step+1, i+1);
			}
			if(curr==0){
				break;
			}
		}
	}
};