#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>

using namespace std;

class Solution{
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
    	int total = 0;
    	int tmp = 0;
    	int start = 0;
    	for ( int i=0; i<gas.size(); ++i )
    	{
    		total += gas[i]-cost[i];
    		tmp += gas[i]-cost[i];
    		if ( tmp<0 )
    		{
    			tmp = 0;
    			start = i;
    		}
    	}
    	return total>=0 ? start : -1;
    }
};