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
    int maxProfit(vector<int>& prices)
    {
    	const int n = prices.size();
    	if ( n==0 ) return 0;
    	vector<int> l(n, 0);
    	vector<int> r(n, 0);
    	int mini = prices[0];
    	for ( int i=1; i<n; ++i )
    	{
    		mini = min(mini, prices[i]);
    		l[i] = max(l[i-1], prices[i]-mini);
    	}
    	int maxi = prices[n-1];
    	for ( int i=n-2; i>=0; --i)
    	{
    		maxi = max(maxi, prices[i]);
    		r[i] = max(r[i+1], maxi-prices[i]);
    	}
    	int ret = 0;
    	for ( int i=0; i<n; ++i ) ret = max(ret, l[i]+r[i]);
    	return ret;
    }
};