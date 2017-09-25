#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
    	if ( nums.size()==0 ) return -1;
    	int begin = 0;
    	int end = nums.size()-1;

    	while ( begin<end )
    	{
    		int mid = (begin+end)/2;
    		if (target==nums[mid]) return mid;
    		if (target>nums[mid])
    		{
    			if (nums[begin]<nums[mid])
    			{
    				begin = mid+1;
    			}
    			else
    			{
    				if (target<=nums[end])
    				{
    					begin = mid+1;
    				}
    				else
    				{
    					end = mid-1;
    				}
    			}
    		}
    		else
    		{
    			if (nums[begin]>nums[mid])
    			{
    				end = mid-1;
    			}
    			else
    			{
    				if (nums[begin]<=target)
    				{
    					end = mid-1;
    				}
    				else
    				{
    					begin = mid+1;
    				}
    			}
    		}
    	}
    	return nums[begin]==target ? begin : -1;
    }
};