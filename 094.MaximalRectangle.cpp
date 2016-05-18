#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix)
    {
   		const int m = matrix.size();
   		if ( m==0 ) return 0;
   		const int n = matrix[0].size();
   		vector<int> height(n, 0);
   		int ret = 0;
   		for ( int i=0; i<m; ++i )
   		{
   			for ( int j=0; j<n; ++j ) height[j] = matrix[i][j]=='1' ? height[j]+1 : 0;
   			ret = max(ret, Solution::updateRectangle(height));
   		}
   		return ret;
    }
    static int updateRectangle(vector<int>& height)
    {
    	height.push_back(0);
    	stack<int> sta;
    	int ret = 0;
    	for (int i=0; i<height.size(); ++i )
    	{
    		if ( sta.empty() || height[i]>height[sta.top()] )
    		{
    			sta.push(i);
    		}
    		else
    		{
    			while ( !sta.empty() && height[i]<=height[sta.top()] )
    			{
    				int index = sta.top(); sta.pop();
    				if ( sta.empty() )
    				{
    					ret = max(ret, i*height[index]);
    				}
    				else
    				{
    					ret = max(ret, (i-sta.top()-1)*height[index]);
    				}
    			}
    			sta.push(i);
    		}
    	}
    	height.pop_back();
    	return ret;
    }
};