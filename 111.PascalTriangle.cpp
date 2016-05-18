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
    vector<vector<int> > generate(int numRows)
    {
    	vector<vector<int> > ret;
    	if (numRows==0) return ret;
    	vector<int> tmp;
    	tmp.push_back(1);
    	ret.push_back(tmp);
    	for ( int i=1; i<numRows; ++i )
    	{
    		for ( int j=tmp.size(); j>0; --j ) tmp[j] = tmp[j] + tmp[j-1];
    		tmp.push_back(1);
    		ret.push_back(tmp);
    	}
    	return ret;
    }
};