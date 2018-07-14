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
    // int missingNumber(vector<int>& nums) {
    // 	int ret = 0;
    // 	for(int i=0; i<nums.size(); i++){
    // 		ret ^= (i+1)^nums[i];
    // 	}
    // 	return ret;
    // }
    int missingNumber(vector<int>& nums) {
    	int ret = 0;
    	for(int i=0; i<nums.size(); i++){
    		ret += nums[i];
    	}
    	return (nums.size()+1)*(nums.size()+1)/2 - ret;
    }
};