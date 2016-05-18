#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>

using namespace std;

class Solution{
    int climbStairs(int n)
    {
    	map<int, int> n_val;
    	n_val[0] = 1;
    	n_val[1] = 1;
    	return Solution::fun(n, n_val);
    }
    static int fun(int n, map<int, int>& n_val)
    {
    	if ( n==0 ) return 0;
    	if ( n==1 ) return 1;
    	int ret1, ret2;
    	if ( n_val.find(n-1)!=n_val.end() )
    	{	
    		ret1 = n_val[n-1];
    	}
    	else
    	{
    		ret1 = Solution::fun(n-1, n_val);
    		n_val[n-1] = ret1;
    	}
    	if ( n_val.find(n-2)!=n_val.end() )
    	{
    		ret2 = n_val[n-2];
    	}
    	else
    	{
    		ret2= Solution::fun(n-2, n_val);
    		n_val[n-2] = ret2;
    	}
    	return ret1+ret2;
    }
};