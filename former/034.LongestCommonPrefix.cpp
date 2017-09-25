#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
    	if ( strs.size()==0 ) return "";
    	string common = strs[0];
    	for ( int i=1; i<strs.size(); ++i )
    	{
    		int j=0;
    		for ( ; j<strs[i].size() && j<common.size(); ++j )
    		{
    			if ( strs[i][j]!=common[j] ) break;
    		}
    		common = common.substr(0,j);
    		if ( common.size()==0 ) break;
    	}
    	return common;
    }
};