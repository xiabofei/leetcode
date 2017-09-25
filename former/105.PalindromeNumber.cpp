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
    bool isPalindrome(int x)
    {
    	if (x<0) return false;
    	int d = 1;
    	while ( x/d>=10 ) d = d*10;
    	if (d==1) return true;
    	while (x>0)
    	{
    		int h = x/d;
    		int l = x%10;
    		if (h!=l) return false;
    		x = x%d/10;
    		d = d/100;
    	}
    	return true;
    }
};