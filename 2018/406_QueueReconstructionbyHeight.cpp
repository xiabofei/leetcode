#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;

// https://blog.csdn.net/prayyojay/article/details/52692532
// 先按h 大→小 排
// 再按k 小→大 排
// k表示排在前面的元素中 有多少比其大的
// 只要按照上述方法去排序 h大的都排在了h小的前面
// 这样在处理到一个元素时 比它大的都已经在它前面处理完了 因此按照k插入就一定符合条件


class Solution {
public:
	static bool comp(const pair<int, int> a, const pair<int, int> b){
		if(a.first == b.first){
			return a.second < b.second;
		}
		return a.first > b.first;
	}
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    	vector<pair<int, int>> ret;
    	if(people.size()==0){return ret;}
    	// 先按h由大到小排 h相同的按k由小到大排
    	sort(people.begin(), people.end(), comp);
    	for(int i=0; i<people.size(); i++){
    		ret.insert(ret.begin() + people[i].second, people[i]);
    	}
    	return ret;
    }
};