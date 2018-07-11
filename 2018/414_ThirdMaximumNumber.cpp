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
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN; 
        long second = LONG_MIN;
        long third = LONG_MIN;
        for(size_t i = 0; i < nums.size(); i++){
        	if(nums[i]==first || nums[i]==second || nums[i]==third){
        		continue;
        	}
        	if(nums[i] > first){
        		third = second;
        		second = first;
        		first = nums[i];
        	}
        	else if(nums[i] > second){
        		third = second;
        		second = nums[i];
        	}
        	else if(nums[i] > third){
        		third = nums[i];
        	}
        	else{
        		continue;
        	}
        }
        return third==LONG_MIN ? first : third;
    }
};