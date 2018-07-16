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
    int threeSumClosest(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
    	int closest = 0;
    	int residu = INT_MAX;
    	for(int i=0; i<nums.size()-2; i++){
    		// 固定第i个元素
    		int l = i+1;
    		int r = nums.size()-1;
    		while(l<r){
    			int sum = nums[i] + nums[l] + nums[r];
    			if(abs(sum - target)<residu){
    				closest = sum;
    				residu = abs(sum - target);
    			}
    			if(sum < target){
    				l++;
    				while(nums[l]==nums[l-1]){l++;}
    			}
    			else if(sum > target){
    				r--;
    				while(nums[r]==nums[r+1]){r--;}
    			}
    			else{
    				return sum;
    			}
    		}
    	}
    	return closest;
    }
};