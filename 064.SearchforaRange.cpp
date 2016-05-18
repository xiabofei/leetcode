#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
    	vector<int> ret;
    	int l = 0;
    	int r = nums.size()-1;
    	int left = -1;
    	int right = -1;
    	// search for left
    	while ( l<=r )
    	{
    		int mid = (l+r)/2;
    		if ( nums[mid]==target )
    		{
    			left = mid;
    			r = mid - 1;
    		}
    		else if ( nums[mid]<target )
    		{
    			l = mid+1;
    		}
    		else
    		{
    			r = mid - 1;
    		}
    	}
    	if ( left == -1) { ret.push_back(-1); ret.push_back(-1); return ret;}
    	// search for the right
    	r = nums.size()-1;
    	while ( l<=r )
    	{
    		int mid = (l+r)/2;
    		if ( nums[mid]==target )
    		{
    			right = mid;
    			l = mid + 1;
    		}
    		else 
    		{
    			r = mid - 1;
    		}
    	}
    	ret.push_back(left);
    	ret.push_back(right);
    	return ret;
    }
};