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
    vector<int> findDuplicates(vector<int>& nums) {
    	vector<int> ret;
    	// 元素下标归位
    	for(int i=0; i<nums.size(); i++){
    		while(nums[i]!=i+1 && nums[i]!=nums[nums[i]-1]){
    			swap(nums[i], nums[nums[i]-1]);
    		}
    	}
    	// 扫描找重复
    	for(int i=0; i<nums.size(); i++){
    		if(nums[i]!=i+1){
    			ret.push_back(nums[i]);
    		}
    	}
    	return ret;
    }
};