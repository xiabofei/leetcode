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
    int pivotIndex(vector<int>& nums) {
    	if(nums.size()==0){return -1;}
    	// 累加和
    	vector<int> accu(nums.size(), 0);
    	accu[0] = nums[0];
    	for(int i=1; i<nums.size(); i++){
    		accu[i] = accu[i-1] + nums[i];
    	}
    	// accu[N] - accu[i] - nums[i]技巧
    	for(int i=0; i<nums.size(); i++){
    		int right = accu[nums.size()-1] - accu[i];
    		int left = accu[i] - nums[i];
    		if(left == right){
    			return i;
    		}
    	}
    	return -1;
    }
};