#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s)
    {
    	vector<vector<string> > ret;
    	vector<string> tmp;
    	Solution::dfs(ret, tmp, s, 0);
    	return ret;
    }
    static void dfs(vector<vector<string> >& ret, vector<string>& tmp, string s, int index)
    {
    	if ( index==s.size() )
    	{
    		ret.push_back(tmp);
    		return;
    	}
    	for ( int i=index; i<s.size(); ++i )
    	{
    		string sub = s.substr(index, i-index+1);
    		if ( Solution::isPalindrome(sub) )
    		{
    			tmp.push_back(sub);
    			Solution::dfs(ret, tmp, s, i+1);
    			tmp.pop_back();
    		}
    	}
    }
    static bool isPalindrome(string s)
    {
    	int l = 0; 
    	int r = s.size()-1;
    	while ( l<r ) if (s[l++]!=s[r--]) return false;
    	return true;
    }
};