#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <math.h>

using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
    	vector<Interval> ret;
    	if ( intervals.empty() ) return ret;
    	// sort 
    	sort(intervals.begin(), intervals.end(), Solution::comp);
    	// merge
    	vector<Interval>::iterator i = intervals.begin();
    	ret.push_back(*i);
    	++i;
    	while ( i!=intervals.end() )
    	{
    		if ( i->start <= ret.back().end )
    		{
    			ret.back().start = min(i->start, ret.back().start);
    			ret.back().end = max(i->end, ret.back().end);
    		}
    		else
    		{
    			ret.push_back(*i);
    		}
    		++i;
    	}
    	return ret;
    }
    static bool comp(Interval a, Interval b)
    {
    	return a.start < b.start;
    }
};