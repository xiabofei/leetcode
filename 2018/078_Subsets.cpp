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
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> ret;
    	vector<int> tmp;
    	int index = 0;
        sort(nums.begin(), nums.end());
    	dfs(ret, tmp, nums, index);
    	return ret;
    }
    void dfs(vector<vector<int>>& ret, vector<int>& tmp, vector<int>& nums, int index){
        ret.push_back(tmp);
        // 深搜的标准写法
        for(int i=index; i<nums.size(); i++){
            tmp.push_back(nums[i]);
            // 每轮只向下迭代i之后的元素
            dfs(ret, tmp, nums, i+1);
            tmp.pop_back();
        }
    }
};