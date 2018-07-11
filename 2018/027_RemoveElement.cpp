#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std	;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int index = 0;
    	for(int i=0; i<nums.size(); i++){
    		if(nums[i]!=val){
    			nums[index]=nums[i];
    			index++;
    		}
    	}
    	return index;
    }
};