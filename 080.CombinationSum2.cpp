#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
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
        set<int> used;
    	for ( int i=index; i<candidates.size(); ++i )
    	{
    		if (target>=candidates[i] && used.find(candidates[i])==used.end() )
    		{
    			tmp.push_back(candidates[i]);
                used.insert(candidates[i]);
    			Solution::dfs(ret, candidates, i+1, target - candidates[i], tmp);
    			tmp.pop_back();
    		}
    	}
    }
};