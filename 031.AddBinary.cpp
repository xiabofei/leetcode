#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    string addBinary(string a, string b)
    {
    	vector<char> ret;
    	int i = a.size()-1;
    	int j = b.size()-1;
    	int carry = 0;
    	int val_a = 0;
    	int val_b = 0;
    	int curr = 0;
    	while ( i>=0 || j>=0 )
    	{
    		val_a = i>=0 ? a[i]-'0' : 0;
    		val_b = j>=0 ? b[j]-'0' : 0;
    		curr = (carry + val_a + val_b)%2;
    		carry = (carry + val_a + val_b)/2;
    		ret.insert(ret.begin(), curr+'0');
    		--i;
    		--j;
    	}
    	if ( carry==1 ) ret.insert(ret.begin(), '1');
    	return string(ret.begin(), ret.end());
    }
};