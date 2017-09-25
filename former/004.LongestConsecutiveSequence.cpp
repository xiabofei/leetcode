#include <iostream>
#include <vector>
#include <map>	

using namespace std;

class Solution{
public:
    int longestConsecutive(vector<int>& nums)
    {
    	    map<int, bool> if_visited;
    	    for ( int i=0; i<nums.size(); ++i ) if_visited[nums[i]] = false;
    	    int globalLongest = 0;
    		for ( int i=0; i<nums.size(); ++i )
    		{
    			if ( if_visited[nums[i]] ) continue;
    			if_visited[nums[i]] = true;
    			int localLongest = 1;
    			// smaller than current value
    			int val = nums[i]-1;
    			while ( if_visited.find(val)!=if_visited.end() )
    			{
    				if_visited[val] = true;
    				localLongest++;
    				val--;
    			}
    			// larger than current value
    			val = nums[i]+1;
    			while ( if_visited.find(val)!=if_visited.end() )
    			{
    				if_visited[val] = true;
    				localLongest++;
    				val++;
    			}
    			globalLongest = max(globalLongest, localLongest);
    		}
    		return globalLongest;
    }
};