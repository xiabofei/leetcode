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
    int maxSubArray(vector<int>& nums) {
    	// 理解DP思想: 不求一步到位, 通过按步骤积累小的阶段性到位, 等走到最后自然就获得全局的到位了
    	int local = INT_MIN;
    	int global = INT_MIN;
    	for(int i=0; i<nums.size(); i++){
    		local = local>0 ? local+nums[i] : nums[i];
    		global = max(global, local);
    	}
    	return global;
    }
};