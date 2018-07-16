#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	unordered_map<int, int> val_idx;
    	for(int i=0; i<nums.size(); i++){
    		if(val_idx.find(nums[i])!=val_idx.end() && i-val_idx[nums[i]]<=k){
    			return true;
    		}
    		val_idx[nums[i]] = i;
    	}
    	return false;
    }
};