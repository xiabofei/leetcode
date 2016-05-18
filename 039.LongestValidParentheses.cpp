#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

/*
动态规划算法 global = max or min( global, local)
这道题的算法在于local的计算并不直观
需要维护一个last_not_match记录上次没有匹配上的字符下标
每次从栈中弹出来元素 就要根据栈顶元素更新一次local "(()()()()()..."这种的
如果栈已经空了 就记录上一次没有匹配的元素的位置更新local
如果直接出现了无效的字符 则可以将last_not_match重新置位 这个时候在无效字符之前出现的有效
长度已经都记录在了global中
*/
class Solution{
public:
    int longestValidParentheses(string s)
    {
    	stack<int> sta;
    	int ret = 0;
    	int last_not_match = -1;
    	for ( int i=0; i<s.size(); ++i )
    	{
    		if ( s[i]=='(' )
    		{
    			sta.push(i);
    		}
    		else
    		{
    			if (sta.empty())
    			{
    				last_not_match = i;
    			}
    			else
    			{
    				sta.pop();
    				if ( sta.empty() )
    				{
    					ret = max(ret, i-last_not_match);
    				}
    				else
    				{
    					ret = max(ret, i-sta.top());
    				}
    			}
    		}
    	}
    	return ret;
    }
};