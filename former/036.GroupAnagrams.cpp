#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs)
    {
    	vector<vector<string> > ret;
    	if ( strs.empty() ) return ret;
    	map<string, vector<string> > strCount;
    	for ( int i=0; i<strs.size(); ++i )
    	{
    		string tmp = strs[i];
    		sort(tmp.begin(), tmp.end());
    		strCount[tmp].push_back(strs[i]);
    	}
    	for ( map<string, vector<string> >::iterator i=strCount.begin(); i!=strCount.end(); ++i )
    	{
    		sort(i->second.begin(), i->second.end());
    		ret.push_back(i->second);
    	}
    	return ret;
    }
};