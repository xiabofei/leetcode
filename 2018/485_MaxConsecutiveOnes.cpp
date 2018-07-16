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
    int findMaxConsecutiveOnes(vector<int>& nums) {
    	if(nums.size()==0){return 0;}
    	int longest = 0;
    	int count = 0;
    	for(int i=0; i<nums.size(); i++){
    		if(nums[i]==1){
    			count++;
    		}
    		else{
    			longest = max(longest, count);
    			count = 0;
    		}
    	}
    	longest = max(longest, count);
    	return longest;
    }
};
