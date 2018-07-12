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
    	int index = 0;
    	int count = 1;
    	// 与完全remove的不同在于 从1开始
    	for(int i = 1; i < nums.size(); i++){
    		if(nums[index]!=nums[i]){
    			nums[++index] = nums[i];
    			count = 1;
    		}
    		else if(count==1){
    			nums[++index] = nums[i];
    			count++;
    		}
    	}
    	return index+1;
    }
};
