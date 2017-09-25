#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
    	int zero = 0;
    	int two = nums.size()-1;
    	int i = 0;
    	while ( i<two )
    	{
    		if ( nums[i]==0 )
    		{
    			swap(nums[i++], nums[zero++]);
    		}
    		else if ( nums[i]==2 )
    		{
    			swap(nums[i], nums[two--]);
    		}
    		else
    		{
    			i++;
    		}
    	}
    }
};