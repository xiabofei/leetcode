#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <multiset>

using namespace std;

// http://www.cnblogs.com/grandyang/p/4534586.html
// 引入可以实现保持相对大小顺序不变的multiset

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings){
    	vector<pair<int, int>> h;
    	vector<pair<int, int>> ret;
    	// 允许相同的val存在
    	multiset<int> m;
    	for(int i=0; i<buildings.size(); i++){
    		// 用'-'表示每个building的left进入点
    		h.push_back({buildings[i][0], -buildings[i][2]});
    		// 用'+'表示每个building的right退出点
    		h.push_back({buildings[i][1], buildings[i][2]});
    	}
    	// 把每个建筑看成 left的进入线 & right的退出线 按x轴上的坐标大小排序
    	sort(h.begin(), h.end());
    	m.insert(0); // 为了能够迭代起来 先把初始height设为0
    	int pre = 0; 
    	int curr = 0;
    	for(int i=0; i<h.size(); i++){
    		if(h[i].second<0){
    			m.insert(-h[i].second);
    		}
    		else{
    			// 如果是right退出点 就把之前left的删了
    			m.erase(m.find(h[i].second));
    		}
    		curr = *m.rbegin(); // 提出来当前最大的
    		if(curr != pre){
    			// 冒出来新的sky点height了 
    			ret.push_back({h[i].first, curr});
    			pre = curr;
    		}

    	}
    	return ret;
    }
};