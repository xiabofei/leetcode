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
    string multiply(string num1, string num2)
    {
    	if ( num1=="0" || num2=="0" ) return "0";
    	vector<int> pre(num1.size(), 0);
    	for ( int i=num2.size()-1; i>=0; --i )
    	{
    		vector<int> tmp;
    		int base = num2[i]-'0';
    		int carry = 0;
    		int val = 0;
    		for ( int j=num1.size()-1; j>=0; --j )
    		{
    			val = base*(num1[j]-'0') + carry;
    			tmp.insert(tmp.begin(), val%10);
    			carry = val/10;
    		}
    		if ( carry>0 ) tmp.insert(tmp.begin(), carry);
    		for ( int j=i; j<num2.size()-1; ++j ) tmp.push_back(0);
    		while ( tmp.size()>pre.size() ) pre.insert(pre.begin(), 0);
    		carry = 0;
    		for ( int j=tmp.size()-1; j>=0; --j )
    		{
    			val = tmp[j] + pre[j] + carry;
    			pre[j] = val%10;
    			carry = val/10;
    		} 
    		if ( carry>0 ) pre.insert(pre.begin(), carry);
    	}
    	vector<char> ret;
    	for ( int i=0; i<pre.size(); ++i ) ret.push_back(pre[i]+'0');
    	return string(ret.begin(),ret.end());
    }
};