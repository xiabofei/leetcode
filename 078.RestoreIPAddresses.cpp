#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
    	vector<string> ret;
    	if (s.size()<4||s.size()>12) return ret;
    	vector<string> tmp;
    	Solution::dfs(ret, tmp, s);
    	return ret;
    }
    static void dfs(vector<string>& ret, vector<string>& tmp, string s)
    {
    	if ( tmp.size()==3 )
    	{
    		if ( Solution::isValid(s) )
    		{
    			tmp.push_back(s);
    			string result = "";
    			for ( int i=0; i<tmp.size(); ++i )
    				result += tmp[i] + ".";
    			ret.push_back(result.substr(0,result.size()-1));
    			tmp.pop_back();
    			return;
    		}
    	}
    	for ( int i=0; i<min(int(s.size()),3); ++i )
    	{
    		if ( Solution::isValid(s.substr(0,i+1)) )
    		{
    			tmp.push_back(s.substr(0,i+1));
    			Solution::dfs(ret, tmp, s.substr(i+1,s.size()-(i+1)));
    			tmp.pop_back();
    		}
    	}
    }
    static bool isValid(string s)
    {
    	if (s=="") return false;
    	if (s.size()>1&&s[0]=='0') return false;
    	if (s.size()>3) return false;
    	int val = atoi(s.c_str());
    	return val<=255;
    }
};