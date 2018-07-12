#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    	vector<string> ret;
    	if(nums.size()==0){return ret;}
    	if(nums.size()==1){
    		ret.push_back(to_string(nums[0]));
    		return ret;
    	}
    	int p1 = 0;
    	int p2 = 1;
    	while(p2<nums.size()){
    		if(nums[p2]-nums[p2-1]==1){
    			p2++;
    		}
    		else{
    			if(p2-p1>1){
    				ret.push_back(to_string(nums[p1])+"->"+to_string(nums[p2-1]));
    			}
    			else{
    				ret.push_back(to_string(nums[p1]));
    			}
    			p1 = p2;
    			p2++;
    		}
    	}
    	if(p2-p1>1){
    		ret.push_back(to_string(nums[p1])+"->"+to_string(nums[p2-1]));
    	}
    	else{
    		ret.push_back(to_string(nums[p1]));
    	}
    	return ret;
    }
};