#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 子数组乘积与和的不同在于有正负
// 子数组和只考虑最大即可 子数组乘积需要同时考虑最大最小

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> max_local(nums.size(), 0);
        vector<int> min_local(nums.size(), 0);
        max_local[0] = nums[0];
        min_local[0] = nums[0];
        int ret = max_local[0];
        for(int i=1; i<nums.size(); i++){
            int opt1 = nums[i];
            int opt2 = nums[i] * max_local[i-1];
            int opt3 = nums[i] * min_local[i-1];
            max_local[i] = max(opt1, max(opt2, opt3));
            min_local[i] = min(opt1, min(opt2, opt3));
            ret = max(ret, max_local[i]);
        }
        return ret;
    }
};