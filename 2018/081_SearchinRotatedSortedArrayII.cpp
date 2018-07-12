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
	bool search(vector<int>& nums, int target) {
		if(nums.size()==0){return false;}
		int b = 0; 
		int e = nums.size()-1;
		while(b<=e){
			int m = (b+e)/2;
			if(target==nums[m]){return true;}
			if(nums[b]<nums[m]){ // 左半边有序
				if(target<nums[m] && target>=nums[b]){
					e = m - 1;
				}
				else{
					b = m + 1;
				}
			}
			else if(nums[b]>nums[m]){ // 右半边有序
				if(target>nums[m] && target<=nums[e]){
					b = m + 1;
				}
				else{
					e = m - 1;
				}
			}
			else{ // 出现重复元素(重复元素把握住一边即可)
				b++;
			}
		}
		return false;
	}
};