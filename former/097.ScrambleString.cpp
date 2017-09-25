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
    bool isScramble(string s1, string s2)
    {
    	const int n1 = s1.size();
    	const int n2 = s2.size();
    	// pruning
    	if (n1!=n2) return false;
    	int alpha[26];
    	fill_n(&alpha[0], 26, 0);
    	int n = n1;
    	for ( int i=0; i<n; ++i ) 
    	{
    		alpha[s1[i]-'a']++;
    		alpha[s2[i]-'a']--;
    	}
    	for ( int i=0; i<26; ++i ) if (alpha[i]!=0) return false;
    	// termination
    	if ( n==1 ) return s1[0]==s2[0];
    	// dfs
    	for ( int i=1; i<n; ++i )
    	{
    		if (
    		   (Solution::isScramble(s1.substr(0,i), s2.substr(0,i)) &&
    		    Solution::isScramble(s1.substr(i,n-i), s2.substr(i,n-i)) )
    		   ||
			   (Solution::isScramble(s1.substr(0,i), s2.substr(n-i,i)) &&
    		   Solution::isScramble(s1.substr(i,n-i), s2.substr(0,n-i)) )
    		   )
			{ return true; }
    	}
    	return false;
    }
};