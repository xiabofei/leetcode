#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target)
    {
    	sort(candidates.begin(), candidates.end());
    	vector<vector<int> > ret;
    	vector<int> tmp;
    	Solution::dfs(ret, candidates, 0, target, tmp);
    	return ret;
    }
    static void dfs(
    	vector<vector<int> >& ret, vector<int>& candidates, int index, 
    	int target, vector<int>& tmp)
    {
    	if ( target==0 )
    	{
    		ret.push_back(tmp);
    		return;
    	}
    	for ( int i=index; i<candidates.size(); ++i )
    	{
    		if (target>=candidates[i])
    		{
    			tmp.push_back(candidates[i]);
    			Solution::dfs(ret, candidates, i, target - candidates[i], tmp);
    			tmp.pop_back();
    		}
    	}
    }
};