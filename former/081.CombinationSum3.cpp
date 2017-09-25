#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n)
    {
    	vector<vector<int> > ret;
    	vector<int> tmp;
    	Solution::dfs(ret, tmp, k, n);
    	return ret;
    }
    static void dfs(vector<vector<int> >& ret, vector<int>& tmp, int k, int n)
    {
    	if ( tmp.size()==k-1 )
    	{
    		if ( n<=9 )
    		{
    			if ( !tmp.empty() && tmp.back()>=n ) return;
    			tmp.push_back(n);
    			ret.push_back(tmp);
    			tmp.pop_back();
    			return;
    		}
    	}
    	for ( int i=tmp.empty()?1:tmp.back()+1; i<=9; ++i )
    	{
    		if ( n>=i )
    		{
    			tmp.push_back(i);
    			Solution::dfs(ret, tmp, k, n-i);
    			tmp.pop_back();
    		}
    	}
    }
};