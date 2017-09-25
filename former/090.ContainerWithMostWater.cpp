#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height)
    {
    	int l = 0;
    	int r = height.size()-1;
    	int global = 0;
    	while (l<r)
    	{
    		if (height[l]<height[r])
    		{
    			global = max(global, (r-l)*height[l]);
    			l++;
    		}
    		else
    		{
    			global = max(global, (r-l)*height[r]);
    			r--;
    		}
    	}
    	return global;
    }
};