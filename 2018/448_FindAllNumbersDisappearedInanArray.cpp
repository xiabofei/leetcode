#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 元素下标归位法
// https://blog.csdn.net/yutianzuijin/article/details/53861485
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	vector<int> ret;
    	for(int i=0; i<nums.size(); i++){
    		// 元素归位法 nums[i]!=nums[nums[i]-1]遇上重复元素了
    		while(i+1!=nums[i] && nums[i]!=nums[nums[i]-1]){
    			swap(nums[i], nums[nums[i]-1]);
    		}
    	}
    	for(int i=0; i<nums.size(); i++){
    		if(nums[i]!=i+1){
    			ret.push_back(i+1);
    		}
    	}
    	return ret;
    }
};