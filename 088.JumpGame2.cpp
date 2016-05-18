#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums)
    {
    	if (nums.size()<2) return 0;
    	int steps = 0;
    	int local = 0;
    	int next = local;
    	for ( int i=0; i<=local; ++i )
    	{
    		next = max(next, i+nums[i]);
    		if ( i==local )
    		{
    			steps++;
    			local = next;
    			if ( local>=nums.size()-1 ) return steps;
    		}
    	}
    	return 0;
    }
};