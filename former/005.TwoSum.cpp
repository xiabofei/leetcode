#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
    	vector<int> ret;
    	map<int, int> valIndex;
    	for ( int i=0; i<nums.size(); ++i )
    	{
    		if ( valIndex.find(target-nums[i])!=valIndex.end() )
    		{
    			ret.push_back(i+1);
    			ret.push_back(valIndex[target-nums[i]]+1);
    		}
    		valIndex[nums[i]] = i; // 防止一个元素使用两次 [3,2,4] 6 这种的
    	}
    	sort(ret.begin(), ret.end());
    	return ret;
    }
};