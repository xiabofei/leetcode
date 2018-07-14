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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	vector<vector<int>> ret;
    	vector<int> tmp;
    	sort(nums.begin(), nums.end());
    	backtracing(ret, tmp, nums, 0);
    	return ret;
    }
    void backtracing(vector<vector<int>>& ret, vector<int>& tmp, 
    	vector<int>& nums, const int idx){
    	ret.push_back(tmp);
    	for(int i=idx; i<nums.size(); i++){
    		if(i==idx || nums[i]!=nums[i-1]){
    			tmp.push_back(nums[i]);
    			backtracing(ret, tmp, nums, i+1);
    			tmp.pop_back();
    		}
    	}
    }
};