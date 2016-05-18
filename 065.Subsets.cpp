#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
    	sort(nums.begin(), nums.end());
    	vector<vector<int> > ret;
    	vector<int> blank;
    	ret.push_back(blank);
    	for ( int i=0; i<nums.size(); ++i )
    	{
    		vector<vector<int> > last = ret;
    		for ( int j=0; j<last.size(); ++j )
    		{
    			last[j].push_back(nums[i]);
    			ret.push_back(last[j]);
    		}
    		ret.push_back(blank);
    	}
    	return ret;
    }
};