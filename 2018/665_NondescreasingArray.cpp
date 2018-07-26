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
    bool checkPossibility(vector<int>& nums) {
    	if(nums.size()<=2){return true;}
    	// 后半段升序中最小的
    	int right_idx = nums.size()-1;
    	for(int i=nums.size()-2; i>0 && nums[i]<=nums[i+1]; i--){right_idx = i;}
    	// 前半段升序中最大的
    	int left_idx = 0;
    	for(int i=1; i<nums.size() && nums[i]>=nums[i-1]; i++){left_idx = i;}
    	if(right_idx <= left_idx){
    		// 有序
    		return true;
    	}
    	else if(right_idx - left_idx > 1){
    		// 间隔太远
    		return false;
    	}
    	else if(left_idx==0 || right_idx==nums.size()-1){
    		// 首尾边界
    		return true;
    	}
    	else{
    		// 两种修改情况
    		return nums[left_idx-1]<=nums[right_idx] || nums[left_idx]<=nums[right_idx+1];
    	}
    }
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {2, 3, 3, 2, 4};
	Solution().checkPossibility(dat);
	return 0;
}