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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
    	vector<Interval> ret;
    	// insert
    	vector<Interval>::iterator i=intervals.begin();
    	while ( i!=intervals.end() )
    	{
    		if ( newInterval.start < i->start )
    		{
    			intervals.insert(i, newInterval);
    			break;
    		}
    		++i;
    	}
    	if ( i==intervals.end() ) intervals.insert(intervals.end(), newInterval);
    	// merge
    	i = intervals.begin();
    	ret.push_back(*i);
    	++i;
    	while ( i!=intervals.end() )
    	{
    		if ( i->start >= ret.back().end )
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
};