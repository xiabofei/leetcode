#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution{
    void nextPermutation(vector<int>& nums)
    {
    	// step 1
    	int violate = -1;
    	for ( int i=nums.size()-1; i>0; --i )
    	{
    		if (nums[i]>nums[i-1])
    		{
    			violate = i-1;
    			break;
    		}
    	}
    	if ( violate==-1 )
    	{
    		reverse(nums.begin(), nums.end());
    		return;
    	}
    	// step 2
    	int larger = nums.size()-1;
    	for ( int i=nums.size()-1; i>=0; --i )
    	{
    		if (nums[i]>nums[violate])
    		{
    			larger = i;
    			break;
    		}
    	}
    	swap(nums[violate],nums[larger]);
    	// step 3
    	reverse(nums.begin()+violate+1, nums.end());
    	return;
    }
};