#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 多总结一下combinations和permutations的区别
// combinations在dfs时候 走循环 每次从begin开始 
// permutations在dfs的时候 走循环 每次从头开始
// subsets在dfs时候 用begin 也得走循环 每层加入一个元素 如果要处理不重复子集的问题 就在当前层判断 
// 另外 subsets在去重的时候 需要县排序
//
// permutations必须走到头 因为需要全体元素
// combination必须走到k 因为只需要k个元素
// subsets只要进入dfs就记录一个结果 因为是找子集 不用等找到最后

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
    	vector<vector<int>> ret;
    	vector<int> tmp;
    	backtracing(ret, tmp, n, 1, k);
    	return ret;
    }
    void backtracing(
    	vector<vector<int>>& ret, vector<int>& tmp, 
    	const int n, const int begin, const int k){
    	if(tmp.size()==k){
    		ret.push_back(tmp);
    		return;
    	}
    	for(int i=begin; i<=n; i++){
    		tmp.push_back(i);
    		backtracing(ret, tmp, n, i+1, k);
    		tmp.pop_back();
    	}
    }
};
