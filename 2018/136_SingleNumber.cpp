#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 思路一 借助一个hashset辅助
// 思路二 如果只有一个 可以用异或的算法 最后留下的一定是单独的那个

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	/*
    	unordered_set<int> sets;
    	for(int i=0; i<nums.size(); i++){
    		if(sets.find(nums[i])!=sets.end()){
    			sets.erase(nums[i]);
    		}
    		else{
    			sets.insert(nums[i]);
    		}
    	}
    	return *sets.begin();
    	*/
    	int ret = 0;
    	for(int i=0; i<nums.size(); i++){
    		ret ^= nums[i];
    	}
    	return ret;
    }
};