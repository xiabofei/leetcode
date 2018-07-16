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
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> ret;
    	if(nums.size()<3){return ret;}
    	sort(nums.begin(), nums.end());
    	for(int i=0; i<nums.size()-2; i++){
    		// 剪枝掉重复元素
    		if(i>0 && nums[i]==nums[i-1]){continue;}
    		// 固定第i个元素计入和
    		int l = i+1;
    		int r = nums.size()-1;
    		while(l<r){
    		    int sum = nums[i] + nums[l] + nums[r];
    			if(sum>0){
    				r--;
    			}
    			else if(sum<0){
    				l++;
    			}
    			else{
    				vector<int> tmp = {nums[i], nums[l], nums[r]};
    				ret.push_back(tmp);
    				// right和left一起移动 直到都遇上不同的元素
    				l++;
    				r--;
    				while(nums[l]==nums[l-1]){l++;}
    				while(nums[r]==nums[r+1]){r--;}
    			}
    		}
    	}
    	return ret;
    }
};