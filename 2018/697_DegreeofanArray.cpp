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
    int findShortestSubArray(vector<int>& nums) {
    	if(nums.size()<2){return nums.size();}
    	unordered_map<int, int> num_freq;
    	unordered_map<int, pair<int,int>> num_head_tail; 
    	int degree = 0;
    	// 走第一遍 获得每个数字频率 每个数字的首尾
    	for(int i=0; i<nums.size(); i++){
    		num_freq[nums[i]]++;
    		degree = max(degree, num_freq[nums[i]]);
    		if(num_head_tail.find(nums[i]) == num_head_tail.end()){
    			num_head_tail[nums[i]] = {i, i};
    		}
    		else{
    			num_head_tail[nums[i]].second = i;
    		}
    	}
    	// 访问每个degree元素的head和tail
    	int shortest = INT_MAX;
    	for(unordered_map<int, int>::iterator it = num_freq.begin(); it != num_freq.end(); it++){
    		if(it->second == degree){
    			shortest = min(shortest,num_head_tail[it->first].second - num_head_tail[it->first].first + 1);
    		}
    	}
    	return shortest;
    }
};