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
    vector<int> findSubstring(string s, vector<string>& words)
    {
    	vector<int> ret;
    	if ( words.empty() ) return ret;
    	int len = words[0].size();
    	if (len*words.size()>s.size()) return ret;
    	map<string, int> ref;
    	for ( int i=0; i<words.size(); ++i ) ref[words[i]]++;
    	map<string, int> word_counts;
    	int match_counts = 0;
    	int i = 0;
    	while ( i<=s.size()-len )
    	{
    		int j = i;
    		word_counts.clear();
    		while ( j<=s.size()-len )
    		{
	    		string word = s.substr(j,len);
	    		if ( ref.find(word)!=ref.end() && word_counts[word]+1 <= ref[word] )
	    		{
	    			word_counts[word]++;
	    			match_counts++; 
		    		if ( match_counts==words.size() )
		    		{
		    			ret.push_back(i);
		    			break;
	    			}
	    			j = j+len;
	    			continue;
	    		}
	    		break;
    		}
    		match_counts=0;
    		++i;
    	}
    	return ret;
    }
};