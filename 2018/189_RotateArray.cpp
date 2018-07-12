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
    void rotate(vector<int>& nums, int k) {
    	if(nums.size()<2 || k<1){return;}
    	k = k%nums.size();
    	// 0 - end reverse
    	reverse(nums, 0, nums.size()-1); 
    	// 0 - k-1 reverse
    	reverse(nums, 0, k-1);
    	// k - end reverse
    	reverse(nums, k, nums.size()-1);
    }
    void reverse(vector<int>& nums, int b, int e){
    	while(b<e){
    		swap(nums[b++], nums[e--]);
    	}
    }
};