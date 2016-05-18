#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
     	int globalGap = INT_MAX;
     	sort(nums.begin(), nums.end());
     	for ( int i=0; i<nums.size()-2; ++i )
     	{
     		if ( i>0 && nums[i]==nums[i-1] ) continue;
     		int val = nums[i];
     		int l = i+1;
     		int r = nums.size()-1;
     		while (l<r)
     		{
     			int gap = nums[l]+nums[r]+val-target;
     			if ( gap==0 ) return target;
     			if ( gap<0 )
     			{
     				l++;
     				if ( abs(gap)<abs(globalGap) ) globalGap = gap;
     			}
     			else
     			{
     				r--;
     				if ( abs(gap)<abs(globalGap) ) globalGap = gap;
     			}
     		}
     	}
     	return globalGap+target;
    }
};