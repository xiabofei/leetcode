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

// http://www.cnblogs.com/grandyang/p/4484571.html
// 有向图中检测是否有环
// 1) 构造图 & 记录每个节点的入度
// 2) bfs过一遍所有的点
// 3) 看有没有入度不等于零的

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites){
    	// 记录graph中每个前驱node与其所有指向的node
    	vector<vector<int>> graph(numCourses, vector<int>()); 
    	// 记录每个node的入度
    	vector<int> in(numCourses, 0);
    	for(int i=0; i<prerequisites.size(); i++){
    		graph[prerequisites[i].second].push_back(prerequisites[i].first);
    		in[prerequisites[i].first]++;
    	}
    	// 把每个入度为0的node入队列
    	queue<int> q;
    	for(int i=0; i<in.size(); i++){
    		if(in[i]==0){
    			q.push(i);
    		}
    	}
    	// 把入度为0的node依次出队
    	while(!q.empty()){
    		int t = q.front();
    		q.pop();
    		// 遍历所有t指向的节点
    		for(int i=0; i<graph[t].size(); i++){
    			in[graph[t][i]]--;
    			if(in[graph[t][i]]==0){
    				q.push(graph[t][i]);
    			}
    		}
    	}
    	// 检查是否有入度不为0的点
    	for(int i=0; i<in.size(); i++){
    		if(in[i]>0){
    			return false;
    		}
    	}
    	return true;
    }
};