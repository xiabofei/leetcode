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
    int rob(vector<int>& nums) {
    	if(nums.size()<1){return 0;}
    	if(nums.size()==1){return nums[0];}
    	if(nums.size()==2){return max(nums[0], nums[1]);}
    	// 只允许head
    	int dp_head[nums.size()+1];
    	fill_n(&dp_head[0], nums.size()+1, 0);
    	dp_head[1] = nums[0];
    	for(int i=2; i<nums.size(); i++){
    		dp_head[i] = max(dp_head[i-1], dp_head[i-2]+nums[i-1]);
    	}
    	// 只允许tail
    	int dp_tail[nums.size()+1];
    	fill_n(&dp_tail[0], nums.size()+1, 0);
    	for(int i=2; i<=nums.size(); i++){
    		dp_tail[i] = max(dp_tail[i-1], dp_tail[i-2]+nums[i-1]);
    	}
    	return max(dp_head[nums.size()-1], dp_tail[nums.size()]);
    }
};