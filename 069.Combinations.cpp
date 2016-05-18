#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k)
    {
    	vector<vector<int> > ret;
    	vector<int> tmp;
    	Solution::dfs(ret, tmp, n, k);
    	return ret;
    }
    static void dfs(vector<vector<int> >& ret, 
    	vector<int>& tmp, int n, int k)
    {
    	if ( tmp.size()==k )
    	{
    		ret.push_back(tmp);
    		return;
    	}
    	int index = tmp.empty() ? 0 : tmp.back();
    	for ( int i=index+1; i<=n; ++i ) // 循环这里也可以控制终止的条件
    	{
    		tmp.push_back(i);
    		Solution::dfs(ret, tmp, n, k);
    		tmp.pop_back();
    	}
    }
};