#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n)
    {
    	double ret = 0;
    	if ( fabs(x-0)<1e-9 ) return 0.0; 
    	ret = Solution::pow(fabs(x), abs(n));
    	if (x>0)
    	{
    		if ( n<0 )
    		{
    			ret = 1.0 / ret;
    		}
    	}
    	else
    	{
    		if ( n & 1 )
    		{
    			ret = -ret;
    		}
    		if ( n<0 )
    		{
    			ret = 1.0 / ret;
    		}
    	}
    	return ret;
    }
    static double pow(double x, int n)
    {
    	if (n==0) return 1;
    	if (n==1) return x;
    	double val = Solution::pow(x, n/2);
    	double remain = n & 1 ? x : 1;
    	return val * val * remain;
    }
};