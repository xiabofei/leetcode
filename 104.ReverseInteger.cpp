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
    int reverse(int x)
    {
    	int sign = 1;
    	if ( x<0 ) sign = -1;
    	vector<int> digits;
    	int remain = 1;
    	while ( remain>0 )
    	{
    		digits.push_back(fabs(x%10));
    		x = x/10;
    		remain = fabs(x);
    	}
    	int ret = 0;
    	for ( int i=0; i<digits.size(); ++i )
    	{
    		if ( INT_MAX/10<ret || (INT_MAX/10==ret && digits[i]>INT_MAX%10) )
    		{
    			return 0;
    		}
    		ret = ret*10 + digits[i];
    	}
    	return ret*sign;
    }
};