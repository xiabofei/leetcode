#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ret;
		vector<int> tmp;
		set<int> already_used;
		backtracing(ret, tmp, nums, already_used);
		return ret;
	}
	void backtracing(
		vector<vector<int>>& ret, vector<int>& tmp, vector<int>& nums, set<int>& already_used){
		if(tmp.size()==nums.size()){
			ret.push_back(tmp);
			return;
		}
		set<int> used_val;
		for(int i=0; i<nums.size(); i++){
			if(already_used.find(i) == already_used.end()){
				// 本层已经用过的value不考虑
				if(used_val.find(nums[i]) != used_val.end()){
					continue;
				}
				else{
					used_val.insert(nums[i]);
				}
				tmp.push_back(nums[i]);
				already_used.insert(i);
				backtracing(ret, tmp, nums, already_used);
				already_used.erase(i);
				tmp.pop_back();
			}
		}
	}
};