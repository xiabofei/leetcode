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
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> ret;
    	vector<int> tmp;
    	int index = 0;
    	backtracing(ret, tmp, nums, index);
    	return ret;
    }
    void backtracing(
    	vector<vector<int>>& ret,
    	vector<int>& tmp,
    	vector<int>& nums,
    	int index){
    	if(index==nums.size()){
    		ret.push_back(tmp);
    		return;
    	}
    	tmp.push_back(nums[index]);
    	backtracing(ret, tmp, nums, index+1);
    	tmp.pop_back();
    	backtracing(ret, tmp, nums, index+1);
    }
};