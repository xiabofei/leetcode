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
    int numDecodings(string s)
    {
    	const int n = s.size();
    	if (n==0) return 0;
    	int dp[s.size()+1];
    	fill_n(&dp[0], s.size()+1, 0);
    	dp[0] = 1;
    	if(s[0]!='0')
    		dp[1] = 1;
    	else
    		return 0;
    	for ( int i=2; i<=n; ++i )
    	{
    		if (s[i-1]=='0')
    		{
    			if ( s[i-2]=='0' || s[i-2]>'2' )
    			{
    				return 0;
    			}
    			else
    			{
    				dp[i] = dp[i-2];
    			}
    		}
    		else
    		{
    			if (s[i-2]=='0')
    			{
    				dp[i] = dp[i-1];
    			}
    			else
    			{
    				if ( ((s[i-2]-'0')*10+(s[i-1]-'0'))>26 )
    				{
    					dp[i] = dp[i-1];
    				}
    				else
    				{
    					dp[i] = dp[i-2] + dp[i-1];
    				}
    			}
    		}
    	}
    	return dp[n];
    }
};