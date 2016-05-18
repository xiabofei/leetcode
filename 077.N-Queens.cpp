#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n)
    {
    	vector<vector<string> > ret;
    	vector<string> tmp;
    	vector<bool> col(n, false);
    	vector<bool> lr(2*n-1, false);
    	vector<bool> rl(2*n-1, false);
    	Solution::dfs(ret, tmp, n, col, lr, rl);
    	return ret;
    }
    static void dfs(vector<vector<string> >& ret, vector<string>& tmp, int n,
    	vector<bool>& col, vector<bool>& lr, vector<bool>& rl)
    {
    	if ( tmp.size()==n )
    	{
    		ret.push_back(tmp);
    		return;
    	}
    	int i = tmp.size();
    	string curr = string(n,'.');
    	for ( int j=0; j<n; ++j )
    	{
    		if ( !col[j] && !lr[j-i+n-1] && !rl[i+j] )
    		{
    			curr[j] = 'Q';
    			col[j] = true;
    			lr[j-i+n-1] = true;
    			rl[i+j] = true;
    			tmp.push_back(curr);
    			Solution::dfs(ret, tmp, n, col, lr, rl);
    			tmp.pop_back();
    			col[j] = false;
    			lr[j-i+n-1] = false;
    			rl[i+j] = false;
    			curr[j] = '.';
    		}
    	}
    }
};