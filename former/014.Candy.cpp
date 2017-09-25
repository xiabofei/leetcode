#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <stack>
#include <set>
#include <numeric>

using namespace std;

class Solution{
public:
    int candy(vector<int>& ratings)
    {
    	vector<int> candyCount(ratings.size(), 1);
    	// from left to right
    	for ( int i=1; i<ratings.size(); ++i )
    	{
    		if ( ratings[i]>ratings[i-1] )
    		{
    			candyCount[i] = candyCount[i-1]+1;
    		}
    	}
    	// from right to left
    	for ( int i=ratings.size()-1; i>0; --i )
    	{
    		if ( ratings[i-1]>ratings[i] )
    		{
    			candyCount[i-1] = max(candyCount[i-1], candyCount[i]+1);
    		}
    	}
    	return accumulate(candyCount.begin(), candyCount.end(), 0);
    }
};