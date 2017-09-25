#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <stack>
#include <set>
#include <numeric>

using namespace std;

class Solution{
	int singleNumber(vector<int>& nums)
	{
		int ret = 0;
		for ( int i=0; i<nums.size(); ++i )
		{
			ret = ret ^ nums[i];
		}
		return ret;
    }
};