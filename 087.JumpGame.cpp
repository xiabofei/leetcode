#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
    	if ( nums.size()==0 ) return false;
    	int global = nums[0];
    	for ( int i=0; i<=global; ++i )
    	{
    		if ( global>=nums.size()-1 ) return true;
    		global = max(global, i+nums[i]);
    	}
    	return false;
    }
};