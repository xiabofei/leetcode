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
    int jump(vector<int>& nums) {
    	if(nums.size()==1){return 0;}
    	int steps = 0;
    	int curr_farest = 0;
    	int next_farest = 0;
    	// 到curr_farest之前 只需要jump一次就能到达
    	for(int i=0; i<=curr_farest; i++){
    		next_farest = max(next_farest, i+nums[i]);
    		// 走到了当前轮能跳到最远的地方
    		if(i == curr_farest){
    			// jump once
    			steps++;
    			curr_farest = next_farest;
    			// 从当前范围内jump 下次已经能够到end了
    			if(curr_farest>=nums.size()-1){
    				return steps;
    			}
    		}
    	}
    	return steps;
    }
};