#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


// 思路与merge interval类似
// 用stack数据结构
// 对每个interval先于newInterval作比较
// 如果没有交集就入栈
// 如果有交集 先merge 再与栈顶的interval比较 直到与栈顶元素没有交集了再出栈

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ret;
		stack<Interval> sta;
		int inserted_flag = false;
		if(intervals.size()==0){
			ret.push_back(newInterval);
			return ret;
		}
		for(int i=0; i<intervals.size(); i++){
			if(intervals[i].end < newInterval.start){
			    // interval全小于newInterval
				sta.push(intervals[i]);
			} 
			else if(intervals[i].start > newInterval.end){
				// 由于原来的intervals是没有overlap的 因此后面的就不用再合并了
				inserted_flag = true;
				sta.push(newInterval);
				for(int j=i; j<intervals.size(); j++){sta.push(intervals[j]);}
				break;
			}
			else{
				// 合并interval与newInterval
				newInterval.start = min(intervals[i].start, newInterval.start);
				newInterval.end = max(intervals[i].end, newInterval.end);
				// 回溯之前的interval是否可以合并
				while(!sta.empty()){
					if(sta.top().end<newInterval.start){
						break;
					}
					else{ // 如果有交集 则合并 并弹出原栈顶元素
						newInterval.start = min(sta.top().start, newInterval.start);
						newInterval.end = max(sta.top().end, newInterval.end);
						sta.pop();
					}
				}
			}
		}
		if(!inserted_flag){sta.push(newInterval);}
		while(!sta.empty()){
			ret.push_back(sta.top());
			sta.pop();
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};