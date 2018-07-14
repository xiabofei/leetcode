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
    vector<int> productExceptSelf(vector<int>& nums) {
    	vector<int> ret(nums.size(), 1);
    	int base = 1;
    	// 记录每个元素左边的连乘积
    	for(int i=1; i<nums.size(); i++){
    		base *= nums[i-1];
    		ret[i] = base;
    	}
    	// 记录每个元素右边的连乘积
    	base = 1;
    	for(int i=nums.size()-2; i>=0; i--){
    		base *= nums[i+1];
    		ret[i] *= base; 
    	}
    	return ret;
    }
};