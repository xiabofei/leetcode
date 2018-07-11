#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	static bool comp(Interval a, Interval b){
		return a.start < b.start;
	}
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ret;
		stack<Interval> sta;
		if(intervals.size()==0){return ret;}
		sort(intervals.begin(), intervals.end(), Solution::comp);
		sta.push(intervals[0]);
		for(int i=1; i<intervals.size(); i++){
			Interval curr = intervals[i];
			while(!sta.empty()){
				Interval last = sta.top();
    		    // 分有无交集讨论 
				if(curr.start>last.end || curr.end<last.start){
					break;
				}
				else{
					curr.start = min(curr.start, last.start);
					curr.end = max(curr.end, last.end);
					sta.pop();
				}
			}
			sta.push(curr);
		}
		while(!sta.empty()){
			ret.push_back(sta.top());
			sta.pop();
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};