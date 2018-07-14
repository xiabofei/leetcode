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
    vector<vector<int>> combinationSum3(int k, int n) {
    	vector<vector<int>> ret;
    	vector<int> tmp;
    	backtracing(ret, tmp, 1, k, n);
    	return ret;
    }
    void backtracing(
    	vector<vector<int>>& ret, vector<int>& tmp, 
    	const int begin, const int k, const int residu){
    	if(residu==0 && tmp.size()==k){
    		ret.push_back(tmp);
    		return;
    	}
    	// 剪枝条件 : 元素大于9 或 组合个数大于k
    	if(begin>9 || tmp.size()>k){return;}
    	// 遍历可能路径
    	for(int i=begin; i<=9; i++){
    		if(i<=residu){
    			tmp.push_back(i);
    			backtracing(ret, tmp, i+1, k, residu-i);
    			tmp.pop_back();
    		}
    	}
    }
};
