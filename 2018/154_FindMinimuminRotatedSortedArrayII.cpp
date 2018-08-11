#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 非常巧妙的解法
// 如果有相通的 e--
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/discuss/48808/My-pretty-simple-code-to-solve-it


class Solution {
public:
    int findMin(vector<int>& nums) {
    	int b = 0;
    	int e = nums.size()-1;
    	while(b<e){
    		int m = (b+e)/2;
    		if(nums[m]>nums[e]){
    			// 左半边有序 最小值在右边
    			b = m+1;
    		}
    		else if(nums[m]<nums[e]){
    			// 右半边有序 最大值在左边
    			e = m;
    		}
    		else{
    			e--;
    		}
    	}
    	return nums[e];
    }
};