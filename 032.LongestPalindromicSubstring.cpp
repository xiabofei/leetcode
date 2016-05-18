#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    string longestPalindrome(string s)
    {
    	bool dp[s.size()][s.size()];
    	fill_n(&dp[0][0], s.size()*s.size(), false);
    	string ret = s.substr(0,1);
    	for ( int i=0; i<s.size(); ++i ) dp[i][i]=true;
    	for ( int i=0; i<s.size(); ++i )
    	{
    		for ( int j=0; j<i; ++j ) // 由于回文是一个字符串内部自己玩儿, 所以第二层循环到i就可以了
    								// 与 RegularExpressionMatching这道题目比较, 可以获得动归这类题目第二层循环如何确定
    		{
    			if ( i-j<2 )
    			{
    				dp[j][i] = s[i]==s[j];
    				if ( dp[j][i] && i-j+1>ret.size() )
    					ret = s.substr(j,i-j+1);
    			}
    			else
    			{
    				dp[j][i] = s[i]==s[j] && dp[j+1][i-1];
    				if ( dp[j][i] && i-j+1>ret.size() )
    					ret = s.substr(j,i-j+1);
    			}
    		}
    	}
    	return ret;
    }
};
int main(int argc, char const *argv[])
{
	string s = "abc";
	cout << s.substr(1,1) << endl;
	return 0;
}