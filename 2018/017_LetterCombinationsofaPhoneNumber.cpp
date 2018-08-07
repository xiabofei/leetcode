#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 生成所有可能的情况 用回溯法
// 每次传进来一个begin的位置

class Solution {
public:
	vector<string> candidates = {
		"0", "1", 
		"abc", "def", "ghi", 
		"jkl", "mno", "pqrs", 
		"tuv", "wxyz"
	};
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		if(digits.size()==0){return ret;}
		vector<char> tmp;
		backtracing(ret, tmp, digits, 0);
		return ret;
	}
	void backtracing(
		vector<string>& ret, vector<char>& tmp, string digits, const int begin){
		if(tmp.size() == digits.size()){
			ret.push_back(string(tmp.begin(), tmp.end()));
			return;
		}
		int curr = digits[begin] - '0';
		for(int i = 0; i < candidates[curr].size(); i++){
			tmp.push_back(candidates[curr][i]);
			backtracing(ret, tmp, digits, begin+1);
			tmp.pop_back();
		}
	}
};
