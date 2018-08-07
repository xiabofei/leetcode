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
    int searchInsert(vector<int>& nums, int target) {
    	if(nums.size()==0){return 0;}
    	if(nums.size()==1){return target>nums[0] ? 1 : 0;}
    	int p = 0;
    	while(p<nums.size()){
    		if(target<=nums[p]){
    			break;
    		}
    		p++;
    	}
    	return p;
    }
};
