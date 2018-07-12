#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	// 求众数采用Moore Voting方法
    	// 采用这种投票法的前提是 majority元素一定存在
    	// 因此不会出现[1,1,1,2,2,2,3]这种情况
    	if(nums.size()==1){return nums[0];}
    	int candidates = 0;
    	int counts = 0;
    	for(int i=0; i<nums.size(); i++){
    		if(nums[i] == candidates){
    			counts++;
    		}
    		else if(counts==0){
    			candidates = nums[i];
    			counts = 1;
    		}
    		else{
    			counts--;
    		}
    	}
    	return candidates;
    }
};