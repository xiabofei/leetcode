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
    int search(vector<int>& nums, int target) {
    	return find(nums, 0, nums.size()-1, target);
    }
    int find(vector<int>& nums, int b, int e, int target){
    	if(b>e){return -1;}
    	if(b==e){return nums[b]==target ? b : -1;}
    	if(e-b==1){
    		if(nums[b]==target){
    			return b;
    		}
    		else if(nums[e]==target){
    			return e;
    		}
    		else{
    			return -1;
    		}
    	}
    	int m = (b+e)/2;
    	if(nums[m]==target){return m;}
    	// left和right都有有序的
    	if(nums[b]<nums[m] && nums[m]<nums[e]){
    		if(nums[m]<target){return find(nums, m+1, e, target);}
    		if(nums[m]>target){return find(nums, b, m-1, target);}
    	}
    	// left和right只有一半是有序的
    	if(nums[b]<nums[m]){ // left是有序的
    		if(nums[b]<=target && nums[m]>target){
    			return find(nums, b, m-1, target);
    		}
    		else{
    			return find(nums, m+1, e, target);
    		}
    	}
    	else{ // right是有序的
    		if(nums[e]>=target && nums[m]<target){
    			return find(nums, m+1, e, target);
    		}
    		else{
    			return find(nums, b, m-1, target);
    		}
    	}
    }
};