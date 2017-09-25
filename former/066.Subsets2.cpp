#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums)
    {
    	sort(nums.begin(), nums.end());
    	vector<vector<int> > ret;
    	vector<int> tmp;
    	Solution::dfs(nums, 0, tmp, ret);
    	return ret;
    }
    // 求子集 dfs每一层只管一个事情
    static void dfs(vector<int>& nums, int begin, vector<int>& tmp, vector<vector<int> >& ret)
    {
    	if ( begin==nums.size() )
    	{
    		ret.push_back(tmp);
    		return;
    	}
    	tmp.push_back(nums[begin]);
    	Solution::dfs(nums, begin+1, tmp, ret);
    	tmp.pop_back();
    	if ( !(!tmp.empty() && tmp.back()==nums[begin]) )
    	{
    		Solution::dfs(nums, begin+1, tmp, ret);
    	}
    }
};