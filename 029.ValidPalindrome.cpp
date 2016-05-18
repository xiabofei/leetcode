#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    bool isPalindrome(string s)
    {
    	transform(s.begin(), s.end(), s.begin(), ::tolower);
    	int l = 0;
    	int r = s.size()-1;
    	while ( l<r )
    	{
    		if ( !::isalnum(s[l]) )
    		{
    			l++;
    		}
    		else if ( !::isalnum(s[r]) )
    		{
    			r--;
    		}
    		else if ( s[l]!=s[r] )
    		{
    			return false;
    		}
    		else
    		{
    			l++;
    			r--;
    		}
    	}
    	return true;
    }
};