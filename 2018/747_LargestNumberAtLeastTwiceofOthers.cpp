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
    int dominantIndex(vector<int>& nums) {
    	if(nums.size()==0){return -1;}
    	if(nums.size()==1){return 0;}
    	pair<int, int> one = {-1, INT_MIN};
    	pair<int, int> two = {-1, INT_MIN};
    	for(int i=0; i<nums.size(); i++){
    		if(nums[i]>=one.second){
    			two.first = one.first;
    			two.second = one.second;
    			one.first = i;
    			one.second = nums[i];
    		}
    		else if(nums[i] >= two.second){
    			two.first = i;
    			two.second = nums[i];
    		}
    	}
    	return one.second>=2*two.second ? one.first : -1;
    }
};