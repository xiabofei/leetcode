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
    int minSubArrayLen(int s, vector<int>& nums) {
    	int p1 = 0;
    	int p2 = 0;
    	int min_len = INT_MAX;
    	bool flag = false;
    	int tmp_sum = 0;
    	for(int p2 = 0; p2 < nums.size(); p2++){
    		tmp_sum += nums[p2];
    		if(tmp_sum>=s){
    			flag = true;
    			while(p1<p2 && tmp_sum-nums[p1]>=s){
    				tmp_sum -= nums[p1];
    				p1++;
    			}
    			min_len = min(min_len, p2-p1+1);
    		}
    	}
    	return flag? min_len : 0;
    }
};