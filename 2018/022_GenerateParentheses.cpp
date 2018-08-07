#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 回溯的时候限定条件

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> ret;
    	string tmp = "";
    	backtracing(ret, tmp, 0, 0, n);
    	return ret;
    }
    void backtracing(vector<string>& ret, string tmp, int l, int r, const int n){
    	if(tmp.size()==2*n){
    		ret.push_back(tmp);
    		return;
    	}
    	// l代表'('的数量 r代表')'的数量
    	// 保证l>=r 且l<=n
    	if(l==r){
    		backtracing(ret, tmp+"(", l+1, r, n);
    	}
    	if(l>r){
    		if(l<n){
    			backtracing(ret, tmp+"(", l+1, r, n);
    		}
    		backtracing(ret, tmp+")", l, r+1, n);
    	}
    }
};