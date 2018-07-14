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
    vector<vector<int>> combine(int n, int k) {
    	vector<vector<int>> ret;
    	vector<int> tmp;
    	backtracing(ret, tmp, n, 1, k);
    	return ret;
    }
    void backtracing(
    	vector<vector<int>>& ret, vector<int>& tmp, 
    	const int n, const int begin, const int k){
    	if(tmp.size()==k){
    		ret.push_back(tmp);
    		return;
    	}
    	for(int i=begin; i<=n; i++){
    		tmp.push_back(i);
    		backtracing(ret, tmp, n, i+1, k);
    		tmp.pop_back();
    	}
    }
};