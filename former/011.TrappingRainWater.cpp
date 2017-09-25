#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
    	if (height.size()<3) return 0;
    	int ret = 0;
    	stack<int> sta;
    	sta.push(0);
    	for ( int i=1; i<height.size(); ++i )
    	{
    		int  pre = 0;
    		while ( !sta.empty() )
    		{
    			ret += (i-sta.top()-1) * ( min(height[i],height[sta.top()])-pre );
    			pre = height[sta.top()];
    			if (height[i]<pre)
    				break;
    			else
    				sta.pop();
    		}
    		sta.push(i);
    	}
    	return ret;
    }
};