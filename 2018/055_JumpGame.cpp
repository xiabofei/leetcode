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
    bool canJump(vector<int>& nums) {
    	int curr_farest = 0;
    	for(int i=0; i<=curr_farest; i++){
    		curr_farest = max(curr_farest, i+nums[i]);
    		if(curr_farest>=nums.size()-1){
    			return true;
    		}
    	}
    	return false;
    }
};