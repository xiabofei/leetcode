#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution{
public:
    vector<vector<int> > threeSum(vector<int>& nums)
    {
    	vector<vector<int> > ret;
		if (nums.size()<3) return ret;
		sort(nums.begin(), nums.end());
    	for (int i=0; i<nums.size()-2; ++i )
    	{
    		if ( i>0 && nums[i]==nums[i-1] ) continue;
    		int val = nums[i];
    		int l = i+1;
    		int r = nums.size()-1;
    		while ( l<r )
    		{
    			if ( nums[l]+nums[r]+val==0 )
    			{
    				vector<int> tmp;
    				tmp.push_back(val);
    				tmp.push_back(nums[l]);
    				tmp.push_back(nums[r]);
    				ret.push_back(tmp);
    				l++;
    				while ( l<r && nums[l]==nums[l-1] ) l++;
    				r--;
    				while ( l<r && nums[r]==nums[r+1] ) r--;
    			}
    			else if ( nums[l]+nums[r]+val<0 )
    			{
    				l++;
    			}
    			else
    			{
    				r--;
    			}
    		}
    	}
    	return ret;
    }
};