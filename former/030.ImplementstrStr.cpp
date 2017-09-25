#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    int strStr(string haystack, string needle)
    {
    	if ( haystack.size()<needle.size() ) return -1;
    	if ( needle.size()==0 ) return 0;
    	for ( int i=0; i<=haystack.size()-needle.size(); ++i )
    	{
    		if ( haystack[i]==needle[0] )
    		{
    			int j = 0;
    			while ( i+j<haystack.size() && haystack[j+i]==needle[j] ) ++j;
    			if ( j==needle.size() ) return i;
    		}
    	}
    	return -1;
    }
};