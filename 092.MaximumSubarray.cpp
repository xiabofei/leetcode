#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
    	int global = INT_MIN;
    	int local = INT_MIN;
    	for ( int i=0; i<nums.size(); ++i )
    	{	
    		local = local>0 ? local+nums[i] : nums[i];
    		global = max(global, local);
    	}
    	return max(global, local);
    }
};