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
    int missingNumber(vector<int>& nums) {
    	int miss = 0;
    	for(int i=0; i<nums.size(); i++){
    		miss ^= (i+1) ^ nums[i];
    	}
    	return miss;
    }
};