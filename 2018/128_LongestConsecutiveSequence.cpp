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
    int longestConsecutive(vector<int>& nums) {
    	// 这种O(n)要求的 可以用hashmap实现
    	if(nums.size()==0){return 0;}
    	unordered_set<int> existed;
    	unordered_set<int> visited;
    	// 获得所有distinct元素的全集
    	for(int i=0; i<nums.size(); i++){existed.insert(nums[i]);}
    	// 遍历nums元素 每定位一个连续的新区间 向left和right延伸 
    	// 直到把nums中所有能拼接的元素都找到
    	int count = 0;
        int longest = 0;
    	for(int i=0; i<nums.size(); i++){
    		if(visited.find(nums[i]) != visited.end()){
    			continue;
    		}
    		int val = nums[i]-1;
    		count = 1;
    		// 向left延伸能找到所有连续的值
    		while(existed.find(val) != existed.end()){
    			visited.insert(val);
    			val--;
    			count++;
    		}
    		// 向right延伸能找到所有连续的值
    		val = nums[i]+1;
    		while(existed.find(val) != existed.end()){
    			visited.insert(val);
    			val++;
    			count++;
    		}
    		longest = max(longest, count);
    	}
    	return longest;
        /*
        // 还有一种只用一个额外空间的解法
        // 这种O(n)的可以想到用hashmap
        if(nums.size()==0){return 0;}
        unordered_set<int> sets;
        for(int i=0; i<nums.size(); i++){
            sets.insert(nums[i]);
        }
        int ret = -1;
        for(int i=0; i<nums.size(); i++){
            if(sets.find(nums[i])!=sets.end()){
                int tmp_len = 1;
                int cur = nums[i];
                // 连续大的
                while(sets.find(++cur)!=sets.end()){
                    tmp_len++;
                    sets.erase(cur);
                }
                cur = nums[i];
                // 连续小的
                while(sets.find(--cur)!=sets.end()){
                    tmp_len++;
                    sets.erase(cur);
                }
                ret = max(ret, tmp_len);
            }
        }
        return ret;
        */
    }
};