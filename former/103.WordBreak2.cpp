#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, set<string>& wordDict)
    {
     	vector<string> ret;
     	vector<string> tmp;
     	vector<bool> possible(s.size(), true);
     	Solution::dfs(ret, tmp, wordDict, s, 0, possible);
     	return ret;
    }
    static void dfs(
    	vector<string>& ret, vector<string>& tmp, set<string>& wordDict, 
    	string s, int begin, vector<bool>& possible)
    {	
    	if (begin==s.size())
    	{
    		string str = "";
    		for ( int i=0; i<tmp.size(); ++i ) str += tmp[i] + " ";
    		ret.push_back(str.substr(0, str.size()-1));
    		return;
    	}
    	for ( int i=begin; i<s.size(); ++i )
    	{
    		if ( wordDict.find(s.substr(begin, i-begin+1))!=wordDict.end() && possible[i] )
    		{
    			int preSolutionNum = ret.size();
    			tmp.push_back(s.substr(begin,i-begin+1));
    			Solution::dfs(ret, tmp, wordDict, s, i+1, possible);
    			tmp.pop_back();
    			if ( preSolutionNum==ret.size() ) possible[i] = false;
    		}
    	}
    }
};