#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x)
    {
    	if (x<2) return x;
    	int l = 1;
    	int r = x/2;
    	while ( l<=r )
    	{
    		int mid = (l+r)/2;
    		if ( x/mid==mid )
    		{
    			return mid;
    		}
    		else if ( x/mid>mid )
    		{
    			l = mid+1;
    		}
    		else
    		{
    			r = mid-1;
    		}
    	}
    	return r+1;
    }
};