#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;
/*
维护一个严格递增的stack
尾部push_back一个0 保证最后所有的元素都能出来
如果不满足严格递增的栈 就往外弹元素 直到不能再弹为止
更新ret的时候 只用栈中弹出来的元素就行 不考虑在外面候着的这个元素
具体的细节在while中体会一下
这里有一个比较巧妙的细节：如果栈中代表的高度是：1 2 3 4 等待入栈的是1
那就把1 2 3 4都弹出去了，再把外面的这个1的下标给push进去
等着新入栈的这个1给弹出去的时候（比如外面来个0.5）
这时候栈空了 
*/

class Solution{
public:
    static int largestRectangleArea(vector<int>& height)
    {
    	int ret;
    	height.push_back(0);
    	stack<int> sta; // increasing stack
    	int len = height.size();
    	for ( int i=0; i<len; ++i )
    	{
    		if ( sta.empty() )
    		{
    			sta.push(i);
    		}
    		else
    		{
    			if ( height[i]>height[sta.top()] )
    			{
    				sta.push(i);
    			}
    			else
    			{
    				while ( !sta.empty() && height[sta.top()]>=height[i] )
    				{
    					int index = sta.top();
    					sta.pop();
    					if ( sta.empty() )
    					{
    						ret = max(ret, i*height[index]);
    					}
    					else
    					{
    						ret = max(ret, (i-sta.top()-1)*height[index] );
    					}
    				}
    				sta.push(i);
    			}
    		}
    	}
    	return ret;
    }
};
int main(int argc, char const *argv[])
{
	vector<int> h;
	h.push_back(1);
	h.push_back(2);
	h.push_back(1);
	h.push_back(2);
	cout << Solution::largestRectangleArea(h) << endl;
	return 0;
}