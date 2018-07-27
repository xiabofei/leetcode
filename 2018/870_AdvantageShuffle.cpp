#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// https://blog.csdn.net/yanglingwell/article/details/81053126
// 只要A比B大就行 不需要大多少 
// 贪心算法 : 省着用A中最大的; 实在没有更大的就牺牲A中最小的

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    	vector<int> ret;
    	// 考虑重复的情况 用key排序的map
    	map<int, int> val_cnt;
    	for(int i=0; i<A.size(); i++){
    		val_cnt[A[i]]++;
    	}
    	// 扫描B
    	for(int i=0; i<B.size(); i++){
    		int curr = 0;
    		auto it = val_cnt.upper_bound(B[i]);
    		if(it!=val_cnt.end()){
    			// 省着用最大的
    			curr = it->first;
    		}
    		else{
    			// 没有更大的 牺牲最小的
    			curr = val_cnt.begin()->first;
    		}
    		if(--val_cnt[curr]==0){
    			val_cnt.erase(curr);
    		}
    		ret.push_back(curr);
    	}
    	return ret;
    }
};