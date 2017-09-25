#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    string countAndSay(int n)
    {
    	if ( n==0 ) return "";
    	vector<char> ret;
    	ret.push_back('1');
    	for ( int i=1; i<n; ++i )
    	{
    		vector<char> tmp = ret;
    		ret.clear();
    		char c = tmp[0];
    		int count = 1;
    		for ( int j=1; j<tmp.size(); ++j )
    		{
    			if ( tmp[j]==c ){
    				count++;
    			}
    			else{
    				ret.push_back(count+'0');
    				ret.push_back(c);
    				c = tmp[j];
    				count = 1;
    			}
    		}
    		ret.push_back(count+'0');
    		ret.push_back(c);
    	}
    	return string(ret.begin(), ret.end());
    }
};