#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
    	vector<string> ret;
    	vector<char> tmp;
    	Solution::dfs(ret, tmp, 0, n);
    	return ret;
    }
    static void dfs(vector<string>& ret, vector<char>& tmp, int balance, int n)
    {
    	if (tmp.size()==n*2)
    	{
    		if (balance==0) ret.push_back(string(tmp.begin(),tmp.end()));
    		return;
    	}
    	if ( balance>0 )
    	{
    		if ( balance<n )
    		{
    			tmp.push_back('(');
    			Solution::dfs(ret, tmp, balance+1, n);
    			tmp.pop_back();
    		}

    		tmp.push_back(')');
    		Solution::dfs(ret, tmp, balance-1, n);
    		tmp.pop_back();
    	}
    	else
    	{
    		tmp.push_back('(');
    		Solution::dfs(ret, tmp, balance+1, n);
    		tmp.pop_back();
    	}
    }
};