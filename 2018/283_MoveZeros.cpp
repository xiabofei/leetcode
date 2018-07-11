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
    void moveZeroes(vector<int>& nums) {
    	int index = 0;
    	for(int i=0; i<nums.size(); i++){
    		if(nums[i]!=0){
    			nums[index] = nums[i];
    			index++;
    		}
    	}
    	while(index<nums.size()){nums[index++] = 0;}
    }
};