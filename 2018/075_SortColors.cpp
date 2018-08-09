#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 把0都换到i前面 i前进
// 把2都换到i后面 i不动
// 遇到了1 i前进
// i与p2交换的时候 只能保证把2换到了后面 没有保证把0换到了前面 因此i不能前进

class Solution {
public:
	void sortColors(vector<int>& nums) {
		if(nums.size()<2){return;}
    	if(nums.size()==2){
    		if(nums[0]>nums[1]){
    			swap(nums[0], nums[1]);
    			return;
    		}
    	}
		int p0 = 0;
		int p2 = nums.size()-1;
		int i = 0;
		while(i<=p2){
			if(nums[i]==0){
				swap(nums[i], nums[p0]);
				i++;
				p0++;
			}
			else if(nums[i]==2){
				swap(nums[i], nums[p2]);
				p2--;
			}
			else{
				i++;
			}
		}
	}
};
