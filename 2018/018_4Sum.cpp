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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int>> ret;
    	if(nums.size()<4){return ret;}
    	sort(nums.begin(), nums.end());
    	// 从前向后卡住位置 留3个富裕
    	for(int i=0; i<nums.size()-3; i++){
    		if(i>0 && nums[i]==nums[i-1]){continue;}
    		// 从后向前卡住位置 留2个富裕
    		for(int j=nums.size()-1; j>i+2; j--){
    			if(j<nums.size()-1 && nums[j]==nums[j+1]){continue;}
    			int l = i+1;
    			int r = j-1;
    			while(l<r){
    				int sum = nums[i] + nums[l] + nums[r] + nums[j];
    				if(sum==target){
    					vector<int> tmp = {nums[i], nums[l], nums[r], nums[j]};
    					ret.push_back(tmp);
    					l++;
    					while(nums[l]==nums[l-1]){l++;}
    					r--;
    					while(nums[r]==nums[r+1]){r--;}
    				}
    				else if(sum>target){	
    					r--;
    				}
    				else{
    					l++;
    				}
    			}
    		}
    	}
    	return ret;
    }
};