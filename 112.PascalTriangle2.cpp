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
    vector<int> getRow(int rowIndex)
    {
    	vector<int> ret;
    	ret.push_back(1);
    	for ( int i=0; i<rowIndex; ++i ) 
    	{
    		for ( int j=ret.size(); j>0; --j ) ret[j] = ret[j]+ret[j-1];
    		ret.push_back(1);
    	}
    	return ret;
    }
};
