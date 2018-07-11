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
    int removeDuplicates(vector<int>& nums) {
    	if(nums.size()==0){return 0;}
    	// 1. index表示前一个插入的位置
    	int index = 0;
    	for(int i=1; i<nums.size(); i++){
    		// 2. 由于是有序数组 插入条件是遇到与前一个不同的元素
    		if(nums[i]!=nums[i-1]){
    			index++;
    			nums[index] = nums[i];
    		}
    	}
    	return index+1;
    }
};