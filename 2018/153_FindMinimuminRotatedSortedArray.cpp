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
    int findMin(vector<int>& nums) {
    	int b = 0;
    	int e = nums.size()-1;
    	while(b<e){
    		if(nums[b]<nums[e]){
    			return nums[b];
    		}
    		int m = (b+e)/2;
    		if(nums[b]<=nums[m]){
    			// 前半段有序 最小值在后半段
    			b = m+1;
    		}
    		else{
    			// 前半段无序 最小值在前半段
    			e = m;
    		}
    	}
    	return nums[e];
    }
};