#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    int minCut(string s)
    {
    	const int n = s.size();
    	vector<vector<bool> > P(n, vector<bool>(n, false));
    	int dp[n];
    	fill_n(&dp[0], n, 0);
    	Solution::isAllPalindrome(P, s);
    	// 在获取所有子串是否是回文的基础上 只需要一维的dp即可
    	for ( int i=1; i<n; ++i )
    	{
    		if ( P[0][i] )
    		{
    			dp[i] = 0;
    		}
    		else
    		{
    			int cuts = INT_MAX;
    			for ( int j=i; j>0; --j )
    			{
    				if ( P[j][i] ) cuts = min(cuts, dp[j-1]+1);
    				if ( cuts==1 ) break;
    			}
    			dp[i] = cuts;
    		}
    	}
    	return dp[n-1];
    }
    // 求所有子串是否是回文
    static void isAllPalindrome(vector<vector<bool> >& p, string s)
    {
    	for ( int i=0; i<s.size(); ++i )
    	{
    		for ( int j=0; j<=i; ++j )
    		{
    			if (i-j<2)
    			{
    				p[j][i] = s[j]==s[i];
    			}
    			else
    			{
    				p[j][i] = p[j+1][i-1] && s[j]==s[i];
    			}
    		}
    	}
    }
};