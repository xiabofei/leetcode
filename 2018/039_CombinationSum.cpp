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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	vector<vector<int>> ret;
    	vector<int> tmp;
    	backtracing(ret, tmp, candidates, 0, target);
    	return ret;
    }
    void backtracing(
    	vector<vector<int>>& ret, vector<int>& tmp, 
    	vector<int>& candidates, const int begin,
    	int residu){
    	if(residu==0){
    		ret.push_back(tmp);
    		return;
    	}
    	for(int i=begin; i < candidates.size(); i++){
    		if(candidates[i]<=residu){
    			tmp.push_back(candidates[i]);
    			backtracing(ret, tmp, candidates, i, residu - candidates[i]);
    			tmp.pop_back();
    		}
    	}
    }
};