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
    int findDuplicate(vector<int>& nums) {
    	// 先排序再遍历 nlog(n)方法
    	/*
    	sort(nums.begin(), nums.end());
    	for(int i=1; i<nums.size(); i++){
    		if(nums[i]==nums[i-1]){
    			return nums[i];
    		}
    	}
    	*/
    	return nums[0];
    	// 双指针找环路的方法 Floyd's Algorithm
    	int slow = 0; 
    	int fast = 0;
    	slow = nums[0];
    	fast = nums[nums[0]];
    	while(slow!=fast){
    		slow = nums[slow];
    		fast = nums[nums[fast]];
    	}
    	fast = 0;
    	while(slow!=fast){
    		slow = nums[slow];
    		fast = nums[fast];
    	}
    	return fast;
    }
};
