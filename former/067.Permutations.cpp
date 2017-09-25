#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums)
    {
    	vector<vector<int> > ret;
    	vector<int> tmp;
    	vector<bool> used(nums.size(), false);
    	Solution::dfs(ret, tmp, nums, used);
    	return ret;
    }
    static void dfs(
    	vector<vector<int> >& ret, vector<int>& tmp, 
    	vector<int>& nums, vector<bool>& used)
    {
    	if ( tmp.size()==nums.size() )
    	{
    		ret.push_back(tmp);
    		return;
    	}
    	// 与SubsetsII这道题对比 每一层也是处理一个元素 只不过可以有多个选择
    	for ( int i=0; i<nums.size(); ++i )
    	{
    		if ( used[i] ) continue;
    		tmp.push_back(nums[i]);
    		used[i] = true;
    		Solution::dfs(ret, tmp, nums, used);
    		used[i] = false;
    		tmp.pop_back();
    	}
    }
};