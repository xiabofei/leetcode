#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


// 选1个元素+1 或 选1个元素-1
// 最小移动次数
// 解法: 排序 两头往中间靠拢

class Solution {
public:
    int minMoves2(vector<int>& nums){
    	sort(nums.begin(), nums.end());
    	int b = 0;
    	int e = nums.size()-1;
    	int ret = 0;
    	while(b<e){
    		ret += nums[e--] - nums[b++];
    	}
    	return ret;
    }
};