#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
动归类的题目 如何确定内外层循环的次数是一个模糊的地方，需要根据具体的题目来确定

这种正则表示的题目 基本可以大体思路往动归上靠 然后基于*这种特殊的情况来考虑动归条件
需要注意的是，由于是判断p能否撇配s，因此外层应该是1到s.size()，内层应该是1到p.size()
这么做相当于每次都拿p的全部去匹配s的部分，这样算到最后就算出来了

对比Longest Palindrome Substring这道题，LPS这道题的外层循环i是0到s.size(), 内层循环j是0到i
为什么内层循环不是s.size()，因为这是在一个字符串内部找子串，所以跟正则这类题目不同
*/
class Solution{
public:
    bool isMatch(string s, string p)
    {
    	bool dp[s.size()+1][p.size()+1];
    	fill_n(&dp[0][0], (s.size()+1)*(p.size()+1), false);
    	// initializing
    	dp[0][0] = true;
    	for ( int i=1; i<=s.size(); ++i ) dp[i][0] = false;
    	for ( int j=1; j<=p.size(); ++j ) dp[0][j] = p[j-1]=='*' ? dp[0][j-2] : false;
    	// dp process
    	for ( int i=1; i<=s.size(); ++i )
    	{
    		for ( int j=1; j<=p.size(); ++j ) // 因为题目要求是p能不能匹配s, 所以需要把p都试一遍
    		{
    			if ( p[j-1]!='*' )
    			{
    				dp[i][j] = dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');  
    			}
    			else
    			{
    				if ( dp[i][j-1] || dp[i][j-2] )
    				{
    					dp[i][j]=true;
    				}
    				else if ( dp[i-1][j] )
    				{
    					dp[i][j] = s[i-1]==p[j-2] || p[j-2]=='.';
    				}
    				else
    				{
    					dp[i][j] = false;
    				}
    			}
    		}
    	}
    	return dp[s.size()][p.size()];
    }
};