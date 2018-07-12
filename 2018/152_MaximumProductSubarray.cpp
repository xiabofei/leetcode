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
    int maxProduct(vector<int>& nums) {
    	vector<int> max_v(nums.size(), 0);
    	vector<int> min_v(nums.size(), 0);
    	// 必定包含当前元素的最大值
    	max_v[0] = nums[0];
    	// 必定包含当前元素的最小值
    	min_v[0] = nums[0];
    	int ret = nums[0];
    	// 遍历
    	for(int i = 1; i < nums.size(); i++){
    		max_v[i] = max(nums[i], max(nums[i] * max_v[i-1], nums[i] * min_v[i-1]));
    		min_v[i] = min(nums[i], min(nums[i] * max_v[i-1], nums[i] * min_v[i-1]));
    		ret = max(ret, max_v[i]);
    	}
    	return ret;
    }
};