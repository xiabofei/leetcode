#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums)
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
        set<int> usedThisLayer;
    	for ( int i=0; i<nums.size(); ++i )
    	{
    		if ( used[i] || usedThisLayer.find(nums[i])!=usedThisLayer.end() ) continue;
            usedThisLayer.insert(nums[i]);
    		tmp.push_back(nums[i]);
    		used[i] = true;
    		Solution::dfs(ret, tmp, nums, used);
    		used[i] = false;
    		tmp.pop_back();
    	}
    }
};