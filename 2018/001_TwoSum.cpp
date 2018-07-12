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
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> ret;
    	map<int, int> val_idx;
    	for(int i=0; i<nums.size(); i++){
    		if(val_idx.find(target-nums[i]) != val_idx.end()){
    			ret.push_back(val_idx[target-nums[i]]);
    			ret.push_back(i);
    		}
    		else{
    			val_idx[nums[i]] = i;
    		}
    	}
    	return ret;
    }
};