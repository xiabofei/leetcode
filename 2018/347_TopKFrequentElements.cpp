#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <priority_queue>


using namespace std;


// 学习用优先队列的方式去构建
// http://www.cnblogs.com/grandyang/p/5454125.html


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	vector<int> ret;
    	unordered_map<int, int> val_cnts;
    	priority_queue<pair<int, int>> q;
    	for(int i=0; i<nums.size(); i++){
    		val_cnts[nums[i]]++;
    	}
    	for(auto it : val_cnts){
    		q.push({it.second, it.first});
    	}
    	for(int i=0; i<k; i++){
    		ret.push_back(q.top().second);
    		q.pop();
    	}
    	return ret;
    }
};