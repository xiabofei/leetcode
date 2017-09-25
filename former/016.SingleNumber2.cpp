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
    	map<int, int> num_times;
    	int ret = 0;
    	for ( int i=0; i<nums.size(); ++i )
    	{
    		num_times[nums[i]]++;
    		if ( num_times[nums[i]]==3 ) num_times[nums[i]]=0;
    	}
    	for ( map<int, int>::iterator i=num_times.begin(); i!=num_times.end(); ++i )
    	{
    		if ( i->second!=0 ) 
    		{
    			ret = i->first;
    			break;
    		}
    	}
    	return ret;
    }
};